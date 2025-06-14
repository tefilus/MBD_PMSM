%==========================================================================
%--------------------------------------------------------------------------
%==========================================================================
%% Load the dataset
load('arrModelMonitoring.mat');                    % Load .mat file containing signal matrix
data = IdcMtr_PotLd_SpMtr_SpLd;                    % Variable of size [3001 x N] where each column is a time frame
Ts = 0.03;                                         % Time interval between each full frame (in seconds)
samplesPerFrame = 600;                             % Number of signal samples per frame
dt = Ts / samplesPerFrame;                         % Time interval between individual samples (sample rate = 1/dt)

%==========================================================================
%--------------------------------------------------------------------------
%==========================================================================
%% Separate signals from the raw matrix
frameTimes = data(1, :);                           % First row contains frame-level timestamps
IdcMtr = data(2:601, :);                           % Motor current signal [600 x N]
PotLd  = data(602:1201, :);                        % Potentiometer load signal
SpLd   = data(1202:1801, :);                       % Load speed
SpMtr  = data(1802:2401, :);                       % Motor speed
SpRef  = data(2402:3001, :);                       % Reference speed

%==========================================================================
%--------------------------------------------------------------------------
%==========================================================================
%% Reconstruct full time-series by concatenating all frames sample-wise
globalTime = [];
IdcMtrAll = []; PotLdAll = []; SpLdAll = []; SpMtrAll = []; SpRefAll = [];

for k = 1:length(frameTimes)
    t0 = frameTimes(k);                            % Starting time of current frame
    t = t0 + (0:samplesPerFrame-1) * dt;           % Reconstruct time vector within frame

    % Append current frame's signals into full vectors
    globalTime = [globalTime, t];
    IdcMtrAll = [IdcMtrAll, IdcMtr(:,k)'];
    PotLdAll  = [PotLdAll,  PotLd(:,k)'];
    SpLdAll   = [SpLdAll,   SpLd(:,k)'];
    SpMtrAll  = [SpMtrAll,  SpMtr(:,k)'];
    SpRefAll  = [SpRefAll,  SpRef(:,k)'];
end

%==========================================================================
%--------------------------------------------------------------------------
%==========================================================================
%% Optionally trim data to skip initial transients
xx = 1.5;                                          % Trim all data before t = 1.5s
validIdx = globalTime > xx;

% Apply logical mask to all signals
globalTime = globalTime(validIdx);
IdcMtrAll = IdcMtrAll(validIdx);
PotLdAll  = PotLdAll(validIdx);
SpLdAll   = SpLdAll(validIdx);
SpMtrAll  = SpMtrAll(validIdx);
SpRefAll  = SpRefAll(validIdx);

%% Compute instantaneous speed tracking error
SpeedError = abs(SpMtrAll - SpRefAll);             % Absolute error between actual and reference speed
validErrorIdx = SpRefAll > 1e-3;                   % Ignore invalid (zero) reference signals
SpeedError(~validErrorIdx) = NaN;                  % Mask error where reference is zero

% Find max error and corresponding time
[maxError, idxMaxErr] = max(SpeedError, [], 'omitnan');
SpRefAtMaxErr = SpRefAll(idxMaxErr);
timeErr = globalTime(idxMaxErr);

% Generate display text for error
if SpRefAtMaxErr > 0
    errorPercent = (maxError / SpRefAtMaxErr) * 100;
    errorText = sprintf('Speed Tracking Error:  \\bf%.2f RPM\\rm  (\\bf%.2f%%\\rm)', maxError, errorPercent);
else
    errorText = sprintf('Speed Tracking Error:  \\bf%.2f RPM\\rm  (\\bfN/A%%\\rm)', maxError);
end

%==========================================================================
%--------------------------------------------------------------------------
%==========================================================================
%% Extract motor current statistics
[maxIdc, idxMaxIdc] = max(IdcMtrAll);              % Peak current
SpAtMaxIdc = SpMtrAll(idxMaxIdc);                  % Speed at peak current
PotAtMaxIdc = PotLdAll(idxMaxIdc);                 % Load at peak current
timeAtMaxIdc = globalTime(idxMaxIdc);              % Time of peak current
rmsIdc = rms(IdcMtrAll);                           % Root-mean-square of current

%==========================================================================
%--------------------------------------------------------------------------
%==========================================================================
%% Compute response time after reference changes
percentThreshold = 0.05;                           % Acceptable relative error (10%)
rpmThreshold = 1;                                  % Minimum absolute tolerance (e.g., 1 RPM)

% Find when SpRef changes significantly
refDiff = diff(SpRefAll);
changeIndices = find(abs(refDiff) > 1e-3) + 1;
minGap = round(0.03 / dt);                         % Minimum gap between ref changes to avoid false detection
filteredChanges = changeIndices([true, diff(changeIndices) > minGap]);

% Preallocate memory for results
Nchange = length(filteredChanges);
responseTimes = NaN(1, Nchange);
changeTimes = NaN(1, Nchange);

for i = 1:Nchange
    idx = filteredChanges(i);
    t0 = globalTime(idx);                          % Time of reference step
    refVal = SpRefAll(idx);                        % New reference value

    % Compute bounds for acceptable tracking
    threshold = max(percentThreshold * abs(refVal), rpmThreshold);
    lower = refVal - threshold;
    upper = refVal + threshold;

    % Define upper bound for response search
    nextChange = length(SpRefAll);
    if i < Nchange
        nextChange = filteredChanges(i+1);
    end

    changeTimes(i) = t0;

    % If SpMtr is already within range → response time = 0
    if SpMtrAll(idx) >= lower && SpMtrAll(idx) <= upper
        responseTimes(i) = 0;
        continue
    end

    % Scan forward to find when SpMtr enters acceptable band
    found = false;
    for j = idx:nextChange-1
        if SpMtrAll(j) >= lower && SpMtrAll(j) <= upper
            responseTimes(i) = globalTime(j) - t0;
            found = true;
            break;
        end
    end

    % If still not found, allow transition toward new ref target
    if ~found
        for j = nextChange:length(SpMtrAll)
            newRef = SpRefAll(j);
            newThreshold = max(percentThreshold * abs(newRef), rpmThreshold);
            newLower = newRef - newThreshold;
            newUpper = newRef + newThreshold;

            if SpMtrAll(j) >= newLower && SpMtrAll(j) <= newUpper
                responseTimes(i) = globalTime(j) - t0;
                break;
            end
        end
    end
end
%--------------------------------------------------------------------------
% Compute global response time stats
if ~isempty(responseTimes)
    maxRespTime = max(responseTimes);
    meanRespTime = mean(responseTimes);
else
    maxRespTime = NaN;
    meanRespTime = NaN;
end

%==========================================================================
%--------------------------------------------------------------------------
%==========================================================================
%% Create visualization layout
figure('Name', 'Dual PMSM synchronous control', 'Color', 'w');
t = tiledlayout(2, 3, 'TileSpacing', 'compact', 'Padding', 'compact');
title(t, 'Dual PMSM synchronous control');

%--------------------------------------------------------------------------
% Plot 1: Motor Current
nexttile(1);
plot(globalTime, IdcMtrAll, 'Color', [0 0.5 0], 'LineWidth', 0.5);
xlabel('Time (s)'); ylabel('Amp'); title('Idc Motor'); grid on;

%--------------------------------------------------------------------------
% Plot 2: Motor Speed vs Reference
nexttile(2);
plot(globalTime, SpMtrAll, 'b', 'LineWidth', 0.75); hold on;
plot(globalTime, SpRefAll, 'Color', [1 0.5 0], 'LineWidth', 0.75);
legend('Speed Motor', 'Speed Ref', 'Location', 'best');
xlabel('Time (s)'); ylabel('RPM'); title('Speed Motor vs Ref'); grid on;

%--------------------------------------------------------------------------
% Plot 3: Potentiometer Load
nexttile(4);
plot(globalTime, PotLdAll, 'r', 'LineWidth', 1.2);
xlabel('Time (s)'); ylabel('%'); title('POT Load'); grid on;

%--------------------------------------------------------------------------
% Plot 4: Load Speed
nexttile(5);
plot(globalTime, SpLdAll, 'Color', [0.6 0.3 0], 'LineWidth', 0.75);
xlabel('Time (s)'); ylabel('RPM'); title('Speed Load'); grid on;

%--------------------------------------------------------------------------
% Plot 5: Info box (statistics + highlights)
nexttile(3, [2 1]);
axis off;
rectangle('Position', [0 0 1 1], 'EdgeColor', 'k', 'LineWidth', 1.5);

%--------------------------------------------------------------------------
% Dynamic annotation layout (text block positions)
y = 0.92; dy = 0.08;

%--------------------------------------------------------------------------
text(0.05, y, errorText, 'FontSize', 14, 'Color', [0 0 1]); y = y - dy;
text(0.05, y, sprintf('At Ref = \\bf%.2f\\rm RPM', SpRefAtMaxErr), 'FontSize', 12); y = y - 0.04;
text(0.05, y, sprintf('Time = \\bf%.2fs', timeErr), 'FontSize', 12); y = y - dy;

%--------------------------------------------------------------------------
text(0.05, y, sprintf('Response Time (Max):  \\bf%.3f\\rm s', maxRespTime), ...
    'FontSize', 13, 'Color', [0.8 0 0.8]); y = y - 0.06;
text(0.05, y, sprintf('Response Time (Mean):  \\bf%.3f\\rm s', meanRespTime), ...
    'FontSize', 13, 'Color', [0.8 0 0.8]); y = y - 0.06;

%--------------------------------------------------------------------------
line([0.05 0.95], [y y], 'Color', 'k', 'LineStyle', '--'); y = y - 0.08;

%--------------------------------------------------------------------------
text(0.05, y, sprintf('Max Motor Current:  \\bf%.2f\\rm A', maxIdc), ...
    'FontSize', 14, 'Color', [0 0.5 0]); y = y - dy;

%--------------------------------------------------------------------------
text(0.05, y, sprintf('At Speed = \\bf%.1f\\rm RPM', SpAtMaxIdc), 'FontSize', 12); y = y - 0.04;
text(0.05, y, sprintf('Load Duty = \\bf%.1f\\rm%%', PotAtMaxIdc), 'FontSize', 12); y = y - 0.04;
text(0.05, y, sprintf('Time = \\bf%.2fs', timeAtMaxIdc), 'FontSize', 12); y = y - dy;

%--------------------------------------------------------------------------
text(0.05, y, sprintf('Average Motor Current:  \\bf%.2f\\rm A', rmsIdc), ...
    'FontSize', 13, 'Color', [0 0.4 0.8]);

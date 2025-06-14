%% Load data
load('ModelMonitoring.mat');

%% Lấy dữ liệu từ timeseries
ts = IdcMtr_PotLd_SpMtr_SpLd;    % timeseries object
data = squeeze(ts.Data);         % [3000 x 2494]
time = ts.Time;                  % [2494 x 1]

%% Chia 5 tín hiệu (mỗi tín hiệu 600 dòng)
N = 600;
IdcMtr = data(1:N, :);              % [600 x 2494]
PotLd  = data(N+1:2*N, :);
SpLd   = data(2*N+1:3*N, :);
SpMtr  = data(3*N+1:4*N, :);
SpRef  = data(4*N+1:5*N, :);

%% Áp dụng bộ lọc trung vị cho tín hiệu (median filter)
windowSize = 11;  % cửa sổ lọc (số lẻ, điều chỉnh được)

for i = 1:size(IdcMtr, 1)
    IdcMtr(i, :) = medfilt1(IdcMtr(i, :), windowSize);
    SpMtr(i, :)  = medfilt1(SpMtr(i, :),  windowSize);
    SpLd(i, :)   = medfilt1(SpLd(i, :),   windowSize);
end

%% Tính Speed Error & Idc max
SpeedError = abs(SpMtr - SpRef);     

% Bỏ qua cột đầu tiên (time = 0)
SpeedError(:,1) = NaN;  % hoặc SpeedError(:,1) = -inf nếu không muốn dùng NaN
[maxError, idxMaxErr] = max(SpeedError(:), [], 'omitnan');   % bỏ qua NaN
[rowErr, colErr] = ind2sub(size(SpeedError), idxMaxErr);
timeErr = time(colErr);                       % thời điểm max error
SpRefAtMaxErr = SpRef(rowErr, colErr);

[maxIdc, idxIdc] = max(IdcMtr(:));
% Tính RMS Current
rmsIdc = sqrt(mean(IdcMtr(:).^2));
[rowIdc, colIdc] = ind2sub(size(IdcMtr), idxIdc);
SpAtMaxIdc = SpMtr(rowIdc, colIdc);
PotAtMaxIdc = PotLd(rowIdc, colIdc);
timeIdc = time(colIdc);

%% Tính Response Time (so sánh SpeedMtr vs SpeedRef theo trung bình mỗi 0.03s)
dt = 0.03;              % bước thời gian kiểm tra
threshold = 0.10;       % sai số 5%
deltaRef = 50;          % ngưỡng thay đổi để xét
responseTimes = [];

for i = 1:N
    ref = SpRef(i, :);
    mtr = SpMtr(i, :);
    dRef = [0 diff(ref)];
    changeIdx = find(abs(dRef) > deltaRef);  % tìm thời điểm ref thay đổi

    j = 1;
    while j <= length(changeIdx)
        % Tìm đoạn bắt đầu thay đổi liên tiếp
        startIdx = changeIdx(j);
        endIdx = startIdx;
        while j < length(changeIdx) && time(changeIdx(j+1)) - time(changeIdx(j)) <= dt
            endIdx = changeIdx(j+1);
            j = j + 1;
        end

        % Xác định vùng thay đổi ref (từ startIdx đến endIdx)
        tStart = time(startIdx);
        refNew = ref(endIdx + 1);
        j = j + 1;

        % Xác định giới hạn sai số
        if abs(refNew) > 50
            lowerBound = refNew - 50;
            upperBound = refNew + 50;
        else
            lowerBound = refNew * (1 - threshold);
            upperBound = refNew * (1 + threshold);
        end

        % Bắt đầu quét mỗi 0.03s sau thời điểm startIdx
        tResp = NaN;
        idx = startIdx;
        while time(idx) <= time(end) - dt
            tWindow = time >= time(idx) & time < time(idx) + dt;
            avgMtr = mean(mtr(tWindow));

            if avgMtr >= lowerBound && avgMtr <= upperBound
                tResp = time(idx) - tStart;
                break;
            end
            idx = idx + 1;
        end

        if ~isnan(tResp)
            responseTimes(end+1) = tResp;
        end
    end
end

% Tính max và mean (bỏ max ra khỏi mean)
if ~isempty(responseTimes)
    maxRespTime = max(responseTimes);
    epsilon = 1e-6;
    responseTimesWithoutMax = responseTimes(abs(responseTimes - maxRespTime) > epsilon);
    meanRespTime = mean(responseTimesWithoutMax);
else
    maxRespTime = NaN;
    meanRespTime = NaN;
end

%% Tiled layout
t = tiledlayout(2, 3, 'TileSpacing', 'compact', 'Padding', 'compact');
title(t, 'Dual PMSM synchronous control');

% Subplot 1: Idc
nexttile(1);
plot(time, IdcMtr', 'Color', [0 0.5 0 0.2]); hold on;
xlabel('Time (s)'); ylabel('Amp'); title('Idc Motor'); grid on;

% Subplot 2: Speed Motor + Ref
nexttile(2);
plot(time, SpMtr', 'Color', [0 0 1 0.2]); hold on;
plot(time, SpRef', 'Color', [1 0.5 0 0.3], 'LineWidth', 1.2);

% Vẽ rõ kênh đầu tiên
h1 = plot(time, SpMtr(1,:)', 'Color', [0 0 1], 'LineWidth', 1.5);
h2 = plot(time, SpRef(1,:)', 'Color', [1 0.5 0], 'LineWidth', 1.5);

legend([h1, h2], {'Speed Motor', 'Speed Ref'}, 'Location', 'best');
xlabel('Time (s)'); ylabel('RPM'); title('Speed Motor vs Ref'); grid on;

% Subplot 3: POT
nexttile(4);
plot(time, PotLd', 'Color', [1 0 0 0.2]); hold on;
xlabel('Time (s)'); ylabel('%'); title('POT Load'); grid on;

% Subplot 4: Speed Load
nexttile(5);
plot(time, SpLd', 'Color', [0.6 0.3 0.0]);
xlabel('Time (s)'); ylabel('RPM'); title('Speed Load'); grid on;

% Subplot 5: Info box
nexttile(3, [2 1]);
axis off;
rectangle('Position', [0 0 1 1], 'EdgeColor', 'k', 'LineWidth', 1.5);

% Speed Error (%)
errorPercent = (maxError / SpRefAtMaxErr) * 100;
text(0.05, 0.92, ...
    ['Speed Tracking Error:  \bf' num2str(maxError, '%.2f') '\rm RPM  (' ...
     '\bf' num2str(errorPercent, '%.2f') '\rm%)'], ...
    'FontSize', 14, 'Color', [0 0 1]);

text(0.05, 0.82, sprintf('At Ref = \\bf%.2f\\rm RPM \n\nTime = \\bf%.2fs', SpRefAtMaxErr, timeErr), ...
    'FontSize', 12);

% Response Time (moved up here)
text(0.05, 0.72, sprintf('Response Time (Max):  \\bf%.3f\\rm s', maxRespTime), ...
    'FontSize', 13, 'Color', [0.8 0 0.8]);
text(0.05, 0.66, sprintf('Response Time (Mean):  \\bf%.3f\\rm s', meanRespTime), ...
    'FontSize', 13, 'Color', [0.8 0 0.8]);

line([0.05 0.95], [0.60 0.60], 'Color', 'k', 'LineStyle', '--');  % moved separator line

% MAX CURRENT
text(0.05, 0.52, sprintf('Max Motor Current:  \\bf%.2f\\rm A', maxIdc), ...
    'FontSize', 14, 'Color', [0 0.5 0]);

text(0.05, 0.42, sprintf('At Speed = \\bf%.1f\\rm RPM \n\nLoad Duty = \\bf%.1f\\rm%%', SpAtMaxIdc, PotAtMaxIdc), ...
    'FontSize', 12);
text(0.05, 0.32, sprintf('Time = \\bf%.2fs', timeIdc), ...
    'FontSize', 12);

% Hiển thị RMS Current
text(0.05, 0.22, sprintf('RMS Motor Current:  \\bf%.2f\\rm A', rmsIdc), ...
    'FontSize', 13, 'Color', [0 0.4 0.8]);

% Model         :   PMSM Field Oriented Control
% Description   :   Set Parameters for Motor, Inverter and Controllers
%               :   for simulating the FOC control algorithm for PMSM
% File name     :   mcb_pmsm_foc_sim_data.m

% Copyright 2020 The MathWorks, Inc.

%% Set PWM Switching frequency
PWM_frequency 	= 20e3;    %Hz          // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s  // PWM switching time period

%% Set Sample Times
Ts          	= T_pwm;        %sec        // Sample time step for controller
Ts_simulink     = T_pwm/2;      %sec        // Simulation time step for model simulation
Ts_motor        = T_pwm/2;      %Sec        // Simulation sample time
Ts_inverter     = T_pwm/2;      %sec        // Simulation time step for average value inverter
Ts_speed        = 10*Ts;        %Sec        // Sample time for speed controller

%% Set data type for controller & code-gen
dataType = fixdt(1,32,17);    % Fixed point code-generation
% dataType = 'single';            % Floating point code-generation

%% System Parameters // Hardware parameters 

% Set target hardware parameters
target = mcb_SetProcessorDetails('F28069M',PWM_frequency);

pmsm = mcb_SetPMSMMotorParameters('Teknic2310P');
pmsm.PositionOffset = 0.165;

%% Parameters below are not mandatory for offset computation

inverter = mcb_SetInverterParameters('BoostXL-DRV8305');

% Voltage output of inverter current sense circuit
inverter.ISenseVoltPerAmp = inverter.ISenseVoltPerAmp * inverter.ADCGain; 

% Update ISenseMax that is measurable by target ADC
inverter.ISenseMax = inverter.ISenseMax * target.ADC_Vref / inverter.ISenseVref;

% Update ISenseMax according to set ADC gain
inverter.ISenseMax = inverter.ISenseMax/inverter.ADCGain;

% Max and min ADC counts for current sense offsets
inverter.CtSensOffsetMax = 2500; % Maximum permitted ADC counts for current sense offset
inverter.CtSensOffsetMin = 1500; % Minimum permitted ADC counts for current sense offset

%% Derive Characteristics
pmsm.N_base = mcb_getBaseSpeed(pmsm,inverter); %rpm // Base speed of motor at given Vdc

% mcb_getCharacteristics(pmsm,inverter);

%% PU System details // Set base values for pu conversion

PU_System = mcb_SetPUSystem(pmsm,inverter);


%% Controller design // Get ballpark values!

PI_params = mcb_SetControllerParameters(pmsm,inverter,PU_System,T_pwm,Ts,Ts_speed);

%Updating delays for simulation
PI_params.delay_Currents    = int32(Ts/Ts_simulink);
PI_params.delay_Position    = int32(Ts/Ts_simulink);
PI_params.delay_Speed       = int32(Ts_speed/Ts_simulink);
PI_params.delay_Speed1      = (PI_params.delay_IIR + 0.5*Ts)/Ts_speed;

% mcb_getControlAnalysis(pmsm,inverter,PU_System,PI_params,Ts,Ts_speed); 

%% Displaying model variables
disp(pmsm);
disp(inverter);
disp(target);
disp(PU_System);
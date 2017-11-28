%% SETUP_LAB_HELI_3D
%
% This script sets the model parameters and designs a PID position
% controller using LQR for the Quanser 3-DOF Helicopter plant.
%
% Copyright (C) 2007 Quanser Consulting Inc.
% Quanser Consulting Inc.
%
clear all;

%% ############### USER-DEFINED 3-DOF HELI CONFIGURATION ###############
% Amplifier Gain used for yaw and pitch axes: set VoltPAQ to 3. 
% When using UPM set K_AMP to 5.
K_AMP = 5;
% Amplifier Maximum Output Voltage (V)
VMAX_AMP = 24;
% Digital-to-Analog Maximum Voltage (V): set to 10 for Q4/Q8 cards
VMAX_DAC = 10;
% Initial elvation angle (rad)
elev_0 = -27.5*pi/180;


%% ############### USER-DEFINED DESIRED COMMAND SETTINGS ###############
% Note: These limits are imposed on both the program and joystick commands.
% Elevation position command limit (deg)
CMD_ELEV_POS_LIMIT_LOWER = elev_0*180/pi;
CMD_ELEV_POS_LIMIT_UPPER = -CMD_ELEV_POS_LIMIT_LOWER;
% Maximum Rate of Desired Position (rad/s)
CMD_RATE_LIMIT = 45.0 * pi / 180;


%% ############### USER-DEFINED JOYSTICK SETTINGS ###############
% Joystick input X sensitivity used for travel (deg/s/V)
K_JOYSTICK_X = 40.0;
% Joystick input Y sensitivity used for elevation (deg/s/V)
K_JOYSTICK_Y = 45.0;


%% ############### MODELING ###############
% These parameters are used for model representation and controller design.
[ Kf, m_h, m_w, m_f, m_b, Lh, La, Lw, g, K_EC_T, K_EC_P, K_EC_E ] = setup_heli_3d_configuration();
%
% For the following state vector: X = [ elevation; pitch; travel, elev_dot, pitch_dot, travel_dot]
% Initialization the state-Space representation of the open-loop System
HELI3D_ABCD_eqns;

K = zeros(2,6);
L = zeros(3,6);

% Add this bias onto U when K and L have been determined
Vo = -1/2*g*(-m_w*Lw + m_f*La + m_b*La ) / (La*Kf);% + 2.0;

%% ############### OBSERVER DESIGN ###############

% slow dominant pole
%P_L = [-12+3j, -12-3j, -50+12.5j, -50-12.5j,-36+9j, -36-9j]';

% faster dominant pole
P_L = [-28+7j, -28-7j, -32+8j, -32-8j,-18+4.5j, -18-4.5j]';

L = place(A',C',P_L)';

%% ############### STATE FEEDBACK DESIGN - No Integral Control ###############

% q_eps = 1/(0.002*((12*pi/180)^2));
% q_rho = 1/(2*((25*pi/180)^2));
% q_lambda = 1/(0.005*((10*pi/180)^2));
% q_epsd = 1/(0.1*((5*pi/180)^2));
% q_rhod = 1/(0.35*((8*pi/180)^2));
% q_lambdad = 1/(0.1*((3*pi/180)^2));
% 
% rho_sf = 900.0;

% q_eps = 1;
% q_rho = 1;
% q_lambda = 1;
% q_epsd = 1;
% q_rhod = 1;
% q_lambdad = 1;

% r_Vf = 1/(15)^2;
% r_Vb = 1/(15)^2;
% 
% Qx = [[q_eps 0 0 0 0 0];
%     [0 q_rho 0 0 0 0];
%     [0 0 q_lambda 0 0 0];
%     [0 0 0 q_epsd 0 0];
%     [0 0 0 0 q_rhod 0];
%     [0 0 0 0 0 q_lambdad]];
% 
% Qu = rho_sf*[[r_Vf 0];
%     [0 r_Vb]];
% 
% C_0 = [[C(1,:)];
%     [C(3,:)]];
% 
% K = lqr(A, B, Qx, Qu);
% K_r = [-1.8974 -4.2426; -1.8974 4.2426];
%K_r = (-C_0*inv(A - B*K)*B)^-1;

%% ############### STATE FEEDBACK DESIGN WITH INTEGRAL ACTION ###############
% output of observer for steady state reference; the input from the
% controller controls elevation and travel, these are 
C_0 = [[C(1,:)];
    [C(3,:)]];

sys_i = ss(A, B, C_0, 0);

% States
q_eps = 1/(0.1*((7*pi/180)^2));
q_rho = 1/(5*((20*pi/180)^2));
q_lambda = 1/(8*((15*pi/180)^2));
q_epsd = 1/(0.5*((5*pi/180)^2));
q_rhod = 1/(0.2*(5*pi/180)^2);
q_lambdad = 1/(0.1*((4*pi/180)^2));

% Integral
q_eps_i = 1/(25*((0.5*pi/180)^2));
q_lambda_i = 1/(25*((0.5*pi/180)^2));

% Input Scaling
rho_sf = 800.0;

% Input
r_Vf = 1/(15)^2;
r_Vb = 1/(15)^2;

% LQR Matrices
Qx_i = [[q_eps 0 0 0 0 0 0 0];
    [0 q_rho 0 0 0 0 0 0];
    [0 0 q_lambda 0 0 0 0 0];
    [0 0 0 q_epsd 0 0 0 0];
    [0 0 0 0 q_rhod 0 0 0];
    [0 0 0 0 0 q_lambdad 0 0]
    [0 0 0 0 0 0 q_eps_i 0];
    [0 0 0 0 0 0 0 q_lambda_i]];

Qu_i = rho_sf*[[r_Vf 0];
    [0 r_Vb]];

% LQR Gain
K = lqi(sys_i, Qx_i, Qu_i, 0);

% Reference Gain
K_r = (-C_0*inv(A - B*K(:,1:6))*B)^-1;

% Integral Gain
K_i = -K(:,7:8);

% State Feedback Gain
K_sf = K(:,1:6);
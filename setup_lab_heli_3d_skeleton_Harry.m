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
Vo = -1/2*g*(-m_w*Lw + m_f*La + m_b*La ) / (La*Kf) + 2.0;
%Vo = 0;


%% ############### OBSERVER DESIGN ###############

P_L = [-12, -12, -10+2j, -10-2j,-8+1.5j, -8-1.5j]';
%P_L = [-12, -12, -10, -10,-4+1j, -4-1j]';

L = place(A',C',P_L)'; %zeros(3,6);

%% ############### STATE FEEDBACK DESIGN ###############

q_eps = 1/(0.7*((8*pi/180)^2));
q_rho = 1/(0.1*((10*pi/180)^2));
q_lambda = 1/(0.01*((15*pi/180)^2));
q_epsd = 1/(0.6*((2*pi/180)^2));
q_rhod = 1/(0.2*((1*pi/180)^2));
q_lambdad = 1/(0.05*((2*pi/180)^2));

% q_eps = 1/(0.7*((8*pi/180)^2));
% q_rho = 1/(0.6*((10*pi/180)^2));
% q_lambda = 1/(0.001*((15*pi/180)^2));
% q_epsd = 1/(0.6*((2*pi/180)^2));
% q_rhod = 1/(0.5*((1*pi/180)^2));
% q_lambdad = 1/(0.005*((2*pi/180)^2));

% q_eps = 1;
% q_rho = 1;
% q_lambda = 1;
% q_epsd = 1;
% q_rhod = 1;
% q_lambdad = 1;


rho_sf = 7000.0;

r_Vf = 1/(11)^2;
r_Vb = 1/(11)^2;

Qx = [[q_eps 0 0 0 0 0];
    [0 q_rho 0 0 0 0];
    [0 0 q_lambda 0 0 0];
    [0 0 0 q_epsd 0 0];
    [0 0 0 0 q_rhod 0];
    [0 0 0 0 0 q_lambdad]];

Qu = rho_sf*[[r_Vf 0];
    [0 r_Vb]];

C_0 = [[C(1,:)];
    [C(3,:)]];

K = lqr(A, B, Qx, Qu);
% K_r = [-1.8974 -4.2426; -1.8974 4.2426];
K_r = (-C_0*inv(A - B*K)*B)^-1;

%% ############### KALMAN FILTER DESIGN ###############

q_eps = 1/(0.7*((8*pi/180)^2));
q_rho = 1/(0.1*((10*pi/180)^2));
q_lambda = 1/(0.01*((15*pi/180)^2));
q_epsd = 1/(0.6*((2*pi/180)^2));
q_rhod = 1/(0.2*((1*pi/180)^2));
q_lambdad = 1/(0.05*((2*pi/180)^2));

rho_L = 7000.0;

r_Vf_L = 1/(11)^2;
r_Vb_L = 1/(11)^2;

Qx_L = [[q_eps 0 0 0 0 0];
    [0 q_rho 0 0 0 0];
    [0 0 q_lambda 0 0 0];
    [0 0 0 q_epsd 0 0];
    [0 0 0 0 q_rhod 0];
    [0 0 0 0 0 q_lambdad]];

Qu_L = rho_sf*[[r_Vf_L 0];
    [0 r_Vb_L]];

C_0 = [[C(1,:)];
    [C(3,:)]];

L = lqr(A, C', Qx_L, Qu_L);
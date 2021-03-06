%close all;
% Define parameters
M = 10;
m = 80;
c = 0.1;
l = 1;
rho = 0.01;
g = 9.81;

%% Question 2, calculate the eigenvalues of the non-linear (simulink) model
sys = linmod('PBA3_2_2', [0, 0, 0, 0], 0);
% 
% EIG_sim = eig(sys.a)
% 
%% Generate a K matrix for the selected pole placement
% P = [-2 -2 -8 -8];                 %stable, th_max = 2.8degrees for 68.4N force applied for 1sec
%P = [-1+0.5i -1-0.5i -2+1i -2-1i];          %unstable for 68.4N force applied for 1sec
P = [-4+2i -4-2i -20+10i -20-10i];           % th_max = 1.6e-3 rad for 68.4N force applied for 1sec
% % % %P = [-400 -500 -505 -600];
%P = [-1 -1 -2 -2];                           %very unstable
% 
K = acker(sys.a, sys.b, P);

%% Pole Placement Notes

% having large poles -> response time too quick for motors, more
% subseptible to disturabances / high frequency forcing

% having poles too low -> slower response time, larger displacement /
% overshoot, resulting in larger drifting on p due to mass on larger angle
% before compensation

% including complex conjugate poles increases rise time -> decreases
% drift on position p, at the expense of (very) small amplitude oscillation
% / overshoot before settling if 1 > zeta > 0.707.

%% Plot the step response of the controlled system
con_sys = linmod('PBA3_4', [0, 0, 0, 0], 0);
[Num, Den] = ss2tf(con_sys.a, con_sys.b, con_sys.c, con_sys.d);
T_pos = tf(Num(1,:), Den);
T_theta = tf(Num(2,:), Den);
figure(1); hold on; step(T_pos); step(T_theta); hold off;

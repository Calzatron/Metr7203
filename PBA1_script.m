%%%  METR7203 PBA1

%% Declare Vaiables
global alpha
global wm

m = 1200;
Tm = 200;
wm(1) = 450;
beta = 0.35;
alpha = {40, 35, 16, 12, 10};
g = 9.81;
Cf = 0.01;
p = 1.3;
Cd = 0.36;
A = 2.2;
gear = 3;
%% Proportional Integral Controller
% Ku = 5
% Tu = 1.1
% Kp = 0.45*Ku
% Ki = 0.54*Ku/Tu

Kp = 3.5
Ki = 0.01


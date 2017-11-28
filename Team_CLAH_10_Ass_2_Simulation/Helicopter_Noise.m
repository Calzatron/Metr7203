%% Continuous White Noise Model

% get system parameters
[ Kf, m_h, m_w, m_f, m_b, Lh, La, Lw, g, K_EC_T, K_EC_P, K_EC_E ] = setup_heli_3d_configuration();
% get state-space model
HELI3D_ABCD_eqns;
% create room in the system matrices
G = zeros(6,2); H = zeros(3,2);
% create a discrete-time system with zoh
SYS = ss(A,[B G],C,[D H]);
SYS = c2d(SYS, 0.012, 'zoh');

%   Q  = integral(F(t) * Qc * F(t)') between 0 and discrete interval delta
%   t. Qc is a 3x3 matrix with one 1 at (3,3), phi is the spectral density 
%   of white noise, a tuning factor that scales Qc

phi =40000000;
Qc = zeros(3,3); n = size(Qc, 1); Qc(n,n) = 1;
Qc = phi*Qc;
syms t
%F = [1 t t^2/2 t^3/6 t^4/12 t^5/60; 0 1 t t^2/2 t^3/6 t^4/12; 0 0 1 t t^2/2 t^3/6; 0 0 0 1 t t^2/2; 0 0 0 0 1 t; 0 0 0 0 0 1];
F = [1 t t^2/2; 0 1 t; 0 0 1];
Q = eval(int(F*Qc*F', t, 0, 0.012));
%Q = eval(diag([Q(1,1), Q(2,2), Q(3,3)]));

% previous Q didn't work, this Q is a matrix based off process noise
% variance
Q = phi*diag([0.002, 0.0005, 0.003]);
Q = diag([0.0014 1.6229e-31 3.7599e-07])

% make the sensor noise matrix, with variance as diagonal elements
R = zeros(3,3); R(1,1) = 8.1846e-06; R(2,2) = 0.00000001; R(3,3) = 0.0000005;
R = 1*R;

% evaluate the kalman filter for L
[KEST,L,P] = kalman(SYS,Q,R);
L

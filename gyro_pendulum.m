%% inverted pendulum controlled by gyroscope
clear all
syms m l c rho gamma g th1_dd th1_d th1 th2_dd th2_d th2 th3 t real

syms I_fwx I_fwz J w_fw real

%% Lagrange
% Lagrangian = Kinetic Energy - Potential Energy
T = (1/2)*m*(rho*sin(th1_d) + l*th2_d*cos(th2))^2 + (1/2)*m*(l*th2_d*sin(th2))^2 + (1/2)*J*th1_d^2;
V = m*g*l*cos(th2);

L = T - V;

% Equations of motion: d/dt (pdL/ pdq_d) - (pdL/pdq) = Q 
%(Q makes up the non-conservative forces acting on the system),
% q is a state-variable,
% pd denotes partial derivative,
% the right-hand side of the above equation will be denoted L_q for state
% variable q; this implies that Q - L_q = 0

% find L_q's given p's first and second derivative is p_d and p_dd
% and theta's derviative is th_d and th_dd
% the lagrange function assumes V contains up to the second derivative of
% each variable
V = [th1, th1_d, th1_dd, th2, th2_d, th2_dd];
L_ = lagrange(L, V);

% for linear position
Q_p = t - c*th1_d + I_fwx*sin(th3)*w_fw*th1_d;
L_p = L_(1);

% for pendulum angle
Q_th = -gamma*th2_d;
L_th = L_(2);

%% Equations of Motion
% writing the equations of motion, whilst collecting  the variables of interest, V
eom1 = collect(simplify(Q_p - L_p), V);
eom2 = collect(simplify(Q_th - L_th), V);

%% State Space Representation
% define state variables and rewrite eom
syms x_1 x_2 x_3 x_4 real

x = [x_1; x_2; x_3; x_4];
x_T = transpose(x);

% where x_1 = p, x_2 = th, x_3 = p_d, x_4 = th_d

eom_s1 = subs(eom1, [th1 th1_d th2 th2_d], x_T);
eom_s2 = subs(eom2, [th1 th1_d th2 th2_d], x_T);

% contruct statespace imput function x_d = F(x)
% prepare state variables
x_d = solve(eom_s1,eom_s2, th1_dd, th2_dd);    %solve for p_dd and th_dd

x_1d = x_3;                                 % x_1d = p_d
x_2d = x_d.th1_dd;                                % x_2d = th_d
x_3d = x_4;                         % x_3d = p_dd
x_4d = x_d.th2_dd;                           % x_4d = th_dd

% x = [th1; th1_d; th2; th2_d];
% x_T = transpose(x);

% write the state-space representation
F_x = [ x_1d; x_2d; x_3d; x_4d ];
F_x = collect(F_x, x);

% solve the jacobian about an equilibrium position
equ = [0 0 0 0];                %define an equilibrium position

% rewrite input function in the form
% x_d = Ax + Bu
A = simplify(subs(jacobian(F_x, x), x_T, equ));
B = simplify(subs(jacobian(F_x, t), x_T, equ));

%J_w = 0.1530

% J = 0.1314
% I_fwx = 0.0273;
% I_fwz = 0.0148;
% m = 0.158;
% l = 0.2698;
% c = 1;
% gamma = 0;
% rho = 0.37
% w_fw = 400*2*pi/60;

A_ = simplify(subs(A, [th3 J I_fwx I_fwz m l c gamma rho w_fw g], [0 0.1314 0.0273 0.0148 0.158 0.2698 1 0 0.37 400*2*pi/60 9.81]));

B_ = simplify(subs(B, [th3 J I_fwx I_fwz m l c gamma rho w_fw g], [0 0.1314 0.0273 0.0148 0.158 0.2698 1 0 0.37 400*2*pi/60 9.81]));

%% Solution
syms J1_bar Jz_bar m Rh lcg c1 grav Kenc4 Kenc3 Kenc2 RotorSpeed JD real
H=RotorSpeed*2*pi/60*JD;
a_param=1/((J1_bar)*Jz_bar-(m*Rh*lcg)^2);
Ksys_prime=H/Kenc2;
A1=[0 1 0 0];
A3=[0 0 0 1];
A2=a_param*[0 -c1*Jz_bar -m^2*lcg^2*Rh*grav*Kenc4/Kenc3 0];
A4=a_param*[0 c1*m*Rh*lcg*Kenc3/Kenc4 (J1_bar)*m*grav*lcg 0];
A_R = simplify([A1;A2;A3;A4]);
B_R= simplify(Ksys_prime*a_param*[0;Kenc4*Jz_bar;0;-Kenc3*m*Rh*lcg]);







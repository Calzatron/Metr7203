%% METR7203 Assignment 3 Part 1
%% mass and cart system derivation script

%% declare symbolic variables;
% masses, length, dampening constants, gravity, linear position, angle
% theta, cart force
syms m M l c rho g p_dd p_d p th_dd th_d th F real

%% Lagrange
% Lagrangian = Kinetic Energy - Potential Energy
T = (1/2)*m*(p_d - l*th_d*cos(th))^2 + (1/2)*m*(l*th_d*sin(th))^2 + (1/2)*M*p_d^2;
V = m*g*l*cos(th);

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
V = [p, p_d, p_dd, th, th_d, th_dd];
L_ = lagrange(L, V);

% for linear position
Q_p = F - c*p_d;
L_p = L_(1);

% for pendulum angle
Q_th = -rho*th_d;
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

eom_s1 = subs(eom1, [p th p_d th_d], x_T);
eom_s2 = subs(eom2, [p th p_d th_d], x_T);

% contruct statespace imput function x_d = F(x)
% prepare state variables
x_d = solve(eom_s1,eom_s2, p_dd, th_dd);    %solve for p_dd and th_dd

x_1d = x_3;                                 % x_1d = p_d
x_2d = x_4;                                 % x_2d = th_d
x_3d = x_d.p_dd;                            % x_3d = p_dd
x_4d = x_d.th_dd;                           % x_4d = th_dd

% write the state-space representation
F_x = [ x_1d; x_2d; x_3d; x_4d ];
F_x = collect(F_x, x);

% solve the jacobian about an equilibrium position
equ = [0 0 0 0];                %define an equilibrium position

% rewrite input function in the form
% x_d = Ax + Bu
A = simplify(subs(jacobian(F_x, x), x_T, equ));
B = simplify(subs(jacobian(F_x, F), x_T, equ));

A_ = simplify(subs(A, [M m c l rho g], [10 80 0.1 1 0.01 9.81]));
B_ = simplify(subs(B, [M m c l rho g], [10 80 0.1 1 0.01 9.81]));

EIG = simplify(eig(A_));

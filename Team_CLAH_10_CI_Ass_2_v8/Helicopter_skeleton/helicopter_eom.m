clear 
syms t Lw La Lh real;
eps = sym('eps(t)'); % epsilon
rho= sym('rho(t)'); % rho;
lambda= sym('lambda(t)'); % lambda

epsd = diff(eps, t);
rhod = diff(rho, t)
lambdad = diff(lambda, t);

% rotation about z *travel axis)
T_lambda = [cos(lambda), -sin(lambda), 0, 0;
           sin(lambda), cos(lambda), 0, 0; 
            0, 0, 1, 0; 
            0, 0, 0, 1]; 
% rotation about elevation axis. 
T_eps = [1, 0, 0, 0; 
     0, cos(eps), -sin(eps),  0; 
     0, sin(eps),  cos(eps), 0; 
     0, 0, 0, 1];

 
%rotatins about the pitch axis 
T_rho = [cos(rho), 0, -sin(rho), 0
       0 1 0 La
       sin(rho), 0, cos(rho), 0
       0 0 0 1]

% Compute the positions of the four masses Mw, Mh, Mb and Mf
w = T_lambda * T_eps * [0; -Lw; 0; 1];
h = T_lambda * T_eps * [0; La; 0; 1];
f = T_lambda * T_eps * T_rho * [Lh; 0; 0; 1]
b = T_lambda * T_eps * T_rho * [-Lh; 0; 0; 1]


syms Mw Mf Mh Mb g real
%
% Potential energy of the system A
%
V = Mw * g * w(3) +  Mf * g * f(3) + Mf * g * b(3); 

V = simplify(V)

%
% Kinetic entergy of the counterweight
%
vw = diff(w, t);
Tw = 1/2 * Mw * (vw(1) * vw(1) + vw(2) * vw(2) + vw(3)*vw(3))

%
% Kinetic energy of mass f
%
vf = diff(f, t)
Tf = 1/2 * Mf * (vf(1)*vf(1) + vf(2)*vf(2) + vf(3)*vf(3))

%
% Kinetic energy of mass b - note that Mb=Mf
%
vb = diff(b, t)
%Tb = 1/2 * Mb * (vb(1)*vb(1) + vb(2)*vb(2) + vb(3)*vb(3))
Tb = 1/2 * Mf * (vb(1)*vb(1) + vb(2)*vb(2) + vb(3)*vb(3))

%
% Kinetic energy of mass h - Mh is lumped with Mb and Mf
%
%vh = diff(h, t)
%Th = 1/2 * Mh * (vh(1)*vh(1) + vh(2)*vh(2) + vh(3)*vh(3))

T = Tw + Tf + Tb; 

%
% Lagrangian 
%
L = T - V;

syms q1 dq1 ddq1 q2 dq2 ddq2 q3 dq3 ddq3; 
L = subs(L, epsd, dq1);
L = subs(L, rhod, dq2);
L = subs(L, lambdad, dq3);
L = subs(L, eps, q1); 
L = subs(L, rho, q2);
L = subs(L, lambda, q3);


% Generalized forces 
%
syms Km Vb Vf 

Q1 = La * Km *(Vf + Vb);
Q2 = Lh * Km * (Vf - Vb);
Q3 = La * Km * (Vf + Vb) * sin(q2);

Q= [Q1, Q2, Q3];

EOM = Lagrange(L, [q1, dq1, ddq1, q2, dq2, ddq2, q3, dq3, ddq3]) - Q;

[e1, e2, e3] = solve(EOM(1), EOM(2), EOM(3), ddq1, ddq2, ddq3)
 
Jx = jacobian([e1, e2, e3], [q1, q2, q3, dq1, dq2, dq3]); 

Ju = jacobian([e1, e2, e3], [Vf, Vb])


% Define the operating point
Vop = -g * (Lw * Mw - 2 * Mf * La) / (2 * La * Km);
Vf = Vop; Vb = Vop;
q1 = 0; q2 = 0; q3 = 0; 
dq1 = 0; dq2 = 0; dq3 = 0; 


%Assemble the linearized state equations. 
A11 = zeros(3,3);
A12 = eye(3); 
A21 = simplify(eval(Jx))
A22 = zeros(3,3);

A = [A11, A12; A21]; 

B11 = zeros(3,2); B21 = simplify(eval(Ju));

B = [B11; B21]; 

C = [eye(3), zeros(3,3)];
D = 0;


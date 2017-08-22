clear all;

syms p Cd A Vr m g Cr Ki alpha Tm beta wm Kp v z Fd u L real


L = Kp*(Vr-v)+Ki*z;                         %Lambda
T = Tm*(1-beta*((alpha*v/wm)-1)^2);         %Torque
Fd = g*Cr*sign(v) - (1/(2*m))*p*Cd*A*v^2;   %Disturbance

% x' = F(x) 
F_vz = [(alpha/m)*L*T - Fd;
        Vr - v];

% evaluate a change in coordinates of F(x)
syms x y
F_vy = simplify(subs(F_vz, z, y + (m*Fd/(alpha*Ki*T))));
F_xy = simplify(subs(F_vy, v, x + Vr));

%collect terms and find Jacobian matrix A_
F_xy = collect(F_xy, [x, y]);
A_ = jacobian(F_xy, [x, y]);

%% construct the function F(x) = Ax + F_(x)
% higher order terms found in F_xy; a.k.a F_(x)
F_ = [((Kp*Tm*alpha^3*beta)/(m*wm^2))*x^3 + (-(Ki*Tm*alpha^3*beta)/(m*wm^2))*x^2*y + (-(Kp*Tm*alpha*(- 2*Vr*beta*alpha^2 + 2*beta*wm*alpha))/(m*wm^2))*x^2 + ((Ki*Tm*alpha*(- 2*Vr*beta*alpha^2 + 2*beta*wm*alpha))/(m*wm^2))*x*y;
        0];
% first order terms found in F_xy; A
A_1 = [((Kp*Tm*alpha*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta - 2*Vr*alpha*beta*wm))/(m*wm^2)), (-(Ki*Tm*alpha*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta - 2*Vr*alpha*beta*wm))/(m*wm^2));
            -1, 0];
        
%% find P_ for the Lyapunov function (As ^T)P_ +P_ As = Q, symbolically
% where Q is the negative identiy matrix. In this case, As contains unknown
% real, positive, coefficents

syms a_11 a_12 a_22 P_11 P_12 P_22 real
As = [a_11, -a_12; 1, 0];
P_ = [ P_11, P_12; P_12, P_22];
Q = -eye(2);
lyp = transpose(As)*P_+P_*As;
solve(lyp == Q, [P_11, P_12, P_22]);
P_ = simplify([ans.P_11, ans.P_12; ans.P_12, ans.P_22]);
D_ = det(P_);
E_ = simplify(eig(P_));           % check the eigenvalues of P > 0
T_ = simplify(trace(P_));         % check the trace of P > 0

%% Find P for the Lyapunov function (A^T)P+PA = Q, symbolically
syms p_11 p_12 p_22 real

P = [ p_11, p_12; p_12, p_22];
Q = -eye(2);
lyp = transpose(A_1)*P+P*A_1;
solve(lyp == Q, [p_11, p_12, p_22]);
P = simplify([ans.p_11, ans.p_12; ans.p_12, ans.p_22]);
E = simplify(eig(P));           % check the eigenvalues of P > 0
T = simplify(trace(P));         % check the trace of P > 0
%check result
EIG = subs(E, [Tm, wm, beta, alpha, g, Cr, p, Cd, A, Vr, Kp, Ki, m],[200, 450, 0.35, 16, 9.81, 0.01, 1.3, 0.36, 2.2, 20, 0.5, 0.1, 1000]);
TRACE = subs(T, [Tm, wm, beta, alpha, g, Cr, p, Cd, A, Vr, Kp, Ki, m],[200, 450, 0.35, 16, 9.81, 0.01, 1.3, 0.36, 2.2, 20, 0.5, 0.1, 1000]);
% gives eigenvalues 0.3506 and 3.9294 > 0
% trace of 4.28 > 0
% therefore asymptopically stable

%% check for global asymptopic stability
% check lim x-> ||F(x)||/||x|| is determinant

F_mag = (F_(1)^2+F_(2)^2)^0.5;                              %magnitude of higher order terms
x_mag = (x^2 + y^2)^0.5;                                    %magnitude of equ variables
Lim_x = limit(F_mag/x_mag, x, 0);
Lim_xy = limit(Lim_x, y, 0);
AS = subs(F_mag/x_mag, [x, y], [0.00000001,0.00000001]);    %computed for values of x and y close to 0
GAS = subs(AS, [Tm, wm, beta, alpha, g, Cr, p, Cd, A, Vr, Kp, Ki, m],[200, 450, 0.35, 16, 9.81, 0.01, 1.3, 0.36, 2.2, 20, 0.5, 0.1, 1000]);
% 
% Lim F_mag/x_mag | x,y -> 0,0 = 0 and
% GAS = 8.0433e+17 / 1.2360e+28
% therefore numerator goes to 0 first -> V(x) is a Lyapunov function
% for the non-linear system
%% show lyapunov function
V = collect([x, y]*P*[x; y], [x, y]);
% V = (m*wm^2*(m*wm^2 + Ki*Tm*alpha*wm^2 - Ki*Tm*alpha*beta*wm^2 - 
%   Ki*Tm*Vr^2*alpha^3*beta + 2*Ki*Tm*Vr*alpha^2*beta*wm)*x^2)/(2*Ki*Kp*Tm^2*
%   alpha^2*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta - 2*Vr*alpha*beta*wm)^2) +
%   (m*wm^2*x*y)/(Ki*Tm*alpha*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta - 2*Vr*
%   alpha*beta*wm)) - ((Ki*m*wm^2 + Ki^2*Tm*alpha*wm^2 + Kp^2*Tm*alpha*wm^2 -
%   Ki^2*Tm*Vr^2*alpha^3*beta - Kp^2*Tm*Vr^2*alpha^3*beta - Ki^2*Tm*alpha*
%   beta*wm^2 - Kp^2*Tm*alpha*beta*wm^2 + 2*Ki^2*Tm*Vr*alpha^2*beta*wm +
%    2*Kp^2*Tm*Vr*alpha^2*beta*wm)*y^2)/(2*Ki*Kp*Tm*alpha*(beta*wm^2 - wm^2 +
%   Vr^2*alpha^2*beta - 2*Vr*alpha*beta*wm))
 
 
V_ = collect([x, y]*P_*[x; y], [x, y]);
% V_ = - ((a_12 + 1)*x^2)/(2*a_11*a_12) + (x*y)/a_12 - 
%        ((a_11^2 + a_12^2 + a_12)*y^2)/(2*a_11*a_12)

%% match the parameter result to the symbolic result
% equating the symbolib and parameter coefficent expressions for x^2
% a_11 and a_12 can be found, represented by b_11 and b_12 respectively
syms b_11 b_12 real
Solv = solve((m*wm^2*(m*wm^2 + Ki*Tm*alpha*wm^2 - Ki*Tm*alpha*beta*wm^2 - Ki*Tm*Vr^2*alpha^3*beta + 2*Ki*Tm*Vr*alpha^2*beta*wm)*x^2)/(2*Ki*Kp*Tm^2*alpha^2*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta - 2*Vr*alpha*beta*wm)^2) == - ((a_12 + 1)*x^2)/(2*a_11*a_12), [a_12, a_11]);
b_12 = Solv.a_12(1);
b_11 = Solv.a_11(1);
E_solv = subs(E_, [a_11, a_12], [b_11, b_12]);
EIG_solv = simplify(subs(E_solv, [Tm, wm, beta, alpha, g, Cr, p, Cd, A, Vr, Kp, Ki, m],[200, 450, 0.35, 16, 9.81, 0.01, 1.3, 0.36, 2.2, 20, 0.5, 0.1, 1000]));

% it is therefore determined that the results are the same.
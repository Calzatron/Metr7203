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
        
%% find P for the Lyapunov function (A^T)P+PA = Q, 
% where Q is the negative identiy matrix. In this case, A_1 is used; as A 
% is already the variable for area, and A_ is the jacobian and so still 
% contains x and y variables

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
AS = subs(F_mag/x_mag, [x, y], [0.00000001,0.00000001]);    %computed for values of x and y close to 0
GAS = subs(AS, [Tm, wm, beta, alpha, g, Cr, p, Cd, A, Vr, Kp, Ki, m],[200, 450, 0.35, 16, 9.81, 0.01, 1.3, 0.36, 2.2, 20, 0.5, 0.1, 1000]);
%the denominator reaches 0 first, thus it is only locally asymptopically
%stable
% GAS = 8.0433e+17 / 1.2360e+28

%% show lyapunov function
V = [x, y]*P*[x; y];
% V = x*((m*wm^2*y)/(2*Ki*Tm*alpha*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta -
%     2*Vr*alpha*beta*wm)) + (m*wm^2*x*(m*wm^2 + Ki*Tm*alpha*wm^2 - Ki*Tm*alpha*beta*wm^2 - 
%     Ki*Tm*Vr^2*alpha^3*beta + 2*Ki*Tm*Vr*alpha^2*beta*wm))/(2*Ki*Kp*Tm^2*alpha^2*(beta*wm^2 
%     - wm^2 + Vr^2*alpha^2*beta - 2*Vr*alpha*beta*wm)^2)) - y*((y*(Ki*m*wm^2 + 
%     Ki^2*Tm*alpha*wm^2 + Kp^2*Tm*alpha*wm^2 - Ki^2*Tm*Vr^2*alpha^3*beta - Kp^2*Tm*Vr^2*alpha^3*beta - 
%     Ki^2*Tm*alpha*beta*wm^2 - Kp^2*Tm*alpha*beta*wm^2 + 2*Ki^2*Tm*Vr*alpha^2*beta*wm + 
%     2*Kp^2*Tm*Vr*alpha^2*beta*wm))/(2*Ki*Kp*Tm*alpha*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta - 
%     2*Vr*alpha*beta*wm)) - (m*wm^2*x)/(2*Ki*Tm*alpha*(beta*wm^2 - wm^2 + Vr^2*alpha^2*beta - 
%     2*Vr*alpha*beta*wm)));

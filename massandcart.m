
% Pendulum on a cart - see METR7203 Tutorial Sheet 1 problem 3 and compare with hand solution

syms p dp ddp th dth ddth t m M  l g  F c alpha  real %Define the symbolic variables.

% Define the Lagragian - 
L= 0.5 * M * dp^2 + 0.5 * m * (dp - l * dth * cos(th))^2 + 0.5 * m * (l * sin(th) * dth)^2 - m * g * l * cos(th);

V = [p, dp, ddp, th, dth, ddth];

% Generalized forces 
genfor = [F - c * dp, -alpha * dth];
% Calculate the equations of motion 
eom=lagrange(L,V) - genfor; 
eom = simplify(eom);

eom = collect(eom, V); 

% Form the equations of motion into the form dx = f(x,u)
S = solve(eom(1), eom(2),ddp, ddth);
f = [dp, dth, S.ddp, S.ddth]';

% Construct the Jacobian
x = [p, th, dp, dth];
Jacx = jacobian(f,x);
Jacu = jacobian(f,F);

% Choose the upright equilibrium
p = 0; dp = 0; th = 0; dth = 0; 
A = simplify(eval(Jacx))
B = simplify(eval(Jacu))
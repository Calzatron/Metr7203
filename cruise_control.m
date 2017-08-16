function dy = cruise_control(t, y)

%% dy = [v', z'] = [a, e];
% where v is the velocity and z is the integral state
% y = [v, z], which are the initial states
dy = zeros(2,1);    %define output
% parameters from assignment 1
Tm = 200;
wm = 450;
beta = 0.35;
alpha = {40, 35, 16, 12, 10};
g = 9.81;
Cr = 0.01;
p = 1.3;
Cd = 0.36;
A = 2.2;
% new parameters
Vr = 20;
Kp = 0.5;
Ki = 0.1;
m = 1000;
gear = 3;
theta = 0;
v = y(1);
z = y(2);

% controller
e = Vr - v;     %error between current velocity and regulated velocity
Gi = Ki * z;    %integral control component
Gp = Kp * e;    %proportional control component
u = Gp + Gi;    %controller output

% actuator
lambda = 0;
if u > 1
    lambda = 1; %max actuation / pedal to the floor
elseif u < 0
    lambda = 0; %minimum actuation / no pedal
else
    lambda = u;
end

% Trottle and Engine
alpha_ = alpha{gear};
w = alpha_*v;       % angular velocity
T = lambda*Tm*(1-beta*((w/wm)-1)^2);    %applied torque

% Applied force
F_app = alpha_*T;

% Disturbance forces
theta = theta*pi/180;
Ff = cos(theta)*m*9.81*Cr*sign(v);      %force due to friction
Fg = sin(theta)*m*9.81;                 %force due to gravity
Fa = 0.5*p*Cd*A*v^2;                    %force due to drag / air
F_d = Ff+Fg+Fa;                         %total disturbance force

% Total / Net force
F = F_app - F_d;

% Body
a = F/m;

dy(1) = a;      %derivative of velocity
dy(2) = e;      %derivative of integral state is current error

end


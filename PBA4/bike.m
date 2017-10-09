clear all;
close all;
% Parameters that are used for the Whipple bicycle model. The model is
% based on the linearized 4th order model and analysis of eigenvalues
% from IEEE CSM (25:4) August 2005 pp 26-47

%   Basic data is given by 26 parameters
g = 9.81;			% Acceleration of gravity [m/s^2]
b = 1.00;			% Wheel base [m]
c = 0.08;			% Trail [m]
Rrw = 0.35; Rfw = 0.35;		% Wheel radii
lambda = pi*70/180;		% Head angle [radians]

% Rear frame mass [kg], center of mass [m], and inertia tensor [kgm^2]
mrf=12;xrf=0.439;zrf=0.579;
Jxxrf=0.475656;Jxzrf=0.273996;Jyyrf=1.033092;Jzzrf=0.527436;
mrf=87;xrf=0.491586;zrf=1.028138;
Jxxrf=3.283666;Jxzrf=0.602765;Jyyrf=3.8795952;Jzzrf=0.565929;

% Front frame mass [kg], center of mass [m], and inertia tensor [kgm^2]
mff=2;xff=0.866;zff=0.676;
Jxxff=0.08;Jxzff=-0.02;Jyyff=0.07;Jzzff=0.02;

% Rear wheel mass [kg], center of mass [m], and inertia tensor [kgm^2]
mrw=1.5;Jxxrw=0.07;Jyyrw=0.14;

% Front wheel mass [kg], center of mass [m], and inertia tensor [kgm^2]
mfw=1.5;Jxxfw=0.07;Jyyfw=0.14;

% Auxiliary variables
xrw=0;zrw=Rrw;xfw=b;zfw=Rfw;
Jzzrw=Jxxrw;Jzzfw=Jxxfw;
mt=mrf+mrw+mff+mfw;
xt=(mrf*xrf+mrw*xrw+mff*xff+mfw*xfw)/mt;
zt=(mrf*zrf+mrw*zrw+mff*zff+mfw*zfw)/mt;
Jxxt=Jxxrf+mrf*zrf^2+Jxxrw+mrw*zrw^2+Jxxff+mff*zff^2+Jxxfw+mfw*zfw^2;
Jxzt=Jxzrf+mrf*xrf*zrf+mrw*xrw*zrw+Jxzff+mff*xff*zff+mfw*xfw*zfw;
Jzzt=Jzzrf+mrf*xrf^2+Jzzrw+mrw*xrw^2+Jzzff+mff*xff^2+Jzzfw+mfw*xfw^2;
mf=mff+mfw;
xf=(mff*xff+mfw*xfw)/mf;zf=(mff*zff+mfw*zfw)/mf;
Jxxf=Jxxff+mff*(zff-zf)^2+Jxxfw+mfw*(zfw-zf)^2;
Jxzf=Jxzff+mff*(xff-xf)*(zff-zf)+mfw*(xfw-xf)*(zfw-zf);
Jzzf=Jzzff+mff*(xff-xf)^2+Jzzfw+mfw*(xfw-xf)^2;
d=(xf-b-c)*sin(lambda)+zf*cos(lambda);
Fll=mf*d^2+Jxxf*cos(lambda)^2+2*Jxzf*sin(lambda)*cos(lambda)+Jzzf*sin(lambda)^2;
Flx=mf*d*zf+Jxxf*cos(lambda)+Jxzf*sin(lambda);
Flz=mf*d*xf+Jxzf*cos(lambda)+Jzzf*sin(lambda);
gamma=c*sin(lambda)/b;
Sr=Jyyrw/Rrw;Sf=Jyyfw/Rfw;St=Sr+Sf;Su=mf*d+gamma*mt*xt;

% Matrices for linearized fourth order model
M=[Jxxt -Flx-gamma*Jxzt;-Flx-gamma*Jxzt Fll+2*gamma*Flz+gamma^2*Jzzt];
K0=[-mt*g*zt g*Su;g*Su  -g*Su*cos(lambda)];
K2=[0 -(St+mt*zt)*sin(lambda)/b;0 (Su+Sf*cos(lambda))*sin(lambda)/b];
c12=gamma*St+Sf*sin(lambda)+Jxzt*sin(lambda)/b+gamma*mt*zt;
c22=Flz*sin(lambda)/b+gamma*(Su+Jzzt*sin(lambda)/b);
C0=[0 -c12;(gamma*St+Sf*sin(lambda)) c22]; 
one=diag([1 1]);null=zeros(2,2);

% Nominal velocity 
v0=5;


%% Part A
% M th_dd + C v0 th_d + (K0 + K2*v0) th = [0; T];
% where th = [gamma; delta] -> angles of bicycle dynamics
% let x1 = gamma, x2 = gamma_d, x3 = delta, x4 = delta_d
% thus, x1_d = x2, x2_d = gamma_dd
%       x3_d = x4, x4_d = delta_dd
% expand matrix equations for 2 eom in terms of state-variables

syms x1 x2 x3 x4 x1_d x2_d x3_d x4_d T real
% get coefficents from matrices
m1 = M(1,1); m2 = M(1,2); m3=M(2,1); m4=M(2,2);
c1 = C0(1,1); c2=C0(1,2); c3=C0(2,1); c4=C0(2,2);
K = [K0 + K2*v0^2];
k1 = K(1,1); k2=K(1,2); k3=K(2,1); k4=K(2,2);

% form equations of motion using state-variables

%x2_d = (-m2/m1)*x4_d - (c1*v0/m1)*x2 - (c2*v0/m1)*x4-(k1/m1)*x1-(k2/m1)*x3;
%x4_d = (-m3/m4)*x2_d - (c3*v0/m4)*x2 - (c4*v0/m4)*x4-(k3/m4)*x1 - (k4/m4)*x3 - T;

% rearrange and substitute expression for x2_d into eom of x4_d; eom2
x2_d_eqn = (-m2/m1)*x4_d - (c1*v0/m1)*x2 - (c2*v0/m1)*x4-(k1/m1)*x1-(k2/m1)*x3;
eom2 = (-m3/m4)*(x2_d_eqn) - (c3*v0/m4)*x2 - (c4*v0/m4)*x4-(k3/m4)*x1 - (k4/m4)*x3 + (T/m4) - x4_d;

% solve for x4_d and x2_d, solution denoted with _s
x4_d_s = collect(solve(eom2 == 0, x4_d), [x1; x2; x3; x4; T]);
x2_d_s = collect(subs(x2_d_eqn, x4_d, x4_d_s), [x1; x2; x3; x4; T]);
x1_d_s = x2;
x3_d_s = x4;

% construct state-space presentation
A = [0 1 0 0;...
     0 0 0 0;...
     0 0 0 1;...
     0 0 0 0];
 
 B = [0; 0; 0; 0];
 
 x = [x1; x2; x3; x4];

 % put the coeffients from the solution to x2_d, into A, 
 % and input term into B
[C_, T_] = coeffs(vpa(x2_d_s));

for i = 1:size(T_,2)
    if T_(i) == x1
        A(2, 1) = C_(i);
    elseif T_(i) == x2
        A(2, 2) = C_(i);
    elseif T_(i) == x3
        A(2, 3) = C_(i);
    elseif T_(i) == x4
        A(2, 4) = C_(i);
    elseif T_(i) == T
        B(2) = C_(i);
    end
end

% put the coeffients from x4_d into A, and input term into B
[C_, T_] = coeffs(vpa(x4_d_s));

for i = 1:size(T_,2)
    if T_(i) == x1
        A(4, 1) = C_(i);
    elseif T_(i) == x2
        A(4, 2) = C_(i);
    elseif T_(i) == x3
        A(4, 3) = C_(i);
    elseif T_(i) == x4
        A(4, 4) = C_(i);
    elseif T_(i) == T
        B(4) = C_(i);
    end
end

% view poles of the state-space model, in Hz
P_A = eig(A)/2/pi;

% findings: v0=5 yields two unstable poles, whilst v0=10 is stable
% 
% 
% x1_d  =         0    1.0000         0         0   * x1   +       0    * T
% x2_d       8.7611   -0.6370   23.2100    2.1486     x2      0.2922
% x3_d            0         0         0    1.0000     x3           0
% x4_d     -14.9477  -17.2465   29.1529  -12.9089     x4      7.9109

%% Part B
% u = -kx, x_d = Ax + Bu, y = Cx
% -> x_d = (A-Bk)x
% poles of closed loop system = eig(A-Bk)
% desired poles:
Pol = [-2 -10 -1+1i -1-1i];
% required feeback gain, k:
k = acker(A, B, Pol);

%k =
%    -1.2565    5.2073  -32.5252   -0.4145
clp = eig(A-B*k);
%% Part C
% with state-feedback and input at delta
kr = [0;0;-1;0];
A_f = A-B*k;
B_f = A*kr-B*k*kr;
C = [0 0 1 0];
D = 0;
sys_delta = ss(A_f,B_f,C,D);
opt = stepDataOptions;
opt.StepAmplitude = 0.002;
t = (0:0.05:10);
figure(1); hold on;
step(sys_delta, t, opt);
sys_gamma = ss(A_f,B_f,[1,0,0,0],D);
step(sys_gamma, t, opt);
sys_delta_d = ss(A_f,B_f,[0,0,0,1],D);
step(sys_delta_d, t, opt);
hold off;
% u = [];
% for n = 1:size(t,2)
%     if t(n) < 0.5
%         u(n) = 0;
%     else 
%         u(n) = 0.002;
%     end
% end
% 
% sys2 = ss(A_f,[0;0;1;0],C,D);
% syslqrcl=ss([A-B*k],B*k(:,1),C,0);
% figure(2); hold on;
% lsim(sys2, u, t);
% lsim(syslqrcl, u, t);
% hold off;
    

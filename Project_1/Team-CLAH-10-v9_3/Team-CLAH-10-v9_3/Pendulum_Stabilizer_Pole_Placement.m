

% This script builds the numerical transfer function and state space models
% for the Pendulum
% Inverted and noninverted dynamic models can be generated.  


%% INITIALIZE
% The following user-specified values vary with plant configuration
% Inverted v. noninverted operation
INV=1 % Set =+1 for inverted operation, =-1 for non-inverted

%ADJUSTABLE DYNAMIC PARAMETERS
yw=INV*.32;	%distance from rod pivot center to weight center
yr=INV*.42;	%distance from rod pivot center to end of rod

%FIXED PARAMETERS
% Body D - Gyro Rotor (incl reflected inertia of Motor #1) 
rho=8.6; %gm/cm^3 Brass
ro=10; %cm = 3.94 in
thick=2.5; % = 0.984 in
thickweb=0.64; % = 0.25 in
rweb=7;
rhol=1.68; % = 0.6625 in
Rhol=4.13; % = 1.625 in
Jmotor=75*10^(-7); %includes small pulley
gratio1=3.33; %motor/rotor gear ratio

mo=rho*thick*pi*ro^2/1000; %Mass of Disk w/o holes (kg)
Jo=1/2*mo*ro^2/10000; %Inertia of Disk w/o holes (kg-m^2)
mhol=6*(rho*thickweb*pi*rhol^2)/1000;  %Mass of holes (kg)
Jhol=mhol*(Rhol^2+1/2*rhol^2)/10000;  %Inertia of holes (kg-m^2)
mwebhol=rho*pi*(thick-thickweb)*rweb^2/1000;
Jwebhol=1/2*mwebhol*rweb^2/10000;
m_pulley=0.069; %mass of larger pulley
J_pulley=1/2*m_pulley*2.54^2/10000; %Inertia of pulley, OD = 2 in


mrotor=mo-mhol-mwebhol + m_pulley;
Jrotor=Jo-Jhol-Jwebhol + J_pulley;
mweb=(rho*0.63*pi*7^2-mhol)/1000;
Jweboffset=mweb*3.8^2/10000; %Inertia due to displacement of web from gimbal axis center, d2 direction


mD=mrotor;
ID=Jrotor/2+Jweboffset
JD=Jrotor + gratio1^2*Jmotor
KD=ID;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Body C: Inner Ring & Attachemnts (incl reflected inertia of Motor #2)
rho=2.7; %gm/cm^3, Al
thick_r1=1.25; %cm, = 0.5 in
height_r1=5.1; %cm, = 2.0 in
Rinner_r1=11.1; %cm, = 4.375 in
Router_r1=12.1; %cm, = 4.75 in
m_motor1=0.37; % 370g., incl encoder @ small pulley
R1_motor1= 5.7; % 2 in from rotor C.L. (in c1 dir. 2 in. from motor disk spin axis)
R2_motor1= 6.1; % 1 in + 4 cm from c1 C.L. (in c2 dir. 4 cm. is from motor front)
R3_motor1= 0; % (in c3 dir)
m_motor2=0.44; % 440g., incl mount, encoder, & pulley
R1_motor2= 7.6; % assume 3 in from rotor C.L. (in c1 dir. 2 in. from motor disk spin axis)
R2_motor2= 4.8; % assume 2 in from c1 C.L. (in c2 dir. 4 cm. is from motor front)
R3_motor2= 0; % (in c3 dir)
m_r1=rho*pi*height_r1*(Router_r1^2-Rinner_r1^2)/1000;
J_r1=1/2*m_r1*(Router_r1^2+Rinner_r1^2)/10000;
%m_c=.221; %measured mass of two plexiglass covers
m_c=.186; %measured mass of two plexiglass covers
J_c=m_c*12^2/2/10000; %Inertia of plexiglass
%R1_weights=7.7; %Avg value, measured
%R2_weights=4.0;
%R3_weights=0;
R1_weights=8.8; %Avg value, measured
R2_weights=3.2;
R3_weights=0;


%Cross Member & brass weights
thick_xmemb1=0.95; %cm = 3/8 in
L_xmemb1=2*Rinner_r1;
height_xmemb1=3.75; %cm, = 1.5 in
m_xmemb1=2*rho*thick_xmemb1*L_xmemb1*height_xmemb1/1000; %includes 2 cross members
J_xmemb1=m_xmemb1/12*(L_xmemb1^2+height_xmemb1^2)/10000;
%m_weights=.32; %measured, avg values
m_weights=.75; %measured, avg values

%Combined
mC=m_r1+m_xmemb1+m_motor1+m_motor2+m_weights;
IC=J_r1/2+J_c/2+(m_motor1*R2_motor1^2+m_motor2*R2_motor2^2+m_xmemb1*2^2+m_weights*R2_weights^2)/10000,%(x-member 2 cm from c1 axis)
JC=J_r1+J_c+(m_motor1*R1_motor1^2+1.25*m_motor2*R1_motor2^2+m_xmemb1*(1/12*(L_xmemb1^2+height_xmemb1^2))+m_weights*R1_weights^2)/10000,% 
KC=J_r1/2+J_c/2+(m_motor1*(R1_motor1^2+R2_motor1^2)+m_motor2*(R1_motor2^2+R2_motor2^2)+m_weights*(R1_weights^2+R2_weights^2)+m_xmemb1*(1/12*(L_xmemb1^2+thick_xmemb1^2)+2^2))/10000,%(x-member 2 cm from c1 axis)


%Body B: Outer Ring + Attachments
thick_r2=1.25; %cm, = 0.5 in
height_r2=3.75; %cm, = 1.5 in
Rinner_r2=14.0; %cm, = 5.5 in
Router_r2=15.2; %cm, = 6 in
m_r2=rho*pi*height_r2*(Router_r2^2-Rinner_r2^2)/1000;
J_r2=1/2*m_r2*(Router_r2^2+Rinner_r2^2)/10000;

%Inertia of Slipring, Capstan Pulley, and Limit Switches
m_slipring=0.05; % 50g.
R_slipring=17.2; % assume 6 in radius + 2 cm (in -b1 dir. 5.5 cm. is from gearhead front)
J_slipring=m_slipring*R_slipring^2/10000;
m_capstan=rho*pi*4.1^2*1.27/1000; %Dia = 8.2 cm (=3.25"), thckness = 1.27 cm (=0.5")
J_capstan=m_capstan*13.0^2/10000; %Radius of capstan pulley cg = 13.0 cm (=5.125")
m_limitswitches=.070; %measured, includes other misc hardware
J_limitswitches=m_limitswitches*14.0^2/10000; %Radius of capstan pulley cg = 14.0 cm (=5.52")


mB=m_r2+m_slipring+m_capstan+m_limitswitches;
IB=J_r2/2
JB=J_r2/2+J_slipring+J_capstan+J_limitswitches
KB=J_r2+J_slipring+J_capstan+J_limitswitches


%Body A: Base Fork (Neglect encoder etc at base)
%Vertical Side Plates
thick_r3=1.25; %cm = 0.5 in
width_r3=6.35; %cm = 2.5 in
height_r3=24.8; %cm, = 9.75 in
R_r3=15.8; %cm = 6.25 in
m_r3=2*rho*width_r3*height_r3*thick_r3/1000;
J_r3=m_r3*R_r3^2/10000; %(neglect rotation about its own cg.)

%Cross Member
thick_xmemb3=1.6; %cm = 5/8 in
L_xmemb3=33.0;%cm = 13 in
width_xmemb3=6.35; %cm = 2.5 in
m_xmemb3=rho*thick_xmemb3*L_xmemb3*width_xmemb3/1000;
J_xmemb3=m_xmemb3/12*(L_xmemb3^2+width_xmemb3^2)/10000;

%Corner Triangular braces
m_brace3=0.13; %Calculated, 2 members combined
R_brace3=13.0; %5.125 in
J_brace3=m_brace3*R_brace3^2/10000;

%Inertia of encoder/slip ring, etc (neglect rotation about its own cg.)
m_encoder3=0.38; %measured Encoder =330 (incl mounting plate), assume other components = 50g.
R_encoder3= 18.4; %7.25 in from vertical member C/L
J_encoder3=m_encoder3*R_encoder3^2/10000;

%Inertia of brake:
m_brake3=0.415; %measured 415g., incl mass of slipring
R_brake3= 18.8; %7.4 in from vertical member C/L
J_brake3=m_brake3*R_brake3^2/10000;

%Combined
m_yoke3=m_r3+m_xmemb3+m_brace3+m_encoder3+m_brake3;
J_yoke3spin=J_r3+J_xmemb3+J_brace3+J_encoder3+J_brake3;

mA=m_yoke3;
IA=J_yoke3spin/2; %WAG, Not used in Model
JA=J_yoke3spin/2; %WAG, Not used in Model
KA=J_yoke3spin

mw=0.089;	%Mass of weight (kg)
mr=.069;%;	%Mass of rod (kg)
Lr=INV*.43; %Total length of rod (m)

Rw=.050; %Radius of round weight (m), only used for detailed expressions of Jy and Jz_bar
grav=9.81; %Acceleration of gravity (m/s^2)

% YOU MUST FIRST RUN THE APPROPRIATE SCRIPTS FOR THE BASIC GYRO TO OBTAIN THE MASS PROPERTIES
RotorSpeed=400 %RPM 
H=RotorSpeed*2*pi/60*JD %Rotor Angular Momentum = Equiv Torque constant according to T = w x H (where q3 is small)
J1=ID+KC+KB+KA %Inertia of components rotating about the vertical axis
c1=1        %Friction coefficient for base (varies from unit to unit)
Rh=0.37 %Distance from yoke rotation axis to hub of pendulum (m)
Kenc2=3883; %Counts / radian
Kenc3=2608; %Counts / radian
Kenc4=2546; %Counts / radian
Ksys_prime=H/Kenc2  %N-m/(counts/sec)

% Derived Properties
m=mr+mw;
lcgr=yr-Lr/2;
lcg=(mr*lcgr+mw*yw)/m;

%SOLVE FOR INERTIA PARAMETERS
J1_bar=J1+m*Rh^2;
Jz_bar=mr*(Lr^2/12+lcgr^2)+mw*yw^2;
Jy=0;

%The following may be used if Rw is to be accounted for (generally this may be neglected)
%Jz_bar=mr*(Lr^2/12+lcgr^2)+mw*(1/2*Rw^2+yw^2);
%Jy=mw*Rw^2/4;
	
%Transfer Function Expressions - these might be usful to you. 
N1=Kenc4*Ksys_prime*[Jz_bar 0 -m*grav*lcg];
N2=-[Kenc3*Ksys_prime*m*Rh*lcg 0];
d_den=[(J1_bar+Jy)*Jz_bar-(m*Rh*lcg)^2 c1*Jz_bar -(J1_bar+Jy)*m*grav*lcg -c1*m*grav*lcg];
N1=N1/d_den(1),N2=N2/d_den(1),d_den=d_den/d_den(1); %Makes d_den monic
D1=[d_den 0];
D2=d_den;

%%

%State Space realization
% The input to the system is the angular speed of gymbal axis 2. 
% The states are:
%     theta1 - angular rotation about the vertical axis. 
%     theta1_dot - angular speed of rotation about the vertical axis. 
%     theta2 - pendulum angle. 
%     theta2_dot - angular speed of the pendulum 

a_param=1/((J1_bar+Jy)*Jz_bar-(m*Rh*lcg)^2);
A1=[0 1 0 0];
A3=[0 0 0 1];
A2=a_param*[0 -c1*Jz_bar -m^2*lcg^2*Rh*grav*Kenc4/Kenc3 0];
A4=a_param*[0 c1*m*Rh*lcg*Kenc3/Kenc4 (J1_bar+Jy)*m*grav*lcg 0];
A=[A1;A2;A3;A4]
B=Ksys_prime*a_param*[0;Kenc4*Jz_bar;0;-Kenc3*m*Rh*lcg]

P_mat = [-8+4i, -8-4i, -40+20i, -40-20i] % Desired pole positions

K_mat = acker(A, B, P_mat)





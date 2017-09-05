%% Problem 1 script
%This script is used to obtain and display data in the form of a phase 
% portrait

close all;                  % close any open figures
figure(1);                  % open figure 1
init = [1, 10]              % Initial cruise control conditions [v, z]
%init = [-100, -100]        % Initial Conditions for instability (negative vel)
%% compute the states in time using ODE solver
% t is time elapsed for y = [v', z']
[t, y] = ode45('cruise_control', [0,100], init);
% plot velocity in blue
plot(t, y(:,1), 'b-o');
hold on;
% plot integral state in red
plot(t, y(:,2), 'r-o');
legend('v', 'z');
title('State response in time');
xlabel('time (seconds)', 'FontSize', 20);
ylabel('State change (blue: m/s, red: m)', 'FontSize', 20);
%% Plot the phase portrait
figure(2)
x = [-10, 50, 10];          % v-axis conditions (limits)
y = [-40, 40, 10];          % z-axis conditions (limits)
phaseplot('cruise_control', x, y, 1, boxgrid(x,y))
title('Phase Portrait');
xlabel('v', 'FontSize', 20);
ylabel('z', 'FontSize', 20);

figure(3)
x = [-30, 90, 10];
y = [-100, 100, 10];
phaseplot('cruise_control', x, y, 1, boxgrid(x,y))
title('Phase Portrait');
xlabel('v', 'FontSize', 20);
ylabel('z', 'FontSize', 20);

figure(4)
x = [-600, 600, 10];
y = [-600, 600, 10];
phaseplot('cruise_control', x, y, 1, boxgrid(x,y))
title('Phase Portrait');
xlabel('v', 'FontSize', 20);
ylabel('z', 'FontSize', 20);

%% generate an interactive phase-portrait
% figure(5);
% interactivePhasePortrait('cruise_control', [-1000,1000;-1000,1000], 0, 1, 30, 'cruise_control');
% grid on;
close all;
figure(1);
init = [1, 10]
%init = [-100, -100]
[t, y] = ode45('cruise_control', [0,100], init);
plot(t, y(:,1), 'b-o');
hold on;
plot(t, y(:,2), 'r-o');
legend('v', 'z');

figure(2)
x = [-10, 50, 10];
y = [-40, 40, 10];
phaseplot('cruise_control', x, y, 1, boxgrid(x,y))
xlabel('v', 'FontSize', 20);
ylabel('z', 'FontSize', 20);

figure(3)
x = [-30, 90, 10];
y = [-100, 100, 10];
phaseplot('cruise_control', x, y, 1, boxgrid(x,y))
xlabel('v', 'FontSize', 20);
ylabel('z', 'FontSize', 20);

figure(4)
x = [-600, 600, 10];
y = [-600, 600, 10];
phaseplot('cruise_control', x, y, 1, boxgrid(x,y))
xlabel('v', 'FontSize', 20);
ylabel('z', 'FontSize', 20);

% figure(5)
% figure(3);
% interactivePhasePortrait('cruise_control', [-1000,1000;-1000,1000], 0, 1, 30, 'cruise_control');
% grid on;
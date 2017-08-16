close all;
figure(1);
[t, y] = ode45('predprey', [0,100], [10,10]);
plot(t, y(:,1), 'b-o');
hold on;
plot(t, y(:,2), 'r-o');
legend('H', 'L');

figure(2)
x = [0, 120, 10];
y = [0, 120, 3];
phaseplot('predprey', x, y, 0.2, boxgrid(x,y))
xlabel('H', 'FontSize', 20);
ylabel('L', 'FontSize', 20);

figure(3);
interactivePhasePortrait('predprey', [0,120;0,120], 0, 1, 30, 'PredPrey');
grid on;

H = 0; L = 0; 
a = 3.2; b = 0.6; C = 50; d = 0.56; k = 125; r = 1.6;

J = [(r-2*r*H/k -a*L/(C+H)+a+H+L/(C+H)^2), -a*H/(C+H);
        b*a*L/(C+H)-a*b*H*L/(C+H)^2, a*b*H/(C+H)^2-d];
%% Plot outputs from simulink model

close all;

figure(1);
hold on;
plot(angle.Time, angle.Data, 'r');
plot(pos.Time, pos.Data, 'b');
legend('theta', 'position');
title('Output of simulink model; 70kg force for 1 second, m=15kg and l=0.4m');
xlabel('time (seconds)', 'FontSize', 12);
ylabel('Position (rads and meters)', 'FontSize', 12);
hold off;
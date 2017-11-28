% %% Motor Voltages
% 
% figure(1)
% plot(Motor_Voltage(:,1), Motor_Voltage(:,2))
% title('Front Motor Voltage')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(2)
% plot(Motor_Voltage(:,1), Motor_Voltage(:,3))
% title('Back Motor Voltage')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(3)
% plot(Motor_Voltage(:,1), Motor_Voltage(:,2), '-r', Motor_Voltage(:,1), Motor_Voltage(:,3), '-b')
% title('Motor Voltages')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% legend('Front Motor', 'Back Motor', 'Location', 'Best')
% 
% %% Plant Input
% 
% figure(4)
% plot(plnt_input(:,1), plnt_input(:,2))
% title('Plant Input - Front Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(5)
% plot(plnt_input(:,1), plnt_input(:,3))
% title('Plant Input - Back Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(6)
% plot(plnt_input(:,1), plnt_input(:,2), '-r', plnt_input(:,1), plnt_input(:,3), '-b')
% title('Plant Input')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% legend('Front Motor', 'Back Motor', 'Location', 'Best')
% 
% 
%% Plant Output - Position
% 
% figure(7)
% plot(y_plant_pos(:,1), y_plant_pos(:,2))
% title('Plant Output - Elevation')
% xlabel('Time (s)')
% ylabel('Position (rad)')
% 
% figure(8)
% plot(y_plant_pos(:,1), y_plant_pos(:,3))
% title('Plant Output - Pitch')
% xlabel('Time (s)')
% ylabel('Position (rad)')
% 
% figure(9)
% plot(y_plant_pos(:,1), y_plant_pos(:,4))
% title('Plant Output - Travel')
% xlabel('Time (s)')
% ylabel('Position (rad)')
%
% figure(10)
% plot(y_plant_pos(:,1), y_plant_pos(:,2), '-r', y_plant_pos(:,1), y_plant_pos(:,3), '-m', y_plant_pos(:,1), y_plant_pos(:,4), '-c')
% title('Plant Output - Position')
% xlabel('Time (s)')
% ylabel('Position (rad)')
% legend('Elevation', 'Pitch', 'Travel', 'Best')
% 
% 
% %% Plant Output - Velocity
% 
% figure(11)
% plot(y_plant_vel(:,1), y_plant_vel(:,2))
% title('Plant Output - Elevation Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(12)
% plot(y_plant_vel(:,1), y_plant_vel(:,3))
% title('Plant Output - Pitch Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(13)
% plot(y_plant_vel(:,1), y_plant_vel(:,4))
% title('Plant Output - Travel Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(14)
% plot(y_plant_vel(:,1), y_plant_vel(:,2), '-y', y_plant_vel(:,1), y_plant_vel(:,3), '-m', y_plant_vel(:,1), y_plant_vel(:,4), '-c')
% title('Plant Output - Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% legend('Elevation Velocity', 'Pitch Velocity', 'Travel Velocity', 'Best')
% 
% %% Plant Output - Velocity - Filtered
% 
% figure(15)
% plot(y_plant_vel_filt(:,1), y_plant_vel_filt(:,2))
% title('Plant Output - Elevation Velocity - Filtered')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(16)
% plot(y_plant_vel_filt(:,1), y_plant_vel_filt(:,3))
% title('Plant Output - Pitch Velocity - Filtered')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(17)
% plot(y_plant_vel_filt(:,1), y_plant_vel_filt(:,4))
% title('Plant Output - Travel Velocity - Filtered')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(18)
% plot(y_plant_vel_filt(:,1), y_plant_vel_filt(:,2), '-y', y_plant_vel_filt(:,1), y_plant_vel_filt(:,3), '-m', y_plant_vel_filt(:,1), y_plant_vel_filt(:,4), '-c')
% title('Plant Output - Velocity - Filtered')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% legend('Elevation Velocity - Filtered', 'Pitch Velocity - Filtered', 'Travel Velocity - Filtered', 'Location', 'Best')
% 
% %% Model Input
% 
% figure(19)
% plot(mdl_input(:,1), mdl_input(:,2))
% title('Model Input - Front Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(20)
% plot(mdl_input(:,1), mdl_input(:,3))
% title('Model Input - Back Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(21)
% plot(mdl_input(:,1), mdl_input(:,2), '-r', mdl_input(:,1), mdl_input(:,3), '-b')
% title('Model Input')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% legend('Front Motor', 'Back Motor', 'Best')
% 
% % Reference Input
% 
% figure(22)
% plot(ref_input(:,1), ref_input(:,2))
% title('Reference Input - Front Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(23)
% plot(ref_input(:,1), ref_input(:,3))
% title('Reference Input - Back Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(24)
% plot(ref_input(:,1), ref_input(:,2), '-r', ref_input(:,1), ref_input(:,3), '-b')
% title('Reference Input')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% legend('Front Motor', 'Back Motor', 'Best')
% 
% %% State Feedback Input
% 
% figure(25)
% plot(sf_input(:,1), sf_input(:,2))
% title('State Feedback Input - Front Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(26)
% plot(sf_input(:,1), sf_input(:,3))
% title('State Feedback Input - Back Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(27)
% plot(sf_input(:,1), sf_input(:,2), '-r', sf_input(:,1), sf_input(:,3), '-b')
% title('State Feedback Input')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% legend('Front Motor', 'Back Motor', 'Best')
% 
%% Model Estimate - Position
% 
% figure(28)
% plot(y_est(:,1), y_est(:,2),ref_info(:,1), ref_info(:,2))
% title('Model Output - Elevation')
% xlabel('Time (s)')
% ylabel('Position (rad)')
% legend('System pitch', 'Reference pitch', 'location','southeast')

% figure(29)
% plot(y_est(:,1), y_est(:,3),ref_info(:,1), ref_info(:,2))
% title('Model Output - Pitch')
% xlabel('Time (s)')
% ylabel('Position (rad)')
% legend('System pitch', 'Reference pitch', 'Best')
% 
% figure(30)
% plot(y_est(:,1), y_est(:,4),ref_info(:,1), ref_info(:,3))
% title('Model Output - Travel')
% xlabel('Time (s)')
% ylabel('Position (rad)')
% legend('System travel', 'Reference travel', 'location','southeast')
%
% figure(31)
% plot(y_est(:,1), y_est(:,2), '-r', y_est(:,1), y_est(:,3), '-m', y_est(:,1), y_est(:,4), '-c')
% title('Model Output')
% xlabel('Time (s)')
% ylabel('Position (rad)')
% legend('Elevation Estimate', 'Pitch Estimate', 'Travel Estimate', 'Location', 'Best')
%
figure(32)
plot(y_plant_pos(:,1), y_plant_pos(:,2), '-r', y_plant_pos(:,1), y_plant_pos(:,3), '-m', y_plant_pos(:,1), y_plant_pos(:,4), '-c', y_est(:,1), y_est(:,2), '--r', y_est(:,1), y_est(:,3), '--m', y_est(:,1), y_est(:,4), '--c')
title('Influence of Observer pole location - Plant vs Model Output')
xlabel('Time (s)')
ylabel('Position (rad)')
legend('Elevation', 'Pitch', 'Travel', 'Elevation Estimate', 'Pitch Estimate', 'Travel Estimate', 'Location', 'Best')
%
%
% %% State Estimate - Velocity
% 
% figure(32)
% plot(x_hat_vel(:,1), x_hat_vel(:,2))
% title('Model Output - Elevation Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(33)
% plot(x_hat_vel(:,1), x_hat_vel(:,3))
% title('Model Output - Pitch Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(34)
% plot(x_hat_vel(:,1), x_hat_vel(:,4))
% title('Model Output - Travel Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% 
% figure(35)
% plot(x_hat_vel(:,1), x_hat_vel(:,2), '-r', x_hat_vel(:,1), x_hat_vel(:,3), '-m', x_hat_vel(:,1), x_hat_vel(:,4), '-c')
% title('Model Output - Velocity')
% xlabel('Time (s)')
% ylabel('Velocity (rad/s)')
% legend('Elevation Velocity Estimate', 'Pitch Velocity Estimate', 'Travel Velocity Estimate', 'Location', 'Best')
%
% %% Integral Input
% 
% figure(36)
% plot(int_input(:,1), int_input(:,2))
% title('Integral Input - Front Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(37)
% plot(int_input(:,1), int_input(:,3))
% title('Integral Input - Back Motor')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% 
% figure(38)
% plot(int_input(:,1), int_input(:,2), '-r', int_input(:,1), int_input(:,3), '-b')
% title('Integral Input')
% xlabel('Time (s)')
% ylabel('Voltage (V)')
% legend('Front Motor', 'Back Motor', 'Best')
% 
% %% Integral Error
% 
% figure(39)
% plot(int_error(:,1), int_error(:,2))
% title('Integral Error - Elevation Position')
% xlabel('Time (s)')
% ylabel('Error (rad)')
% 
% figure(40)
% plot(int_error(:,1), int_error(:,3))
% title('Integral Error - Travel Position')
% xlabel('Time (s)')
% ylabel('Error (rad)')
% 
% figure(41)
% plot(int_error(:,1), int_error(:,2), '-y', int_error(:,1), int_error(:,3), '-c')
% title('Integral Error')
% xlabel('Time (s)')
% ylabel('Error (rad)')
% legend('Elevation Position Error', 'Travel Position Error', 'Best')
% 
% %% Reference Information
% 
% % figure(39)
% % plot(ref_info(:,1), ref_info(:,2))
% % title('Reference - Elevation Position')
% % xlabel('Time (s)')
% % ylabel('Position (rad)')
% % 
% % figure(40)
% % plot(ref_info(:,1), ref_info(:,3))
% % title('Reference - Travel Position')
% % xlabel('Time (s)')
% % ylabel('Position (rad)')
% 
% figure(41)
% plot(ref_info(:,1), ref_info(:,2), '-r', ref_info(:,1), ref_info(:,3), '-c')
% title('Reference')
% xlabel('Time (s)')
% ylabel('Position(rad)')
% legend('Elevation Position', 'Travel Position', 'Best')
%
%% Steady State Error

figure(42)
plot(steady_state_error(:,1), steady_state_error(:,2), '-r', steady_state_error(:,1), steady_state_error(:,3), '-b', steady_state_error(:,1), steady_state_error(:,4), '-g', steady_state_error(:,1), steady_state_error(:,6), '-m')
title('Steady State Error')
xlabel('Time (s)')
ylabel('Error (rad)')
legend('Elevation Reference', 'Travel Reference', 'Elevation Position', 'Travel Position', 'Location', 'Best')
%%% EKF example
%%%%%STATE
% [x xdot y ydot theta thetadot]
%%%% MODEL
% f = [ xdot; u*cos(theta); ydot; u*sin(theta); thetadot; alpha];
% h = [x; y ; theta];
%%%%%% LINEARIZATIONS
%
% dF =
% [ 0, 1, 0, 0,             0, 0]
% [ 0, 0, 0, 0, -u*sin(theta), 0]
% [ 0, 0, 0, 1,             0, 0]
% [ 0, 0, 0, 0,  u*cos(theta), 0]
% [ 0, 0, 0, 0,             0, 1]
% [ 0, 0, 0, 0,             0, 0]
% dH =
% [1 0 0 0 0 0; 0 0 1 0 0 0; 0 0 0 0 1 0];
%
% Set up covariances
clear;
close all;
Q = 0.1*eye(6);  % model uncertainty covariance (process noise)
R = 0.5*eye(3); % measurement covariance
Phat(:,:,1) = .1*eye(6); % error covariance of the initial state estimate
% initialize plant model
x_0 = [1 0 1 0 pi/4 0]';
x_plant = x_0;
y_plant = [x_plant(1,1); x_plant(3,1); x_plant(5,1)];
%y_plant = [x_plant(1,1)^2+x_plant(3,1)^2; tan(x_plant(3,1)/x_plant(1,1)); x_plant(5,1)];
y_meas = y_plant;
% initialize EKF
x_hat = x_0;
ypred = y_plant;
u = [1 0];
Ts = 0.1;
for k = 1:100
    u(2) = sin(pi*k/10);
    % simulate model - use Forward Euler
    x_plant(:,k+1) = x_plant(:,k) + Ts*[x_plant(2,k); u(1)*cos(x_plant(5,k)); x_plant(4,k); u(1)*sin(x_plant(5,k));...
        x_plant(6,k); u(2)];% + transpose(mvnrnd(zeros(1, 6) , Q)) * sqrt(Ts);
    % take measurement
    y_plant(:,k+1) = [x_plant(1,k+1); x_plant(3,k+1); x_plant(5,k+1)] ;%+ transpose(mvnrnd(zeros(3, 1), R)) * sqrt(Ts);
    y_meas(:,k+1) = y_plant(:,k+1)+ transpose(mvnrnd(zeros(3, 1), R));
   
    % predict states and covariances and linearise model
    xpred(:,k+1) = x_hat(:,k) + Ts*[x_hat(2,k); u(1)*cos(x_hat(5,k)); x_hat(4,k); u(1)*sin(x_hat(5,k));...
        x_hat(6,k); u(2)];
    ypred(:,k+1) =[xpred(1,k+1);xpred(3,k+1); xpred(5,k+1)];
    dF = [[ 0, 1, 0, 0,             0, 0];
        [ 0, 0, 0, 0, -u(1)*sin(xpred(5,k+1)), 0];
        [ 0, 0, 0, 1,             0, 0];
        [ 0, 0, 0, 0,  u(1)*cos(xpred(5,k+1)), 0];
        [ 0, 0, 0, 0,             0, 1];
        [ 0, 0, 0, 0,             0, 0]];
    dH =  [1 0 0 0 0 0; 0 0 1 0 0 0; 0 0 0 0 1 0];
   
    Ppred(:,:,k+1) = dF*Phat(:,:,k)*dF' + Q;
    %kalman gain
    K = Ppred(:,:,k+1) * dH'/(R - dH*Ppred(:,:,k+1)*dH');
    % update estimates with measurement
    x_hat(:,k+1) = xpred(:,k+1) + K*(y_meas(:,k+1)- ypred(:,k+1));
    Phat(:,:,k+1) =  Ppred(:,:,k+1) - K*(R + dH*Ppred(:,:,k+1)*dH')*K';
    %(eye(size(K,1)) - K*dH)*Ppred(:,:,k+1)*(eye(size(K,1)) - K*dH)'...
     %   + K*R*K';
end
figure(21)
clf
plot(x_plant(1,:), x_plant(3,:), 'LineWidth', 2);
hold on
plot(x_hat(1,:), x_hat(3,:), ':r', 'LineWidth', 2);
title('x-y')
xlabel('x (m)')
ylabel('y (m)')
figure(22)
clf
vars = {'x', 'xdot', 'y', 'ydot', 'theta', 'thetadot'};
for k =1:6
    subplot(6,1,k)
    plot(x_plant(k,:), 'LineWidth', 2);
    title(vars{k})
    hold on
    plot(x_hat(k,:), 'r:', 'LineWidth', 2);
end
 
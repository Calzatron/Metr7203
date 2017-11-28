
N_1 = y_plant.signals.values(:,1) - mean(y_plant.signals.values(:,1))
N_2 = y_plant.signals.values(:,2) - mean(y_plant.signals.values(:,2))
N_3 = y_plant.signals.values(:,3) - mean(y_plant.signals.values(:,3))


var1 = std(N_1)^2
var2 = std(N_2)^2
var3 = std(N_3)^2

N_4 = y_plant1.signals.values(:,1) - mean(y_plant1.signals.values(:,1))
N_5 = y_plant1.signals.values(:,2) - mean(y_plant1.signals.values(:,2))
N_6 = y_plant1.signals.values(:,3) - mean(y_plant1.signals.values(:,3))


var4 = std(N_4)^2
var5 = std(N_5)^2
var6 = std(N_6)^2

R = diag([var1, var2, var3, var4, var5, var6]);

% 
% Q_1 = y_plant2.signals.values(:,1) - mean(y_plant2.signals.values(:,1))
% Q_2 = y_plant2.signals.values(:,2) - mean(y_plant2.signals.values(:,2))
% Q_3 = y_plant2.signals.values(:,3) - mean(y_plant2.signals.values(:,3))
% 
% 
% Qvar1 = std(N_1 - Q_1)^2;
% Qvar2 = std(N_2 - Q_2)^2;
% Qvar3 = std(N_3 - Q_3)^2;
% 
% Q_4 = y_plant3.signals.values(:,1) - mean(y_plant3.signals.values(:,1))
% Q_5 = y_plant3.signals.values(:,2) - mean(y_plant3.signals.values(:,2))
% Q_6 = y_plant3.signals.values(:,3) - mean(y_plant3.signals.values(:,3))
% 
% 
% Qvar4 = std(N_4 - Q_4)^2;
% Qvar5 = std(N_5 - Q_5)^2;
% Qvar6 = std(N_6 - Q_6)^2;
% 
% Q_k = diag([Qvar1, Qvar2, Qvar3, Qvar4, Qvar5, Qvar6]);

%%
% R =
% 
%     0.0001         0         0         0         0         0
%          0    0.0000         0         0         0         0
%          0         0    0.0003         0         0         0
%          0         0         0    0.0086         0         0
%          0         0         0         0    0.0002         0
%          0         0         0         0         0    0.0011

% R =
% 
%     7.5783e-06         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0    0.0024         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0

% R =
% 
%     4.1876e-05         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0    0.0061         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0

% R =
% 
%     8.1846e-06         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0    0.0018         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0

% R =
% 
%     6.5153e-06         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0
%          0         0         0    0.0020         0         0
%          0         0         0         0         0         0
%          0         0         0         0         0         0


%% position
Y_plant = y_plant;
Y_plant.signals.values(:,1) = y_plant.signals.values(:,1) - y_plant.signals.values(1,1);
Y_plant.signals.values(:,1) = y_plant.signals.values(:,2) - y_plant.signals.values(1,2);
Y_plant.signals.values(:,1) = y_plant.signals.values(:,3) - y_plant.signals.values(1,3);


Y_model = y_plant2;


off1 = Y_plant.signals.values(1:502,1) - Y_model.signals.values(1:502,1);
off2 = Y_plant.signals.values(1:502,2) - Y_model.signals.values(1:502,2);
off3 = Y_plant.signals.values(1:502,3) - Y_model.signals.values(1:502,3);
time = Y_plant.time(1:502, 1);


var1 = var(off1);
var2 = var(off2);
var3 = var(off3);

%% velocity
Y_plant1 = y_plant1;
Y_plant1.signals.values(:,1) = y_plant1.signals.values(:,1) - y_plant1.signals.values(1,1);
Y_plant1.signals.values(:,2) = y_plant1.signals.values(:,2) - y_plant1.signals.values(1,2);
Y_plant1.signals.values(:,3) = y_plant1.signals.values(:,3) - y_plant1.signals.values(1,3);


Y_model1 = y_plant3;


off4 = Y_plant1.signals.values(1:502,1) - Y_model1.signals.values(1:502,4);
off5 = Y_plant1.signals.values(1:502,2) - Y_model1.signals.values(1:502,5);
off6 = Y_plant1.signals.values(1:502,3) - Y_model1.signals.values(1:502,6);
time = Y_plant1.time(1:502,1);


var4 = var(off4);
var5 = var(off5);
var6 = var(off6);

%% Q
Q = diag([var1, var2, var3, var4, var5, var6])
%var1 = 0.0015
%var2 = 5.4207e-31
%var3 = 3.0264e-07

%var1 = 0.0014
%var2 = 1.6229e-31
%var3 = 3.7599e-07
%var4 = 0.0530
%var5 = 0
%var6 = 0.0047




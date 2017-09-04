% Define parameters
M = 10;
m = 80;
c = 0.1;
l = 1;
rho = 0.01;
g = 9.81;

sys = linmod('PBA3_2_2', [0, 0, 0, 0], 0)

EIG_sim = eig(sys.a)

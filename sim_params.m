% plant and noise parameters
A = [0 1; 0 0];
B = [0; 1]
C = [1 0]
Q = diag([.2 .3])
R = 0.1

% model parameters
A_m = A
B_m = B
C_m = C
close all;
syms s
v1 = (s+18.0000 + 4.5000i)*(s+18.0000 - 4.5000i)*(s+32.0000 + 8.0000i)*(s+32.0000 - 8.0000i)*(s+28.0000 + 7.0000i)*(s+28.0000 - 7.0000i);

[T, Co] = coeffs(vpa(eval(expand(v1))));
T = double(T);
sys = tf([1], [T(1,1) T(1,2) T(1,3) T(1,4) T(1,5) T(1,6)]);

v2 = (s+18.0000 + 8.7120i)*(s+18.0000 K_r- 8.7120i)*(s+32.0000 + 15.4880i)*(s+32.0000 - 15.4880i)*(s+28.0000 + 13.5520i)*(s+28.0000 - 13.5520i);

[T, Co] = coeffs(vpa(eval(expand(v2))));
T = double(T);
sys1 = tf([1], [T(1,1) T(1,2) T(1,3) T(1,4) T(1,5) T(1,6)]);


% v3 = (s+12.0000 + 3.000i)*(s+12.0000 - 3.00i)*(s+36.0000 + 9.0000i)*(s+36.0000 - 9.0000i)*(s+42.0000 + 10.50000i)*(s+42.0000 - 10.50000i);
% 
% [T, Co] = coeffs(vpa(eval(expand(v3))));
% T = double(T);
% sys2 = tf([1], [T(1,1) T(1,2) T(1,3) T(1,4) T(1,5) T(1,6)]);
% 
% v3 = (s+12.0000 + 3.000i)*(s+12.0000 - 3.000i)*(s+50.0000 + 12.50000i)*(s+50.0000 - 12.50000i)*(s+36.0000 + 9.0000i)*(s+36.0000 - 9.0000i);
% 
% [T, Co] = coeffs(vpa(eval(expand(v3))));
% T = double(T);
% sys3 = tf([1], [T(1,1) T(1,2) T(1,3) T(1,4) T(1,5) T(1,6)]);


figure(1); hold on;
step(sys);
step(sys1);
% step(sys2);
% step(sys3);
hold off;
figure(2); hold on;
impulse(sys);
impulse(sys1);
% impulse(sys2);
% impulse(sys3);
hold off;
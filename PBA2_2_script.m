syms p Cd A Vr m g Cr Ki alpha Tm beta wm Kp v z

F = [(1/m)*(alpha*Tm*(1-beta*(alpha*v*(1/wm) - 1)^2)*((Vr - v)*Kp+Ki*z)-0.5*p*Cd*A*v^2-m*g*Cr*v);
        Vr - v];
% J = jacobian(F, [v, z]);
% 
% %set the equilibrium point
% v= Vr;
% z = (0.5*p*Cd*A*v^2+m*g*Cr*v)/(Ki*alpha*Tm*(1-beta*(alpha*v*(1/wm) - 1)^2));
% solve(J(1));

taylor(F, [v;z], [Vr; (0.5*p*Cd*A*Vr^2+m*g*Cr*Vr)/(Ki*alpha*Tm*(1-beta*(alpha*Vr*(1/wm) - 1)^2))], 'Order', 2)
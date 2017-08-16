function dy = predprey(t, y)

a = 3.2; b = 0.6; C = 50; d = 0.56; k = 125; r = 1.6;

dy = zeros(2,1);    %a column vector containing H' and L'

dy(1) = r*y(1)*(1-y(1)/k) - a*y(1)*y(2)/(C+y(1));
dy(2) = b*a*y(1)*y(2)/(C+y(1)) - d*y(2);


end
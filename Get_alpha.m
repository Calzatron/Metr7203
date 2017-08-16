function Alpha_ = Get_alpha( Vel )
% Selects the highest gear for the speed of the car, Vel,
% returning the effective wheel radius Alpha
%   
    global alpha
    global wm
    %check if velocity is above maximum -> gear change
    s = size(alpha);
    w = 0;
    wn = wm(1);
    
    for n = 1:s(2)
        w = Vel*alpha{n};
        if w < wn
            Alpha_ = alpha{n};
            %velocity suitable for current gear, n
            return
        end
    end
    % over speed of final gear, use final gear
    if w > wn
        Alpha_ = alpha{s(2)};
    end
    
end


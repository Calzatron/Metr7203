function [ Lambda ] = Actuator( Vel, Vel_r )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    Vel_diff = Vel_r - Vel;
    Vel_error = Vel_diff / Vel_r;
    
    if Vel_diff == 0
        Lambda = 0;         %at correct speed
        return;
    end
    
    ratio = Vel_diff / abs(Vel_diff)
    
    if ratio < 0
        Lambda = 0         %no throttle required
        
    elseif ratio > 0
        Lambda = Vel_error  %Proportional gain on error 
    end  

end


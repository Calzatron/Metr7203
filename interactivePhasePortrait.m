%%%%   phasePortrait.m%%%%   Inputs:%%             systemFile,            name of file with macro that simulates system%%             ICrange,               matrix for initial conditions range [xMin,xMax;yMin,yMax]%%             startTime,             starting time for simulation%%             endTime                ending time for simulation%%             spacing                how many grid divisions for initialConditions%%%%function interactivePhasePortrait(systemFile,ICrange,startTime,endTime,spacing, theTitle)colour = hsv(10);hold on%% Set the initialConditions vector%xMin=ICrange(1,1);xMax=ICrange(1,2);yMin=ICrange(2,1);yMax=ICrange(2,2);dx = (xMax-xMin)/(spacing);dy = (yMax-yMin)/(spacing);for i=0:spacing,	for j=0:spacing,		IC=[xMin+dx*i,yMin+dy*j];		[t,y] = ode23(systemFile,[startTime,endTime],IC);%         [t,y] = ode45(systemFile,[startTime,endTime],IC);		plot(y(:,1),y(:,2),'color',colour(rem(i+j+1,10)+1,:));        title(theTitle)	endendejes=[xMin-0.25*dx xMax+0.25*dx yMin-0.25*dy yMax+0.25*dy];axis(ejes);grid on;xlabel('X1');ylabel('X2');% waitforbuttonpresswhile(1)    [y1_in ,y2_in,button] = ginput(1);    if (button == 1 )         [t,y] = ode23(systemFile,[0,20],[y1_in;y2_in]);        hold on;        plot(y(:,1),y(:,2),'linewidth',5);        ejes=[xMin-0.25*dx xMax+0.25*dx yMin-0.25*dy yMax+0.25*dy];        title(theTitle);        axis(ejes);        grid on;        hold off    elseif (button == 3)        current_IC_range_x = xMax - yMin;        current_IC_range_y = yMax - yMin;        new_IC_range = [ y1_in - current_IC_range_x/4 y1_in + current_IC_range_x/4;y2_in - current_IC_range_y/4 y2_in + current_IC_range_y/4];        clf;        interactivePhasePortrait(systemFile,new_IC_range,startTime,endTime,spacing,theTitle)    else        return    endendend
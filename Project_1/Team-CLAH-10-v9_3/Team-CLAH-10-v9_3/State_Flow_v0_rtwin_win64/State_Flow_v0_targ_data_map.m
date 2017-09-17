  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (State_Flow_v0_P)
    ;%
      section.nData     = 52;
      section.data(52)  = dumData; %prealloc
      
	  ;% State_Flow_v0_P.SFunction_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% State_Flow_v0_P.SFunction_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% State_Flow_v0_P.SFunction_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% State_Flow_v0_P.SFunction_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 10;
	
	  ;% State_Flow_v0_P.SFunction_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 11;
	
	  ;% State_Flow_v0_P.SFunction_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% State_Flow_v0_P.SFunction_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 14;
	
	  ;% State_Flow_v0_P.SFunction_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 16;
	
	  ;% State_Flow_v0_P.Gain1_Gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 17;
	
	  ;% State_Flow_v0_P.Constant4_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 18;
	
	  ;% State_Flow_v0_P.Gain2_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 19;
	
	  ;% State_Flow_v0_P.Gain3_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 20;
	
	  ;% State_Flow_v0_P.Gain3_Gain_o
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 21;
	
	  ;% State_Flow_v0_P.Gain_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 22;
	
	  ;% State_Flow_v0_P.Gain1_Gain_j
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 23;
	
	  ;% State_Flow_v0_P.Gain4_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 24;
	
	  ;% State_Flow_v0_P.Gain5_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 25;
	
	  ;% State_Flow_v0_P.TransferFcn1_A
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 26;
	
	  ;% State_Flow_v0_P.TransferFcn1_C
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 27;
	
	  ;% State_Flow_v0_P.Gain4_Gain_k
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 28;
	
	  ;% State_Flow_v0_P.Gain_Gain_o
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 29;
	
	  ;% State_Flow_v0_P.Constant1_Value
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 30;
	
	  ;% State_Flow_v0_P.ProportionalGain_Gain
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 31;
	
	  ;% State_Flow_v0_P.Integrator_IC
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 32;
	
	  ;% State_Flow_v0_P.DerivativeGain_Gain
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 33;
	
	  ;% State_Flow_v0_P.Filter_IC
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 34;
	
	  ;% State_Flow_v0_P.FilterCoefficient_Gain
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 35;
	
	  ;% State_Flow_v0_P.Saturation_UpperSat
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 36;
	
	  ;% State_Flow_v0_P.Saturation_LowerSat
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 37;
	
	  ;% State_Flow_v0_P.InitialCondition_Value
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 38;
	
	  ;% State_Flow_v0_P.Constant2_Value
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 39;
	
	  ;% State_Flow_v0_P.FixPtUnitDelay1_InitialCondition
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 40;
	
	  ;% State_Flow_v0_P.Gain4_Gain_j
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 41;
	
	  ;% State_Flow_v0_P.Constant1_Value_g
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 42;
	
	  ;% State_Flow_v0_P.Saturation_UpperSat_h
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 43;
	
	  ;% State_Flow_v0_P.Saturation_LowerSat_j
	  section.data(36).logicalSrcIdx = 37;
	  section.data(36).dtTransOffset = 44;
	
	  ;% State_Flow_v0_P.Gain5_Gain_o
	  section.data(37).logicalSrcIdx = 38;
	  section.data(37).dtTransOffset = 45;
	
	  ;% State_Flow_v0_P.Gain_Gain_i
	  section.data(38).logicalSrcIdx = 39;
	  section.data(38).dtTransOffset = 46;
	
	  ;% State_Flow_v0_P.Constant_Value
	  section.data(39).logicalSrcIdx = 40;
	  section.data(39).dtTransOffset = 47;
	
	  ;% State_Flow_v0_P.Gain2_Gain_b
	  section.data(40).logicalSrcIdx = 41;
	  section.data(40).dtTransOffset = 48;
	
	  ;% State_Flow_v0_P.Gain3_Gain_h
	  section.data(41).logicalSrcIdx = 42;
	  section.data(41).dtTransOffset = 49;
	
	  ;% State_Flow_v0_P.Gain1_Gain_a
	  section.data(42).logicalSrcIdx = 43;
	  section.data(42).dtTransOffset = 50;
	
	  ;% State_Flow_v0_P.Stepon_Time
	  section.data(43).logicalSrcIdx = 44;
	  section.data(43).dtTransOffset = 51;
	
	  ;% State_Flow_v0_P.Stepon_Y0
	  section.data(44).logicalSrcIdx = 45;
	  section.data(44).dtTransOffset = 52;
	
	  ;% State_Flow_v0_P.Stepon_YFinal
	  section.data(45).logicalSrcIdx = 46;
	  section.data(45).dtTransOffset = 53;
	
	  ;% State_Flow_v0_P.Stepoff_Time
	  section.data(46).logicalSrcIdx = 47;
	  section.data(46).dtTransOffset = 54;
	
	  ;% State_Flow_v0_P.Stepoff_Y0
	  section.data(47).logicalSrcIdx = 48;
	  section.data(47).dtTransOffset = 55;
	
	  ;% State_Flow_v0_P.Stepoff_YFinal
	  section.data(48).logicalSrcIdx = 49;
	  section.data(48).dtTransOffset = 56;
	
	  ;% State_Flow_v0_P.Gain5_Gain_b
	  section.data(49).logicalSrcIdx = 50;
	  section.data(49).dtTransOffset = 57;
	
	  ;% State_Flow_v0_P.IntegralGain_Gain
	  section.data(50).logicalSrcIdx = 51;
	  section.data(50).dtTransOffset = 58;
	
	  ;% State_Flow_v0_P.Saturation1_UpperSat
	  section.data(51).logicalSrcIdx = 52;
	  section.data(51).dtTransOffset = 59;
	
	  ;% State_Flow_v0_P.Saturation1_LowerSat
	  section.data(52).logicalSrcIdx = 53;
	  section.data(52).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_P.EnabledSubsystem2.uout_Y0
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_P.EnabledSubsystem.uout_Y0
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (State_Flow_v0_B)
    ;%
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% State_Flow_v0_B.SFunction
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% State_Flow_v0_B.theta
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% State_Flow_v0_B.thetacorrection1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% State_Flow_v0_B.theta_dot
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% State_Flow_v0_B.Gain2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% State_Flow_v0_B.theta4
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% State_Flow_v0_B.Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% State_Flow_v0_B.Gain5
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% State_Flow_v0_B.TransferFcn1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% State_Flow_v0_B.Gain4
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% State_Flow_v0_B.Derivative
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% State_Flow_v0_B.Gain_c
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% State_Flow_v0_B.FilterCoefficient
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% State_Flow_v0_B.Saturation
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% State_Flow_v0_B.FixPtUnitDelay1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% State_Flow_v0_B.Reset
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% State_Flow_v0_B.Gain5_n
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% State_Flow_v0_B.Gain3
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% State_Flow_v0_B.E
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% State_Flow_v0_B.TrigonometricFunction1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% State_Flow_v0_B.Gain1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% State_Flow_v0_B.Gain5_e
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% State_Flow_v0_B.IntegralGain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% State_Flow_v0_B.Saturation1
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% State_Flow_v0_B.x
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% State_Flow_v0_B.y
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% State_Flow_v0_B.z
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_B.EnabledSubsystem2.uin
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_B.EnabledSubsystem.uin
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (State_Flow_v0_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% State_Flow_v0_DW.Derivative1_RWORK.TimeStampA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% State_Flow_v0_DW.Derivative2_RWORK.TimeStampA
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% State_Flow_v0_DW.Derivative_RWORK.TimeStampA
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.CatchEnable_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% State_Flow_v0_DW.CatchEnableuin_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% State_Flow_v0_DW.CatchEnableuout_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% State_Flow_v0_DW.Encoder1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% State_Flow_v0_DW.FlywheelRotSpeedrads_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% State_Flow_v0_DW.FlywheelRotSpeedrads1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% State_Flow_v0_DW.FlywheelRotSpeedrads2_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% State_Flow_v0_DW.GimbalEncoder1_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% State_Flow_v0_DW.PIDoutputvoltage_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% State_Flow_v0_DW.PendulumEncoder_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% State_Flow_v0_DW.RPM_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
	  ;% State_Flow_v0_DW.Restx_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 11;
	
	  ;% State_Flow_v0_DW.SwingEnable_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 12;
	
	  ;% State_Flow_v0_DW.SwingEnableuin_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 13;
	
	  ;% State_Flow_v0_DW.SwingEnableuout_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 14;
	
	  ;% State_Flow_v0_DW.Scope_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 15;
	
	  ;% State_Flow_v0_DW.Scope1_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 16;
	
	  ;% State_Flow_v0_DW.Scope2_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 17;
	
	  ;% State_Flow_v0_DW.Scope3_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.sfEvent
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.is_active_c3_State_Flow_v0
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% State_Flow_v0_DW.is_c3_State_Flow_v0
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.isStable
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.EnabledSubsystem2.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.EnabledSubsystem2.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.EnabledSubsystem.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% State_Flow_v0_DW.EnabledSubsystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2489480683;
  targMap.checksum1 = 2893304224;
  targMap.checksum2 = 1197350479;
  targMap.checksum3 = 2446042263;


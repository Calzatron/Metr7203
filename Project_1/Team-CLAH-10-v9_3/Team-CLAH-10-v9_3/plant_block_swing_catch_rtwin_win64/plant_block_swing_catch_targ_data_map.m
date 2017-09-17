  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
    ;% Auto data (plant_block_swing_catch_P)
    ;%
      section.nData     = 62;
      section.data(62)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_P.SFunction_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_P.SFunction_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% plant_block_swing_catch_P.SFunction_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% plant_block_swing_catch_P.SFunction_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 10;
	
	  ;% plant_block_swing_catch_P.SFunction_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 11;
	
	  ;% plant_block_swing_catch_P.SFunction_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% plant_block_swing_catch_P.SFunction_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 14;
	
	  ;% plant_block_swing_catch_P.SFunction_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 16;
	
	  ;% plant_block_swing_catch_P.Gain1_Gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 17;
	
	  ;% plant_block_swing_catch_P.Constant4_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 18;
	
	  ;% plant_block_swing_catch_P.TransferFcn5_A
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 19;
	
	  ;% plant_block_swing_catch_P.TransferFcn5_C
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 20;
	
	  ;% plant_block_swing_catch_P.Gain2_Gain
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 21;
	
	  ;% plant_block_swing_catch_P.TransferFcn2_A
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 22;
	
	  ;% plant_block_swing_catch_P.TransferFcn2_C
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 23;
	
	  ;% plant_block_swing_catch_P.Gain3_Gain
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 24;
	
	  ;% plant_block_swing_catch_P.TransferFcn3_A
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 25;
	
	  ;% plant_block_swing_catch_P.TransferFcn3_C
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 26;
	
	  ;% plant_block_swing_catch_P.Constant1_Value
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 27;
	
	  ;% plant_block_swing_catch_P.Constant2_Value
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 28;
	
	  ;% plant_block_swing_catch_P.Gain_Gain
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 29;
	
	  ;% plant_block_swing_catch_P.TransferFcn4_A
	  section.data(22).logicalSrcIdx = 27;
	  section.data(22).dtTransOffset = 30;
	
	  ;% plant_block_swing_catch_P.TransferFcn4_C
	  section.data(23).logicalSrcIdx = 28;
	  section.data(23).dtTransOffset = 31;
	
	  ;% plant_block_swing_catch_P.Gain1_Gain_j
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 32;
	
	  ;% plant_block_swing_catch_P.Gain4_Gain
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 33;
	
	  ;% plant_block_swing_catch_P.TransferFcn1_A
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 34;
	
	  ;% plant_block_swing_catch_P.TransferFcn1_C
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 35;
	
	  ;% plant_block_swing_catch_P.Gain4_Gain_c
	  section.data(28).logicalSrcIdx = 37;
	  section.data(28).dtTransOffset = 36;
	
	  ;% plant_block_swing_catch_P.Gain_Gain_l
	  section.data(29).logicalSrcIdx = 38;
	  section.data(29).dtTransOffset = 37;
	
	  ;% plant_block_swing_catch_P.Gain6_Gain
	  section.data(30).logicalSrcIdx = 39;
	  section.data(30).dtTransOffset = 38;
	
	  ;% plant_block_swing_catch_P.Constant_Value
	  section.data(31).logicalSrcIdx = 40;
	  section.data(31).dtTransOffset = 39;
	
	  ;% plant_block_swing_catch_P.ProportionalGain_Gain
	  section.data(32).logicalSrcIdx = 41;
	  section.data(32).dtTransOffset = 40;
	
	  ;% plant_block_swing_catch_P.Integrator_IC
	  section.data(33).logicalSrcIdx = 42;
	  section.data(33).dtTransOffset = 41;
	
	  ;% plant_block_swing_catch_P.DerivativeGain_Gain
	  section.data(34).logicalSrcIdx = 43;
	  section.data(34).dtTransOffset = 42;
	
	  ;% plant_block_swing_catch_P.Filter_IC
	  section.data(35).logicalSrcIdx = 44;
	  section.data(35).dtTransOffset = 43;
	
	  ;% plant_block_swing_catch_P.FilterCoefficient_Gain
	  section.data(36).logicalSrcIdx = 45;
	  section.data(36).dtTransOffset = 44;
	
	  ;% plant_block_swing_catch_P.Saturation_UpperSat
	  section.data(37).logicalSrcIdx = 46;
	  section.data(37).dtTransOffset = 45;
	
	  ;% plant_block_swing_catch_P.Saturation_LowerSat
	  section.data(38).logicalSrcIdx = 47;
	  section.data(38).dtTransOffset = 46;
	
	  ;% plant_block_swing_catch_P.ProportionalGain_Gain_b
	  section.data(39).logicalSrcIdx = 48;
	  section.data(39).dtTransOffset = 47;
	
	  ;% plant_block_swing_catch_P.Integrator_IC_l
	  section.data(40).logicalSrcIdx = 49;
	  section.data(40).dtTransOffset = 48;
	
	  ;% plant_block_swing_catch_P.DerivativeGain_Gain_n
	  section.data(41).logicalSrcIdx = 50;
	  section.data(41).dtTransOffset = 49;
	
	  ;% plant_block_swing_catch_P.Filter_IC_o
	  section.data(42).logicalSrcIdx = 51;
	  section.data(42).dtTransOffset = 50;
	
	  ;% plant_block_swing_catch_P.FilterCoefficient_Gain_g
	  section.data(43).logicalSrcIdx = 52;
	  section.data(43).dtTransOffset = 51;
	
	  ;% plant_block_swing_catch_P.InitialCondition_Value
	  section.data(44).logicalSrcIdx = 53;
	  section.data(44).dtTransOffset = 52;
	
	  ;% plant_block_swing_catch_P.Constant2_Value_l
	  section.data(45).logicalSrcIdx = 54;
	  section.data(45).dtTransOffset = 53;
	
	  ;% plant_block_swing_catch_P.FixPtUnitDelay1_InitialConditio
	  section.data(46).logicalSrcIdx = 55;
	  section.data(46).dtTransOffset = 54;
	
	  ;% plant_block_swing_catch_P.Gain4_Gain_f
	  section.data(47).logicalSrcIdx = 56;
	  section.data(47).dtTransOffset = 55;
	
	  ;% plant_block_swing_catch_P.Constant1_Value_a
	  section.data(48).logicalSrcIdx = 57;
	  section.data(48).dtTransOffset = 56;
	
	  ;% plant_block_swing_catch_P.Saturation_UpperSat_p
	  section.data(49).logicalSrcIdx = 58;
	  section.data(49).dtTransOffset = 57;
	
	  ;% plant_block_swing_catch_P.Saturation_LowerSat_f
	  section.data(50).logicalSrcIdx = 59;
	  section.data(50).dtTransOffset = 58;
	
	  ;% plant_block_swing_catch_P.Gain5_Gain
	  section.data(51).logicalSrcIdx = 60;
	  section.data(51).dtTransOffset = 59;
	
	  ;% plant_block_swing_catch_P.Gain_Gain_h
	  section.data(52).logicalSrcIdx = 61;
	  section.data(52).dtTransOffset = 60;
	
	  ;% plant_block_swing_catch_P.Constant_Value_g
	  section.data(53).logicalSrcIdx = 62;
	  section.data(53).dtTransOffset = 61;
	
	  ;% plant_block_swing_catch_P.Gain2_Gain_d
	  section.data(54).logicalSrcIdx = 63;
	  section.data(54).dtTransOffset = 62;
	
	  ;% plant_block_swing_catch_P.Gain3_Gain_f
	  section.data(55).logicalSrcIdx = 64;
	  section.data(55).dtTransOffset = 63;
	
	  ;% plant_block_swing_catch_P.Gain1_Gain_a
	  section.data(56).logicalSrcIdx = 65;
	  section.data(56).dtTransOffset = 64;
	
	  ;% plant_block_swing_catch_P.Saturation1_UpperSat
	  section.data(57).logicalSrcIdx = 66;
	  section.data(57).dtTransOffset = 65;
	
	  ;% plant_block_swing_catch_P.Saturation1_LowerSat
	  section.data(58).logicalSrcIdx = 67;
	  section.data(58).dtTransOffset = 66;
	
	  ;% plant_block_swing_catch_P.Gain3_Gain_b
	  section.data(59).logicalSrcIdx = 68;
	  section.data(59).dtTransOffset = 67;
	
	  ;% plant_block_swing_catch_P.Gain5_Gain_b
	  section.data(60).logicalSrcIdx = 69;
	  section.data(60).dtTransOffset = 68;
	
	  ;% plant_block_swing_catch_P.IntegralGain_Gain
	  section.data(61).logicalSrcIdx = 70;
	  section.data(61).dtTransOffset = 69;
	
	  ;% plant_block_swing_catch_P.IntegralGain_Gain_o
	  section.data(62).logicalSrcIdx = 71;
	  section.data(62).dtTransOffset = 70;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (plant_block_swing_catch_B)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_B.SFunction
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_B.theta
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% plant_block_swing_catch_B.thetacorrection1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% plant_block_swing_catch_B.theta_dot
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% plant_block_swing_catch_B.Abs1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% plant_block_swing_catch_B.Add2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% plant_block_swing_catch_B.Gain4
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% plant_block_swing_catch_B.Product1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% plant_block_swing_catch_B.TransferFcn1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% plant_block_swing_catch_B.Gain4_e
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% plant_block_swing_catch_B.Derivative
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% plant_block_swing_catch_B.Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% plant_block_swing_catch_B.Product3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% plant_block_swing_catch_B.FilterCoefficient
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% plant_block_swing_catch_B.Saturation
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% plant_block_swing_catch_B.Add1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% plant_block_swing_catch_B.FilterCoefficient_k
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% plant_block_swing_catch_B.Sum
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% plant_block_swing_catch_B.FixPtUnitDelay1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% plant_block_swing_catch_B.Reset
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% plant_block_swing_catch_B.Gain5
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% plant_block_swing_catch_B.Gain3
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% plant_block_swing_catch_B.E
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% plant_block_swing_catch_B.TrigonometricFunction1
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% plant_block_swing_catch_B.Gain1
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% plant_block_swing_catch_B.Product2
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% plant_block_swing_catch_B.Saturation1
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% plant_block_swing_catch_B.theta4
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% plant_block_swing_catch_B.Derivative2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% plant_block_swing_catch_B.Gain5_f
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 33;
	
	  ;% plant_block_swing_catch_B.IntegralGain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 34;
	
	  ;% plant_block_swing_catch_B.IntegralGain_i
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% plant_block_swing_catch_B.x
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 36;
	
	  ;% plant_block_swing_catch_B.y
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 37;
	
	  ;% plant_block_swing_catch_B.z
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 5;
    sectIdxOffset = 1;
    
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
    ;% Auto data (plant_block_swing_catch_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampA
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampA
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.CatchEnable_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_DW.CatchEnableuin_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% plant_block_swing_catch_DW.CatchEnableuin1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% plant_block_swing_catch_DW.CatchEnableuout_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% plant_block_swing_catch_DW.Encoder1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% plant_block_swing_catch_DW.FlywheelRotSpeedrads_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% plant_block_swing_catch_DW.FlywheelRotSpeedrads1_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% plant_block_swing_catch_DW.FlywheelRotSpeedrads2_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% plant_block_swing_catch_DW.GimbalEncoder1_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% plant_block_swing_catch_DW.GimbleVelocity_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
	  ;% plant_block_swing_catch_DW.PIDoutputvoltage_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 10;
	
	  ;% plant_block_swing_catch_DW.PendulumEncoder_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 11;
	
	  ;% plant_block_swing_catch_DW.PendulumEncodervel_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 17;
	  section.data(13).dtTransOffset = 12;
	
	  ;% plant_block_swing_catch_DW.PositionCompensation_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 18;
	  section.data(14).dtTransOffset = 13;
	
	  ;% plant_block_swing_catch_DW.Positionerror1_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 19;
	  section.data(15).dtTransOffset = 14;
	
	  ;% plant_block_swing_catch_DW.RPM_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 20;
	  section.data(16).dtTransOffset = 15;
	
	  ;% plant_block_swing_catch_DW.Restx_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 21;
	  section.data(17).dtTransOffset = 16;
	
	  ;% plant_block_swing_catch_DW.SwingEnable_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 22;
	  section.data(18).dtTransOffset = 17;
	
	  ;% plant_block_swing_catch_DW.SwingEnableuin_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 23;
	  section.data(19).dtTransOffset = 18;
	
	  ;% plant_block_swing_catch_DW.SwingEnableuin1_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 24;
	  section.data(20).dtTransOffset = 19;
	
	  ;% plant_block_swing_catch_DW.SwingEnableuout_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 25;
	  section.data(21).dtTransOffset = 20;
	
	  ;% plant_block_swing_catch_DW.Table_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 26;
	  section.data(22).dtTransOffset = 21;
	
	  ;% plant_block_swing_catch_DW.Tabledot_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 27;
	  section.data(23).dtTransOffset = 22;
	
	  ;% plant_block_swing_catch_DW.Scope_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 28;
	  section.data(24).dtTransOffset = 23;
	
	  ;% plant_block_swing_catch_DW.Scope1_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 29;
	  section.data(25).dtTransOffset = 24;
	
	  ;% plant_block_swing_catch_DW.Scope2_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 30;
	  section.data(26).dtTransOffset = 25;
	
	  ;% plant_block_swing_catch_DW.Scope3_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 31;
	  section.data(27).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.sfEvent
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.is_active_c3_plant_block_swing_
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_DW.is_c3_plant_block_swing_catch
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.isStable
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
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


  targMap.checksum0 = 3959971182;
  targMap.checksum1 = 2294589923;
  targMap.checksum2 = 2279569597;
  targMap.checksum3 = 1589219494;


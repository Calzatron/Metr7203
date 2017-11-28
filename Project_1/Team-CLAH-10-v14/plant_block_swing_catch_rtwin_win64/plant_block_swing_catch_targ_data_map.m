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
      section.nData     = 74;
      section.data(74)  = dumData; %prealloc
      
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
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel4_A
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 19;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel4_C
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 20;
	
	  ;% plant_block_swing_catch_P.Constant1_Value
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 21;
	
	  ;% plant_block_swing_catch_P.Constant2_Value
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 22;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel6_A
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 23;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel6_C
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 24;
	
	  ;% plant_block_swing_catch_P.SliderGain_Gain
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 25;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel5_A
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 26;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel5_C
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 27;
	
	  ;% plant_block_swing_catch_P.SliderGain_Gain_n
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 28;
	
	  ;% plant_block_swing_catch_P.SliderGain_Gain_a
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 29;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel3_A
	  section.data(22).logicalSrcIdx = 27;
	  section.data(22).dtTransOffset = 30;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel3_C
	  section.data(23).logicalSrcIdx = 28;
	  section.data(23).dtTransOffset = 31;
	
	  ;% plant_block_swing_catch_P.SliderGain_Gain_c
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 32;
	
	  ;% plant_block_swing_catch_P.Gain4_Gain
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 33;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel_A
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 34;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel_C
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 35;
	
	  ;% plant_block_swing_catch_P.Desiredrpm_Value
	  section.data(28).logicalSrcIdx = 37;
	  section.data(28).dtTransOffset = 36;
	
	  ;% plant_block_swing_catch_P.ProportionalGain_Gain
	  section.data(29).logicalSrcIdx = 38;
	  section.data(29).dtTransOffset = 37;
	
	  ;% plant_block_swing_catch_P.Integrator_IC
	  section.data(30).logicalSrcIdx = 39;
	  section.data(30).dtTransOffset = 38;
	
	  ;% plant_block_swing_catch_P.DerivativeGain_Gain
	  section.data(31).logicalSrcIdx = 40;
	  section.data(31).dtTransOffset = 39;
	
	  ;% plant_block_swing_catch_P.Filter_IC
	  section.data(32).logicalSrcIdx = 41;
	  section.data(32).dtTransOffset = 40;
	
	  ;% plant_block_swing_catch_P.FilterCoefficient_Gain
	  section.data(33).logicalSrcIdx = 42;
	  section.data(33).dtTransOffset = 41;
	
	  ;% plant_block_swing_catch_P.Saturation_UpperSat
	  section.data(34).logicalSrcIdx = 43;
	  section.data(34).dtTransOffset = 42;
	
	  ;% plant_block_swing_catch_P.Saturation_LowerSat
	  section.data(35).logicalSrcIdx = 44;
	  section.data(35).dtTransOffset = 43;
	
	  ;% plant_block_swing_catch_P.Gain_Gain
	  section.data(36).logicalSrcIdx = 45;
	  section.data(36).dtTransOffset = 44;
	
	  ;% plant_block_swing_catch_P.LowPassFilterGimbleVelocity_A
	  section.data(37).logicalSrcIdx = 46;
	  section.data(37).dtTransOffset = 45;
	
	  ;% plant_block_swing_catch_P.LowPassFilterGimbleVelocity_C
	  section.data(38).logicalSrcIdx = 47;
	  section.data(38).dtTransOffset = 46;
	
	  ;% plant_block_swing_catch_P.TransferFcn_A
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 47;
	
	  ;% plant_block_swing_catch_P.TransferFcn_C
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 48;
	
	  ;% plant_block_swing_catch_P.ProportionalGain_Gain_n
	  section.data(41).logicalSrcIdx = 54;
	  section.data(41).dtTransOffset = 49;
	
	  ;% plant_block_swing_catch_P.Integrator_IC_b
	  section.data(42).logicalSrcIdx = 55;
	  section.data(42).dtTransOffset = 50;
	
	  ;% plant_block_swing_catch_P.DerivativeGain_Gain_l
	  section.data(43).logicalSrcIdx = 56;
	  section.data(43).dtTransOffset = 51;
	
	  ;% plant_block_swing_catch_P.Filter_IC_m
	  section.data(44).logicalSrcIdx = 57;
	  section.data(44).dtTransOffset = 52;
	
	  ;% plant_block_swing_catch_P.FilterCoefficient_Gain_e
	  section.data(45).logicalSrcIdx = 58;
	  section.data(45).dtTransOffset = 53;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel2_A
	  section.data(46).logicalSrcIdx = 59;
	  section.data(46).dtTransOffset = 54;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel2_C
	  section.data(47).logicalSrcIdx = 60;
	  section.data(47).dtTransOffset = 55;
	
	  ;% plant_block_swing_catch_P.Gain_Gain_h
	  section.data(48).logicalSrcIdx = 63;
	  section.data(48).dtTransOffset = 56;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel1_A
	  section.data(49).logicalSrcIdx = 64;
	  section.data(49).dtTransOffset = 57;
	
	  ;% plant_block_swing_catch_P.LowPassFilterFlyWheel1_C
	  section.data(50).logicalSrcIdx = 65;
	  section.data(50).dtTransOffset = 58;
	
	  ;% plant_block_swing_catch_P.Constant_Value
	  section.data(51).logicalSrcIdx = 68;
	  section.data(51).dtTransOffset = 59;
	
	  ;% plant_block_swing_catch_P.Gain2_Gain
	  section.data(52).logicalSrcIdx = 69;
	  section.data(52).dtTransOffset = 60;
	
	  ;% plant_block_swing_catch_P.TableAccelerationtoGimbleVeloci
	  section.data(53).logicalSrcIdx = 70;
	  section.data(53).dtTransOffset = 61;
	
	  ;% plant_block_swing_catch_P.SliderGain_Gain_e
	  section.data(54).logicalSrcIdx = 71;
	  section.data(54).dtTransOffset = 62;
	
	  ;% plant_block_swing_catch_P.Saturation1_UpperSat
	  section.data(55).logicalSrcIdx = 72;
	  section.data(55).dtTransOffset = 63;
	
	  ;% plant_block_swing_catch_P.Saturation1_LowerSat
	  section.data(56).logicalSrcIdx = 73;
	  section.data(56).dtTransOffset = 64;
	
	  ;% plant_block_swing_catch_P.Constant_Value_d
	  section.data(57).logicalSrcIdx = 74;
	  section.data(57).dtTransOffset = 65;
	
	  ;% plant_block_swing_catch_P.ProportionalGain_Gain_i
	  section.data(58).logicalSrcIdx = 75;
	  section.data(58).dtTransOffset = 66;
	
	  ;% plant_block_swing_catch_P.Integrator_IC_p
	  section.data(59).logicalSrcIdx = 76;
	  section.data(59).dtTransOffset = 67;
	
	  ;% plant_block_swing_catch_P.DerivativeGain_Gain_n
	  section.data(60).logicalSrcIdx = 77;
	  section.data(60).dtTransOffset = 68;
	
	  ;% plant_block_swing_catch_P.Filter_IC_mr
	  section.data(61).logicalSrcIdx = 78;
	  section.data(61).dtTransOffset = 69;
	
	  ;% plant_block_swing_catch_P.FilterCoefficient_Gain_f
	  section.data(62).logicalSrcIdx = 79;
	  section.data(62).dtTransOffset = 70;
	
	  ;% plant_block_swing_catch_P.Saturation2_UpperSat
	  section.data(63).logicalSrcIdx = 80;
	  section.data(63).dtTransOffset = 71;
	
	  ;% plant_block_swing_catch_P.Saturation2_LowerSat
	  section.data(64).logicalSrcIdx = 81;
	  section.data(64).dtTransOffset = 72;
	
	  ;% plant_block_swing_catch_P.encodertoradians_Gain
	  section.data(65).logicalSrcIdx = 82;
	  section.data(65).dtTransOffset = 73;
	
	  ;% plant_block_swing_catch_P.IntegralGain_Gain
	  section.data(66).logicalSrcIdx = 83;
	  section.data(66).dtTransOffset = 74;
	
	  ;% plant_block_swing_catch_P.radsectorpm_Gain
	  section.data(67).logicalSrcIdx = 84;
	  section.data(67).dtTransOffset = 75;
	
	  ;% plant_block_swing_catch_P.Gain3_Gain
	  section.data(68).logicalSrcIdx = 85;
	  section.data(68).dtTransOffset = 76;
	
	  ;% plant_block_swing_catch_P.IntegralGain_Gain_m
	  section.data(69).logicalSrcIdx = 86;
	  section.data(69).dtTransOffset = 77;
	
	  ;% plant_block_swing_catch_P.Constant4_Value_l
	  section.data(70).logicalSrcIdx = 87;
	  section.data(70).dtTransOffset = 78;
	
	  ;% plant_block_swing_catch_P.DesiredEnergy_Value
	  section.data(71).logicalSrcIdx = 88;
	  section.data(71).dtTransOffset = 79;
	
	  ;% plant_block_swing_catch_P.InitialCondition_Value
	  section.data(72).logicalSrcIdx = 89;
	  section.data(72).dtTransOffset = 80;
	
	  ;% plant_block_swing_catch_P.FixPtUnitDelay1_InitialConditio
	  section.data(73).logicalSrcIdx = 90;
	  section.data(73).dtTransOffset = 81;
	
	  ;% plant_block_swing_catch_P.IntegralGain_Gain_d
	  section.data(74).logicalSrcIdx = 91;
	  section.data(74).dtTransOffset = 82;
	
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
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
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
	
	  ;% plant_block_swing_catch_B.LowPassFilterFlyWheel5
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% plant_block_swing_catch_B.LowPassFilterFlyWheel3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% plant_block_swing_catch_B.Product2
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% plant_block_swing_catch_B.LowPassFilterFlyWheel
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% plant_block_swing_catch_B.FilterCoefficient
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% plant_block_swing_catch_B.Saturation
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% plant_block_swing_catch_B.Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% plant_block_swing_catch_B.Derivative6
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% plant_block_swing_catch_B.ActualGimbleVelocity
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% plant_block_swing_catch_B.TransferFcn
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% plant_block_swing_catch_B.FilterCoefficient_a
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% plant_block_swing_catch_B.Sum
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% plant_block_swing_catch_B.LowPassFilterFlyWheel2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% plant_block_swing_catch_B.LowPassFilterFlyWheel1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% plant_block_swing_catch_B.E
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% plant_block_swing_catch_B.Product2_b
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% plant_block_swing_catch_B.w_2
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% plant_block_swing_catch_B.EnableSwingVelocity
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% plant_block_swing_catch_B.Product
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% plant_block_swing_catch_B.SliderGain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% plant_block_swing_catch_B.Abs
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% plant_block_swing_catch_B.Product1
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% plant_block_swing_catch_B.FilterCoefficient_p
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% plant_block_swing_catch_B.Sum_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 33;
	
	  ;% plant_block_swing_catch_B.Add
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 34;
	
	  ;% plant_block_swing_catch_B.encodertoradians
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% plant_block_swing_catch_B.Derivative
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 36;
	
	  ;% plant_block_swing_catch_B.IntegralGain
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 37;
	
	  ;% plant_block_swing_catch_B.radsectorpm
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 38;
	
	  ;% plant_block_swing_catch_B.theta4
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 39;
	
	  ;% plant_block_swing_catch_B.IntegralGain_a
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 40;
	
	  ;% plant_block_swing_catch_B.Resetafterswingstate
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 41;
	
	  ;% plant_block_swing_catch_B.FixPtUnitDelay1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 42;
	
	  ;% plant_block_swing_catch_B.Reset
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 43;
	
	  ;% plant_block_swing_catch_B.Sum3
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 44;
	
	  ;% plant_block_swing_catch_B.IntegralGain_p
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 45;
	
	  ;% plant_block_swing_catch_B.x
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 46;
	
	  ;% plant_block_swing_catch_B.y
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 47;
	
	  ;% plant_block_swing_catch_B.z
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 48;
	
	  ;% plant_block_swing_catch_B.r
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 49;
	
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
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampA
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampA
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampA
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.AllStopr_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_DW.CatchEnable_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% plant_block_swing_catch_DW.CatchEnableuin1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% plant_block_swing_catch_DW.CatchEnableuout_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% plant_block_swing_catch_DW.Encoder1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% plant_block_swing_catch_DW.FlywheelVoltage_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% plant_block_swing_catch_DW.GimbalEncoder1_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% plant_block_swing_catch_DW.GimbleVelocityscope_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% plant_block_swing_catch_DW.GimbleVoltage_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% plant_block_swing_catch_DW.PendulumEncoder_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% plant_block_swing_catch_DW.PendulumEncodervel_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% plant_block_swing_catch_DW.Restx_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
	  ;% plant_block_swing_catch_DW.SwingEnableuin2_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 12;
	
	  ;% plant_block_swing_catch_DW.SwingEnableuin3_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 13;
	
	  ;% plant_block_swing_catch_DW.SwingEnableuout_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 14;
	
	  ;% plant_block_swing_catch_DW.SwingEnabley_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 15;
	
	  ;% plant_block_swing_catch_DW.SwingOuput_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 16;
	
	  ;% plant_block_swing_catch_DW.FlywheelRotSpeedrads_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 17;
	
	  ;% plant_block_swing_catch_DW.RPM_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 18;
	
	  ;% plant_block_swing_catch_DW.catchcheck_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 19;
	
	  ;% plant_block_swing_catch_DW.catcherror_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 20;
	
	  ;% plant_block_swing_catch_DW.swingcheck_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 27;
	  section.data(22).dtTransOffset = 21;
	
	  ;% plant_block_swing_catch_DW.swingcheck1_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 28;
	  section.data(23).dtTransOffset = 22;
	
	  ;% plant_block_swing_catch_DW.swingcheck2_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 29;
	  section.data(24).dtTransOffset = 23;
	
	  ;% plant_block_swing_catch_DW.swingerror_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 30;
	  section.data(25).dtTransOffset = 24;
	
	  ;% plant_block_swing_catch_DW.Collect_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 31;
	  section.data(26).dtTransOffset = 25;
	
	  ;% plant_block_swing_catch_DW.Energy_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 32;
	  section.data(27).dtTransOffset = 26;
	
	  ;% plant_block_swing_catch_DW.Error_PWORK.LoggedData
	  section.data(28).logicalSrcIdx = 33;
	  section.data(28).dtTransOffset = 27;
	
	  ;% plant_block_swing_catch_DW.K_PWORK.LoggedData
	  section.data(29).logicalSrcIdx = 34;
	  section.data(29).dtTransOffset = 28;
	
	  ;% plant_block_swing_catch_DW.Lyapunovseqn_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 35;
	  section.data(30).dtTransOffset = 29;
	
	  ;% plant_block_swing_catch_DW.MinEnergy_PWORK.LoggedData
	  section.data(31).logicalSrcIdx = 36;
	  section.data(31).dtTransOffset = 30;
	
	  ;% plant_block_swing_catch_DW.Theta__PWORK.LoggedData
	  section.data(32).logicalSrcIdx = 37;
	  section.data(32).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.sfEvent
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.is_active_c3_plant_block_swing_
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% plant_block_swing_catch_DW.is_c3_plant_block_swing_catch
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% plant_block_swing_catch_DW.isStable
	  section.data(1).logicalSrcIdx = 41;
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


  targMap.checksum0 = 1425515457;
  targMap.checksum1 = 3403792553;
  targMap.checksum2 = 1572016139;
  targMap.checksum3 = 1125992215;


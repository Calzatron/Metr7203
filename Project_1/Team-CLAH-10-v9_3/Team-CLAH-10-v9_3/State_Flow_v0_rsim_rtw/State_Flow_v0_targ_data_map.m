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
    ;% Auto data (rtP)
    ;%
      section.nData     = 44;
      section.data(44)  = dumData; %prealloc
      
	  ;% rtP.SFunction_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.SFunction_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtP.SFunction_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% rtP.SFunction_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 10;
	
	  ;% rtP.SFunction_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 11;
	
	  ;% rtP.SFunction_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% rtP.SFunction_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 14;
	
	  ;% rtP.SFunction_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 16;
	
	  ;% rtP.Gain4_Gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 17;
	
	  ;% rtP.Gain_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 18;
	
	  ;% rtP.TransferFcn1_A
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 19;
	
	  ;% rtP.TransferFcn1_C
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 20;
	
	  ;% rtP.Constant1_Value
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 21;
	
	  ;% rtP.ProportionalGain_Gain
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 22;
	
	  ;% rtP.Integrator_IC
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 23;
	
	  ;% rtP.DerivativeGain_Gain
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 24;
	
	  ;% rtP.Filter_IC
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 25;
	
	  ;% rtP.FilterCoefficient_Gain
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 26;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 27;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 28;
	
	  ;% rtP.Gain1_Gain
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 29;
	
	  ;% rtP.Stepon_Time
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 30;
	
	  ;% rtP.Stepon_Y0
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 31;
	
	  ;% rtP.Stepon_YFinal
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 32;
	
	  ;% rtP.Stepoff_Time
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 33;
	
	  ;% rtP.Stepoff_Y0
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 34;
	
	  ;% rtP.Stepoff_YFinal
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 35;
	
	  ;% rtP.InitialCondition_Value
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 36;
	
	  ;% rtP.Constant2_Value
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 37;
	
	  ;% rtP.FixPtUnitDelay1_InitialConditio
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 38;
	
	  ;% rtP.Gain4_Gain_j
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 39;
	
	  ;% rtP.Constant1_Value_g
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 40;
	
	  ;% rtP.Saturation_UpperSat_h
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 41;
	
	  ;% rtP.Saturation_LowerSat_j
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 42;
	
	  ;% rtP.Gain5_Gain
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 43;
	
	  ;% rtP.Gain_Gain_i
	  section.data(36).logicalSrcIdx = 37;
	  section.data(36).dtTransOffset = 44;
	
	  ;% rtP.Constant_Value
	  section.data(37).logicalSrcIdx = 38;
	  section.data(37).dtTransOffset = 45;
	
	  ;% rtP.Gain2_Gain
	  section.data(38).logicalSrcIdx = 39;
	  section.data(38).dtTransOffset = 46;
	
	  ;% rtP.Gain3_Gain
	  section.data(39).logicalSrcIdx = 40;
	  section.data(39).dtTransOffset = 47;
	
	  ;% rtP.Gain1_Gain_a
	  section.data(40).logicalSrcIdx = 41;
	  section.data(40).dtTransOffset = 48;
	
	  ;% rtP.Gain5_Gain_b
	  section.data(41).logicalSrcIdx = 42;
	  section.data(41).dtTransOffset = 49;
	
	  ;% rtP.IntegralGain_Gain
	  section.data(42).logicalSrcIdx = 43;
	  section.data(42).dtTransOffset = 50;
	
	  ;% rtP.Saturation1_UpperSat
	  section.data(43).logicalSrcIdx = 44;
	  section.data(43).dtTransOffset = 51;
	
	  ;% rtP.Saturation1_LowerSat
	  section.data(44).logicalSrcIdx = 45;
	  section.data(44).dtTransOffset = 52;
	
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
    ;% Auto data (rtB)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% rtB.SFunction
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.Gain4
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% rtB.FilterCoefficient
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtB.Sum
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtB.Saturation
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtB.theta
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% rtB.Stepon
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% rtB.Stepoff
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% rtB.FixPtUnitDelay1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% rtB.Reset
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% rtB.Sum2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtB.TrigonometricFunction
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtB.Gain3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtB.TrigonometricFunction1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtB.gimbalmotorvoltage
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtB.Gain5
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtB.IntegralGain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtB.Saturation1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
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
    nTotSects     = 3;
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
    ;% Auto data (rtDW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.Derivative_RWORK.TimeStampA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.Derivative1_RWORK.TimeStampA
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtDW.Encoder1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.FlywheelRotSpeedrads_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.FlywheelRotSpeedrads1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.FlywheelRotSpeedrads2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.GimbalEncoder1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.PIDoutputvoltage_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.PendulumEncoder_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.RPM_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.Scope_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.Scope1_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.Scope2_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.Scope3_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.Saturation_MODE
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.Stepon_MODE
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.Stepoff_MODE
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.Saturation_MODE_l
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.Saturation1_MODE
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 2685009145;
  targMap.checksum1 = 3934435865;
  targMap.checksum2 = 1415350355;
  targMap.checksum3 = 2059386061;


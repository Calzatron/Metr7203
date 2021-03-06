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
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% rtP.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.B
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% rtP.C
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 48;
	
	  ;% rtP.C_0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 66;
	
	  ;% rtP.K_i
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 78;
	
	  ;% rtP.K_r
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 82;
	
	  ;% rtP.K_sf
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 86;
	
	  ;% rtP.L
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 98;
	
	  ;% rtP.SensorNoise_Minimum
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 116;
	
	  ;% rtP.SensorNoise_Maximum
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 117;
	
	  ;% rtP.SensorNoise_Seed
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 118;
	
	  ;% rtP.StateSpace_X0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 119;
	
	  ;% rtP.Integrator_IC
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 120;
	
	  ;% rtP.Step_Time
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 121;
	
	  ;% rtP.Step_Y0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 122;
	
	  ;% rtP.Step_YFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 123;
	
	  ;% rtP.Step1_Time
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 124;
	
	  ;% rtP.Step1_Y0
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 125;
	
	  ;% rtP.Step1_YFinal
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 126;
	
	  ;% rtP.Step2_Time
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 127;
	
	  ;% rtP.Step2_Y0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 128;
	
	  ;% rtP.Step2_YFinal
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 129;
	
	  ;% rtP.Step3_Time
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 130;
	
	  ;% rtP.Step3_Y0
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 131;
	
	  ;% rtP.Step3_YFinal
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 132;
	
	  ;% rtP.Integrator1_IC
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 133;
	
	  ;% rtP.Integrator1_UpperSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 134;
	
	  ;% rtP.Integrator1_LowerSat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 135;
	
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
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtB.y
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.Sum3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.Add2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtB.Add1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtB.Kr
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtB.InputVoltage
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtB.x_dot
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtB.Sum2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 18;
	
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
    nTotSects     = 4;
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
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.SensorNoise_NextOutput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.TimeStampA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.LastUAtTimeA
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.TimeStampB
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% rtDW.LastUAtTimeB
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% rtDW.EncoderReading_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.Error_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.Input_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.InputOutput_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.IntegralScope_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ObserverPositions_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.ObserverStates_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.PlantInput_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.PlantPositions_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.PlantStates_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.Reference_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.RandSeed
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.Step_MODE
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.Step1_MODE
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.Step2_MODE
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.Step3_MODE
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.Integrator1_MODE
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 1939716385;
  targMap.checksum1 = 1654384753;
  targMap.checksum2 = 1504546028;
  targMap.checksum3 = 4237664371;


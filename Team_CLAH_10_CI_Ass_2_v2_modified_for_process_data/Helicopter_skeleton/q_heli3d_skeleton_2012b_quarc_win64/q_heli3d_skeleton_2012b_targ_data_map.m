  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (q_heli3d_skeleton_2012b_P)
    ;%
      section.nData     = 76;
      section.data(76)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POLeading
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POTrailing
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_2012b_P.Constant_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_heli3d_skeleton_2012b_P.SliderGain_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% q_heli3d_skeleton_2012b_P.Step_Time
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% q_heli3d_skeleton_2012b_P.Step_Y0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% q_heli3d_skeleton_2012b_P.Step_YFinal
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% q_heli3d_skeleton_2012b_P.Constant_Value_e
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% q_heli3d_skeleton_2012b_P.Constant1_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% q_heli3d_skeleton_2012b_P.Saturation_UpperSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_2012b_P.Saturation_LowerSat
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% q_heli3d_skeleton_2012b_P.Step_Time_a
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% q_heli3d_skeleton_2012b_P.Step_Y0_o
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% q_heli3d_skeleton_2012b_P.Step_YFinal_o
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% q_heli3d_skeleton_2012b_P.Constant_Value_k
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% q_heli3d_skeleton_2012b_P.Constant1_Value_d
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% q_heli3d_skeleton_2012b_P.Saturation1_UpperSat
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% q_heli3d_skeleton_2012b_P.Saturation1_LowerSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% q_heli3d_skeleton_2012b_P.Integrator1_IC
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% q_heli3d_skeleton_2012b_P.SliderGain_Gain_m
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% q_heli3d_skeleton_2012b_P.Integrator_IC
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% q_heli3d_skeleton_2012b_P.Gain3_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% q_heli3d_skeleton_2012b_P.Bias_Bias
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 48;
	
	  ;% q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_UpperSat
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 49;
	
	  ;% q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_LowerSat
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 50;
	
	  ;% q_heli3d_skeleton_2012b_P.AmplifierGainPreCompensation_Ga
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 51;
	
	  ;% q_heli3d_skeleton_2012b_P.DACBLimitV_UpperSat
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 52;
	
	  ;% q_heli3d_skeleton_2012b_P.DACBLimitV_LowerSat
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 53;
	
	  ;% q_heli3d_skeleton_2012b_P.AmplifierGain_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 54;
	
	  ;% q_heli3d_skeleton_2012b_P.EncoderResolutionElevationradco
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 55;
	
	  ;% q_heli3d_skeleton_2012b_P.EncoderResolutionPitchradcount_
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 56;
	
	  ;% q_heli3d_skeleton_2012b_P.EncoderResolutionTravelradcount
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 57;
	
	  ;% q_heli3d_skeleton_2012b_P.InitialElevationrad_Bias
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 58;
	
	  ;% q_heli3d_skeleton_2012b_P.EnableAmp_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 59;
	
	  ;% q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_IC
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 63;
	
	  ;% q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_UpperSa
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 64;
	
	  ;% q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_LowerSa
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 65;
	
	  ;% q_heli3d_skeleton_2012b_P.DesPositionTraveldeg_IC
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 66;
	
	  ;% q_heli3d_skeleton_2012b_P.Gain1_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 67;
	
	  ;% q_heli3d_skeleton_2012b_P.Gain6_Gain
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 68;
	
	  ;% q_heli3d_skeleton_2012b_P.Gain4_Gain
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 80;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn_A
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 84;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn_C
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 85;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn_D
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 86;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn1_A
	  section.data(60).logicalSrcIdx = 60;
	  section.data(60).dtTransOffset = 87;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn1_C
	  section.data(61).logicalSrcIdx = 61;
	  section.data(61).dtTransOffset = 88;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn1_D
	  section.data(62).logicalSrcIdx = 62;
	  section.data(62).dtTransOffset = 89;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn2_A
	  section.data(63).logicalSrcIdx = 64;
	  section.data(63).dtTransOffset = 90;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn2_C
	  section.data(64).logicalSrcIdx = 65;
	  section.data(64).dtTransOffset = 91;
	
	  ;% q_heli3d_skeleton_2012b_P.TransferFcn2_D
	  section.data(65).logicalSrcIdx = 66;
	  section.data(65).dtTransOffset = 92;
	
	  ;% q_heli3d_skeleton_2012b_P.Gain2_Gain
	  section.data(66).logicalSrcIdx = 68;
	  section.data(66).dtTransOffset = 93;
	
	  ;% q_heli3d_skeleton_2012b_P.Gain_Gain
	  section.data(67).logicalSrcIdx = 69;
	  section.data(67).dtTransOffset = 111;
	
	  ;% q_heli3d_skeleton_2012b_P.Gain1_Gain_l
	  section.data(68).logicalSrcIdx = 70;
	  section.data(68).dtTransOffset = 123;
	
	  ;% q_heli3d_skeleton_2012b_P.RateTransitionz_X0
	  section.data(69).logicalSrcIdx = 71;
	  section.data(69).dtTransOffset = 159;
	
	  ;% q_heli3d_skeleton_2012b_P.Inverse_Gain
	  section.data(70).logicalSrcIdx = 72;
	  section.data(70).dtTransOffset = 160;
	
	  ;% q_heli3d_skeleton_2012b_P.Bias_Bias_k
	  section.data(71).logicalSrcIdx = 73;
	  section.data(71).dtTransOffset = 161;
	
	  ;% q_heli3d_skeleton_2012b_P.Constant_Value_c
	  section.data(72).logicalSrcIdx = 74;
	  section.data(72).dtTransOffset = 162;
	
	  ;% q_heli3d_skeleton_2012b_P.RateTransitionx_X0
	  section.data(73).logicalSrcIdx = 75;
	  section.data(73).dtTransOffset = 163;
	
	  ;% q_heli3d_skeleton_2012b_P.CalibrationXdegsV_Gain
	  section.data(74).logicalSrcIdx = 76;
	  section.data(74).dtTransOffset = 164;
	
	  ;% q_heli3d_skeleton_2012b_P.RateTransitiony_X0
	  section.data(75).logicalSrcIdx = 77;
	  section.data(75).dtTransOffset = 165;
	
	  ;% q_heli3d_skeleton_2012b_P.CalibrationYdegsV_Gain
	  section.data(76).logicalSrcIdx = 78;
	  section.data(76).dtTransOffset = 166;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 83;
	  section.data(5).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 84;
	  section.data(6).dtTransOffset = 7;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 85;
	  section.data(7).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_2012b_P.HILReadEncoderTimebase_Clock
	  section.data(8).logicalSrcIdx = 86;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 88;
	  section.data(2).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DIChannels
	  section.data(3).logicalSrcIdx = 89;
	  section.data(3).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOChannels
	  section.data(4).logicalSrcIdx = 90;
	  section.data(4).dtTransOffset = 20;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_EIChannels
	  section.data(5).logicalSrcIdx = 91;
	  section.data(5).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_EIQuadrature
	  section.data(6).logicalSrcIdx = 92;
	  section.data(6).dtTransOffset = 32;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POChannels
	  section.data(7).logicalSrcIdx = 93;
	  section.data(7).dtTransOffset = 33;
	
	  ;% q_heli3d_skeleton_2012b_P.HILReadEncoderTimebase_Channels
	  section.data(8).logicalSrcIdx = 94;
	  section.data(8).dtTransOffset = 41;
	
	  ;% q_heli3d_skeleton_2012b_P.HILReadEncoderTimebase_SamplesI
	  section.data(9).logicalSrcIdx = 95;
	  section.data(9).dtTransOffset = 44;
	
	  ;% q_heli3d_skeleton_2012b_P.HILWriteAnalog_Channels
	  section.data(10).logicalSrcIdx = 96;
	  section.data(10).dtTransOffset = 45;
	
	  ;% q_heli3d_skeleton_2012b_P.HILWriteDigital_Channels
	  section.data(11).logicalSrcIdx = 97;
	  section.data(11).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_P.GameController_ControllerNumber
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 101;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 102;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 103;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 104;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 105;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 106;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 107;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 108;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 109;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 110;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 111;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 112;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 113;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 114;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 115;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 116;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 117;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 118;
	  section.data(19).dtTransOffset = 18;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 119;
	  section.data(20).dtTransOffset = 19;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 120;
	  section.data(21).dtTransOffset = 20;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 121;
	  section.data(22).dtTransOffset = 21;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 122;
	  section.data(23).dtTransOffset = 22;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 123;
	  section.data(24).dtTransOffset = 23;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 124;
	  section.data(25).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 125;
	  section.data(26).dtTransOffset = 25;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 126;
	  section.data(27).dtTransOffset = 26;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 127;
	  section.data(28).dtTransOffset = 27;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 128;
	  section.data(29).dtTransOffset = 28;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 129;
	  section.data(30).dtTransOffset = 29;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 130;
	  section.data(31).dtTransOffset = 30;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 131;
	  section.data(32).dtTransOffset = 31;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 132;
	  section.data(33).dtTransOffset = 32;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 133;
	  section.data(34).dtTransOffset = 33;
	
	  ;% q_heli3d_skeleton_2012b_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 134;
	  section.data(35).dtTransOffset = 34;
	
	  ;% q_heli3d_skeleton_2012b_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 135;
	  section.data(36).dtTransOffset = 35;
	
	  ;% q_heli3d_skeleton_2012b_P.HILWriteAnalog_Active
	  section.data(37).logicalSrcIdx = 136;
	  section.data(37).dtTransOffset = 36;
	
	  ;% q_heli3d_skeleton_2012b_P.HILWriteDigital_Active
	  section.data(38).logicalSrcIdx = 137;
	  section.data(38).dtTransOffset = 37;
	
	  ;% q_heli3d_skeleton_2012b_P.GameController_AutoCenter
	  section.data(39).logicalSrcIdx = 138;
	  section.data(39).dtTransOffset = 38;
	
	  ;% q_heli3d_skeleton_2012b_P.GameController_Enabled
	  section.data(40).logicalSrcIdx = 139;
	  section.data(40).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    ;% Auto data (q_heli3d_skeleton_2012b_B)
    ;%
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_B.SliderGain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_B.Constant
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_2012b_B.Constant1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_2012b_B.Saturation
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_2012b_B.Constant_c
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_2012b_B.Constant1_c
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_2012b_B.Saturation1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_2012b_B.SliderGain_k
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli3d_skeleton_2012b_B.Integrator
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% q_heli3d_skeleton_2012b_B.Gain3
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% q_heli3d_skeleton_2012b_B.Sum
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% q_heli3d_skeleton_2012b_B.DACBLimitV
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% q_heli3d_skeleton_2012b_B.AmplifierGain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 21;
	
	  ;% q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_2012b_B.InitialElevationrad
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25;
	
	  ;% q_heli3d_skeleton_2012b_B.Gain1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% q_heli3d_skeleton_2012b_B.Gain6
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 28;
	
	  ;% q_heli3d_skeleton_2012b_B.Sum1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% q_heli3d_skeleton_2012b_B.TmpSignalConversionAtMeasInport
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% q_heli3d_skeleton_2012b_B.Gain4
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 35;
	
	  ;% q_heli3d_skeleton_2012b_B.TransferFcn
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 37;
	
	  ;% q_heli3d_skeleton_2012b_B.TransferFcn1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 38;
	
	  ;% q_heli3d_skeleton_2012b_B.TransferFcn2
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 39;
	
	  ;% q_heli3d_skeleton_2012b_B.Derivative
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 40;
	
	  ;% q_heli3d_skeleton_2012b_B.Gain2
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 43;
	
	  ;% q_heli3d_skeleton_2012b_B.Add
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 46;
	
	  ;% q_heli3d_skeleton_2012b_B.RateTransitionz
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 52;
	
	  ;% q_heli3d_skeleton_2012b_B.RateTransitionx
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 53;
	
	  ;% q_heli3d_skeleton_2012b_B.CalibrationXdegsV
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 54;
	
	  ;% q_heli3d_skeleton_2012b_B.RateTransitiony
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 55;
	
	  ;% q_heli3d_skeleton_2012b_B.CalibrationYdegsV
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 56;
	
	  ;% q_heli3d_skeleton_2012b_B.startTime
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 57;
	
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
    nTotSects     = 10;
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
    ;% Auto data (q_heli3d_skeleton_2012b_DWork)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% q_heli3d_skeleton_2012b_DWork.RateTransitionz_Buffer0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% q_heli3d_skeleton_2012b_DWork.RateTransitionx_Buffer0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% q_heli3d_skeleton_2012b_DWork.RateTransitiony_Buffer0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.GameController_Controller
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.Derivative_RWORK.TimeStampA
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILWriteDigital_PWORK
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_2012b_DWork.ErrorbetweenReferenceandActual_.LoggedData
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_2012b_DWork.IntegralInput_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_2012b_DWork.Meas_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_2012b_DWork.Motorvoltage_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_2012b_DWork.Reference_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_2012b_DWork.ReferenceInput_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli3d_skeleton_2012b_DWork.ReferenceInput1_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_2012b_DWork.Scope1_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli3d_skeleton_2012b_DWork.StateFeedbackInput_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli3d_skeleton_2012b_DWork.rate_est_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli3d_skeleton_2012b_DWork.rate_est1_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli3d_skeleton_2012b_DWork.u_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_heli3d_skeleton_2012b_DWork.x_hat_angle_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 29;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_heli3d_skeleton_2012b_DWork.x_hat_rates_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 30;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_heli3d_skeleton_2012b_DWork.y1_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 31;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_2012b_DWork.y2_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 32;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_heli3d_skeleton_2012b_DWork.y3_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 33;
	  section.data(19).dtTransOffset = 18;
	
	  ;% q_heli3d_skeleton_2012b_DWork.y4_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 34;
	  section.data(20).dtTransOffset = 19;
	
	  ;% q_heli3d_skeleton_2012b_DWork.y_hat_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 35;
	  section.data(21).dtTransOffset = 20;
	
	  ;% q_heli3d_skeleton_2012b_DWork.y_hatelevationandtravel_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 36;
	  section.data(22).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 7;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 15;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 23;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 42;
	  section.data(6).dtTransOffset = 31;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 43;
	  section.data(7).dtTransOffset = 39;
	
	  ;% q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Buffer
	  section.data(8).logicalSrcIdx = 44;
	  section.data(8).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_2012b_DWork.HILWriteDigital_Buffer
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
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


  targMap.checksum0 = 1336612095;
  targMap.checksum1 = 1681430765;
  targMap.checksum2 = 3524153349;
  targMap.checksum3 = 3524924486;


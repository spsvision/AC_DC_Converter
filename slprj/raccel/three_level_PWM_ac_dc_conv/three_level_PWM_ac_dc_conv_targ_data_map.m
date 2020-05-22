  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
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
      section.nData     = 60;
      section.data(60)  = dumData; %prealloc
      
	  ;% rtP.ACVoltageV120V_Amplitude
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.DiscretePWMGenerator6Level_Freq
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.ACVoltageV120V_Frequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.DiscretePWMGenerator6Level_Internal
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.ACVoltageV120V_Phase
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.DiscretePWMGenerator6Level_Phase
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.DiscretePWMGenerator6Level_mIndex
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Triangle_rep_seq_y
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Constant_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtP.Constant_Value_ouuylrsk2d
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtP.AC_Bias
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtP.StateSpace_P1_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% rtP.StateSpace_P1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtP.StateSpace_P2_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 2104;
	
	  ;% rtP.StateSpace_P2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 2106;
	
	  ;% rtP.StateSpace_P3_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 2110;
	
	  ;% rtP.StateSpace_P3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 2112;
	
	  ;% rtP.StateSpace_P4_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 2122;
	
	  ;% rtP.StateSpace_P4
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 2124;
	
	  ;% rtP.StateSpace_P5_Size
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 3924;
	
	  ;% rtP.StateSpace_P5
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 3926;
	
	  ;% rtP.StateSpace_P6_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 3954;
	
	  ;% rtP.StateSpace_P6
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 3956;
	
	  ;% rtP.StateSpace_P7_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 3970;
	
	  ;% rtP.StateSpace_P7
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 3972;
	
	  ;% rtP.StateSpace_P8_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 3986;
	
	  ;% rtP.StateSpace_P8
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 3988;
	
	  ;% rtP.StateSpace_P9_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 4002;
	
	  ;% rtP.StateSpace_P9
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 4004;
	
	  ;% rtP.StateSpace_P10_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 4005;
	
	  ;% rtP.StateSpace_P10
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 4007;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 4008;
	
	  ;% rtP.donotdeletethisgain_Gain_jzoyz0z31n
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 4009;
	
	  ;% rtP.donotdeletethisgain_Gain_aiprxxe3wc
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 4010;
	
	  ;% rtP.donotdeletethisgain_Gain_lbhty2tvzw
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 4011;
	
	  ;% rtP.Gain2_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 4012;
	
	  ;% rtP.Constant_Value_fqq1ckc0wv
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 4013;
	
	  ;% rtP.Switch_Threshold
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 4016;
	
	  ;% rtP.LookUpTable1_bp01Data
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 4017;
	
	  ;% rtP.donotdeletethisgain_Gain_k14ykx3pkj
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 4021;
	
	  ;% rtP.Constant_Value_cieer5snor
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 4022;
	
	  ;% rtP.Constant1_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 4023;
	
	  ;% rtP.Vpp60Hz_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 4024;
	
	  ;% rtP.Constant_Value_eblvmaugeh
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 4025;
	
	  ;% rtP.eee_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 4026;
	
	  ;% rtP.gate_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 4027;
	
	  ;% rtP.eee_Value_ltwrydmito
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 4028;
	
	  ;% rtP.gate_Value_mefctpxgq1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 4029;
	
	  ;% rtP.eee_Value_c3qjua3w0z
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 4030;
	
	  ;% rtP.gate_Value_lxdkjkxc5z
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 4031;
	
	  ;% rtP.eee_Value_bubd4jwjra
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 4032;
	
	  ;% rtP.gate_Value_cgaoozqbxm
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 4033;
	
	  ;% rtP.eee_Value_feaxwyjqep
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 4034;
	
	  ;% rtP.gate_Value_godmk3yhan
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 4035;
	
	  ;% rtP.eee_Value_itsuzfhxkb
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 4036;
	
	  ;% rtP.gate_Value_jwa3agpy2x
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 4037;
	
	  ;% rtP.eee_Value_hng2mmrvii
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 4038;
	
	  ;% rtP.gate_Value_my4wneoq4r
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 4039;
	
	  ;% rtP.eee_Value_cszrsograu
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 4040;
	
	  ;% rtP.gate_Value_m2iq3im1pa
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 4041;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.CombinatorialLogic_table
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
    nTotSects     = 2;
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
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% rtB.opl0oc5efs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.bqotgs0lpr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.fw30ihycwi
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtB.ky3ypmchwb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 34;
	
	  ;% rtB.i2ascqprig
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 35;
	
	  ;% rtB.lyfopxbigf
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 36;
	
	  ;% rtB.lhtjuefs1s
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 37;
	
	  ;% rtB.jmr2urlziy
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 38;
	
	  ;% rtB.hwgujgig0r
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 39;
	
	  ;% rtB.ej0uzzsc2t
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 40;
	
	  ;% rtB.npjsoehvli
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 41;
	
	  ;% rtB.boj5trihky
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 47;
	
	  ;% rtB.nhlp2yjplc
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 48;
	
	  ;% rtB.jbvxwyij0y
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 49;
	
	  ;% rtB.h4uqpfbbgz
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 50;
	
	  ;% rtB.ieqnits2k1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 51;
	
	  ;% rtB.cb1lqzfxpl
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 52;
	
	  ;% rtB.mtnwul5crs
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 53;
	
	  ;% rtB.br2tmxhmz2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 54;
	
	  ;% rtB.l1vu1bkjhv
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 55;
	
	  ;% rtB.g4bvofm2sv
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 56;
	
	  ;% rtB.e021regt1w
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 57;
	
	  ;% rtB.ouxsqqztxa
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 58;
	
	  ;% rtB.bddpitx5vb
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 59;
	
	  ;% rtB.a15cmwzmks
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 60;
	
	  ;% rtB.gdyoxwm15d
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 61;
	
	  ;% rtB.lwgwdivmux
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 62;
	
	  ;% rtB.hiib4anv4i
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 63;
	
	  ;% rtB.e4ua4g0fko
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 64;
	
	  ;% rtB.mjnjjwxjad
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 65;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lobxxus3zf
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    sectIdxOffset = 2;
    
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
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.oetzn5jscx
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.kytgfvyij5
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.e3nmbwzb2u.LoggedData
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 22;
	
	  ;% rtDW.drxsehypdl.LoggedData
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 24;
	
	  ;% rtDW.jti1ku22dn.AQHandles
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 27;
	
	  ;% rtDW.pexeigqnvk.AQHandles
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 28;
	
	  ;% rtDW.kyyge3hbne.LoggedData
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 29;
	
	  ;% rtDW.hxaystgzkw.LoggedData
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 30;
	
	  ;% rtDW.aogymm20xl.AQHandles
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 36;
	
	  ;% rtDW.ine0liz2jy.LoggedData
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.czwcnoupsx
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jtyytfci20
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 23;
	
	  ;% rtDW.hwtnslxeeo
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.k0d12xqate
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.mrboyrtusm
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.khbjj3tefj
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
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


  targMap.checksum0 = 949554994;
  targMap.checksum1 = 1332906209;
  targMap.checksum2 = 109567221;
  targMap.checksum3 = 659647683;


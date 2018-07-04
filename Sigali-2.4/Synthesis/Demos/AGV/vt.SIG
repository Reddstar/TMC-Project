process vt =
     ( ? boolean C1;
         boolean C2;
         boolean C3;
         boolean C4;
         boolean C5;
         boolean C6;
         boolean C7;
         boolean C8;
         boolean C9;
         boolean C10;
       ! event Tick;
         boolean NEXT_AGV11;
         boolean NEXT_AGV12;
         boolean NEXT_AGV13;
         boolean NEXT_AGV14;
         boolean NEXT_AGV15;
         boolean NEXT_AGV16;
         boolean NEXT_AGV21;
         boolean NEXT_AGV22;
         boolean NEXT_AGV23;
         boolean NEXT_AGV24;
         boolean NEXT_AGV25;
         boolean NEXT_AGV26;
         boolean NEXT_AGV27;
         boolean NEXT_AGV28;
         boolean NEXT_AGV29;
         boolean NEXT_AGV210;
         boolean NEXT_AGV211;
         boolean NEXT_AGV212;
         boolean NEXT_AGV31;
         boolean NEXT_AGV32;
         boolean NEXT_AGV33;
         boolean NEXT_AGV34;
         boolean NEXT_AGV35;
         boolean NEXT_AGV36;
         boolean NEXT_AGV41;
         boolean NEXT_AGV42;
         boolean NEXT_AGV43;
         boolean NEXT_AGV44;
         boolean NEXT_AGV45;
         boolean NEXT_AGV46;
         boolean NEXT_AGV47;
         boolean NEXT_AGV48;
         boolean NEXT_AGV49;
         boolean NEXT_AGV410;
         boolean NEXT_AGV51;
         boolean NEXT_AGV52;
         boolean NEXT_AGV53;
         boolean NEXT_AGV54;
         boolean NEXT_AGV55;
         boolean NEXT_AGV56;
         boolean NEXT_AGV57;
         boolean NEXT_AGV58;
         boolean NEXT_WST11;
         boolean NEXT_WST12;
         boolean NEXT_WST13;
         boolean NEXT_WST14;
         boolean NEXT_WST21;
         boolean NEXT_WST22;
         boolean NEXT_WST23;
         boolean NEXT_WST24;
         boolean NEXT_WST31;
         boolean NEXT_WST32;
         boolean NEXT_WST33;
         boolean NEXT_WST34;
         boolean NEXT_WST41;
         boolean NEXT_WST42;
         boolean NEXT_WST51;
         boolean NEXT_WST52;
         boolean NEXT_WST53;
         boolean NEXT_WST54;
         boolean NEXT_WST55;
         boolean NEXT_WST56;
         boolean Conflit;
     )
   (| (| (| Tick := true
          | C1 ^= C2 ^= C3 ^= C4 ^= C5 ^= C6 ^= C7 ^= C8 ^= C9 ^= C10 ^= Tick
          |)
       | (| AGV1{}
          | AGV2{}
          | AGV3{}
          | AGV4{}
          | AGV5{}
          | WORK_STATION1{}
          | WORK_STATION2{}
          | WORK_STATION3{}
          | WORK_STATION4{}
          | WORK_STATION5{}
          |)
       | (| Zone_1 := ((when (when (NEXT_AGV16 or NEXT_AGV13))) when (NEXT_AGV23 or NEXT_AGV212)) default (when (NEXT_AGV16 and NEXT_AGV13)) default false
          | Zone_2 := ((when (when (NEXT_AGV25 or NEXT_AGV210))) when (NEXT_AGV33 or NEXT_AGV36)) default (when (NEXT_AGV33 and NEXT_AGV36)) default false
          | Zone_3 := ((when (when (NEXT_AGV26 or NEXT_AGV29))) when (NEXT_AGV43 or NEXT_AGV410)) default false
          | Zone_4 := ((when (when (NEXT_AGV45 or NEXT_AGV48))) when (NEXT_AGV53 or NEXT_AGV58)) default (when (NEXT_AGV53 and NEXT_AGV58)) default false
          | Zone_1 ^= Zone_2 ^= Zone_3 ^= Zone_4 ^= Tick ^= true
          | Conflit := Zone_1 or Zone_2 or Zone_3 or Zone_4
          | SIGALI(Controllable(C1))
          | SIGALI(Controllable(C2))
          | SIGALI(Controllable(C3))
          | SIGALI(Controllable(C4))
          | SIGALI(Controllable(C5))
          | SIGALI(Controllable(C6))
          | SIGALI(Controllable(C7))
          | SIGALI(Controllable(C8))
          | SIGALI(Controllable(C9))
          | SIGALI(Controllable(C10))
          | SIGALI(S_Security(B_False(Conflit)))
          | (| b := Simul()
             | SIGALI(b)
             | b ^= C10
             |)
          |)
       |)/ Zone_1, Zone_2, Zone_3, Zone_4, b |)
   where 
   use SIGALI; 
   boolean CURRENT_WST11 init true, CURRENT_WST12 init false, CURRENT_WST13 init true, CURRENT_WST14 init false;
   boolean CURRENT_WST21 init true, CURRENT_WST22 init false, CURRENT_WST23 init false, CURRENT_WST24 init false;
   boolean CURRENT_WST31 init true, CURRENT_WST32 init false, CURRENT_WST33 init false, CURRENT_WST34 init false;
   boolean CURRENT_WST41 init true, CURRENT_WST42 init false;
   boolean CURRENT_WST51 init true, CURRENT_WST52 init false, CURRENT_WST53 init true, CURRENT_WST54 init false, CURRENT_WST55 init false, CURRENT_WST56 init false;
   boolean CURRENT_AGV11 init true, CURRENT_AGV12 init false, CURRENT_AGV13 init false, CURRENT_AGV14 init false, CURRENT_AGV15 init false, CURRENT_AGV16 init false;
   boolean CURRENT_AGV21 init true, CURRENT_AGV22 init false, CURRENT_AGV23 init false, CURRENT_AGV24 init false, CURRENT_AGV25 init false, CURRENT_AGV26 init false, CURRENT_AGV27 init false, CURRENT_AGV28 init false, CURRENT_AGV29 init false, 
          CURRENT_AGV210 init false, CURRENT_AGV211 init false, CURRENT_AGV212 init false;
   boolean CURRENT_AGV31 init true, CURRENT_AGV32 init false, CURRENT_AGV33 init false, CURRENT_AGV34 init false, CURRENT_AGV35 init false, CURRENT_AGV36 init false;
   boolean CURRENT_AGV41 init true, CURRENT_AGV42 init false, CURRENT_AGV43 init false, CURRENT_AGV44 init false, CURRENT_AGV45 init false, CURRENT_AGV46 init false, CURRENT_AGV47 init false, CURRENT_AGV48 init false, CURRENT_AGV49 init false, 
          CURRENT_AGV410 init false;
   boolean CURRENT_AGV51 init true, CURRENT_AGV52 init false, CURRENT_AGV53 init false, CURRENT_AGV54 init false, CURRENT_AGV55 init false, CURRENT_AGV56 init false, CURRENT_AGV57 init false, CURRENT_AGV58 init false;
   process AGV2 =
        ( ? boolean C3;
            boolean C4;
            boolean CURRENT_WST31;
            boolean CURRENT_WST13;
            Tick;
          ! boolean CURRENT_AGV21 init true;
            boolean CURRENT_AGV22 init false;
            boolean CURRENT_AGV23 init false;
            boolean CURRENT_AGV24 init false;
            boolean CURRENT_AGV25 init false;
            boolean CURRENT_AGV26 init false;
            boolean CURRENT_AGV27 init false;
            boolean CURRENT_AGV28 init false;
            boolean CURRENT_AGV29 init false;
            boolean CURRENT_AGV210 init false;
            boolean CURRENT_AGV211 init false;
            boolean CURRENT_AGV212 init false;
            boolean NEXT_AGV21;
            boolean NEXT_AGV22;
            boolean NEXT_AGV23;
            boolean NEXT_AGV24;
            boolean NEXT_AGV25;
            boolean NEXT_AGV26;
            boolean NEXT_AGV27;
            boolean NEXT_AGV28;
            boolean NEXT_AGV29;
            boolean NEXT_AGV210;
            boolean NEXT_AGV211;
            boolean NEXT_AGV212;
        )
      (| (| INTER_NEXT_AGV21 := (when CURRENT_AGV212) default (false when CURRENT_AGV21 when CURRENT_WST13)
          | INTER_NEXT_AGV22 := ((when CURRENT_AGV21) when CURRENT_WST13) default (false when C3 when CURRENT_AGV22)
          | INTER_NEXT_AGV23 := ((when C3) when CURRENT_AGV22) default (false when CURRENT_AGV23)
          | INTER_NEXT_AGV24 := (when CURRENT_AGV23) default (false when CURRENT_AGV24)
          | INTER_NEXT_AGV25 := (when CURRENT_AGV24) default (false when CURRENT_AGV25)
          | INTER_NEXT_AGV26 := (when CURRENT_AGV25) default (false when CURRENT_AGV26)
          | INTER_NEXT_AGV27 := (when CURRENT_AGV26) default (false when CURRENT_AGV27 when CURRENT_WST31)
          | INTER_NEXT_AGV28 := ((when CURRENT_AGV27) when CURRENT_WST31) default (false when C4 when CURRENT_AGV28)
          | INTER_NEXT_AGV29 := ((when C4) when CURRENT_AGV28) default (false when CURRENT_AGV29)
          | INTER_NEXT_AGV210 := (when CURRENT_AGV29) default (false when CURRENT_AGV210)
          | INTER_NEXT_AGV211 := (when CURRENT_AGV210) default (false when CURRENT_AGV211)
          | INTER_NEXT_AGV212 := (when CURRENT_AGV211) default (false when CURRENT_AGV212)
          | NEXT_AGV21 := INTER_NEXT_AGV21 default CURRENT_AGV21
          | NEXT_AGV22 := INTER_NEXT_AGV22 default CURRENT_AGV22
          | NEXT_AGV23 := INTER_NEXT_AGV23 default CURRENT_AGV23
          | NEXT_AGV24 := INTER_NEXT_AGV24 default CURRENT_AGV24
          | NEXT_AGV25 := INTER_NEXT_AGV25 default CURRENT_AGV25
          | NEXT_AGV26 := INTER_NEXT_AGV26 default CURRENT_AGV26
          | NEXT_AGV27 := INTER_NEXT_AGV27 default CURRENT_AGV27
          | NEXT_AGV28 := INTER_NEXT_AGV28 default CURRENT_AGV28
          | NEXT_AGV29 := INTER_NEXT_AGV29 default CURRENT_AGV29
          | NEXT_AGV210 := INTER_NEXT_AGV210 default CURRENT_AGV210
          | NEXT_AGV211 := INTER_NEXT_AGV211 default CURRENT_AGV211
          | NEXT_AGV212 := INTER_NEXT_AGV212 default CURRENT_AGV212
          | CURRENT_AGV21 := NEXT_AGV21$1 init true
          | CURRENT_AGV22 := NEXT_AGV22$1 init false
          | CURRENT_AGV23 := NEXT_AGV23$1 init false
          | CURRENT_AGV24 := NEXT_AGV24$1 init false
          | CURRENT_AGV25 := NEXT_AGV25$1 init false
          | CURRENT_AGV26 := NEXT_AGV26$1 init false
          | CURRENT_AGV27 := NEXT_AGV27$1 init false
          | CURRENT_AGV28 := NEXT_AGV28$1 init false
          | CURRENT_AGV29 := NEXT_AGV29$1 init false
          | CURRENT_AGV210 := NEXT_AGV210$1 init false
          | CURRENT_AGV211 := NEXT_AGV211$1 init false
          | CURRENT_AGV212 := NEXT_AGV212$1 init false
          | NEXT_AGV21 ^= NEXT_AGV22 ^= NEXT_AGV23 ^= NEXT_AGV24 ^= NEXT_AGV25 ^= NEXT_AGV26 ^= NEXT_AGV27 ^= NEXT_AGV28 ^= NEXT_AGV29 ^= NEXT_AGV210 ^= NEXT_AGV211 ^= NEXT_AGV212 ^= Tick
          |)/ INTER_NEXT_AGV21, INTER_NEXT_AGV22, INTER_NEXT_AGV23, INTER_NEXT_AGV24, INTER_NEXT_AGV25, INTER_NEXT_AGV26, INTER_NEXT_AGV27, INTER_NEXT_AGV28, INTER_NEXT_AGV29, INTER_NEXT_AGV210, INTER_NEXT_AGV211, INTER_NEXT_AGV212 |)
   ; 
   process AGV4 =
        ( ? boolean C7;
            boolean C8;
            boolean CURRENT_WST34;
            boolean CURRENT_WST53;
            Tick;
          ! boolean CURRENT_AGV41 init true;
            boolean CURRENT_AGV42 init false;
            boolean CURRENT_AGV43 init false;
            boolean CURRENT_AGV44 init false;
            boolean CURRENT_AGV45 init false;
            boolean CURRENT_AGV46 init false;
            boolean CURRENT_AGV47 init false;
            boolean CURRENT_AGV48 init false;
            boolean CURRENT_AGV49 init false;
            boolean CURRENT_AGV410 init false;
            boolean NEXT_AGV41;
            boolean NEXT_AGV42;
            boolean NEXT_AGV43;
            boolean NEXT_AGV44;
            boolean NEXT_AGV45;
            boolean NEXT_AGV46;
            boolean NEXT_AGV47;
            boolean NEXT_AGV48;
            boolean NEXT_AGV49;
            boolean NEXT_AGV410;
        )
      (| (| INTER_NEXT_AGV41 := (when CURRENT_AGV410) default (false when CURRENT_AGV41 when CURRENT_WST53)
          | INTER_NEXT_AGV42 := ((when CURRENT_AGV41) when CURRENT_WST53) default (false when C7 when CURRENT_AGV42)
          | INTER_NEXT_AGV43 := ((when C7) when CURRENT_AGV42) default (false when CURRENT_AGV43)
          | INTER_NEXT_AGV44 := (when CURRENT_AGV43) default (false when CURRENT_AGV44)
          | INTER_NEXT_AGV45 := (when CURRENT_AGV44) default (false when CURRENT_AGV45)
          | INTER_NEXT_AGV46 := (when CURRENT_AGV45) default (false when CURRENT_AGV46 when CURRENT_WST34)
          | INTER_NEXT_AGV47 := ((when CURRENT_AGV46) when CURRENT_WST34) default (false when C8 when CURRENT_AGV47)
          | INTER_NEXT_AGV48 := ((when C8) when CURRENT_AGV47) default (false when CURRENT_AGV48)
          | INTER_NEXT_AGV49 := (when CURRENT_AGV48) default (false when CURRENT_AGV49)
          | INTER_NEXT_AGV410 := (when CURRENT_AGV49) default (false when CURRENT_AGV410)
          | NEXT_AGV41 := INTER_NEXT_AGV41 default CURRENT_AGV41
          | NEXT_AGV42 := INTER_NEXT_AGV42 default CURRENT_AGV42
          | NEXT_AGV43 := INTER_NEXT_AGV43 default CURRENT_AGV43
          | NEXT_AGV44 := INTER_NEXT_AGV44 default CURRENT_AGV44
          | NEXT_AGV45 := INTER_NEXT_AGV45 default CURRENT_AGV45
          | NEXT_AGV46 := INTER_NEXT_AGV46 default CURRENT_AGV46
          | NEXT_AGV47 := INTER_NEXT_AGV47 default CURRENT_AGV47
          | NEXT_AGV48 := INTER_NEXT_AGV48 default CURRENT_AGV48
          | NEXT_AGV49 := INTER_NEXT_AGV49 default CURRENT_AGV49
          | NEXT_AGV410 := INTER_NEXT_AGV410 default CURRENT_AGV410
          | CURRENT_AGV41 := NEXT_AGV41$1 init true
          | CURRENT_AGV42 := NEXT_AGV42$1 init false
          | CURRENT_AGV43 := NEXT_AGV43$1 init false
          | CURRENT_AGV44 := NEXT_AGV44$1 init false
          | CURRENT_AGV45 := NEXT_AGV45$1 init false
          | CURRENT_AGV46 := NEXT_AGV46$1 init false
          | CURRENT_AGV47 := NEXT_AGV47$1 init false
          | CURRENT_AGV48 := NEXT_AGV48$1 init false
          | CURRENT_AGV49 := NEXT_AGV49$1 init false
          | CURRENT_AGV410 := NEXT_AGV410$1 init false
          | NEXT_AGV41 ^= NEXT_AGV42 ^= NEXT_AGV43 ^= NEXT_AGV44 ^= NEXT_AGV45 ^= NEXT_AGV46 ^= NEXT_AGV47 ^= NEXT_AGV48 ^= NEXT_AGV49 ^= NEXT_AGV410 ^= Tick
          |)/ INTER_NEXT_AGV41, INTER_NEXT_AGV42, INTER_NEXT_AGV43, INTER_NEXT_AGV44, INTER_NEXT_AGV45, INTER_NEXT_AGV46, INTER_NEXT_AGV47, INTER_NEXT_AGV48, INTER_NEXT_AGV49, INTER_NEXT_AGV410 |)
   ; 
   process AGV5 =
        ( ? boolean C9;
            boolean C10;
            boolean CURRENT_WST42;
            boolean CURRENT_WST56;
            Tick;
          ! boolean CURRENT_AGV51 init true;
            boolean CURRENT_AGV52 init false;
            boolean CURRENT_AGV53 init false;
            boolean CURRENT_AGV54 init false;
            boolean CURRENT_AGV55 init false;
            boolean CURRENT_AGV56 init true;
            boolean CURRENT_AGV57 init false;
            boolean CURRENT_AGV58 init false;
            boolean NEXT_AGV51;
            boolean NEXT_AGV52;
            boolean NEXT_AGV53;
            boolean NEXT_AGV54;
            boolean NEXT_AGV55;
            boolean NEXT_AGV56;
            boolean NEXT_AGV57;
            boolean NEXT_AGV58;
        )
      (| (| INTER_NEXT_AGV51 := (when CURRENT_AGV58) default (false when CURRENT_AGV51 when CURRENT_WST56)
          | INTER_NEXT_AGV52 := ((when CURRENT_AGV51) when CURRENT_WST56) default (false when C9 when CURRENT_AGV52)
          | INTER_NEXT_AGV53 := ((when C9) when CURRENT_AGV52) default (false when CURRENT_AGV53)
          | INTER_NEXT_AGV54 := (when CURRENT_AGV53) default (false when CURRENT_AGV54)
          | INTER_NEXT_AGV55 := (when CURRENT_AGV54) default (false when CURRENT_AGV55 when CURRENT_WST42)
          | INTER_NEXT_AGV56 := ((when CURRENT_AGV55) when CURRENT_WST42) default (false when CURRENT_AGV56)
          | INTER_NEXT_AGV57 := (when CURRENT_AGV56) default (false when C10 when CURRENT_AGV57)
          | INTER_NEXT_AGV58 := ((when C10) when CURRENT_AGV57) default (false when CURRENT_AGV58)
          | NEXT_AGV51 := INTER_NEXT_AGV51 default CURRENT_AGV51
          | NEXT_AGV52 := INTER_NEXT_AGV52 default CURRENT_AGV52
          | NEXT_AGV53 := INTER_NEXT_AGV53 default CURRENT_AGV53
          | NEXT_AGV54 := INTER_NEXT_AGV54 default CURRENT_AGV54
          | NEXT_AGV55 := INTER_NEXT_AGV55 default CURRENT_AGV55
          | NEXT_AGV56 := INTER_NEXT_AGV56 default CURRENT_AGV56
          | NEXT_AGV57 := INTER_NEXT_AGV57 default CURRENT_AGV57
          | NEXT_AGV58 := INTER_NEXT_AGV58 default CURRENT_AGV58
          | CURRENT_AGV51 := NEXT_AGV51$1 init true
          | CURRENT_AGV52 := NEXT_AGV52$1 init false
          | CURRENT_AGV53 := NEXT_AGV53$1 init false
          | CURRENT_AGV54 := NEXT_AGV54$1 init false
          | CURRENT_AGV55 := NEXT_AGV55$1 init false
          | CURRENT_AGV56 := NEXT_AGV56$1 init false
          | CURRENT_AGV57 := NEXT_AGV57$1 init false
          | CURRENT_AGV58 := NEXT_AGV58$1 init false
          | NEXT_AGV51 ^= NEXT_AGV52 ^= NEXT_AGV53 ^= NEXT_AGV54 ^= NEXT_AGV55 ^= NEXT_AGV56 ^= NEXT_AGV57 ^= NEXT_AGV58 ^= Tick
          |)/ INTER_NEXT_AGV51, INTER_NEXT_AGV52, INTER_NEXT_AGV53, INTER_NEXT_AGV54, INTER_NEXT_AGV55, INTER_NEXT_AGV56, INTER_NEXT_AGV57, INTER_NEXT_AGV58 |)
   ; 
   process WORK_STATION5 =
        ( ? boolean CURRENT_AGV31;
            boolean CURRENT_AGV32;
            boolean CURRENT_AGV41;
            boolean CURRENT_AGV42;
            boolean CURRENT_AGV51;
            boolean CURRENT_AGV52;
            Tick;
          ! boolean CURRENT_WST51 init true;
            boolean CURRENT_WST52 init false;
            boolean CURRENT_WST53 init true;
            boolean CURRENT_WST54 init false;
            boolean CURRENT_WST55 init false;
            boolean CURRENT_WST56 init false;
            boolean NEXT_WST51;
            boolean NEXT_WST52;
            boolean NEXT_WST53;
            boolean NEXT_WST54;
            boolean NEXT_WST55;
            boolean NEXT_WST56;
        )
      (| (| INTER_NEXT_WST51 := ((when CURRENT_WST56) when CURRENT_AGV51) default (false when CURRENT_WST51 when CURRENT_AGV31)
          | INTER_NEXT_WST52 := ((when CURRENT_WST51) when CURRENT_AGV31) default (false when CURRENT_WST52 when CURRENT_WST54)
          | INTER_NEXT_WST53 := ((when CURRENT_WST56) when CURRENT_AGV51) default (false when CURRENT_WST53 when CURRENT_AGV41)
          | INTER_NEXT_WST54 := ((when CURRENT_WST53) when CURRENT_AGV41) default (false when CURRENT_WST54 when CURRENT_WST52)
          | INTER_NEXT_WST55 := ((when CURRENT_WST54) when CURRENT_WST52) default (false when CURRENT_WST55)
          | INTER_NEXT_WST56 := (when CURRENT_WST55) default (false when CURRENT_WST56 when CURRENT_AGV51)
          | NEXT_WST51 := INTER_NEXT_WST51 default CURRENT_WST51
          | NEXT_WST52 := INTER_NEXT_WST52 default CURRENT_WST52
          | NEXT_WST53 := INTER_NEXT_WST53 default CURRENT_WST53
          | NEXT_WST54 := INTER_NEXT_WST54 default CURRENT_WST54
          | NEXT_WST55 := INTER_NEXT_WST55 default CURRENT_WST55
          | NEXT_WST56 := INTER_NEXT_WST56 default CURRENT_WST56
          | CURRENT_WST51 := NEXT_WST51$1 init true
          | CURRENT_WST52 := NEXT_WST52$1 init false
          | CURRENT_WST53 := NEXT_WST53$1 init false
          | CURRENT_WST54 := NEXT_WST54$1 init false
          | CURRENT_WST55 := NEXT_WST55$1 init false
          | CURRENT_WST56 := NEXT_WST56$1 init false
          | NEXT_WST51 ^= NEXT_WST52 ^= NEXT_WST53 ^= NEXT_WST54 ^= NEXT_WST55 ^= NEXT_WST56 ^= Tick
          |)/ INTER_NEXT_WST51, INTER_NEXT_WST52, INTER_NEXT_WST53, INTER_NEXT_WST54, INTER_NEXT_WST55, INTER_NEXT_WST56 |)
   ; 
   process WORK_STATION1 =
        ( ? event Tick;
            boolean CURRENT_AGV11;
            boolean CURRENT_AGV12;
            boolean CURRENT_AGV21;
            boolean CURRENT_AGV22;
          ! boolean CURRENT_WST11 init true;
            boolean CURRENT_WST12 init false;
            boolean CURRENT_WST13 init true;
            boolean CURRENT_WST14 init false;
            boolean NEXT_WST11;
            boolean NEXT_WST12;
            boolean NEXT_WST13;
            boolean NEXT_WST14;
        )
      (| (| (| INTER_NEXT_WST11 := (when CURRENT_WST12) default (false when CURRENT_WST11 when CURRENT_AGV11)
             | NEXT_WST11 := INTER_NEXT_WST11 default CURRENT_WST11
             | INTER_NEXT_WST12 := ((when CURRENT_WST11) when CURRENT_AGV11) default (false when CURRENT_WST12)
             | NEXT_WST12 := INTER_NEXT_WST12 default CURRENT_WST12
             |)
          | (| INTER_NEXT_WST13 := (when CURRENT_WST14) default (false when CURRENT_WST13 when CURRENT_AGV21)
             | NEXT_WST13 := INTER_NEXT_WST13 default CURRENT_WST13
             | INTER_NEXT_WST14 := ((when CURRENT_WST13) when CURRENT_AGV21) default (false when CURRENT_WST14)
             | NEXT_WST14 := INTER_NEXT_WST14 default CURRENT_WST14
             |)
          | CURRENT_WST11 := NEXT_WST11$1 init true
          | CURRENT_WST12 := NEXT_WST12$1 init false
          | CURRENT_WST13 := NEXT_WST13$1 init false
          | CURRENT_WST14 := NEXT_WST14$1 init false
          | CURRENT_WST11 ^= CURRENT_WST12 ^= CURRENT_WST13 ^= CURRENT_WST14 ^= Tick
          |)/ INTER_NEXT_WST11, INTER_NEXT_WST12, INTER_NEXT_WST13, INTER_NEXT_WST14 |)
   ; 
   process WORK_STATION2 =
        ( ? boolean CURRENT_AGV14;
            boolean CURRENT_AGV15;
            boolean CURRENT_AGV34;
            boolean CURRENT_AGV35;
            event Tick;
          ! boolean CURRENT_WST21 init true;
            boolean CURRENT_WST22 init false;
            boolean CURRENT_WST23 init false;
            boolean CURRENT_WST24 init false;
            boolean NEXT_WST21;
            boolean NEXT_WST22;
            boolean NEXT_WST23;
            boolean NEXT_WST24;
        )
      (| (| INTER_NEXT_WST21 := ((when CURRENT_AGV34) when CURRENT_WST24) default (false when CURRENT_WST21 when CURRENT_AGV14)
          | NEXT_WST21 := INTER_NEXT_WST21 default CURRENT_WST21
          | INTER_NEXT_WST22 := ((when CURRENT_WST21) when CURRENT_AGV14) default (false when CURRENT_WST22)
          | NEXT_WST22 := INTER_NEXT_WST22 default CURRENT_WST22
          | INTER_NEXT_WST23 := (when CURRENT_WST22) default (false when CURRENT_WST23)
          | NEXT_WST23 := INTER_NEXT_WST23 default CURRENT_WST23
          | INTER_NEXT_WST24 := (when CURRENT_WST23) default (false when CURRENT_AGV34 when CURRENT_WST24)
          | NEXT_WST24 := INTER_NEXT_WST24 default CURRENT_WST24
          | CURRENT_WST21 := NEXT_WST21$1 init true
          | CURRENT_WST22 := NEXT_WST22$1 init false
          | CURRENT_WST23 := NEXT_WST23$1 init false
          | CURRENT_WST24 := NEXT_WST24$1 init false
          | NEXT_WST21 ^= NEXT_WST22 ^= NEXT_WST23 ^= NEXT_WST24 ^= Tick
          |)/ INTER_NEXT_WST21, INTER_NEXT_WST22, INTER_NEXT_WST23, INTER_NEXT_WST24 |)
   ; 
   process WORK_STATION3 =
        ( ? Tick;
            boolean CURRENT_AGV27;
            boolean CURRENT_AGV46;
            boolean CURRENT_AGV28;
            boolean CURRENT_AGV47;
          ! boolean CURRENT_WST31 init true;
            boolean CURRENT_WST32 init false;
            boolean CURRENT_WST33 init false;
            boolean CURRENT_WST34 init false;
            boolean NEXT_WST31, NEXT_WST32, NEXT_WST33, NEXT_WST34;
        )
      (| (| INTER_NEXT_WST31 := ((when CURRENT_WST34) when CURRENT_AGV46) default (false when CURRENT_WST31 when CURRENT_AGV27)
          | INTER_NEXT_WST32 := ((when CURRENT_WST31) when CURRENT_AGV27) default (false when CURRENT_WST32)
          | INTER_NEXT_WST33 := (when CURRENT_WST32) default (false when CURRENT_WST33)
          | INTER_NEXT_WST34 := (when CURRENT_WST33) default (false when CURRENT_WST34 when CURRENT_AGV46)
          | NEXT_WST31 := INTER_NEXT_WST31 default CURRENT_WST31
          | NEXT_WST32 := INTER_NEXT_WST32 default CURRENT_WST32
          | NEXT_WST33 := INTER_NEXT_WST33 default CURRENT_WST33
          | NEXT_WST34 := INTER_NEXT_WST34 default CURRENT_WST34
          | CURRENT_WST31 := NEXT_WST31$1 init true
          | CURRENT_WST32 := NEXT_WST32$1 init false
          | CURRENT_WST33 := NEXT_WST33$1 init false
          | CURRENT_WST34 := NEXT_WST34$1 init false
          | NEXT_WST31 ^= NEXT_WST32 ^= NEXT_WST33 ^= NEXT_WST34 ^= Tick
          |)/ INTER_NEXT_WST31, INTER_NEXT_WST32, INTER_NEXT_WST33, INTER_NEXT_WST34 |)
   ; 
   process WORK_STATION4 =
        ( ? event Tick;
            boolean CURRENT_AGV55;
            CURRENT_AGV56;
          ! boolean CURRENT_WST41 init true;
            boolean CURRENT_WST42 init false;
            boolean NEXT_WST41;
            boolean NEXT_WST42;
        )
      (| (| INTER_NEXT_WST41 := ((when CURRENT_WST42) when CURRENT_AGV55) default (false when CURRENT_WST41)
          | INTER_NEXT_WST42 := (when CURRENT_WST41) default (false when CURRENT_WST42 when CURRENT_AGV55)
          | NEXT_WST41 := INTER_NEXT_WST41 default CURRENT_WST41
          | NEXT_WST42 := INTER_NEXT_WST42 default CURRENT_WST42
          | CURRENT_WST41 := NEXT_WST41$1 init true
          | CURRENT_WST42 := NEXT_WST42$1 init false
          | NEXT_WST41 ^= NEXT_WST42 ^= Tick
          |)/ INTER_NEXT_WST41, INTER_NEXT_WST42 |)
   ; 
   process AGV1 =
        ( ? boolean C1;
            boolean C2;
            boolean CURRENT_WST11;
            boolean CURRENT_WST21;
            event Tick;
          ! boolean CURRENT_AGV11 init true;
            boolean CURRENT_AGV12 init false;
            boolean CURRENT_AGV13 init false;
            boolean CURRENT_AGV14 init true;
            boolean CURRENT_AGV15 init false;
            boolean CURRENT_AGV16 init false;
            boolean NEXT_AGV11;
            boolean NEXT_AGV12;
            boolean NEXT_AGV13;
            boolean NEXT_AGV14;
            boolean NEXT_AGV15;
            boolean NEXT_AGV16;
        )
      (| (| INTER_NEXT_AGV11 := (when CURRENT_AGV16) default (false when CURRENT_AGV11 when CURRENT_WST11)
          | NEXT_AGV11 := INTER_NEXT_AGV11 default CURRENT_AGV11
          | INTER_NEXT_AGV12 := (when (CURRENT_AGV11 when CURRENT_WST11)) default (false when (C1 when CURRENT_AGV12))
          | NEXT_AGV12 := INTER_NEXT_AGV12 default CURRENT_AGV12
          | INTER_NEXT_AGV13 := (when (C1 when CURRENT_AGV12)) default (false when CURRENT_AGV13)
          | NEXT_AGV13 := INTER_NEXT_AGV13 default CURRENT_AGV13
          | INTER_NEXT_AGV14 := (when CURRENT_AGV13) default (false when (CURRENT_AGV14 when CURRENT_WST21))
          | NEXT_AGV14 := INTER_NEXT_AGV14 default CURRENT_AGV14
          | INTER_NEXT_AGV15 := (when (CURRENT_AGV14 when CURRENT_WST21)) default (false when (C2 when CURRENT_AGV15))
          | NEXT_AGV15 := INTER_NEXT_AGV15 default CURRENT_AGV15
          | INTER_NEXT_AGV16 := (when (C2 when CURRENT_AGV15)) default (false when CURRENT_AGV16)
          | NEXT_AGV16 := INTER_NEXT_AGV16 default CURRENT_AGV16
          | CURRENT_AGV11 := NEXT_AGV11$1 init true
          | CURRENT_AGV12 := NEXT_AGV12$1 init false
          | CURRENT_AGV13 := NEXT_AGV13$1 init false
          | CURRENT_AGV14 := NEXT_AGV14$1 init false
          | CURRENT_AGV15 := NEXT_AGV15$1 init false
          | CURRENT_AGV16 := NEXT_AGV16$1 init false
          | NEXT_AGV11 ^= NEXT_AGV12 ^= NEXT_AGV13 ^= NEXT_AGV14 ^= NEXT_AGV15 ^= NEXT_AGV16 ^= Tick
          |)/ INTER_NEXT_AGV11, INTER_NEXT_AGV12, INTER_NEXT_AGV13, INTER_NEXT_AGV14, INTER_NEXT_AGV15, INTER_NEXT_AGV16 |)
   ; 
   process AGV3 =
        ( ? boolean C5;
            boolean C6;
            boolean CURRENT_WST24;
            boolean CURRENT_WST51;
            Tick;
          ! boolean CURRENT_AGV31 init true;
            boolean CURRENT_AGV32 init false;
            boolean CURRENT_AGV33 init false;
            boolean CURRENT_AGV34 init true;
            boolean CURRENT_AGV35 init false;
            boolean CURRENT_AGV36 init false;
            boolean NEXT_AGV31;
            boolean NEXT_AGV32;
            boolean NEXT_AGV33;
            boolean NEXT_AGV34;
            boolean NEXT_AGV35;
            boolean NEXT_AGV36;
        )
      (| (| INTER_NEXT_AGV31 := (when CURRENT_AGV36) default (false when CURRENT_AGV31 when CURRENT_WST51)
          | INTER_NEXT_AGV32 := ((when CURRENT_AGV31) when CURRENT_WST51) default (false when C5 when CURRENT_AGV32)
          | INTER_NEXT_AGV33 := ((when C5) when CURRENT_AGV32) default (false when CURRENT_AGV33)
          | INTER_NEXT_AGV34 := (when CURRENT_AGV33) default (false when CURRENT_AGV34 when CURRENT_WST24)
          | INTER_NEXT_AGV35 := ((when CURRENT_AGV34) when CURRENT_WST24) default (false when C6 when CURRENT_AGV35)
          | INTER_NEXT_AGV36 := ((when C6) when CURRENT_AGV35) default (false when CURRENT_AGV36)
          | NEXT_AGV31 := INTER_NEXT_AGV31 default CURRENT_AGV31
          | NEXT_AGV32 := INTER_NEXT_AGV32 default CURRENT_AGV32
          | NEXT_AGV33 := INTER_NEXT_AGV33 default CURRENT_AGV33
          | NEXT_AGV34 := INTER_NEXT_AGV34 default CURRENT_AGV34
          | NEXT_AGV35 := INTER_NEXT_AGV35 default CURRENT_AGV35
          | NEXT_AGV36 := INTER_NEXT_AGV36 default CURRENT_AGV36
          | CURRENT_AGV31 := NEXT_AGV31$1 init true
          | CURRENT_AGV32 := NEXT_AGV32$1 init false
          | CURRENT_AGV33 := NEXT_AGV33$1 init false
          | CURRENT_AGV34 := NEXT_AGV34$1 init false
          | CURRENT_AGV35 := NEXT_AGV35$1 init false
          | CURRENT_AGV36 := NEXT_AGV36$1 init false
          | NEXT_AGV31 ^= NEXT_AGV32 ^= NEXT_AGV33 ^= NEXT_AGV34 ^= NEXT_AGV35 ^= NEXT_AGV36 ^= Tick
          |)/ INTER_NEXT_AGV31, INTER_NEXT_AGV32, INTER_NEXT_AGV33, INTER_NEXT_AGV34, INTER_NEXT_AGV35, INTER_NEXT_AGV36 |)
   ; 
   end
; 

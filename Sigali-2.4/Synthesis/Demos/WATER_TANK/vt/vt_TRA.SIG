process vt_TRA =
     ( ? event HE;
     )
   pragmas 
      main
   end pragmas
   (| (| HE ^= HE
       | ACT_HE{}
       |) |)
   where 
   constant integer N = 2;
   constant integer NUL_CODE = 0;
   constant integer LIN_CODE = 2;
   constant integer PHY_0 = 0;
   constant integer PI_0_67 = 1;
   constant integer V_0 = 1;
   constant integer ncond = 1;
   constant integer nx = 6;
   constant integer nu = 4;
   constant integer ny = 3;
   process ACT_HE =
        ( )
      (| HE ^= ADR_COUNT ^= CODE_CHANGE ^= AUTOMOD ^= C_SW_AUTO ^= C_TICK ^= CINIT
       | (| CLK_C_UP_DOWN := when (CODE_CHANGE/=0)
          | ACT_CLK_C_UP_DOWN{}
          | CLK_171 := when (not (CODE_CHANGE/=0))
          |)
       | (| CLK_193 := when C_SW_AUTO
          | CLK_194 := when (not C_SW_AUTO)
          |)
       | (| CLK_MAX := when AUTOMOD
          | ACT_CLK_MAX{}
          | CLK_C_STOP := when (not AUTOMOD)
          | ACT_CLK_C_STOP{}
          |)
       | (| CLK_222 := when C_TICK
          | CLK_223 := when (not C_TICK)
          |)
       | (| CLK_PI_0 := when CINIT
          | CLK_PI_0 ^= PI_0 ^= DESCR
          | (DESCR,PI_0) := GET_PACE_RHYTHM()
          | CLK_240 := when (not CINIT)
          |)
       | (| CLK_904 := CLK_MAX ^+ CLK_C_UP_DOWN |)
       | (| CLK_906 := CLK_MAX ^+ CLK_215 |)
       | (| CLK_908 := CLK_222 ^+ CLK_904 |)
       | (| CLK_z_b := CLK_222 ^+ CLK_42
          | ACT_CLK_z_b{}
          |)
       | (| CLK_912 := CLK_PI_0 ^+ CLK_z_b |)
       | (| CLK_ZAUTO := CLK_193 ^+ CLK_PI_0
          | CLK_ZAUTO ^= NEXTAUTO
          | ACT_CLK_ZAUTO{}
          |)
       | (| CLK_916 := CLK_PI_0 ^+ CLK_NEW_BOUND_2 |)
       | (| CLK_NEW_BOUND := CLK_C_UP_DOWN ^+ CLK_PI_0
          | CLK_NEW_BOUND ^= NEW_BOUND ^= OLD_BOUND
          | ACT_CLK_NEW_BOUND{}
          |)
       | (| CLK_MAX1 := CLK_NEW_BOUND ^+ CLK_MAX
          | CLK_MAX1 ^= MAX1
          | MAX1 := ((0 when CLK) default ((NEW_BOUND-1) when CLK_22)) cell CLK_MAX1 init 0
          |)
       | (| CLK_924 := CLK_NEW_BOUND ^+ CLK_42 |)
       | (| CLK_932 := CLK_916 ^+ CLK_NEW_BOUND_1 |)
       | (| CLK_934 := CLK_ZAUTO ^+ CLK_906 |)
       | (| CLK_936 := CLK_934 ^+ CLK_222 |)
       | (| CLK_1167 := CLK_MAX ^* CLK |)
       | (| CLK_1266 := CLK_NEW_BOUND ^- CLK_932 |)
       | (| CLK_1268 := CLK_PI_0 ^- CLK_C_UP_DOWN |)
       | (| CLK_1271 := CLK_222 ^- CLK_42 |)
       | (| CLK_1274 := CLK_193 ^- CLK_PI_0 |)
       | (| CLK_1276 := CLK_NEW_BOUND_2 ^- CLK_PI_0 |)
       | (| CLK_1278 := CLK_NEW_BOUND_1 ^- CLK_916 |)
       | (| ADR_COUNT := (DESCR when CLK_PI_0) cell HE init 0
          | CODE_CHANGE := RCHANGE(ADR_COUNT)
          | AUTOMOD := (NEXTAUTO when CLK_ZAUTO) cell HE init true
          | C_SW_AUTO := RAUTO()
          | C_TICK := RTICK()
          | CINIT := (false when HE)$1 init true
          |)
       |)
      where 
      event CLK_1278, CLK_1276, CLK_1274, CLK_1271, CLK_1268, CLK_1266, CLK_1167, CLK_936, CLK_934, CLK_932, CLK_924, CLK_MAX1, CLK_NEW_BOUND, CLK_916, CLK_ZAUTO, CLK_912, CLK_z_b, CLK_908, CLK_906, CLK_904, CLK_NEW_BOUND_2, CLK_NEW_BOUND_1, CLK_240, 
           CLK_PI_0, CLK_223, CLK_222, CLK_215, CLK_C_STOP, CLK_MAX, CLK_194, CLK_193, CLK_171, CLK_C_UP_DOWN, CLK_42, CLK_22, CLK;
      integer PI_0, NEW_BOUND, ADR_COUNT, MAX1, OLD_BOUND, NEW_BOUND_1, NEW_BOUND_2, CODE_CHANGE;
      boolean AUTOMOD, C_SW_AUTO, NEXTAUTO, C_TICK;
      integer DESCR;
      boolean CINIT;
      process ACT_CLK_C_UP_DOWN =
           ( )
         (| CLK_C_UP_DOWN ^= C_UP_DOWN ^= C_LIN_EXP ^= XZX_245
          | (| CLK_XZX_159 := when C_LIN_EXP
             | ACT_CLK_XZX_159{}
             | CLK_XZX_134 := when (not C_LIN_EXP)
             | ACT_CLK_XZX_134{}
             |)
          | (| CLK_902 := CLK_XZX_159 ^+ CLK_891 |)
          | (| C_LIN_EXP := (CODE_CHANGE=2) when CLK_C_UP_DOWN
             | XZX_245 := ADR_COUNT when CLK_C_UP_DOWN
             | C_UP_DOWN := RUPDOWN(XZX_245)
             |)
          |)
         where 
         event CLK_902, CLK_891, CLK_XZX_134, CLK_XZX_159;
         boolean C_UP_DOWN, C_LIN_EXP;
         integer XZX_245;
         process ACT_CLK_XZX_159 =
              ( )
            (| CLK_XZX_159 ^= XZX_159 ^= XZX_162 ^= DELTA
             | (| CLK_109 := when (XZX_159>=16)
                | CLK_110 := when (not (XZX_159>=16))
                |)
             | (| CLK_118 := when XZX_162
                | CLK_VD_168 := when (not XZX_162)
                | CLK_VD_168 ^= VD_168
                | ACT_CLK_VD_168{}
                |)
             | (| CLK_124 := when (XZX_159>1)
                | CLK_125 := when (not (XZX_159>1))
                |)
             | (| CLK_VU_169 := CLK_118 ^* CLK_124
                | CLK_VU_169 ^= VU_169
                | VU_169 := (XZX_159-DELTA) when CLK_VU_169
                |)
             | (| CLK_898 := CLK_VU_169 ^+ CLK_VD_168 |)
             | (| CLK_NEW_BOUND_2 := CLK_VU_169 ^+ CLK_129
                | CLK_NEW_BOUND_2 ^= NEW_BOUND_2
                | NEW_BOUND_2 := (VU_169 when CLK_VU_169) default (VD_168 when CLK_129)
                |)
             | (| XZX_159 := OLD_BOUND when CLK_XZX_159
                | XZX_162 := C_UP_DOWN when CLK_XZX_159
                | DELTA := ((XZX_159/16) when CLK_109) default (1 when CLK_110)
                |)
             |)
            where 
            event CLK_898, CLK_VU_169, CLK_129, CLK_125, CLK_124, CLK_VD_168, CLK_118, CLK_110, CLK_109;
            integer XZX_159;
            boolean XZX_162;
            integer DELTA, VD_168, VU_169;
            process ACT_CLK_VD_168 =
                 ( )
               (| (| CLK_129 := when (VD_168>0)
                   | CLK_130 := when (not (VD_168>0))
                   |)
                | (| VD_168 := (XZX_159+DELTA) when CLK_VD_168 |)
                |)
               where 
               event CLK_130;
               end
            %ACT_CLK_VD_168%; 
            end
         %ACT_CLK_XZX_159%; 
         process ACT_CLK_XZX_134 =
              ( )
            (| CLK_XZX_134 ^= XZX_134 ^= XZX_138
             | (| CLK_80 := when XZX_138
                | CLK_VD := when (not XZX_138)
                | CLK_VD ^= VD
                | ACT_CLK_VD{}
                |)
             | (| CLK_86 := when (XZX_134>1)
                | CLK_87 := when (not (XZX_134>1))
                |)
             | (| CLK_VU := CLK_80 ^* CLK_86
                | CLK_VU ^= VU
                | VU := (XZX_134/2) when CLK_VU
                |)
             | (| CLK_891 := CLK_VU ^+ CLK_VD |)
             | (| CLK_NEW_BOUND_1 := CLK_VU ^+ CLK_91
                | CLK_NEW_BOUND_1 ^= NEW_BOUND_1
                | NEW_BOUND_1 := (VU when CLK_VU) default (VD when CLK_91)
                |)
             | (| XZX_134 := OLD_BOUND when CLK_XZX_134
                | XZX_138 := C_UP_DOWN when CLK_XZX_134
                |)
             |)
            where 
            event CLK_VU, CLK_91, CLK_87, CLK_86, CLK_VD, CLK_80;
            integer XZX_134;
            boolean XZX_138;
            integer VD, VU;
            process ACT_CLK_VD =
                 ( )
               (| (| CLK_91 := when (VD>0)
                   | CLK_92 := when (not (VD>0))
                   |)
                | (| VD := (XZX_134+XZX_134) when CLK_VD |)
                |)
               where 
               event CLK_92;
               end
            %ACT_CLK_VD%; 
            end
         %ACT_CLK_XZX_134%; 
         end
      %ACT_CLK_C_UP_DOWN%; 
      process ACT_CLK_MAX =
           ( )
         (| CLK_MAX ^= MAX ^= ZV ^= V
          | (| CLK_36 := when (ZV>=MAX)
             | CLK_37 := when (not (ZV>=MAX))
             |)
          | (| CLK_42 := when (V=0)
             | CLK_43 := when (not (V=0))
             |)
          | (| MAX := MAX1 when CLK_MAX
             | ZV := V$1 init V_0
             | V := (0 when CLK_36) default ((ZV+1) when CLK_37)
             |)
          |)
         where 
         event CLK_43, CLK_37, CLK_36;
         integer MAX, ZV, V;
         end
      %ACT_CLK_MAX%; 
      process ACT_CLK_C_STOP =
           ( )
         (| CLK_C_STOP ^= C_STOP
          | (| CLK_215 := when C_STOP
             | WSTOP(CLK_215)
             | CLK_216 := when (not C_STOP)
             |)
          | (| C_STOP := RSTOP() |)
          |)
         where 
         event CLK_216;
         boolean C_STOP;
         end
      %ACT_CLK_C_STOP%; 
      process ACT_CLK_z_b =
           ( )
         (| CLK_z_b ^= z_b ^= b ^= S_cod_x ^= S_cod_u ^= Z_S_cod_u ^= S_cod_y ^= Z_S_cod_y ^= S_cod_cond ^= fin_resolver
          | (| CLK_761 := when fin_resolver
             | CLK_762 := when (not fin_resolver)
             |)
          | (| CLK_Task_1 := when z_b
             | CLK_Task_1 ^= cod_cond ^= cod_x
             | ACT_CLK_Task_1{}
             | CLK_769 := when (not z_b)
             |)
          | (| z_b := b$1 init true
             | b := CLK_761 default (not CLK_762)
             | S_cod_x := (cod_x when CLK_Task_1) cell CLK_z_b init [[0]:0]
             | Z_S_cod_u := S_cod_u$1 init [{i to 4 step 1}:0]
             | Z_S_cod_y := S_cod_y$1 init [{i_965 to 3 step 1}:0]
             | S_cod_cond := (cod_cond when CLK_Task_1) cell CLK_z_b init [[0]:0]
             | (S_cod_u,S_cod_y,fin_resolver) := resolver(S_cod_cond,S_cod_x)
             |)
          |)
         where 
         event CLK_769, CLK_Task_1, CLK_762, CLK_761;
         [1]integer cod_cond;
         [6]integer cod_x;
         boolean z_b, b;
         [6]integer S_cod_x;
         [4]integer S_cod_u, Z_S_cod_u;
         [3]integer S_cod_y, Z_S_cod_y;
         [1]integer S_cod_cond;
         boolean fin_resolver;
         process ACT_CLK_Task_1 =
              ( )
            (| CLK_Task_1 ^= Task_1 ^= INTERM0 ^= INTERM1 ^= INTERM2 ^= INTERM3 ^= INTERM4 ^= INTERM5 ^= cod_y ^= cod_u ^= Pump_Off ^= u2 ^= u4 ^= u3 ^= u1 ^= d_stuck ^= d_run ^= d_normal ^= Pump_On ^= Flow_0 ^= X0 ^= X1 ^= X2 ^= X3 ^= X4 ^= X5 ^= X6 ^= 
               Z_Pump_On ^= Z_Pump_Off ^= Z_X0 ^= Z_X1 ^= Z_X2 ^= Z_X3 ^= Z_X4 ^= Z_X5 ^= Z_X6 ^= Z_Task_1
             | (| CLK_296 := when (u1 and d_normal)
                | CLK_297 := when (not (u1 and d_normal))
                |)
             | (| CLK_298 := when d_run
                | CLK_299 := when (not d_run)
                |)
             | (| CLK_303 := when d_normal
                | CLK_304 := when (not d_normal)
                |)
             | (| CLK_306 := when u1
                | CLK_307 := when (not u1)
                |)
             | (| CLK_312 := when d_stuck
                | CLK_313 := when (not d_stuck)
                |)
             | (| CLK_337 := when Pump_On
                | CLK_338 := when (not Pump_On)
                |)
             | (| CLK_340 := when u2
                | CLK_341 := when (not u2)
                |)
             | (| CLK_352 := when Z_X1
                | CLK_353 := when (not Z_X1)
                |)
             | (| CLK_360 := when Z_X0
                | CLK_361 := when (not Z_X0)
                |)
             | (| CLK_368 := when Z_X2
                | CLK_369 := when (not Z_X2)
                |)
             | (| CLK_386 := when Z_X3
                | CLK_387 := when (not Z_X3)
                |)
             | (| CLK_415 := when Z_X4
                | CLK_416 := when (not Z_X4)
                |)
             | (| CLK_439 := when Z_X5
                | CLK_440 := when (not Z_X5)
                |)
             | (| CLK_463 := when Z_X6
                | CLK_464 := when (not Z_X6)
                |)
             | (| CLK_511 := when (u3 and u4)
                | CLK_512 := when (not (u3 and u4))
                |)
             | (| CLK_514 := when Flow_0
                | CLK_515 := when (not Flow_0)
                |)
             | (| CLK_517 := when u4
                | CLK_518 := when (not u4)
                |)
             | (| CLK_521 := when u3
                | CLK_522 := when (not u3)
                |)
             | (| CLK_574 := when X1
                | CLK_575 := when (not X1)
                |)
             | (| CLK_576 := when X5
                | CLK_577 := when (not X5)
                |)
             | (| CLK_602 := when X0
                | CLK_603 := when (not X0)
                |)
             | (| CLK_627 := when X6
                | CLK_628 := when (not X6)
                |)
             | (| CLK_637 := when X2
                | CLK_638 := when (not X2)
                |)
             | (| CLK_648 := when (cod_y[0]=1)
                | CLK_649 := when (not (cod_y[0]=1))
                |)
             | (| CLK_651 := when (cod_y[0]=(-1))
                | CLK_652 := when (not (cod_y[0]=(-1)))
                |)
             | (| CLK_660 := when (cod_y[1]=1)
                | CLK_661 := when (not (cod_y[1]=1))
                |)
             | (| CLK_663 := when (cod_y[1]=(-1))
                | CLK_664 := when (not (cod_y[1]=(-1)))
                |)
             | (| CLK_672 := when (cod_y[2]=1)
                | CLK_673 := when (not (cod_y[2]=1))
                |)
             | (| CLK_675 := when (cod_y[2]=(-1))
                | CLK_676 := when (not (cod_y[2]=(-1)))
                |)
             | (| CLK_685 := when (cod_u[0]=1)
                | CLK_686 := when (not (cod_u[0]=1))
                |)
             | (| CLK_688 := when (cod_u[0]=(-1))
                | CLK_689 := when (not (cod_u[0]=(-1)))
                |)
             | (| CLK_697 := when (cod_u[1]=1)
                | CLK_698 := when (not (cod_u[1]=1))
                |)
             | (| CLK_700 := when (cod_u[1]=(-1))
                | CLK_701 := when (not (cod_u[1]=(-1)))
                |)
             | (| CLK_709 := when (cod_u[2]=1)
                | CLK_710 := when (not (cod_u[2]=1))
                |)
             | (| CLK_712 := when (cod_u[2]=(-1))
                | CLK_713 := when (not (cod_u[2]=(-1)))
                |)
             | (| CLK_721 := when (cod_u[3]=1)
                | CLK_722 := when (not (cod_u[3]=1))
                |)
             | (| CLK_724 := when (cod_u[3]=(-1))
                | CLK_725 := when (not (cod_u[3]=(-1)))
                |)
             | (| CLK_874 := CLK_721 ^+ CLK_724 |)
             | (| CLK_876 := CLK_709 ^+ CLK_712 |)
             | (| CLK_878 := CLK_697 ^+ CLK_700 |)
             | (| CLK_880 := CLK_685 ^+ CLK_688 |)
             | (| CLK_882 := CLK_672 ^+ CLK_675 |)
             | (| CLK_884 := CLK_660 ^+ CLK_663 |)
             | (| CLK_886 := CLK_648 ^+ CLK_651 |)
             | (| CLK_938 := CLK_296 ^+ CLK_298 |)
             | (| CLK_940 := CLK_303 ^* CLK_307 |)
             | (| CLK_942 := CLK_307 ^+ CLK_938 |)
             | (| CLK_944 := CLK_940 ^+ CLK_938 |)
             | (| CLK_Inter_Pump_On := CLK_312 ^+ CLK_944
                | CLK_Inter_Pump_On ^= Inter_Pump_On ^= Inter_Pump_Off
                | ACT_CLK_Inter_Pump_On{}
                |)
             | (| CLK_948 := CLK_312 ^+ CLK_940 |)
             | (| CLK_950 := CLK_312 ^+ CLK_942 |)
             | (| CLK_952 := CLK_950 ^* CLK_303 |)
             | (| CLK_954 := CLK_948 ^+ CLK_296 |)
             | (| CLK_959 := CLK_337 ^* CLK_340 |)
             | (| CLK_961 := CLK_511 ^* CLK_515 |)
             | (| CLK_963 := CLK_961 ^* CLK_463 |)
             | (| CLK_965 := CLK_961 ^* CLK_439 |)
             | (| CLK_967 := CLK_961 ^* CLK_415 |)
             | (| CLK_969 := CLK_961 ^* CLK_386 |)
             | (| CLK_971 := CLK_961 ^* CLK_368 |)
             | (| CLK_973 := CLK_511 ^* CLK_514 |)
             | (| CLK_975 := CLK_973 ^+ CLK_515 |)
             | (| CLK_977 := CLK_518 ^* CLK_522 |)
             | (| CLK_XZX_673 := CLK_518 ^+ CLK_522
                | ACT_CLK_XZX_673{}
                |)
             | (| CLK_981 := CLK_514 ^* CLK_522 |)
             | (| CLK_983 := CLK_981 ^* CLK_518 |)
             | (| CLK_985 := CLK_983 ^* CLK_439 |)
             | (| CLK_987 := CLK_983 ^* CLK_415 |)
             | (| CLK_989 := CLK_983 ^* CLK_386 |)
             | (| CLK_991 := CLK_983 ^* CLK_368 |)
             | (| CLK_993 := CLK_983 ^* CLK_360 |)
             | (| CLK_995 := CLK_983 ^* CLK_352 |)
             | (| CLK_997 := CLK_975 ^* CLK_528 |)
             | (| CLK_999 := CLK_515 ^* CLK_528 |)
             | (| CLK_1001 := CLK_999 ^+ CLK_973 |)
             | (| CLK_1003 := CLK_999 ^+ CLK_514 |)
             | (| CLK_1005 := CLK_1003 ^* CLK_511 |)
             | (| CLK_1007 := CLK_1001 ^+ CLK_987 |)
             | (| CLK_1009 := CLK_1001 ^+ CLK_983 |)
             | (| CLK_1011 := CLK_1001 ^* CLK_522 |)
             | (| CLK_1013 := CLK_1001 ^* CLK_518 |)
             | (| CLK_1015 := CLK_1001 ^+ CLK_961 |)
             | (| CLK_1017 := CLK_1001 ^* CLK_463 |)
             | (| CLK_1019 := CLK_1001 ^* CLK_439 |)
             | (| CLK_1021 := CLK_1001 ^* CLK_415 |)
             | (| CLK_1023 := CLK_1001 ^* CLK_386 |)
             | (| CLK_1025 := CLK_1001 ^* CLK_368 |)
             | (| CLK_1027 := CLK_1025 ^+ CLK_969 |)
             | (| CLK_1029 := CLK_1027 ^+ CLK_993 |)
             | (| CLK_1031 := CLK_1027 ^+ CLK_983 |)
             | (| CLK_1033 := CLK_1023 ^+ CLK_967 |)
             | (| CLK_1035 := CLK_1033 ^+ CLK_995 |)
             | (| CLK_1037 := CLK_1033 ^+ CLK_983 |)
             | (| CLK_1039 := CLK_1021 ^+ CLK_965 |)
             | (| CLK_1041 := CLK_1039 ^+ CLK_991 |)
             | (| CLK_1043 := CLK_1039 ^+ CLK_983 |)
             | (| CLK_1045 := CLK_1019 ^+ CLK_963 |)
             | (| CLK_1047 := CLK_1045 ^+ CLK_989 |)
             | (| CLK_1049 := CLK_1045 ^+ CLK_983 |)
             | (| CLK_1051 := CLK_1017 ^+ CLK_987 |)
             | (| CLK_1053 := CLK_1017 ^+ CLK_983 |)
             | (| CLK_1055 := CLK_1015 ^+ CLK_983 |)
             | (| CLK_1057 := CLK_1015 ^* CLK_360 |)
             | (| CLK_1059 := CLK_1015 ^* CLK_352 |)
             | (| CLK_1061 := CLK_1057 ^+ CLK_1059 |)
             | (| CLK_1063 := CLK_1061 ^+ CLK_971 |)
             | (| CLK_1065 := CLK_1061 ^+ CLK_961 |)
             | (| CLK_1067 := CLK_1065 ^+ CLK_993 |)
             | (| CLK_1069 := CLK_1067 ^* CLK_368 |)
             | (| CLK_Inter_X0 := CLK_1063 ^+ CLK_993
                | CLK_Inter_X0 ^= Inter_X0
                | Inter_X0 := CLK_1059 default CLK_1222 default CLK_1249 default (not CLK_1233)
                |)
             | (| CLK_1073 := CLK_1063 ^+ CLK_983 |)
             | (| CLK_1075 := CLK_1073 ^* CLK_360 |)
             | (| CLK_1077 := CLK_Inter_X0 ^* CLK_352 |)
             | (| CLK_1086 := CLK_1055 ^* CLK_463 |)
             | (| CLK_1088 := CLK_1055 ^* CLK_439 |)
             | (| CLK_1090 := CLK_1055 ^* CLK_415 |)
             | (| CLK_1092 := CLK_1055 ^* CLK_386 |)
             | (| CLK_1094 := CLK_1055 ^* CLK_368 |)
             | (| CLK_1096 := CLK_1055 ^* CLK_352 |)
             | (| CLK_Inter_X1 := CLK_1096 ^+ CLK_1029
                | CLK_Inter_X1 ^= Inter_X1
                | Inter_X1 := CLK_1025 default CLK_1247 default CLK_1235 default (not CLK_1220)
                |)
             | (| CLK_1100 := CLK_1096 ^+ CLK_1031 |)
             | (| CLK_1102 := CLK_1100 ^* CLK_360 |)
             | (| CLK_1104 := CLK_Inter_X1 ^* CLK_386 |)
             | (| CLK_1106 := CLK_Inter_X1 ^* CLK_368 |)
             | (| CLK_Inter_X2 := CLK_1094 ^+ CLK_1035
                | CLK_Inter_X2 ^= Inter_X2
                | Inter_X2 := CLK_1023 default CLK_1245 default CLK_1237 default (not CLK_1218)
                |)
             | (| CLK_1110 := CLK_1094 ^+ CLK_1037 |)
             | (| CLK_1112 := CLK_1110 ^* CLK_352 |)
             | (| CLK_1114 := CLK_Inter_X2 ^* CLK_415 |)
             | (| CLK_1116 := CLK_Inter_X2 ^* CLK_386 |)
             | (| CLK_Inter_X3 := CLK_1092 ^+ CLK_1041
                | CLK_Inter_X3 ^= Inter_X3
                | Inter_X3 := CLK_1021 default CLK_1243 default CLK_1231 default (not CLK_1216)
                |)
             | (| CLK_1120 := CLK_1092 ^+ CLK_1043 |)
             | (| CLK_1122 := CLK_1120 ^* CLK_368 |)
             | (| CLK_1124 := CLK_Inter_X3 ^* CLK_439 |)
             | (| CLK_1126 := CLK_Inter_X3 ^* CLK_415 |)
             | (| CLK_Inter_X4 := CLK_1090 ^+ CLK_1047
                | CLK_Inter_X4 ^= Inter_X4
                | Inter_X4 := CLK_1019 default CLK_1241 default CLK_1229 default (not CLK_1214)
                |)
             | (| CLK_1130 := CLK_1090 ^+ CLK_1049 |)
             | (| CLK_1132 := CLK_1130 ^* CLK_386 |)
             | (| CLK_1134 := CLK_Inter_X4 ^* CLK_463 |)
             | (| CLK_1136 := CLK_Inter_X4 ^* CLK_439 |)
             | (| CLK_Inter_X5 := CLK_1088 ^+ CLK_1051
                | CLK_Inter_X5 ^= Inter_X5
                | Inter_X5 := CLK_1017 default CLK_1227 default (not CLK_1212)
                |)
             | (| CLK_1140 := CLK_1088 ^+ CLK_1053 |)
             | (| CLK_1142 := CLK_1140 ^* CLK_415 |)
             | (| CLK_Inter_X6 := CLK_1086 ^+ CLK_985
                | CLK_Inter_X6 ^= Inter_X6
                | Inter_X6 := CLK_985 default (not CLK_1210)
                |)
             | (| CLK_1146 := CLK_1086 ^+ CLK_983 |)
             | (| CLK_1148 := CLK_1146 ^* CLK_439 |)
             | (| CLK_1156 := CLK_1007 ^+ CLK_1088 |)
             | (| CLK_1158 := CLK_1156 ^* CLK_463 |)
             | (| CLK_Inter_Task_1 := CLK_574 ^+ CLK_576
                | CLK_Inter_Task_1 ^= Inter_Task_1
                | Inter_Task_1 := CLK_574 default (not CLK_1206)
                |)
             | (| CLK_1169 := CLK_Task_1 ^- CLK_874 |)
             | (| CLK_1171 := CLK_Task_1 ^- CLK_876 |)
             | (| CLK_1173 := CLK_Task_1 ^- CLK_878 |)
             | (| CLK_1175 := CLK_Task_1 ^- CLK_880 |)
             | (| CLK_1177 := CLK_Task_1 ^- CLK_882 |)
             | (| CLK_1179 := CLK_Task_1 ^- CLK_884 |)
             | (| CLK_1181 := CLK_Task_1 ^- CLK_886 |)
             | (| CLK_1183 := CLK_Task_1 ^- CLK_Inter_Task_1 |)
             | (| CLK_1185 := CLK_Task_1 ^- CLK_Inter_X0 |)
             | (| CLK_1187 := CLK_Task_1 ^- CLK_Inter_X1 |)
             | (| CLK_1189 := CLK_Task_1 ^- CLK_Inter_X2 |)
             | (| CLK_1191 := CLK_Task_1 ^- CLK_Inter_X3 |)
             | (| CLK_1193 := CLK_Task_1 ^- CLK_Inter_X4 |)
             | (| CLK_1195 := CLK_Task_1 ^- CLK_Inter_X5 |)
             | (| CLK_1197 := CLK_Task_1 ^- CLK_Inter_X6 |)
             | (| CLK_1199 := CLK_Task_1 ^- CLK_959 |)
             | (| CLK_1201 := CLK_Task_1 ^- CLK_Inter_Pump_On |)
             | (| CLK_1206 := CLK_576 ^- CLK_574 |)
             | (| CLK_1210 := CLK_1086 ^- CLK_985 |)
             | (| CLK_1212 := CLK_1088 ^- CLK_1051 |)
             | (| CLK_1214 := CLK_1090 ^- CLK_1047 |)
             | (| CLK_1216 := CLK_1092 ^- CLK_1041 |)
             | (| CLK_1218 := CLK_1094 ^- CLK_1035 |)
             | (| CLK_1220 := CLK_1096 ^- CLK_1029 |)
             | (| CLK_1222 := CLK_1057 ^- CLK_1059 |)
             | (| CLK_1224 := CLK_1001 ^- CLK_983 |)
             | (| CLK_1227 := CLK_987 ^- CLK_1017 |)
             | (| CLK_1229 := CLK_989 ^- CLK_1045 |)
             | (| CLK_1231 := CLK_991 ^- CLK_1039 |)
             | (| CLK_1233 := CLK_993 ^- CLK_1063 |)
             | (| CLK_1235 := CLK_993 ^- CLK_1027 |)
             | (| CLK_1237 := CLK_995 ^- CLK_1033 |)
             | (| CLK_1239 := CLK_522 ^- CLK_518 |)
             | (| CLK_1241 := CLK_963 ^- CLK_1019 |)
             | (| CLK_1243 := CLK_965 ^- CLK_1021 |)
             | (| CLK_1245 := CLK_967 ^- CLK_1023 |)
             | (| CLK_1247 := CLK_969 ^- CLK_1025 |)
             | (| CLK_1249 := CLK_971 ^- CLK_1061 |)
             | (| CLK_1251 := CLK_961 ^- CLK_1009 |)
             | (| CLK_1255 := CLK_312 ^- CLK_944 |)
             | (| CLK_1257 := CLK_312 ^- CLK_940 |)
             | (| CLK_1259 := CLK_940 ^- CLK_938 |)
             | (| CLK_1261 := CLK_298 ^- CLK_296 |)
             | (| CLK_1263 := CLK_298 ^- CLK_954 |)
             | (| CLK_1283 := CLK_296 ^- CLK_948 |)
             | (| CLK_1285 := CLK_651 ^- CLK_648 |)
             | (| CLK_1287 := CLK_663 ^- CLK_660 |)
             | (| CLK_1289 := CLK_675 ^- CLK_672 |)
             | (| CLK_1291 := CLK_688 ^- CLK_685 |)
             | (| CLK_1293 := CLK_700 ^- CLK_697 |)
             | (| CLK_1295 := CLK_712 ^- CLK_709 |)
             | (| CLK_1297 := CLK_724 ^- CLK_721 |)
             | (| Task_1 := (Inter_Task_1 when CLK_Inter_Task_1) default (Z_Task_1 when CLK_1183)
                | INTERM0 := (1 when CLK_337) default (2 when CLK_338)
                | INTERM1 := (1 when CLK_602) default (2 when CLK_603)
                | INTERM2 := (1 when CLK_574) default (2 when CLK_575)
                | INTERM3 := (1 when CLK_576) default (2 when CLK_577)
                | INTERM4 := (1 when CLK_627) default (2 when CLK_628)
                | INTERM5 := (1 when CLK_637) default (2 when CLK_638)
                | cod_y := Z_S_cod_y when CLK_Task_1
                | cod_cond := [[0]:0] when CLK_Task_1
                | cod_x := [[0]:INTERM0,[1]:INTERM1,[2]:INTERM2,[3]:INTERM3,[4]:INTERM4,[5]:INTERM5]
                | cod_u := Z_S_cod_u when CLK_Task_1
                | Pump_Off := (Inter_Pump_Off when CLK_Inter_Pump_On) default (Z_Pump_Off when CLK_1201)
                | u2 := CLK_697 default (not CLK_1293) default (not CLK_1173)
                | u4 := CLK_721 default (not CLK_1297) default (not CLK_1169)
                | u3 := CLK_709 default (not CLK_1295) default (not CLK_1171)
                | u1 := CLK_685 default (not CLK_1291) default (not CLK_1175)
                | d_stuck := CLK_672 default (not CLK_1289) default (not CLK_1177)
                | d_run := CLK_660 default (not CLK_1287) default (not CLK_1179)
                | d_normal := CLK_648 default (not CLK_1285) default (not CLK_1181)
                | Pump_On := (Inter_Pump_On when CLK_Inter_Pump_On) default (Z_Pump_On when CLK_1201)
                | Flow_0 := CLK_959 default (not CLK_1199)
                | X0 := (Inter_X0 when CLK_Inter_X0) default (Z_X0 when CLK_1185)
                | X1 := (Inter_X1 when CLK_Inter_X1) default (Z_X1 when CLK_1187)
                | X2 := (Inter_X2 when CLK_Inter_X2) default (Z_X2 when CLK_1189)
                | X3 := (Inter_X3 when CLK_Inter_X3) default (Z_X3 when CLK_1191)
                | X4 := (Inter_X4 when CLK_Inter_X4) default (Z_X4 when CLK_1193)
                | X5 := (Inter_X5 when CLK_Inter_X5) default (Z_X5 when CLK_1195)
                | X6 := (Inter_X6 when CLK_Inter_X6) default (Z_X6 when CLK_1197)
                | Z_Pump_On := Pump_On$1 init false
                | Z_Pump_Off := Pump_Off$1 init true
                | Z_X0 := X0$1 init false
                | Z_X1 := X1$1 init false
                | Z_X2 := X2$1 init false
                | Z_X3 := X3$1 init true
                | Z_X4 := X4$1 init false
                | Z_X5 := X5$1 init false
                | Z_X6 := X6$1 init false
                | Draw_State(X0,X1,X2,X3,X4,X5,X6,Flow_0)
                | Draw(Pump_On,Flow_0,u2,u3,u4)
                | Z_Task_1 := Task_1$1 init false
                |)
             |)
            where 
            event CLK_1297, CLK_1295, CLK_1293, CLK_1291, CLK_1289, CLK_1287, CLK_1285, CLK_1283, CLK_1263, CLK_1261, CLK_1259, CLK_1257, CLK_1255, CLK_1251, CLK_1249, CLK_1247, CLK_1245, CLK_1243, CLK_1241, CLK_1239, CLK_1237, CLK_1235, CLK_1233, 
                 CLK_1231, CLK_1229, CLK_1227, CLK_1224, CLK_1222, CLK_1220, CLK_1218, CLK_1216, CLK_1214, CLK_1212, CLK_1210, CLK_1206, CLK_1201, CLK_1199, CLK_1197, CLK_1195, CLK_1193, CLK_1191, CLK_1189, CLK_1187, CLK_1185, CLK_1183, CLK_1181, CLK_1179,
                 CLK_1177, CLK_1175, CLK_1173, CLK_1171, CLK_1169, CLK_Inter_Task_1, CLK_1158, CLK_1156, CLK_1148, CLK_1146, CLK_Inter_X6, CLK_1142, CLK_1140, CLK_Inter_X5, CLK_1136, CLK_1134, CLK_1132, CLK_1130, CLK_Inter_X4, CLK_1126, CLK_1124, CLK_1122,
                 CLK_1120, CLK_Inter_X3, CLK_1116, CLK_1114, CLK_1112, CLK_1110, CLK_Inter_X2, CLK_1106, CLK_1104, CLK_1102, CLK_1100, CLK_Inter_X1, CLK_1096, CLK_1094, CLK_1092, CLK_1090, CLK_1088, CLK_1086, CLK_1077, CLK_1075, CLK_1073, CLK_Inter_X0, 
                 CLK_1069, CLK_1067, CLK_1065, CLK_1063, CLK_1061, CLK_1059, CLK_1057, CLK_1055, CLK_1053, CLK_1051, CLK_1049, CLK_1047, CLK_1045, CLK_1043, CLK_1041, CLK_1039, CLK_1037, CLK_1035, CLK_1033, CLK_1031, CLK_1029, CLK_1027, CLK_1025, CLK_1023,
                 CLK_1021, CLK_1019, CLK_1017, CLK_1015, CLK_1013, CLK_1011, CLK_1009, CLK_1007, CLK_1005, CLK_1003, CLK_1001, CLK_999, CLK_997, CLK_995, CLK_993, CLK_991, CLK_989, CLK_987, CLK_985, CLK_983, CLK_981, CLK_XZX_673, CLK_977, CLK_975, CLK_973,
                 CLK_971, CLK_969, CLK_967, CLK_965, CLK_963, CLK_961, CLK_959, CLK_954, CLK_952, CLK_950, CLK_948, CLK_Inter_Pump_On, CLK_944, CLK_942, CLK_940, CLK_938, CLK_886, CLK_884, CLK_882, CLK_880, CLK_878, CLK_876, CLK_874, CLK_725, CLK_724, 
                 CLK_722, CLK_721, CLK_713, CLK_712, CLK_710, CLK_709, CLK_701, CLK_700, CLK_698, CLK_697, CLK_689, CLK_688, CLK_686, CLK_685, CLK_676, CLK_675, CLK_673, CLK_672, CLK_664, CLK_663, CLK_661, CLK_660, CLK_652, CLK_651, CLK_649, CLK_648, 
                 CLK_638, CLK_637, CLK_628, CLK_627, CLK_603, CLK_602, CLK_577, CLK_576, CLK_575, CLK_574, CLK_528, CLK_522, CLK_521, CLK_518, CLK_517, CLK_515, CLK_514, CLK_512, CLK_511, CLK_464, CLK_463, CLK_440, CLK_439, CLK_416, CLK_415, CLK_387, 
                 CLK_386, CLK_369, CLK_368, CLK_361, CLK_360, CLK_353, CLK_352, CLK_341, CLK_340, CLK_338, CLK_337, CLK_313, CLK_312, CLK_307, CLK_306, CLK_304, CLK_303, CLK_299, CLK_298, CLK_297, CLK_296;
            boolean Task_1;
            integer INTERM0, INTERM1, INTERM2, INTERM3, INTERM4, INTERM5;
            [3]integer cod_y;
            [4]integer cod_u;
            boolean Pump_Off, u2, u4, u3, u1, d_stuck, d_run, d_normal, Pump_On, Flow_0, X0, X1, X2, X3, X4, X5, X6, Z_Pump_On, Inter_Pump_On, Z_Pump_Off, Inter_Pump_Off, Z_X0, Z_X1, Z_X2, Z_X3, Z_X4, Z_X5, Z_X6, Inter_X0, Inter_X1, Inter_X2, Inter_X3, 
                   Inter_X4, Inter_X5, Inter_X6, Inter_Task_1, Z_Task_1;
            process ACT_CLK_Inter_Pump_On =
                 ( )
               (| (| Inter_Pump_On := CLK_296 default CLK_1261 default (not CLK_1259) default (not CLK_1255)
                   | Inter_Pump_Off := CLK_940 default CLK_1257 default (not CLK_1283) default (not CLK_1263)
                   |) |)
            %ACT_CLK_Inter_Pump_On%; 
            process ACT_CLK_XZX_673 =
                 ( )
               (| CLK_XZX_673 ^= XZX_673
                | (| CLK_528 := when XZX_673
                   | CLK_529 := when (not XZX_673)
                   |)
                | (| XZX_673 := (u3 when CLK_518) default (u4 when CLK_1239) |)
                |)
               where 
               event CLK_529;
               boolean XZX_673;
               end
            %ACT_CLK_XZX_673%; 
            end
         %ACT_CLK_Task_1%; 
         end
      %ACT_CLK_z_b%; 
      process ACT_CLK_ZAUTO =
           ( )
         (| CLK_ZAUTO ^= ZAUTO
          | (| ZAUTO := NEXTAUTO$1 init true
             | NEXTAUTO := not ZAUTO
             | RESET_PANEL(NEXTAUTO)
             |)
          |)
         where 
         boolean ZAUTO;
         end
      %ACT_CLK_ZAUTO%; 
      process ACT_CLK_NEW_BOUND =
           ( )
         (| CLK_NEW_BOUND ^= XZX_355
          | (| CLK := when (NEW_BOUND<=1)
             | CLK_22 := when (not (NEW_BOUND<=1))
             |)
          | (| NEW_BOUND := (PI_0 when CLK_PI_0) default (NEW_BOUND_2 when CLK_1276) default (NEW_BOUND_1 when CLK_1278) default (OLD_BOUND when CLK_1266)
             | OLD_BOUND := NEW_BOUND$1 init 1
             | XZX_355 := ADR_COUNT when CLK_NEW_BOUND
             | WIWRITE(XZX_355,NEW_BOUND)
             |)
          |)
         where 
         integer XZX_355;
         end
      %ACT_CLK_NEW_BOUND%; 
      end
   %ACT_HE%; 
   process RUPDOWN =
        ( ? integer ADRCOUNT;
          ! boolean UPDOWN;
        )
        spec (| ADRCOUNT ^= UPDOWN |)
   
   %RUPDOWN%; 
   process WSTOP =
        ( ? event DOWN;
        )
   
   %WSTOP%; 
   process RSTOP =
        ( ! boolean STOP;
        )
   
   %RSTOP%; 
   process GET_PACE_RHYTHM =
        ( ! integer DESCR;
            integer PI_0;
        )
        spec (| DESCR ^= PI_0 |)
   
   %GET_PACE_RHYTHM%; 
   process Draw_State =
        ( ? boolean X0;
            boolean X1;
            boolean X2;
            boolean X3;
            boolean X4;
            boolean X5;
            boolean X6;
            boolean Flow;
        )
        spec (| X0 ^= X1 ^= X2 ^= X3 ^= X4 ^= X5 ^= X6 ^= Flow |)
   
   %Draw_State%; 
   process Draw =
        ( ? boolean Flow_Pump;
            boolean Flow_Valve2;
            boolean Valve2;
            boolean Valve3;
            boolean Valve4;
        )
        spec (| Flow_Pump ^= Flow_Valve2 ^= Valve2 ^= Valve3 ^= Valve4 |)
   
   %Draw%; 
   process resolver =
        ( ? [ncond]integer S_cod_cond;
            [nx]integer S_cod_x;
          ! [nu]integer S_cod_u;
            [ny]integer S_cod_y;
            boolean fin_resolver;
        )
        spec (| S_cod_cond ^= S_cod_x ^= S_cod_u ^= S_cod_y ^= fin_resolver |)
   
   %resolver%; 
   process RESET_PANEL =
        ( ? boolean AUTO;
        )
   
   %RESET_PANEL%; 
   process WIWRITE =
        ( ? integer ADR_COUNT;
            integer V;
        )
        spec (| ADR_COUNT ^= V |)
   
   %WIWRITE%; 
   process RCHANGE =
        ( ? integer ADRCOUNT;
          ! integer CODE;
        )
        spec (| ADRCOUNT ^= CODE |)
   
   %RCHANGE%; 
   process RAUTO =
        ( ! boolean AUTO;
        )
   
   %RAUTO%; 
   process RTICK =
        ( ! boolean TICK;
        )
   
   %RTICK%; 
   end
%vt_TRA%; 

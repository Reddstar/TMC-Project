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
   constant integer PI_0_241 = 1;
   constant integer V_0 = 1;
   constant integer ncond = 1;
   constant integer nx = 20;
   constant integer nu = 12;
   constant integer ny = 13;
   process ACT_HE =
        ( )
      (| HE ^= ADR_COUNT ^= CINIT ^= AUTOMOD ^= C_TICK ^= C_SW_AUTO ^= CODE_CHANGE
       | (| CLK_PI_0 := when CINIT
          | CLK_PI_0 ^= PI_0 ^= DESCR
          | (DESCR,PI_0) := GET_PACE_RHYTHM()
          | CLK := when (not CINIT)
          |)
       | (| CLK_56 := when C_TICK
          | CLK_57 := when (not C_TICK)
          |)
       | (| CLK_64 := when C_SW_AUTO
          | CLK_65 := when (not C_SW_AUTO)
          |)
       | (| CLK_MAX := when AUTOMOD
          | ACT_CLK_MAX{}
          | CLK_C_STOP := when (not AUTOMOD)
          | ACT_CLK_C_STOP{}
          |)
       | (| CLK_C_UP_DOWN := when (CODE_CHANGE/=0)
          | ACT_CLK_C_UP_DOWN{}
          | CLK_101 := when (not (CODE_CHANGE/=0))
          |)
       | (| CLK_NEW_BOUND := CLK_PI_0 ^+ CLK_C_UP_DOWN
          | CLK_NEW_BOUND ^= NEW_BOUND ^= OLD_BOUND
          | ACT_CLK_NEW_BOUND{}
          |)
       | (| CLK_ZAUTO := CLK_PI_0 ^+ CLK_64
          | CLK_ZAUTO ^= NEXTAUTO
          | ACT_CLK_ZAUTO{}
          |)
       | (| CLK_MAX1 := CLK_MAX ^+ CLK_NEW_BOUND
          | CLK_MAX1 ^= MAX1
          | MAX1 := ((0 when CLK_130) default ((NEW_BOUND-1) when CLK_131)) cell CLK_MAX1 init 0
          |)
       | (| CLK_1591 := CLK_MAX ^+ CLK_C_UP_DOWN |)
       | (| CLK_1593 := CLK_MAX ^* CLK_130 |)
       | (| CLK_1595 := CLK_1591 ^+ CLK_56 |)
       | (| CLK_1598 := CLK_MAX ^+ CLK_86 |)
       | (| CLK_1600 := CLK_1598 ^+ CLK_ZAUTO |)
       | (| CLK_1602 := CLK_1600 ^+ CLK_56 |)
       | (| CLK_1613 := CLK_PI_0 ^+ CLK_NEW_BOUND_1 |)
       | (| CLK_1622 := CLK_1613 ^+ CLK_NEW_BOUND_2 |)
       | (| CLK_1631 := CLK_MAX1 ^+ CLK_56 |)
       | (| CLK_z_b := CLK_56 ^+ CLK_152
          | ACT_CLK_z_b{}
          |)
       | (| CLK_1703 := CLK_NEW_BOUND ^+ CLK_152 |)
       | (| CLK_1705 := CLK_z_b ^+ CLK_PI_0 |)
       | (| CLK_1858 := CLK_NEW_BOUND_2 ^- CLK_1613 |)
       | (| CLK_1860 := CLK_NEW_BOUND_1 ^- CLK_PI_0 |)
       | (| CLK_1864 := CLK_64 ^- CLK_PI_0 |)
       | (| CLK_1866 := CLK_56 ^- CLK_152 |)
       | (| CLK_1869 := CLK_NEW_BOUND ^- CLK_1622 |)
       | (| CLK_1871 := CLK_PI_0 ^- CLK_C_UP_DOWN |)
       | (| ADR_COUNT := (DESCR when CLK_PI_0) cell HE init 0
          | CINIT := (false when HE)$1 init true
          | AUTOMOD := (NEXTAUTO when CLK_ZAUTO) cell HE init true
          | C_TICK := RTICK()
          | C_SW_AUTO := RAUTO()
          | CODE_CHANGE := RCHANGE(ADR_COUNT)
          |)
       |)
      where 
      event CLK_1871, CLK_1869, CLK_1866, CLK_1864, CLK_1860, CLK_1858, CLK_1705, CLK_1703, CLK_z_b, CLK_1631, CLK_1622, CLK_NEW_BOUND_2, CLK_1613, CLK_NEW_BOUND_1, CLK_1602, CLK_1600, CLK_1598, CLK_1595, CLK_1593, CLK_1591, CLK_MAX1, CLK_ZAUTO, 
           CLK_NEW_BOUND, CLK_152, CLK_131, CLK_130, CLK_101, CLK_C_UP_DOWN, CLK_86, CLK_C_STOP, CLK_MAX, CLK_65, CLK_64, CLK_57, CLK_56, CLK, CLK_PI_0;
      integer PI_0, NEW_BOUND, ADR_COUNT;
      boolean CINIT;
      integer DESCR;
      boolean AUTOMOD, C_TICK, C_SW_AUTO, NEXTAUTO;
      integer CODE_CHANGE, MAX1, OLD_BOUND, NEW_BOUND_1, NEW_BOUND_2;
      process ACT_CLK_MAX =
           ( )
         (| CLK_MAX ^= MAX ^= ZV ^= V
          | (| CLK_145 := when (ZV>=MAX)
             | CLK_146 := when (not (ZV>=MAX))
             |)
          | (| CLK_152 := when (V=0)
             | CLK_153 := when (not (V=0))
             |)
          | (| MAX := MAX1 when CLK_MAX
             | ZV := V$1 init V_0
             | V := (0 when CLK_145) default ((ZV+1) when CLK_146)
             |)
          |)
         where 
         event CLK_153, CLK_146, CLK_145;
         integer MAX, ZV, V;
         end
      %ACT_CLK_MAX%; 
      process ACT_CLK_C_STOP =
           ( )
         (| CLK_C_STOP ^= C_STOP
          | (| CLK_86 := when C_STOP
             | WSTOP(CLK_86)
             | CLK_87 := when (not C_STOP)
             |)
          | (| C_STOP := RSTOP() |)
          |)
         where 
         event CLK_87;
         boolean C_STOP;
         end
      %ACT_CLK_C_STOP%; 
      process ACT_CLK_C_UP_DOWN =
           ( )
         (| CLK_C_UP_DOWN ^= C_UP_DOWN ^= C_LIN_EXP ^= XZX_199
          | (| CLK_XZX_289 := when C_LIN_EXP
             | ACT_CLK_XZX_289{}
             | CLK_XZX_320 := when (not C_LIN_EXP)
             | ACT_CLK_XZX_320{}
             |)
          | (| C_LIN_EXP := (CODE_CHANGE=2) when CLK_C_UP_DOWN
             | XZX_199 := ADR_COUNT when CLK_C_UP_DOWN
             | C_UP_DOWN := RUPDOWN(XZX_199)
             |)
          |)
         where 
         event CLK_XZX_320, CLK_XZX_289;
         boolean C_UP_DOWN, C_LIN_EXP;
         integer XZX_199;
         process ACT_CLK_XZX_289 =
              ( )
            (| CLK_XZX_289 ^= XZX_289 ^= XZX_292 ^= DELTA
             | (| CLK_171 := when (XZX_289>=16)
                | CLK_172 := when (not (XZX_289>=16))
                |)
             | (| CLK_180 := when XZX_292
                | CLK_VD := when (not XZX_292)
                | CLK_VD ^= VD
                | ACT_CLK_VD{}
                |)
             | (| CLK_186 := when (XZX_289>1)
                | CLK_187 := when (not (XZX_289>1))
                |)
             | (| CLK_VU := CLK_180 ^* CLK_186
                | CLK_VU ^= VU
                | VU := (XZX_289-DELTA) when CLK_VU
                |)
             | (| CLK_1608 := CLK_VU ^+ CLK_VD |)
             | (| CLK_NEW_BOUND_1 := CLK_VU ^+ CLK_191
                | CLK_NEW_BOUND_1 ^= NEW_BOUND_1
                | NEW_BOUND_1 := (VU when CLK_VU) default (VD when CLK_191)
                |)
             | (| XZX_289 := OLD_BOUND when CLK_XZX_289
                | XZX_292 := C_UP_DOWN when CLK_XZX_289
                | DELTA := ((XZX_289/16) when CLK_171) default (1 when CLK_172)
                |)
             |)
            where 
            event CLK_1608, CLK_VU, CLK_191, CLK_187, CLK_186, CLK_VD, CLK_180, CLK_172, CLK_171;
            integer XZX_289;
            boolean XZX_292;
            integer DELTA, VD, VU;
            process ACT_CLK_VD =
                 ( )
               (| (| CLK_191 := when (VD>0)
                   | CLK_192 := when (not (VD>0))
                   |)
                | (| VD := (XZX_289+DELTA) when CLK_VD |)
                |)
               where 
               event CLK_192;
               end
            %ACT_CLK_VD%; 
            end
         %ACT_CLK_XZX_289%; 
         process ACT_CLK_XZX_320 =
              ( )
            (| CLK_XZX_320 ^= XZX_320 ^= XZX_324
             | (| CLK_211 := when XZX_324
                | CLK_VD_329 := when (not XZX_324)
                | CLK_VD_329 ^= VD_329
                | ACT_CLK_VD_329{}
                |)
             | (| CLK_217 := when (XZX_320>1)
                | CLK_218 := when (not (XZX_320>1))
                |)
             | (| CLK_VU_330 := CLK_211 ^* CLK_217
                | CLK_VU_330 ^= VU_330
                | VU_330 := (XZX_320/2) when CLK_VU_330
                |)
             | (| CLK_1617 := CLK_VU_330 ^+ CLK_VD_329 |)
             | (| CLK_NEW_BOUND_2 := CLK_VU_330 ^+ CLK_222
                | CLK_NEW_BOUND_2 ^= NEW_BOUND_2
                | NEW_BOUND_2 := (VU_330 when CLK_VU_330) default (VD_329 when CLK_222)
                |)
             | (| XZX_320 := OLD_BOUND when CLK_XZX_320
                | XZX_324 := C_UP_DOWN when CLK_XZX_320
                |)
             |)
            where 
            event CLK_1617, CLK_VU_330, CLK_222, CLK_218, CLK_217, CLK_VD_329, CLK_211;
            integer XZX_320;
            boolean XZX_324;
            integer VD_329, VU_330;
            process ACT_CLK_VD_329 =
                 ( )
               (| (| CLK_222 := when (VD_329>0)
                   | CLK_223 := when (not (VD_329>0))
                   |)
                | (| VD_329 := (XZX_320+XZX_320) when CLK_VD_329 |)
                |)
               where 
               event CLK_223;
               end
            %ACT_CLK_VD_329%; 
            end
         %ACT_CLK_XZX_320%; 
         end
      %ACT_CLK_C_UP_DOWN%; 
      process ACT_CLK_NEW_BOUND =
           ( )
         (| CLK_NEW_BOUND ^= XZX
          | (| CLK_130 := when (NEW_BOUND<=1)
             | CLK_131 := when (not (NEW_BOUND<=1))
             |)
          | (| NEW_BOUND := (PI_0 when CLK_PI_0) default (NEW_BOUND_1 when CLK_1860) default (NEW_BOUND_2 when CLK_1858) default (OLD_BOUND when CLK_1869)
             | XZX := ADR_COUNT when CLK_NEW_BOUND
             | WIWRITE(XZX,NEW_BOUND)
             | OLD_BOUND := NEW_BOUND$1 init 1
             |)
          |)
         where 
         integer XZX;
         end
      %ACT_CLK_NEW_BOUND%; 
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
      process ACT_CLK_z_b =
           ( )
         (| CLK_z_b ^= z_b ^= b ^= S_cod_x ^= S_cod_u ^= Z_S_cod_u ^= S_cod_y ^= Z_S_cod_y ^= S_cod_cond ^= fin_resolver
          | (| CLK_1362 := when fin_resolver
             | CLK_1363 := when (not fin_resolver)
             |)
          | (| CLK_INTERM0 := when z_b
             | CLK_INTERM0 ^= cod_cond ^= cod_x
             | ACT_CLK_INTERM0{}
             | CLK_1370 := when (not z_b)
             |)
          | (| z_b := b$1 init true
             | b := CLK_1362 default (not CLK_1363)
             | S_cod_x := (cod_x when CLK_INTERM0) cell CLK_z_b init [[0]:0]
             | Z_S_cod_u := S_cod_u$1 init [{i to 12 step 1}:0]
             | Z_S_cod_y := S_cod_y$1 init [{i_1781 to 13 step 1}:0]
             | S_cod_cond := (cod_cond when CLK_INTERM0) cell CLK_z_b init [[0]:0]
             | (S_cod_u,S_cod_y,fin_resolver) := resolver(S_cod_cond,S_cod_x)
             |)
          |)
         where 
         event CLK_1370, CLK_INTERM0, CLK_1363, CLK_1362;
         [1]integer cod_cond;
         [20]integer cod_x;
         boolean z_b, b;
         [20]integer S_cod_x;
         [12]integer S_cod_u, Z_S_cod_u;
         [13]integer S_cod_y, Z_S_cod_y;
         [1]integer S_cod_cond;
         boolean fin_resolver;
         process ACT_CLK_INTERM0 =
              ( )
            (| CLK_INTERM0 ^= INTERM0 ^= INTERM1 ^= INTERM2 ^= INTERM3 ^= INTERM4 ^= INTERM5 ^= INTERM6 ^= INTERM7 ^= INTERM8 ^= INTERM9 ^= INTERM10 ^= INTERM11 ^= INTERM12 ^= INTERM13 ^= INTERM14 ^= INTERM15 ^= INTERM16 ^= INTERM17 ^= INTERM18 ^= 
               INTERM19 ^= cod_y ^= cod_u ^= Cat_Room_4 ^= Cat_Room_3 ^= Cat_Room_2 ^= Cat_Room_1 ^= Cat_Room_0 ^= Mouse_Room_4 ^= Mouse_Room_3 ^= Mouse_Room_2 ^= Mouse_Room_1 ^= Mouse_Room_0 ^= DoorState_Cat_6 ^= DoorState_Cat_5 ^= DoorState_Cat_4 ^= 
               DoorState_Cat_3 ^= DoorState_Cat_2 ^= DoorState_Cat_1 ^= DoorState_Mouse_6 ^= DoorState_Mouse_5 ^= DoorState_Mouse_4 ^= DoorState_Mouse_3 ^= DoorState_Mouse_2 ^= DoorState_Mouse_1 ^= Mvt_Cat_7 ^= Mvt_Cat_6 ^= Mvt_Cat_5 ^= Mvt_Cat_4 ^= 
               Mvt_Cat_3 ^= Mvt_Cat_2 ^= Mvt_Cat_1 ^= Mvt_Mouse_6 ^= Mvt_Mouse_5 ^= Mvt_Mouse_4 ^= Mvt_Mouse_3 ^= Mvt_Mouse_2 ^= Mvt_Mouse_1 ^= Z_Cat_Room_4 ^= Z_Mouse_Room_4 ^= Z_Cat_Room_3 ^= Z_Mouse_Room_3 ^= Z_Cat_Room_2 ^= Z_Mouse_Room_2 ^= 
               Z_Cat_Room_1 ^= Z_Mouse_Room_1 ^= Z_Cat_Room_0 ^= Z_Mouse_Room_0 ^= Z_Cat_Door_1 ^= Z_Cat_Door_2 ^= Z_Cat_Door_3 ^= Z_Cat_Door_4 ^= Z_Cat_Door_5 ^= Z_Cat_Door_6 ^= Z_Mouse_Door_1 ^= Z_Mouse_Door_2 ^= Z_Mouse_Door_3 ^= Z_Mouse_Door_4 ^= 
               Z_Mouse_Door_5 ^= Z_Mouse_Door_6 ^= Cat_Door_1 ^= Cat_Door_2 ^= Cat_Door_3 ^= Cat_Door_4 ^= Cat_Door_5 ^= Cat_Door_6 ^= Mouse_Door_1 ^= Mouse_Door_2 ^= Mouse_Door_3 ^= Mouse_Door_4 ^= Mouse_Door_5 ^= Mouse_Door_6 ^= Pos_Cat ^= Pos_Mouse ^= 
               Door_Cat ^= Door_Mouse ^= Pos_Cat_0 ^= Pos_Cat_1 ^= Pos_Cat_2 ^= Pos_Cat_3 ^= Pos_Cat_4 ^= Pos_Mouse_0 ^= Pos_Mouse_1 ^= Pos_Mouse_2 ^= Pos_Mouse_3 ^= Pos_Mouse_4 ^= Door_Cat_1 ^= Door_Cat_2 ^= Door_Cat_3 ^= Door_Cat_4 ^= Door_Cat_5 ^= 
               Door_Cat_6 ^= Door_Mouse_1 ^= Door_Mouse_2 ^= Door_Mouse_3 ^= Door_Mouse_4 ^= Door_Mouse_5 ^= Door_Mouse_6 ^= Conflict
             | (| CLK_435 := when Mvt_Mouse_3
                | CLK_436 := when (not Mvt_Mouse_3)
                |)
             | (| CLK_437 := when Mvt_Mouse_6
                | CLK_438 := when (not Mvt_Mouse_6)
                |)
             | (| CLK_442 := when Mvt_Mouse_1
                | CLK_443 := when (not Mvt_Mouse_1)
                |)
             | (| CLK_448 := when Mvt_Mouse_4
                | CLK_449 := when (not Mvt_Mouse_4)
                |)
             | (| CLK_458 := when Mvt_Cat_3
                | CLK_459 := when (not Mvt_Cat_3)
                |)
             | (| CLK_460 := when Mvt_Cat_6
                | CLK_461 := when (not Mvt_Cat_6)
                |)
             | (| CLK_465 := when Mvt_Cat_1
                | CLK_466 := when (not Mvt_Cat_1)
                |)
             | (| CLK_471 := when Mvt_Cat_4
                | CLK_472 := when (not Mvt_Cat_4)
                |)
             | (| CLK_481 := when Mvt_Mouse_2
                | CLK_482 := when (not Mvt_Mouse_2)
                |)
             | (| CLK_491 := when Mvt_Cat_7
                | CLK_492 := when (not Mvt_Cat_7)
                |)
             | (| CLK_494 := when Z_Cat_Room_3
                | CLK_495 := when (not Z_Cat_Room_3)
                |)
             | (| CLK_500 := when Mvt_Cat_2
                | CLK_501 := when (not Mvt_Cat_2)
                |)
             | (| CLK_506 := when Z_Cat_Room_1
                | CLK_507 := when (not Z_Cat_Room_1)
                |)
             | (| CLK_533 := when Mvt_Mouse_5
                | CLK_534 := when (not Mvt_Mouse_5)
                |)
             | (| CLK_547 := when Mvt_Cat_5
                | CLK_548 := when (not Mvt_Cat_5)
                |)
             | (| CLK_586 := when Cat_Room_0
                | CLK_587 := when (not Cat_Room_0)
                |)
             | (| CLK_593 := when Cat_Room_1
                | CLK_594 := when (not Cat_Room_1)
                |)
             | (| CLK_600 := when Cat_Room_2
                | CLK_601 := when (not Cat_Room_2)
                |)
             | (| CLK_607 := when Cat_Room_3
                | CLK_608 := when (not Cat_Room_3)
                |)
             | (| CLK_614 := when Cat_Room_4
                | CLK_615 := when (not Cat_Room_4)
                |)
             | (| CLK_631 := when Mouse_Room_0
                | CLK_632 := when (not Mouse_Room_0)
                |)
             | (| CLK_638 := when Mouse_Room_1
                | CLK_639 := when (not Mouse_Room_1)
                |)
             | (| CLK_645 := when Mouse_Room_2
                | CLK_646 := when (not Mouse_Room_2)
                |)
             | (| CLK_652 := when Mouse_Room_3
                | CLK_653 := when (not Mouse_Room_3)
                |)
             | (| CLK_659 := when Mouse_Room_4
                | CLK_660 := when (not Mouse_Room_4)
                |)
             | (| CLK_682 := when DoorState_Cat_1
                | CLK_683 := when (not DoorState_Cat_1)
                |)
             | (| CLK_689 := when DoorState_Cat_2
                | CLK_690 := when (not DoorState_Cat_2)
                |)
             | (| CLK_696 := when DoorState_Cat_3
                | CLK_697 := when (not DoorState_Cat_3)
                |)
             | (| CLK_703 := when DoorState_Cat_4
                | CLK_704 := when (not DoorState_Cat_4)
                |)
             | (| CLK_710 := when DoorState_Cat_5
                | CLK_711 := when (not DoorState_Cat_5)
                |)
             | (| CLK_717 := when DoorState_Cat_6
                | CLK_718 := when (not DoorState_Cat_6)
                |)
             | (| CLK_736 := when DoorState_Mouse_1
                | CLK_737 := when (not DoorState_Mouse_1)
                |)
             | (| CLK_743 := when DoorState_Mouse_2
                | CLK_744 := when (not DoorState_Mouse_2)
                |)
             | (| CLK_750 := when DoorState_Mouse_3
                | CLK_751 := when (not DoorState_Mouse_3)
                |)
             | (| CLK_757 := when DoorState_Mouse_4
                | CLK_758 := when (not DoorState_Mouse_4)
                |)
             | (| CLK_764 := when DoorState_Mouse_5
                | CLK_765 := when (not DoorState_Mouse_5)
                |)
             | (| CLK_771 := when DoorState_Mouse_6
                | CLK_772 := when (not DoorState_Mouse_6)
                |)
             | (| CLK_796 := when (Cat_Room_0 and Mouse_Room_0)
                | CLK_797 := when (not (Cat_Room_0 and Mouse_Room_0))
                |)
             | (| CLK_799 := when (Cat_Room_1 and Mouse_Room_1)
                | CLK_800 := when (not (Cat_Room_1 and Mouse_Room_1))
                |)
             | (| CLK_802 := when (Cat_Room_2 and Mouse_Room_2)
                | CLK_803 := when (not (Cat_Room_2 and Mouse_Room_2))
                |)
             | (| CLK_805 := when (Cat_Room_3 and Mouse_Room_3)
                | CLK_806 := when (not (Cat_Room_3 and Mouse_Room_3))
                |)
             | (| CLK_808 := when (Cat_Room_4 and Mouse_Room_4)
                | CLK_809 := when (not (Cat_Room_4 and Mouse_Room_4))
                |)
             | (| CLK_932 := when Cat_Door_1
                | CLK_933 := when (not Cat_Door_1)
                |)
             | (| CLK_942 := when Cat_Door_2
                | CLK_943 := when (not Cat_Door_2)
                |)
             | (| CLK_952 := when Cat_Door_3
                | CLK_953 := when (not Cat_Door_3)
                |)
             | (| CLK_962 := when Cat_Door_4
                | CLK_963 := when (not Cat_Door_4)
                |)
             | (| CLK_972 := when Cat_Door_6
                | CLK_973 := when (not Cat_Door_6)
                |)
             | (| CLK_982 := when Mouse_Door_2
                | CLK_983 := when (not Mouse_Door_2)
                |)
             | (| CLK_992 := when Mouse_Door_3
                | CLK_993 := when (not Mouse_Door_3)
                |)
             | (| CLK_1002 := when Mouse_Door_4
                | CLK_1003 := when (not Mouse_Door_4)
                |)
             | (| CLK_1012 := when Mouse_Door_5
                | CLK_1013 := when (not Mouse_Door_5)
                |)
             | (| CLK_1022 := when Mouse_Door_6
                | CLK_1023 := when (not Mouse_Door_6)
                |)
             | (| CLK_1033 := when (cod_y[0]=1)
                | CLK_1034 := when (not (cod_y[0]=1))
                |)
             | (| CLK_1036 := when (cod_y[0]=(-1))
                | CLK_1037 := when (not (cod_y[0]=(-1)))
                |)
             | (| CLK_1045 := when (cod_y[1]=1)
                | CLK_1046 := when (not (cod_y[1]=1))
                |)
             | (| CLK_1048 := when (cod_y[1]=(-1))
                | CLK_1049 := when (not (cod_y[1]=(-1)))
                |)
             | (| CLK_1057 := when (cod_y[2]=1)
                | CLK_1058 := when (not (cod_y[2]=1))
                |)
             | (| CLK_1060 := when (cod_y[2]=(-1))
                | CLK_1061 := when (not (cod_y[2]=(-1)))
                |)
             | (| CLK_1069 := when (cod_y[3]=1)
                | CLK_1070 := when (not (cod_y[3]=1))
                |)
             | (| CLK_1072 := when (cod_y[3]=(-1))
                | CLK_1073 := when (not (cod_y[3]=(-1)))
                |)
             | (| CLK_1081 := when (cod_y[4]=1)
                | CLK_1082 := when (not (cod_y[4]=1))
                |)
             | (| CLK_1084 := when (cod_y[4]=(-1))
                | CLK_1085 := when (not (cod_y[4]=(-1)))
                |)
             | (| CLK_1093 := when (cod_y[5]=1)
                | CLK_1094 := when (not (cod_y[5]=1))
                |)
             | (| CLK_1096 := when (cod_y[5]=(-1))
                | CLK_1097 := when (not (cod_y[5]=(-1)))
                |)
             | (| CLK_1105 := when (cod_y[6]=1)
                | CLK_1106 := when (not (cod_y[6]=1))
                |)
             | (| CLK_1108 := when (cod_y[6]=(-1))
                | CLK_1109 := when (not (cod_y[6]=(-1)))
                |)
             | (| CLK_1117 := when (cod_y[7]=1)
                | CLK_1118 := when (not (cod_y[7]=1))
                |)
             | (| CLK_1120 := when (cod_y[7]=(-1))
                | CLK_1121 := when (not (cod_y[7]=(-1)))
                |)
             | (| CLK_1129 := when (cod_y[8]=1)
                | CLK_1130 := when (not (cod_y[8]=1))
                |)
             | (| CLK_1132 := when (cod_y[8]=(-1))
                | CLK_1133 := when (not (cod_y[8]=(-1)))
                |)
             | (| CLK_1141 := when (cod_y[9]=1)
                | CLK_1142 := when (not (cod_y[9]=1))
                |)
             | (| CLK_1144 := when (cod_y[9]=(-1))
                | CLK_1145 := when (not (cod_y[9]=(-1)))
                |)
             | (| CLK_1153 := when (cod_y[10]=1)
                | CLK_1154 := when (not (cod_y[10]=1))
                |)
             | (| CLK_1156 := when (cod_y[10]=(-1))
                | CLK_1157 := when (not (cod_y[10]=(-1)))
                |)
             | (| CLK_1165 := when (cod_y[11]=1)
                | CLK_1166 := when (not (cod_y[11]=1))
                |)
             | (| CLK_1168 := when (cod_y[11]=(-1))
                | CLK_1169 := when (not (cod_y[11]=(-1)))
                |)
             | (| CLK_1177 := when (cod_y[12]=1)
                | CLK_1178 := when (not (cod_y[12]=1))
                |)
             | (| CLK_1180 := when (cod_y[12]=(-1))
                | CLK_1181 := when (not (cod_y[12]=(-1)))
                |)
             | (| CLK_1190 := when (cod_u[0]=1)
                | CLK_1191 := when (not (cod_u[0]=1))
                |)
             | (| CLK_1193 := when (cod_u[0]=(-1))
                | CLK_1194 := when (not (cod_u[0]=(-1)))
                |)
             | (| CLK_1202 := when (cod_u[1]=1)
                | CLK_1203 := when (not (cod_u[1]=1))
                |)
             | (| CLK_1205 := when (cod_u[1]=(-1))
                | CLK_1206 := when (not (cod_u[1]=(-1)))
                |)
             | (| CLK_1214 := when (cod_u[2]=1)
                | CLK_1215 := when (not (cod_u[2]=1))
                |)
             | (| CLK_1217 := when (cod_u[2]=(-1))
                | CLK_1218 := when (not (cod_u[2]=(-1)))
                |)
             | (| CLK_1226 := when (cod_u[3]=1)
                | CLK_1227 := when (not (cod_u[3]=1))
                |)
             | (| CLK_1229 := when (cod_u[3]=(-1))
                | CLK_1230 := when (not (cod_u[3]=(-1)))
                |)
             | (| CLK_1238 := when (cod_u[4]=1)
                | CLK_1239 := when (not (cod_u[4]=1))
                |)
             | (| CLK_1241 := when (cod_u[4]=(-1))
                | CLK_1242 := when (not (cod_u[4]=(-1)))
                |)
             | (| CLK_1250 := when (cod_u[5]=1)
                | CLK_1251 := when (not (cod_u[5]=1))
                |)
             | (| CLK_1253 := when (cod_u[5]=(-1))
                | CLK_1254 := when (not (cod_u[5]=(-1)))
                |)
             | (| CLK_1262 := when (cod_u[6]=1)
                | CLK_1263 := when (not (cod_u[6]=1))
                |)
             | (| CLK_1265 := when (cod_u[6]=(-1))
                | CLK_1266 := when (not (cod_u[6]=(-1)))
                |)
             | (| CLK_1274 := when (cod_u[7]=1)
                | CLK_1275 := when (not (cod_u[7]=1))
                |)
             | (| CLK_1277 := when (cod_u[7]=(-1))
                | CLK_1278 := when (not (cod_u[7]=(-1)))
                |)
             | (| CLK_1286 := when (cod_u[8]=1)
                | CLK_1287 := when (not (cod_u[8]=1))
                |)
             | (| CLK_1289 := when (cod_u[8]=(-1))
                | CLK_1290 := when (not (cod_u[8]=(-1)))
                |)
             | (| CLK_1298 := when (cod_u[9]=1)
                | CLK_1299 := when (not (cod_u[9]=1))
                |)
             | (| CLK_1301 := when (cod_u[9]=(-1))
                | CLK_1302 := when (not (cod_u[9]=(-1)))
                |)
             | (| CLK_1310 := when (cod_u[10]=1)
                | CLK_1311 := when (not (cod_u[10]=1))
                |)
             | (| CLK_1313 := when (cod_u[10]=(-1))
                | CLK_1314 := when (not (cod_u[10]=(-1)))
                |)
             | (| CLK_1322 := when (cod_u[11]=1)
                | CLK_1323 := when (not (cod_u[11]=1))
                |)
             | (| CLK_1325 := when (cod_u[11]=(-1))
                | CLK_1326 := when (not (cod_u[11]=(-1)))
                |)
             | (| CLK_1525 := CLK_1322 ^+ CLK_1325 |)
             | (| CLK_1527 := CLK_1310 ^+ CLK_1313 |)
             | (| CLK_1529 := CLK_1298 ^+ CLK_1301 |)
             | (| CLK_1531 := CLK_1286 ^+ CLK_1289 |)
             | (| CLK_1533 := CLK_1274 ^+ CLK_1277 |)
             | (| CLK_1535 := CLK_1262 ^+ CLK_1265 |)
             | (| CLK_1537 := CLK_1250 ^+ CLK_1253 |)
             | (| CLK_1539 := CLK_1238 ^+ CLK_1241 |)
             | (| CLK_1541 := CLK_1226 ^+ CLK_1229 |)
             | (| CLK_1543 := CLK_1214 ^+ CLK_1217 |)
             | (| CLK_1545 := CLK_1202 ^+ CLK_1205 |)
             | (| CLK_1547 := CLK_1190 ^+ CLK_1193 |)
             | (| CLK_1549 := CLK_1177 ^+ CLK_1180 |)
             | (| CLK_1551 := CLK_1165 ^+ CLK_1168 |)
             | (| CLK_1553 := CLK_1153 ^+ CLK_1156 |)
             | (| CLK_1555 := CLK_1141 ^+ CLK_1144 |)
             | (| CLK_1557 := CLK_1129 ^+ CLK_1132 |)
             | (| CLK_1559 := CLK_1117 ^+ CLK_1120 |)
             | (| CLK_1561 := CLK_1105 ^+ CLK_1108 |)
             | (| CLK_1563 := CLK_1093 ^+ CLK_1096 |)
             | (| CLK_1565 := CLK_1081 ^+ CLK_1084 |)
             | (| CLK_1567 := CLK_1069 ^+ CLK_1072 |)
             | (| CLK_1569 := CLK_1057 ^+ CLK_1060 |)
             | (| CLK_1571 := CLK_1045 ^+ CLK_1048 |)
             | (| CLK_1573 := CLK_1033 ^+ CLK_1036 |)
             | (| CLK_1575 := CLK_796 ^+ CLK_799 |)
             | (| CLK_1577 := CLK_1575 ^+ CLK_802 |)
             | (| CLK_1579 := CLK_1577 ^+ CLK_805 |)
             | (| CLK_1581 := CLK_1579 ^+ CLK_808 |)
             | (| CLK_1633 := CLK_435 ^+ CLK_437 |)
             | (| CLK_1635 := CLK_442 ^+ CLK_1633 |)
             | (| CLK_Inter_Mouse_Room_0 := CLK_448 ^+ CLK_1635
                | CLK_Inter_Mouse_Room_0 ^= Inter_Mouse_Room_0
                | Inter_Mouse_Room_0 := CLK_435 default CLK_1852 default (not CLK_1850) default (not CLK_1848)
                |)
             | (| CLK_1639 := CLK_458 ^+ CLK_460 |)
             | (| CLK_1641 := CLK_465 ^+ CLK_1639 |)
             | (| CLK_Inter_Cat_Room_0 := CLK_471 ^+ CLK_1641
                | CLK_Inter_Cat_Room_0 ^= Inter_Cat_Room_0
                | Inter_Cat_Room_0 := CLK_458 default CLK_1842 default (not CLK_1840) default (not CLK_1838)
                |)
             | (| CLK_Inter_Mouse_Room_2 := CLK_442 ^+ CLK_481
                | CLK_Inter_Mouse_Room_2 ^= Inter_Mouse_Room_2
                | Inter_Mouse_Room_2 := CLK_442 default (not CLK_1836)
                |)
             | (| CLK_Inter_Mouse_Room_1 := CLK_435 ^+ CLK_481
                | CLK_Inter_Mouse_Room_1 ^= Inter_Mouse_Room_1
                | Inter_Mouse_Room_1 := CLK_481 default (not CLK_1856)
                |)
             | (| CLK_1649 := CLK_491 ^* CLK_494 |)
             | (| CLK_1651 := CLK_1649 ^+ CLK_465 |)
             | (| CLK_1653 := CLK_500 ^+ CLK_1651 |)
             | (| CLK_Inter_Cat_Room_2 := CLK_458 ^+ CLK_500
                | CLK_Inter_Cat_Room_2 ^= Inter_Cat_Room_2
                | Inter_Cat_Room_2 := CLK_500 default (not CLK_1846)
                |)
             | (| CLK_1657 := CLK_506 ^+ CLK_1653 |)
             | (| CLK_1659 := CLK_491 ^* CLK_506 |)
             | (| CLK_Inter_Cat_Room_1 := CLK_1659 ^+ CLK_1653
                | CLK_Inter_Cat_Room_1 ^= Inter_Cat_Room_1
                | Inter_Cat_Room_1 := CLK_465 default CLK_1832 default (not CLK_1830) default (not CLK_1826)
                |)
             | (| CLK_1663 := CLK_1659 ^+ CLK_471 |)
             | (| CLK_1665 := CLK_1657 ^* CLK_491 |)
             | (| CLK_Inter_Mouse_Room_4 := CLK_448 ^+ CLK_533
                | CLK_Inter_Mouse_Room_4 ^= Inter_Mouse_Room_4
                | Inter_Mouse_Room_4 := CLK_448 default (not CLK_1824)
                |)
             | (| CLK_Inter_Mouse_Room_3 := CLK_437 ^+ CLK_533
                | CLK_Inter_Mouse_Room_3 ^= Inter_Mouse_Room_3
                | Inter_Mouse_Room_3 := CLK_533 default (not CLK_1854)
                |)
             | (| CLK_1671 := CLK_547 ^+ CLK_1663 |)
             | (| CLK_Inter_Cat_Room_4 := CLK_460 ^+ CLK_547
                | CLK_Inter_Cat_Room_4 ^= Inter_Cat_Room_4
                | Inter_Cat_Room_4 := CLK_547 default (not CLK_1844)
                |)
             | (| CLK_Inter_Cat_Room_3 := CLK_1671 ^+ CLK_1649
                | CLK_Inter_Cat_Room_3 ^= Inter_Cat_Room_3
                | Inter_Cat_Room_3 := CLK_471 default CLK_1828 default (not CLK_1822) default (not CLK_1834)
                |)
             | (| CLK_1677 := CLK_1671 ^+ CLK_494 |)
             | (| CLK_1679 := CLK_1677 ^* CLK_491 |)
             | (| CLK_1708 := CLK_INTERM0 ^- CLK_1525 |)
             | (| CLK_1710 := CLK_INTERM0 ^- CLK_1527 |)
             | (| CLK_1712 := CLK_INTERM0 ^- CLK_1529 |)
             | (| CLK_1714 := CLK_INTERM0 ^- CLK_1531 |)
             | (| CLK_1716 := CLK_INTERM0 ^- CLK_1533 |)
             | (| CLK_1718 := CLK_INTERM0 ^- CLK_1535 |)
             | (| CLK_1720 := CLK_INTERM0 ^- CLK_1537 |)
             | (| CLK_1722 := CLK_INTERM0 ^- CLK_1539 |)
             | (| CLK_1724 := CLK_INTERM0 ^- CLK_1541 |)
             | (| CLK_1726 := CLK_INTERM0 ^- CLK_1543 |)
             | (| CLK_1728 := CLK_INTERM0 ^- CLK_1545 |)
             | (| CLK_1730 := CLK_INTERM0 ^- CLK_1547 |)
             | (| CLK_1732 := CLK_INTERM0 ^- CLK_1549 |)
             | (| CLK_1734 := CLK_INTERM0 ^- CLK_1551 |)
             | (| CLK_1736 := CLK_INTERM0 ^- CLK_1553 |)
             | (| CLK_1738 := CLK_INTERM0 ^- CLK_1555 |)
             | (| CLK_1740 := CLK_INTERM0 ^- CLK_1557 |)
             | (| CLK_1742 := CLK_INTERM0 ^- CLK_1559 |)
             | (| CLK_1744 := CLK_INTERM0 ^- CLK_1561 |)
             | (| CLK_1746 := CLK_INTERM0 ^- CLK_1563 |)
             | (| CLK_1748 := CLK_INTERM0 ^- CLK_1565 |)
             | (| CLK_1750 := CLK_INTERM0 ^- CLK_1567 |)
             | (| CLK_1752 := CLK_INTERM0 ^- CLK_1569 |)
             | (| CLK_1754 := CLK_INTERM0 ^- CLK_1571 |)
             | (| CLK_1756 := CLK_INTERM0 ^- CLK_1573 |)
             | (| CLK_1758 := CLK_INTERM0 ^- CLK_1581 |)
             | (| CLK_1782 := CLK_INTERM0 ^- CLK_Inter_Cat_Room_4 |)
             | (| CLK_1784 := CLK_INTERM0 ^- CLK_Inter_Cat_Room_3 |)
             | (| CLK_1786 := CLK_INTERM0 ^- CLK_Inter_Cat_Room_2 |)
             | (| CLK_1788 := CLK_INTERM0 ^- CLK_Inter_Cat_Room_1 |)
             | (| CLK_1790 := CLK_INTERM0 ^- CLK_Inter_Cat_Room_0 |)
             | (| CLK_1792 := CLK_INTERM0 ^- CLK_Inter_Mouse_Room_4 |)
             | (| CLK_1794 := CLK_INTERM0 ^- CLK_Inter_Mouse_Room_3 |)
             | (| CLK_1796 := CLK_INTERM0 ^- CLK_Inter_Mouse_Room_2 |)
             | (| CLK_1798 := CLK_INTERM0 ^- CLK_Inter_Mouse_Room_1 |)
             | (| CLK_1800 := CLK_INTERM0 ^- CLK_Inter_Mouse_Room_0 |)
             | (| CLK_1822 := CLK_547 ^- CLK_1663 |)
             | (| CLK_1824 := CLK_533 ^- CLK_448 |)
             | (| CLK_1826 := CLK_1659 ^- CLK_1653 |)
             | (| CLK_1828 := CLK_1659 ^- CLK_471 |)
             | (| CLK_1830 := CLK_500 ^- CLK_1651 |)
             | (| CLK_1832 := CLK_1649 ^- CLK_465 |)
             | (| CLK_1834 := CLK_1649 ^- CLK_1671 |)
             | (| CLK_1836 := CLK_481 ^- CLK_442 |)
             | (| CLK_1838 := CLK_471 ^- CLK_1641 |)
             | (| CLK_1840 := CLK_465 ^- CLK_1639 |)
             | (| CLK_1842 := CLK_460 ^- CLK_458 |)
             | (| CLK_1844 := CLK_460 ^- CLK_547 |)
             | (| CLK_1846 := CLK_458 ^- CLK_500 |)
             | (| CLK_1848 := CLK_448 ^- CLK_1635 |)
             | (| CLK_1850 := CLK_442 ^- CLK_1633 |)
             | (| CLK_1852 := CLK_437 ^- CLK_435 |)
             | (| CLK_1854 := CLK_437 ^- CLK_533 |)
             | (| CLK_1856 := CLK_435 ^- CLK_481 |)
             | (| CLK_1875 := CLK_799 ^- CLK_796 |)
             | (| CLK_1877 := CLK_802 ^- CLK_1575 |)
             | (| CLK_1879 := CLK_805 ^- CLK_1577 |)
             | (| CLK_1881 := CLK_808 ^- CLK_1579 |)
             | (| CLK_1883 := CLK_1036 ^- CLK_1033 |)
             | (| CLK_1885 := CLK_1048 ^- CLK_1045 |)
             | (| CLK_1887 := CLK_1060 ^- CLK_1057 |)
             | (| CLK_1889 := CLK_1072 ^- CLK_1069 |)
             | (| CLK_1891 := CLK_1084 ^- CLK_1081 |)
             | (| CLK_1893 := CLK_1096 ^- CLK_1093 |)
             | (| CLK_1895 := CLK_1108 ^- CLK_1105 |)
             | (| CLK_1897 := CLK_1120 ^- CLK_1117 |)
             | (| CLK_1899 := CLK_1132 ^- CLK_1129 |)
             | (| CLK_1901 := CLK_1144 ^- CLK_1141 |)
             | (| CLK_1903 := CLK_1156 ^- CLK_1153 |)
             | (| CLK_1905 := CLK_1168 ^- CLK_1165 |)
             | (| CLK_1907 := CLK_1180 ^- CLK_1177 |)
             | (| CLK_1909 := CLK_1193 ^- CLK_1190 |)
             | (| CLK_1911 := CLK_1205 ^- CLK_1202 |)
             | (| CLK_1913 := CLK_1217 ^- CLK_1214 |)
             | (| CLK_1915 := CLK_1229 ^- CLK_1226 |)
             | (| CLK_1917 := CLK_1241 ^- CLK_1238 |)
             | (| CLK_1919 := CLK_1253 ^- CLK_1250 |)
             | (| CLK_1921 := CLK_1265 ^- CLK_1262 |)
             | (| CLK_1923 := CLK_1277 ^- CLK_1274 |)
             | (| CLK_1925 := CLK_1289 ^- CLK_1286 |)
             | (| CLK_1927 := CLK_1301 ^- CLK_1298 |)
             | (| CLK_1929 := CLK_1313 ^- CLK_1310 |)
             | (| CLK_1931 := CLK_1325 ^- CLK_1322 |)
             | (| INTERM0 := (1 when CLK_614) default (2 when CLK_615)
                | INTERM1 := (1 when CLK_659) default (2 when CLK_660)
                | INTERM2 := (1 when CLK_607) default (2 when CLK_608)
                | INTERM3 := (1 when CLK_652) default (2 when CLK_653)
                | INTERM4 := (1 when CLK_600) default (2 when CLK_601)
                | INTERM5 := (1 when CLK_645) default (2 when CLK_646)
                | INTERM6 := (1 when CLK_593) default (2 when CLK_594)
                | INTERM7 := (1 when CLK_638) default (2 when CLK_639)
                | INTERM8 := (1 when CLK_586) default (2 when CLK_587)
                | INTERM9 := (1 when CLK_631) default (2 when CLK_632)
                | INTERM10 := (1 when CLK_932) default (2 when CLK_933)
                | INTERM11 := (1 when CLK_942) default (2 when CLK_943)
                | INTERM12 := (1 when CLK_952) default (2 when CLK_953)
                | INTERM13 := (1 when CLK_962) default (2 when CLK_963)
                | INTERM14 := (1 when CLK_972) default (2 when CLK_973)
                | INTERM15 := (1 when CLK_982) default (2 when CLK_983)
                | INTERM16 := (1 when CLK_992) default (2 when CLK_993)
                | INTERM17 := (1 when CLK_1002) default (2 when CLK_1003)
                | INTERM18 := (1 when CLK_1012) default (2 when CLK_1013)
                | INTERM19 := (1 when CLK_1022) default (2 when CLK_1023)
                | cod_y := Z_S_cod_y when CLK_INTERM0
                | cod_cond := [[0]:0] when CLK_INTERM0
                | cod_x := [[0]:INTERM0,[1]:INTERM1,[2]:INTERM2,[3]:INTERM3,[4]:INTERM4,[5]:INTERM5,[6]:INTERM6,[7]:INTERM7,[8]:INTERM8,[9]:INTERM9,[10]:INTERM10,[11]:INTERM11,[12]:INTERM12,[13]:INTERM13,[14]:INTERM14,[15]:INTERM15,[16]:INTERM16,[17]:
                            INTERM17,[18]:INTERM18,[19]:INTERM19]
                | cod_u := Z_S_cod_u when CLK_INTERM0
                | Cat_Room_4 := (Inter_Cat_Room_4 when CLK_Inter_Cat_Room_4) default (Z_Cat_Room_4 when CLK_1782)
                | Cat_Room_3 := (Inter_Cat_Room_3 when CLK_Inter_Cat_Room_3) default (Z_Cat_Room_3 when CLK_1784)
                | Cat_Room_2 := (Inter_Cat_Room_2 when CLK_Inter_Cat_Room_2) default (Z_Cat_Room_2 when CLK_1786)
                | Cat_Room_1 := (Inter_Cat_Room_1 when CLK_Inter_Cat_Room_1) default (Z_Cat_Room_1 when CLK_1788)
                | Cat_Room_0 := (Inter_Cat_Room_0 when CLK_Inter_Cat_Room_0) default (Z_Cat_Room_0 when CLK_1790)
                | Mouse_Room_4 := (Inter_Mouse_Room_4 when CLK_Inter_Mouse_Room_4) default (Z_Mouse_Room_4 when CLK_1792)
                | Mouse_Room_3 := (Inter_Mouse_Room_3 when CLK_Inter_Mouse_Room_3) default (Z_Mouse_Room_3 when CLK_1794)
                | Mouse_Room_2 := (Inter_Mouse_Room_2 when CLK_Inter_Mouse_Room_2) default (Z_Mouse_Room_2 when CLK_1796)
                | Mouse_Room_1 := (Inter_Mouse_Room_1 when CLK_Inter_Mouse_Room_1) default (Z_Mouse_Room_1 when CLK_1798)
                | Mouse_Room_0 := (Inter_Mouse_Room_0 when CLK_Inter_Mouse_Room_0) default (Z_Mouse_Room_0 when CLK_1800)
                | DoorState_Cat_6 := CLK_1250 default (not CLK_1919) default (not CLK_1720)
                | DoorState_Cat_5 := CLK_1238 default (not CLK_1917) default (not CLK_1722)
                | DoorState_Cat_4 := CLK_1226 default (not CLK_1915) default (not CLK_1724)
                | DoorState_Cat_3 := CLK_1214 default (not CLK_1913) default (not CLK_1726)
                | DoorState_Cat_2 := CLK_1202 default (not CLK_1911) default (not CLK_1728)
                | DoorState_Cat_1 := CLK_1190 default (not CLK_1909) default (not CLK_1730)
                | DoorState_Mouse_6 := CLK_1322 default (not CLK_1931) default (not CLK_1708)
                | DoorState_Mouse_5 := CLK_1310 default (not CLK_1929) default (not CLK_1710)
                | DoorState_Mouse_4 := CLK_1298 default (not CLK_1927) default (not CLK_1712)
                | DoorState_Mouse_3 := CLK_1286 default (not CLK_1925) default (not CLK_1714)
                | DoorState_Mouse_2 := CLK_1274 default (not CLK_1923) default (not CLK_1716)
                | DoorState_Mouse_1 := CLK_1262 default (not CLK_1921) default (not CLK_1718)
                | Mvt_Cat_7 := CLK_1177 default (not CLK_1907) default (not CLK_1732)
                | Mvt_Cat_6 := CLK_1165 default (not CLK_1905) default (not CLK_1734)
                | Mvt_Cat_5 := CLK_1153 default (not CLK_1903) default (not CLK_1736)
                | Mvt_Cat_4 := CLK_1141 default (not CLK_1901) default (not CLK_1738)
                | Mvt_Cat_3 := CLK_1129 default (not CLK_1899) default (not CLK_1740)
                | Mvt_Cat_2 := CLK_1117 default (not CLK_1897) default (not CLK_1742)
                | Mvt_Cat_1 := CLK_1105 default (not CLK_1895) default (not CLK_1744)
                | Mvt_Mouse_6 := CLK_1093 default (not CLK_1893) default (not CLK_1746)
                | Mvt_Mouse_5 := CLK_1081 default (not CLK_1891) default (not CLK_1748)
                | Mvt_Mouse_4 := CLK_1069 default (not CLK_1889) default (not CLK_1750)
                | Mvt_Mouse_3 := CLK_1057 default (not CLK_1887) default (not CLK_1752)
                | Mvt_Mouse_2 := CLK_1045 default (not CLK_1885) default (not CLK_1754)
                | Mvt_Mouse_1 := CLK_1033 default (not CLK_1883) default (not CLK_1756)
                | Z_Cat_Room_4 := Cat_Room_4$1 init false
                | Z_Mouse_Room_4 := Mouse_Room_4$1 init true
                | Z_Cat_Room_3 := Cat_Room_3$1 init false
                | Z_Mouse_Room_3 := Mouse_Room_3$1 init false
                | Z_Cat_Room_2 := Cat_Room_2$1 init true
                | Z_Mouse_Room_2 := Mouse_Room_2$1 init false
                | Z_Cat_Room_1 := Cat_Room_1$1 init false
                | Z_Mouse_Room_1 := Mouse_Room_1$1 init false
                | Z_Cat_Room_0 := Cat_Room_0$1 init false
                | Z_Mouse_Room_0 := Mouse_Room_0$1 init false
                | Z_Cat_Door_1 := Cat_Door_1$1 init false
                | Z_Cat_Door_2 := Cat_Door_2$1 init false
                | Z_Cat_Door_3 := Cat_Door_3$1 init false
                | Z_Cat_Door_4 := Cat_Door_4$1 init false
                | Z_Cat_Door_5 := Cat_Door_5$1 init false
                | Z_Cat_Door_6 := Cat_Door_6$1 init false
                | Z_Mouse_Door_1 := Mouse_Door_1$1 init false
                | Z_Mouse_Door_2 := Mouse_Door_2$1 init false
                | Z_Mouse_Door_3 := Mouse_Door_3$1 init false
                | Z_Mouse_Door_4 := Mouse_Door_4$1 init false
                | Z_Mouse_Door_5 := Mouse_Door_5$1 init false
                | Z_Mouse_Door_6 := Mouse_Door_6$1 init false
                | Cat_Door_1 := DoorState_Cat_1
                | Cat_Door_2 := DoorState_Cat_2
                | Cat_Door_3 := DoorState_Cat_3
                | Cat_Door_4 := DoorState_Cat_4
                | Cat_Door_5 := DoorState_Cat_5
                | Cat_Door_6 := DoorState_Cat_6
                | Mouse_Door_1 := DoorState_Mouse_1
                | Mouse_Door_2 := DoorState_Mouse_2
                | Mouse_Door_3 := DoorState_Mouse_3
                | Mouse_Door_4 := DoorState_Mouse_4
                | Mouse_Door_5 := DoorState_Mouse_5
                | Mouse_Door_6 := DoorState_Mouse_6
                | Pos_Cat := [[0]:1,[1]:Pos_Cat_0,[2]:Pos_Cat_1,[3]:Pos_Cat_2,[4]:Pos_Cat_3,[5]:Pos_Cat_4]
                | Pos_Mouse := [[0]:1,[1]:Pos_Mouse_0,[2]:Pos_Mouse_1,[3]:Pos_Mouse_2,[4]:Pos_Mouse_3,[5]:Pos_Mouse_4]
                | Door_Cat := [[0]:1,[1]:Door_Cat_1,[2]:Door_Cat_2,[3]:Door_Cat_3,[4]:Door_Cat_4,[5]:Door_Cat_5,[6]:Door_Cat_6]
                | Door_Mouse := [[0]:1,[1]:Door_Mouse_1,[2]:Door_Mouse_2,[3]:Door_Mouse_3,[4]:Door_Mouse_4,[5]:Door_Mouse_5,[6]:Door_Mouse_6]
                | Pos_Cat_0 := (1 when CLK_586) default (0 when CLK_587)
                | Pos_Cat_1 := (1 when CLK_593) default (0 when CLK_594)
                | Pos_Cat_2 := (1 when CLK_600) default (0 when CLK_601)
                | Pos_Cat_3 := (1 when CLK_607) default (0 when CLK_608)
                | Pos_Cat_4 := (1 when CLK_614) default (0 when CLK_615)
                | Pos_Mouse_0 := (1 when CLK_631) default (0 when CLK_632)
                | Pos_Mouse_1 := (1 when CLK_638) default (0 when CLK_639)
                | Pos_Mouse_2 := (1 when CLK_645) default (0 when CLK_646)
                | Pos_Mouse_3 := (1 when CLK_652) default (0 when CLK_653)
                | Pos_Mouse_4 := (1 when CLK_659) default (0 when CLK_660)
                | Draw_Cat(Pos_Cat)
                | Draw_Mouse(Pos_Mouse)
                | Door_Cat_1 := (1 when CLK_682) default (0 when CLK_683)
                | Door_Cat_2 := (1 when CLK_689) default (0 when CLK_690)
                | Door_Cat_3 := (1 when CLK_696) default (0 when CLK_697)
                | Door_Cat_4 := (1 when CLK_703) default (0 when CLK_704)
                | Door_Cat_5 := (1 when CLK_710) default (0 when CLK_711)
                | Door_Cat_6 := (1 when CLK_717) default (0 when CLK_718)
                | Door_Mouse_1 := (1 when CLK_736) default (0 when CLK_737)
                | Door_Mouse_2 := (1 when CLK_743) default (0 when CLK_744)
                | Door_Mouse_3 := (1 when CLK_750) default (0 when CLK_751)
                | Door_Mouse_4 := (1 when CLK_757) default (0 when CLK_758)
                | Door_Mouse_5 := (1 when CLK_764) default (0 when CLK_765)
                | Door_Mouse_6 := (1 when CLK_771) default (0 when CLK_772)
                | Draw_Door_Cat(Door_Cat)
                | Draw_Door_Mouse(Door_Mouse)
                | Conflict := (1 when CLK_796) default (1 when CLK_1875) default (1 when CLK_1877) default (1 when CLK_1879) default (1 when CLK_1881) default (0 when CLK_1758)
                | Draw_Conflict(Conflict)
                |)
             |)
            where 
            event CLK_1931, CLK_1929, CLK_1927, CLK_1925, CLK_1923, CLK_1921, CLK_1919, CLK_1917, CLK_1915, CLK_1913, CLK_1911, CLK_1909, CLK_1907, CLK_1905, CLK_1903, CLK_1901, CLK_1899, CLK_1897, CLK_1895, CLK_1893, CLK_1891, CLK_1889, CLK_1887, 
                 CLK_1885, CLK_1883, CLK_1881, CLK_1879, CLK_1877, CLK_1875, CLK_1856, CLK_1854, CLK_1852, CLK_1850, CLK_1848, CLK_1846, CLK_1844, CLK_1842, CLK_1840, CLK_1838, CLK_1836, CLK_1834, CLK_1832, CLK_1830, CLK_1828, CLK_1826, CLK_1824, CLK_1822,
                 CLK_1800, CLK_1798, CLK_1796, CLK_1794, CLK_1792, CLK_1790, CLK_1788, CLK_1786, CLK_1784, CLK_1782, CLK_1758, CLK_1756, CLK_1754, CLK_1752, CLK_1750, CLK_1748, CLK_1746, CLK_1744, CLK_1742, CLK_1740, CLK_1738, CLK_1736, CLK_1734, CLK_1732,
                 CLK_1730, CLK_1728, CLK_1726, CLK_1724, CLK_1722, CLK_1720, CLK_1718, CLK_1716, CLK_1714, CLK_1712, CLK_1710, CLK_1708, CLK_1679, CLK_1677, CLK_Inter_Cat_Room_3, CLK_Inter_Cat_Room_4, CLK_1671, CLK_Inter_Mouse_Room_3, 
                 CLK_Inter_Mouse_Room_4, CLK_1665, CLK_1663, CLK_Inter_Cat_Room_1, CLK_1659, CLK_1657, CLK_Inter_Cat_Room_2, CLK_1653, CLK_1651, CLK_1649, CLK_Inter_Mouse_Room_1, CLK_Inter_Mouse_Room_2, CLK_Inter_Cat_Room_0, CLK_1641, CLK_1639, 
                 CLK_Inter_Mouse_Room_0, CLK_1635, CLK_1633, CLK_1581, CLK_1579, CLK_1577, CLK_1575, CLK_1573, CLK_1571, CLK_1569, CLK_1567, CLK_1565, CLK_1563, CLK_1561, CLK_1559, CLK_1557, CLK_1555, CLK_1553, CLK_1551, CLK_1549, CLK_1547, CLK_1545, 
                 CLK_1543, CLK_1541, CLK_1539, CLK_1537, CLK_1535, CLK_1533, CLK_1531, CLK_1529, CLK_1527, CLK_1525, CLK_1326, CLK_1325, CLK_1323, CLK_1322, CLK_1314, CLK_1313, CLK_1311, CLK_1310, CLK_1302, CLK_1301, CLK_1299, CLK_1298, CLK_1290, CLK_1289,
                 CLK_1287, CLK_1286, CLK_1278, CLK_1277, CLK_1275, CLK_1274, CLK_1266, CLK_1265, CLK_1263, CLK_1262, CLK_1254, CLK_1253, CLK_1251, CLK_1250, CLK_1242, CLK_1241, CLK_1239, CLK_1238, CLK_1230, CLK_1229, CLK_1227, CLK_1226, CLK_1218, CLK_1217,
                 CLK_1215, CLK_1214, CLK_1206, CLK_1205, CLK_1203, CLK_1202, CLK_1194, CLK_1193, CLK_1191, CLK_1190, CLK_1181, CLK_1180, CLK_1178, CLK_1177, CLK_1169, CLK_1168, CLK_1166, CLK_1165, CLK_1157, CLK_1156, CLK_1154, CLK_1153, CLK_1145, CLK_1144,
                 CLK_1142, CLK_1141, CLK_1133, CLK_1132, CLK_1130, CLK_1129, CLK_1121, CLK_1120, CLK_1118, CLK_1117, CLK_1109, CLK_1108, CLK_1106, CLK_1105, CLK_1097, CLK_1096, CLK_1094, CLK_1093, CLK_1085, CLK_1084, CLK_1082, CLK_1081, CLK_1073, CLK_1072,
                 CLK_1070, CLK_1069, CLK_1061, CLK_1060, CLK_1058, CLK_1057, CLK_1049, CLK_1048, CLK_1046, CLK_1045, CLK_1037, CLK_1036, CLK_1034, CLK_1033, CLK_1023, CLK_1022, CLK_1013, CLK_1012, CLK_1003, CLK_1002, CLK_993, CLK_992, CLK_983, CLK_982, 
                 CLK_973, CLK_972, CLK_963, CLK_962, CLK_953, CLK_952, CLK_943, CLK_942, CLK_933, CLK_932, CLK_809, CLK_808, CLK_806, CLK_805, CLK_803, CLK_802, CLK_800, CLK_799, CLK_797, CLK_796, CLK_772, CLK_771, CLK_765, CLK_764, CLK_758, CLK_757, 
                 CLK_751, CLK_750, CLK_744, CLK_743, CLK_737, CLK_736, CLK_718, CLK_717, CLK_711, CLK_710, CLK_704, CLK_703, CLK_697, CLK_696, CLK_690, CLK_689, CLK_683, CLK_682, CLK_660, CLK_659, CLK_653, CLK_652, CLK_646, CLK_645, CLK_639, CLK_638, 
                 CLK_632, CLK_631, CLK_615, CLK_614, CLK_608, CLK_607, CLK_601, CLK_600, CLK_594, CLK_593, CLK_587, CLK_586, CLK_548, CLK_547, CLK_534, CLK_533, CLK_507, CLK_506, CLK_501, CLK_500, CLK_495, CLK_494, CLK_492, CLK_491, CLK_482, CLK_481, 
                 CLK_472, CLK_471, CLK_466, CLK_465, CLK_461, CLK_460, CLK_459, CLK_458, CLK_449, CLK_448, CLK_443, CLK_442, CLK_438, CLK_437, CLK_436, CLK_435;
            integer INTERM0, INTERM1, INTERM2, INTERM3, INTERM4, INTERM5, INTERM6, INTERM7, INTERM8, INTERM9, INTERM10, INTERM11, INTERM12, INTERM13, INTERM14, INTERM15, INTERM16, INTERM17, INTERM18, INTERM19;
            [13]integer cod_y;
            [12]integer cod_u;
            boolean Cat_Room_4, Cat_Room_3, Cat_Room_2, Cat_Room_1, Cat_Room_0, Mouse_Room_4, Mouse_Room_3, Mouse_Room_2, Mouse_Room_1, Mouse_Room_0, DoorState_Cat_6, DoorState_Cat_5, DoorState_Cat_4, DoorState_Cat_3, DoorState_Cat_2, DoorState_Cat_1, 
                   DoorState_Mouse_6, DoorState_Mouse_5, DoorState_Mouse_4, DoorState_Mouse_3, DoorState_Mouse_2, DoorState_Mouse_1, Mvt_Cat_7, Mvt_Cat_6, Mvt_Cat_5, Mvt_Cat_4, Mvt_Cat_3, Mvt_Cat_2, Mvt_Cat_1, Mvt_Mouse_6, Mvt_Mouse_5, Mvt_Mouse_4, 
                   Mvt_Mouse_3, Mvt_Mouse_2, Mvt_Mouse_1, Z_Cat_Room_4, Z_Mouse_Room_4, Z_Cat_Room_3, Z_Mouse_Room_3, Z_Cat_Room_2, Z_Mouse_Room_2, Z_Cat_Room_1, Z_Mouse_Room_1, Z_Cat_Room_0, Z_Mouse_Room_0, Z_Cat_Door_1, Z_Cat_Door_2, Z_Cat_Door_3, 
                   Z_Cat_Door_4, Z_Cat_Door_5, Z_Cat_Door_6, Z_Mouse_Door_1, Z_Mouse_Door_2, Z_Mouse_Door_3, Z_Mouse_Door_4, Z_Mouse_Door_5, Z_Mouse_Door_6, Cat_Door_1, Cat_Door_2, Cat_Door_3, Cat_Door_4, Cat_Door_5, Cat_Door_6, Mouse_Door_1, 
                   Mouse_Door_2, Mouse_Door_3, Mouse_Door_4, Mouse_Door_5, Mouse_Door_6, Inter_Cat_Room_0, Inter_Cat_Room_1, Inter_Cat_Room_3, Inter_Cat_Room_4, Inter_Cat_Room_2, Inter_Mouse_Room_0, Inter_Mouse_Room_1, Inter_Mouse_Room_2, 
                   Inter_Mouse_Room_3, Inter_Mouse_Room_4;
            [6]integer Pos_Cat, Pos_Mouse;
            [7]integer Door_Cat, Door_Mouse;
            integer Pos_Cat_0, Pos_Cat_1, Pos_Cat_2, Pos_Cat_3, Pos_Cat_4, Pos_Mouse_0, Pos_Mouse_1, Pos_Mouse_2, Pos_Mouse_3, Pos_Mouse_4, Door_Cat_1, Door_Cat_2, Door_Cat_3, Door_Cat_4, Door_Cat_5, Door_Cat_6, Door_Mouse_1, Door_Mouse_2, Door_Mouse_3, 
                   Door_Mouse_4, Door_Mouse_5, Door_Mouse_6, Conflict;
            end
         %ACT_CLK_INTERM0%; 
         end
      %ACT_CLK_z_b%; 
      end
   %ACT_HE%; 
   process GET_PACE_RHYTHM =
        ( ! integer DESCR;
            integer PI_0;
        )
        spec (| DESCR ^= PI_0 |)
   
   %GET_PACE_RHYTHM%; 
   process WSTOP =
        ( ? event DOWN;
        )
   
   %WSTOP%; 
   process RSTOP =
        ( ! boolean STOP;
        )
   
   %RSTOP%; 
   process RUPDOWN =
        ( ? integer ADRCOUNT;
          ! boolean UPDOWN;
        )
        spec (| ADRCOUNT ^= UPDOWN |)
   
   %RUPDOWN%; 
   process WIWRITE =
        ( ? integer ADR_COUNT;
            integer V;
        )
        spec (| ADR_COUNT ^= V |)
   
   %WIWRITE%; 
   process RESET_PANEL =
        ( ? boolean AUTO;
        )
   
   %RESET_PANEL%; 
   process Draw_Cat =
        ( ? [6]integer Pos_Cat;
        )
   
   %Draw_Cat%; 
   process Draw_Mouse =
        ( ? [6]integer Pos_Mouse;
        )
   
   %Draw_Mouse%; 
   process Draw_Door_Cat =
        ( ? [7]integer Door_Cat;
        )
   
   %Draw_Door_Cat%; 
   process Draw_Door_Mouse =
        ( ? [7]integer Door_Mouse;
        )
   
   %Draw_Door_Mouse%; 
   process Draw_Conflict =
        ( ? integer Conflict;
        )
   
   %Draw_Conflict%; 
   process resolver =
        ( ? [ncond]integer S_cod_cond;
            [nx]integer S_cod_x;
          ! [nu]integer S_cod_u;
            [ny]integer S_cod_y;
            boolean fin_resolver;
        )
        spec (| S_cod_cond ^= S_cod_x ^= S_cod_u ^= S_cod_y ^= fin_resolver |)
   
   %resolver%; 
   process RTICK =
        ( ! boolean TICK;
        )
   
   %RTICK%; 
   process RAUTO =
        ( ! boolean AUTO;
        )
   
   %RAUTO%; 
   process RCHANGE =
        ( ? integer ADRCOUNT;
          ! integer CODE;
        )
        spec (| ADRCOUNT ^= CODE |)
   
   %RCHANGE%; 
   end
%vt_TRA%; 

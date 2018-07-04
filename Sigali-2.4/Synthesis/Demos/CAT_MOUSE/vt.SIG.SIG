process vt =
     { integer N, NUL_CODE, LIN_CODE; }
     ( ? event HE;
     )
   (| (| (| CONTEXT{N,NUL_CODE,LIN_CODE} |)/ H_0
       | VT_Cat_and_Mouse{}
       |)/ TTick |)
   where 
   process CONTEXT =
        { integer N, NUL_CODE, LIN_CODE; }
        ( ? event HE;
          ! event H_0;
            event TTick;
        )
      (| (| S_PACE_MAKER{NUL_CODE,LIN_CODE}
          | TTick := HES
          |) where event HES; end |)
      where 
      process SCAN =
           { integer N; }
           ( ? event H;
             ! boolean CLICK;
           )
         (| CLICK := GETSIG{}(H,RCLICK()) |)
         where 
         process GETSIG =
              ( ? event H;
                  boolean V_ON;
                  boolean C_ON;
                ! event ON;
              )
            (| H ^= C_ON ^= V_ON
             | ON := V_ON when C_ON
             |)
         ; 
         process RCLICK =
              ( ! boolean V_CLICK;
                  boolean present;
              )
              spec (| V_CLICK ^= present |)
         
         ; 
         end
      ; 
      process S_PACE_MAKER =
           { integer NUL_CODE, LIN_CODE; }
           ( ? event HE;
             ! event HES;
               event H_0;
           )
         (| (| (| HW := ^NEW_BOUND
                | WIWRITE(ADR_COUNT when HW,NEW_BOUND)
                |)/ HW
             | (| SCAN{NUL_CODE,LIN_CODE}
                | HS_1 := HS
                |) where event HS; end
             | (| HE := HS_1
                | PACE_MAKER{}
                | HS_2 := HS
                |) where event HE, HS; end
             | (| HSP := HS_2
                | HES := HSP default TICK
                |) where event HSP; end
             |)/ HS_2, NEW_BOUND, TICK, HS_1, C_UP_DOWN, C_LIN_EXP, PI_0, ADR_COUNT |)
         where 
         process SCAN =
              { integer NUL_CODE, LIN_CODE; }
              ( ? event HE;
                ! integer PI_0;
                  event H_0;
                  integer ADR_COUNT;
                  event TICK;
                  event HS;
                  boolean C_LIN_EXP;
                  boolean C_UP_DOWN;
              )
            (| (| INIT_PACE{}
                | (| HINIT := H_0
                   | MODE_INPUT{}
                   |) where event HINIT; end
                | PERIOD_INPUT{NUL_CODE,LIN_CODE}
                | (| DOWN := STOP
                   | WSTOP{}
                   |) where event DOWN; end
                | RESET_PANEL{}
                |)/ AUTO, STOP |)
            where 
            process MODE_INPUT =
                 ( ? event HE;
                     event HINIT;
                   ! event TICK;
                     boolean AUTO;
                     event HS;
                     event STOP;
                 )
               (| (| (| C_TICK ^= HE
                      | C_TICK := RTICK{}()
                      | TICK := when C_TICK
                      |)/ C_TICK
                   | (| (| C_SW_AUTO ^= HE
                         | C_SW_AUTO := RAUTO{}()
                         | NEXTAUTO ^= HINIT default (when C_SW_AUTO)
                         | NEXTAUTO := not ZAUTO
                         | ZAUTO := NEXTAUTO$1
                         | AUTOMOD := NEXTAUTO cell HE
                         | HS := HE when AUTOMOD
                         |)
                      | AUTO := NEXTAUTO
                      |) where boolean NEXTAUTO; end/ C_SW_AUTO
                                             / ZAUTO
                   | (| C_STOP ^= when (not AUTOMOD)
                      | C_STOP := RSTOP{}()
                      | STOP := when C_STOP
                      |)/ C_STOP
                   |)/ AUTOMOD |)
               where 
               process RAUTO =
                    ( ! boolean AUTO;
                    )
               
               ; 
               process RTICK =
                    ( ! boolean TICK;
                    )
               
               ; 
               process RSTOP =
                    ( ! boolean STOP;
                    )
               
               ; 
               boolean C_TICK, C_SW_AUTO, ZAUTO init true, AUTOMOD init true, C_STOP;
               end
            ; 
            process RESET_PANEL =
                 ( ? boolean AUTO;
                 )
            
            ; 
            process WSTOP =
                 ( ? event DOWN;
                 )
            
            ; 
            process INIT_PACE =
                 ( ? event HE;
                   ! event H_0;
                     integer PI_0;
                     integer ADR_COUNT;
                 )
               (| CINIT := NCINIT$1
                | NCINIT := not HE
                | H_0 := when CINIT
                | DESCR ^= H_0
                | GET_PACE_RHYTHM{}()
                | ADR_COUNT := DESCR cell HE
                |)
               where 
               boolean CINIT init true, NCINIT;
               integer DESCR;
               process GET_PACE_RHYTHM =
                    ( ! integer DESCR;
                        integer PI_0;
                    )
                    spec (| DESCR ^= PI_0 |)
               
               ; 
               end
            ; 
            event STOP;
            boolean AUTO;
            end
         ; 
         event HW, HS_1, HS, TICK, HS_2;
         integer ADR_COUNT, PI_0, NEW_BOUND;
         boolean C_LIN_EXP, C_UP_DOWN;
         end
      ; 
      process PACE_MAKER =
           ( ? boolean C_UP_DOWN;
               boolean C_LIN_EXP;
               integer PI_0;
               event HE;
             ! integer NEW_BOUND;
               event HS;
           )
         (| HS := DYN_EVERY{0,1,1}(0 when HE,NEW_BOUND,HE)
          | SET_BOUND{}
          |)
         where 
         process SET_BOUND =
              ( ? boolean C_UP_DOWN;
                  boolean C_LIN_EXP;
                  integer PI_0;
                ! integer NEW_BOUND;
              )
            (| (| OLD_BOUND := NEW_BOUND$1
                | (| LINEAR{}(C_UP_DOWN when C_LIN_EXP,OLD_BOUND when C_LIN_EXP)
                   | NEW_BOUND_1 := NEW_BOUND
                   |) where integer NEW_BOUND; end
                | (| EXPONENTIAL{}(C_UP_DOWN when (not C_LIN_EXP),OLD_BOUND when (not C_LIN_EXP))
                   | NEW_BOUND_2 := NEW_BOUND
                   |) where integer NEW_BOUND; end
                | (| NEW_EXP := NEW_BOUND_2
                   | NEW_LIN := NEW_BOUND_1
                   | (| NEW_BOUND ^= (^C_LIN_EXP) default (^PI_0)
                      | NEW_BOUND := PI_0 default NEW_LIN default NEW_EXP default OLD_BOUND
                      |)
                   |) where integer NEW_LIN, NEW_EXP; end
                |)/ NEW_BOUND_2, NEW_BOUND_1, OLD_BOUND |)
            where 
            process EXPONENTIAL =
                 ( ? boolean C_UP_DOWN;
                     integer OLD_BOUND;
                   ! integer NEW_BOUND;
                 )
               (| VD := (OLD_BOUND+OLD_BOUND) when (not C_UP_DOWN)
                | VU := (OLD_BOUND/2) when (OLD_BOUND>1) when C_UP_DOWN
                | NEW_BOUND := VU default (VD when (VD>0))
                |)
               where 
               integer VD, VU;
               end
            ; 
            process LINEAR =
                 ( ? boolean C_UP_DOWN;
                     integer OLD_BOUND;
                   ! integer NEW_BOUND;
                 )
               (| DELTA := ((OLD_BOUND/16) when (OLD_BOUND>=16)) default (1 when (^OLD_BOUND))
                | VD := (OLD_BOUND+DELTA) when (not C_UP_DOWN)
                | VU := (OLD_BOUND-DELTA) when (OLD_BOUND>1) when C_UP_DOWN
                | NEW_BOUND := VU default (VD when (VD>0))
                |)
               where 
               integer DELTA, VD, VU;
               end
            ; 
            integer OLD_BOUND init 1, NEW_BOUND_1, NEW_BOUND_2;
            end
         ; 
         end
      ; 
      process PERIOD_INPUT =
           { integer NUL_CODE, LIN_CODE; }
           ( ? event HE;
               integer ADR_COUNT;
             ! boolean C_UP_DOWN;
               boolean C_LIN_EXP;
           )
         (| CODE_CHANGE := RCHANGE{}(ADR_COUNT when HE)
          | C_LIN_EXP := (CODE_CHANGE=LIN_CODE) when (CODE_CHANGE/=NUL_CODE)
          | C_UP_DOWN := RUPDOWN{}(ADR_COUNT when (^C_LIN_EXP))
          |)
         where 
         integer CODE_CHANGE;
         process RUPDOWN =
              ( ? integer ADRCOUNT;
                ! boolean UPDOWN;
              )
              spec (| ADRCOUNT ^= UPDOWN |)
         
         ; 
         process RCHANGE =
              ( ? integer ADRCOUNT;
                ! integer CODE;
              )
              spec (| ADRCOUNT ^= CODE |)
         
         ; 
         end
      ; 
      process WIWRITE =
           ( ? integer ADR_COUNT;
               integer V;
           )
           spec (| ADR_COUNT ^= V |)
      
      ; 
      process DYN_EVERY =
           { integer PHY_0, PI_0, V_0; }
           ( ? integer PHY;
               integer PERIOD;
               event HE;
             ! event HS;
           )
         (| MAX1 := ((0 when (PERIOD<=1)) default (PERIOD-1)) cell HE
          | MAX := MAX1 when HE
          | CPHY1 := ((0 when (PHY<0)) default PHY) cell HE
          | CPHY := CPHY1 when HE
          | ZV := V$1
          | V := (0 when (ZV>=MAX)) default (ZV+1)
          | HS := when (V=CPHY)
          |)
         where 
         integer MAX1 init PI_0-1, MAX, CPHY1 init PHY_0, CPHY, ZV init V_0, V;
         end
      ; 
      end
   ; 
   process VT_Cat_and_Mouse =
        ( ? event TTick;
        )
      (| Model_Cat_and_Mouse{}
       | Drawing{}
       | Drawing_Conflict{}
       | cod_x := [[0] : INTERM0,[1] : INTERM1,[2] : INTERM2,[3] : INTERM3,[4] : INTERM4,[5] : INTERM5,[6] : INTERM6,[7] : INTERM7,[8] : INTERM8,[9] : INTERM9,[10] : INTERM10,[11] : INTERM11,[12] : INTERM12,[13] : INTERM13,[14] : INTERM14,[15] : INTERM15,[
                                             16] : INTERM16,[17] : INTERM17,[18] : INTERM18,[19] : INTERM19]
       | INTERM0 := (1 when Cat_Room_4) default (2 when (not Cat_Room_4)) default (0 when Tick)
       | INTERM1 := (1 when Mouse_Room_4) default (2 when (not Mouse_Room_4)) default (0 when Tick)
       | INTERM2 := (1 when Cat_Room_3) default (2 when (not Cat_Room_3)) default (0 when Tick)
       | INTERM3 := (1 when Mouse_Room_3) default (2 when (not Mouse_Room_3)) default (0 when Tick)
       | INTERM4 := (1 when Cat_Room_2) default (2 when (not Cat_Room_2)) default (0 when Tick)
       | INTERM5 := (1 when Mouse_Room_2) default (2 when (not Mouse_Room_2)) default (0 when Tick)
       | INTERM6 := (1 when Cat_Room_1) default (2 when (not Cat_Room_1)) default (0 when Tick)
       | INTERM7 := (1 when Mouse_Room_1) default (2 when (not Mouse_Room_1)) default (0 when Tick)
       | INTERM8 := (1 when Cat_Room_0) default (2 when (not Cat_Room_0)) default (0 when Tick)
       | INTERM9 := (1 when Mouse_Room_0) default (2 when (not Mouse_Room_0)) default (0 when Tick)
       | INTERM10 := (1 when states_1) default (2 when (not states_1)) default (0 when Tick)
       | INTERM11 := (1 when states_2) default (2 when (not states_2)) default (0 when Tick)
       | INTERM12 := (1 when states_3) default (2 when (not states_3)) default (0 when Tick)
       | INTERM13 := (1 when states_4) default (2 when (not states_4)) default (0 when Tick)
       | INTERM14 := (1 when states_6) default (2 when (not states_6)) default (0 when Tick)
       | INTERM15 := (1 when states_8) default (2 when (not states_8)) default (0 when Tick)
       | INTERM16 := (1 when states_9) default (2 when (not states_9)) default (0 when Tick)
       | INTERM17 := (1 when states_10) default (2 when (not states_10)) default (0 when Tick)
       | INTERM18 := (1 when states_11) default (2 when (not states_11)) default (0 when Tick)
       | INTERM19 := (1 when states_12) default (2 when (not states_12)) default (0 when Tick)
       | Mvt_Mouse_1 := (true when (cod_y[0]=1)) default (false when (cod_y[0]=(-1))) default false
       | Mvt_Mouse_2 := (true when (cod_y[1]=1)) default (false when (cod_y[1]=(-1))) default false
       | Mvt_Mouse_3 := (true when (cod_y[2]=1)) default (false when (cod_y[2]=(-1))) default false
       | Mvt_Mouse_4 := (true when (cod_y[3]=1)) default (false when (cod_y[3]=(-1))) default false
       | Mvt_Mouse_5 := (true when (cod_y[4]=1)) default (false when (cod_y[4]=(-1))) default false
       | Mvt_Mouse_6 := (true when (cod_y[5]=1)) default (false when (cod_y[5]=(-1))) default false
       | Mvt_Cat_1 := (true when (cod_y[6]=1)) default (false when (cod_y[6]=(-1))) default false
       | Mvt_Cat_2 := (true when (cod_y[7]=1)) default (false when (cod_y[7]=(-1))) default false
       | Mvt_Cat_3 := (true when (cod_y[8]=1)) default (false when (cod_y[8]=(-1))) default false
       | Mvt_Cat_4 := (true when (cod_y[9]=1)) default (false when (cod_y[9]=(-1))) default false
       | Mvt_Cat_5 := (true when (cod_y[10]=1)) default (false when (cod_y[10]=(-1))) default false
       | Mvt_Cat_6 := (true when (cod_y[11]=1)) default (false when (cod_y[11]=(-1))) default false
       | Mvt_Cat_7 := (true when (cod_y[12]=1)) default (false when (cod_y[12]=(-1))) default false
       | DoorState_Cat_1 := (true when (cod_u[0]=1)) default (false when (cod_u[0]=(-1))) default false
       | DoorState_Cat_2 := (true when (cod_u[1]=1)) default (false when (cod_u[1]=(-1))) default false
       | DoorState_Cat_3 := (true when (cod_u[2]=1)) default (false when (cod_u[2]=(-1))) default false
       | DoorState_Cat_4 := (true when (cod_u[3]=1)) default (false when (cod_u[3]=(-1))) default false
       | DoorState_Cat_5 := (true when (cod_u[4]=1)) default (false when (cod_u[4]=(-1))) default false
       | DoorState_Cat_6 := (true when (cod_u[5]=1)) default (false when (cod_u[5]=(-1))) default false
       | DoorState_Mouse_1 := (true when (cod_u[6]=1)) default (false when (cod_u[6]=(-1))) default false
       | DoorState_Mouse_2 := (true when (cod_u[7]=1)) default (false when (cod_u[7]=(-1))) default false
       | DoorState_Mouse_3 := (true when (cod_u[8]=1)) default (false when (cod_u[8]=(-1))) default false
       | DoorState_Mouse_4 := (true when (cod_u[9]=1)) default (false when (cod_u[9]=(-1))) default false
       | DoorState_Mouse_5 := (true when (cod_u[10]=1)) default (false when (cod_u[10]=(-1))) default false
       | DoorState_Mouse_6 := (true when (cod_u[11]=1)) default (false when (cod_u[11]=(-1))) default false
       | DoorState_Cat_1 ^= DoorState_Cat_2 ^= DoorState_Cat_3 ^= DoorState_Cat_4 ^= DoorState_Cat_5 ^= DoorState_Cat_6 ^= DoorState_Mouse_1 ^= DoorState_Mouse_2 ^= DoorState_Mouse_3 ^= DoorState_Mouse_4 ^= DoorState_Mouse_5 ^= DoorState_Mouse_6 ^= Tick
       | Mvt_Mouse_1 ^= Mvt_Mouse_2 ^= Mvt_Mouse_3 ^= Mvt_Mouse_4 ^= Mvt_Mouse_5 ^= Mvt_Mouse_6 ^= Mvt_Cat_1 ^= Mvt_Cat_2 ^= Mvt_Cat_3 ^= Mvt_Cat_4 ^= Mvt_Cat_5 ^= Mvt_Cat_6 ^= Mvt_Cat_7 ^= Tick
       | cod_cond := [[0] : 0 when Tick]
       | RESOLVER{1,20,12,13}
       |)
      where 
      integer INTERM0, INTERM1, INTERM2, INTERM3, INTERM4, INTERM5, INTERM6, INTERM7, INTERM8, INTERM9, INTERM10, INTERM11, INTERM12, INTERM13, INTERM14, INTERM15, INTERM16, INTERM17, INTERM18, INTERM19;
      [13]integer cod_y;
      [1]integer cod_cond;
      [20]integer cod_x;
      [12]integer cod_u;
      boolean Mouse_Door_6;
      boolean Mouse_Door_5;
      boolean Mouse_Door_4;
      boolean Mouse_Door_3;
      boolean Mouse_Door_2;
      boolean Mouse_Door_1;
      boolean Cat_Door_6;
      boolean Cat_Door_5;
      boolean Cat_Door_4;
      boolean Cat_Door_3;
      boolean Cat_Door_2;
      boolean Cat_Door_1;
      boolean Cat_Room_4;
      boolean Cat_Room_3;
      boolean Cat_Room_2;
      boolean Cat_Room_1;
      boolean Cat_Room_0;
      boolean Mouse_Room_4;
      boolean Mouse_Room_3;
      boolean Mouse_Room_2;
      boolean Mouse_Room_1;
      boolean Mouse_Room_0;
      boolean DoorState_Cat_6;
      boolean DoorState_Cat_5;
      boolean DoorState_Cat_4;
      boolean DoorState_Cat_3;
      boolean DoorState_Cat_2;
      boolean DoorState_Cat_1;
      boolean DoorState_Mouse_6;
      boolean DoorState_Mouse_5;
      boolean DoorState_Mouse_4;
      boolean DoorState_Mouse_3;
      boolean DoorState_Mouse_2;
      boolean DoorState_Mouse_1;
      boolean Mvt_Cat_7;
      boolean Mvt_Cat_6;
      boolean Mvt_Cat_5;
      boolean Mvt_Cat_4;
      boolean Mvt_Cat_3;
      boolean Mvt_Cat_2;
      boolean Mvt_Cat_1;
      boolean Mvt_Mouse_6;
      boolean Mvt_Mouse_5;
      boolean Mvt_Mouse_4;
      boolean Mvt_Mouse_3;
      boolean Mvt_Mouse_2;
      boolean Mvt_Mouse_1;
      event Tick;
      boolean states_1;
      boolean states_2;
      boolean states_3;
      boolean states_4;
      boolean states_5;
      boolean states_6;
      boolean states_7;
      boolean states_8;
      boolean states_9;
      boolean states_10;
      boolean states_11;
      boolean states_12;
      process Model_Cat_and_Mouse =
           ( ? boolean Mvt_Mouse_1;
               boolean Mvt_Mouse_2;
               boolean Mvt_Mouse_3;
               boolean Mvt_Mouse_4;
               boolean Mvt_Mouse_5;
               boolean Mvt_Mouse_6;
               boolean Mvt_Cat_1;
               boolean Mvt_Cat_2;
               boolean Mvt_Cat_3;
               boolean Mvt_Cat_4;
               boolean Mvt_Cat_5;
               boolean Mvt_Cat_6;
               boolean Mvt_Cat_7;
               event Tick;
               boolean DoorState_Mouse_1;
               boolean DoorState_Mouse_2;
               boolean DoorState_Mouse_3;
               boolean DoorState_Mouse_4;
               boolean DoorState_Mouse_5;
               boolean DoorState_Mouse_6;
               boolean DoorState_Cat_1;
               boolean DoorState_Cat_2;
               boolean DoorState_Cat_3;
               boolean DoorState_Cat_4;
               boolean DoorState_Cat_5;
               boolean DoorState_Cat_6;
             ! boolean Mouse_Room_0;
               boolean Mouse_Room_1;
               boolean Mouse_Room_2;
               boolean Mouse_Room_3;
               boolean Mouse_Room_4;
               boolean Cat_Room_0;
               boolean Cat_Room_1;
               boolean Cat_Room_2;
               boolean Cat_Room_3;
               boolean Cat_Room_4;
               boolean states_1;
               boolean states_2;
               boolean states_3;
               boolean states_4;
               boolean states_5;
               boolean states_6;
               boolean states_7;
               boolean states_8;
               boolean states_9;
               boolean states_10;
               boolean states_11;
               boolean states_12;
           )
         (| (| Assert_Mvt{}
             | Assert_Controls{}
             |)
          | (| (| State_of_Doors{}
                | states_1 := Cat_Door_1
                | states_2 := Cat_Door_2
                | states_3 := Cat_Door_3
                | states_4 := Cat_Door_4
                | states_5 := Cat_Door_5
                | states_6 := Cat_Door_6
                | states_7 := Mouse_Door_1
                | states_8 := Mouse_Door_2
                | states_9 := Mouse_Door_3
                | states_10 := Mouse_Door_4
                | states_11 := Mouse_Door_5
                | states_12 := Mouse_Door_6
                |) where boolean Cat_Door_1, Cat_Door_2, Cat_Door_3, Cat_Door_4, Cat_Door_5, Cat_Door_6, Mouse_Door_1, Mouse_Door_2, Mouse_Door_3, Mouse_Door_4, Mouse_Door_5, Mouse_Door_6; end
             | State_of_Rooms{}
             |)
          |)
         where 
         boolean Z_Cat_Room_4 init false;
         boolean Z_Mouse_Room_4 init true;
         boolean Z_Cat_Room_3 init false;
         boolean Z_Mouse_Room_3 init false;
         boolean Z_Cat_Room_2 init true;
         boolean Z_Mouse_Room_2 init false;
         boolean Z_Cat_Room_1 init false;
         boolean Z_Mouse_Room_1 init false;
         boolean Z_Cat_Room_0 init false;
         boolean Z_Mouse_Room_0 init false;
         event Z_Mvt_Mouse_1;
         event Z_Mvt_Mouse_2;
         event Z_Mvt_Mouse_3;
         event Z_Mvt_Mouse_4;
         event Z_Mvt_Mouse_5;
         event Z_Mvt_Mouse_6;
         event Z_Mvt_Cat_1;
         event Z_Mvt_Cat_2;
         event Z_Mvt_Cat_3;
         event Z_Mvt_Cat_4;
         event Z_Mvt_Cat_5;
         event Z_Mvt_Cat_6;
         event Z_Mvt_Cat_7;
         boolean Z_Cat_Door_1 init false;
         boolean Z_Cat_Door_2 init false;
         boolean Z_Cat_Door_3 init false;
         boolean Z_Cat_Door_4 init false;
         boolean Z_Cat_Door_5 init false;
         boolean Z_Cat_Door_6 init false;
         boolean Z_Mouse_Door_1 init false;
         boolean Z_Mouse_Door_2 init false;
         boolean Z_Mouse_Door_3 init false;
         boolean Z_Mouse_Door_4 init false;
         boolean Z_Mouse_Door_5 init false;
         boolean Z_Mouse_Door_6 init false;
         process State_of_Rooms =
              ( ? event Tick;
                  boolean Mvt_Mouse_1;
                  boolean Mvt_Cat_1;
                  boolean Mvt_Mouse_2;
                  boolean Mvt_Cat_2;
                  boolean Mvt_Mouse_3;
                  boolean Mvt_Cat_3;
                  boolean Mvt_Mouse_4;
                  boolean Mvt_Cat_4;
                  boolean Mvt_Mouse_5;
                  boolean Mvt_Cat_5;
                  boolean Mvt_Mouse_6;
                  boolean Mvt_Cat_6;
                  boolean Mvt_Cat_7;
                ! boolean Mouse_Room_0;
                  boolean Cat_Room_0;
                  boolean Mouse_Room_1;
                  boolean Cat_Room_1;
                  boolean Mouse_Room_2;
                  boolean Cat_Room_2;
                  boolean Mouse_Room_3;
                  boolean Cat_Room_3;
                  boolean Mouse_Room_4;
                  boolean Cat_Room_4;
                  boolean Z_Mouse_Room_0;
                  boolean Z_Cat_Room_0;
                  boolean Z_Mouse_Room_1;
                  boolean Z_Cat_Room_1;
                  boolean Z_Mouse_Room_2;
                  boolean Z_Cat_Room_2;
                  boolean Z_Mouse_Room_3;
                  boolean Z_Cat_Room_3;
                  boolean Z_Mouse_Room_4;
                  boolean Z_Cat_Room_4;
              )
            (| (| (| Inter_Mouse_Room_0 := (when Mvt_Mouse_3) default (when Mvt_Mouse_6) default (false when Mvt_Mouse_1) default (false when Mvt_Mouse_4)
                   | Mouse_Room_0 := Inter_Mouse_Room_0 default Z_Mouse_Room_0
                   | Z_Mouse_Room_0 := Mouse_Room_0$1 init false
                   |)
                | (| Inter_Cat_Room_0 := (when Mvt_Cat_3) default (when Mvt_Cat_6) default (false when Mvt_Cat_1) default (false when Mvt_Cat_4)
                   | Cat_Room_0 := Inter_Cat_Room_0 default Z_Cat_Room_0
                   | Z_Cat_Room_0 := Cat_Room_0$1 init false
                   |)
                | (| Inter_Mouse_Room_1 := (when Mvt_Mouse_2) default (false when Mvt_Mouse_3)
                   | Mouse_Room_1 := Inter_Mouse_Room_1 default Z_Mouse_Room_1
                   | Z_Mouse_Room_1 := Mouse_Room_1$1 init false
                   |)
                | (| Inter_Cat_Room_1 := (when Mvt_Cat_1) default ((when Z_Cat_Room_3) when Mvt_Cat_7) default (false when Mvt_Cat_2) default (false when ((when Z_Cat_Room_1) when Mvt_Cat_7))
                   | Cat_Room_1 := Inter_Cat_Room_1 default Z_Cat_Room_1
                   | Z_Cat_Room_1 := Cat_Room_1$1 init false
                   |)
                | (| Inter_Mouse_Room_2 := (when Mvt_Mouse_1) default (false when Mvt_Mouse_2)
                   | Mouse_Room_2 := Inter_Mouse_Room_2 default Z_Mouse_Room_2
                   | Z_Mouse_Room_2 := Mouse_Room_2$1 init false
                   |)
                | (| Inter_Cat_Room_2 := (when Mvt_Cat_2) default (false when Mvt_Cat_3)
                   | Cat_Room_2 := Inter_Cat_Room_2 default Z_Cat_Room_2
                   | Z_Cat_Room_2 := Cat_Room_2$1 init true
                   |)
                | (| Inter_Mouse_Room_3 := (when Mvt_Mouse_5) default (false when Mvt_Mouse_6)
                   | Mouse_Room_3 := Inter_Mouse_Room_3 default Z_Mouse_Room_3
                   | Z_Mouse_Room_3 := Mouse_Room_3$1 init false
                   |)
                | (| Inter_Cat_Room_3 := (when Mvt_Cat_4) default ((when Z_Cat_Room_1) when Mvt_Cat_7) default (false when Mvt_Cat_5) default (false when ((when Z_Cat_Room_3) when Mvt_Cat_7))
                   | Cat_Room_3 := Inter_Cat_Room_3 default Z_Cat_Room_3
                   | Z_Cat_Room_3 := Cat_Room_3$1 init false
                   |)
                | (| Inter_Mouse_Room_4 := (when Mvt_Mouse_4) default (false when Mvt_Mouse_5)
                   | Mouse_Room_4 := Inter_Mouse_Room_4 default Z_Mouse_Room_4
                   | Z_Mouse_Room_4 := Mouse_Room_4$1 init true
                   |)
                | (| Inter_Cat_Room_4 := (when Mvt_Cat_5) default (false when Mvt_Cat_6)
                   | Cat_Room_4 := Inter_Cat_Room_4 default Z_Cat_Room_4
                   | Z_Cat_Room_4 := Cat_Room_4$1 init false
                   |)
                | Mouse_Room_0 ^= Mouse_Room_1 ^= Mouse_Room_2 ^= Mouse_Room_3 ^= Mouse_Room_4 ^= Cat_Room_0 ^= Cat_Room_1 ^= Cat_Room_2 ^= Cat_Room_3 ^= Cat_Room_4 ^= Tick
                |)/ Inter_Cat_Room_0, Inter_Cat_Room_1, Inter_Cat_Room_3, Inter_Cat_Room_4, Inter_Cat_Room_2, Inter_Mouse_Room_0, Inter_Mouse_Room_1, Inter_Mouse_Room_2, Inter_Mouse_Room_3, Inter_Mouse_Room_4 |)
         ; 
         process State_of_Doors =
              ( ? boolean DoorState_Mouse_1;
                  boolean DoorState_Mouse_2;
                  boolean DoorState_Mouse_3;
                  boolean DoorState_Mouse_4;
                  boolean DoorState_Mouse_5;
                  boolean DoorState_Mouse_6;
                  boolean DoorState_Cat_1;
                  boolean DoorState_Cat_2;
                  boolean DoorState_Cat_3;
                  boolean DoorState_Cat_4;
                  boolean DoorState_Cat_5;
                  boolean DoorState_Cat_6;
                  event Tick;
                ! boolean Z_Cat_Door_1;
                  boolean Z_Cat_Door_2;
                  boolean Z_Cat_Door_3;
                  boolean Z_Cat_Door_4;
                  boolean Z_Cat_Door_5;
                  boolean Z_Cat_Door_6;
                  boolean Z_Mouse_Door_1;
                  boolean Z_Mouse_Door_2;
                  boolean Z_Mouse_Door_3;
                  boolean Z_Mouse_Door_4;
                  boolean Z_Mouse_Door_5;
                  boolean Z_Mouse_Door_6;
                  boolean Cat_Door_1;
                  boolean Cat_Door_2;
                  boolean Cat_Door_3;
                  boolean Cat_Door_4;
                  boolean Cat_Door_5;
                  boolean Cat_Door_6;
                  boolean Mouse_Door_1;
                  boolean Mouse_Door_2;
                  boolean Mouse_Door_3;
                  boolean Mouse_Door_4;
                  boolean Mouse_Door_5;
                  boolean Mouse_Door_6;
              )
            (| (| Cat_Door_1 := DoorState_Cat_1 default Z_Cat_Door_1
                | Z_Cat_Door_1 := Cat_Door_1$1 init false
                |)
             | (| Cat_Door_2 := DoorState_Cat_2 default Z_Cat_Door_2
                | Z_Cat_Door_2 := Cat_Door_2$1 init false
                |)
             | (| Cat_Door_3 := DoorState_Cat_3 default Z_Cat_Door_3
                | Z_Cat_Door_3 := Cat_Door_3$1 init false
                |)
             | (| Cat_Door_4 := DoorState_Cat_4 default Z_Cat_Door_4
                | Z_Cat_Door_4 := Cat_Door_4$1 init false
                |)
             | (| Cat_Door_5 := DoorState_Cat_5 default Z_Cat_Door_5
                | Z_Cat_Door_5 := Cat_Door_5$1 init false
                |)
             | (| Cat_Door_6 := DoorState_Cat_6 default Z_Cat_Door_6
                | Z_Cat_Door_6 := Cat_Door_6$1 init false
                |)
             | (| Mouse_Door_1 := DoorState_Mouse_1 default Z_Mouse_Door_1
                | Z_Mouse_Door_1 := Mouse_Door_1$1 init false
                |)
             | (| Mouse_Door_2 := DoorState_Mouse_2 default Z_Mouse_Door_2
                | Z_Mouse_Door_2 := Mouse_Door_2$1 init false
                |)
             | (| Mouse_Door_3 := DoorState_Mouse_3 default Z_Mouse_Door_3
                | Z_Mouse_Door_3 := Mouse_Door_3$1 init false
                |)
             | (| Mouse_Door_4 := DoorState_Mouse_4 default Z_Mouse_Door_4
                | Z_Mouse_Door_4 := Mouse_Door_4$1 init false
                |)
             | (| Mouse_Door_5 := DoorState_Mouse_5 default Z_Mouse_Door_5
                | Z_Mouse_Door_5 := Mouse_Door_5$1 init false
                |)
             | (| Mouse_Door_6 := DoorState_Mouse_6 default Z_Mouse_Door_6
                | Z_Mouse_Door_6 := Mouse_Door_6$1 init false
                |)
             | Mouse_Door_1 ^= Mouse_Door_2 ^= Mouse_Door_3 ^= Mouse_Door_4 ^= Mouse_Door_5 ^= Mouse_Door_6 ^= Tick
             | Cat_Door_1 ^= Cat_Door_2 ^= Cat_Door_3 ^= Cat_Door_4 ^= Cat_Door_5 ^= Cat_Door_6 ^= Tick
             |)
         ; 
         process Assert_Controls =
              ( ? DoorState_Cat_6;
                  DoorState_Cat_5;
                  DoorState_Cat_4;
                  DoorState_Cat_3;
                  DoorState_Cat_2;
                  DoorState_Cat_1;
                  DoorState_Mouse_6;
                  DoorState_Mouse_5;
                  DoorState_Mouse_4;
                  DoorState_Mouse_3;
                  DoorState_Mouse_2;
                  DoorState_Mouse_1;
                  event Tick;
              )
            (| (| DoorState_Cat_1 ^= DoorState_Cat_2 ^= DoorState_Cat_3 ^= Tick
                | DoorState_Cat_4 ^= DoorState_Cat_5 ^= DoorState_Cat_6 ^= Tick
                |)
             | (| DoorState_Mouse_1 ^= DoorState_Mouse_2 ^= DoorState_Mouse_3 ^= Tick
                | DoorState_Mouse_4 ^= DoorState_Mouse_5 ^= DoorState_Mouse_6 ^= Tick
                |)
             |)
         ; 
         process Assert_Mvt =
              ( ? Tick;
                  Mvt_Cat_7;
                  Mvt_Cat_6;
                  Mvt_Mouse_6;
                  Mvt_Cat_5;
                  Mvt_Mouse_5;
                  Mvt_Cat_4;
                  Mvt_Mouse_4;
                  Mvt_Cat_3;
                  Mvt_Mouse_3;
                  Mvt_Cat_2;
                  Mvt_Mouse_2;
                  Mvt_Cat_1;
                  Mvt_Mouse_1;
              )
            (| Mvt_Mouse_1 ^= Tick
             | Mvt_Cat_1 ^= Tick
             | Mvt_Mouse_2 ^= Tick
             | Mvt_Cat_2 ^= Tick
             | Mvt_Mouse_3 ^= Tick
             | Mvt_Cat_3 ^= Tick
             | Mvt_Mouse_4 ^= Tick
             | Mvt_Cat_4 ^= Tick
             | Mvt_Mouse_5 ^= Tick
             | Mvt_Cat_5 ^= Tick
             | Mvt_Mouse_6 ^= Tick
             | Mvt_Cat_6 ^= Tick
             | Mvt_Cat_7 ^= Tick
             |)
         ; 
         end
      ; 
      process Drawing =
           ( ? boolean Cat_Room_4;
               boolean Cat_Room_3;
               boolean Cat_Room_2;
               boolean Cat_Room_1;
               boolean Cat_Room_0;
               boolean Mouse_Room_4;
               boolean Mouse_Room_3;
               boolean Mouse_Room_2;
               boolean Mouse_Room_1;
               boolean Mouse_Room_0;
               DoorState_Cat_6;
               DoorState_Cat_5;
               DoorState_Cat_4;
               DoorState_Cat_3;
               DoorState_Cat_2;
               DoorState_Cat_1;
               DoorState_Mouse_6;
               DoorState_Mouse_5;
               DoorState_Mouse_4;
               DoorState_Mouse_3;
               DoorState_Mouse_2;
               DoorState_Mouse_1;
               Tick;
           )
         (| (| (| Pos_Cat_0 := (1 when Cat_Room_0) default 0
                | Pos_Cat_1 := (1 when Cat_Room_1) default 0
                | Pos_Cat_2 := (1 when Cat_Room_2) default 0
                | Pos_Cat_3 := (1 when Cat_Room_3) default 0
                | Pos_Cat_4 := (1 when Cat_Room_4) default 0
                | Pos_Cat_0 ^= Pos_Cat_1 ^= Pos_Cat_2 ^= Pos_Cat_3 ^= Pos_Cat_4 ^= Tick
                | Pos_Cat := [[0] : 1 when Tick,[1] : Pos_Cat_0,[2] : Pos_Cat_1,[3] : Pos_Cat_2,[4] : Pos_Cat_3,[5] : Pos_Cat_4]
                |)/ Pos_Cat_0, Pos_Cat_1, Pos_Cat_2, Pos_Cat_3, Pos_Cat_4
             | (| Pos_Mouse_0 := (1 when Mouse_Room_0) default 0
                | Pos_Mouse_1 := (1 when Mouse_Room_1) default 0
                | Pos_Mouse_2 := (1 when Mouse_Room_2) default 0
                | Pos_Mouse_3 := (1 when Mouse_Room_3) default 0
                | Pos_Mouse_4 := (1 when Mouse_Room_4) default 0
                | Pos_Mouse_0 ^= Pos_Mouse_1 ^= Pos_Mouse_2 ^= Pos_Mouse_3 ^= Pos_Mouse_4 ^= Tick
                | Pos_Mouse := [[0] : 1 when Tick,[1] : Pos_Mouse_0,[2] : Pos_Mouse_1,[3] : Pos_Mouse_2,[4] : Pos_Mouse_3,[5] : Pos_Mouse_4]
                |)/ Pos_Mouse_0, Pos_Mouse_1, Pos_Mouse_2, Pos_Mouse_3, Pos_Mouse_4
             | Draw_Cat{}
             | Draw_Mouse{}
             | (| Door_Cat_1 := (1 when DoorState_Cat_1) default 0
                | Door_Cat_2 := (1 when DoorState_Cat_2) default 0
                | Door_Cat_3 := (1 when DoorState_Cat_3) default 0
                | Door_Cat_4 := (1 when DoorState_Cat_4) default 0
                | Door_Cat_5 := (1 when DoorState_Cat_5) default 0
                | Door_Cat_6 := (1 when DoorState_Cat_6) default 0
                | Door_Cat_1 ^= Door_Cat_2 ^= Door_Cat_3 ^= Door_Cat_4 ^= Door_Cat_5 ^= Door_Cat_6 ^= Tick
                | Door_Cat := [[0] : 1 when Tick,[1] : Door_Cat_1,[2] : Door_Cat_2,[3] : Door_Cat_3,[4] : Door_Cat_4,[5] : Door_Cat_5,[6] : Door_Cat_6]
                |)/ Door_Cat_1, Door_Cat_2, Door_Cat_3, Door_Cat_4, Door_Cat_5, Door_Cat_6
             | (| Door_Mouse_1 := (1 when DoorState_Mouse_1) default 0
                | Door_Mouse_2 := (1 when DoorState_Mouse_2) default 0
                | Door_Mouse_3 := (1 when DoorState_Mouse_3) default 0
                | Door_Mouse_4 := (1 when DoorState_Mouse_4) default 0
                | Door_Mouse_5 := (1 when DoorState_Mouse_5) default 0
                | Door_Mouse_6 := (1 when DoorState_Mouse_6) default 0
                | Door_Mouse_1 ^= Door_Mouse_2 ^= Door_Mouse_3 ^= Door_Mouse_4 ^= Door_Mouse_5 ^= Door_Mouse_6 ^= Tick
                | Door_Mouse := [[0] : 1 when Tick,[1] : Door_Mouse_1,[2] : Door_Mouse_2,[3] : Door_Mouse_3,[4] : Door_Mouse_4,[5] : Door_Mouse_5,[6] : Door_Mouse_6]
                |)/ Door_Mouse_1, Door_Mouse_2, Door_Mouse_3, Door_Mouse_4, Door_Mouse_5, Door_Mouse_6
             | Draw_Door_Cat{}
             | Draw_Door_Mouse{}
             |)/ Door_Mouse, Door_Cat, Pos_Mouse, Pos_Cat |)
         where 
         [6]integer Pos_Cat, Pos_Mouse;
         [7]integer Door_Cat, Door_Mouse;
         process Draw_Cat =
              ( ? [6]integer Pos_Cat;
              )
         
         ; 
         process Draw_Mouse =
              ( ? [6]integer Pos_Mouse;
              )
         
         ; 
         process Draw_Door_Mouse =
              ( ? [7]integer Door_Mouse;
              )
         
         ; 
         process Draw_Door_Cat =
              ( ? [7]integer Door_Cat;
              )
         
         ; 
         end
      ; 
      process Drawing_Conflict =
           ( ? Cat_Room_4;
               Cat_Room_3;
               Cat_Room_2;
               Cat_Room_1;
               Cat_Room_0;
               Mouse_Room_4;
               Mouse_Room_3;
               Mouse_Room_2;
               Mouse_Room_1;
               Mouse_Room_0;
               event Tick;
           )
         (| (| (| Cat_Mouse_Room_0 := when (Cat_Room_0 and Mouse_Room_0)
                | Cat_Mouse_Room_1 := when (Cat_Room_1 and Mouse_Room_1)
                | Cat_Mouse_Room_2 := when (Cat_Room_2 and Mouse_Room_2)
                | Cat_Mouse_Room_3 := when (Cat_Room_3 and Mouse_Room_3)
                | Cat_Mouse_Room_4 := when (Cat_Room_4 and Mouse_Room_4)
                | Conflict := (1 when Cat_Mouse_Room_0) default (1 when Cat_Mouse_Room_1) default (1 when Cat_Mouse_Room_2) default (1 when Cat_Mouse_Room_3) default (1 when Cat_Mouse_Room_4) default 0
                | Conflict ^= Tick
                |)/ Cat_Mouse_Room_0, Cat_Mouse_Room_1, Cat_Mouse_Room_2, Cat_Mouse_Room_3, Cat_Mouse_Room_4
             | Draw_Conflict{}
             |)/ Conflict |)
         where 
         process Draw_Conflict =
              ( ? integer Conflict;
              )
         
         ; 
         integer Conflict;
         end
      ; 
      process RESOLVER =
           { integer ncond, nx, nu, ny; }
           ( ? [ncond]integer cod_cond;
               [nx]integer cod_x;
               event TTick;
             ! [nu]integer cod_u;
               [ny]integer cod_y;
               event Tick;
           )
         (| (| (| S_cod_cond := cod_cond cell TTick
                | S_cod_x := cod_x cell TTick
                | resolver{}
                |)
             | (| Z_S_cod_u := S_cod_u$1 init [{i to nu}:0]
                | cod_u := Z_S_cod_u when Tick
                | Z_S_cod_y := S_cod_y$1 init [{i to ny}:0]
                | cod_y := Z_S_cod_y when Tick
                |)
             | (| (| b := (when fin_resolver) default false
                   | z_b := b$1
                   | b ^= TTick
                   |)
                | Tick := when z_b
                |)
             |) |)
         where 
         boolean z_b init true, b;
         [nx]integer S_cod_x;
         [nu]integer S_cod_u;
         [nu]integer Z_S_cod_u;
         [ny]integer S_cod_y;
         [ny]integer Z_S_cod_y;
         [ncond]integer S_cod_cond;
         boolean fin_resolver;
         process resolver =
              ( ? [ncond]integer S_cod_cond;
                  [nx]integer S_cod_x;
                ! [nu]integer S_cod_u;
                  [ny]integer S_cod_y;
                  boolean fin_resolver;
              )
              spec (| S_cod_cond ^= S_cod_x ^= S_cod_u ^= S_cod_y ^= fin_resolver |)
         
         ; 
         end
      ; 
      end
   ; 
   process vt =
        ( ? boolean Mvt_Mouse_1;
            boolean Mvt_Mouse_2;
            boolean Mvt_Mouse_3;
            boolean Mvt_Mouse_4;
            boolean Mvt_Mouse_5;
            boolean Mvt_Mouse_6;
            boolean Mvt_Cat_1;
            boolean Mvt_Cat_2;
            boolean Mvt_Cat_3;
            boolean Mvt_Cat_4;
            boolean Mvt_Cat_5;
            boolean Mvt_Cat_6;
            boolean Mvt_Cat_7;
            boolean DoorState_Mouse_1;
            boolean DoorState_Mouse_2;
            boolean DoorState_Mouse_3;
            boolean DoorState_Mouse_4;
            boolean DoorState_Mouse_5;
            boolean DoorState_Mouse_6;
            boolean DoorState_Cat_1;
            boolean DoorState_Cat_2;
            boolean DoorState_Cat_3;
            boolean DoorState_Cat_4;
            boolean DoorState_Cat_5;
            boolean DoorState_Cat_6;
          ! boolean Mouse_Room_0;
            boolean Mouse_Room_1;
            boolean Mouse_Room_2;
            boolean Mouse_Room_3;
            boolean Mouse_Room_4;
            boolean Cat_Room_0;
            boolean Cat_Room_1;
            boolean Cat_Room_2;
            boolean Cat_Room_3;
            boolean Cat_Room_4;
            boolean Cat_Door_1;
            boolean Cat_Door_2;
            boolean Cat_Door_3;
            boolean Cat_Door_4;
            boolean Cat_Door_5;
            boolean Cat_Door_6;
            boolean Mouse_Door_1;
            boolean Mouse_Door_2;
            boolean Mouse_Door_3;
            boolean Mouse_Door_4;
            boolean Mouse_Door_5;
            boolean Mouse_Door_6;
        )
      (| (| Assert_Controls{}
          | Assert_Mouse{}
          | Assert_Cat{}
          |)
       | (| State_of_Doors{}
          | State_of_Rooms{}
          |)
       | Control_Obj{}
       | Tick := true
       |)
      where 
      use SIGALI; 
      boolean Z_Cat_Room_4 init false;
      boolean Z_Mouse_Room_4 init true;
      boolean Z_Cat_Room_3 init false;
      boolean Z_Mouse_Room_3 init false;
      boolean Z_Cat_Room_2 init true;
      boolean Z_Mouse_Room_2 init false;
      boolean Z_Cat_Room_1 init false;
      boolean Z_Mouse_Room_1 init false;
      boolean Z_Cat_Room_0 init false;
      boolean Z_Mouse_Room_0 init false;
      event Z_Mvt_Mouse_1;
      event Z_Mvt_Mouse_2;
      event Z_Mvt_Mouse_3;
      event Z_Mvt_Mouse_4;
      event Z_Mvt_Mouse_5;
      event Z_Mvt_Mouse_6;
      event Z_Mvt_Cat_1;
      event Z_Mvt_Cat_2;
      event Z_Mvt_Cat_3;
      event Z_Mvt_Cat_4;
      event Z_Mvt_Cat_5;
      event Z_Mvt_Cat_6;
      event Z_Mvt_Cat_7;
      boolean Z_Cat_Door_1 init false;
      boolean Z_Cat_Door_2 init false;
      boolean Z_Cat_Door_3 init false;
      boolean Z_Cat_Door_4 init false;
      boolean Z_Cat_Door_5 init false;
      boolean Z_Cat_Door_6 init false;
      boolean Z_Mouse_Door_1 init false;
      boolean Z_Mouse_Door_2 init false;
      boolean Z_Mouse_Door_3 init false;
      boolean Z_Mouse_Door_4 init false;
      boolean Z_Mouse_Door_5 init false;
      boolean Z_Mouse_Door_6 init false;
      event Tick;
      process State_of_Rooms =
           ( ? event Tick;
               boolean Mvt_Mouse_1;
               boolean Mvt_Cat_1;
               boolean Mvt_Mouse_2;
               boolean Mvt_Cat_2;
               boolean Mvt_Mouse_3;
               boolean Mvt_Cat_3;
               boolean Mvt_Mouse_4;
               boolean Mvt_Cat_4;
               boolean Mvt_Mouse_5;
               boolean Mvt_Cat_5;
               boolean Mvt_Mouse_6;
               boolean Mvt_Cat_6;
               boolean Mvt_Cat_7;
             ! boolean Mouse_Room_0;
               boolean Cat_Room_0;
               boolean Mouse_Room_1;
               boolean Cat_Room_1;
               boolean Mouse_Room_2;
               boolean Cat_Room_2;
               boolean Mouse_Room_3;
               boolean Cat_Room_3;
               boolean Mouse_Room_4;
               boolean Cat_Room_4;
               boolean Z_Mouse_Room_0;
               boolean Z_Cat_Room_0;
               boolean Z_Mouse_Room_1;
               boolean Z_Cat_Room_1;
               boolean Z_Mouse_Room_2;
               boolean Z_Cat_Room_2;
               boolean Z_Mouse_Room_3;
               boolean Z_Cat_Room_3;
               boolean Z_Mouse_Room_4;
               boolean Z_Cat_Room_4;
           )
         (| (| (| Inter_Mouse_Room_0 := (when Mvt_Mouse_3) default (when Mvt_Mouse_6) default (false when Mvt_Mouse_1) default (false when Mvt_Mouse_4)
                | Mouse_Room_0 := Inter_Mouse_Room_0 default Z_Mouse_Room_0
                | Z_Mouse_Room_0 := Mouse_Room_0$1 init false
                |)
             | (| Inter_Cat_Room_0 := (when Mvt_Cat_3) default (when Mvt_Cat_6) default (false when Mvt_Cat_1) default (false when Mvt_Cat_4)
                | Cat_Room_0 := Inter_Cat_Room_0 default Z_Cat_Room_0
                | Z_Cat_Room_0 := Cat_Room_0$1 init false
                |)
             | (| Inter_Mouse_Room_1 := (when Mvt_Mouse_2) default (false when Mvt_Mouse_3)
                | Mouse_Room_1 := Inter_Mouse_Room_1 default Z_Mouse_Room_1
                | Z_Mouse_Room_1 := Mouse_Room_1$1 init false
                |)
             | (| Inter_Cat_Room_1 := (when Mvt_Cat_1) default ((when Z_Cat_Room_3) when Mvt_Cat_7) default (false when Mvt_Cat_2) default (false when ((when Z_Cat_Room_1) when Mvt_Cat_7))
                | Cat_Room_1 := Inter_Cat_Room_1 default Z_Cat_Room_1
                | Z_Cat_Room_1 := Cat_Room_1$1 init false
                |)
             | (| Inter_Mouse_Room_2 := (when Mvt_Mouse_1) default (false when Mvt_Mouse_2)
                | Mouse_Room_2 := Inter_Mouse_Room_2 default Z_Mouse_Room_2
                | Z_Mouse_Room_2 := Mouse_Room_2$1 init false
                |)
             | (| Inter_Cat_Room_2 := (when Mvt_Cat_2) default (false when Mvt_Cat_3)
                | Cat_Room_2 := Inter_Cat_Room_2 default Z_Cat_Room_2
                | Z_Cat_Room_2 := Cat_Room_2$1 init true
                |)
             | (| Inter_Mouse_Room_3 := (when Mvt_Mouse_5) default (false when Mvt_Mouse_6)
                | Mouse_Room_3 := Inter_Mouse_Room_3 default Z_Mouse_Room_3
                | Z_Mouse_Room_3 := Mouse_Room_3$1 init false
                |)
             | (| Inter_Cat_Room_3 := (when Mvt_Cat_4) default ((when Z_Cat_Room_1) when Mvt_Cat_7) default (false when Mvt_Cat_5) default (false when ((when Z_Cat_Room_3) when Mvt_Cat_7))
                | Cat_Room_3 := Inter_Cat_Room_3 default Z_Cat_Room_3
                | Z_Cat_Room_3 := Cat_Room_3$1 init false
                |)
             | (| Inter_Mouse_Room_4 := (when Mvt_Mouse_4) default (false when Mvt_Mouse_5)
                | Mouse_Room_4 := Inter_Mouse_Room_4 default Z_Mouse_Room_4
                | Z_Mouse_Room_4 := Mouse_Room_4$1 init true
                |)
             | (| Inter_Cat_Room_4 := (when Mvt_Cat_5) default (false when Mvt_Cat_6)
                | Cat_Room_4 := Inter_Cat_Room_4 default Z_Cat_Room_4
                | Z_Cat_Room_4 := Cat_Room_4$1 init false
                |)
             | Mouse_Room_0 ^= Mouse_Room_1 ^= Mouse_Room_2 ^= Mouse_Room_3 ^= Mouse_Room_4 ^= Cat_Room_0 ^= Cat_Room_1 ^= Cat_Room_2 ^= Cat_Room_3 ^= Cat_Room_4 ^= Tick
             |)/ Inter_Cat_Room_0, Inter_Cat_Room_1, Inter_Cat_Room_3, Inter_Cat_Room_4, Inter_Cat_Room_2, Inter_Mouse_Room_0, Inter_Mouse_Room_1, Inter_Mouse_Room_2, Inter_Mouse_Room_3, Inter_Mouse_Room_4 |)
      ; 
      process State_of_Doors =
           ( ? boolean DoorState_Mouse_1;
               boolean DoorState_Mouse_2;
               boolean DoorState_Mouse_3;
               boolean DoorState_Mouse_4;
               boolean DoorState_Mouse_5;
               boolean DoorState_Mouse_6;
               boolean DoorState_Cat_1;
               boolean DoorState_Cat_2;
               boolean DoorState_Cat_3;
               boolean DoorState_Cat_4;
               boolean DoorState_Cat_5;
               boolean DoorState_Cat_6;
               event Tick;
             ! boolean Z_Cat_Door_1;
               boolean Z_Cat_Door_2;
               boolean Z_Cat_Door_3;
               boolean Z_Cat_Door_4;
               boolean Z_Cat_Door_5;
               boolean Z_Cat_Door_6;
               boolean Z_Mouse_Door_1;
               boolean Z_Mouse_Door_2;
               boolean Z_Mouse_Door_3;
               boolean Z_Mouse_Door_4;
               boolean Z_Mouse_Door_5;
               boolean Z_Mouse_Door_6;
               boolean Cat_Door_1;
               boolean Cat_Door_2;
               boolean Cat_Door_3;
               boolean Cat_Door_4;
               boolean Cat_Door_5;
               boolean Cat_Door_6;
               boolean Mouse_Door_1;
               boolean Mouse_Door_2;
               boolean Mouse_Door_3;
               boolean Mouse_Door_4;
               boolean Mouse_Door_5;
               boolean Mouse_Door_6;
           )
         (| (| Cat_Door_1 := DoorState_Cat_1 default Z_Cat_Door_1
             | Z_Cat_Door_1 := Cat_Door_1$1 init false
             |)
          | (| Cat_Door_2 := DoorState_Cat_2 default Z_Cat_Door_2
             | Z_Cat_Door_2 := Cat_Door_2$1 init false
             |)
          | (| Cat_Door_3 := DoorState_Cat_3 default Z_Cat_Door_3
             | Z_Cat_Door_3 := Cat_Door_3$1 init false
             |)
          | (| Cat_Door_4 := DoorState_Cat_4 default Z_Cat_Door_4
             | Z_Cat_Door_4 := Cat_Door_4$1 init false
             |)
          | (| Cat_Door_5 := DoorState_Cat_5 default Z_Cat_Door_5
             | Z_Cat_Door_5 := Cat_Door_5$1 init false
             |)
          | (| Cat_Door_6 := DoorState_Cat_6 default Z_Cat_Door_6
             | Z_Cat_Door_6 := Cat_Door_6$1 init false
             |)
          | (| Mouse_Door_1 := DoorState_Mouse_1 default Z_Mouse_Door_1
             | Z_Mouse_Door_1 := Mouse_Door_1$1 init false
             |)
          | (| Mouse_Door_2 := DoorState_Mouse_2 default Z_Mouse_Door_2
             | Z_Mouse_Door_2 := Mouse_Door_2$1 init false
             |)
          | (| Mouse_Door_3 := DoorState_Mouse_3 default Z_Mouse_Door_3
             | Z_Mouse_Door_3 := Mouse_Door_3$1 init false
             |)
          | (| Mouse_Door_4 := DoorState_Mouse_4 default Z_Mouse_Door_4
             | Z_Mouse_Door_4 := Mouse_Door_4$1 init false
             |)
          | (| Mouse_Door_5 := DoorState_Mouse_5 default Z_Mouse_Door_5
             | Z_Mouse_Door_5 := Mouse_Door_5$1 init false
             |)
          | (| Mouse_Door_6 := DoorState_Mouse_6 default Z_Mouse_Door_6
             | Z_Mouse_Door_6 := Mouse_Door_6$1 init false
             |)
          | Mouse_Door_1 ^= Mouse_Door_2 ^= Mouse_Door_3 ^= Mouse_Door_4 ^= Mouse_Door_5 ^= Mouse_Door_6 ^= Tick
          | Cat_Door_1 ^= Cat_Door_2 ^= Cat_Door_3 ^= Cat_Door_4 ^= Cat_Door_5 ^= Cat_Door_6 ^= Tick
          |)
      ; 
      process Assert_Controls =
           ( ? DoorState_Cat_6;
               DoorState_Cat_5;
               DoorState_Cat_4;
               DoorState_Cat_3;
               DoorState_Cat_2;
               DoorState_Cat_1;
               DoorState_Mouse_6;
               DoorState_Mouse_5;
               DoorState_Mouse_4;
               DoorState_Mouse_3;
               DoorState_Mouse_2;
               DoorState_Mouse_1;
               event Tick;
           )
         (| (| DoorState_Cat_1 ^= DoorState_Cat_2 ^= DoorState_Cat_3 ^= Tick
             | DoorState_Cat_4 ^= DoorState_Cat_5 ^= DoorState_Cat_6 ^= Tick
             |)
          | (| DoorState_Mouse_1 ^= DoorState_Mouse_2 ^= DoorState_Mouse_3 ^= Tick
             | DoorState_Mouse_4 ^= DoorState_Mouse_5 ^= DoorState_Mouse_6 ^= Tick
             |)
          |)
      ; 
      process Assert_Cat =
           ( ? Z_Cat_Door_6;
               Z_Cat_Door_5;
               Z_Cat_Door_4;
               Z_Cat_Door_3;
               Z_Cat_Door_2;
               Z_Cat_Door_1;
               Z_Cat_Room_4;
               Z_Cat_Room_3;
               Z_Cat_Room_2;
               Z_Cat_Room_1;
               Z_Cat_Room_0;
               Mvt_Cat_7;
               Mvt_Cat_6;
               Mvt_Cat_5;
               Mvt_Cat_4;
               Mvt_Cat_3;
               Mvt_Cat_2;
               Mvt_Cat_1;
               Tick;
           )
         (| (| when Mvt_Cat_1 ^= (when Mvt_Cat_1) when Z_Cat_Room_0
             | when Mvt_Cat_2 ^= (when Mvt_Cat_2) when Z_Cat_Room_1
             | when Mvt_Cat_3 ^= (when Mvt_Cat_3) when Z_Cat_Room_2
             | when Mvt_Cat_4 ^= (when Mvt_Cat_4) when Z_Cat_Room_0
             | when Mvt_Cat_5 ^= (when Mvt_Cat_5) when Z_Cat_Room_3
             | when Mvt_Cat_6 ^= (when Mvt_Cat_6) when Z_Cat_Room_4
             | when Mvt_Cat_7 ^= ((when Mvt_Cat_7) when Z_Cat_Room_1) default ((when Mvt_Cat_7) when Z_Cat_Room_3)
             |)
          | (| when Mvt_Cat_1 ^= (when Mvt_Cat_1) when Z_Cat_Door_1
             | when Mvt_Cat_2 ^= (when Mvt_Cat_2) when Z_Cat_Door_2
             | when Mvt_Cat_3 ^= (when Mvt_Cat_3) when Z_Cat_Door_3
             | when Mvt_Cat_4 ^= (when Mvt_Cat_4) when Z_Cat_Door_4
             | when Mvt_Cat_5 ^= (when Mvt_Cat_5) when Z_Cat_Door_5
             | when Mvt_Cat_6 ^= (when Mvt_Cat_6) when Z_Cat_Door_6
             |)
          | (| disjoint(Mvt_Cat_1,Mvt_Cat_2)
             | disjoint(Mvt_Cat_1,Mvt_Cat_3)
             | disjoint(Mvt_Cat_1,Mvt_Cat_4)
             | disjoint(Mvt_Cat_1,Mvt_Cat_5)
             | disjoint(Mvt_Cat_1,Mvt_Cat_6)
             | disjoint(Mvt_Cat_1,Mvt_Cat_7)
             | disjoint(Mvt_Cat_2,Mvt_Cat_3)
             | disjoint(Mvt_Cat_2,Mvt_Cat_4)
             | disjoint(Mvt_Cat_2,Mvt_Cat_5)
             | disjoint(Mvt_Cat_2,Mvt_Cat_6)
             | disjoint(Mvt_Cat_2,Mvt_Cat_7)
             | disjoint(Mvt_Cat_3,Mvt_Cat_4)
             | disjoint(Mvt_Cat_3,Mvt_Cat_5)
             | disjoint(Mvt_Cat_3,Mvt_Cat_6)
             | disjoint(Mvt_Cat_3,Mvt_Cat_7)
             | disjoint(Mvt_Cat_4,Mvt_Cat_5)
             | disjoint(Mvt_Cat_4,Mvt_Cat_6)
             | disjoint(Mvt_Cat_4,Mvt_Cat_7)
             | disjoint(Mvt_Cat_5,Mvt_Cat_6)
             | disjoint(Mvt_Cat_5,Mvt_Cat_7)
             | disjoint(Mvt_Cat_6,Mvt_Cat_7)
             |)
          | (| Mvt_Cat_1 ^= Tick
             | Mvt_Cat_2 ^= Tick
             | Mvt_Cat_3 ^= Tick
             | Mvt_Cat_4 ^= Tick
             | Mvt_Cat_5 ^= Tick
             | Mvt_Cat_6 ^= Tick
             | Mvt_Cat_7 ^= Tick
             |)
          |)
      ; 
      process Assert_Mouse =
           ( ? Z_Mouse_Door_6;
               Z_Mouse_Door_5;
               Z_Mouse_Door_4;
               Z_Mouse_Door_3;
               Z_Mouse_Door_2;
               Z_Mouse_Door_1;
               Z_Mouse_Room_4;
               Z_Mouse_Room_3;
               Z_Mouse_Room_2;
               Z_Mouse_Room_1;
               Z_Mouse_Room_0;
               Mvt_Mouse_6;
               Mvt_Mouse_5;
               Mvt_Mouse_4;
               Mvt_Mouse_3;
               Mvt_Mouse_2;
               Mvt_Mouse_1;
               Tick;
           )
         (| (| when Mvt_Mouse_1 ^= (when Mvt_Mouse_1) when Z_Mouse_Room_0
             | when Mvt_Mouse_4 ^= (when Mvt_Mouse_4) when Z_Mouse_Room_0
             | when Mvt_Mouse_2 ^= (when Mvt_Mouse_2) when Z_Mouse_Room_2
             | when Mvt_Mouse_3 ^= (when Mvt_Mouse_3) when Z_Mouse_Room_1
             | when Mvt_Mouse_5 ^= (when Mvt_Mouse_5) when Z_Mouse_Room_4
             | when Mvt_Mouse_6 ^= (when Mvt_Mouse_6) when Z_Mouse_Room_3
             |)
          | (| when Mvt_Mouse_1 ^= (when Mvt_Mouse_1) when Z_Mouse_Door_1
             | when Mvt_Mouse_2 ^= (when Mvt_Mouse_2) when Z_Mouse_Door_2
             | when Mvt_Mouse_3 ^= (when Mvt_Mouse_3) when Z_Mouse_Door_3
             | when Mvt_Mouse_4 ^= (when Mvt_Mouse_4) when Z_Mouse_Door_4
             | when Mvt_Mouse_5 ^= (when Mvt_Mouse_5) when Z_Mouse_Door_5
             | when Mvt_Mouse_6 ^= (when Mvt_Mouse_6) when Z_Mouse_Door_6
             |)
          | (| disjoint(Mvt_Mouse_1,Mvt_Mouse_2)
             | disjoint(Mvt_Mouse_1,Mvt_Mouse_3)
             | disjoint(Mvt_Mouse_1,Mvt_Mouse_4)
             | disjoint(Mvt_Mouse_1,Mvt_Mouse_5)
             | disjoint(Mvt_Mouse_1,Mvt_Mouse_6)
             | disjoint(Mvt_Mouse_2,Mvt_Mouse_3)
             | disjoint(Mvt_Mouse_2,Mvt_Mouse_4)
             | disjoint(Mvt_Mouse_2,Mvt_Mouse_5)
             | disjoint(Mvt_Mouse_2,Mvt_Mouse_6)
             | disjoint(Mvt_Mouse_3,Mvt_Mouse_4)
             | disjoint(Mvt_Mouse_3,Mvt_Mouse_5)
             | disjoint(Mvt_Mouse_3,Mvt_Mouse_6)
             | disjoint(Mvt_Mouse_4,Mvt_Mouse_5)
             | disjoint(Mvt_Mouse_4,Mvt_Mouse_6)
             | disjoint(Mvt_Mouse_5,Mvt_Mouse_6)
             |)
          | (| Mvt_Mouse_1 ^= Tick
             | Mvt_Mouse_2 ^= Tick
             | Mvt_Mouse_3 ^= Tick
             | Mvt_Mouse_4 ^= Tick
             | Mvt_Mouse_5 ^= Tick
             | Mvt_Mouse_6 ^= Tick
             |)
          |)
      ; 
      process disjoint =
           ( ? boolean A;
               boolean B;
           )
         (| (when A) when B ^= when (not (^A)) |)
      ; 
      process Control_Obj =
           ( ? boolean Z_Cat_Room_4;
               boolean Z_Mouse_Room_4;
               boolean Z_Cat_Room_3;
               boolean Z_Mouse_Room_3;
               boolean Z_Cat_Room_2;
               boolean Z_Mouse_Room_2;
               boolean Z_Cat_Room_1;
               boolean Z_Mouse_Room_1;
               boolean Z_Cat_Room_0;
               boolean Z_Mouse_Room_0;
               boolean DoorState_Mouse_1;
               boolean DoorState_Mouse_2;
               boolean DoorState_Mouse_3;
               boolean DoorState_Mouse_4;
               boolean DoorState_Mouse_5;
               boolean DoorState_Mouse_6;
               boolean DoorState_Cat_1;
               boolean DoorState_Cat_2;
               boolean DoorState_Cat_3;
               boolean DoorState_Cat_4;
               boolean DoorState_Cat_5;
               boolean DoorState_Cat_6;
               event Tick;
           )
         (| (| (| Cat_Mouse_Room_0 := when (Z_Cat_Room_0 and Z_Mouse_Room_0)
                | Cat_Mouse_Room_1 := when (Z_Cat_Room_1 and Z_Mouse_Room_1)
                | Cat_Mouse_Room_2 := when (Z_Cat_Room_2 and Z_Mouse_Room_2)
                | Cat_Mouse_Room_3 := when (Z_Cat_Room_3 and Z_Mouse_Room_3)
                | Cat_Mouse_Room_4 := when (Z_Cat_Room_4 and Z_Mouse_Room_4)
                |)
             | (| SIGALI(Controllable(DoorState_Cat_1))
                | SIGALI(Controllable(DoorState_Cat_2))
                | SIGALI(Controllable(DoorState_Cat_3))
                | SIGALI(Controllable(DoorState_Cat_4))
                | SIGALI(Controllable(DoorState_Cat_5))
                | SIGALI(Controllable(DoorState_Cat_6))
                | SIGALI(Controllable(DoorState_Mouse_1))
                | SIGALI(Controllable(DoorState_Mouse_2))
                | SIGALI(Controllable(DoorState_Mouse_3))
                | SIGALI(Controllable(DoorState_Mouse_4))
                | SIGALI(Controllable(DoorState_Mouse_5))
                | SIGALI(Controllable(DoorState_Mouse_6))
                | SIGALI(S_Security(B_False(Error)))
                | SIGALI(S_Reachable(B_True(Initial_States)))
                | (| b := Simul()
                   | SIGALI(b)
                   | b ^= DoorState_Cat_1
                   |)
                |)
             | (| Error := Cat_Mouse_Room_0 default Cat_Mouse_Room_1 default Cat_Mouse_Room_2 default Cat_Mouse_Room_3 default Cat_Mouse_Room_4 default false
                | Error ^= Tick
                | Initial_States := Z_Cat_Room_2 and Z_Mouse_Room_4
                |)
             |)/ Initial_States, Error, Cat_Mouse_Room_4, Cat_Mouse_Room_3, Cat_Mouse_Room_2, Cat_Mouse_Room_1, Cat_Mouse_Room_0 |)
         where 
         boolean b, Error, Initial_States;
         event Cat_Mouse_Room_0, Cat_Mouse_Room_1, Cat_Mouse_Room_2, Cat_Mouse_Room_3, Cat_Mouse_Room_4;
         end
      ; 
      end
   ; 
   event H_0, TTick;
   end
; 

process vt =
     { integer N, NUL_CODE, LIN_CODE; }
     ( ? event HE;
     )
   (| (| (| CONTEXT{N,NUL_CODE,LIN_CODE} |)/ H_0
       | VT_Compt{}
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
                      | C_TICK := RTICK()
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
            function RESET_PANEL =
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
      function WIWRITE =
           ( ? integer ADR_COUNT;
               integer V;
           )
      
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
   process VT_Compt =
        ( ? event TTick;
        )
      (| (| Compt{}
          | Draw{}
          | cod_x := [[0] : INTERM0,[1] : INTERM1]
          | INTERM0 := (1 when New_B1) default (2 when (not New_B1)) default (0 when Tick)
          | INTERM1 := (1 when New_B2) default (2 when (not New_B2)) default (0 when Tick)
          | Mult := (true when (cod_y[0]=1)) default (false when (cod_y[0]=(-1))) default false
          | Incr := (true when (cod_u[0]=1)) default (false when (cod_u[0]=(-1))) default false
          | Incr ^= Tick
          | Mult ^= Tick
          | cod_cond := [[0] : 0 when Tick]
          | RESOLVER{1,2,1,1}
          |)/ New_B2, New_B1, CC |)
      where 
      integer INTERM0, INTERM1;
      [1]integer cod_y;
      [1]integer cod_cond;
      [2]integer cod_x;
      [1]integer cod_u;
      boolean New_B2;
      boolean B2;
      boolean B1;
      boolean New_B1;
      boolean CC;
      boolean Mult;
      boolean Incr;
      event Tick;
      process Draw =
           ( ? boolean CC;
               boolean New_B1;
               boolean New_B2;
           )
      
      ; 
      process Compt =
           ( ? boolean Incr;
               event Tick;
               boolean Mult;
             ! boolean CC;
               boolean New_B1;
               boolean B1;
               boolean B2;
               boolean New_B2;
           )
         (| (| (| (C1a,C2a,CCa) := Incr2bit{}(Incr,B1,B2)
                | (C1b,C2b,CCb) := mult2bit{}(Mult,B1,B2)
                |)
             | (| C1 := (C1a when Incr) default (C1b when Mult)
                | C2 := (C2a when Incr) default (C2b when Mult)
                | CC := (CCa when Incr) default (CCb when Mult) default false
                | (| New_B1 := C1 default B1
                   | B1 := New_B1$1 init false
                   |)
                | (| New_B2 := C2 default B2
                   | B2 := New_B2$1 init false
                   |)
                |)
             | (| Mult ^= Incr ^= Tick ^= B1 ^= B2 ^= CC |)
             |)/ C2, C1, CCb, C2b, C1b, CCa, C2a, C1a |)
         where 
         boolean C2, C1, CCb, C2b, C1b, CCa, C2a, C1a;
         process Incr2bit =
              ( ? boolean Incr;
                  boolean Bin1;
                  boolean Bin2;
                ! boolean Bout1;
                  boolean Bout2;
                  boolean Cout;
              )
            (| (| (Bout1,Cout1) := Incr1bit{}(Bin1,Incr)
                | (Bout2,Cout) := Incr1bit{}(Bin2,Cout1)
                |)/ Cout1 |)
            where 
            boolean Cout1;
            process Incr1bit =
                 ( ? boolean Bin;
                     boolean Cin;
                   ! boolean Bout;
                     boolean Cout;
                 )
               (| Bout := ((not Bin) when Cin) default Bin
                | Cout := Bin and (not Bout)
                |)
            ; 
            end
         ; 
         process mult2bit =
              ( ? boolean Mult;
                  boolean Bin1;
                  boolean Bin2;
                ! boolean Bout1;
                  boolean Bout2;
                  boolean Cout;
              )
            (| (| (Bout1,Cout1) := mult1bit{}(Bin1,false when Mult)
                | (Bout2,Cout) := mult1bit{}(Bin2,Cout1)
                |)/ Cout1 |)
            where 
            boolean Cout1;
            process mult1bit =
                 ( ? boolean Bin;
                     boolean Cin;
                   ! boolean Bout;
                     boolean Cout;
                 )
               (| Bout := Cin
                | Cout := Bin when (^Cin)
                |)
            ; 
            end
         ; 
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
        ( ? boolean Incr;
            boolean Mult;
          ! boolean CC;
            boolean New_B1;
            boolean B1;
            boolean B2;
            boolean New_B2;
        )
      (| (| (| (C1a,C2a,CCa) := Incr2bit{}(Incr,B1,B2)
             | (C1b,C2b,CCb) := mult2bit{}(Mult,B1,B2)
             |)
          | (| C1 := (C1a when Incr) default (C1b when Mult)
             | C2 := (C2a when Incr) default (C2b when Mult)
             | CC := (CCa when Incr) default (CCb when Mult) default false
             | (| New_B1 := C1 default B1
                | B1 := New_B1$1 init false
                |)
             | (| New_B2 := C2 default B2
                | B2 := New_B2$1 init false
                |)
             |)
          | (| Tick := true
             | Mult ^= Incr ^= Tick ^= B1 ^= B2 ^= CC
             | (when Mult) when Incr ^= ^0
             |)
          | (| Prop := New_B1 and New_B2
             | SIGALI(Controllable(Incr))
             | SIGALI(S_Security(B_False(Prop)))
             | SIGALI(Simul())
             |)/ Prop
          |)/ C2, C1, CCb, C2b, C1b, CCa, C2a, C1a, Tick |)
      where 
      use SIGALI; 
      boolean C2, C1, CCb, C2b, C1b, CCa, C2a, C1a;
      process Incr2bit =
           ( ? boolean Incr;
               boolean Bin1;
               boolean Bin2;
             ! boolean Bout1;
               boolean Bout2;
               boolean Cout;
           )
         (| (| (Bout1,Cout1) := Incr1bit{}(Bin1,Incr)
             | (Bout2,Cout) := Incr1bit{}(Bin2,Cout1)
             |)/ Cout1 |)
         where 
         boolean Cout1;
         process Incr1bit =
              ( ? boolean Bin;
                  boolean Cin;
                ! boolean Bout;
                  boolean Cout;
              )
            (| Bout := ((not Bin) when Cin) default Bin
             | Cout := Bin and (not Bout)
             |)
         ; 
         end
      ; 
      process mult2bit =
           ( ? boolean Mult;
               boolean Bin1;
               boolean Bin2;
             ! boolean Bout1;
               boolean Bout2;
               boolean Cout;
           )
         (| (| (Bout1,Cout1) := mult1bit{}(Bin1,false when Mult)
             | (Bout2,Cout) := mult1bit{}(Bin2,Cout1)
             |)/ Cout1 |)
         where 
         boolean Cout1;
         process mult1bit =
              ( ? boolean Bin;
                  boolean Cin;
                ! boolean Bout;
                  boolean Cout;
              )
            (| Bout := Cin
             | Cout := Bin when (^Cin)
             |)
         ; 
         end
      ; 
      end
   ; 
   event H_0, TTick;
   end
; 

process vt =
     { integer N, NUL_CODE, LIN_CODE; }
     ( ? event HE;
     )
   (| (| (| CONTEXT{N,NUL_CODE,LIN_CODE} |)/ H_0
       | (| VT_Water_Tank{} |)/ Task_1
       |)/ TTick |)
   where 
   boolean Task_1;
   use CONTEXT_LIB; 
   process VT_Water_Tank =
        ( ? event TTick;
          ! boolean Task_1;
        )
      (| (| Model{}
          | (| Valve2 := u2
             | Valve3 := u3
             | Valve4 := u4
             |)
          | (| Flow := Flow_0
             | Draw_State{}
             |) where boolean Flow; end
          | (| Flow_Pump := Pump_On
             | Flow_Valve2 := Flow_0
             | Draw{}
             |) where boolean Flow_Valve2, Flow_Pump; end
          | Scheduler{}
          | cod_x := [[0] : INTERM0,[1] : INTERM1,[2] : INTERM2,[3] : INTERM3,[4] : INTERM4,[5] : INTERM5]
          | INTERM0 := (1 when Pump_On) default (2 when (not Pump_On)) default (0 when Tick)
          | INTERM1 := (1 when X0) default (2 when (not X0)) default (0 when Tick)
          | INTERM2 := (1 when X1) default (2 when (not X1)) default (0 when Tick)
          | INTERM3 := (1 when X5) default (2 when (not X5)) default (0 when Tick)
          | INTERM4 := (1 when X6) default (2 when (not X6)) default (0 when Tick)
          | INTERM5 := (1 when X2) default (2 when (not X2)) default (0 when Tick)
          | d_normal := (true when (cod_y[0]=1)) default (false when (cod_y[0]=(-1))) default false
          | d_run := (true when (cod_y[1]=1)) default (false when (cod_y[1]=(-1))) default false
          | d_stuck := (true when (cod_y[2]=1)) default (false when (cod_y[2]=(-1))) default false
          | u1 := (true when (cod_u[0]=1)) default (false when (cod_u[0]=(-1))) default false
          | u2 := (true when (cod_u[1]=1)) default (false when (cod_u[1]=(-1))) default false
          | u3 := (true when (cod_u[2]=1)) default (false when (cod_u[2]=(-1))) default false
          | u4 := (true when (cod_u[3]=1)) default (false when (cod_u[3]=(-1))) default false
          | u1 ^= u2 ^= u3 ^= u4 ^= Tick
          | d_normal ^= d_run ^= d_stuck ^= Tick
          | cod_cond := [[0] : 0 when Tick]
          | RESOLVER{1,6,4,3}
          |)/ Valve4, Valve3, Valve2, Pump_On, Flow_0, X6, X5, X4, X3, X2, X1, X0 |)
      where 
      integer INTERM0, INTERM1, INTERM2, INTERM3, INTERM4, INTERM5;
      [3]integer cod_y;
      [1]integer cod_cond;
      [6]integer cod_x;
      [4]integer cod_u;
      boolean X6;
      boolean X5;
      boolean X4;
      boolean X3;
      boolean X2;
      boolean X1;
      boolean X0;
      boolean Flow_0;
      boolean Pump_On;
      boolean Pump_Off;
      boolean u2;
      boolean u4;
      boolean u3;
      boolean u1;
      boolean d_stuck;
      boolean d_run;
      boolean d_normal, Valve2, Valve3, Valve4;
      event Tick;
      process Model =
           ( ? boolean d_run;
               boolean d_stuck;
               boolean d_normal;
               boolean u1;
               boolean u2;
               event Tick;
               boolean u3;
               boolean u4;
             ! boolean Pump_Off;
               boolean Pump_On;
               boolean Flow_0;
               boolean X0;
               boolean X1;
               boolean X2;
               boolean X3;
               boolean X4;
               boolean X5;
               boolean X6;
           )
         (| (| Pump{}
             | (| Flow_0 := ((when u2) when Pump_On) default false
                | Flow_0 ^= Tick
                |)
             | Water_Tank{}
             | Flow{}
             | (| X0 ^= X1 ^= X2 ^= X3 ^= X4 ^= X5 ^= X6 ^= Tick ^= u1 ^= u2 ^= u3 ^= u4 ^= d_run ^= d_normal ^= d_stuck |)
             |)/ Flow2_minus, Flow_minus, Flow_plus |)
         where 
         event Flow_plus, Flow_minus, Flow2_minus;
         process Pump =
              ( ? boolean d_run;
                  boolean u1;
                  boolean d_stuck;
                  Tick;
                  boolean d_normal;
                ! boolean Pump_On;
                  boolean Pump_Off;
              )
            (| (| Inter_Pump_On := (when (u1 and d_normal)) default (when d_run) default ((not ((when (not u1)) when d_normal)) default (not (when d_stuck)))
                | Pump_On := Inter_Pump_On default Z_Pump_On
                | Z_Pump_On := Pump_On$1 init false
                |)/ Z_Pump_On, Inter_Pump_On
             | (| Inter_Pump_Off := ((when (not u1)) when d_normal) default (when d_stuck) default ((not (when (u1 and d_normal))) default (not (when d_run)))
                | Pump_Off := Inter_Pump_Off default Z_Pump_Off
                | Z_Pump_Off := Pump_Off$1 init true
                |)/ Z_Pump_Off, Inter_Pump_Off
             | Tick ^= Pump_On ^= Pump_Off ^= u1 ^= d_run ^= d_normal ^= d_stuck
             |)
         ; 
         process Flow =
              ( ? boolean Flow_0;
                  boolean u3;
                  boolean u4;
                ! event Flow_plus;
                  event Flow_minus;
                  event Flow2_minus;
              )
            (| Flow_minus := ((when Flow_0) when (u3 and u4)) default ((when (not Flow_0)) when ((u3 when (not u4)) default (u4 when (not u3))))
             | Flow2_minus := (when (not Flow_0)) when (u3 and u4)
             | Flow_plus := (when Flow_0) when (not u3) when (not u4)
             | Flow_0 ^= u3 ^= u4
             |)
         ; 
         process Water_Tank =
              ( ? event Flow_plus;
                  event Flow_minus;
                  event Flow2_minus;
                ! boolean X0;
                  boolean X1;
                  boolean X2;
                  boolean X3;
                  boolean X4;
                  boolean X5;
                  boolean X6;
              )
            (| (| Inter_X0 := (((when Flow_minus) default (when Flow2_minus)) when Z_X1) default (((when Flow_minus) default (when Flow2_minus)) when Z_X0) default ((when Flow2_minus) when Z_X2) default (not ((when Flow_plus) when Z_X0))
                | X0 := Inter_X0 default Z_X0
                | Z_X0 := X0$1 init false
                |)/ Inter_X0
             | (| Inter_X1 := ((when Flow_minus) when Z_X2) default ((when Flow2_minus) when Z_X3) default ((when Flow_plus) when Z_X0) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X1))
                | X1 := Inter_X1 default Z_X1
                | Z_X1 := X1$1 init false
                |)/ Inter_X1
             | (| Inter_X2 := ((when Flow_minus) when Z_X3) default ((when Flow2_minus) when Z_X4) default ((when Flow_plus) when Z_X1) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X2))
                | X2 := Inter_X2 default Z_X2
                | Z_X2 := X2$1 init false
                |)/ Inter_X2
             | (| Inter_X3 := ((when Flow_minus) when Z_X4) default ((when Flow2_minus) when Z_X5) default ((when Flow_plus) when Z_X2) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X3))
                | X3 := Inter_X3 default Z_X3
                | Z_X3 := X3$1 init true
                |)/ Inter_X3
             | (| Inter_X4 := ((when Flow_minus) when Z_X5) default ((when Flow2_minus) when Z_X6) default ((when Flow_plus) when Z_X3) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X4))
                | X4 := Inter_X4 default Z_X4
                | Z_X4 := X4$1 init false
                |)/ Inter_X4
             | (| Inter_X5 := ((when Flow_minus) when Z_X6) default ((when Flow_plus) when Z_X4) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X5))
                | X5 := Inter_X5 default Z_X5
                | Z_X5 := X5$1 init false
                |)/ Inter_X5
             | (| Inter_X6 := (((when Flow_plus) default (when Flow_plus)) when Z_X5) default ((when Flow_plus) when Z_X5) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X6))
                | X6 := Inter_X6 default Z_X6
                | Z_X6 := X6$1 init false
                |)/ Inter_X6
             |)
            where 
            boolean Z_X0, Z_X1, Z_X2, Z_X3, Z_X4, Z_X5, Z_X6;
            end
         ; 
         end
      ; 
      process Draw =
           ( ? boolean Flow_Pump;
               boolean Flow_Valve2;
               boolean Valve2;
               boolean Valve3;
               boolean Valve4;
           )
           spec (| Flow_Pump ^= Flow_Valve2 ^= Valve2 ^= Valve3 ^= Valve4 |)
      
      ; 
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
      
      ; 
      process Scheduler =
           ( ? event Tick;
               boolean X1;
               boolean X5;
             ! boolean Task_1;
           )
         (| (| Inter_Task_1 := (when X1) default (not (when X5))
             | Task_1 := Inter_Task_1 default Z_Task_1
             | Z_Task_1 := Task_1$1 init false
             | Task_1 ^= Tick
             |)/ Inter_Task_1, Z_Task_1 |)
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
        ( ? boolean d_normal;
            boolean d_run;
            boolean d_stuck;
            boolean u1;
            boolean u3;
            boolean u4;
            boolean u2;
          ! boolean Pump_Off;
            boolean Pump_On;
            boolean Flow_0;
            boolean X0;
            boolean X1;
            boolean X2;
            boolean X3;
            boolean X4;
            boolean X5;
            boolean X6;
        )
      (| Tick := true
       | Model{}
       | (| SIGALI(Controllable(u1))
          | SIGALI(Controllable(u2))
          | SIGALI(Controllable(u3))
          | SIGALI(Controllable(u4))
          | Forbidden_States := X0 or X6
          | SIGALI(S_Security(B_False(Forbidden_States)))
          | (| b := Simul()
             | SIGALI(b)
             | b ^= u1
             |)
          |)/ Forbidden_States, b
       | (| (when d_normal) when d_run ^= ^0
          | (when d_normal) when d_stuck ^= ^0
          | (when d_run) when d_stuck ^= ^0
          |)
       |)
      where 
      event Tick;
      use SIGALI; 
      process Model =
           ( ? boolean d_run;
               boolean d_stuck;
               boolean d_normal;
               boolean u1;
               boolean u2;
               event Tick;
               boolean u3;
               boolean u4;
             ! boolean Pump_Off;
               boolean Pump_On;
               boolean Flow_0;
               boolean X0;
               boolean X1;
               boolean X2;
               boolean X3;
               boolean X4;
               boolean X5;
               boolean X6;
           )
         (| (| Pump{}
             | (| Flow_0 := ((when u2) when Pump_On) default false
                | Flow_0 ^= Tick
                |)
             | Water_Tank{}
             | Flow{}
             | (| X0 ^= X1 ^= X2 ^= X3 ^= X4 ^= X5 ^= X6 ^= Tick ^= u1 ^= u2 ^= u3 ^= u4 ^= d_run ^= d_normal ^= d_stuck |)
             |)/ Flow2_minus, Flow_minus, Flow_plus |)
         where 
         event Flow_plus, Flow_minus, Flow2_minus;
         process Pump =
              ( ? boolean d_run;
                  boolean u1;
                  boolean d_stuck;
                  Tick;
                  boolean d_normal;
                ! boolean Pump_On;
                  boolean Pump_Off;
              )
            (| (| Inter_Pump_On := (when (u1 and d_normal)) default (when d_run) default ((not ((when (not u1)) when d_normal)) default (not (when d_stuck)))
                | Pump_On := Inter_Pump_On default Z_Pump_On
                | Z_Pump_On := Pump_On$1 init false
                |)/ Z_Pump_On, Inter_Pump_On
             | (| Inter_Pump_Off := ((when (not u1)) when d_normal) default (when d_stuck) default ((not (when (u1 and d_normal))) default (not (when d_run)))
                | Pump_Off := Inter_Pump_Off default Z_Pump_Off
                | Z_Pump_Off := Pump_Off$1 init true
                |)/ Z_Pump_Off, Inter_Pump_Off
             | Tick ^= Pump_On ^= Pump_Off ^= u1 ^= d_run ^= d_normal ^= d_stuck
             |)
         ; 
         process Flow =
              ( ? boolean Flow_0;
                  boolean u3;
                  boolean u4;
                ! event Flow_plus;
                  event Flow_minus;
                  event Flow2_minus;
              )
            (| Flow_minus := ((when Flow_0) when (u3 and u4)) default ((when (not Flow_0)) when ((u3 when (not u4)) default (u4 when (not u3))))
             | Flow2_minus := (when (not Flow_0)) when (u3 and u4)
             | Flow_plus := (when Flow_0) when (not u3) when (not u4)
             | Flow_0 ^= u3 ^= u4
             |)
         ; 
         process Water_Tank =
              ( ? event Flow_plus;
                  event Flow_minus;
                  event Flow2_minus;
                ! boolean X0;
                  boolean X1;
                  boolean X2;
                  boolean X3;
                  boolean X4;
                  boolean X5;
                  boolean X6;
              )
            (| (| Inter_X0 := (((when Flow_minus) default (when Flow2_minus)) when Z_X1) default (((when Flow_minus) default (when Flow2_minus)) when Z_X0) default ((when Flow2_minus) when Z_X2) default (not ((when Flow_plus) when Z_X0))
                | X0 := Inter_X0 default Z_X0
                | Z_X0 := X0$1 init false
                |)/ Inter_X0
             | (| Inter_X1 := ((when Flow_minus) when Z_X2) default ((when Flow2_minus) when Z_X3) default ((when Flow_plus) when Z_X0) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X1))
                | X1 := Inter_X1 default Z_X1
                | Z_X1 := X1$1 init false
                |)/ Inter_X1
             | (| Inter_X2 := ((when Flow_minus) when Z_X3) default ((when Flow2_minus) when Z_X4) default ((when Flow_plus) when Z_X1) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X2))
                | X2 := Inter_X2 default Z_X2
                | Z_X2 := X2$1 init false
                |)/ Inter_X2
             | (| Inter_X3 := ((when Flow_minus) when Z_X4) default ((when Flow2_minus) when Z_X5) default ((when Flow_plus) when Z_X2) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X3))
                | X3 := Inter_X3 default Z_X3
                | Z_X3 := X3$1 init true
                |)/ Inter_X3
             | (| Inter_X4 := ((when Flow_minus) when Z_X5) default ((when Flow2_minus) when Z_X6) default ((when Flow_plus) when Z_X3) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X4))
                | X4 := Inter_X4 default Z_X4
                | Z_X4 := X4$1 init false
                |)/ Inter_X4
             | (| Inter_X5 := ((when Flow_minus) when Z_X6) default ((when Flow_plus) when Z_X4) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X5))
                | X5 := Inter_X5 default Z_X5
                | Z_X5 := X5$1 init false
                |)/ Inter_X5
             | (| Inter_X6 := (((when Flow_plus) default (when Flow_plus)) when Z_X5) default ((when Flow_plus) when Z_X5) default (not ((when (Flow_plus default Flow_minus default Flow2_minus)) when Z_X6))
                | X6 := Inter_X6 default Z_X6
                | Z_X6 := X6$1 init false
                |)/ Inter_X6
             |)
            where 
            boolean Z_X0, Z_X1, Z_X2, Z_X3, Z_X4, Z_X5, Z_X6;
            end
         ; 
         end
      ; 
      end
   ; 
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
   event H_0, TTick;
   end
; 

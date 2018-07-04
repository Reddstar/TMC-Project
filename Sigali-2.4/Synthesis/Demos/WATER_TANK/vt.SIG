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

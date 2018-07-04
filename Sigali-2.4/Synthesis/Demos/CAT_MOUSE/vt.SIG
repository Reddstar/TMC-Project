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

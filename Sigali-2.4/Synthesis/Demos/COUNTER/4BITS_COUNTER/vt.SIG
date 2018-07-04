process vt =
     ( ? boolean Incr;
         boolean Mult;
       ! boolean CC;
         boolean C1;
         boolean C2;
         boolean C3;
         boolean C4;
     )
   (| (| (C1a,C2a,C3a,C4a,CCa) := Incr4bit(B1,B2,Incr,B3,B4)
       | (C1b,C2b,C3b,C4b,CCb) := mult4bit(Mult,B1,B2,B3,B4)
       | (| C1 := (C1a when Incr) default (C1b when Mult)
          | C2 := (C2a when Incr) default (C2b when Mult)
          | C3 := (C3a when Incr) default (C3b when Mult)
          | C4 := (C4a when Incr) default (C4b when Mult)
          | CC := (CCa when Incr) default (CCb when Mult) default false
          |)
       | (| (| New_B1 := C1 default B1
             | B1 := New_B1$1 init false
             |)
          | (| New_B2 := C2 default B2
             | B2 := New_B2$1 init false
             |)
          | (| New_B3 := C3 default B3
             | B3 := New_B3$1 init false
             |)
          | (| New_B4 := C4 default B4
             | B4 := New_B4$1 init false
             |)
          | B1 ^= B2 ^= B3 ^= B4 ^= Tick
          |)/ New_B1, New_B2, New_B3, New_B4
       | (| Tick := true
          | Incr ^= Mult ^= Tick ^= CC
          | (when Incr) when Mult ^= ^0
          | Forbidden_state := B1 and B2 and B3 and B4
          | SIGALI(Controllable(Incr))
          | SIGALI(Controllable(Mult))
          | SIGALI(S_Security(B_False(Forbidden_state)))
          | SIGALI(Simul())
          |)/ Forbidden_state
       |)/ B4, B3, B2, B1, CCb, C4b, C3b, C2b, C1b, CCa, C4a, C3a, C2a, C1a |)
   where 
   use SIGALI; 
   event Tick;
   process mult4bit =
        ( ? boolean Mult;
            boolean B1;
            boolean B2;
            boolean B3;
            boolean B4;
          ! boolean C1;
            boolean C2;
            boolean C3;
            boolean C4;
            boolean CC;
        )
      (| (| (C1,C2,CCa) := mult2bit(false when Mult,B1,B2)
          | (C3,C4,CC) := mult2bit(CCa,B3,B4)
          |)/ CCa |)
      where 
      process mult2bit =
           ( ? boolean Mult;
               boolean Bin1;
               boolean Bin2;
             ! boolean Bout1;
               boolean Bout2;
               boolean Cout;
           )
         (| (| (Bout1,Cout1) := mult1bit{}(Bin1,Mult)
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
      boolean CCa;
      end
   ; 
   process Incr4bit =
        ( ? boolean B1;
            boolean B2;
            boolean Incr;
            boolean B3;
            boolean B4;
          ! boolean C1;
            boolean C2;
            boolean C3;
            boolean C4;
            boolean CC;
        )
      (| (| (C1,C2,CCa) := Incr2bit{}(Incr,B1,B2)
          | (C3,C4,CC) := Incr2bit{}(CCa,B3,B4)
          |)/ CCa |)
      where 
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
      boolean CCa;
      end
   ; 
   boolean C1a, C2a, C3a, C4a, CCa, C1b, C2b, C3b, C4b, CCb, B1, B2, B3, B4;
   end
; 

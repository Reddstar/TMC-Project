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

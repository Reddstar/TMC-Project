module SIGALI =
   pragmas 
      COMMENT " SIGALI predefined library "
   end pragmas
   type setOfStates = boolean;
   process Simul =
        ( ! boolean RESULT;
        )
      pragmas 
         SIGALI ""
         COMMENT "simul(S,nom_fichier1,nom_fichier2)        "
                 " creates a controller at the right format so that it can be "
                 " read by the C resolver  function. The result is given by two files"
                 " name_of_the_process.sim/.res   (Cf. Sigali User-manual for more details)"
      end pragmas
   
   %Simul%; 
   process Controllable =
        ( ? boolean E;
          ! boolean F;
        )
        spec (| E ^= F |)
      pragmas 
         SIGALI ""
         COMMENT " Allows to define the events (Input variables) that will be controllable for"
                 " controller synthesis purposes"
      end pragmas
   
   %Controllable%; 
   process SIGALI =
        ( ? boolean E;
        )
      pragmas 
         SIGALI ""
         COMMENT "In case of verification the E expression  will be evaluated by the sigali tool."
                 "In case of synthesis, the sigali tool will produce the controlled system according to the E expression."
                 "In case of controllable, the E input variable will be considered as controllable."
                 "In case of simulation, see Simul process %function%comment."
      end pragmas
   
   %SIGALI%; 
   process B_True =
        ( ? boolean A;
          ! setOfStates PROP;
        )
        spec (| A ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Will compute the set of states where boolean A is true"
      end pragmas
   
   %B_True%; 
   process B_False =
        ( ? boolean A;
          ! setOfStates PROP;
        )
        spec (| A ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Compute  the set of states where boolean A is false"
      end pragmas
   
   %B_False%; 
   process B_Absent =
        ( ? boolean A;
          ! setOfStates PROP;
        )
        spec (| A ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Compute  the set of states where the boolean  A is absent"
      end pragmas
   
   %B_Absent%; 
   process B_And =
        ( ? setOfStates PROP1, PROP2;
          ! setOfStates PROP;
        )
        spec (| PROP1 ^= PROP2 ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Perform the And between two set of states: "
                 " e.g. B_And(B_True(A),B_False(B)) will compute the "
                 " set of states where A is true whereas B is false"
      end pragmas
   
   %B_And%; 
   process B_Or =
        ( ? setOfStates PROP1, PROP2;
          ! setOfStates PROP;
        )
        spec (| PROP1 ^= PROP2 ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Perform the or between two set of states: "
                 " e.g. B_Or(B_True(A),B_False(B) will compute the "
                 " set of states where A is true whereas B is false"
      end pragmas
   
   %B_Or%; 
   process Complementary =
        ( ? setOfStates PROP1;
          ! setOfStates PROP;
        )
        spec (| PROP1 ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Compute the set of states where the property PROP1 is invalidated"
      end pragmas
   
   %Complementary%; 
   process Equal =
        ( ? boolean A, B;
          ! setOfStates PROP;
        )
        spec (| A ^= B ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "compute the set of states where  the boolean A is equal to the boolean B"
      end pragmas
   
   %Equal%; 
   process Synch =
        ( ? boolean A, B;
          ! setOfStates PROP;
        )
        spec (| A ^= B ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "compute the set of states where  the booleans A and B are present at the same time"
                 " respect to  the system syst. "
      end pragmas
   
   %Synch%; 
   process Always =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "invariant(SYSTEM, SET) -> BOOLEAN : invariant(syst, p) is True whenever"
                 " the  set of  states,  solution of  the  polynomial p  is invariant  with"
      end pragmas
   
   %Always%; 
   process Reachable =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Reachable(SYSTEM,  SET)  ->  BOOLEAN  :   Reachable(syst,  p)  is  True"
                 " whenever at least one of the state  of the set V(p) can be reached via a"
                 " trajectory of the system from one of the initial states."
      end pragmas
   
   %Reachable%; 
   process Never =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "Never(SYSTEM,  SET)  ->  BOOLEAN  :   Never(syst,  p)  is  True"
                 " whenever no state of V(p) can be reached from the initial states of the system"
      end pragmas
   
   %Never%; 
   process Attractivity =
        ( ? setOfStates PROP1, PROP2;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP1 ^= PROP2 |)
      pragmas 
         SIGALI ""
         COMMENT " Attractivity(SYSTEM,SET,SET)  ->  BOOLEAN :   Attractivity(p1,p2) is  True"
                 " whenever  all the  trajectories initialized  in V(p1)  reach the  set of"
                 " states   V(p2).  "
      end pragmas
   
   %Attractivity%; 
   process Invariant =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT " Same as Always"
                 " under control with respect to the  system syst. ie there is always a way"
      end pragmas
   
   %Invariant%; 
   process C_Invariant =
        ( ? boolean PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT " C_invariant(SYSTEM,  SET) ->  BOOLEAN  : c_invariant(syst,  p) is  True"
                 " whenever the set  of states, solutions of the  polynomial p is invariant"
                 " to stay inside V(p)."
                 " with respect to the system S.  The controlled system is the output of this"
      end pragmas
   
   %C_Invariant%; 
   process S_Security =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "S_Security(SYSTEM,SET)  -> SYSTEM  :  If  p encodes  a set  of  states E,"
                 "S_Security(S,p) computes a controller  that ensures  the invariance  of E"
                 " function. "
      end pragmas
   
   %S_Security%; 
   process S_Reachable =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT " S_Reachable(SYSTEM,SET)  -> SYSTEM :   If p  encodes a  set of  states E,"
                 " S_Reachable(S,p) computes a controller  that ensures the reachability of E"
                 " from  the initial  states  The controlled  system  is the  output of  this"
                 " function. "
      end pragmas
   
   %S_Reachable%; 
   process S_Attractivity =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT " S_Attractivity(SYSTEM,SET) -> SYSTEM  :  If p encodes a  set of states E,"
                 " S_Attractivity(S,p) computes a controller that ensures the attractivity of"
                 " E from  the initial  states The  controlled system is  the output  of this"
                 " function."
      end pragmas
   
   %S_Attractivity%; 
   process S_Reachable_Secur =
        ( ? setOfStates PROP;
          ! boolean RESULT;
        )
        spec (| RESULT ^= PROP |)
      pragmas 
         SIGALI ""
         COMMENT "S_Reachable_Security(SYSTEM,SET)-> SYSTEM : If  p encodes a set of states"
                 " S_Attractivity(S,p)   computes  a  controller   that  first   ensures  the"
                 " invariance of E (computation of  the greatest invariant under U-control of"
                 " E, say F, and secondly that ensures the reachability of F from the initial"
                 " states.  The controlled system is the output of this function."
      end pragmas
   
   %S_Reachable_Secur%; 
   process S_Attractivity_Secur =
        ( ? boolean SET;
          ! boolean RESULT;
        )
        spec (| RESULT ^= SET |)
      pragmas 
         SIGALI ""
         COMMENT "S_Reachable_Security(SYSTEM,SET)-> SYSTEM : If  p encodes a set of states"
                 " S_Attractivity(S,p)   computes  a  controller   that  first   ensures  the"
                 " invariance of E (computation of  the greatest invariant under U-control of"
                 " E, say F, and secondly that ensures the reachability of F from the initial"
                 " states.  The controlled system is the output of this function."
      end pragmas
   
   %S_Attractivity_Secur%; 
end %SIGALI%; 

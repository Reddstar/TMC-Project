node system(a : bool;
b : bool;
xx : bool) returns (suiv_P0_de_std_task_0 : bool;
suiv_P1_de_std_task_0 : bool;
suiv_P2_de_std_task_0 : bool;
suiv_P3_de_std_task_0 : bool;
suiv_P4_de_std_task_0 : bool;
suiv_Q1_de_std_task_0 : bool;
suiv_Q2_de_std_task_0 : bool;
suiv_Q3_de_std_task_0 : bool;
suiv_Q4_de_std_task_0 : bool);
var
   P0_de_std_task_0_Choix : bool;
   P1_de_std_task_0_Choix : bool;
   P2_de_std_task_0_Choix : bool;
   P3_de_std_task_0_Choix : bool;
   P4_de_std_task_0_Choix : bool;
   Q1_de_std_task_0_Choix : bool;
   Q2_de_std_task_0_Choix : bool;
   Q3_de_std_task_0_Choix : bool;
   Q4_de_std_task_0_Choix : bool;
   condition_de_P0_de_std_task_0_vers_P1_de_std_task_0_0 : bool;
   condition_de_P0_de_std_task_0_vers_P2_de_std_task_0_1 : bool;
   condition_de_P0_de_std_task_0_vers_P4_de_std_task_0_2 : bool;
   condition_de_P1_de_std_task_0_vers_Q1_de_std_task_0_3 : bool;
   condition_de_P1_de_std_task_0_vers_Q2_de_std_task_0_4 : bool;
   condition_de_P1_de_std_task_0_vers_Q3_de_std_task_0_5 : bool;
   condition_de_P2_de_std_task_0_vers_P3_de_std_task_0_6 : bool;
   condition_de_P4_de_std_task_0_vers_P3_de_std_task_0_7 : bool;
   condition_de_Q1_de_std_task_0_vers_P3_de_std_task_0_8 : bool;
   condition_de_Q2_de_std_task_0_vers_P3_de_std_task_0_9 : bool;
   condition_de_Q3_de_std_task_0_vers_P3_de_std_task_0_10 : bool;
   condition_de_Q3_de_std_task_0_vers_Q4_de_std_task_0_11 : bool;
   condition_de_Q4_de_std_task_0_vers_Q3_de_std_task_0_12 : bool;
   P0_de_std_task_0 : bool;
   P1_de_std_task_0 : bool;
   P2_de_std_task_0 : bool;
   P3_de_std_task_0 : bool;
   P4_de_std_task_0 : bool;
   Q1_de_std_task_0 : bool;
   Q2_de_std_task_0 : bool;
   Q3_de_std_task_0 : bool;
   Q4_de_std_task_0 : bool;
   
let
   P0_de_std_task_0_Choix=true;
   P1_de_std_task_0_Choix=false;
   P2_de_std_task_0_Choix=false;
   P3_de_std_task_0_Choix=false;
   P4_de_std_task_0_Choix=false;
   Q1_de_std_task_0_Choix=false;
   Q2_de_std_task_0_Choix=false;
   Q3_de_std_task_0_Choix=false;
   Q4_de_std_task_0_Choix=false;
   condition_de_P0_de_std_task_0_vers_P1_de_std_task_0_0=if (P0_de_std_task_0) then (a and b) else false;
   condition_de_P0_de_std_task_0_vers_P2_de_std_task_0_1=if (P0_de_std_task_0) then (not (a) and b) else false;
   condition_de_P0_de_std_task_0_vers_P4_de_std_task_0_2=if (P0_de_std_task_0) then (not (a) and not (b)) else false;
   condition_de_P1_de_std_task_0_vers_Q1_de_std_task_0_3=if (P1_de_std_task_0) then xx else false;
   condition_de_P1_de_std_task_0_vers_Q2_de_std_task_0_4=if (P1_de_std_task_0) then (not (xx) and a) else false;
   condition_de_P1_de_std_task_0_vers_Q3_de_std_task_0_5=if (P1_de_std_task_0) then (not (xx) and not (a)) else false;
   condition_de_P2_de_std_task_0_vers_P3_de_std_task_0_6=if (P2_de_std_task_0) then a else false;
   condition_de_P4_de_std_task_0_vers_P3_de_std_task_0_7=if (P4_de_std_task_0) then a else false;
   condition_de_Q1_de_std_task_0_vers_P3_de_std_task_0_8=if (Q1_de_std_task_0) then a else false;
   condition_de_Q2_de_std_task_0_vers_P3_de_std_task_0_9=if (Q2_de_std_task_0) then a else false;
   condition_de_Q3_de_std_task_0_vers_P3_de_std_task_0_10=if (Q3_de_std_task_0) then (not (xx) and a) else false;
   condition_de_Q3_de_std_task_0_vers_Q4_de_std_task_0_11=if (Q3_de_std_task_0) then xx else false;
   condition_de_Q4_de_std_task_0_vers_Q3_de_std_task_0_12=if (Q4_de_std_task_0) then a else false;
   P0_de_std_task_0=true->pre(suiv_P0_de_std_task_0);
   P1_de_std_task_0=false->pre(suiv_P1_de_std_task_0);
   P2_de_std_task_0=false->pre(suiv_P2_de_std_task_0);
   P3_de_std_task_0=false->pre(suiv_P3_de_std_task_0);
   P4_de_std_task_0=false->pre(suiv_P4_de_std_task_0);
   Q1_de_std_task_0=false->pre(suiv_Q1_de_std_task_0);
   Q2_de_std_task_0=false->pre(suiv_Q2_de_std_task_0);
   Q3_de_std_task_0=false->pre(suiv_Q3_de_std_task_0);
   Q4_de_std_task_0=false->pre(suiv_Q4_de_std_task_0);
   suiv_P0_de_std_task_0=if (P0_de_std_task_0) then not (((condition_de_P0_de_std_task_0_vers_P1_de_std_task_0_0 or 
condition_de_P0_de_std_task_0_vers_P2_de_std_task_0_1) or condition_de_P0_de_std_task_0_vers_P4_de_std_task_0_2)) else 
P0_de_std_task_0;
   suiv_P1_de_std_task_0=if (P0_de_std_task_0) then condition_de_P0_de_std_task_0_vers_P1_de_std_task_0_0 else if (P1_de_std_task_0
) then not (((condition_de_P1_de_std_task_0_vers_Q1_de_std_task_0_3 or condition_de_P1_de_std_task_0_vers_Q2_de_std_task_0_4) or 
condition_de_P1_de_std_task_0_vers_Q3_de_std_task_0_5)) else P1_de_std_task_0;
   suiv_P2_de_std_task_0=if (P0_de_std_task_0) then condition_de_P0_de_std_task_0_vers_P2_de_std_task_0_1 else if (P2_de_std_task_0
) then not (condition_de_P2_de_std_task_0_vers_P3_de_std_task_0_6) else P2_de_std_task_0;
   suiv_P3_de_std_task_0=if (P2_de_std_task_0) then condition_de_P2_de_std_task_0_vers_P3_de_std_task_0_6 else if (P3_de_std_task_0
) then true else if (P4_de_std_task_0) then condition_de_P4_de_std_task_0_vers_P3_de_std_task_0_7 else if (Q1_de_std_task_0) then 
condition_de_Q1_de_std_task_0_vers_P3_de_std_task_0_8 else if (Q2_de_std_task_0) then 
condition_de_Q2_de_std_task_0_vers_P3_de_std_task_0_9 else if (Q3_de_std_task_0) then 
condition_de_Q3_de_std_task_0_vers_P3_de_std_task_0_10 else P3_de_std_task_0;
   suiv_P4_de_std_task_0=if (P0_de_std_task_0) then condition_de_P0_de_std_task_0_vers_P4_de_std_task_0_2 else if (P4_de_std_task_0
) then not (condition_de_P4_de_std_task_0_vers_P3_de_std_task_0_7) else P4_de_std_task_0;
   suiv_Q1_de_std_task_0=if (P1_de_std_task_0) then condition_de_P1_de_std_task_0_vers_Q1_de_std_task_0_3 else if (Q1_de_std_task_0
) then not (condition_de_Q1_de_std_task_0_vers_P3_de_std_task_0_8) else Q1_de_std_task_0;
   suiv_Q2_de_std_task_0=if (P1_de_std_task_0) then condition_de_P1_de_std_task_0_vers_Q2_de_std_task_0_4 else if (Q2_de_std_task_0
) then not (condition_de_Q2_de_std_task_0_vers_P3_de_std_task_0_9) else Q2_de_std_task_0;
   suiv_Q3_de_std_task_0=if (P1_de_std_task_0) then condition_de_P1_de_std_task_0_vers_Q3_de_std_task_0_5 else if (Q3_de_std_task_0
) then not ((condition_de_Q3_de_std_task_0_vers_P3_de_std_task_0_10 or condition_de_Q3_de_std_task_0_vers_Q4_de_std_task_0_11))
 else if (Q4_de_std_task_0) then condition_de_Q4_de_std_task_0_vers_Q3_de_std_task_0_12 else Q3_de_std_task_0;
   suiv_Q4_de_std_task_0=if (Q3_de_std_task_0) then condition_de_Q3_de_std_task_0_vers_Q4_de_std_task_0_11 else if (
Q4_de_std_task_0) then not (condition_de_Q4_de_std_task_0_vers_Q3_de_std_task_0_12) else Q4_de_std_task_0;
   
tel;


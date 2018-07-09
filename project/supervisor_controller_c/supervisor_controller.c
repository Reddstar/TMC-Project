/* --- Generated the 8/7/2018 at 22:17 --- */
/* --- heptagon compiler, version 1.03.00 (compiled mon. jun. 11 20:42:30 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c supervisor_controller.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "supervisor_controller.h"

void Supervisor_controller__supervisor_controller_supervisor_c_lac_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1, int supervisor_c_rac,
  int supervisor_c_l, int supervisor_c_l5, int supervisor_c_l4,
  int supervisor_c_l3, int supervisor_c_l2, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_lac_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  int sub_11;
  int sub_12;
  int sub_13;
  int sub_14;
  int sub_15;
  int sub_16;
  int sub_17;
  int sub_18;
  int sub_19;
  int sub_20;
  int sub_21;
  int sub_22;
  int sub_23;
  int sub_24;
  int sub_25;
  int sub_26;
  int sub_27;
  int sub_28;
  int sub_29;
  int sub_30;
  int sub_31;
  int sub_32;
  int sub_33;
  sub_17 = false;
  sub_16 = sub_17;
  sub_15 = sub_16;
  sub_14 = sub_15;
  sub_13 = sub_14;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_33 = true;
  sub_32 = sub_33;
  sub_31 = sub_32;
  sub_30 = sub_31;
  sub_29 = sub_30;
  sub_28 = sub_29;
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_25 = sub_26;
  sub_24 = sub_25;
  sub_23 = sub_24;
  sub_22 = sub_23;
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  if (p_supervisor_c_lac) {
    sub_0 = sub_18;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c_lac = sub_0;;
}

void Supervisor_controller__supervisor_controller_supervisor_c_rac_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1, int supervisor_c_l,
  int supervisor_c_l5, int supervisor_c_l4, int supervisor_c_l3,
  int supervisor_c_l2, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_rac_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  int sub_11;
  int sub_12;
  int sub_13;
  int sub_14;
  int sub_15;
  int sub_16;
  int sub_17;
  int sub_18;
  int sub_19;
  int sub_20;
  int sub_21;
  int sub_22;
  int sub_23;
  int sub_24;
  int sub_25;
  int sub_26;
  int sub_27;
  int sub_28;
  int sub_29;
  int sub_30;
  int sub_31;
  sub_16 = false;
  sub_15 = sub_16;
  sub_14 = sub_15;
  sub_13 = sub_14;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_31 = true;
  sub_30 = sub_31;
  sub_29 = sub_30;
  sub_28 = sub_29;
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_25 = sub_26;
  sub_24 = sub_25;
  sub_23 = sub_24;
  sub_22 = sub_23;
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  sub_17 = sub_18;
  if (p_supervisor_c_rac) {
    sub_0 = sub_17;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c_rac = sub_0;;
}

void Supervisor_controller__supervisor_controller_supervisor_c_l_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1, int supervisor_c_l5,
  int supervisor_c_l4, int supervisor_c_l3, int supervisor_c_l2,
  int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  int sub_11;
  int sub_12;
  int sub_13;
  int sub_14;
  int sub_15;
  int sub_16;
  int sub_17;
  int sub_18;
  int sub_19;
  int sub_20;
  int sub_21;
  int sub_22;
  int sub_23;
  int sub_24;
  int sub_25;
  int sub_26;
  int sub_27;
  int sub_28;
  int sub_29;
  sub_15 = false;
  sub_14 = sub_15;
  sub_13 = sub_14;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_29 = true;
  sub_28 = sub_29;
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_25 = sub_26;
  sub_24 = sub_25;
  sub_23 = sub_24;
  sub_22 = sub_23;
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  sub_17 = sub_18;
  sub_16 = sub_17;
  if (p_supervisor_c_l) {
    sub_0 = sub_16;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c_l = sub_0;;
}

void Supervisor_controller__supervisor_controller_supervisor_c_l5_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1, int supervisor_c_l4,
  int supervisor_c_l3, int supervisor_c_l2, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l5_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  int sub_11;
  int sub_12;
  int sub_13;
  int sub_14;
  sub_14 = false;
  if (p_supervisor_c_l5) {
    sub_13 = true;
  } else {
    sub_13 = sub_14;
  };
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_0 = sub_1;
  _out->supervisor_c_l5 = sub_0;;
}

void Supervisor_controller__supervisor_controller_supervisor_c_l4_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1, int supervisor_c_l3,
  int supervisor_c_l2, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l4_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  int sub_11;
  int sub_12;
  int sub_13;
  int sub_14;
  int sub_15;
  int sub_16;
  int sub_17;
  int sub_18;
  int sub_19;
  int sub_20;
  int sub_21;
  int sub_22;
  int sub_23;
  int sub_24;
  int sub_25;
  sub_13 = false;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_25 = true;
  sub_24 = sub_25;
  sub_23 = sub_24;
  sub_22 = sub_23;
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  sub_17 = sub_18;
  sub_16 = sub_17;
  sub_15 = sub_16;
  sub_14 = sub_15;
  if (p_supervisor_c_l4) {
    sub_0 = sub_14;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c_l4 = sub_0;;
}

void Supervisor_controller__supervisor_controller_supervisor_c_l3_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1, int supervisor_c_l2,
  int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l3_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  int sub_11;
  int sub_12;
  int sub_13;
  int sub_14;
  int sub_15;
  int sub_16;
  int sub_17;
  int sub_18;
  int sub_19;
  int sub_20;
  int sub_21;
  int sub_22;
  int sub_23;
  sub_12 = false;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_23 = true;
  sub_22 = sub_23;
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  sub_17 = sub_18;
  sub_16 = sub_17;
  sub_15 = sub_16;
  sub_14 = sub_15;
  sub_13 = sub_14;
  if (p_supervisor_c_l3) {
    sub_0 = sub_13;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c_l3 = sub_0;;
}

void Supervisor_controller__supervisor_controller_supervisor_c_l2_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l2_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  int sub_11;
  sub_11 = p_supervisor_c_l2;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_0 = sub_1;
  _out->supervisor_c_l2 = sub_0;;
}

void Supervisor_controller__supervisor_controller_supervisor_c_l1_step(
  int supervisor_presence, int supervisor_turn_on_l1,
  int supervisor_turn_on_l2, int supervisor_turn_on_rl,
  int supervisor_turn_on_l, int supervisor_turn_on_rac,
  int supervisor_turn_on_lac, int supervisor_turn_on_tv,
  int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
  int supervisor_pnr_9, int supervisor_ck_11_1, int supervisor_pnr_8,
  int supervisor_ck_13_1, int supervisor_pnr_7, int supervisor_ck_15_1,
  int supervisor_pnr_6, int supervisor_ck_17_1, int supervisor_pnr_5,
  int supervisor_ck_19_1, int supervisor_pnr_4, int supervisor_ck_21_1,
  int supervisor_pnr_3, int supervisor_ck_23_1, int supervisor_pnr_2,
  int supervisor_v_116, int supervisor_v_115, int supervisor_pnr_1,
  int supervisor_v_100, int supervisor_v_99, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l5, int p_supervisor_c_l4, int p_supervisor_c_l3,
  int p_supervisor_c_l2, int p_supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l1_out* _out) {
  
  int sub_0;
  int sub_1;
  int sub_2;
  int sub_3;
  int sub_4;
  int sub_5;
  int sub_6;
  int sub_7;
  int sub_8;
  int sub_9;
  int sub_10;
  sub_10 = p_supervisor_c_l1;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_0 = sub_1;
  _out->supervisor_c_l1 = sub_0;;
}

void Supervisor_controller__supervisor_controller_step(int supervisor_presence,
                                                       int supervisor_turn_on_l1,
                                                       int supervisor_turn_on_l2,
                                                       int supervisor_turn_on_rl,
                                                       int supervisor_turn_on_l,
                                                       int supervisor_turn_on_rac,
                                                       int supervisor_turn_on_lac,
                                                       int supervisor_turn_on_tv,
                                                       int supervisor_turn_on_wm,
                                                       int supervisor_do_open,
                                                       int supervisor_ck_1,
                                                       int supervisor_pnr_9,
                                                       int supervisor_ck_11_1,
                                                       int supervisor_pnr_8,
                                                       int supervisor_ck_13_1,
                                                       int supervisor_pnr_7,
                                                       int supervisor_ck_15_1,
                                                       int supervisor_pnr_6,
                                                       int supervisor_ck_17_1,
                                                       int supervisor_pnr_5,
                                                       int supervisor_ck_19_1,
                                                       int supervisor_pnr_4,
                                                       int supervisor_ck_21_1,
                                                       int supervisor_pnr_3,
                                                       int supervisor_ck_23_1,
                                                       int supervisor_pnr_2,
                                                       int supervisor_v_116,
                                                       int supervisor_v_115,
                                                       int supervisor_pnr_1,
                                                       int supervisor_v_100,
                                                       int supervisor_v_99,
                                                       int supervisor_pnr,
                                                       int p_supervisor_c_lac,
                                                       int p_supervisor_c_rac,
                                                       int p_supervisor_c_l,
                                                       int p_supervisor_c_l5,
                                                       int p_supervisor_c_l4,
                                                       int p_supervisor_c_l3,
                                                       int p_supervisor_c_l2,
                                                       int p_supervisor_c_l1,
                                                       Supervisor_controller__supervisor_controller_out* _out) {
  Supervisor_controller__supervisor_controller_supervisor_c_lac_out Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l1_out Supervisor_controller__supervisor_controller_supervisor_c_l1_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l_out Supervisor_controller__supervisor_controller_supervisor_c_l_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l4_out Supervisor_controller__supervisor_controller_supervisor_c_l4_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l5_out Supervisor_controller__supervisor_controller_supervisor_c_l5_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l3_out Supervisor_controller__supervisor_controller_supervisor_c_l3_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l2_out Supervisor_controller__supervisor_controller_supervisor_c_l2_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_rac_out Supervisor_controller__supervisor_controller_supervisor_c_rac_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l1_step(supervisor_presence,
                                                                    supervisor_turn_on_l1,
                                                                    supervisor_turn_on_l2,
                                                                    supervisor_turn_on_rl,
                                                                    supervisor_turn_on_l,
                                                                    supervisor_turn_on_rac,
                                                                    supervisor_turn_on_lac,
                                                                    supervisor_turn_on_tv,
                                                                    supervisor_turn_on_wm,
                                                                    supervisor_do_open,
                                                                    supervisor_ck_1,
                                                                    supervisor_pnr_9,
                                                                    supervisor_ck_11_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_13_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_15_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_17_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_19_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_21_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_23_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_116,
                                                                    supervisor_v_115,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_100,
                                                                    supervisor_v_99,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l1_out_st);
  _out->supervisor_c_l1 = Supervisor_controller__supervisor_controller_supervisor_c_l1_out_st.supervisor_c_l1;
  Supervisor_controller__supervisor_controller_supervisor_c_l2_step(supervisor_presence,
                                                                    supervisor_turn_on_l1,
                                                                    supervisor_turn_on_l2,
                                                                    supervisor_turn_on_rl,
                                                                    supervisor_turn_on_l,
                                                                    supervisor_turn_on_rac,
                                                                    supervisor_turn_on_lac,
                                                                    supervisor_turn_on_tv,
                                                                    supervisor_turn_on_wm,
                                                                    supervisor_do_open,
                                                                    supervisor_ck_1,
                                                                    supervisor_pnr_9,
                                                                    supervisor_ck_11_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_13_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_15_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_17_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_19_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_21_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_23_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_116,
                                                                    supervisor_v_115,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_100,
                                                                    supervisor_v_99,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l2_out_st);
  _out->supervisor_c_l2 = Supervisor_controller__supervisor_controller_supervisor_c_l2_out_st.supervisor_c_l2;
  Supervisor_controller__supervisor_controller_supervisor_c_l3_step(supervisor_presence,
                                                                    supervisor_turn_on_l1,
                                                                    supervisor_turn_on_l2,
                                                                    supervisor_turn_on_rl,
                                                                    supervisor_turn_on_l,
                                                                    supervisor_turn_on_rac,
                                                                    supervisor_turn_on_lac,
                                                                    supervisor_turn_on_tv,
                                                                    supervisor_turn_on_wm,
                                                                    supervisor_do_open,
                                                                    supervisor_ck_1,
                                                                    supervisor_pnr_9,
                                                                    supervisor_ck_11_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_13_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_15_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_17_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_19_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_21_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_23_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_116,
                                                                    supervisor_v_115,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_100,
                                                                    supervisor_v_99,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l2,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l3_out_st);
  _out->supervisor_c_l3 = Supervisor_controller__supervisor_controller_supervisor_c_l3_out_st.supervisor_c_l3;
  Supervisor_controller__supervisor_controller_supervisor_c_l4_step(supervisor_presence,
                                                                    supervisor_turn_on_l1,
                                                                    supervisor_turn_on_l2,
                                                                    supervisor_turn_on_rl,
                                                                    supervisor_turn_on_l,
                                                                    supervisor_turn_on_rac,
                                                                    supervisor_turn_on_lac,
                                                                    supervisor_turn_on_tv,
                                                                    supervisor_turn_on_wm,
                                                                    supervisor_do_open,
                                                                    supervisor_ck_1,
                                                                    supervisor_pnr_9,
                                                                    supervisor_ck_11_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_13_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_15_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_17_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_19_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_21_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_23_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_116,
                                                                    supervisor_v_115,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_100,
                                                                    supervisor_v_99,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l3,
                                                                    _out->supervisor_c_l2,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l4_out_st);
  _out->supervisor_c_l4 = Supervisor_controller__supervisor_controller_supervisor_c_l4_out_st.supervisor_c_l4;
  Supervisor_controller__supervisor_controller_supervisor_c_l5_step(supervisor_presence,
                                                                    supervisor_turn_on_l1,
                                                                    supervisor_turn_on_l2,
                                                                    supervisor_turn_on_rl,
                                                                    supervisor_turn_on_l,
                                                                    supervisor_turn_on_rac,
                                                                    supervisor_turn_on_lac,
                                                                    supervisor_turn_on_tv,
                                                                    supervisor_turn_on_wm,
                                                                    supervisor_do_open,
                                                                    supervisor_ck_1,
                                                                    supervisor_pnr_9,
                                                                    supervisor_ck_11_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_13_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_15_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_17_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_19_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_21_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_23_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_116,
                                                                    supervisor_v_115,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_100,
                                                                    supervisor_v_99,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l4,
                                                                    _out->supervisor_c_l3,
                                                                    _out->supervisor_c_l2,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l5_out_st);
  _out->supervisor_c_l5 = Supervisor_controller__supervisor_controller_supervisor_c_l5_out_st.supervisor_c_l5;
  Supervisor_controller__supervisor_controller_supervisor_c_l_step(supervisor_presence,
                                                                   supervisor_turn_on_l1,
                                                                   supervisor_turn_on_l2,
                                                                   supervisor_turn_on_rl,
                                                                   supervisor_turn_on_l,
                                                                   supervisor_turn_on_rac,
                                                                   supervisor_turn_on_lac,
                                                                   supervisor_turn_on_tv,
                                                                   supervisor_turn_on_wm,
                                                                   supervisor_do_open,
                                                                   supervisor_ck_1,
                                                                   supervisor_pnr_9,
                                                                   supervisor_ck_11_1,
                                                                   supervisor_pnr_8,
                                                                   supervisor_ck_13_1,
                                                                   supervisor_pnr_7,
                                                                   supervisor_ck_15_1,
                                                                   supervisor_pnr_6,
                                                                   supervisor_ck_17_1,
                                                                   supervisor_pnr_5,
                                                                   supervisor_ck_19_1,
                                                                   supervisor_pnr_4,
                                                                   supervisor_ck_21_1,
                                                                   supervisor_pnr_3,
                                                                   supervisor_ck_23_1,
                                                                   supervisor_pnr_2,
                                                                   supervisor_v_116,
                                                                   supervisor_v_115,
                                                                   supervisor_pnr_1,
                                                                   supervisor_v_100,
                                                                   supervisor_v_99,
                                                                   supervisor_pnr,
                                                                   p_supervisor_c_lac,
                                                                   p_supervisor_c_rac,
                                                                   p_supervisor_c_l,
                                                                   p_supervisor_c_l5,
                                                                   p_supervisor_c_l4,
                                                                   p_supervisor_c_l3,
                                                                   p_supervisor_c_l2,
                                                                   p_supervisor_c_l1,
                                                                   _out->supervisor_c_l5,
                                                                   _out->supervisor_c_l4,
                                                                   _out->supervisor_c_l3,
                                                                   _out->supervisor_c_l2,
                                                                   _out->supervisor_c_l1,
                                                                   &Supervisor_controller__supervisor_controller_supervisor_c_l_out_st);
  _out->supervisor_c_l = Supervisor_controller__supervisor_controller_supervisor_c_l_out_st.supervisor_c_l;
  Supervisor_controller__supervisor_controller_supervisor_c_rac_step(
  supervisor_presence, supervisor_turn_on_l1, supervisor_turn_on_l2,
  supervisor_turn_on_rl, supervisor_turn_on_l, supervisor_turn_on_rac,
  supervisor_turn_on_lac, supervisor_turn_on_tv, supervisor_turn_on_wm,
  supervisor_do_open, supervisor_ck_1, supervisor_pnr_9, supervisor_ck_11_1,
  supervisor_pnr_8, supervisor_ck_13_1, supervisor_pnr_7, supervisor_ck_15_1,
  supervisor_pnr_6, supervisor_ck_17_1, supervisor_pnr_5, supervisor_ck_19_1,
  supervisor_pnr_4, supervisor_ck_21_1, supervisor_pnr_3, supervisor_ck_23_1,
  supervisor_pnr_2, supervisor_v_116, supervisor_v_115, supervisor_pnr_1,
  supervisor_v_100, supervisor_v_99, supervisor_pnr, p_supervisor_c_lac,
  p_supervisor_c_rac, p_supervisor_c_l, p_supervisor_c_l5, p_supervisor_c_l4,
  p_supervisor_c_l3, p_supervisor_c_l2, p_supervisor_c_l1,
  _out->supervisor_c_l, _out->supervisor_c_l5, _out->supervisor_c_l4,
  _out->supervisor_c_l3, _out->supervisor_c_l2, _out->supervisor_c_l1,
  &Supervisor_controller__supervisor_controller_supervisor_c_rac_out_st);
  _out->supervisor_c_rac = Supervisor_controller__supervisor_controller_supervisor_c_rac_out_st.supervisor_c_rac;
  Supervisor_controller__supervisor_controller_supervisor_c_lac_step(
  supervisor_presence, supervisor_turn_on_l1, supervisor_turn_on_l2,
  supervisor_turn_on_rl, supervisor_turn_on_l, supervisor_turn_on_rac,
  supervisor_turn_on_lac, supervisor_turn_on_tv, supervisor_turn_on_wm,
  supervisor_do_open, supervisor_ck_1, supervisor_pnr_9, supervisor_ck_11_1,
  supervisor_pnr_8, supervisor_ck_13_1, supervisor_pnr_7, supervisor_ck_15_1,
  supervisor_pnr_6, supervisor_ck_17_1, supervisor_pnr_5, supervisor_ck_19_1,
  supervisor_pnr_4, supervisor_ck_21_1, supervisor_pnr_3, supervisor_ck_23_1,
  supervisor_pnr_2, supervisor_v_116, supervisor_v_115, supervisor_pnr_1,
  supervisor_v_100, supervisor_v_99, supervisor_pnr, p_supervisor_c_lac,
  p_supervisor_c_rac, p_supervisor_c_l, p_supervisor_c_l5, p_supervisor_c_l4,
  p_supervisor_c_l3, p_supervisor_c_l2, p_supervisor_c_l1,
  _out->supervisor_c_rac, _out->supervisor_c_l, _out->supervisor_c_l5,
  _out->supervisor_c_l4, _out->supervisor_c_l3, _out->supervisor_c_l2,
  _out->supervisor_c_l1,
  &Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st);
  _out->supervisor_c_lac = Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st.supervisor_c_lac;
}


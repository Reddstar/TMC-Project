/* --- Generated the 4/7/2018 at 11:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
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
  int supervisor_v_121, int supervisor_v_120, int supervisor_pnr_1,
  int supervisor_v_105, int supervisor_v_104, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l4, int p_supervisor_c_l3, int p_supervisor_c_l2,
  int p_supervisor_c_l1, int supervisor_c_rac, int supervisor_c_l,
  int supervisor_c_l4, int supervisor_c_l3, int supervisor_c_l2,
  int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_lac_out* _out) {
  
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
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
  int sub_34;
  int sub_35;
  int sub_36;
  int sub_37;
  int sub_38;
  int sub_39;
  sub_15 = false;
  sub_14 = sub_15;
  sub_13 = sub_14;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  if (supervisor_turn_on_l2) {
    sub_18 = sub_12;
  } else {
    sub_18 = false;
  };
  if (supervisor_c_l3) {
    v_6 = sub_18;
  } else {
    v_6 = false;
  };
  if (supervisor_c_l4) {
    sub_17 = sub_9;
  } else {
    sub_17 = v_6;
  };
  if (supervisor_turn_on_l2) {
    sub_19 = false;
  } else {
    sub_19 = sub_12;
  };
  if (supervisor_c_l3) {
    v_7 = sub_19;
  } else {
    v_7 = sub_10;
  };
  if (supervisor_c_l4) {
    v_8 = false;
  } else {
    v_8 = v_7;
  };
  if (supervisor_ck_13_1) {
    sub_16 = v_8;
  } else {
    sub_16 = sub_17;
  };
  if (supervisor_ck_11_1) {
    sub_7 = sub_16;
    v_5 = sub_8;
  } else {
    sub_7 = sub_8;
    v_5 = sub_16;
  };
  if (supervisor_c_l2) {
    sub_20 = sub_7;
  } else {
    sub_20 = v_5;
  };
  if (supervisor_c_l1) {
    v_9 = sub_7;
  } else {
    v_9 = sub_20;
  };
  if (supervisor_turn_on_l1) {
    sub_6 = v_9;
  } else {
    sub_6 = sub_20;
  };
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_34 = true;
  sub_33 = sub_34;
  sub_32 = sub_33;
  sub_31 = sub_32;
  sub_30 = sub_31;
  sub_29 = sub_30;
  sub_28 = sub_29;
  sub_27 = sub_28;
  if (supervisor_turn_on_l2) {
    sub_37 = sub_31;
  } else {
    sub_37 = false;
  };
  if (supervisor_c_l3) {
    v_1 = sub_37;
  } else {
    v_1 = false;
  };
  if (supervisor_c_l4) {
    sub_36 = sub_28;
  } else {
    sub_36 = v_1;
  };
  if (supervisor_turn_on_l2) {
    sub_38 = false;
  } else {
    sub_38 = sub_31;
  };
  if (supervisor_c_l3) {
    v_2 = sub_38;
  } else {
    v_2 = sub_29;
  };
  if (supervisor_c_l4) {
    v_3 = false;
  } else {
    v_3 = v_2;
  };
  if (supervisor_ck_13_1) {
    sub_35 = v_3;
  } else {
    sub_35 = sub_36;
  };
  if (supervisor_ck_11_1) {
    sub_26 = sub_35;
    v = sub_27;
  } else {
    sub_26 = sub_27;
    v = sub_35;
  };
  if (supervisor_c_l2) {
    sub_39 = sub_26;
  } else {
    sub_39 = v;
  };
  if (supervisor_c_l1) {
    v_4 = sub_26;
  } else {
    v_4 = sub_39;
  };
  if (supervisor_turn_on_l1) {
    sub_25 = v_4;
  } else {
    sub_25 = sub_39;
  };
  sub_24 = sub_25;
  sub_23 = sub_24;
  sub_22 = sub_23;
  sub_21 = sub_22;
  if (p_supervisor_c_lac) {
    sub_0 = sub_21;
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
  int supervisor_v_121, int supervisor_v_120, int supervisor_pnr_1,
  int supervisor_v_105, int supervisor_v_104, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l4, int p_supervisor_c_l3, int p_supervisor_c_l2,
  int p_supervisor_c_l1, int supervisor_c_l, int supervisor_c_l4,
  int supervisor_c_l3, int supervisor_c_l2, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_rac_out* _out) {
  
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v;
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
  int sub_34;
  int sub_35;
  int sub_36;
  int sub_37;
  sub_14 = false;
  sub_13 = sub_14;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  if (supervisor_turn_on_l2) {
    sub_17 = sub_11;
  } else {
    sub_17 = false;
  };
  if (supervisor_c_l3) {
    v_15 = sub_17;
  } else {
    v_15 = false;
  };
  if (supervisor_c_l4) {
    sub_16 = sub_8;
  } else {
    sub_16 = v_15;
  };
  if (supervisor_turn_on_l2) {
    sub_18 = false;
  } else {
    sub_18 = sub_11;
  };
  if (supervisor_c_l3) {
    v_16 = sub_18;
  } else {
    v_16 = sub_9;
  };
  if (supervisor_c_l4) {
    v_17 = false;
  } else {
    v_17 = v_16;
  };
  if (supervisor_ck_13_1) {
    sub_15 = v_17;
  } else {
    sub_15 = sub_16;
  };
  if (supervisor_ck_11_1) {
    sub_6 = sub_15;
    v_14 = sub_7;
  } else {
    sub_6 = sub_7;
    v_14 = sub_15;
  };
  if (supervisor_c_l2) {
    sub_19 = sub_6;
  } else {
    sub_19 = v_14;
  };
  if (supervisor_c_l1) {
    v_18 = sub_6;
  } else {
    v_18 = sub_19;
  };
  if (supervisor_turn_on_l1) {
    sub_5 = v_18;
  } else {
    sub_5 = sub_19;
  };
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_32 = true;
  sub_31 = sub_32;
  sub_30 = sub_31;
  sub_29 = sub_30;
  sub_28 = sub_29;
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_25 = sub_26;
  if (supervisor_turn_on_l2) {
    sub_35 = sub_29;
  } else {
    sub_35 = false;
  };
  if (supervisor_c_l3) {
    v_10 = sub_35;
  } else {
    v_10 = false;
  };
  if (supervisor_c_l4) {
    sub_34 = sub_26;
  } else {
    sub_34 = v_10;
  };
  if (supervisor_turn_on_l2) {
    sub_36 = false;
  } else {
    sub_36 = sub_29;
  };
  if (supervisor_c_l3) {
    v_11 = sub_36;
  } else {
    v_11 = sub_27;
  };
  if (supervisor_c_l4) {
    v_12 = false;
  } else {
    v_12 = v_11;
  };
  if (supervisor_ck_13_1) {
    sub_33 = v_12;
  } else {
    sub_33 = sub_34;
  };
  if (supervisor_ck_11_1) {
    sub_24 = sub_33;
    v = sub_25;
  } else {
    sub_24 = sub_25;
    v = sub_33;
  };
  if (supervisor_c_l2) {
    sub_37 = sub_24;
  } else {
    sub_37 = v;
  };
  if (supervisor_c_l1) {
    v_13 = sub_24;
  } else {
    v_13 = sub_37;
  };
  if (supervisor_turn_on_l1) {
    sub_23 = v_13;
  } else {
    sub_23 = sub_37;
  };
  sub_22 = sub_23;
  sub_21 = sub_22;
  sub_20 = sub_21;
  if (p_supervisor_c_rac) {
    sub_0 = sub_20;
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
  int supervisor_v_121, int supervisor_v_120, int supervisor_pnr_1,
  int supervisor_v_105, int supervisor_v_104, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l4, int p_supervisor_c_l3, int p_supervisor_c_l2,
  int p_supervisor_c_l1, int supervisor_c_l4, int supervisor_c_l3,
  int supervisor_c_l2, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l_out* _out) {
  
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v;
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
  int sub_34;
  int sub_35;
  sub_13 = false;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  if (supervisor_turn_on_l2) {
    sub_16 = sub_10;
  } else {
    sub_16 = false;
  };
  if (supervisor_c_l3) {
    v_24 = sub_16;
  } else {
    v_24 = false;
  };
  if (supervisor_c_l4) {
    sub_15 = sub_7;
  } else {
    sub_15 = v_24;
  };
  if (supervisor_turn_on_l2) {
    sub_17 = false;
  } else {
    sub_17 = sub_10;
  };
  if (supervisor_c_l3) {
    v_25 = sub_17;
  } else {
    v_25 = sub_8;
  };
  if (supervisor_c_l4) {
    v_26 = false;
  } else {
    v_26 = v_25;
  };
  if (supervisor_ck_13_1) {
    sub_14 = v_26;
  } else {
    sub_14 = sub_15;
  };
  if (supervisor_ck_11_1) {
    sub_5 = sub_14;
    v_23 = sub_6;
  } else {
    sub_5 = sub_6;
    v_23 = sub_14;
  };
  if (supervisor_c_l2) {
    sub_18 = sub_5;
  } else {
    sub_18 = v_23;
  };
  if (supervisor_c_l1) {
    v_27 = sub_5;
  } else {
    v_27 = sub_18;
  };
  if (supervisor_turn_on_l1) {
    sub_4 = v_27;
  } else {
    sub_4 = sub_18;
  };
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_30 = true;
  sub_29 = sub_30;
  sub_28 = sub_29;
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_25 = sub_26;
  sub_24 = sub_25;
  sub_23 = sub_24;
  if (supervisor_turn_on_l2) {
    sub_33 = sub_27;
  } else {
    sub_33 = false;
  };
  if (supervisor_c_l3) {
    v_19 = sub_33;
  } else {
    v_19 = false;
  };
  if (supervisor_c_l4) {
    sub_32 = sub_24;
  } else {
    sub_32 = v_19;
  };
  if (supervisor_turn_on_l2) {
    sub_34 = false;
  } else {
    sub_34 = sub_27;
  };
  if (supervisor_c_l3) {
    v_20 = sub_34;
  } else {
    v_20 = sub_25;
  };
  if (supervisor_c_l4) {
    v_21 = false;
  } else {
    v_21 = v_20;
  };
  if (supervisor_ck_13_1) {
    sub_31 = v_21;
  } else {
    sub_31 = sub_32;
  };
  if (supervisor_ck_11_1) {
    sub_22 = sub_31;
    v = sub_23;
  } else {
    sub_22 = sub_23;
    v = sub_31;
  };
  if (supervisor_c_l2) {
    sub_35 = sub_22;
  } else {
    sub_35 = v;
  };
  if (supervisor_c_l1) {
    v_22 = sub_22;
  } else {
    v_22 = sub_35;
  };
  if (supervisor_turn_on_l1) {
    sub_21 = v_22;
  } else {
    sub_21 = sub_35;
  };
  sub_20 = sub_21;
  sub_19 = sub_20;
  if (p_supervisor_c_l) {
    sub_0 = sub_19;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c_l = sub_0;;
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
  int supervisor_v_121, int supervisor_v_120, int supervisor_pnr_1,
  int supervisor_v_105, int supervisor_v_104, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l4, int p_supervisor_c_l3, int p_supervisor_c_l2,
  int p_supervisor_c_l1, int supervisor_c_l3, int supervisor_c_l2,
  int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l4_out* _out) {
  
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v;
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
  sub_12 = false;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_19 = true;
  sub_18 = sub_19;
  sub_17 = sub_18;
  sub_16 = sub_17;
  if (supervisor_turn_on_l2) {
    sub_15 = sub_9;
  } else {
    sub_15 = sub_16;
  };
  sub_21 = sub_16;
  sub_20 = sub_21;
  if (supervisor_c_l3) {
    sub_14 = sub_15;
  } else {
    sub_14 = sub_20;
  };
  if (supervisor_turn_on_l2) {
    sub_23 = false;
  } else {
    sub_23 = sub_9;
  };
  if (supervisor_c_l3) {
    sub_22 = sub_23;
  } else {
    sub_22 = sub_7;
  };
  if (supervisor_ck_13_1) {
    sub_13 = sub_22;
  } else {
    sub_13 = sub_14;
  };
  if (supervisor_ck_11_1) {
    sub_5 = sub_13;
    v_28 = sub_6;
  } else {
    sub_5 = sub_6;
    v_28 = sub_13;
  };
  if (supervisor_c_l2) {
    sub_24 = sub_5;
  } else {
    sub_24 = v_28;
  };
  if (supervisor_c_l1) {
    v_29 = sub_5;
  } else {
    v_29 = sub_24;
  };
  if (supervisor_turn_on_l1) {
    sub_4 = v_29;
  } else {
    sub_4 = sub_24;
  };
  sub_26 = sub_20;
  if (supervisor_ck_13_1) {
    sub_27 = sub_22;
  } else {
    sub_27 = sub_26;
  };
  if (supervisor_ck_11_1) {
    sub_25 = sub_27;
    v = sub_26;
  } else {
    sub_25 = sub_26;
    v = sub_27;
  };
  if (supervisor_c_l2) {
    sub_28 = sub_25;
  } else {
    sub_28 = v;
  };
  if (supervisor_c_l1) {
    v_30 = sub_25;
  } else {
    v_30 = sub_28;
  };
  if (supervisor_turn_on_l1) {
    v_31 = v_30;
  } else {
    v_31 = sub_28;
  };
  if (p_supervisor_c_l4) {
    sub_3 = v_31;
  } else {
    sub_3 = sub_4;
  };
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_0 = sub_1;
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
  int supervisor_v_121, int supervisor_v_120, int supervisor_pnr_1,
  int supervisor_v_105, int supervisor_v_104, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l4, int p_supervisor_c_l3, int p_supervisor_c_l2,
  int p_supervisor_c_l1, int supervisor_c_l2, int supervisor_c_l1,
  Supervisor_controller__supervisor_controller_supervisor_c_l3_out* _out) {
  
  int v_32;
  int v;
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
  sub_11 = p_supervisor_c_l3;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_5 = sub_6;
  sub_16 = false;
  sub_15 = sub_16;
  sub_14 = sub_15;
  if (supervisor_turn_on_l2) {
    sub_13 = sub_14;
  } else {
    sub_13 = sub_7;
  };
  if (supervisor_ck_13_1) {
    sub_12 = sub_13;
  } else {
    sub_12 = sub_5;
  };
  if (supervisor_ck_11_1) {
    sub_4 = sub_12;
    v = sub_5;
  } else {
    sub_4 = sub_5;
    v = sub_12;
  };
  if (supervisor_c_l2) {
    sub_17 = sub_4;
  } else {
    sub_17 = v;
  };
  if (supervisor_c_l1) {
    v_32 = sub_4;
  } else {
    v_32 = sub_17;
  };
  if (supervisor_turn_on_l1) {
    sub_3 = v_32;
  } else {
    sub_3 = sub_17;
  };
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_0 = sub_1;
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
  int supervisor_v_121, int supervisor_v_120, int supervisor_pnr_1,
  int supervisor_v_105, int supervisor_v_104, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l4, int p_supervisor_c_l3, int p_supervisor_c_l2,
  int p_supervisor_c_l1, int supervisor_c_l1,
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
  int supervisor_v_121, int supervisor_v_120, int supervisor_pnr_1,
  int supervisor_v_105, int supervisor_v_104, int supervisor_pnr,
  int p_supervisor_c_lac, int p_supervisor_c_rac, int p_supervisor_c_l,
  int p_supervisor_c_l4, int p_supervisor_c_l3, int p_supervisor_c_l2,
  int p_supervisor_c_l1,
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
                                                       int supervisor_v_121,
                                                       int supervisor_v_120,
                                                       int supervisor_pnr_1,
                                                       int supervisor_v_105,
                                                       int supervisor_v_104,
                                                       int supervisor_pnr,
                                                       int p_supervisor_c_lac,
                                                       int p_supervisor_c_rac,
                                                       int p_supervisor_c_l,
                                                       int p_supervisor_c_l4,
                                                       int p_supervisor_c_l3,
                                                       int p_supervisor_c_l2,
                                                       int p_supervisor_c_l1,
                                                       Supervisor_controller__supervisor_controller_out* _out) {
  Supervisor_controller__supervisor_controller_supervisor_c_lac_out Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l1_out Supervisor_controller__supervisor_controller_supervisor_c_l1_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l_out Supervisor_controller__supervisor_controller_supervisor_c_l_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l4_out Supervisor_controller__supervisor_controller_supervisor_c_l4_out_st;
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
                                                                    supervisor_v_121,
                                                                    supervisor_v_120,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_105,
                                                                    supervisor_v_104,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
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
                                                                    supervisor_v_121,
                                                                    supervisor_v_120,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_105,
                                                                    supervisor_v_104,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
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
                                                                    supervisor_v_121,
                                                                    supervisor_v_120,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_105,
                                                                    supervisor_v_104,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
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
                                                                    supervisor_v_121,
                                                                    supervisor_v_120,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_105,
                                                                    supervisor_v_104,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l3,
                                                                    _out->supervisor_c_l2,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l4_out_st);
  _out->supervisor_c_l4 = Supervisor_controller__supervisor_controller_supervisor_c_l4_out_st.supervisor_c_l4;
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
                                                                   supervisor_v_121,
                                                                   supervisor_v_120,
                                                                   supervisor_pnr_1,
                                                                   supervisor_v_105,
                                                                   supervisor_v_104,
                                                                   supervisor_pnr,
                                                                   p_supervisor_c_lac,
                                                                   p_supervisor_c_rac,
                                                                   p_supervisor_c_l,
                                                                   p_supervisor_c_l4,
                                                                   p_supervisor_c_l3,
                                                                   p_supervisor_c_l2,
                                                                   p_supervisor_c_l1,
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
  supervisor_pnr_2, supervisor_v_121, supervisor_v_120, supervisor_pnr_1,
  supervisor_v_105, supervisor_v_104, supervisor_pnr, p_supervisor_c_lac,
  p_supervisor_c_rac, p_supervisor_c_l, p_supervisor_c_l4, p_supervisor_c_l3,
  p_supervisor_c_l2, p_supervisor_c_l1, _out->supervisor_c_l,
  _out->supervisor_c_l4, _out->supervisor_c_l3, _out->supervisor_c_l2,
  _out->supervisor_c_l1,
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
  supervisor_pnr_2, supervisor_v_121, supervisor_v_120, supervisor_pnr_1,
  supervisor_v_105, supervisor_v_104, supervisor_pnr, p_supervisor_c_lac,
  p_supervisor_c_rac, p_supervisor_c_l, p_supervisor_c_l4, p_supervisor_c_l3,
  p_supervisor_c_l2, p_supervisor_c_l1, _out->supervisor_c_rac,
  _out->supervisor_c_l, _out->supervisor_c_l4, _out->supervisor_c_l3,
  _out->supervisor_c_l2, _out->supervisor_c_l1,
  &Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st);
  _out->supervisor_c_lac = Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st.supervisor_c_lac;
}


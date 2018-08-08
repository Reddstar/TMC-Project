/* --- Generated the 8/8/2018 at 10:52 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c supervisor_controller.ept --- */

#ifndef SUPERVISOR_CONTROLLER_H
#define SUPERVISOR_CONTROLLER_H

#include "supervisor_controller_types.h"
typedef struct Supervisor_controller__supervisor_controller_supervisor_c2_lac_out {
  int supervisor_c2_lac;
} Supervisor_controller__supervisor_controller_supervisor_c2_lac_out;

void Supervisor_controller__supervisor_controller_supervisor_c2_lac_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c2_rac, int supervisor_c_lac,
int supervisor_c_rac, int supervisor_c_l5, int supervisor_c_l,
int supervisor_c_l4, int supervisor_c_l2, int supervisor_c_l3,
int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c2_lac_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c2_rac_out {
  int supervisor_c2_rac;
} Supervisor_controller__supervisor_controller_supervisor_c2_rac_out;

void Supervisor_controller__supervisor_controller_supervisor_c2_rac_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_lac, int supervisor_c_rac,
int supervisor_c_l5, int supervisor_c_l, int supervisor_c_l4,
int supervisor_c_l2, int supervisor_c_l3, int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c2_rac_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_lac_out {
  int supervisor_c_lac;
} Supervisor_controller__supervisor_controller_supervisor_c_lac_out;

void Supervisor_controller__supervisor_controller_supervisor_c_lac_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_rac, int supervisor_c_l5,
int supervisor_c_l, int supervisor_c_l4, int supervisor_c_l2,
int supervisor_c_l3, int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_lac_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_rac_out {
  int supervisor_c_rac;
} Supervisor_controller__supervisor_controller_supervisor_c_rac_out;

void Supervisor_controller__supervisor_controller_supervisor_c_rac_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_l5, int supervisor_c_l,
int supervisor_c_l4, int supervisor_c_l2, int supervisor_c_l3,
int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_rac_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_l5_out {
  int supervisor_c_l5;
} Supervisor_controller__supervisor_controller_supervisor_c_l5_out;

void Supervisor_controller__supervisor_controller_supervisor_c_l5_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_l, int supervisor_c_l4,
int supervisor_c_l2, int supervisor_c_l3, int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_l5_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_l_out {
  int supervisor_c_l;
} Supervisor_controller__supervisor_controller_supervisor_c_l_out;

void Supervisor_controller__supervisor_controller_supervisor_c_l_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_l4, int supervisor_c_l2,
int supervisor_c_l3, int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_l_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_l4_out {
  int supervisor_c_l4;
} Supervisor_controller__supervisor_controller_supervisor_c_l4_out;

void Supervisor_controller__supervisor_controller_supervisor_c_l4_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_l2, int supervisor_c_l3,
int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_l4_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_l2_out {
  int supervisor_c_l2;
} Supervisor_controller__supervisor_controller_supervisor_c_l2_out;

void Supervisor_controller__supervisor_controller_supervisor_c_l2_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_l3, int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_l2_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_l3_out {
  int supervisor_c_l3;
} Supervisor_controller__supervisor_controller_supervisor_c_l3_out;

void Supervisor_controller__supervisor_controller_supervisor_c_l3_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1, int supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_l3_out* _out);

typedef struct Supervisor_controller__supervisor_controller_supervisor_c_l1_out {
  int supervisor_c_l1;
} Supervisor_controller__supervisor_controller_supervisor_c_l1_out;

void Supervisor_controller__supervisor_controller_supervisor_c_l1_step(
int supervisor_presence, int supervisor_turn_on_l1,
int supervisor_turn_on_l2, int supervisor_turn_on_rl,
int supervisor_turn_on_l, int supervisor_turn_on_rac,
int supervisor_turn_on_lac, int supervisor_turn_on_tv,
int supervisor_turn_on_wm, int supervisor_do_open, int supervisor_ck_1,
int supervisor_pnr_9, int supervisor_ck_10_1, int supervisor_pnr_8,
int supervisor_ck_12_1, int supervisor_pnr_7, int supervisor_ck_14_1,
int supervisor_pnr_6, int supervisor_ck_16_1, int supervisor_pnr_5,
int supervisor_ck_18_1, int supervisor_pnr_4, int supervisor_ck_20_1,
int supervisor_pnr_3, int supervisor_ck_22_1, int supervisor_pnr_2,
int supervisor_v_128, int supervisor_v_127, int supervisor_pnr_1,
int supervisor_v_112, int supervisor_v_111, int supervisor_pnr,
int p_supervisor_c2_lac, int p_supervisor_c2_rac, int p_supervisor_c_lac,
int p_supervisor_c_rac, int p_supervisor_c_l5, int p_supervisor_c_l,
int p_supervisor_c_l4, int p_supervisor_c_l2, int p_supervisor_c_l3,
int p_supervisor_c_l1,
Supervisor_controller__supervisor_controller_supervisor_c_l1_out* _out);

typedef struct Supervisor_controller__supervisor_controller_out {
  int supervisor_c2_lac;
  int supervisor_c2_rac;
  int supervisor_c_lac;
  int supervisor_c_rac;
  int supervisor_c_l5;
  int supervisor_c_l;
  int supervisor_c_l4;
  int supervisor_c_l2;
  int supervisor_c_l3;
  int supervisor_c_l1;
} Supervisor_controller__supervisor_controller_out;

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
                                                       int supervisor_ck_10_1,
                                                       int supervisor_pnr_8,
                                                       int supervisor_ck_12_1,
                                                       int supervisor_pnr_7,
                                                       int supervisor_ck_14_1,
                                                       int supervisor_pnr_6,
                                                       int supervisor_ck_16_1,
                                                       int supervisor_pnr_5,
                                                       int supervisor_ck_18_1,
                                                       int supervisor_pnr_4,
                                                       int supervisor_ck_20_1,
                                                       int supervisor_pnr_3,
                                                       int supervisor_ck_22_1,
                                                       int supervisor_pnr_2,
                                                       int supervisor_v_128,
                                                       int supervisor_v_127,
                                                       int supervisor_pnr_1,
                                                       int supervisor_v_112,
                                                       int supervisor_v_111,
                                                       int supervisor_pnr,
                                                       int p_supervisor_c2_lac,
                                                       int p_supervisor_c2_rac,
                                                       int p_supervisor_c_lac,
                                                       int p_supervisor_c_rac,
                                                       int p_supervisor_c_l5,
                                                       int p_supervisor_c_l,
                                                       int p_supervisor_c_l4,
                                                       int p_supervisor_c_l2,
                                                       int p_supervisor_c_l3,
                                                       int p_supervisor_c_l1,
                                                       Supervisor_controller__supervisor_controller_out* _out);

#endif // SUPERVISOR_CONTROLLER_H

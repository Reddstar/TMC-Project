/* --- Generated the 8/8/2018 at 10:52 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s supervisor project.ept --- */

#ifndef PROJECT_H
#define PROJECT_H

#include "project_types.h"
#include "supervisor_controller.h"
typedef struct Project__living_room_presence_mem {
  int ck_1_2;
  int pnr;
} Project__living_room_presence_mem;

typedef struct Project__living_room_presence_out {
  int has_presence;
} Project__living_room_presence_out;

void Project__living_room_presence_reset(Project__living_room_presence_mem* self);

void Project__living_room_presence_step(int presence,
                                        Project__living_room_presence_out* _out,
                                        Project__living_room_presence_mem* self);

typedef struct Project__living_room_lamp_1_mem {
  int ck_1;
  int pnr;
} Project__living_room_lamp_1_mem;

typedef struct Project__living_room_lamp_1_out {
  int is_on_l1;
} Project__living_room_lamp_1_out;

void Project__living_room_lamp_1_reset(Project__living_room_lamp_1_mem* self);

void Project__living_room_lamp_1_step(int turn_on_l1, int c_l1, int c_l2,
                                      Project__living_room_lamp_1_out* _out,
                                      Project__living_room_lamp_1_mem* self);

typedef struct Project__room_lamp_mem {
  int ck_1;
  int pnr;
} Project__room_lamp_mem;

typedef struct Project__room_lamp_out {
  int is_on_l;
} Project__room_lamp_out;

void Project__room_lamp_reset(Project__room_lamp_mem* self);

void Project__room_lamp_step(int turn_on_l, int c_l1, int c_l2,
                             Project__room_lamp_out* _out,
                             Project__room_lamp_mem* self);

typedef struct Project__room_reading_lamp_mem {
  int ck_1;
  int pnr;
} Project__room_reading_lamp_mem;

typedef struct Project__room_reading_lamp_out {
  int is_on_rl;
} Project__room_reading_lamp_out;

void Project__room_reading_lamp_reset(Project__room_reading_lamp_mem* self);

void Project__room_reading_lamp_step(int turn_on_rl,
                                     Project__room_reading_lamp_out* _out,
                                     Project__room_reading_lamp_mem* self);

typedef struct Project__living_room_air_conditioner_mem {
  int v_96;
  int v_95;
  int pnr;
} Project__living_room_air_conditioner_mem;

typedef struct Project__living_room_air_conditioner_out {
  int working_state_lac;
} Project__living_room_air_conditioner_out;

void Project__living_room_air_conditioner_reset(Project__living_room_air_conditioner_mem* self);

void Project__living_room_air_conditioner_step(int turn_on_lac, int c_lac,
                                               int c2_lac,
                                               Project__living_room_air_conditioner_out* _out,
                                               Project__living_room_air_conditioner_mem* self);

typedef struct Project__tv_mem {
  int ck_1;
  int pnr;
} Project__tv_mem;

typedef struct Project__tv_out {
  int is_tv_on;
} Project__tv_out;

void Project__tv_reset(Project__tv_mem* self);

void Project__tv_step(int turn_on_tv, Project__tv_out* _out,
                      Project__tv_mem* self);

typedef struct Project__washing_machine_mem {
  int ck_1;
  int pnr;
} Project__washing_machine_mem;

typedef struct Project__washing_machine_out {
  int is_working_wm;
} Project__washing_machine_out;

void Project__washing_machine_reset(Project__washing_machine_mem* self);

void Project__washing_machine_step(int turn_on_wm,
                                   Project__washing_machine_out* _out,
                                   Project__washing_machine_mem* self);

typedef struct Project__window_mem {
  int ck_1;
  int pnr;
} Project__window_mem;

typedef struct Project__window_out {
  int is_w_opened;
} Project__window_out;

void Project__window_reset(Project__window_mem* self);

void Project__window_step(int do_open, Project__window_out* _out,
                          Project__window_mem* self);

typedef struct Project__supervisor_mem {
  int v_112;
  int v_111;
  int v_128;
  int v_127;
  int ck_22_1;
  int ck_20_1;
  int ck_18_1;
  int ck_16_1;
  int ck_14_1;
  int ck_12_1;
  int ck_10_1;
  int ck_1;
  int pnr_9;
  int pnr_8;
  int pnr_7;
  int pnr_6;
  int pnr_5;
  int pnr_4;
  int pnr_3;
  int pnr_2;
  int pnr_1;
  int pnr;
} Project__supervisor_mem;

typedef struct Project__supervisor_out {
  int has_presence;
  int is_on_l1;
  int is_on_l2;
  int is_on_rl;
  int is_on_l;
  int is_tv_on;
  int is_working_wm;
  int is_w_opened;
  int working_state_rac;
  int working_state_lac;
} Project__supervisor_out;

void Project__supervisor_reset(Project__supervisor_mem* self);

void Project__supervisor_step(int presence, int turn_on_l1, int turn_on_l2,
                              int turn_on_rl, int turn_on_l, int turn_on_rac,
                              int turn_on_lac, int turn_on_tv,
                              int turn_on_wm, int do_open,
                              Project__supervisor_out* _out,
                              Project__supervisor_mem* self);

#endif // PROJECT_H

/* --- Generated the 8/8/2018 at 10:52 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s supervisor project.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "project.h"

void Project__living_room_presence_reset(Project__living_room_presence_mem* self) {
  self->pnr = false;
  self->ck_1_2 = true;
}

void Project__living_room_presence_step(int presence,
                                        Project__living_room_presence_out* _out,
                                        Project__living_room_presence_mem* self) {
  
  int nr_St_Occupied;
  int ns_St_Occupied_1;
  int has_presence_St_Occupied;
  int nr_St_Empty;
  int ns_St_Empty_1;
  int has_presence_St_Empty;
  int ck_1_1;
  int r_St_Occupied;
  int s_St_Occupied_1;
  int r_St_Empty;
  int s_St_Empty_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1_2) {
    if (presence) {
      r_St_Empty = true;
      s_St_Empty_1 = false;
    } else {
      r_St_Empty = self->pnr;
      s_St_Empty_1 = true;
    };
    r = r_St_Empty;
    s_1 = s_St_Empty_1;
  } else {
    if (presence) {
      r_St_Occupied = true;
    } else {
      r_St_Occupied = self->pnr;
    };
    r = r_St_Occupied;
    if (presence) {
      s_St_Occupied_1 = true;
    } else {
      s_St_Occupied_1 = false;
    };
    s_1 = s_St_Occupied_1;
  };
  ck_1_1 = s_1;
  if (ck_1_1) {
    has_presence_St_Empty = false;
    nr_St_Empty = false;
    ns_St_Empty_1 = true;
    _out->has_presence = has_presence_St_Empty;
    nr = nr_St_Empty;
    ns_1 = ns_St_Empty_1;
  } else {
    has_presence_St_Occupied = true;
    _out->has_presence = has_presence_St_Occupied;
    nr_St_Occupied = false;
    nr = nr_St_Occupied;
    ns_St_Occupied_1 = false;
    ns_1 = ns_St_Occupied_1;
  };
  self->pnr = nr;
  self->ck_1_2 = ns_1;;
}

void Project__living_room_lamp_1_reset(Project__living_room_lamp_1_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Project__living_room_lamp_1_step(int turn_on_l1, int c_l1, int c_l2,
                                      Project__living_room_lamp_1_out* _out,
                                      Project__living_room_lamp_1_mem* self) {
  
  int nr_St_1_On;
  int ns_St_1_On_1;
  int is_on_l1_St_1_On;
  int nr_St_1_Off;
  int ns_St_1_Off_1;
  int is_on_l1_St_1_Off;
  int ck_2_1;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  int r_St_1_On;
  int s_St_1_On_1;
  int r_St_1_Off;
  int s_St_1_Off_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    v_4 = !(c_l2);
    v_3 = (turn_on_l1&&c_l1);
    v_5 = (v_3||v_4);
    if (v_5) {
      r_St_1_Off = true;
      s_St_1_Off_1 = false;
    } else {
      r_St_1_Off = self->pnr;
      s_St_1_Off_1 = true;
    };
    r = r_St_1_Off;
    s_1 = s_St_1_Off_1;
  } else {
    v_1 = !(c_l2);
    v = (turn_on_l1&&c_l1);
    v_2 = (v||v_1);
    if (v_2) {
      r_St_1_On = true;
    } else {
      r_St_1_On = self->pnr;
    };
    r = r_St_1_On;
    if (v_2) {
      s_St_1_On_1 = true;
    } else {
      s_St_1_On_1 = false;
    };
    s_1 = s_St_1_On_1;
  };
  ck_2_1 = s_1;
  if (ck_2_1) {
    is_on_l1_St_1_Off = false;
    nr_St_1_Off = false;
    ns_St_1_Off_1 = true;
    _out->is_on_l1 = is_on_l1_St_1_Off;
    nr = nr_St_1_Off;
    ns_1 = ns_St_1_Off_1;
  } else {
    is_on_l1_St_1_On = true;
    _out->is_on_l1 = is_on_l1_St_1_On;
    nr_St_1_On = false;
    nr = nr_St_1_On;
    ns_St_1_On_1 = false;
    ns_1 = ns_St_1_On_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__room_lamp_reset(Project__room_lamp_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Project__room_lamp_step(int turn_on_l, int c_l1, int c_l2,
                             Project__room_lamp_out* _out,
                             Project__room_lamp_mem* self) {
  
  int nr_St_2_On;
  int ns_St_2_On_1;
  int is_on_l_St_2_On;
  int nr_St_2_Off;
  int ns_St_2_Off_1;
  int is_on_l_St_2_Off;
  int ck_3_1;
  int v_8;
  int v_7;
  int v_6;
  int v;
  int r_St_2_On;
  int s_St_2_On_1;
  int r_St_2_Off;
  int s_St_2_Off_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    v_8 = (turn_on_l&&c_l1);
    if (v_8) {
      r_St_2_Off = true;
      s_St_2_Off_1 = false;
    } else {
      r_St_2_Off = self->pnr;
      s_St_2_Off_1 = true;
    };
    r = r_St_2_Off;
    s_1 = s_St_2_Off_1;
  } else {
    v_6 = !(c_l2);
    v = (turn_on_l&&c_l1);
    v_7 = (v||v_6);
    if (v_7) {
      r_St_2_On = true;
    } else {
      r_St_2_On = self->pnr;
    };
    r = r_St_2_On;
    if (v_7) {
      s_St_2_On_1 = true;
    } else {
      s_St_2_On_1 = false;
    };
    s_1 = s_St_2_On_1;
  };
  ck_3_1 = s_1;
  if (ck_3_1) {
    is_on_l_St_2_Off = false;
    nr_St_2_Off = false;
    ns_St_2_Off_1 = true;
    _out->is_on_l = is_on_l_St_2_Off;
    nr = nr_St_2_Off;
    ns_1 = ns_St_2_Off_1;
  } else {
    is_on_l_St_2_On = true;
    _out->is_on_l = is_on_l_St_2_On;
    nr_St_2_On = false;
    nr = nr_St_2_On;
    ns_St_2_On_1 = false;
    ns_1 = ns_St_2_On_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__room_reading_lamp_reset(Project__room_reading_lamp_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Project__room_reading_lamp_step(int turn_on_rl,
                                     Project__room_reading_lamp_out* _out,
                                     Project__room_reading_lamp_mem* self) {
  
  int nr_St_3_On;
  int ns_St_3_On_1;
  int is_on_rl_St_3_On;
  int nr_St_3_Off;
  int ns_St_3_Off_1;
  int is_on_rl_St_3_Off;
  int ck_4_1;
  int r_St_3_On;
  int s_St_3_On_1;
  int r_St_3_Off;
  int s_St_3_Off_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_rl) {
      r_St_3_Off = true;
      s_St_3_Off_1 = false;
    } else {
      r_St_3_Off = self->pnr;
      s_St_3_Off_1 = true;
    };
    r = r_St_3_Off;
    s_1 = s_St_3_Off_1;
  } else {
    if (turn_on_rl) {
      r_St_3_On = true;
    } else {
      r_St_3_On = self->pnr;
    };
    r = r_St_3_On;
    if (turn_on_rl) {
      s_St_3_On_1 = true;
    } else {
      s_St_3_On_1 = false;
    };
    s_1 = s_St_3_On_1;
  };
  ck_4_1 = s_1;
  if (ck_4_1) {
    is_on_rl_St_3_Off = false;
    nr_St_3_Off = false;
    ns_St_3_Off_1 = true;
    _out->is_on_rl = is_on_rl_St_3_Off;
    nr = nr_St_3_Off;
    ns_1 = ns_St_3_Off_1;
  } else {
    is_on_rl_St_3_On = true;
    _out->is_on_rl = is_on_rl_St_3_On;
    nr_St_3_On = false;
    nr = nr_St_3_On;
    ns_St_3_On_1 = false;
    ns_1 = ns_St_3_On_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__living_room_air_conditioner_reset(Project__living_room_air_conditioner_mem* self) {
  self->pnr = false;
  self->v_95 = true;
  self->v_96 = true;
}

void Project__living_room_air_conditioner_step(int turn_on_lac, int c_lac,
                                               int c2_lac,
                                               Project__living_room_air_conditioner_out* _out,
                                               Project__living_room_air_conditioner_mem* self) {
  
  int v_94;
  int v_93;
  int v_92;
  int v_91;
  int v_90;
  int v_89;
  int v_88;
  int v_87;
  int ns_St_4_Wait_2_0;
  int ns_St_4_Wait_2_1;
  int ns_St_4_On_2_0;
  int ns_St_4_On_2_1;
  int ns_St_4_Off_2_0;
  int ns_St_4_Off_2_1;
  int ck_5_2_0;
  int ck_5_2_1;
  int nr_St_4_Wait;
  int ns_St_4_Wait_2;
  int ns_St_4_Wait_1;
  int working_state_lac_St_4_Wait;
  int nr_St_4_On;
  int ns_St_4_On_2;
  int ns_St_4_On_1;
  int working_state_lac_St_4_On;
  int nr_St_4_Off;
  int ns_St_4_Off_2;
  int ns_St_4_Off_1;
  int working_state_lac_St_4_Off;
  int ck_5_2;
  int ck_5_1;
  int v_21_2_0;
  int v_21_2_1;
  int v_22;
  int v_21_2;
  int v_21_1;
  int v_20;
  int v_19;
  int v_17_2_0;
  int v_17_2_1;
  int v_15_2_0;
  int v_15_2_1;
  int v_18;
  int v_17_2;
  int v_17_1;
  int v_16;
  int v_15_2;
  int v_15_1;
  int v_14;
  int v_13;
  int v_11_2_0;
  int v_11_2_1;
  int v_9_2_0;
  int v_9_2_1;
  int v_12;
  int v_11_2;
  int v_11_1;
  int v_10;
  int v_9_2;
  int v_9_1;
  int v;
  int v_102;
  int v_101;
  int v_100;
  int v_99;
  int v_98;
  int v_97;
  int s_St_4_Wait_2_0;
  int s_St_4_Wait_2_1;
  int s_St_4_On_2_0;
  int s_St_4_On_2_1;
  int s_St_4_Off_2_0;
  int s_St_4_Off_2_1;
  int ck_2_0;
  int ck_2_1;
  int r_St_4_Wait;
  int s_St_4_Wait_2;
  int s_St_4_Wait_1;
  int r_St_4_On;
  int s_St_4_On_2;
  int s_St_4_On_1;
  int r_St_4_Off;
  int s_St_4_Off_2;
  int s_St_4_Off_1;
  int ck_2;
  int ck_1;
  int s_2_0;
  int s_2_1;
  int ns_2_0;
  int ns_2_1;
  int s_2;
  int s_1;
  int ns_2;
  int ns_1;
  int r;
  int nr;
  ck_1 = self->v_95;
  ck_2 = self->v_96;
  if (ck_1) {
    ck_2_1 = ck_2;
    if (ck_2_1) {
      v_20 = (turn_on_lac&&c2_lac);
      if (v_20) {
        v_22 = true;
        v_21_1 = false;
        v_21_2 = false;
      } else {
        v_22 = self->pnr;
        v_21_1 = true;
        v_21_2 = true;
      };
      v_19 = (turn_on_lac&&c_lac);
      if (v_19) {
        r_St_4_Off = true;
        s_St_4_Off_1 = true;
        s_St_4_Off_2 = false;
      } else {
        r_St_4_Off = v_22;
        s_St_4_Off_1 = v_21_1;
        s_St_4_Off_2 = v_21_2;
      };
      v_101 = r_St_4_Off;
      v_97 = s_St_4_Off_1;
      v_98 = s_St_4_Off_2;
      if (v_21_1) {
        v_21_2_1 = v_21_2;
      } else {
        v_21_2_0 = v_21_2;
      };
      if (s_St_4_Off_1) {
        s_St_4_Off_2_1 = s_St_4_Off_2;
      } else {
        s_St_4_Off_2_0 = s_St_4_Off_2;
      };
    } else {
      v_14 = !(c_lac);
      if (v_14) {
        v_16 = true;
        v_15_1 = true;
        v_15_2 = true;
      } else {
        v_16 = self->pnr;
        v_15_1 = true;
        v_15_2 = false;
      };
      v_13 = !(c2_lac);
      if (v_13) {
        v_18 = true;
      } else {
        v_18 = v_16;
      };
      if (turn_on_lac) {
        r_St_4_On = true;
      } else {
        r_St_4_On = v_18;
      };
      v_101 = r_St_4_On;
      if (v_13) {
        v_17_1 = false;
      } else {
        v_17_1 = v_15_1;
      };
      if (turn_on_lac) {
        s_St_4_On_1 = true;
      } else {
        s_St_4_On_1 = v_17_1;
      };
      v_97 = s_St_4_On_1;
      if (v_13) {
        v_17_2 = false;
      } else {
        v_17_2 = v_15_2;
      };
      if (turn_on_lac) {
        s_St_4_On_2 = true;
      } else {
        s_St_4_On_2 = v_17_2;
      };
      v_98 = s_St_4_On_2;
      if (v_15_1) {
        v_15_2_1 = v_15_2;
      } else {
        v_15_2_0 = v_15_2;
      };
      if (v_17_1) {
        v_17_2_1 = v_17_2;
      } else {
        v_17_2_0 = v_17_2;
      };
      if (s_St_4_On_1) {
        s_St_4_On_2_1 = s_St_4_On_2;
      } else {
        s_St_4_On_2_0 = s_St_4_On_2;
      };
    };
    s_1 = v_97;
    s_2 = v_98;
    r = v_101;
  } else {
    ck_2_0 = ck_2;
    if (ck_2_0) {
      v_102 = true;
      v_99 = true;
      v_100 = true;
    } else {
      v = !(c_lac);
      if (v) {
        v_10 = true;
      } else {
        v_10 = self->pnr;
      };
      if (c2_lac) {
        v_12 = true;
      } else {
        v_12 = v_10;
      };
      if (turn_on_lac) {
        r_St_4_Wait = true;
      } else {
        r_St_4_Wait = v_12;
      };
      v_102 = r_St_4_Wait;
      if (v) {
        v_9_1 = true;
      } else {
        v_9_1 = false;
      };
      if (c2_lac) {
        v_11_1 = true;
      } else {
        v_11_1 = v_9_1;
      };
      if (turn_on_lac) {
        s_St_4_Wait_1 = true;
      } else {
        s_St_4_Wait_1 = v_11_1;
      };
      v_99 = s_St_4_Wait_1;
      if (v) {
        v_9_2 = true;
      } else {
        v_9_2 = false;
      };
      if (c2_lac) {
        v_11_2 = false;
      } else {
        v_11_2 = v_9_2;
      };
      if (turn_on_lac) {
        s_St_4_Wait_2 = true;
      } else {
        s_St_4_Wait_2 = v_11_2;
      };
      v_100 = s_St_4_Wait_2;
    };
    s_1 = v_99;
    s_2 = v_100;
    r = v_102;
  };
  ck_5_1 = s_1;
  ck_5_2 = s_2;
  if (ck_5_1) {
    ck_5_2_1 = ck_5_2;
    if (ck_5_2_1) {
      working_state_lac_St_4_Off = 0;
      nr_St_4_Off = false;
      ns_St_4_Off_1 = true;
      ns_St_4_Off_2 = true;
      v_87 = working_state_lac_St_4_Off;
      v_93 = nr_St_4_Off;
      v_89 = ns_St_4_Off_1;
      v_90 = ns_St_4_Off_2;
      if (ns_St_4_Off_1) {
        ns_St_4_Off_2_1 = ns_St_4_Off_2;
      } else {
        ns_St_4_Off_2_0 = ns_St_4_Off_2;
      };
    } else {
      working_state_lac_St_4_On = 2;
      v_87 = working_state_lac_St_4_On;
      nr_St_4_On = false;
      v_93 = nr_St_4_On;
      ns_St_4_On_1 = true;
      v_89 = ns_St_4_On_1;
      ns_St_4_On_2 = false;
      v_90 = ns_St_4_On_2;
      if (ns_St_4_On_1) {
        ns_St_4_On_2_1 = ns_St_4_On_2;
      } else {
        ns_St_4_On_2_0 = ns_St_4_On_2;
      };
    };
    _out->working_state_lac = v_87;
    ns_1 = v_89;
    ns_2 = v_90;
    nr = v_93;
  } else {
    ck_5_2_0 = ck_5_2;
    if (ck_5_2_0) {
      v_88 = 0;
      v_94 = true;
      v_91 = true;
      v_92 = true;
    } else {
      working_state_lac_St_4_Wait = 1;
      v_88 = working_state_lac_St_4_Wait;
      nr_St_4_Wait = false;
      v_94 = nr_St_4_Wait;
      ns_St_4_Wait_1 = false;
      v_91 = ns_St_4_Wait_1;
      ns_St_4_Wait_2 = false;
      v_92 = ns_St_4_Wait_2;
    };
    _out->working_state_lac = v_88;
    ns_1 = v_91;
    ns_2 = v_92;
    nr = v_94;
  };
  if (ns_1) {
    ns_2_1 = ns_2;
  } else {
    ns_2_0 = ns_2;
  };
  if (!(ck_5_1)) {
    if (!(ck_5_2_0)) {
      if (ns_St_4_Wait_1) {
        ns_St_4_Wait_2_1 = ns_St_4_Wait_2;
      } else {
        ns_St_4_Wait_2_0 = ns_St_4_Wait_2;
      };
    };
  };
  if (s_1) {
    s_2_1 = s_2;
  } else {
    s_2_0 = s_2;
  };
  if (!(ck_1)) {
    if (!(ck_2_0)) {
      if (v_9_1) {
        v_9_2_1 = v_9_2;
      } else {
        v_9_2_0 = v_9_2;
      };
      if (v_11_1) {
        v_11_2_1 = v_11_2;
      } else {
        v_11_2_0 = v_11_2;
      };
      if (s_St_4_Wait_1) {
        s_St_4_Wait_2_1 = s_St_4_Wait_2;
      } else {
        s_St_4_Wait_2_0 = s_St_4_Wait_2;
      };
    };
  };
  self->pnr = nr;
  self->v_95 = ns_1;
  self->v_96 = ns_2;;
}

void Project__tv_reset(Project__tv_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Project__tv_step(int turn_on_tv, Project__tv_out* _out,
                      Project__tv_mem* self) {
  
  int nr_St_5_On;
  int ns_St_5_On_1;
  int is_tv_on_St_5_On;
  int nr_St_5_Off;
  int ns_St_5_Off_1;
  int is_tv_on_St_5_Off;
  int ck_6_1;
  int r_St_5_On;
  int s_St_5_On_1;
  int r_St_5_Off;
  int s_St_5_Off_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_tv) {
      r_St_5_Off = true;
      s_St_5_Off_1 = false;
    } else {
      r_St_5_Off = self->pnr;
      s_St_5_Off_1 = true;
    };
    r = r_St_5_Off;
    s_1 = s_St_5_Off_1;
  } else {
    if (turn_on_tv) {
      r_St_5_On = true;
    } else {
      r_St_5_On = self->pnr;
    };
    r = r_St_5_On;
    if (turn_on_tv) {
      s_St_5_On_1 = true;
    } else {
      s_St_5_On_1 = false;
    };
    s_1 = s_St_5_On_1;
  };
  ck_6_1 = s_1;
  if (ck_6_1) {
    is_tv_on_St_5_Off = false;
    nr_St_5_Off = false;
    ns_St_5_Off_1 = true;
    _out->is_tv_on = is_tv_on_St_5_Off;
    nr = nr_St_5_Off;
    ns_1 = ns_St_5_Off_1;
  } else {
    is_tv_on_St_5_On = true;
    _out->is_tv_on = is_tv_on_St_5_On;
    nr_St_5_On = false;
    nr = nr_St_5_On;
    ns_St_5_On_1 = false;
    ns_1 = ns_St_5_On_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__washing_machine_reset(Project__washing_machine_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Project__washing_machine_step(int turn_on_wm,
                                   Project__washing_machine_out* _out,
                                   Project__washing_machine_mem* self) {
  
  int nr_St_6_Washing;
  int ns_St_6_Washing_1;
  int is_working_wm_St_6_Washing;
  int nr_St_6_Off;
  int ns_St_6_Off_1;
  int is_working_wm_St_6_Off;
  int ck_7_1;
  int r_St_6_Washing;
  int s_St_6_Washing_1;
  int r_St_6_Off;
  int s_St_6_Off_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_wm) {
      r_St_6_Off = true;
      s_St_6_Off_1 = false;
    } else {
      r_St_6_Off = self->pnr;
      s_St_6_Off_1 = true;
    };
    r = r_St_6_Off;
    s_1 = s_St_6_Off_1;
  } else {
    if (turn_on_wm) {
      r_St_6_Washing = true;
    } else {
      r_St_6_Washing = self->pnr;
    };
    r = r_St_6_Washing;
    if (turn_on_wm) {
      s_St_6_Washing_1 = true;
    } else {
      s_St_6_Washing_1 = false;
    };
    s_1 = s_St_6_Washing_1;
  };
  ck_7_1 = s_1;
  if (ck_7_1) {
    is_working_wm_St_6_Off = false;
    nr_St_6_Off = false;
    ns_St_6_Off_1 = true;
    _out->is_working_wm = is_working_wm_St_6_Off;
    nr = nr_St_6_Off;
    ns_1 = ns_St_6_Off_1;
  } else {
    is_working_wm_St_6_Washing = true;
    _out->is_working_wm = is_working_wm_St_6_Washing;
    nr_St_6_Washing = false;
    nr = nr_St_6_Washing;
    ns_St_6_Washing_1 = false;
    ns_1 = ns_St_6_Washing_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__window_reset(Project__window_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Project__window_step(int do_open, Project__window_out* _out,
                          Project__window_mem* self) {
  
  int nr_St_7_Opened;
  int ns_St_7_Opened_1;
  int is_w_opened_St_7_Opened;
  int nr_St_7_Closed;
  int ns_St_7_Closed_1;
  int is_w_opened_St_7_Closed;
  int ck_8_1;
  int r_St_7_Opened;
  int s_St_7_Opened_1;
  int r_St_7_Closed;
  int s_St_7_Closed_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (do_open) {
      r_St_7_Closed = true;
      s_St_7_Closed_1 = false;
    } else {
      r_St_7_Closed = self->pnr;
      s_St_7_Closed_1 = true;
    };
    r = r_St_7_Closed;
    s_1 = s_St_7_Closed_1;
  } else {
    if (do_open) {
      r_St_7_Opened = true;
    } else {
      r_St_7_Opened = self->pnr;
    };
    r = r_St_7_Opened;
    if (do_open) {
      s_St_7_Opened_1 = true;
    } else {
      s_St_7_Opened_1 = false;
    };
    s_1 = s_St_7_Opened_1;
  };
  ck_8_1 = s_1;
  if (ck_8_1) {
    is_w_opened_St_7_Closed = false;
    nr_St_7_Closed = false;
    ns_St_7_Closed_1 = true;
    _out->is_w_opened = is_w_opened_St_7_Closed;
    nr = nr_St_7_Closed;
    ns_1 = ns_St_7_Closed_1;
  } else {
    is_w_opened_St_7_Opened = true;
    _out->is_w_opened = is_w_opened_St_7_Opened;
    nr_St_7_Opened = false;
    nr = nr_St_7_Opened;
    ns_St_7_Opened_1 = false;
    ns_1 = ns_St_7_Opened_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__supervisor_reset(Project__supervisor_mem* self) {
  self->pnr = false;
  self->v_111 = true;
  self->v_112 = true;
  self->pnr_1 = false;
  self->v_127 = true;
  self->v_128 = true;
  self->pnr_2 = false;
  self->ck_22_1 = true;
  self->pnr_3 = false;
  self->ck_20_1 = true;
  self->pnr_4 = false;
  self->ck_18_1 = true;
  self->pnr_5 = false;
  self->ck_16_1 = true;
  self->pnr_6 = false;
  self->ck_14_1 = true;
  self->pnr_7 = false;
  self->ck_12_1 = true;
  self->pnr_8 = false;
  self->ck_10_1 = true;
  self->pnr_9 = false;
  self->ck_1 = true;
}

void Project__supervisor_step(int presence, int turn_on_l1, int turn_on_l2,
                              int turn_on_rl, int turn_on_l, int turn_on_rac,
                              int turn_on_lac, int turn_on_tv,
                              int turn_on_wm, int do_open,
                              Project__supervisor_out* _out,
                              Project__supervisor_mem* self) {
  Supervisor_controller__supervisor_controller_out Supervisor_controller__supervisor_controller_out_st;
  
  int v_110;
  int v_109;
  int v_108;
  int v_107;
  int v_106;
  int v_105;
  int v_104;
  int v_103;
  int ns_St_8_Wait_2_0;
  int ns_St_8_Wait_2_1;
  int ns_St_8_On_2_0;
  int ns_St_8_On_2_1;
  int ns_St_8_Off_2_0;
  int ns_St_8_Off_2_1;
  int ck_27_2_0;
  int ck_27_2_1;
  int nr_St_8_Wait;
  int ns_St_8_Wait_2;
  int ns_St_8_Wait_1;
  int working_state_lac_2_St_8_Wait;
  int nr_St_8_On;
  int ns_St_8_On_2;
  int ns_St_8_On_1;
  int working_state_lac_2_St_8_On;
  int nr_St_8_Off;
  int ns_St_8_Off_2;
  int ns_St_8_Off_1;
  int working_state_lac_2_St_8_Off;
  int ck_27_2;
  int ck_27_1;
  int v_85_2_0;
  int v_85_2_1;
  int v_86;
  int v_85_2;
  int v_85_1;
  int v_84;
  int v_83;
  int v_81_2_0;
  int v_81_2_1;
  int v_79_2_0;
  int v_79_2_1;
  int v_82;
  int v_81_2;
  int v_81_1;
  int v_80;
  int v_79_2;
  int v_79_1;
  int v_78;
  int v_77;
  int v_75_2_0;
  int v_75_2_1;
  int v_73_2_0;
  int v_73_2_1;
  int v_76;
  int v_75_2;
  int v_75_1;
  int v_74;
  int v_73_2;
  int v_73_1;
  int v_72;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  int v_114;
  int v_113;
  int s_St_8_Wait_2_0;
  int s_St_8_Wait_2_1;
  int s_St_8_On_2_0;
  int s_St_8_On_2_1;
  int s_St_8_Off_2_0;
  int s_St_8_Off_2_1;
  int ck_26_2_0;
  int ck_26_2_1;
  int r_St_8_Wait;
  int s_St_8_Wait_2;
  int s_St_8_Wait_1;
  int r_St_8_On;
  int s_St_8_On_2;
  int s_St_8_On_1;
  int r_St_8_Off;
  int s_St_8_Off_2;
  int s_St_8_Off_1;
  int ck_26_2;
  int ck_26_1;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  int ns_1_St_9_Wait_2_0;
  int ns_1_St_9_Wait_2_1;
  int ns_1_St_9_On_2_0;
  int ns_1_St_9_On_2_1;
  int ns_1_St_9_Off_2_0;
  int ns_1_St_9_Off_2_1;
  int ck_25_2_0;
  int ck_25_2_1;
  int nr_1_St_9_Wait;
  int ns_1_St_9_Wait_2;
  int ns_1_St_9_Wait_1;
  int working_state_lac_1_St_9_Wait;
  int nr_1_St_9_On;
  int ns_1_St_9_On_2;
  int ns_1_St_9_On_1;
  int working_state_lac_1_St_9_On;
  int nr_1_St_9_Off;
  int ns_1_St_9_Off_2;
  int ns_1_St_9_Off_1;
  int working_state_lac_1_St_9_Off;
  int ck_25_2;
  int ck_25_1;
  int v_70_2_0;
  int v_70_2_1;
  int v_71;
  int v_70_2;
  int v_70_1;
  int v_69;
  int v_68;
  int v_66_2_0;
  int v_66_2_1;
  int v_64_2_0;
  int v_64_2_1;
  int v_67;
  int v_66_2;
  int v_66_1;
  int v_65;
  int v_64_2;
  int v_64_1;
  int v_63;
  int v_62;
  int v_60_2_0;
  int v_60_2_1;
  int v_58_2_0;
  int v_58_2_1;
  int v_61;
  int v_60_2;
  int v_60_1;
  int v_59;
  int v_58_2;
  int v_58_1;
  int v_57;
  int v_134;
  int v_133;
  int v_132;
  int v_131;
  int v_130;
  int v_129;
  int s_1_St_9_Wait_2_0;
  int s_1_St_9_Wait_2_1;
  int s_1_St_9_On_2_0;
  int s_1_St_9_On_2_1;
  int s_1_St_9_Off_2_0;
  int s_1_St_9_Off_2_1;
  int ck_24_2_0;
  int ck_24_2_1;
  int r_1_St_9_Wait;
  int s_1_St_9_Wait_2;
  int s_1_St_9_Wait_1;
  int r_1_St_9_On;
  int s_1_St_9_On_2;
  int s_1_St_9_On_1;
  int r_1_St_9_Off;
  int s_1_St_9_Off_2;
  int s_1_St_9_Off_1;
  int ck_24_2;
  int ck_24_1;
  int nr_2_St_10_Opened;
  int ns_2_St_10_Opened_1;
  int is_w_opened_1_St_10_Opened;
  int nr_2_St_10_Closed;
  int ns_2_St_10_Closed_1;
  int is_w_opened_1_St_10_Closed;
  int ck_23_1;
  int r_2_St_10_Opened;
  int s_2_St_10_Opened_1;
  int r_2_St_10_Closed;
  int s_2_St_10_Closed_1;
  int nr_3_St_11_Washing;
  int ns_3_St_11_Washing_1;
  int is_working_wm_1_St_11_Washing;
  int nr_3_St_11_Off;
  int ns_3_St_11_Off_1;
  int is_working_wm_1_St_11_Off;
  int ck_21_1;
  int r_3_St_11_Washing;
  int s_3_St_11_Washing_1;
  int r_3_St_11_Off;
  int s_3_St_11_Off_1;
  int nr_4_St_12_On;
  int ns_4_St_12_On_1;
  int is_tv_on_1_St_12_On;
  int nr_4_St_12_Off;
  int ns_4_St_12_Off_1;
  int is_tv_on_1_St_12_Off;
  int ck_19_1;
  int r_4_St_12_On;
  int s_4_St_12_On_1;
  int r_4_St_12_Off;
  int s_4_St_12_Off_1;
  int nr_5_St_13_On;
  int ns_5_St_13_On_1;
  int is_on_l_1_St_13_On;
  int nr_5_St_13_Off;
  int ns_5_St_13_Off_1;
  int is_on_l_1_St_13_Off;
  int ck_17_1;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  int r_5_St_13_On;
  int s_5_St_13_On_1;
  int r_5_St_13_Off;
  int s_5_St_13_Off_1;
  int nr_6_St_14_On;
  int ns_6_St_14_On_1;
  int is_on_rl_1_St_14_On;
  int nr_6_St_14_Off;
  int ns_6_St_14_Off_1;
  int is_on_rl_1_St_14_Off;
  int ck_15_1;
  int r_6_St_14_On;
  int s_6_St_14_On_1;
  int r_6_St_14_Off;
  int s_6_St_14_Off_1;
  int nr_7_St_15_On;
  int ns_7_St_15_On_1;
  int is_on_l1_2_St_15_On;
  int nr_7_St_15_Off;
  int ns_7_St_15_Off_1;
  int is_on_l1_2_St_15_Off;
  int ck_13_1;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_47;
  int r_7_St_15_On;
  int s_7_St_15_On_1;
  int r_7_St_15_Off;
  int s_7_St_15_Off_1;
  int nr_8_St_16_On;
  int ns_8_St_16_On_1;
  int is_on_l1_1_St_16_On;
  int nr_8_St_16_Off;
  int ns_8_St_16_Off_1;
  int is_on_l1_1_St_16_Off;
  int ck_11_1;
  int v_46;
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int r_8_St_16_On;
  int s_8_St_16_On_1;
  int r_8_St_16_Off;
  int s_8_St_16_Off_1;
  int nr_9_St_17_Occupied;
  int ns_9_St_17_Occupied_1;
  int has_presence_1_St_17_Occupied;
  int nr_9_St_17_Empty;
  int ns_9_St_17_Empty_1;
  int has_presence_1_St_17_Empty;
  int ck_9_1;
  int r_9_St_17_Occupied;
  int s_9_St_17_Occupied_1;
  int r_9_St_17_Empty;
  int s_9_St_17_Empty_1;
  int s_1_2_0;
  int s_1_2_1;
  int ns_1_2_0;
  int ns_1_2_1;
  int s_2_2_0;
  int s_2_2_1;
  int ns_2_2_0;
  int ns_2_2_1;
  int s_9_1;
  int ns_9_1;
  int r_9;
  int nr_9;
  int s_8_1;
  int ns_8_1;
  int r_8;
  int nr_8;
  int s_7_1;
  int ns_7_1;
  int r_7;
  int nr_7;
  int s_6_1;
  int ns_6_1;
  int r_6;
  int nr_6;
  int s_5_1;
  int ns_5_1;
  int r_5;
  int nr_5;
  int s_4_1;
  int ns_4_1;
  int r_4;
  int nr_4;
  int s_3_1;
  int ns_3_1;
  int r_3;
  int nr_3;
  int s_2_1;
  int ns_2_1;
  int r_2;
  int nr_2;
  int s_1_2;
  int s_1_1;
  int ns_1_2;
  int ns_1_1;
  int r_1;
  int nr_1;
  int s_2_2;
  int s_1_3;
  int ns_2_2;
  int ns_1_3;
  int r;
  int nr;
  int turn_on_lac_2;
  int c_lac_2;
  int c2_lac_2;
  int working_state_lac_2;
  int turn_on_lac_1;
  int c_lac_1;
  int c2_lac_1;
  int working_state_lac_1;
  int do_open_1;
  int is_w_opened_1;
  int turn_on_wm_1;
  int is_working_wm_1;
  int turn_on_tv_1;
  int is_tv_on_1;
  int turn_on_l_1;
  int c_l1_3;
  int c_l2_3;
  int is_on_l_1;
  int turn_on_rl_1;
  int is_on_rl_1;
  int turn_on_l1_2;
  int c_l1_2;
  int c_l2_2;
  int is_on_l1_2;
  int turn_on_l1_1;
  int c_l1_1;
  int c_l2_1;
  int is_on_l1_1;
  int presence_1;
  int has_presence_1;
  int rule6;
  int rule5;
  int rule4;
  int rule3;
  int rule2;
  int rule1;
  int v;
  int v_23;
  int v_24;
  int v_25;
  int v_26;
  int v_27;
  int v_28;
  int v_29;
  int v_30;
  int v_31;
  int v_32;
  int v_33;
  int v_34;
  int v_35;
  int v_36;
  int v_37;
  int v_38;
  int v_39;
  int v_40;
  int c2_lac;
  int c2_rac;
  int c_lac;
  int c_rac;
  int c_l5;
  int c_l;
  int c_l4;
  int c_l2;
  int c_l3;
  int c_l1;
  turn_on_lac_2 = turn_on_lac;
  ck_26_1 = self->v_111;
  ck_26_2 = self->v_112;
  turn_on_lac_1 = turn_on_rac;
  ck_24_1 = self->v_127;
  ck_24_2 = self->v_128;
  do_open_1 = do_open;
  turn_on_wm_1 = turn_on_wm;
  turn_on_tv_1 = turn_on_tv;
  turn_on_l_1 = turn_on_l;
  turn_on_rl_1 = turn_on_rl;
  turn_on_l1_2 = turn_on_l2;
  turn_on_l1_1 = turn_on_l1;
  presence_1 = presence;
  Supervisor_controller__supervisor_controller_step(presence, turn_on_l1,
                                                    turn_on_l2, turn_on_rl,
                                                    turn_on_l, turn_on_rac,
                                                    turn_on_lac, turn_on_tv,
                                                    turn_on_wm, do_open,
                                                    self->ck_1, self->pnr_9,
                                                    self->ck_10_1,
                                                    self->pnr_8,
                                                    self->ck_12_1,
                                                    self->pnr_7,
                                                    self->ck_14_1,
                                                    self->pnr_6,
                                                    self->ck_16_1,
                                                    self->pnr_5,
                                                    self->ck_18_1,
                                                    self->pnr_4,
                                                    self->ck_20_1,
                                                    self->pnr_3,
                                                    self->ck_22_1,
                                                    self->pnr_2, self->v_128,
                                                    self->v_127, self->pnr_1,
                                                    self->v_112, self->v_111,
                                                    self->pnr, true, true,
                                                    true, true, true, true,
                                                    true, true, true, true,
                                                    &Supervisor_controller__supervisor_controller_out_st);
  c2_lac = Supervisor_controller__supervisor_controller_out_st.supervisor_c2_lac;
  c2_rac = Supervisor_controller__supervisor_controller_out_st.supervisor_c2_rac;
  c_lac = Supervisor_controller__supervisor_controller_out_st.supervisor_c_lac;
  c_rac = Supervisor_controller__supervisor_controller_out_st.supervisor_c_rac;
  c_l5 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l5;
  c_l = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l;
  c_l4 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l4;
  c_l2 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l2;
  c_l3 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l3;
  c_l1 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l1;
  c_lac_2 = c_lac;
  c2_lac_2 = c2_lac;
  c_lac_1 = c_rac;
  c2_lac_1 = c2_rac;
  c_l1_3 = c_l;
  c_l2_3 = c_l5;
  c_l1_2 = c_l3;
  c_l2_2 = c_l4;
  c_l1_1 = c_l1;
  c_l2_1 = c_l2;
  if (ck_26_1) {
    ck_26_2_1 = ck_26_2;
    if (ck_26_2_1) {
      v_84 = (turn_on_lac_2&&c2_lac_2);
      if (v_84) {
        v_86 = true;
        v_85_1 = false;
        v_85_2 = false;
      } else {
        v_86 = self->pnr;
        v_85_1 = true;
        v_85_2 = true;
      };
      v_83 = (turn_on_lac_2&&c_lac_2);
      if (v_83) {
        r_St_8_Off = true;
        s_St_8_Off_1 = true;
        s_St_8_Off_2 = false;
      } else {
        r_St_8_Off = v_86;
        s_St_8_Off_1 = v_85_1;
        s_St_8_Off_2 = v_85_2;
      };
      v_117 = r_St_8_Off;
      v_113 = s_St_8_Off_1;
      v_114 = s_St_8_Off_2;
      if (v_85_1) {
        v_85_2_1 = v_85_2;
      } else {
        v_85_2_0 = v_85_2;
      };
      if (s_St_8_Off_1) {
        s_St_8_Off_2_1 = s_St_8_Off_2;
      } else {
        s_St_8_Off_2_0 = s_St_8_Off_2;
      };
    } else {
      v_78 = !(c_lac_2);
      if (v_78) {
        v_80 = true;
        v_79_1 = true;
        v_79_2 = true;
      } else {
        v_80 = self->pnr;
        v_79_1 = true;
        v_79_2 = false;
      };
      v_77 = !(c2_lac_2);
      if (v_77) {
        v_82 = true;
      } else {
        v_82 = v_80;
      };
      if (turn_on_lac_2) {
        r_St_8_On = true;
      } else {
        r_St_8_On = v_82;
      };
      v_117 = r_St_8_On;
      if (v_77) {
        v_81_1 = false;
      } else {
        v_81_1 = v_79_1;
      };
      if (turn_on_lac_2) {
        s_St_8_On_1 = true;
      } else {
        s_St_8_On_1 = v_81_1;
      };
      v_113 = s_St_8_On_1;
      if (v_77) {
        v_81_2 = false;
      } else {
        v_81_2 = v_79_2;
      };
      if (turn_on_lac_2) {
        s_St_8_On_2 = true;
      } else {
        s_St_8_On_2 = v_81_2;
      };
      v_114 = s_St_8_On_2;
      if (v_79_1) {
        v_79_2_1 = v_79_2;
      } else {
        v_79_2_0 = v_79_2;
      };
      if (v_81_1) {
        v_81_2_1 = v_81_2;
      } else {
        v_81_2_0 = v_81_2;
      };
      if (s_St_8_On_1) {
        s_St_8_On_2_1 = s_St_8_On_2;
      } else {
        s_St_8_On_2_0 = s_St_8_On_2;
      };
    };
    s_1_3 = v_113;
    s_2_2 = v_114;
    r = v_117;
  } else {
    ck_26_2_0 = ck_26_2;
    if (ck_26_2_0) {
      v_118 = true;
      v_115 = true;
      v_116 = true;
    } else {
      v_72 = !(c_lac_2);
      if (v_72) {
        v_74 = true;
      } else {
        v_74 = self->pnr;
      };
      if (c2_lac_2) {
        v_76 = true;
      } else {
        v_76 = v_74;
      };
      if (turn_on_lac_2) {
        r_St_8_Wait = true;
      } else {
        r_St_8_Wait = v_76;
      };
      v_118 = r_St_8_Wait;
      if (v_72) {
        v_73_1 = true;
      } else {
        v_73_1 = false;
      };
      if (c2_lac_2) {
        v_75_1 = true;
      } else {
        v_75_1 = v_73_1;
      };
      if (turn_on_lac_2) {
        s_St_8_Wait_1 = true;
      } else {
        s_St_8_Wait_1 = v_75_1;
      };
      v_115 = s_St_8_Wait_1;
      if (v_72) {
        v_73_2 = true;
      } else {
        v_73_2 = false;
      };
      if (c2_lac_2) {
        v_75_2 = false;
      } else {
        v_75_2 = v_73_2;
      };
      if (turn_on_lac_2) {
        s_St_8_Wait_2 = true;
      } else {
        s_St_8_Wait_2 = v_75_2;
      };
      v_116 = s_St_8_Wait_2;
    };
    s_1_3 = v_115;
    s_2_2 = v_116;
    r = v_118;
  };
  ck_27_1 = s_1_3;
  ck_27_2 = s_2_2;
  if (ck_27_1) {
    ck_27_2_1 = ck_27_2;
    if (ck_27_2_1) {
      working_state_lac_2_St_8_Off = 0;
      nr_St_8_Off = false;
      ns_St_8_Off_1 = true;
      ns_St_8_Off_2 = true;
      v_103 = working_state_lac_2_St_8_Off;
      v_109 = nr_St_8_Off;
      v_105 = ns_St_8_Off_1;
      v_106 = ns_St_8_Off_2;
      if (ns_St_8_Off_1) {
        ns_St_8_Off_2_1 = ns_St_8_Off_2;
      } else {
        ns_St_8_Off_2_0 = ns_St_8_Off_2;
      };
    } else {
      working_state_lac_2_St_8_On = 2;
      v_103 = working_state_lac_2_St_8_On;
      nr_St_8_On = false;
      v_109 = nr_St_8_On;
      ns_St_8_On_1 = true;
      v_105 = ns_St_8_On_1;
      ns_St_8_On_2 = false;
      v_106 = ns_St_8_On_2;
      if (ns_St_8_On_1) {
        ns_St_8_On_2_1 = ns_St_8_On_2;
      } else {
        ns_St_8_On_2_0 = ns_St_8_On_2;
      };
    };
    working_state_lac_2 = v_103;
    ns_1_3 = v_105;
    ns_2_2 = v_106;
    nr = v_109;
  } else {
    ck_27_2_0 = ck_27_2;
    if (ck_27_2_0) {
      v_104 = 0;
      v_110 = true;
      v_107 = true;
      v_108 = true;
    } else {
      working_state_lac_2_St_8_Wait = 1;
      v_104 = working_state_lac_2_St_8_Wait;
      nr_St_8_Wait = false;
      v_110 = nr_St_8_Wait;
      ns_St_8_Wait_1 = false;
      v_107 = ns_St_8_Wait_1;
      ns_St_8_Wait_2 = false;
      v_108 = ns_St_8_Wait_2;
    };
    working_state_lac_2 = v_104;
    ns_1_3 = v_107;
    ns_2_2 = v_108;
    nr = v_110;
  };
  _out->working_state_lac = working_state_lac_2;
  v_33 = (_out->working_state_lac>0);
  if (ns_1_3) {
    ns_2_2_1 = ns_2_2;
  } else {
    ns_2_2_0 = ns_2_2;
  };
  if (!(ck_27_1)) {
    if (!(ck_27_2_0)) {
      if (ns_St_8_Wait_1) {
        ns_St_8_Wait_2_1 = ns_St_8_Wait_2;
      } else {
        ns_St_8_Wait_2_0 = ns_St_8_Wait_2;
      };
    };
  };
  if (s_1_3) {
    s_2_2_1 = s_2_2;
  } else {
    s_2_2_0 = s_2_2;
  };
  if (!(ck_26_1)) {
    if (!(ck_26_2_0)) {
      if (v_73_1) {
        v_73_2_1 = v_73_2;
      } else {
        v_73_2_0 = v_73_2;
      };
      if (v_75_1) {
        v_75_2_1 = v_75_2;
      } else {
        v_75_2_0 = v_75_2;
      };
      if (s_St_8_Wait_1) {
        s_St_8_Wait_2_1 = s_St_8_Wait_2;
      } else {
        s_St_8_Wait_2_0 = s_St_8_Wait_2;
      };
    };
  };
  if (ck_24_1) {
    ck_24_2_1 = ck_24_2;
    if (ck_24_2_1) {
      v_69 = (turn_on_lac_1&&c2_lac_1);
      if (v_69) {
        v_71 = true;
        v_70_1 = false;
        v_70_2 = false;
      } else {
        v_71 = self->pnr_1;
        v_70_1 = true;
        v_70_2 = true;
      };
      v_68 = (turn_on_lac_1&&c_lac_1);
      if (v_68) {
        r_1_St_9_Off = true;
        s_1_St_9_Off_1 = true;
        s_1_St_9_Off_2 = false;
      } else {
        r_1_St_9_Off = v_71;
        s_1_St_9_Off_1 = v_70_1;
        s_1_St_9_Off_2 = v_70_2;
      };
      v_133 = r_1_St_9_Off;
      v_129 = s_1_St_9_Off_1;
      v_130 = s_1_St_9_Off_2;
      if (v_70_1) {
        v_70_2_1 = v_70_2;
      } else {
        v_70_2_0 = v_70_2;
      };
      if (s_1_St_9_Off_1) {
        s_1_St_9_Off_2_1 = s_1_St_9_Off_2;
      } else {
        s_1_St_9_Off_2_0 = s_1_St_9_Off_2;
      };
    } else {
      v_63 = !(c_lac_1);
      if (v_63) {
        v_65 = true;
        v_64_1 = true;
        v_64_2 = true;
      } else {
        v_65 = self->pnr_1;
        v_64_1 = true;
        v_64_2 = false;
      };
      v_62 = !(c2_lac_1);
      if (v_62) {
        v_67 = true;
      } else {
        v_67 = v_65;
      };
      if (turn_on_lac_1) {
        r_1_St_9_On = true;
      } else {
        r_1_St_9_On = v_67;
      };
      v_133 = r_1_St_9_On;
      if (v_62) {
        v_66_1 = false;
      } else {
        v_66_1 = v_64_1;
      };
      if (turn_on_lac_1) {
        s_1_St_9_On_1 = true;
      } else {
        s_1_St_9_On_1 = v_66_1;
      };
      v_129 = s_1_St_9_On_1;
      if (v_62) {
        v_66_2 = false;
      } else {
        v_66_2 = v_64_2;
      };
      if (turn_on_lac_1) {
        s_1_St_9_On_2 = true;
      } else {
        s_1_St_9_On_2 = v_66_2;
      };
      v_130 = s_1_St_9_On_2;
      if (v_64_1) {
        v_64_2_1 = v_64_2;
      } else {
        v_64_2_0 = v_64_2;
      };
      if (v_66_1) {
        v_66_2_1 = v_66_2;
      } else {
        v_66_2_0 = v_66_2;
      };
      if (s_1_St_9_On_1) {
        s_1_St_9_On_2_1 = s_1_St_9_On_2;
      } else {
        s_1_St_9_On_2_0 = s_1_St_9_On_2;
      };
    };
    s_1_1 = v_129;
    s_1_2 = v_130;
    r_1 = v_133;
  } else {
    ck_24_2_0 = ck_24_2;
    if (ck_24_2_0) {
      v_134 = true;
      v_131 = true;
      v_132 = true;
    } else {
      v_57 = !(c_lac_1);
      if (v_57) {
        v_59 = true;
      } else {
        v_59 = self->pnr_1;
      };
      if (c2_lac_1) {
        v_61 = true;
      } else {
        v_61 = v_59;
      };
      if (turn_on_lac_1) {
        r_1_St_9_Wait = true;
      } else {
        r_1_St_9_Wait = v_61;
      };
      v_134 = r_1_St_9_Wait;
      if (v_57) {
        v_58_1 = true;
      } else {
        v_58_1 = false;
      };
      if (c2_lac_1) {
        v_60_1 = true;
      } else {
        v_60_1 = v_58_1;
      };
      if (turn_on_lac_1) {
        s_1_St_9_Wait_1 = true;
      } else {
        s_1_St_9_Wait_1 = v_60_1;
      };
      v_131 = s_1_St_9_Wait_1;
      if (v_57) {
        v_58_2 = true;
      } else {
        v_58_2 = false;
      };
      if (c2_lac_1) {
        v_60_2 = false;
      } else {
        v_60_2 = v_58_2;
      };
      if (turn_on_lac_1) {
        s_1_St_9_Wait_2 = true;
      } else {
        s_1_St_9_Wait_2 = v_60_2;
      };
      v_132 = s_1_St_9_Wait_2;
    };
    s_1_1 = v_131;
    s_1_2 = v_132;
    r_1 = v_134;
  };
  ck_25_1 = s_1_1;
  ck_25_2 = s_1_2;
  if (ck_25_1) {
    ck_25_2_1 = ck_25_2;
    if (ck_25_2_1) {
      working_state_lac_1_St_9_Off = 0;
      nr_1_St_9_Off = false;
      ns_1_St_9_Off_1 = true;
      ns_1_St_9_Off_2 = true;
      v_119 = working_state_lac_1_St_9_Off;
      v_125 = nr_1_St_9_Off;
      v_121 = ns_1_St_9_Off_1;
      v_122 = ns_1_St_9_Off_2;
      if (ns_1_St_9_Off_1) {
        ns_1_St_9_Off_2_1 = ns_1_St_9_Off_2;
      } else {
        ns_1_St_9_Off_2_0 = ns_1_St_9_Off_2;
      };
    } else {
      working_state_lac_1_St_9_On = 2;
      v_119 = working_state_lac_1_St_9_On;
      nr_1_St_9_On = false;
      v_125 = nr_1_St_9_On;
      ns_1_St_9_On_1 = true;
      v_121 = ns_1_St_9_On_1;
      ns_1_St_9_On_2 = false;
      v_122 = ns_1_St_9_On_2;
      if (ns_1_St_9_On_1) {
        ns_1_St_9_On_2_1 = ns_1_St_9_On_2;
      } else {
        ns_1_St_9_On_2_0 = ns_1_St_9_On_2;
      };
    };
    working_state_lac_1 = v_119;
    ns_1_1 = v_121;
    ns_1_2 = v_122;
    nr_1 = v_125;
  } else {
    ck_25_2_0 = ck_25_2;
    if (ck_25_2_0) {
      v_120 = 0;
      v_126 = true;
      v_123 = true;
      v_124 = true;
    } else {
      working_state_lac_1_St_9_Wait = 1;
      v_120 = working_state_lac_1_St_9_Wait;
      nr_1_St_9_Wait = false;
      v_126 = nr_1_St_9_Wait;
      ns_1_St_9_Wait_1 = false;
      v_123 = ns_1_St_9_Wait_1;
      ns_1_St_9_Wait_2 = false;
      v_124 = ns_1_St_9_Wait_2;
    };
    working_state_lac_1 = v_120;
    ns_1_1 = v_123;
    ns_1_2 = v_124;
    nr_1 = v_126;
  };
  _out->working_state_rac = working_state_lac_1;
  v_26 = (_out->working_state_lac+_out->working_state_rac);
  v_27 = (v_26==0);
  v_29 = (_out->working_state_lac+_out->working_state_rac);
  v_30 = (v_29<2);
  v_32 = (_out->working_state_rac>0);
  v_34 = (v_32&&v_33);
  rule2 = !(v_34);
  if (ns_1_1) {
    ns_1_2_1 = ns_1_2;
  } else {
    ns_1_2_0 = ns_1_2;
  };
  if (!(ck_25_1)) {
    if (!(ck_25_2_0)) {
      if (ns_1_St_9_Wait_1) {
        ns_1_St_9_Wait_2_1 = ns_1_St_9_Wait_2;
      } else {
        ns_1_St_9_Wait_2_0 = ns_1_St_9_Wait_2;
      };
    };
  };
  if (s_1_1) {
    s_1_2_1 = s_1_2;
  } else {
    s_1_2_0 = s_1_2;
  };
  if (!(ck_24_1)) {
    if (!(ck_24_2_0)) {
      if (v_58_1) {
        v_58_2_1 = v_58_2;
      } else {
        v_58_2_0 = v_58_2;
      };
      if (v_60_1) {
        v_60_2_1 = v_60_2;
      } else {
        v_60_2_0 = v_60_2;
      };
      if (s_1_St_9_Wait_1) {
        s_1_St_9_Wait_2_1 = s_1_St_9_Wait_2;
      } else {
        s_1_St_9_Wait_2_0 = s_1_St_9_Wait_2;
      };
    };
  };
  if (self->ck_22_1) {
    if (do_open_1) {
      r_2_St_10_Closed = true;
      s_2_St_10_Closed_1 = false;
    } else {
      r_2_St_10_Closed = self->pnr_2;
      s_2_St_10_Closed_1 = true;
    };
    r_2 = r_2_St_10_Closed;
    s_2_1 = s_2_St_10_Closed_1;
  } else {
    if (do_open_1) {
      r_2_St_10_Opened = true;
    } else {
      r_2_St_10_Opened = self->pnr_2;
    };
    r_2 = r_2_St_10_Opened;
    if (do_open_1) {
      s_2_St_10_Opened_1 = true;
    } else {
      s_2_St_10_Opened_1 = false;
    };
    s_2_1 = s_2_St_10_Opened_1;
  };
  ck_23_1 = s_2_1;
  if (ck_23_1) {
    is_w_opened_1_St_10_Closed = false;
    nr_2_St_10_Closed = false;
    ns_2_St_10_Closed_1 = true;
    is_w_opened_1 = is_w_opened_1_St_10_Closed;
    nr_2 = nr_2_St_10_Closed;
    ns_2_1 = ns_2_St_10_Closed_1;
  } else {
    is_w_opened_1_St_10_Opened = true;
    is_w_opened_1 = is_w_opened_1_St_10_Opened;
    nr_2_St_10_Opened = false;
    nr_2 = nr_2_St_10_Opened;
    ns_2_St_10_Opened_1 = false;
    ns_2_1 = ns_2_St_10_Opened_1;
  };
  _out->is_w_opened = is_w_opened_1;
  v_25 = !(_out->is_w_opened);
  rule5 = (v_25||v_27);
  if (self->ck_20_1) {
    if (turn_on_wm_1) {
      r_3_St_11_Off = true;
      s_3_St_11_Off_1 = false;
    } else {
      r_3_St_11_Off = self->pnr_3;
      s_3_St_11_Off_1 = true;
    };
    r_3 = r_3_St_11_Off;
    s_3_1 = s_3_St_11_Off_1;
  } else {
    if (turn_on_wm_1) {
      r_3_St_11_Washing = true;
    } else {
      r_3_St_11_Washing = self->pnr_3;
    };
    r_3 = r_3_St_11_Washing;
    if (turn_on_wm_1) {
      s_3_St_11_Washing_1 = true;
    } else {
      s_3_St_11_Washing_1 = false;
    };
    s_3_1 = s_3_St_11_Washing_1;
  };
  ck_21_1 = s_3_1;
  if (ck_21_1) {
    is_working_wm_1_St_11_Off = false;
    nr_3_St_11_Off = false;
    ns_3_St_11_Off_1 = true;
    is_working_wm_1 = is_working_wm_1_St_11_Off;
    nr_3 = nr_3_St_11_Off;
    ns_3_1 = ns_3_St_11_Off_1;
  } else {
    is_working_wm_1_St_11_Washing = true;
    is_working_wm_1 = is_working_wm_1_St_11_Washing;
    nr_3_St_11_Washing = false;
    nr_3 = nr_3_St_11_Washing;
    ns_3_St_11_Washing_1 = false;
    ns_3_1 = ns_3_St_11_Washing_1;
  };
  _out->is_working_wm = is_working_wm_1;
  v_28 = !(_out->is_working_wm);
  rule4 = (v_28||v_30);
  if (self->ck_18_1) {
    if (turn_on_tv_1) {
      r_4_St_12_Off = true;
      s_4_St_12_Off_1 = false;
    } else {
      r_4_St_12_Off = self->pnr_4;
      s_4_St_12_Off_1 = true;
    };
    r_4 = r_4_St_12_Off;
    s_4_1 = s_4_St_12_Off_1;
  } else {
    if (turn_on_tv_1) {
      r_4_St_12_On = true;
    } else {
      r_4_St_12_On = self->pnr_4;
    };
    r_4 = r_4_St_12_On;
    if (turn_on_tv_1) {
      s_4_St_12_On_1 = true;
    } else {
      s_4_St_12_On_1 = false;
    };
    s_4_1 = s_4_St_12_On_1;
  };
  ck_19_1 = s_4_1;
  if (ck_19_1) {
    is_tv_on_1_St_12_Off = false;
    nr_4_St_12_Off = false;
    ns_4_St_12_Off_1 = true;
    is_tv_on_1 = is_tv_on_1_St_12_Off;
    nr_4 = nr_4_St_12_Off;
    ns_4_1 = ns_4_St_12_Off_1;
  } else {
    is_tv_on_1_St_12_On = true;
    is_tv_on_1 = is_tv_on_1_St_12_On;
    nr_4_St_12_On = false;
    nr_4 = nr_4_St_12_On;
    ns_4_St_12_On_1 = false;
    ns_4_1 = ns_4_St_12_On_1;
  };
  _out->is_tv_on = is_tv_on_1;
  v = !(_out->is_tv_on);
  if (self->ck_16_1) {
    v_56 = (turn_on_l_1&&c_l1_3);
    if (v_56) {
      r_5_St_13_Off = true;
      s_5_St_13_Off_1 = false;
    } else {
      r_5_St_13_Off = self->pnr_5;
      s_5_St_13_Off_1 = true;
    };
    r_5 = r_5_St_13_Off;
    s_5_1 = s_5_St_13_Off_1;
  } else {
    v_54 = !(c_l2_3);
    v_53 = (turn_on_l_1&&c_l1_3);
    v_55 = (v_53||v_54);
    if (v_55) {
      r_5_St_13_On = true;
    } else {
      r_5_St_13_On = self->pnr_5;
    };
    r_5 = r_5_St_13_On;
    if (v_55) {
      s_5_St_13_On_1 = true;
    } else {
      s_5_St_13_On_1 = false;
    };
    s_5_1 = s_5_St_13_On_1;
  };
  ck_17_1 = s_5_1;
  if (ck_17_1) {
    is_on_l_1_St_13_Off = false;
    nr_5_St_13_Off = false;
    ns_5_St_13_Off_1 = true;
    is_on_l_1 = is_on_l_1_St_13_Off;
    nr_5 = nr_5_St_13_Off;
    ns_5_1 = ns_5_St_13_Off_1;
  } else {
    is_on_l_1_St_13_On = true;
    is_on_l_1 = is_on_l_1_St_13_On;
    nr_5_St_13_On = false;
    nr_5 = nr_5_St_13_On;
    ns_5_St_13_On_1 = false;
    ns_5_1 = ns_5_St_13_On_1;
  };
  _out->is_on_l = is_on_l_1;
  if (self->ck_14_1) {
    if (turn_on_rl_1) {
      r_6_St_14_Off = true;
      s_6_St_14_Off_1 = false;
    } else {
      r_6_St_14_Off = self->pnr_6;
      s_6_St_14_Off_1 = true;
    };
    r_6 = r_6_St_14_Off;
    s_6_1 = s_6_St_14_Off_1;
  } else {
    if (turn_on_rl_1) {
      r_6_St_14_On = true;
    } else {
      r_6_St_14_On = self->pnr_6;
    };
    r_6 = r_6_St_14_On;
    if (turn_on_rl_1) {
      s_6_St_14_On_1 = true;
    } else {
      s_6_St_14_On_1 = false;
    };
    s_6_1 = s_6_St_14_On_1;
  };
  ck_15_1 = s_6_1;
  if (ck_15_1) {
    is_on_rl_1_St_14_Off = false;
    nr_6_St_14_Off = false;
    ns_6_St_14_Off_1 = true;
    is_on_rl_1 = is_on_rl_1_St_14_Off;
    nr_6 = nr_6_St_14_Off;
    ns_6_1 = ns_6_St_14_Off_1;
  } else {
    is_on_rl_1_St_14_On = true;
    is_on_rl_1 = is_on_rl_1_St_14_On;
    nr_6_St_14_On = false;
    nr_6 = nr_6_St_14_On;
    ns_6_St_14_On_1 = false;
    ns_6_1 = ns_6_St_14_On_1;
  };
  _out->is_on_rl = is_on_rl_1;
  v_31 = (_out->is_on_rl&&_out->is_on_l);
  rule3 = !(v_31);
  if (self->ck_12_1) {
    v_51 = !(c_l2_2);
    v_50 = (turn_on_l1_2&&c_l1_2);
    v_52 = (v_50||v_51);
    if (v_52) {
      r_7_St_15_Off = true;
      s_7_St_15_Off_1 = false;
    } else {
      r_7_St_15_Off = self->pnr_7;
      s_7_St_15_Off_1 = true;
    };
    r_7 = r_7_St_15_Off;
    s_7_1 = s_7_St_15_Off_1;
  } else {
    v_48 = !(c_l2_2);
    v_47 = (turn_on_l1_2&&c_l1_2);
    v_49 = (v_47||v_48);
    if (v_49) {
      r_7_St_15_On = true;
    } else {
      r_7_St_15_On = self->pnr_7;
    };
    r_7 = r_7_St_15_On;
    if (v_49) {
      s_7_St_15_On_1 = true;
    } else {
      s_7_St_15_On_1 = false;
    };
    s_7_1 = s_7_St_15_On_1;
  };
  ck_13_1 = s_7_1;
  if (ck_13_1) {
    is_on_l1_2_St_15_Off = false;
    nr_7_St_15_Off = false;
    ns_7_St_15_Off_1 = true;
    is_on_l1_2 = is_on_l1_2_St_15_Off;
    nr_7 = nr_7_St_15_Off;
    ns_7_1 = ns_7_St_15_Off_1;
  } else {
    is_on_l1_2_St_15_On = true;
    is_on_l1_2 = is_on_l1_2_St_15_On;
    nr_7_St_15_On = false;
    nr_7 = nr_7_St_15_On;
    ns_7_St_15_On_1 = false;
    ns_7_1 = ns_7_St_15_On_1;
  };
  _out->is_on_l2 = is_on_l1_2;
  if (self->ck_10_1) {
    v_45 = !(c_l2_1);
    v_44 = (turn_on_l1_1&&c_l1_1);
    v_46 = (v_44||v_45);
    if (v_46) {
      r_8_St_16_Off = true;
      s_8_St_16_Off_1 = false;
    } else {
      r_8_St_16_Off = self->pnr_8;
      s_8_St_16_Off_1 = true;
    };
    r_8 = r_8_St_16_Off;
    s_8_1 = s_8_St_16_Off_1;
  } else {
    v_42 = !(c_l2_1);
    v_41 = (turn_on_l1_1&&c_l1_1);
    v_43 = (v_41||v_42);
    if (v_43) {
      r_8_St_16_On = true;
    } else {
      r_8_St_16_On = self->pnr_8;
    };
    r_8 = r_8_St_16_On;
    if (v_43) {
      s_8_St_16_On_1 = true;
    } else {
      s_8_St_16_On_1 = false;
    };
    s_8_1 = s_8_St_16_On_1;
  };
  ck_11_1 = s_8_1;
  if (ck_11_1) {
    is_on_l1_1_St_16_Off = false;
    nr_8_St_16_Off = false;
    ns_8_St_16_Off_1 = true;
    is_on_l1_1 = is_on_l1_1_St_16_Off;
    nr_8 = nr_8_St_16_Off;
    ns_8_1 = ns_8_St_16_Off_1;
  } else {
    is_on_l1_1_St_16_On = true;
    is_on_l1_1 = is_on_l1_1_St_16_On;
    nr_8_St_16_On = false;
    nr_8 = nr_8_St_16_On;
    ns_8_St_16_On_1 = false;
    ns_8_1 = ns_8_St_16_On_1;
  };
  _out->is_on_l1 = is_on_l1_1;
  v_35 = (_out->is_on_l1&&_out->is_on_l2);
  rule1 = !(v_35);
  v_36 = (rule1&&rule2);
  v_37 = (v_36&&rule3);
  v_38 = (v_37&&rule4);
  v_39 = (v_38&&rule5);
  if (self->ck_1) {
    if (presence_1) {
      r_9_St_17_Empty = true;
      s_9_St_17_Empty_1 = false;
    } else {
      r_9_St_17_Empty = self->pnr_9;
      s_9_St_17_Empty_1 = true;
    };
    r_9 = r_9_St_17_Empty;
    s_9_1 = s_9_St_17_Empty_1;
  } else {
    if (presence_1) {
      r_9_St_17_Occupied = true;
    } else {
      r_9_St_17_Occupied = self->pnr_9;
    };
    r_9 = r_9_St_17_Occupied;
    if (presence_1) {
      s_9_St_17_Occupied_1 = true;
    } else {
      s_9_St_17_Occupied_1 = false;
    };
    s_9_1 = s_9_St_17_Occupied_1;
  };
  ck_9_1 = s_9_1;
  if (ck_9_1) {
    has_presence_1_St_17_Empty = false;
    nr_9_St_17_Empty = false;
    ns_9_St_17_Empty_1 = true;
    has_presence_1 = has_presence_1_St_17_Empty;
    nr_9 = nr_9_St_17_Empty;
    ns_9_1 = ns_9_St_17_Empty_1;
  } else {
    has_presence_1_St_17_Occupied = true;
    has_presence_1 = has_presence_1_St_17_Occupied;
    nr_9_St_17_Occupied = false;
    nr_9 = nr_9_St_17_Occupied;
    ns_9_St_17_Occupied_1 = false;
    ns_9_1 = ns_9_St_17_Occupied_1;
  };
  _out->has_presence = has_presence_1;
  v_23 = (_out->has_presence&&v);
  v_24 = !(v_23);
  rule6 = (v_24||_out->is_on_l1);
  v_40 = (v_39&&rule6);
  self->pnr = nr;
  self->v_111 = ns_1_3;
  self->v_112 = ns_2_2;
  self->pnr_1 = nr_1;
  self->v_127 = ns_1_1;
  self->v_128 = ns_1_2;
  self->pnr_2 = nr_2;
  self->ck_22_1 = ns_2_1;
  self->pnr_3 = nr_3;
  self->ck_20_1 = ns_3_1;
  self->pnr_4 = nr_4;
  self->ck_18_1 = ns_4_1;
  self->pnr_5 = nr_5;
  self->ck_16_1 = ns_5_1;
  self->pnr_6 = nr_6;
  self->ck_14_1 = ns_6_1;
  self->pnr_7 = nr_7;
  self->ck_12_1 = ns_7_1;
  self->pnr_8 = nr_8;
  self->ck_10_1 = ns_8_1;
  self->pnr_9 = nr_9;
  self->ck_1 = ns_9_1;;
}


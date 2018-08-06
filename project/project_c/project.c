/* --- Generated the 6/8/2018 at 10:53 --- */
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
  int v_7;
  int v_6;
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
    v_6 = !(c_l2);
    v_4 = !(c_l1);
    v_5 = (turn_on_l1&&v_4);
    v_7 = (v_5||v_6);
    if (v_7) {
      r_St_1_Off = true;
      s_St_1_Off_1 = false;
    } else {
      r_St_1_Off = self->pnr;
      s_St_1_Off_1 = true;
    };
    r = r_St_1_Off;
    s_1 = s_St_1_Off_1;
  } else {
    v_2 = !(c_l2);
    v = !(c_l1);
    v_1 = (turn_on_l1&&v);
    v_3 = (v_1||v_2);
    if (v_3) {
      r_St_1_On = true;
    } else {
      r_St_1_On = self->pnr;
    };
    r = r_St_1_On;
    if (v_3) {
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
  int v_12;
  int v_11;
  int v_10;
  int v_9;
  int v_8;
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
    v_11 = !(c_l1);
    v_12 = (turn_on_l&&v_11);
    if (v_12) {
      r_St_2_Off = true;
      s_St_2_Off_1 = false;
    } else {
      r_St_2_Off = self->pnr;
      s_St_2_Off_1 = true;
    };
    r = r_St_2_Off;
    s_1 = s_St_2_Off_1;
  } else {
    v_9 = !(c_l2);
    v = !(c_l1);
    v_8 = (turn_on_l&&v);
    v_10 = (v_8||v_9);
    if (v_10) {
      r_St_2_On = true;
    } else {
      r_St_2_On = self->pnr;
    };
    r = r_St_2_On;
    if (v_10) {
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

void Project__room_air_conditioner_reset(Project__room_air_conditioner_mem* self) {
  self->pnr = false;
  self->v_97 = true;
  self->v_98 = true;
}

void Project__room_air_conditioner_step(int turn_on_rac, int c_rac,
                                        Project__room_air_conditioner_out* _out,
                                        Project__room_air_conditioner_mem* self) {
  
  int v_96;
  int v_95;
  int v_94;
  int v_93;
  int v_92;
  int v_91;
  int v_90;
  int v_89;
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
  int working_state_rac_St_4_Wait;
  int nr_St_4_On;
  int ns_St_4_On_2;
  int ns_St_4_On_1;
  int working_state_rac_St_4_On;
  int nr_St_4_Off;
  int ns_St_4_Off_2;
  int ns_St_4_Off_1;
  int working_state_rac_St_4_Off;
  int ck_5_2;
  int ck_5_1;
  int v_18_2_0;
  int v_18_2_1;
  int v_19;
  int v_18_2;
  int v_18_1;
  int v_17;
  int v_16;
  int v_15;
  int v_13_2_0;
  int v_13_2_1;
  int v_14;
  int v_13_2;
  int v_13_1;
  int v;
  int v_104;
  int v_103;
  int v_102;
  int v_101;
  int v_100;
  int v_99;
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
  ck_1 = self->v_97;
  ck_2 = self->v_98;
  if (ck_1) {
    ck_2_1 = ck_2;
    if (ck_2_1) {
      v_16 = !(c_rac);
      v_17 = (turn_on_rac&&v_16);
      if (v_17) {
        v_19 = true;
        v_18_1 = false;
        v_18_2 = false;
      } else {
        v_19 = self->pnr;
        v_18_1 = true;
        v_18_2 = true;
      };
      v_15 = (turn_on_rac&&c_rac);
      if (v_15) {
        r_St_4_Off = true;
        s_St_4_Off_1 = true;
        s_St_4_Off_2 = false;
      } else {
        r_St_4_Off = v_19;
        s_St_4_Off_1 = v_18_1;
        s_St_4_Off_2 = v_18_2;
      };
      v_103 = r_St_4_Off;
      v_99 = s_St_4_Off_1;
      v_100 = s_St_4_Off_2;
      if (v_18_1) {
        v_18_2_1 = v_18_2;
      } else {
        v_18_2_0 = v_18_2;
      };
      if (s_St_4_Off_1) {
        s_St_4_Off_2_1 = s_St_4_Off_2;
      } else {
        s_St_4_Off_2_0 = s_St_4_Off_2;
      };
    } else {
      v = !(c_rac);
      if (v) {
        v_14 = true;
      } else {
        v_14 = self->pnr;
      };
      if (turn_on_rac) {
        r_St_4_On = true;
      } else {
        r_St_4_On = v_14;
      };
      v_103 = r_St_4_On;
      if (v) {
        v_13_1 = false;
      } else {
        v_13_1 = true;
      };
      if (turn_on_rac) {
        s_St_4_On_1 = true;
      } else {
        s_St_4_On_1 = v_13_1;
      };
      v_99 = s_St_4_On_1;
      if (v) {
        v_13_2 = false;
      } else {
        v_13_2 = false;
      };
      if (turn_on_rac) {
        s_St_4_On_2 = true;
      } else {
        s_St_4_On_2 = v_13_2;
      };
      v_100 = s_St_4_On_2;
      if (v_13_1) {
        v_13_2_1 = v_13_2;
      } else {
        v_13_2_0 = v_13_2;
      };
      if (s_St_4_On_1) {
        s_St_4_On_2_1 = s_St_4_On_2;
      } else {
        s_St_4_On_2_0 = s_St_4_On_2;
      };
    };
    s_1 = v_99;
    s_2 = v_100;
    r = v_103;
  } else {
    ck_2_0 = ck_2;
    if (ck_2_0) {
      v_104 = true;
      v_101 = true;
      v_102 = true;
    } else {
      if (c_rac) {
        r_St_4_Wait = true;
      } else {
        r_St_4_Wait = self->pnr;
      };
      v_104 = r_St_4_Wait;
      if (c_rac) {
        s_St_4_Wait_1 = true;
      } else {
        s_St_4_Wait_1 = false;
      };
      v_101 = s_St_4_Wait_1;
      if (c_rac) {
        s_St_4_Wait_2 = false;
      } else {
        s_St_4_Wait_2 = false;
      };
      v_102 = s_St_4_Wait_2;
    };
    s_1 = v_101;
    s_2 = v_102;
    r = v_104;
  };
  ck_5_1 = s_1;
  ck_5_2 = s_2;
  if (ck_5_1) {
    ck_5_2_1 = ck_5_2;
    if (ck_5_2_1) {
      working_state_rac_St_4_Off = 0;
      nr_St_4_Off = false;
      ns_St_4_Off_1 = true;
      ns_St_4_Off_2 = true;
      v_89 = working_state_rac_St_4_Off;
      v_95 = nr_St_4_Off;
      v_91 = ns_St_4_Off_1;
      v_92 = ns_St_4_Off_2;
      if (ns_St_4_Off_1) {
        ns_St_4_Off_2_1 = ns_St_4_Off_2;
      } else {
        ns_St_4_Off_2_0 = ns_St_4_Off_2;
      };
    } else {
      working_state_rac_St_4_On = 2;
      v_89 = working_state_rac_St_4_On;
      nr_St_4_On = false;
      v_95 = nr_St_4_On;
      ns_St_4_On_1 = true;
      v_91 = ns_St_4_On_1;
      ns_St_4_On_2 = false;
      v_92 = ns_St_4_On_2;
      if (ns_St_4_On_1) {
        ns_St_4_On_2_1 = ns_St_4_On_2;
      } else {
        ns_St_4_On_2_0 = ns_St_4_On_2;
      };
    };
    _out->working_state_rac = v_89;
    ns_1 = v_91;
    ns_2 = v_92;
    nr = v_95;
  } else {
    ck_5_2_0 = ck_5_2;
    if (ck_5_2_0) {
      v_90 = 0;
      v_96 = true;
      v_93 = true;
      v_94 = true;
    } else {
      working_state_rac_St_4_Wait = 1;
      v_90 = working_state_rac_St_4_Wait;
      nr_St_4_Wait = false;
      v_96 = nr_St_4_Wait;
      ns_St_4_Wait_1 = false;
      v_93 = ns_St_4_Wait_1;
      ns_St_4_Wait_2 = false;
      v_94 = ns_St_4_Wait_2;
    };
    _out->working_state_rac = v_90;
    ns_1 = v_93;
    ns_2 = v_94;
    nr = v_96;
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
      if (s_St_4_Wait_1) {
        s_St_4_Wait_2_1 = s_St_4_Wait_2;
      } else {
        s_St_4_Wait_2_0 = s_St_4_Wait_2;
      };
    };
  };
  self->pnr = nr;
  self->v_97 = ns_1;
  self->v_98 = ns_2;;
}

void Project__living_room_air_conditioner_reset(Project__living_room_air_conditioner_mem* self) {
  self->pnr = false;
  self->v_113 = true;
  self->v_114 = true;
}

void Project__living_room_air_conditioner_step(int turn_on_lac, int c_lac,
                                               int c2_lac,
                                               Project__living_room_air_conditioner_out* _out,
                                               Project__living_room_air_conditioner_mem* self) {
  
  int v_112;
  int v_111;
  int v_110;
  int v_109;
  int v_108;
  int v_107;
  int v_106;
  int v_105;
  int ns_St_5_Wait_2_0;
  int ns_St_5_Wait_2_1;
  int ns_St_5_On_2_0;
  int ns_St_5_On_2_1;
  int ns_St_5_Off_2_0;
  int ns_St_5_Off_2_1;
  int ck_6_2_0;
  int ck_6_2_1;
  int nr_St_5_Wait;
  int ns_St_5_Wait_2;
  int ns_St_5_Wait_1;
  int working_state_lac_St_5_Wait;
  int nr_St_5_On;
  int ns_St_5_On_2;
  int ns_St_5_On_1;
  int working_state_lac_St_5_On;
  int nr_St_5_Off;
  int ns_St_5_Off_2;
  int ns_St_5_Off_1;
  int working_state_lac_St_5_Off;
  int ck_6_2;
  int ck_6_1;
  int v_26_2_0;
  int v_26_2_1;
  int v_27;
  int v_26_2;
  int v_26_1;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_20_2_0;
  int v_20_2_1;
  int v_21;
  int v_20_2;
  int v_20_1;
  int v;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  int s_St_5_Wait_2_0;
  int s_St_5_Wait_2_1;
  int s_St_5_On_2_0;
  int s_St_5_On_2_1;
  int s_St_5_Off_2_0;
  int s_St_5_Off_2_1;
  int ck_2_0;
  int ck_2_1;
  int r_St_5_Wait;
  int s_St_5_Wait_2;
  int s_St_5_Wait_1;
  int r_St_5_On;
  int s_St_5_On_2;
  int s_St_5_On_1;
  int r_St_5_Off;
  int s_St_5_Off_2;
  int s_St_5_Off_1;
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
  ck_1 = self->v_113;
  ck_2 = self->v_114;
  if (ck_1) {
    ck_2_1 = ck_2;
    if (ck_2_1) {
      v_24 = !(c2_lac);
      v_25 = (turn_on_lac&&v_24);
      if (v_25) {
        v_27 = true;
        v_26_1 = false;
        v_26_2 = false;
      } else {
        v_27 = self->pnr;
        v_26_1 = true;
        v_26_2 = true;
      };
      v_22 = (turn_on_lac&&c_lac);
      v_23 = (v_22&&c2_lac);
      if (v_23) {
        r_St_5_Off = true;
        s_St_5_Off_1 = true;
        s_St_5_Off_2 = false;
      } else {
        r_St_5_Off = v_27;
        s_St_5_Off_1 = v_26_1;
        s_St_5_Off_2 = v_26_2;
      };
      v_119 = r_St_5_Off;
      v_115 = s_St_5_Off_1;
      v_116 = s_St_5_Off_2;
      if (v_26_1) {
        v_26_2_1 = v_26_2;
      } else {
        v_26_2_0 = v_26_2;
      };
      if (s_St_5_Off_1) {
        s_St_5_Off_2_1 = s_St_5_Off_2;
      } else {
        s_St_5_Off_2_0 = s_St_5_Off_2;
      };
    } else {
      v = !(c2_lac);
      if (v) {
        v_21 = true;
      } else {
        v_21 = self->pnr;
      };
      if (turn_on_lac) {
        r_St_5_On = true;
      } else {
        r_St_5_On = v_21;
      };
      v_119 = r_St_5_On;
      if (v) {
        v_20_1 = false;
      } else {
        v_20_1 = true;
      };
      if (turn_on_lac) {
        s_St_5_On_1 = true;
      } else {
        s_St_5_On_1 = v_20_1;
      };
      v_115 = s_St_5_On_1;
      if (v) {
        v_20_2 = false;
      } else {
        v_20_2 = false;
      };
      if (turn_on_lac) {
        s_St_5_On_2 = true;
      } else {
        s_St_5_On_2 = v_20_2;
      };
      v_116 = s_St_5_On_2;
      if (v_20_1) {
        v_20_2_1 = v_20_2;
      } else {
        v_20_2_0 = v_20_2;
      };
      if (s_St_5_On_1) {
        s_St_5_On_2_1 = s_St_5_On_2;
      } else {
        s_St_5_On_2_0 = s_St_5_On_2;
      };
    };
    s_1 = v_115;
    s_2 = v_116;
    r = v_119;
  } else {
    ck_2_0 = ck_2;
    if (ck_2_0) {
      v_120 = true;
      v_117 = true;
      v_118 = true;
    } else {
      if (c2_lac) {
        r_St_5_Wait = true;
      } else {
        r_St_5_Wait = self->pnr;
      };
      v_120 = r_St_5_Wait;
      if (c2_lac) {
        s_St_5_Wait_1 = true;
      } else {
        s_St_5_Wait_1 = false;
      };
      v_117 = s_St_5_Wait_1;
      if (c2_lac) {
        s_St_5_Wait_2 = false;
      } else {
        s_St_5_Wait_2 = false;
      };
      v_118 = s_St_5_Wait_2;
    };
    s_1 = v_117;
    s_2 = v_118;
    r = v_120;
  };
  ck_6_1 = s_1;
  ck_6_2 = s_2;
  if (ck_6_1) {
    ck_6_2_1 = ck_6_2;
    if (ck_6_2_1) {
      working_state_lac_St_5_Off = 0;
      nr_St_5_Off = false;
      ns_St_5_Off_1 = true;
      ns_St_5_Off_2 = true;
      v_105 = working_state_lac_St_5_Off;
      v_111 = nr_St_5_Off;
      v_107 = ns_St_5_Off_1;
      v_108 = ns_St_5_Off_2;
      if (ns_St_5_Off_1) {
        ns_St_5_Off_2_1 = ns_St_5_Off_2;
      } else {
        ns_St_5_Off_2_0 = ns_St_5_Off_2;
      };
    } else {
      working_state_lac_St_5_On = 2;
      v_105 = working_state_lac_St_5_On;
      nr_St_5_On = false;
      v_111 = nr_St_5_On;
      ns_St_5_On_1 = true;
      v_107 = ns_St_5_On_1;
      ns_St_5_On_2 = false;
      v_108 = ns_St_5_On_2;
      if (ns_St_5_On_1) {
        ns_St_5_On_2_1 = ns_St_5_On_2;
      } else {
        ns_St_5_On_2_0 = ns_St_5_On_2;
      };
    };
    _out->working_state_lac = v_105;
    ns_1 = v_107;
    ns_2 = v_108;
    nr = v_111;
  } else {
    ck_6_2_0 = ck_6_2;
    if (ck_6_2_0) {
      v_106 = 0;
      v_112 = true;
      v_109 = true;
      v_110 = true;
    } else {
      working_state_lac_St_5_Wait = 1;
      v_106 = working_state_lac_St_5_Wait;
      nr_St_5_Wait = false;
      v_112 = nr_St_5_Wait;
      ns_St_5_Wait_1 = false;
      v_109 = ns_St_5_Wait_1;
      ns_St_5_Wait_2 = false;
      v_110 = ns_St_5_Wait_2;
    };
    _out->working_state_lac = v_106;
    ns_1 = v_109;
    ns_2 = v_110;
    nr = v_112;
  };
  if (ns_1) {
    ns_2_1 = ns_2;
  } else {
    ns_2_0 = ns_2;
  };
  if (!(ck_6_1)) {
    if (!(ck_6_2_0)) {
      if (ns_St_5_Wait_1) {
        ns_St_5_Wait_2_1 = ns_St_5_Wait_2;
      } else {
        ns_St_5_Wait_2_0 = ns_St_5_Wait_2;
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
      if (s_St_5_Wait_1) {
        s_St_5_Wait_2_1 = s_St_5_Wait_2;
      } else {
        s_St_5_Wait_2_0 = s_St_5_Wait_2;
      };
    };
  };
  self->pnr = nr;
  self->v_113 = ns_1;
  self->v_114 = ns_2;;
}

void Project__tv_reset(Project__tv_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Project__tv_step(int turn_on_tv, Project__tv_out* _out,
                      Project__tv_mem* self) {
  
  int nr_St_6_On;
  int ns_St_6_On_1;
  int is_tv_on_St_6_On;
  int nr_St_6_Off;
  int ns_St_6_Off_1;
  int is_tv_on_St_6_Off;
  int ck_7_1;
  int r_St_6_On;
  int s_St_6_On_1;
  int r_St_6_Off;
  int s_St_6_Off_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_tv) {
      r_St_6_Off = true;
      s_St_6_Off_1 = false;
    } else {
      r_St_6_Off = self->pnr;
      s_St_6_Off_1 = true;
    };
    r = r_St_6_Off;
    s_1 = s_St_6_Off_1;
  } else {
    if (turn_on_tv) {
      r_St_6_On = true;
    } else {
      r_St_6_On = self->pnr;
    };
    r = r_St_6_On;
    if (turn_on_tv) {
      s_St_6_On_1 = true;
    } else {
      s_St_6_On_1 = false;
    };
    s_1 = s_St_6_On_1;
  };
  ck_7_1 = s_1;
  if (ck_7_1) {
    is_tv_on_St_6_Off = false;
    nr_St_6_Off = false;
    ns_St_6_Off_1 = true;
    _out->is_tv_on = is_tv_on_St_6_Off;
    nr = nr_St_6_Off;
    ns_1 = ns_St_6_Off_1;
  } else {
    is_tv_on_St_6_On = true;
    _out->is_tv_on = is_tv_on_St_6_On;
    nr_St_6_On = false;
    nr = nr_St_6_On;
    ns_St_6_On_1 = false;
    ns_1 = ns_St_6_On_1;
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
  
  int nr_St_7_Washing;
  int ns_St_7_Washing_1;
  int is_working_wm_St_7_Washing;
  int nr_St_7_Off;
  int ns_St_7_Off_1;
  int is_working_wm_St_7_Off;
  int ck_8_1;
  int r_St_7_Washing;
  int s_St_7_Washing_1;
  int r_St_7_Off;
  int s_St_7_Off_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_wm) {
      r_St_7_Off = true;
      s_St_7_Off_1 = false;
    } else {
      r_St_7_Off = self->pnr;
      s_St_7_Off_1 = true;
    };
    r = r_St_7_Off;
    s_1 = s_St_7_Off_1;
  } else {
    if (turn_on_wm) {
      r_St_7_Washing = true;
    } else {
      r_St_7_Washing = self->pnr;
    };
    r = r_St_7_Washing;
    if (turn_on_wm) {
      s_St_7_Washing_1 = true;
    } else {
      s_St_7_Washing_1 = false;
    };
    s_1 = s_St_7_Washing_1;
  };
  ck_8_1 = s_1;
  if (ck_8_1) {
    is_working_wm_St_7_Off = false;
    nr_St_7_Off = false;
    ns_St_7_Off_1 = true;
    _out->is_working_wm = is_working_wm_St_7_Off;
    nr = nr_St_7_Off;
    ns_1 = ns_St_7_Off_1;
  } else {
    is_working_wm_St_7_Washing = true;
    _out->is_working_wm = is_working_wm_St_7_Washing;
    nr_St_7_Washing = false;
    nr = nr_St_7_Washing;
    ns_St_7_Washing_1 = false;
    ns_1 = ns_St_7_Washing_1;
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
  
  int nr_St_8_Opened;
  int ns_St_8_Opened_1;
  int is_w_opened_St_8_Opened;
  int nr_St_8_Closed;
  int ns_St_8_Closed_1;
  int is_w_opened_St_8_Closed;
  int ck_9_1;
  int r_St_8_Opened;
  int s_St_8_Opened_1;
  int r_St_8_Closed;
  int s_St_8_Closed_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (do_open) {
      r_St_8_Closed = true;
      s_St_8_Closed_1 = false;
    } else {
      r_St_8_Closed = self->pnr;
      s_St_8_Closed_1 = true;
    };
    r = r_St_8_Closed;
    s_1 = s_St_8_Closed_1;
  } else {
    if (do_open) {
      r_St_8_Opened = true;
    } else {
      r_St_8_Opened = self->pnr;
    };
    r = r_St_8_Opened;
    if (do_open) {
      s_St_8_Opened_1 = true;
    } else {
      s_St_8_Opened_1 = false;
    };
    s_1 = s_St_8_Opened_1;
  };
  ck_9_1 = s_1;
  if (ck_9_1) {
    is_w_opened_St_8_Closed = false;
    nr_St_8_Closed = false;
    ns_St_8_Closed_1 = true;
    _out->is_w_opened = is_w_opened_St_8_Closed;
    nr = nr_St_8_Closed;
    ns_1 = ns_St_8_Closed_1;
  } else {
    is_w_opened_St_8_Opened = true;
    _out->is_w_opened = is_w_opened_St_8_Opened;
    nr_St_8_Opened = false;
    nr = nr_St_8_Opened;
    ns_St_8_Opened_1 = false;
    ns_1 = ns_St_8_Opened_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__supervisor_reset(Project__supervisor_mem* self) {
  self->pnr = false;
  self->v_129 = true;
  self->v_130 = true;
  self->pnr_1 = false;
  self->v_145 = true;
  self->v_146 = true;
  self->pnr_2 = false;
  self->ck_23_1 = true;
  self->pnr_3 = false;
  self->ck_21_1 = true;
  self->pnr_4 = false;
  self->ck_19_1 = true;
  self->pnr_5 = false;
  self->ck_17_1 = true;
  self->pnr_6 = false;
  self->ck_15_1 = true;
  self->pnr_7 = false;
  self->ck_13_1 = true;
  self->pnr_8 = false;
  self->ck_11_1 = true;
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
  
  int v_128;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  int ns_St_9_Wait_2_0;
  int ns_St_9_Wait_2_1;
  int ns_St_9_On_2_0;
  int ns_St_9_On_2_1;
  int ns_St_9_Off_2_0;
  int ns_St_9_Off_2_1;
  int ck_28_2_0;
  int ck_28_2_1;
  int nr_St_9_Wait;
  int ns_St_9_Wait_2;
  int ns_St_9_Wait_1;
  int working_state_lac_2_St_9_Wait;
  int nr_St_9_On;
  int ns_St_9_On_2;
  int ns_St_9_On_1;
  int working_state_lac_2_St_9_On;
  int nr_St_9_Off;
  int ns_St_9_Off_2;
  int ns_St_9_Off_1;
  int working_state_lac_2_St_9_Off;
  int ck_28_2;
  int ck_28_1;
  int v_87_2_0;
  int v_87_2_1;
  int v_88;
  int v_87_2;
  int v_87_1;
  int v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_81_2_0;
  int v_81_2_1;
  int v_82;
  int v_81_2;
  int v_81_1;
  int v_80;
  int v_136;
  int v_135;
  int v_134;
  int v_133;
  int v_132;
  int v_131;
  int s_St_9_Wait_2_0;
  int s_St_9_Wait_2_1;
  int s_St_9_On_2_0;
  int s_St_9_On_2_1;
  int s_St_9_Off_2_0;
  int s_St_9_Off_2_1;
  int ck_27_2_0;
  int ck_27_2_1;
  int r_St_9_Wait;
  int s_St_9_Wait_2;
  int s_St_9_Wait_1;
  int r_St_9_On;
  int s_St_9_On_2;
  int s_St_9_On_1;
  int r_St_9_Off;
  int s_St_9_Off_2;
  int s_St_9_Off_1;
  int ck_27_2;
  int ck_27_1;
  int v_144;
  int v_143;
  int v_142;
  int v_141;
  int v_140;
  int v_139;
  int v_138;
  int v_137;
  int ns_1_St_10_Wait_2_0;
  int ns_1_St_10_Wait_2_1;
  int ns_1_St_10_On_2_0;
  int ns_1_St_10_On_2_1;
  int ns_1_St_10_Off_2_0;
  int ns_1_St_10_Off_2_1;
  int ck_26_2_0;
  int ck_26_2_1;
  int nr_1_St_10_Wait;
  int ns_1_St_10_Wait_2;
  int ns_1_St_10_Wait_1;
  int working_state_lac_1_St_10_Wait;
  int nr_1_St_10_On;
  int ns_1_St_10_On_2;
  int ns_1_St_10_On_1;
  int working_state_lac_1_St_10_On;
  int nr_1_St_10_Off;
  int ns_1_St_10_Off_2;
  int ns_1_St_10_Off_1;
  int working_state_lac_1_St_10_Off;
  int ck_26_2;
  int ck_26_1;
  int v_78_2_0;
  int v_78_2_1;
  int v_79;
  int v_78_2;
  int v_78_1;
  int v_77;
  int v_76;
  int v_75;
  int v_74;
  int v_72_2_0;
  int v_72_2_1;
  int v_73;
  int v_72_2;
  int v_72_1;
  int v_71;
  int v_152;
  int v_151;
  int v_150;
  int v_149;
  int v_148;
  int v_147;
  int s_1_St_10_Wait_2_0;
  int s_1_St_10_Wait_2_1;
  int s_1_St_10_On_2_0;
  int s_1_St_10_On_2_1;
  int s_1_St_10_Off_2_0;
  int s_1_St_10_Off_2_1;
  int ck_25_2_0;
  int ck_25_2_1;
  int r_1_St_10_Wait;
  int s_1_St_10_Wait_2;
  int s_1_St_10_Wait_1;
  int r_1_St_10_On;
  int s_1_St_10_On_2;
  int s_1_St_10_On_1;
  int r_1_St_10_Off;
  int s_1_St_10_Off_2;
  int s_1_St_10_Off_1;
  int ck_25_2;
  int ck_25_1;
  int nr_2_St_11_Opened;
  int ns_2_St_11_Opened_1;
  int is_w_opened_1_St_11_Opened;
  int nr_2_St_11_Closed;
  int ns_2_St_11_Closed_1;
  int is_w_opened_1_St_11_Closed;
  int ck_24_1;
  int r_2_St_11_Opened;
  int s_2_St_11_Opened_1;
  int r_2_St_11_Closed;
  int s_2_St_11_Closed_1;
  int nr_3_St_12_Washing;
  int ns_3_St_12_Washing_1;
  int is_working_wm_1_St_12_Washing;
  int nr_3_St_12_Off;
  int ns_3_St_12_Off_1;
  int is_working_wm_1_St_12_Off;
  int ck_22_1;
  int r_3_St_12_Washing;
  int s_3_St_12_Washing_1;
  int r_3_St_12_Off;
  int s_3_St_12_Off_1;
  int nr_4_St_13_On;
  int ns_4_St_13_On_1;
  int is_tv_on_1_St_13_On;
  int nr_4_St_13_Off;
  int ns_4_St_13_Off_1;
  int is_tv_on_1_St_13_Off;
  int ck_20_1;
  int r_4_St_13_On;
  int s_4_St_13_On_1;
  int r_4_St_13_Off;
  int s_4_St_13_Off_1;
  int nr_5_St_14_On;
  int ns_5_St_14_On_1;
  int is_on_l_1_St_14_On;
  int nr_5_St_14_Off;
  int ns_5_St_14_Off_1;
  int is_on_l_1_St_14_Off;
  int ck_18_1;
  int v_70;
  int v_69;
  int v_68;
  int v_67;
  int v_66;
  int v_65;
  int r_5_St_14_On;
  int s_5_St_14_On_1;
  int r_5_St_14_Off;
  int s_5_St_14_Off_1;
  int nr_6_St_15_On;
  int ns_6_St_15_On_1;
  int is_on_rl_1_St_15_On;
  int nr_6_St_15_Off;
  int ns_6_St_15_Off_1;
  int is_on_rl_1_St_15_Off;
  int ck_16_1;
  int r_6_St_15_On;
  int s_6_St_15_On_1;
  int r_6_St_15_Off;
  int s_6_St_15_Off_1;
  int nr_7_St_16_On;
  int ns_7_St_16_On_1;
  int is_on_l1_2_St_16_On;
  int nr_7_St_16_Off;
  int ns_7_St_16_Off_1;
  int is_on_l1_2_St_16_Off;
  int ck_14_1;
  int v_64;
  int v_63;
  int v_62;
  int v_61;
  int v_60;
  int v_59;
  int v_58;
  int v_57;
  int r_7_St_16_On;
  int s_7_St_16_On_1;
  int r_7_St_16_Off;
  int s_7_St_16_Off_1;
  int nr_8_St_17_On;
  int ns_8_St_17_On_1;
  int is_on_l1_1_St_17_On;
  int nr_8_St_17_Off;
  int ns_8_St_17_Off_1;
  int is_on_l1_1_St_17_Off;
  int ck_12_1;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int r_8_St_17_On;
  int s_8_St_17_On_1;
  int r_8_St_17_Off;
  int s_8_St_17_Off_1;
  int nr_9_St_18_Occupied;
  int ns_9_St_18_Occupied_1;
  int has_presence_1_St_18_Occupied;
  int nr_9_St_18_Empty;
  int ns_9_St_18_Empty_1;
  int has_presence_1_St_18_Empty;
  int ck_10_1;
  int r_9_St_18_Occupied;
  int s_9_St_18_Occupied_1;
  int r_9_St_18_Empty;
  int s_9_St_18_Empty_1;
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
  int v_41;
  int v_42;
  int v_43;
  int v_44;
  int v_45;
  int v_46;
  int v_47;
  int v_48;
  int c2_lac;
  int c2_rac;
  int c_lac;
  int c_rac;
  int c_l;
  int c_l5;
  int c_l4;
  int c_l3;
  int c_l2;
  int c_l1;
  turn_on_lac_2 = turn_on_lac;
  ck_27_1 = self->v_129;
  ck_27_2 = self->v_130;
  turn_on_lac_1 = turn_on_rac;
  ck_25_1 = self->v_145;
  ck_25_2 = self->v_146;
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
                                                    self->ck_11_1,
                                                    self->pnr_8,
                                                    self->ck_13_1,
                                                    self->pnr_7,
                                                    self->ck_15_1,
                                                    self->pnr_6,
                                                    self->ck_17_1,
                                                    self->pnr_5,
                                                    self->ck_19_1,
                                                    self->pnr_4,
                                                    self->ck_21_1,
                                                    self->pnr_3,
                                                    self->ck_23_1,
                                                    self->pnr_2, self->v_146,
                                                    self->v_145, self->pnr_1,
                                                    self->v_130, self->v_129,
                                                    self->pnr, true, true,
                                                    true, true, true, true,
                                                    true, true, true, true,
                                                    &Supervisor_controller__supervisor_controller_out_st);
  c2_lac = Supervisor_controller__supervisor_controller_out_st.supervisor_c2_lac;
  c2_rac = Supervisor_controller__supervisor_controller_out_st.supervisor_c2_rac;
  c_lac = Supervisor_controller__supervisor_controller_out_st.supervisor_c_lac;
  c_rac = Supervisor_controller__supervisor_controller_out_st.supervisor_c_rac;
  c_l = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l;
  c_l5 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l5;
  c_l4 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l4;
  c_l3 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l3;
  c_l2 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l2;
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
  if (ck_27_1) {
    ck_27_2_1 = ck_27_2;
    if (ck_27_2_1) {
      v_85 = !(c2_lac_2);
      v_86 = (turn_on_lac_2&&v_85);
      if (v_86) {
        v_88 = true;
        v_87_1 = false;
        v_87_2 = false;
      } else {
        v_88 = self->pnr;
        v_87_1 = true;
        v_87_2 = true;
      };
      v_83 = (turn_on_lac_2&&c_lac_2);
      v_84 = (v_83&&c2_lac_2);
      if (v_84) {
        r_St_9_Off = true;
        s_St_9_Off_1 = true;
        s_St_9_Off_2 = false;
      } else {
        r_St_9_Off = v_88;
        s_St_9_Off_1 = v_87_1;
        s_St_9_Off_2 = v_87_2;
      };
      v_135 = r_St_9_Off;
      v_131 = s_St_9_Off_1;
      v_132 = s_St_9_Off_2;
      if (v_87_1) {
        v_87_2_1 = v_87_2;
      } else {
        v_87_2_0 = v_87_2;
      };
      if (s_St_9_Off_1) {
        s_St_9_Off_2_1 = s_St_9_Off_2;
      } else {
        s_St_9_Off_2_0 = s_St_9_Off_2;
      };
    } else {
      v_80 = !(c2_lac_2);
      if (v_80) {
        v_82 = true;
      } else {
        v_82 = self->pnr;
      };
      if (turn_on_lac_2) {
        r_St_9_On = true;
      } else {
        r_St_9_On = v_82;
      };
      v_135 = r_St_9_On;
      if (v_80) {
        v_81_1 = false;
      } else {
        v_81_1 = true;
      };
      if (turn_on_lac_2) {
        s_St_9_On_1 = true;
      } else {
        s_St_9_On_1 = v_81_1;
      };
      v_131 = s_St_9_On_1;
      if (v_80) {
        v_81_2 = false;
      } else {
        v_81_2 = false;
      };
      if (turn_on_lac_2) {
        s_St_9_On_2 = true;
      } else {
        s_St_9_On_2 = v_81_2;
      };
      v_132 = s_St_9_On_2;
      if (v_81_1) {
        v_81_2_1 = v_81_2;
      } else {
        v_81_2_0 = v_81_2;
      };
      if (s_St_9_On_1) {
        s_St_9_On_2_1 = s_St_9_On_2;
      } else {
        s_St_9_On_2_0 = s_St_9_On_2;
      };
    };
    s_1_3 = v_131;
    s_2_2 = v_132;
    r = v_135;
  } else {
    ck_27_2_0 = ck_27_2;
    if (ck_27_2_0) {
      v_136 = true;
      v_133 = true;
      v_134 = true;
    } else {
      if (c2_lac_2) {
        r_St_9_Wait = true;
      } else {
        r_St_9_Wait = self->pnr;
      };
      v_136 = r_St_9_Wait;
      if (c2_lac_2) {
        s_St_9_Wait_1 = true;
      } else {
        s_St_9_Wait_1 = false;
      };
      v_133 = s_St_9_Wait_1;
      if (c2_lac_2) {
        s_St_9_Wait_2 = false;
      } else {
        s_St_9_Wait_2 = false;
      };
      v_134 = s_St_9_Wait_2;
    };
    s_1_3 = v_133;
    s_2_2 = v_134;
    r = v_136;
  };
  ck_28_1 = s_1_3;
  ck_28_2 = s_2_2;
  if (ck_28_1) {
    ck_28_2_1 = ck_28_2;
    if (ck_28_2_1) {
      working_state_lac_2_St_9_Off = 0;
      nr_St_9_Off = false;
      ns_St_9_Off_1 = true;
      ns_St_9_Off_2 = true;
      v_121 = working_state_lac_2_St_9_Off;
      v_127 = nr_St_9_Off;
      v_123 = ns_St_9_Off_1;
      v_124 = ns_St_9_Off_2;
      if (ns_St_9_Off_1) {
        ns_St_9_Off_2_1 = ns_St_9_Off_2;
      } else {
        ns_St_9_Off_2_0 = ns_St_9_Off_2;
      };
    } else {
      working_state_lac_2_St_9_On = 2;
      v_121 = working_state_lac_2_St_9_On;
      nr_St_9_On = false;
      v_127 = nr_St_9_On;
      ns_St_9_On_1 = true;
      v_123 = ns_St_9_On_1;
      ns_St_9_On_2 = false;
      v_124 = ns_St_9_On_2;
      if (ns_St_9_On_1) {
        ns_St_9_On_2_1 = ns_St_9_On_2;
      } else {
        ns_St_9_On_2_0 = ns_St_9_On_2;
      };
    };
    working_state_lac_2 = v_121;
    ns_1_3 = v_123;
    ns_2_2 = v_124;
    nr = v_127;
  } else {
    ck_28_2_0 = ck_28_2;
    if (ck_28_2_0) {
      v_122 = 0;
      v_128 = true;
      v_125 = true;
      v_126 = true;
    } else {
      working_state_lac_2_St_9_Wait = 1;
      v_122 = working_state_lac_2_St_9_Wait;
      nr_St_9_Wait = false;
      v_128 = nr_St_9_Wait;
      ns_St_9_Wait_1 = false;
      v_125 = ns_St_9_Wait_1;
      ns_St_9_Wait_2 = false;
      v_126 = ns_St_9_Wait_2;
    };
    working_state_lac_2 = v_122;
    ns_1_3 = v_125;
    ns_2_2 = v_126;
    nr = v_128;
  };
  _out->working_state_lac = working_state_lac_2;
  v_41 = (_out->working_state_lac>0);
  if (ns_1_3) {
    ns_2_2_1 = ns_2_2;
  } else {
    ns_2_2_0 = ns_2_2;
  };
  if (!(ck_28_1)) {
    if (!(ck_28_2_0)) {
      if (ns_St_9_Wait_1) {
        ns_St_9_Wait_2_1 = ns_St_9_Wait_2;
      } else {
        ns_St_9_Wait_2_0 = ns_St_9_Wait_2;
      };
    };
  };
  if (s_1_3) {
    s_2_2_1 = s_2_2;
  } else {
    s_2_2_0 = s_2_2;
  };
  if (!(ck_27_1)) {
    if (!(ck_27_2_0)) {
      if (s_St_9_Wait_1) {
        s_St_9_Wait_2_1 = s_St_9_Wait_2;
      } else {
        s_St_9_Wait_2_0 = s_St_9_Wait_2;
      };
    };
  };
  if (ck_25_1) {
    ck_25_2_1 = ck_25_2;
    if (ck_25_2_1) {
      v_76 = !(c2_lac_1);
      v_77 = (turn_on_lac_1&&v_76);
      if (v_77) {
        v_79 = true;
        v_78_1 = false;
        v_78_2 = false;
      } else {
        v_79 = self->pnr_1;
        v_78_1 = true;
        v_78_2 = true;
      };
      v_74 = (turn_on_lac_1&&c_lac_1);
      v_75 = (v_74&&c2_lac_1);
      if (v_75) {
        r_1_St_10_Off = true;
        s_1_St_10_Off_1 = true;
        s_1_St_10_Off_2 = false;
      } else {
        r_1_St_10_Off = v_79;
        s_1_St_10_Off_1 = v_78_1;
        s_1_St_10_Off_2 = v_78_2;
      };
      v_151 = r_1_St_10_Off;
      v_147 = s_1_St_10_Off_1;
      v_148 = s_1_St_10_Off_2;
      if (v_78_1) {
        v_78_2_1 = v_78_2;
      } else {
        v_78_2_0 = v_78_2;
      };
      if (s_1_St_10_Off_1) {
        s_1_St_10_Off_2_1 = s_1_St_10_Off_2;
      } else {
        s_1_St_10_Off_2_0 = s_1_St_10_Off_2;
      };
    } else {
      v_71 = !(c2_lac_1);
      if (v_71) {
        v_73 = true;
      } else {
        v_73 = self->pnr_1;
      };
      if (turn_on_lac_1) {
        r_1_St_10_On = true;
      } else {
        r_1_St_10_On = v_73;
      };
      v_151 = r_1_St_10_On;
      if (v_71) {
        v_72_1 = false;
      } else {
        v_72_1 = true;
      };
      if (turn_on_lac_1) {
        s_1_St_10_On_1 = true;
      } else {
        s_1_St_10_On_1 = v_72_1;
      };
      v_147 = s_1_St_10_On_1;
      if (v_71) {
        v_72_2 = false;
      } else {
        v_72_2 = false;
      };
      if (turn_on_lac_1) {
        s_1_St_10_On_2 = true;
      } else {
        s_1_St_10_On_2 = v_72_2;
      };
      v_148 = s_1_St_10_On_2;
      if (v_72_1) {
        v_72_2_1 = v_72_2;
      } else {
        v_72_2_0 = v_72_2;
      };
      if (s_1_St_10_On_1) {
        s_1_St_10_On_2_1 = s_1_St_10_On_2;
      } else {
        s_1_St_10_On_2_0 = s_1_St_10_On_2;
      };
    };
    s_1_1 = v_147;
    s_1_2 = v_148;
    r_1 = v_151;
  } else {
    ck_25_2_0 = ck_25_2;
    if (ck_25_2_0) {
      v_152 = true;
      v_149 = true;
      v_150 = true;
    } else {
      if (c2_lac_1) {
        r_1_St_10_Wait = true;
      } else {
        r_1_St_10_Wait = self->pnr_1;
      };
      v_152 = r_1_St_10_Wait;
      if (c2_lac_1) {
        s_1_St_10_Wait_1 = true;
      } else {
        s_1_St_10_Wait_1 = false;
      };
      v_149 = s_1_St_10_Wait_1;
      if (c2_lac_1) {
        s_1_St_10_Wait_2 = false;
      } else {
        s_1_St_10_Wait_2 = false;
      };
      v_150 = s_1_St_10_Wait_2;
    };
    s_1_1 = v_149;
    s_1_2 = v_150;
    r_1 = v_152;
  };
  ck_26_1 = s_1_1;
  ck_26_2 = s_1_2;
  if (ck_26_1) {
    ck_26_2_1 = ck_26_2;
    if (ck_26_2_1) {
      working_state_lac_1_St_10_Off = 0;
      nr_1_St_10_Off = false;
      ns_1_St_10_Off_1 = true;
      ns_1_St_10_Off_2 = true;
      v_137 = working_state_lac_1_St_10_Off;
      v_143 = nr_1_St_10_Off;
      v_139 = ns_1_St_10_Off_1;
      v_140 = ns_1_St_10_Off_2;
      if (ns_1_St_10_Off_1) {
        ns_1_St_10_Off_2_1 = ns_1_St_10_Off_2;
      } else {
        ns_1_St_10_Off_2_0 = ns_1_St_10_Off_2;
      };
    } else {
      working_state_lac_1_St_10_On = 2;
      v_137 = working_state_lac_1_St_10_On;
      nr_1_St_10_On = false;
      v_143 = nr_1_St_10_On;
      ns_1_St_10_On_1 = true;
      v_139 = ns_1_St_10_On_1;
      ns_1_St_10_On_2 = false;
      v_140 = ns_1_St_10_On_2;
      if (ns_1_St_10_On_1) {
        ns_1_St_10_On_2_1 = ns_1_St_10_On_2;
      } else {
        ns_1_St_10_On_2_0 = ns_1_St_10_On_2;
      };
    };
    working_state_lac_1 = v_137;
    ns_1_1 = v_139;
    ns_1_2 = v_140;
    nr_1 = v_143;
  } else {
    ck_26_2_0 = ck_26_2;
    if (ck_26_2_0) {
      v_138 = 0;
      v_144 = true;
      v_141 = true;
      v_142 = true;
    } else {
      working_state_lac_1_St_10_Wait = 1;
      v_138 = working_state_lac_1_St_10_Wait;
      nr_1_St_10_Wait = false;
      v_144 = nr_1_St_10_Wait;
      ns_1_St_10_Wait_1 = false;
      v_141 = ns_1_St_10_Wait_1;
      ns_1_St_10_Wait_2 = false;
      v_142 = ns_1_St_10_Wait_2;
    };
    working_state_lac_1 = v_138;
    ns_1_1 = v_141;
    ns_1_2 = v_142;
    nr_1 = v_144;
  };
  _out->working_state_rac = working_state_lac_1;
  v_33 = (_out->working_state_lac+_out->working_state_rac);
  v_34 = (v_33>0);
  v_36 = (_out->working_state_lac+_out->working_state_rac);
  v_37 = (v_36>1);
  v_40 = (_out->working_state_rac>0);
  v_42 = (v_40&&v_41);
  rule2 = !(v_42);
  if (ns_1_1) {
    ns_1_2_1 = ns_1_2;
  } else {
    ns_1_2_0 = ns_1_2;
  };
  if (!(ck_26_1)) {
    if (!(ck_26_2_0)) {
      if (ns_1_St_10_Wait_1) {
        ns_1_St_10_Wait_2_1 = ns_1_St_10_Wait_2;
      } else {
        ns_1_St_10_Wait_2_0 = ns_1_St_10_Wait_2;
      };
    };
  };
  if (s_1_1) {
    s_1_2_1 = s_1_2;
  } else {
    s_1_2_0 = s_1_2;
  };
  if (!(ck_25_1)) {
    if (!(ck_25_2_0)) {
      if (s_1_St_10_Wait_1) {
        s_1_St_10_Wait_2_1 = s_1_St_10_Wait_2;
      } else {
        s_1_St_10_Wait_2_0 = s_1_St_10_Wait_2;
      };
    };
  };
  if (self->ck_23_1) {
    if (do_open_1) {
      r_2_St_11_Closed = true;
      s_2_St_11_Closed_1 = false;
    } else {
      r_2_St_11_Closed = self->pnr_2;
      s_2_St_11_Closed_1 = true;
    };
    r_2 = r_2_St_11_Closed;
    s_2_1 = s_2_St_11_Closed_1;
  } else {
    if (do_open_1) {
      r_2_St_11_Opened = true;
    } else {
      r_2_St_11_Opened = self->pnr_2;
    };
    r_2 = r_2_St_11_Opened;
    if (do_open_1) {
      s_2_St_11_Opened_1 = true;
    } else {
      s_2_St_11_Opened_1 = false;
    };
    s_2_1 = s_2_St_11_Opened_1;
  };
  ck_24_1 = s_2_1;
  if (ck_24_1) {
    is_w_opened_1_St_11_Closed = false;
    nr_2_St_11_Closed = false;
    ns_2_St_11_Closed_1 = true;
    is_w_opened_1 = is_w_opened_1_St_11_Closed;
    nr_2 = nr_2_St_11_Closed;
    ns_2_1 = ns_2_St_11_Closed_1;
  } else {
    is_w_opened_1_St_11_Opened = true;
    is_w_opened_1 = is_w_opened_1_St_11_Opened;
    nr_2_St_11_Opened = false;
    nr_2 = nr_2_St_11_Opened;
    ns_2_St_11_Opened_1 = false;
    ns_2_1 = ns_2_St_11_Opened_1;
  };
  _out->is_w_opened = is_w_opened_1;
  v_35 = (_out->is_w_opened&&v_34);
  rule5 = !(v_35);
  if (self->ck_21_1) {
    if (turn_on_wm_1) {
      r_3_St_12_Off = true;
      s_3_St_12_Off_1 = false;
    } else {
      r_3_St_12_Off = self->pnr_3;
      s_3_St_12_Off_1 = true;
    };
    r_3 = r_3_St_12_Off;
    s_3_1 = s_3_St_12_Off_1;
  } else {
    if (turn_on_wm_1) {
      r_3_St_12_Washing = true;
    } else {
      r_3_St_12_Washing = self->pnr_3;
    };
    r_3 = r_3_St_12_Washing;
    if (turn_on_wm_1) {
      s_3_St_12_Washing_1 = true;
    } else {
      s_3_St_12_Washing_1 = false;
    };
    s_3_1 = s_3_St_12_Washing_1;
  };
  ck_22_1 = s_3_1;
  if (ck_22_1) {
    is_working_wm_1_St_12_Off = false;
    nr_3_St_12_Off = false;
    ns_3_St_12_Off_1 = true;
    is_working_wm_1 = is_working_wm_1_St_12_Off;
    nr_3 = nr_3_St_12_Off;
    ns_3_1 = ns_3_St_12_Off_1;
  } else {
    is_working_wm_1_St_12_Washing = true;
    is_working_wm_1 = is_working_wm_1_St_12_Washing;
    nr_3_St_12_Washing = false;
    nr_3 = nr_3_St_12_Washing;
    ns_3_St_12_Washing_1 = false;
    ns_3_1 = ns_3_St_12_Washing_1;
  };
  _out->is_working_wm = is_working_wm_1;
  v_38 = (_out->is_working_wm&&v_37);
  rule4 = !(v_38);
  if (self->ck_19_1) {
    if (turn_on_tv_1) {
      r_4_St_13_Off = true;
      s_4_St_13_Off_1 = false;
    } else {
      r_4_St_13_Off = self->pnr_4;
      s_4_St_13_Off_1 = true;
    };
    r_4 = r_4_St_13_Off;
    s_4_1 = s_4_St_13_Off_1;
  } else {
    if (turn_on_tv_1) {
      r_4_St_13_On = true;
    } else {
      r_4_St_13_On = self->pnr_4;
    };
    r_4 = r_4_St_13_On;
    if (turn_on_tv_1) {
      s_4_St_13_On_1 = true;
    } else {
      s_4_St_13_On_1 = false;
    };
    s_4_1 = s_4_St_13_On_1;
  };
  ck_20_1 = s_4_1;
  if (ck_20_1) {
    is_tv_on_1_St_13_Off = false;
    nr_4_St_13_Off = false;
    ns_4_St_13_Off_1 = true;
    is_tv_on_1 = is_tv_on_1_St_13_Off;
    nr_4 = nr_4_St_13_Off;
    ns_4_1 = ns_4_St_13_Off_1;
  } else {
    is_tv_on_1_St_13_On = true;
    is_tv_on_1 = is_tv_on_1_St_13_On;
    nr_4_St_13_On = false;
    nr_4 = nr_4_St_13_On;
    ns_4_St_13_On_1 = false;
    ns_4_1 = ns_4_St_13_On_1;
  };
  _out->is_tv_on = is_tv_on_1;
  v = !(_out->is_tv_on);
  if (self->ck_17_1) {
    v_69 = !(c_l1_3);
    v_70 = (turn_on_l_1&&v_69);
    if (v_70) {
      r_5_St_14_Off = true;
      s_5_St_14_Off_1 = false;
    } else {
      r_5_St_14_Off = self->pnr_5;
      s_5_St_14_Off_1 = true;
    };
    r_5 = r_5_St_14_Off;
    s_5_1 = s_5_St_14_Off_1;
  } else {
    v_67 = !(c_l2_3);
    v_65 = !(c_l1_3);
    v_66 = (turn_on_l_1&&v_65);
    v_68 = (v_66||v_67);
    if (v_68) {
      r_5_St_14_On = true;
    } else {
      r_5_St_14_On = self->pnr_5;
    };
    r_5 = r_5_St_14_On;
    if (v_68) {
      s_5_St_14_On_1 = true;
    } else {
      s_5_St_14_On_1 = false;
    };
    s_5_1 = s_5_St_14_On_1;
  };
  ck_18_1 = s_5_1;
  if (ck_18_1) {
    is_on_l_1_St_14_Off = false;
    nr_5_St_14_Off = false;
    ns_5_St_14_Off_1 = true;
    is_on_l_1 = is_on_l_1_St_14_Off;
    nr_5 = nr_5_St_14_Off;
    ns_5_1 = ns_5_St_14_Off_1;
  } else {
    is_on_l_1_St_14_On = true;
    is_on_l_1 = is_on_l_1_St_14_On;
    nr_5_St_14_On = false;
    nr_5 = nr_5_St_14_On;
    ns_5_St_14_On_1 = false;
    ns_5_1 = ns_5_St_14_On_1;
  };
  _out->is_on_l = is_on_l_1;
  if (self->ck_15_1) {
    if (turn_on_rl_1) {
      r_6_St_15_Off = true;
      s_6_St_15_Off_1 = false;
    } else {
      r_6_St_15_Off = self->pnr_6;
      s_6_St_15_Off_1 = true;
    };
    r_6 = r_6_St_15_Off;
    s_6_1 = s_6_St_15_Off_1;
  } else {
    if (turn_on_rl_1) {
      r_6_St_15_On = true;
    } else {
      r_6_St_15_On = self->pnr_6;
    };
    r_6 = r_6_St_15_On;
    if (turn_on_rl_1) {
      s_6_St_15_On_1 = true;
    } else {
      s_6_St_15_On_1 = false;
    };
    s_6_1 = s_6_St_15_On_1;
  };
  ck_16_1 = s_6_1;
  if (ck_16_1) {
    is_on_rl_1_St_15_Off = false;
    nr_6_St_15_Off = false;
    ns_6_St_15_Off_1 = true;
    is_on_rl_1 = is_on_rl_1_St_15_Off;
    nr_6 = nr_6_St_15_Off;
    ns_6_1 = ns_6_St_15_Off_1;
  } else {
    is_on_rl_1_St_15_On = true;
    is_on_rl_1 = is_on_rl_1_St_15_On;
    nr_6_St_15_On = false;
    nr_6 = nr_6_St_15_On;
    ns_6_St_15_On_1 = false;
    ns_6_1 = ns_6_St_15_On_1;
  };
  _out->is_on_rl = is_on_rl_1;
  v_39 = (_out->is_on_rl&&_out->is_on_l);
  rule3 = !(v_39);
  if (self->ck_13_1) {
    v_63 = !(c_l2_2);
    v_61 = !(c_l1_2);
    v_62 = (turn_on_l1_2&&v_61);
    v_64 = (v_62||v_63);
    if (v_64) {
      r_7_St_16_Off = true;
      s_7_St_16_Off_1 = false;
    } else {
      r_7_St_16_Off = self->pnr_7;
      s_7_St_16_Off_1 = true;
    };
    r_7 = r_7_St_16_Off;
    s_7_1 = s_7_St_16_Off_1;
  } else {
    v_59 = !(c_l2_2);
    v_57 = !(c_l1_2);
    v_58 = (turn_on_l1_2&&v_57);
    v_60 = (v_58||v_59);
    if (v_60) {
      r_7_St_16_On = true;
    } else {
      r_7_St_16_On = self->pnr_7;
    };
    r_7 = r_7_St_16_On;
    if (v_60) {
      s_7_St_16_On_1 = true;
    } else {
      s_7_St_16_On_1 = false;
    };
    s_7_1 = s_7_St_16_On_1;
  };
  ck_14_1 = s_7_1;
  if (ck_14_1) {
    is_on_l1_2_St_16_Off = false;
    nr_7_St_16_Off = false;
    ns_7_St_16_Off_1 = true;
    is_on_l1_2 = is_on_l1_2_St_16_Off;
    nr_7 = nr_7_St_16_Off;
    ns_7_1 = ns_7_St_16_Off_1;
  } else {
    is_on_l1_2_St_16_On = true;
    is_on_l1_2 = is_on_l1_2_St_16_On;
    nr_7_St_16_On = false;
    nr_7 = nr_7_St_16_On;
    ns_7_St_16_On_1 = false;
    ns_7_1 = ns_7_St_16_On_1;
  };
  _out->is_on_l2 = is_on_l1_2;
  v_30 = !(_out->is_on_l2);
  if (self->ck_11_1) {
    v_55 = !(c_l2_1);
    v_53 = !(c_l1_1);
    v_54 = (turn_on_l1_1&&v_53);
    v_56 = (v_54||v_55);
    if (v_56) {
      r_8_St_17_Off = true;
      s_8_St_17_Off_1 = false;
    } else {
      r_8_St_17_Off = self->pnr_8;
      s_8_St_17_Off_1 = true;
    };
    r_8 = r_8_St_17_Off;
    s_8_1 = s_8_St_17_Off_1;
  } else {
    v_51 = !(c_l2_1);
    v_49 = !(c_l1_1);
    v_50 = (turn_on_l1_1&&v_49);
    v_52 = (v_50||v_51);
    if (v_52) {
      r_8_St_17_On = true;
    } else {
      r_8_St_17_On = self->pnr_8;
    };
    r_8 = r_8_St_17_On;
    if (v_52) {
      s_8_St_17_On_1 = true;
    } else {
      s_8_St_17_On_1 = false;
    };
    s_8_1 = s_8_St_17_On_1;
  };
  ck_12_1 = s_8_1;
  if (ck_12_1) {
    is_on_l1_1_St_17_Off = false;
    nr_8_St_17_Off = false;
    ns_8_St_17_Off_1 = true;
    is_on_l1_1 = is_on_l1_1_St_17_Off;
    nr_8 = nr_8_St_17_Off;
    ns_8_1 = ns_8_St_17_Off_1;
  } else {
    is_on_l1_1_St_17_On = true;
    is_on_l1_1 = is_on_l1_1_St_17_On;
    nr_8_St_17_On = false;
    nr_8 = nr_8_St_17_On;
    ns_8_St_17_On_1 = false;
    ns_8_1 = ns_8_St_17_On_1;
  };
  _out->is_on_l1 = is_on_l1_1;
  v_29 = !(_out->is_on_l1);
  v_31 = (v_29&&v_30);
  v_43 = (_out->is_on_l1&&_out->is_on_l2);
  rule1 = !(v_43);
  v_44 = (rule1&&rule2);
  v_45 = (v_44&&rule3);
  v_46 = (v_45&&rule4);
  v_47 = (v_46&&rule5);
  if (self->ck_1) {
    if (presence_1) {
      r_9_St_18_Empty = true;
      s_9_St_18_Empty_1 = false;
    } else {
      r_9_St_18_Empty = self->pnr_9;
      s_9_St_18_Empty_1 = true;
    };
    r_9 = r_9_St_18_Empty;
    s_9_1 = s_9_St_18_Empty_1;
  } else {
    if (presence_1) {
      r_9_St_18_Occupied = true;
    } else {
      r_9_St_18_Occupied = self->pnr_9;
    };
    r_9 = r_9_St_18_Occupied;
    if (presence_1) {
      s_9_St_18_Occupied_1 = true;
    } else {
      s_9_St_18_Occupied_1 = false;
    };
    s_9_1 = s_9_St_18_Occupied_1;
  };
  ck_10_1 = s_9_1;
  if (ck_10_1) {
    has_presence_1_St_18_Empty = false;
    nr_9_St_18_Empty = false;
    ns_9_St_18_Empty_1 = true;
    has_presence_1 = has_presence_1_St_18_Empty;
    nr_9 = nr_9_St_18_Empty;
    ns_9_1 = ns_9_St_18_Empty_1;
  } else {
    has_presence_1_St_18_Occupied = true;
    has_presence_1 = has_presence_1_St_18_Occupied;
    nr_9_St_18_Occupied = false;
    nr_9 = nr_9_St_18_Occupied;
    ns_9_St_18_Occupied_1 = false;
    ns_9_1 = ns_9_St_18_Occupied_1;
  };
  _out->has_presence = has_presence_1;
  v_28 = (_out->has_presence&&v);
  v_32 = (v_28&&v_31);
  rule6 = !(v_32);
  v_48 = (v_47&&rule6);
  self->pnr = nr;
  self->v_129 = ns_1_3;
  self->v_130 = ns_2_2;
  self->pnr_1 = nr_1;
  self->v_145 = ns_1_1;
  self->v_146 = ns_1_2;
  self->pnr_2 = nr_2;
  self->ck_23_1 = ns_2_1;
  self->pnr_3 = nr_3;
  self->ck_21_1 = ns_3_1;
  self->pnr_4 = nr_4;
  self->ck_19_1 = ns_4_1;
  self->pnr_5 = nr_5;
  self->ck_17_1 = ns_5_1;
  self->pnr_6 = nr_6;
  self->ck_15_1 = ns_6_1;
  self->pnr_7 = nr_7;
  self->ck_13_1 = ns_7_1;
  self->pnr_8 = nr_8;
  self->ck_11_1 = ns_8_1;
  self->pnr_9 = nr_9;
  self->ck_1 = ns_9_1;;
}


/* --- Generated the 4/7/2018 at 11:9 --- */
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
  int v;
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
    v = !(presence);
    if (v) {
      r_St_Occupied = true;
    } else {
      r_St_Occupied = self->pnr;
    };
    r = r_St_Occupied;
    if (v) {
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
    v_2 = (turn_on_l1&&c_l1);
    v_3 = (v_2||c_l2);
    if (v_3) {
      r_St_1_Off = true;
      s_St_1_Off_1 = false;
    } else {
      r_St_1_Off = self->pnr;
      s_St_1_Off_1 = true;
    };
    r = r_St_1_Off;
    s_1 = s_St_1_Off_1;
  } else {
    v = (turn_on_l1&&c_l1);
    v_1 = (v||c_l2);
    if (v_1) {
      r_St_1_On = true;
    } else {
      r_St_1_On = self->pnr;
    };
    r = r_St_1_On;
    if (v_1) {
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

void Project__room_reading_lamp_reset(Project__room_reading_lamp_mem* self) {
  self->pnr = false;
  self->ck_1 = false;
}

void Project__room_reading_lamp_step(int turn_on_rl,
                                     Project__room_reading_lamp_out* _out,
                                     Project__room_reading_lamp_mem* self) {
  
  int nr_St_2_Off;
  int ns_St_2_Off_1;
  int is_on_rl_St_2_Off;
  int nr_St_2_On;
  int ns_St_2_On_1;
  int is_on_rl_St_2_On;
  int ck_3_1;
  int v;
  int r_St_2_Off;
  int s_St_2_Off_1;
  int r_St_2_On;
  int s_St_2_On_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_rl) {
      r_St_2_Off = true;
    } else {
      r_St_2_Off = self->pnr;
    };
    r = r_St_2_Off;
    if (turn_on_rl) {
      s_St_2_Off_1 = false;
    } else {
      s_St_2_Off_1 = true;
    };
    s_1 = s_St_2_Off_1;
  } else {
    v = !(turn_on_rl);
    if (v) {
      r_St_2_On = true;
      s_St_2_On_1 = true;
    } else {
      r_St_2_On = self->pnr;
      s_St_2_On_1 = false;
    };
    r = r_St_2_On;
    s_1 = s_St_2_On_1;
  };
  ck_3_1 = s_1;
  if (ck_3_1) {
    is_on_rl_St_2_Off = false;
    _out->is_on_rl = is_on_rl_St_2_Off;
    nr_St_2_Off = false;
    nr = nr_St_2_Off;
    ns_St_2_Off_1 = true;
    ns_1 = ns_St_2_Off_1;
  } else {
    is_on_rl_St_2_On = true;
    nr_St_2_On = false;
    ns_St_2_On_1 = false;
    _out->is_on_rl = is_on_rl_St_2_On;
    nr = nr_St_2_On;
    ns_1 = ns_St_2_On_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__room_lamp_reset(Project__room_lamp_mem* self) {
  self->pnr = false;
  self->ck_1 = false;
}

void Project__room_lamp_step(int turn_on_l, int c_l,
                             Project__room_lamp_out* _out,
                             Project__room_lamp_mem* self) {
  
  int nr_St_3_Off;
  int ns_St_3_Off_1;
  int is_on_l_St_3_Off;
  int nr_St_3_On;
  int ns_St_3_On_1;
  int is_on_l_St_3_On;
  int ck_4_1;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v;
  int r_St_3_Off;
  int s_St_3_Off_1;
  int r_St_3_On;
  int s_St_3_On_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    v = (turn_on_l&&c_l);
    v_4 = (v||c_l);
    if (v_4) {
      r_St_3_Off = true;
    } else {
      r_St_3_Off = self->pnr;
    };
    r = r_St_3_Off;
    if (v_4) {
      s_St_3_Off_1 = false;
    } else {
      s_St_3_Off_1 = true;
    };
    s_1 = s_St_3_Off_1;
  } else {
    v_8 = !(c_l);
    v_6 = !(c_l);
    v_5 = !(turn_on_l);
    v_7 = (v_5&&v_6);
    v_9 = (v_7||v_8);
    if (v_9) {
      r_St_3_On = true;
      s_St_3_On_1 = true;
    } else {
      r_St_3_On = self->pnr;
      s_St_3_On_1 = false;
    };
    r = r_St_3_On;
    s_1 = s_St_3_On_1;
  };
  ck_4_1 = s_1;
  if (ck_4_1) {
    is_on_l_St_3_Off = false;
    _out->is_on_l = is_on_l_St_3_Off;
    nr_St_3_Off = false;
    nr = nr_St_3_Off;
    ns_St_3_Off_1 = true;
    ns_1 = ns_St_3_Off_1;
  } else {
    is_on_l_St_3_On = true;
    nr_St_3_On = false;
    ns_St_3_On_1 = false;
    _out->is_on_l = is_on_l_St_3_On;
    nr = nr_St_3_On;
    ns_1 = ns_St_3_On_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__room_air_conditioner_reset(Project__room_air_conditioner_mem* self) {
  self->pnr = false;
  self->v_72 = true;
  self->v_73 = true;
}

void Project__room_air_conditioner_step(int turn_on_rac, int c_rac,
                                        Project__room_air_conditioner_out* _out,
                                        Project__room_air_conditioner_mem* self) {
  
  int v_71;
  int v_70;
  int v_69;
  int v_68;
  int v_67;
  int v_66;
  int v_65;
  int v_64;
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
  int v_16_2_0;
  int v_16_2_1;
  int v_17;
  int v_16_2;
  int v_16_1;
  int v_15;
  int v_14;
  int v_13;
  int v_11_2_0;
  int v_11_2_1;
  int v_12;
  int v_11_2;
  int v_11_1;
  int v_10;
  int v;
  int v_79;
  int v_78;
  int v_77;
  int v_76;
  int v_75;
  int v_74;
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
  ck_1 = self->v_72;
  ck_2 = self->v_73;
  if (ck_1) {
    ck_2_1 = ck_2;
    if (ck_2_1) {
      v_14 = !(c_rac);
      v_15 = (turn_on_rac&&v_14);
      if (v_15) {
        v_17 = true;
        v_16_1 = false;
        v_16_2 = false;
      } else {
        v_17 = self->pnr;
        v_16_1 = true;
        v_16_2 = true;
      };
      v_13 = (turn_on_rac&&c_rac);
      if (v_13) {
        r_St_4_Off = true;
        s_St_4_Off_1 = true;
        s_St_4_Off_2 = false;
      } else {
        r_St_4_Off = v_17;
        s_St_4_Off_1 = v_16_1;
        s_St_4_Off_2 = v_16_2;
      };
      v_78 = r_St_4_Off;
      v_74 = s_St_4_Off_1;
      v_75 = s_St_4_Off_2;
      if (v_16_1) {
        v_16_2_1 = v_16_2;
      } else {
        v_16_2_0 = v_16_2;
      };
      if (s_St_4_Off_1) {
        s_St_4_Off_2_1 = s_St_4_Off_2;
      } else {
        s_St_4_Off_2_0 = s_St_4_Off_2;
      };
    } else {
      v_10 = !(c_rac);
      if (v_10) {
        v_12 = true;
        v_11_1 = false;
        v_11_2 = false;
      } else {
        v_12 = self->pnr;
        v_11_1 = true;
        v_11_2 = false;
      };
      v = !(turn_on_rac);
      if (v) {
        r_St_4_On = true;
      } else {
        r_St_4_On = v_12;
      };
      v_78 = r_St_4_On;
      if (v) {
        s_St_4_On_1 = true;
      } else {
        s_St_4_On_1 = v_11_1;
      };
      v_74 = s_St_4_On_1;
      if (v) {
        s_St_4_On_2 = true;
      } else {
        s_St_4_On_2 = v_11_2;
      };
      v_75 = s_St_4_On_2;
      if (v_11_1) {
        v_11_2_1 = v_11_2;
      } else {
        v_11_2_0 = v_11_2;
      };
      if (s_St_4_On_1) {
        s_St_4_On_2_1 = s_St_4_On_2;
      } else {
        s_St_4_On_2_0 = s_St_4_On_2;
      };
    };
    s_1 = v_74;
    s_2 = v_75;
    r = v_78;
  } else {
    ck_2_0 = ck_2;
    if (ck_2_0) {
      v_79 = true;
      v_76 = true;
      v_77 = true;
    } else {
      if (c_rac) {
        r_St_4_Wait = true;
      } else {
        r_St_4_Wait = self->pnr;
      };
      v_79 = r_St_4_Wait;
      if (c_rac) {
        s_St_4_Wait_1 = true;
      } else {
        s_St_4_Wait_1 = false;
      };
      v_76 = s_St_4_Wait_1;
      if (c_rac) {
        s_St_4_Wait_2 = false;
      } else {
        s_St_4_Wait_2 = false;
      };
      v_77 = s_St_4_Wait_2;
    };
    s_1 = v_76;
    s_2 = v_77;
    r = v_79;
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
      v_64 = working_state_rac_St_4_Off;
      v_70 = nr_St_4_Off;
      v_66 = ns_St_4_Off_1;
      v_67 = ns_St_4_Off_2;
      if (ns_St_4_Off_1) {
        ns_St_4_Off_2_1 = ns_St_4_Off_2;
      } else {
        ns_St_4_Off_2_0 = ns_St_4_Off_2;
      };
    } else {
      working_state_rac_St_4_On = 1;
      v_64 = working_state_rac_St_4_On;
      nr_St_4_On = false;
      v_70 = nr_St_4_On;
      ns_St_4_On_1 = true;
      v_66 = ns_St_4_On_1;
      ns_St_4_On_2 = false;
      v_67 = ns_St_4_On_2;
      if (ns_St_4_On_1) {
        ns_St_4_On_2_1 = ns_St_4_On_2;
      } else {
        ns_St_4_On_2_0 = ns_St_4_On_2;
      };
    };
    _out->working_state_rac = v_64;
    ns_1 = v_66;
    ns_2 = v_67;
    nr = v_70;
  } else {
    ck_5_2_0 = ck_5_2;
    if (ck_5_2_0) {
      v_65 = 0;
      v_71 = true;
      v_68 = true;
      v_69 = true;
    } else {
      working_state_rac_St_4_Wait = 2;
      v_65 = working_state_rac_St_4_Wait;
      nr_St_4_Wait = false;
      v_71 = nr_St_4_Wait;
      ns_St_4_Wait_1 = false;
      v_68 = ns_St_4_Wait_1;
      ns_St_4_Wait_2 = false;
      v_69 = ns_St_4_Wait_2;
    };
    _out->working_state_rac = v_65;
    ns_1 = v_68;
    ns_2 = v_69;
    nr = v_71;
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
  self->v_72 = ns_1;
  self->v_73 = ns_2;;
}

void Project__living_room_air_conditioner_reset(Project__living_room_air_conditioner_mem* self) {
  self->pnr = false;
  self->v_88 = true;
  self->v_89 = true;
}

void Project__living_room_air_conditioner_step(int turn_on_lac, int c_lac,
                                               Project__living_room_air_conditioner_out* _out,
                                               Project__living_room_air_conditioner_mem* self) {
  
  int v_87;
  int v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_82;
  int v_81;
  int v_80;
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
  int v_24_2_0;
  int v_24_2_1;
  int v_25;
  int v_24_2;
  int v_24_1;
  int v_23;
  int v_22;
  int v_21;
  int v_19_2_0;
  int v_19_2_1;
  int v_20;
  int v_19_2;
  int v_19_1;
  int v_18;
  int v;
  int v_95;
  int v_94;
  int v_93;
  int v_92;
  int v_91;
  int v_90;
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
  ck_1 = self->v_88;
  ck_2 = self->v_89;
  if (ck_1) {
    ck_2_1 = ck_2;
    if (ck_2_1) {
      v_22 = !(c_lac);
      v_23 = (turn_on_lac&&v_22);
      if (v_23) {
        v_25 = true;
        v_24_1 = false;
        v_24_2 = false;
      } else {
        v_25 = self->pnr;
        v_24_1 = true;
        v_24_2 = true;
      };
      v_21 = (turn_on_lac&&c_lac);
      if (v_21) {
        r_St_5_Off = true;
        s_St_5_Off_1 = true;
        s_St_5_Off_2 = false;
      } else {
        r_St_5_Off = v_25;
        s_St_5_Off_1 = v_24_1;
        s_St_5_Off_2 = v_24_2;
      };
      v_94 = r_St_5_Off;
      v_90 = s_St_5_Off_1;
      v_91 = s_St_5_Off_2;
      if (v_24_1) {
        v_24_2_1 = v_24_2;
      } else {
        v_24_2_0 = v_24_2;
      };
      if (s_St_5_Off_1) {
        s_St_5_Off_2_1 = s_St_5_Off_2;
      } else {
        s_St_5_Off_2_0 = s_St_5_Off_2;
      };
    } else {
      v_18 = !(c_lac);
      if (v_18) {
        v_20 = true;
        v_19_1 = false;
        v_19_2 = false;
      } else {
        v_20 = self->pnr;
        v_19_1 = true;
        v_19_2 = false;
      };
      v = !(turn_on_lac);
      if (v) {
        r_St_5_On = true;
      } else {
        r_St_5_On = v_20;
      };
      v_94 = r_St_5_On;
      if (v) {
        s_St_5_On_1 = true;
      } else {
        s_St_5_On_1 = v_19_1;
      };
      v_90 = s_St_5_On_1;
      if (v) {
        s_St_5_On_2 = true;
      } else {
        s_St_5_On_2 = v_19_2;
      };
      v_91 = s_St_5_On_2;
      if (v_19_1) {
        v_19_2_1 = v_19_2;
      } else {
        v_19_2_0 = v_19_2;
      };
      if (s_St_5_On_1) {
        s_St_5_On_2_1 = s_St_5_On_2;
      } else {
        s_St_5_On_2_0 = s_St_5_On_2;
      };
    };
    s_1 = v_90;
    s_2 = v_91;
    r = v_94;
  } else {
    ck_2_0 = ck_2;
    if (ck_2_0) {
      v_95 = true;
      v_92 = true;
      v_93 = true;
    } else {
      if (c_lac) {
        r_St_5_Wait = true;
      } else {
        r_St_5_Wait = self->pnr;
      };
      v_95 = r_St_5_Wait;
      if (c_lac) {
        s_St_5_Wait_1 = true;
      } else {
        s_St_5_Wait_1 = false;
      };
      v_92 = s_St_5_Wait_1;
      if (c_lac) {
        s_St_5_Wait_2 = false;
      } else {
        s_St_5_Wait_2 = false;
      };
      v_93 = s_St_5_Wait_2;
    };
    s_1 = v_92;
    s_2 = v_93;
    r = v_95;
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
      v_80 = working_state_lac_St_5_Off;
      v_86 = nr_St_5_Off;
      v_82 = ns_St_5_Off_1;
      v_83 = ns_St_5_Off_2;
      if (ns_St_5_Off_1) {
        ns_St_5_Off_2_1 = ns_St_5_Off_2;
      } else {
        ns_St_5_Off_2_0 = ns_St_5_Off_2;
      };
    } else {
      working_state_lac_St_5_On = 1;
      v_80 = working_state_lac_St_5_On;
      nr_St_5_On = false;
      v_86 = nr_St_5_On;
      ns_St_5_On_1 = true;
      v_82 = ns_St_5_On_1;
      ns_St_5_On_2 = false;
      v_83 = ns_St_5_On_2;
      if (ns_St_5_On_1) {
        ns_St_5_On_2_1 = ns_St_5_On_2;
      } else {
        ns_St_5_On_2_0 = ns_St_5_On_2;
      };
    };
    _out->working_state_lac = v_80;
    ns_1 = v_82;
    ns_2 = v_83;
    nr = v_86;
  } else {
    ck_6_2_0 = ck_6_2;
    if (ck_6_2_0) {
      v_81 = 0;
      v_87 = true;
      v_84 = true;
      v_85 = true;
    } else {
      working_state_lac_St_5_Wait = 2;
      v_81 = working_state_lac_St_5_Wait;
      nr_St_5_Wait = false;
      v_87 = nr_St_5_Wait;
      ns_St_5_Wait_1 = false;
      v_84 = ns_St_5_Wait_1;
      ns_St_5_Wait_2 = false;
      v_85 = ns_St_5_Wait_2;
    };
    _out->working_state_lac = v_81;
    ns_1 = v_84;
    ns_2 = v_85;
    nr = v_87;
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
  self->v_88 = ns_1;
  self->v_89 = ns_2;;
}

void Project__tv_reset(Project__tv_mem* self) {
  self->pnr = false;
  self->ck_1 = false;
}

void Project__tv_step(int turn_on_tv, Project__tv_out* _out,
                      Project__tv_mem* self) {
  
  int nr_St_6_Off;
  int ns_St_6_Off_1;
  int is_tv_on_St_6_Off;
  int nr_St_6_On;
  int ns_St_6_On_1;
  int is_tv_on_St_6_On;
  int ck_7_1;
  int v;
  int r_St_6_Off;
  int s_St_6_Off_1;
  int r_St_6_On;
  int s_St_6_On_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_tv) {
      r_St_6_Off = true;
    } else {
      r_St_6_Off = self->pnr;
    };
    r = r_St_6_Off;
    if (turn_on_tv) {
      s_St_6_Off_1 = false;
    } else {
      s_St_6_Off_1 = true;
    };
    s_1 = s_St_6_Off_1;
  } else {
    v = !(turn_on_tv);
    if (v) {
      r_St_6_On = true;
      s_St_6_On_1 = true;
    } else {
      r_St_6_On = self->pnr;
      s_St_6_On_1 = false;
    };
    r = r_St_6_On;
    s_1 = s_St_6_On_1;
  };
  ck_7_1 = s_1;
  if (ck_7_1) {
    is_tv_on_St_6_Off = false;
    _out->is_tv_on = is_tv_on_St_6_Off;
    nr_St_6_Off = false;
    nr = nr_St_6_Off;
    ns_St_6_Off_1 = true;
    ns_1 = ns_St_6_Off_1;
  } else {
    is_tv_on_St_6_On = true;
    nr_St_6_On = false;
    ns_St_6_On_1 = false;
    _out->is_tv_on = is_tv_on_St_6_On;
    nr = nr_St_6_On;
    ns_1 = ns_St_6_On_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__washing_machine_reset(Project__washing_machine_mem* self) {
  self->pnr = false;
  self->ck_1 = false;
}

void Project__washing_machine_step(int turn_on_wm,
                                   Project__washing_machine_out* _out,
                                   Project__washing_machine_mem* self) {
  
  int nr_St_7_Off;
  int ns_St_7_Off_1;
  int is_working_wm_St_7_Off;
  int nr_St_7_Washing;
  int ns_St_7_Washing_1;
  int is_working_wm_St_7_Washing;
  int ck_8_1;
  int v;
  int r_St_7_Off;
  int s_St_7_Off_1;
  int r_St_7_Washing;
  int s_St_7_Washing_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (turn_on_wm) {
      r_St_7_Off = true;
    } else {
      r_St_7_Off = self->pnr;
    };
    r = r_St_7_Off;
    if (turn_on_wm) {
      s_St_7_Off_1 = false;
    } else {
      s_St_7_Off_1 = true;
    };
    s_1 = s_St_7_Off_1;
  } else {
    v = !(turn_on_wm);
    if (v) {
      r_St_7_Washing = true;
      s_St_7_Washing_1 = true;
    } else {
      r_St_7_Washing = self->pnr;
      s_St_7_Washing_1 = false;
    };
    r = r_St_7_Washing;
    s_1 = s_St_7_Washing_1;
  };
  ck_8_1 = s_1;
  if (ck_8_1) {
    is_working_wm_St_7_Off = false;
    _out->is_working_wm = is_working_wm_St_7_Off;
    nr_St_7_Off = false;
    nr = nr_St_7_Off;
    ns_St_7_Off_1 = true;
    ns_1 = ns_St_7_Off_1;
  } else {
    is_working_wm_St_7_Washing = true;
    nr_St_7_Washing = false;
    ns_St_7_Washing_1 = false;
    _out->is_working_wm = is_working_wm_St_7_Washing;
    nr = nr_St_7_Washing;
    ns_1 = ns_St_7_Washing_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__window_reset(Project__window_mem* self) {
  self->pnr = false;
  self->ck_1 = false;
}

void Project__window_step(int do_open, Project__window_out* _out,
                          Project__window_mem* self) {
  
  int nr_St_8_Closed;
  int ns_St_8_Closed_1;
  int is_w_opened_St_8_Closed;
  int nr_St_8_Opened;
  int ns_St_8_Opened_1;
  int is_w_opened_St_8_Opened;
  int ck_9_1;
  int v;
  int r_St_8_Closed;
  int s_St_8_Closed_1;
  int r_St_8_Opened;
  int s_St_8_Opened_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (do_open) {
      r_St_8_Closed = true;
    } else {
      r_St_8_Closed = self->pnr;
    };
    r = r_St_8_Closed;
    if (do_open) {
      s_St_8_Closed_1 = false;
    } else {
      s_St_8_Closed_1 = true;
    };
    s_1 = s_St_8_Closed_1;
  } else {
    v = !(do_open);
    if (v) {
      r_St_8_Opened = true;
      s_St_8_Opened_1 = true;
    } else {
      r_St_8_Opened = self->pnr;
      s_St_8_Opened_1 = false;
    };
    r = r_St_8_Opened;
    s_1 = s_St_8_Opened_1;
  };
  ck_9_1 = s_1;
  if (ck_9_1) {
    is_w_opened_St_8_Closed = false;
    _out->is_w_opened = is_w_opened_St_8_Closed;
    nr_St_8_Closed = false;
    nr = nr_St_8_Closed;
    ns_St_8_Closed_1 = true;
    ns_1 = ns_St_8_Closed_1;
  } else {
    is_w_opened_St_8_Opened = true;
    nr_St_8_Opened = false;
    ns_St_8_Opened_1 = false;
    _out->is_w_opened = is_w_opened_St_8_Opened;
    nr = nr_St_8_Opened;
    ns_1 = ns_St_8_Opened_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Project__supervisor_reset(Project__supervisor_mem* self) {
  self->pnr = false;
  self->v_104 = true;
  self->v_105 = true;
  self->pnr_1 = false;
  self->v_120 = true;
  self->v_121 = true;
  self->pnr_2 = false;
  self->ck_23_1 = false;
  self->pnr_3 = false;
  self->ck_21_1 = false;
  self->pnr_4 = false;
  self->ck_19_1 = false;
  self->pnr_5 = false;
  self->ck_17_1 = false;
  self->pnr_6 = false;
  self->ck_15_1 = false;
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
  
  int v_103;
  int v_102;
  int v_101;
  int v_100;
  int v_99;
  int v_98;
  int v_97;
  int v_96;
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
  int working_state_lac_1_St_9_Wait;
  int nr_St_9_On;
  int ns_St_9_On_2;
  int ns_St_9_On_1;
  int working_state_lac_1_St_9_On;
  int nr_St_9_Off;
  int ns_St_9_Off_2;
  int ns_St_9_Off_1;
  int working_state_lac_1_St_9_Off;
  int ck_28_2;
  int ck_28_1;
  int v_62_2_0;
  int v_62_2_1;
  int v_63;
  int v_62_2;
  int v_62_1;
  int v_61;
  int v_60;
  int v_59;
  int v_57_2_0;
  int v_57_2_1;
  int v_58;
  int v_57_2;
  int v_57_1;
  int v_56;
  int v_55;
  int v_111;
  int v_110;
  int v_109;
  int v_108;
  int v_107;
  int v_106;
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
  int v_119;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  int v_114;
  int v_113;
  int v_112;
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
  int working_state_rac_1_St_10_Wait;
  int nr_1_St_10_On;
  int ns_1_St_10_On_2;
  int ns_1_St_10_On_1;
  int working_state_rac_1_St_10_On;
  int nr_1_St_10_Off;
  int ns_1_St_10_Off_2;
  int ns_1_St_10_Off_1;
  int working_state_rac_1_St_10_Off;
  int ck_26_2;
  int ck_26_1;
  int v_53_2_0;
  int v_53_2_1;
  int v_54;
  int v_53_2;
  int v_53_1;
  int v_52;
  int v_51;
  int v_50;
  int v_48_2_0;
  int v_48_2_1;
  int v_49;
  int v_48_2;
  int v_48_1;
  int v_47;
  int v_46;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
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
  int nr_2_St_11_Closed;
  int ns_2_St_11_Closed_1;
  int is_w_opened_1_St_11_Closed;
  int nr_2_St_11_Opened;
  int ns_2_St_11_Opened_1;
  int is_w_opened_1_St_11_Opened;
  int ck_24_1;
  int v_45;
  int r_2_St_11_Closed;
  int s_2_St_11_Closed_1;
  int r_2_St_11_Opened;
  int s_2_St_11_Opened_1;
  int nr_3_St_12_Off;
  int ns_3_St_12_Off_1;
  int is_working_wm_1_St_12_Off;
  int nr_3_St_12_Washing;
  int ns_3_St_12_Washing_1;
  int is_working_wm_1_St_12_Washing;
  int ck_22_1;
  int v_44;
  int r_3_St_12_Off;
  int s_3_St_12_Off_1;
  int r_3_St_12_Washing;
  int s_3_St_12_Washing_1;
  int nr_4_St_13_Off;
  int ns_4_St_13_Off_1;
  int is_tv_on_1_St_13_Off;
  int nr_4_St_13_On;
  int ns_4_St_13_On_1;
  int is_tv_on_1_St_13_On;
  int ck_20_1;
  int v_43;
  int r_4_St_13_Off;
  int s_4_St_13_Off_1;
  int r_4_St_13_On;
  int s_4_St_13_On_1;
  int nr_5_St_14_Off;
  int ns_5_St_14_Off_1;
  int is_on_l_1_St_14_Off;
  int nr_5_St_14_On;
  int ns_5_St_14_On_1;
  int is_on_l_1_St_14_On;
  int ck_18_1;
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int r_5_St_14_Off;
  int s_5_St_14_Off_1;
  int r_5_St_14_On;
  int s_5_St_14_On_1;
  int nr_6_St_15_Off;
  int ns_6_St_15_Off_1;
  int is_on_rl_1_St_15_Off;
  int nr_6_St_15_On;
  int ns_6_St_15_On_1;
  int is_on_rl_1_St_15_On;
  int ck_16_1;
  int v_35;
  int r_6_St_15_Off;
  int s_6_St_15_Off_1;
  int r_6_St_15_On;
  int s_6_St_15_On_1;
  int nr_7_St_16_On;
  int ns_7_St_16_On_1;
  int is_on_l1_2_St_16_On;
  int nr_7_St_16_Off;
  int ns_7_St_16_Off_1;
  int is_on_l1_2_St_16_Off;
  int ck_14_1;
  int v_34;
  int v_33;
  int v_32;
  int v_31;
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
  int v_30;
  int v_29;
  int v_28;
  int v_27;
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
  int v_26;
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
  int turn_on_lac_1;
  int c_lac_1;
  int working_state_lac_1;
  int turn_on_rac_1;
  int c_rac_1;
  int working_state_rac_1;
  int do_open_1;
  int is_w_opened_1;
  int turn_on_wm_1;
  int is_working_wm_1;
  int turn_on_tv_1;
  int is_tv_on_1;
  int turn_on_l_1;
  int c_l_1;
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
  int rule1;
  int v;
  int c_lac;
  int c_rac;
  int c_l;
  int c_l4;
  int c_l3;
  int c_l2;
  int c_l1;
  turn_on_lac_1 = turn_on_lac;
  ck_27_1 = self->v_104;
  ck_27_2 = self->v_105;
  turn_on_rac_1 = turn_on_rac;
  ck_25_1 = self->v_120;
  ck_25_2 = self->v_121;
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
                                                    self->pnr_2, self->v_121,
                                                    self->v_120, self->pnr_1,
                                                    self->v_105, self->v_104,
                                                    self->pnr, true, true,
                                                    true, true, true, true,
                                                    true,
                                                    &Supervisor_controller__supervisor_controller_out_st);
  c_lac = Supervisor_controller__supervisor_controller_out_st.supervisor_c_lac;
  c_rac = Supervisor_controller__supervisor_controller_out_st.supervisor_c_rac;
  c_l = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l;
  c_l4 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l4;
  c_l3 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l3;
  c_l2 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l2;
  c_l1 = Supervisor_controller__supervisor_controller_out_st.supervisor_c_l1;
  c_lac_1 = c_lac;
  c_rac_1 = c_rac;
  c_l_1 = c_l;
  c_l1_2 = c_l3;
  c_l2_2 = c_l4;
  c_l1_1 = c_l1;
  c_l2_1 = c_l2;
  if (ck_27_1) {
    ck_27_2_1 = ck_27_2;
    if (ck_27_2_1) {
      v_60 = !(c_lac_1);
      v_61 = (turn_on_lac_1&&v_60);
      if (v_61) {
        v_63 = true;
        v_62_1 = false;
        v_62_2 = false;
      } else {
        v_63 = self->pnr;
        v_62_1 = true;
        v_62_2 = true;
      };
      v_59 = (turn_on_lac_1&&c_lac_1);
      if (v_59) {
        r_St_9_Off = true;
        s_St_9_Off_1 = true;
        s_St_9_Off_2 = false;
      } else {
        r_St_9_Off = v_63;
        s_St_9_Off_1 = v_62_1;
        s_St_9_Off_2 = v_62_2;
      };
      v_110 = r_St_9_Off;
      v_106 = s_St_9_Off_1;
      v_107 = s_St_9_Off_2;
      if (v_62_1) {
        v_62_2_1 = v_62_2;
      } else {
        v_62_2_0 = v_62_2;
      };
      if (s_St_9_Off_1) {
        s_St_9_Off_2_1 = s_St_9_Off_2;
      } else {
        s_St_9_Off_2_0 = s_St_9_Off_2;
      };
    } else {
      v_56 = !(c_lac_1);
      if (v_56) {
        v_58 = true;
        v_57_1 = false;
        v_57_2 = false;
      } else {
        v_58 = self->pnr;
        v_57_1 = true;
        v_57_2 = false;
      };
      v_55 = !(turn_on_lac_1);
      if (v_55) {
        r_St_9_On = true;
      } else {
        r_St_9_On = v_58;
      };
      v_110 = r_St_9_On;
      if (v_55) {
        s_St_9_On_1 = true;
      } else {
        s_St_9_On_1 = v_57_1;
      };
      v_106 = s_St_9_On_1;
      if (v_55) {
        s_St_9_On_2 = true;
      } else {
        s_St_9_On_2 = v_57_2;
      };
      v_107 = s_St_9_On_2;
      if (v_57_1) {
        v_57_2_1 = v_57_2;
      } else {
        v_57_2_0 = v_57_2;
      };
      if (s_St_9_On_1) {
        s_St_9_On_2_1 = s_St_9_On_2;
      } else {
        s_St_9_On_2_0 = s_St_9_On_2;
      };
    };
    s_1_3 = v_106;
    s_2_2 = v_107;
    r = v_110;
  } else {
    ck_27_2_0 = ck_27_2;
    if (ck_27_2_0) {
      v_111 = true;
      v_108 = true;
      v_109 = true;
    } else {
      if (c_lac_1) {
        r_St_9_Wait = true;
      } else {
        r_St_9_Wait = self->pnr;
      };
      v_111 = r_St_9_Wait;
      if (c_lac_1) {
        s_St_9_Wait_1 = true;
      } else {
        s_St_9_Wait_1 = false;
      };
      v_108 = s_St_9_Wait_1;
      if (c_lac_1) {
        s_St_9_Wait_2 = false;
      } else {
        s_St_9_Wait_2 = false;
      };
      v_109 = s_St_9_Wait_2;
    };
    s_1_3 = v_108;
    s_2_2 = v_109;
    r = v_111;
  };
  ck_28_1 = s_1_3;
  ck_28_2 = s_2_2;
  if (ck_28_1) {
    ck_28_2_1 = ck_28_2;
    if (ck_28_2_1) {
      working_state_lac_1_St_9_Off = 0;
      nr_St_9_Off = false;
      ns_St_9_Off_1 = true;
      ns_St_9_Off_2 = true;
      v_96 = working_state_lac_1_St_9_Off;
      v_102 = nr_St_9_Off;
      v_98 = ns_St_9_Off_1;
      v_99 = ns_St_9_Off_2;
      if (ns_St_9_Off_1) {
        ns_St_9_Off_2_1 = ns_St_9_Off_2;
      } else {
        ns_St_9_Off_2_0 = ns_St_9_Off_2;
      };
    } else {
      working_state_lac_1_St_9_On = 1;
      v_96 = working_state_lac_1_St_9_On;
      nr_St_9_On = false;
      v_102 = nr_St_9_On;
      ns_St_9_On_1 = true;
      v_98 = ns_St_9_On_1;
      ns_St_9_On_2 = false;
      v_99 = ns_St_9_On_2;
      if (ns_St_9_On_1) {
        ns_St_9_On_2_1 = ns_St_9_On_2;
      } else {
        ns_St_9_On_2_0 = ns_St_9_On_2;
      };
    };
    working_state_lac_1 = v_96;
    ns_1_3 = v_98;
    ns_2_2 = v_99;
    nr = v_102;
  } else {
    ck_28_2_0 = ck_28_2;
    if (ck_28_2_0) {
      v_97 = 0;
      v_103 = true;
      v_100 = true;
      v_101 = true;
    } else {
      working_state_lac_1_St_9_Wait = 2;
      v_97 = working_state_lac_1_St_9_Wait;
      nr_St_9_Wait = false;
      v_103 = nr_St_9_Wait;
      ns_St_9_Wait_1 = false;
      v_100 = ns_St_9_Wait_1;
      ns_St_9_Wait_2 = false;
      v_101 = ns_St_9_Wait_2;
    };
    working_state_lac_1 = v_97;
    ns_1_3 = v_100;
    ns_2_2 = v_101;
    nr = v_103;
  };
  _out->working_state_lac = working_state_lac_1;
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
      v_51 = !(c_rac_1);
      v_52 = (turn_on_rac_1&&v_51);
      if (v_52) {
        v_54 = true;
        v_53_1 = false;
        v_53_2 = false;
      } else {
        v_54 = self->pnr_1;
        v_53_1 = true;
        v_53_2 = true;
      };
      v_50 = (turn_on_rac_1&&c_rac_1);
      if (v_50) {
        r_1_St_10_Off = true;
        s_1_St_10_Off_1 = true;
        s_1_St_10_Off_2 = false;
      } else {
        r_1_St_10_Off = v_54;
        s_1_St_10_Off_1 = v_53_1;
        s_1_St_10_Off_2 = v_53_2;
      };
      v_126 = r_1_St_10_Off;
      v_122 = s_1_St_10_Off_1;
      v_123 = s_1_St_10_Off_2;
      if (v_53_1) {
        v_53_2_1 = v_53_2;
      } else {
        v_53_2_0 = v_53_2;
      };
      if (s_1_St_10_Off_1) {
        s_1_St_10_Off_2_1 = s_1_St_10_Off_2;
      } else {
        s_1_St_10_Off_2_0 = s_1_St_10_Off_2;
      };
    } else {
      v_47 = !(c_rac_1);
      if (v_47) {
        v_49 = true;
        v_48_1 = false;
        v_48_2 = false;
      } else {
        v_49 = self->pnr_1;
        v_48_1 = true;
        v_48_2 = false;
      };
      v_46 = !(turn_on_rac_1);
      if (v_46) {
        r_1_St_10_On = true;
      } else {
        r_1_St_10_On = v_49;
      };
      v_126 = r_1_St_10_On;
      if (v_46) {
        s_1_St_10_On_1 = true;
      } else {
        s_1_St_10_On_1 = v_48_1;
      };
      v_122 = s_1_St_10_On_1;
      if (v_46) {
        s_1_St_10_On_2 = true;
      } else {
        s_1_St_10_On_2 = v_48_2;
      };
      v_123 = s_1_St_10_On_2;
      if (v_48_1) {
        v_48_2_1 = v_48_2;
      } else {
        v_48_2_0 = v_48_2;
      };
      if (s_1_St_10_On_1) {
        s_1_St_10_On_2_1 = s_1_St_10_On_2;
      } else {
        s_1_St_10_On_2_0 = s_1_St_10_On_2;
      };
    };
    s_1_1 = v_122;
    s_1_2 = v_123;
    r_1 = v_126;
  } else {
    ck_25_2_0 = ck_25_2;
    if (ck_25_2_0) {
      v_127 = true;
      v_124 = true;
      v_125 = true;
    } else {
      if (c_rac_1) {
        r_1_St_10_Wait = true;
      } else {
        r_1_St_10_Wait = self->pnr_1;
      };
      v_127 = r_1_St_10_Wait;
      if (c_rac_1) {
        s_1_St_10_Wait_1 = true;
      } else {
        s_1_St_10_Wait_1 = false;
      };
      v_124 = s_1_St_10_Wait_1;
      if (c_rac_1) {
        s_1_St_10_Wait_2 = false;
      } else {
        s_1_St_10_Wait_2 = false;
      };
      v_125 = s_1_St_10_Wait_2;
    };
    s_1_1 = v_124;
    s_1_2 = v_125;
    r_1 = v_127;
  };
  ck_26_1 = s_1_1;
  ck_26_2 = s_1_2;
  if (ck_26_1) {
    ck_26_2_1 = ck_26_2;
    if (ck_26_2_1) {
      working_state_rac_1_St_10_Off = 0;
      nr_1_St_10_Off = false;
      ns_1_St_10_Off_1 = true;
      ns_1_St_10_Off_2 = true;
      v_112 = working_state_rac_1_St_10_Off;
      v_118 = nr_1_St_10_Off;
      v_114 = ns_1_St_10_Off_1;
      v_115 = ns_1_St_10_Off_2;
      if (ns_1_St_10_Off_1) {
        ns_1_St_10_Off_2_1 = ns_1_St_10_Off_2;
      } else {
        ns_1_St_10_Off_2_0 = ns_1_St_10_Off_2;
      };
    } else {
      working_state_rac_1_St_10_On = 1;
      v_112 = working_state_rac_1_St_10_On;
      nr_1_St_10_On = false;
      v_118 = nr_1_St_10_On;
      ns_1_St_10_On_1 = true;
      v_114 = ns_1_St_10_On_1;
      ns_1_St_10_On_2 = false;
      v_115 = ns_1_St_10_On_2;
      if (ns_1_St_10_On_1) {
        ns_1_St_10_On_2_1 = ns_1_St_10_On_2;
      } else {
        ns_1_St_10_On_2_0 = ns_1_St_10_On_2;
      };
    };
    working_state_rac_1 = v_112;
    ns_1_1 = v_114;
    ns_1_2 = v_115;
    nr_1 = v_118;
  } else {
    ck_26_2_0 = ck_26_2;
    if (ck_26_2_0) {
      v_113 = 0;
      v_119 = true;
      v_116 = true;
      v_117 = true;
    } else {
      working_state_rac_1_St_10_Wait = 2;
      v_113 = working_state_rac_1_St_10_Wait;
      nr_1_St_10_Wait = false;
      v_119 = nr_1_St_10_Wait;
      ns_1_St_10_Wait_1 = false;
      v_116 = ns_1_St_10_Wait_1;
      ns_1_St_10_Wait_2 = false;
      v_117 = ns_1_St_10_Wait_2;
    };
    working_state_rac_1 = v_113;
    ns_1_1 = v_116;
    ns_1_2 = v_117;
    nr_1 = v_119;
  };
  _out->working_state_rac = working_state_rac_1;
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
    } else {
      r_2_St_11_Closed = self->pnr_2;
    };
    r_2 = r_2_St_11_Closed;
    if (do_open_1) {
      s_2_St_11_Closed_1 = false;
    } else {
      s_2_St_11_Closed_1 = true;
    };
    s_2_1 = s_2_St_11_Closed_1;
  } else {
    v_45 = !(do_open_1);
    if (v_45) {
      r_2_St_11_Opened = true;
      s_2_St_11_Opened_1 = true;
    } else {
      r_2_St_11_Opened = self->pnr_2;
      s_2_St_11_Opened_1 = false;
    };
    r_2 = r_2_St_11_Opened;
    s_2_1 = s_2_St_11_Opened_1;
  };
  ck_24_1 = s_2_1;
  if (ck_24_1) {
    is_w_opened_1_St_11_Closed = false;
    is_w_opened_1 = is_w_opened_1_St_11_Closed;
    nr_2_St_11_Closed = false;
    nr_2 = nr_2_St_11_Closed;
    ns_2_St_11_Closed_1 = true;
    ns_2_1 = ns_2_St_11_Closed_1;
  } else {
    is_w_opened_1_St_11_Opened = true;
    nr_2_St_11_Opened = false;
    ns_2_St_11_Opened_1 = false;
    is_w_opened_1 = is_w_opened_1_St_11_Opened;
    nr_2 = nr_2_St_11_Opened;
    ns_2_1 = ns_2_St_11_Opened_1;
  };
  _out->is_w_opened = is_w_opened_1;
  if (self->ck_21_1) {
    if (turn_on_wm_1) {
      r_3_St_12_Off = true;
    } else {
      r_3_St_12_Off = self->pnr_3;
    };
    r_3 = r_3_St_12_Off;
    if (turn_on_wm_1) {
      s_3_St_12_Off_1 = false;
    } else {
      s_3_St_12_Off_1 = true;
    };
    s_3_1 = s_3_St_12_Off_1;
  } else {
    v_44 = !(turn_on_wm_1);
    if (v_44) {
      r_3_St_12_Washing = true;
      s_3_St_12_Washing_1 = true;
    } else {
      r_3_St_12_Washing = self->pnr_3;
      s_3_St_12_Washing_1 = false;
    };
    r_3 = r_3_St_12_Washing;
    s_3_1 = s_3_St_12_Washing_1;
  };
  ck_22_1 = s_3_1;
  if (ck_22_1) {
    is_working_wm_1_St_12_Off = false;
    is_working_wm_1 = is_working_wm_1_St_12_Off;
    nr_3_St_12_Off = false;
    nr_3 = nr_3_St_12_Off;
    ns_3_St_12_Off_1 = true;
    ns_3_1 = ns_3_St_12_Off_1;
  } else {
    is_working_wm_1_St_12_Washing = true;
    nr_3_St_12_Washing = false;
    ns_3_St_12_Washing_1 = false;
    is_working_wm_1 = is_working_wm_1_St_12_Washing;
    nr_3 = nr_3_St_12_Washing;
    ns_3_1 = ns_3_St_12_Washing_1;
  };
  _out->is_working_wm = is_working_wm_1;
  if (self->ck_19_1) {
    if (turn_on_tv_1) {
      r_4_St_13_Off = true;
    } else {
      r_4_St_13_Off = self->pnr_4;
    };
    r_4 = r_4_St_13_Off;
    if (turn_on_tv_1) {
      s_4_St_13_Off_1 = false;
    } else {
      s_4_St_13_Off_1 = true;
    };
    s_4_1 = s_4_St_13_Off_1;
  } else {
    v_43 = !(turn_on_tv_1);
    if (v_43) {
      r_4_St_13_On = true;
      s_4_St_13_On_1 = true;
    } else {
      r_4_St_13_On = self->pnr_4;
      s_4_St_13_On_1 = false;
    };
    r_4 = r_4_St_13_On;
    s_4_1 = s_4_St_13_On_1;
  };
  ck_20_1 = s_4_1;
  if (ck_20_1) {
    is_tv_on_1_St_13_Off = false;
    is_tv_on_1 = is_tv_on_1_St_13_Off;
    nr_4_St_13_Off = false;
    nr_4 = nr_4_St_13_Off;
    ns_4_St_13_Off_1 = true;
    ns_4_1 = ns_4_St_13_Off_1;
  } else {
    is_tv_on_1_St_13_On = true;
    nr_4_St_13_On = false;
    ns_4_St_13_On_1 = false;
    is_tv_on_1 = is_tv_on_1_St_13_On;
    nr_4 = nr_4_St_13_On;
    ns_4_1 = ns_4_St_13_On_1;
  };
  _out->is_tv_on = is_tv_on_1;
  if (self->ck_17_1) {
    v_36 = (turn_on_l_1&&c_l_1);
    v_37 = (v_36||c_l_1);
    if (v_37) {
      r_5_St_14_Off = true;
    } else {
      r_5_St_14_Off = self->pnr_5;
    };
    r_5 = r_5_St_14_Off;
    if (v_37) {
      s_5_St_14_Off_1 = false;
    } else {
      s_5_St_14_Off_1 = true;
    };
    s_5_1 = s_5_St_14_Off_1;
  } else {
    v_41 = !(c_l_1);
    v_39 = !(c_l_1);
    v_38 = !(turn_on_l_1);
    v_40 = (v_38&&v_39);
    v_42 = (v_40||v_41);
    if (v_42) {
      r_5_St_14_On = true;
      s_5_St_14_On_1 = true;
    } else {
      r_5_St_14_On = self->pnr_5;
      s_5_St_14_On_1 = false;
    };
    r_5 = r_5_St_14_On;
    s_5_1 = s_5_St_14_On_1;
  };
  ck_18_1 = s_5_1;
  if (ck_18_1) {
    is_on_l_1_St_14_Off = false;
    is_on_l_1 = is_on_l_1_St_14_Off;
    nr_5_St_14_Off = false;
    nr_5 = nr_5_St_14_Off;
    ns_5_St_14_Off_1 = true;
    ns_5_1 = ns_5_St_14_Off_1;
  } else {
    is_on_l_1_St_14_On = true;
    nr_5_St_14_On = false;
    ns_5_St_14_On_1 = false;
    is_on_l_1 = is_on_l_1_St_14_On;
    nr_5 = nr_5_St_14_On;
    ns_5_1 = ns_5_St_14_On_1;
  };
  _out->is_on_l = is_on_l_1;
  if (self->ck_15_1) {
    if (turn_on_rl_1) {
      r_6_St_15_Off = true;
    } else {
      r_6_St_15_Off = self->pnr_6;
    };
    r_6 = r_6_St_15_Off;
    if (turn_on_rl_1) {
      s_6_St_15_Off_1 = false;
    } else {
      s_6_St_15_Off_1 = true;
    };
    s_6_1 = s_6_St_15_Off_1;
  } else {
    v_35 = !(turn_on_rl_1);
    if (v_35) {
      r_6_St_15_On = true;
      s_6_St_15_On_1 = true;
    } else {
      r_6_St_15_On = self->pnr_6;
      s_6_St_15_On_1 = false;
    };
    r_6 = r_6_St_15_On;
    s_6_1 = s_6_St_15_On_1;
  };
  ck_16_1 = s_6_1;
  if (ck_16_1) {
    is_on_rl_1_St_15_Off = false;
    is_on_rl_1 = is_on_rl_1_St_15_Off;
    nr_6_St_15_Off = false;
    nr_6 = nr_6_St_15_Off;
    ns_6_St_15_Off_1 = true;
    ns_6_1 = ns_6_St_15_Off_1;
  } else {
    is_on_rl_1_St_15_On = true;
    nr_6_St_15_On = false;
    ns_6_St_15_On_1 = false;
    is_on_rl_1 = is_on_rl_1_St_15_On;
    nr_6 = nr_6_St_15_On;
    ns_6_1 = ns_6_St_15_On_1;
  };
  _out->is_on_rl = is_on_rl_1;
  if (self->ck_13_1) {
    v_33 = (turn_on_l1_2&&c_l1_2);
    v_34 = (v_33||c_l2_2);
    if (v_34) {
      r_7_St_16_Off = true;
      s_7_St_16_Off_1 = false;
    } else {
      r_7_St_16_Off = self->pnr_7;
      s_7_St_16_Off_1 = true;
    };
    r_7 = r_7_St_16_Off;
    s_7_1 = s_7_St_16_Off_1;
  } else {
    v_31 = (turn_on_l1_2&&c_l1_2);
    v_32 = (v_31||c_l2_2);
    if (v_32) {
      r_7_St_16_On = true;
    } else {
      r_7_St_16_On = self->pnr_7;
    };
    r_7 = r_7_St_16_On;
    if (v_32) {
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
  if (self->ck_11_1) {
    v_29 = (turn_on_l1_1&&c_l1_1);
    v_30 = (v_29||c_l2_1);
    if (v_30) {
      r_8_St_17_Off = true;
      s_8_St_17_Off_1 = false;
    } else {
      r_8_St_17_Off = self->pnr_8;
      s_8_St_17_Off_1 = true;
    };
    r_8 = r_8_St_17_Off;
    s_8_1 = s_8_St_17_Off_1;
  } else {
    v_27 = (turn_on_l1_1&&c_l1_1);
    v_28 = (v_27||c_l2_1);
    if (v_28) {
      r_8_St_17_On = true;
    } else {
      r_8_St_17_On = self->pnr_8;
    };
    r_8 = r_8_St_17_On;
    if (v_28) {
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
  v = (_out->is_on_l1&&_out->is_on_l2);
  rule1 = !(v);
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
    v_26 = !(presence_1);
    if (v_26) {
      r_9_St_18_Occupied = true;
    } else {
      r_9_St_18_Occupied = self->pnr_9;
    };
    r_9 = r_9_St_18_Occupied;
    if (v_26) {
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
  self->pnr = nr;
  self->v_104 = ns_1_3;
  self->v_105 = ns_2_2;
  self->pnr_1 = nr_1;
  self->v_120 = ns_1_1;
  self->v_121 = ns_1_2;
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


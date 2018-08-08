/* --- Generated the 8/8/2018 at 10:52 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c supervisor_controller.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "supervisor_controller.h"

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
  Supervisor_controller__supervisor_controller_supervisor_c2_lac_out* _out) {
  
  int v_152;
  int v_151;
  int v_150;
  int v_149;
  int v_148;
  int v_147;
  int v_146;
  int v_145;
  int v_144;
  int v_143;
  int v_142;
  int v_141;
  int v_140;
  int v_139;
  int v_138;
  int v_137;
  int v_136;
  int v_135;
  int v_134;
  int v_133;
  int v_132;
  int v_131;
  int v_130;
  int v_129;
  int v_128;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  int v_114;
  int v_113;
  int v_112;
  int v_111;
  int v_110;
  int v_109;
  int v_108;
  int v_107;
  int v_106;
  int v_105;
  int v_104;
  int v_103;
  int v_102;
  int v_101;
  int v_100;
  int v_99;
  int v_98;
  int v_97;
  int v_96;
  int v_95;
  int v_94;
  int v_93;
  int v_92;
  int v_91;
  int v_90;
  int v_89;
  int v_88;
  int v_87;
  int v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_82;
  int v_81;
  int v_80;
  int v_79;
  int v_78;
  int v_77;
  int v_76;
  int v_75;
  int v_74;
  int v_73;
  int v_72;
  int v_71;
  int v_70;
  int v_69;
  int v_68;
  int v_67;
  int v_66;
  int v_65;
  int v_64;
  int v_63;
  int v_62;
  int v_61;
  int v_60;
  int v_59;
  int v_58;
  int v_57;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_47;
  int v_46;
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  int v_34;
  int v_33;
  int v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
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
  int sub_40;
  int sub_41;
  int sub_42;
  int sub_43;
  int sub_44;
  int sub_45;
  int sub_46;
  int sub_47;
  int sub_48;
  int sub_49;
  int sub_50;
  int sub_51;
  int sub_52;
  int sub_53;
  int sub_54;
  int sub_55;
  int sub_56;
  int sub_57;
  int sub_58;
  int sub_59;
  int sub_60;
  int sub_61;
  int sub_62;
  int sub_63;
  int sub_64;
  int sub_65;
  int sub_66;
  int sub_67;
  int sub_68;
  int sub_69;
  int sub_70;
  int sub_71;
  int sub_72;
  int sub_73;
  int sub_74;
  int sub_75;
  int sub_76;
  int sub_77;
  int sub_78;
  int sub_79;
  int sub_80;
  int sub_81;
  int sub_82;
  int sub_83;
  int sub_84;
  int sub_85;
  int sub_86;
  int sub_87;
  int sub_88;
  int sub_89;
  int sub_90;
  int sub_91;
  int sub_92;
  int sub_93;
  int sub_94;
  int sub_95;
  int sub_96;
  int sub_97;
  int sub_98;
  int sub_99;
  int sub_100;
  int sub_101;
  int sub_102;
  int sub_103;
  int sub_104;
  int sub_105;
  int sub_106;
  int sub_107;
  int sub_108;
  int sub_109;
  int sub_110;
  int sub_111;
  int sub_112;
  int sub_113;
  int sub_114;
  int sub_115;
  int sub_116;
  int sub_117;
  int sub_118;
  int sub_119;
  int sub_120;
  int sub_121;
  int sub_122;
  int sub_123;
  int sub_124;
  int sub_125;
  int sub_126;
  int sub_127;
  int sub_128;
  int sub_129;
  int sub_130;
  int sub_131;
  int sub_132;
  int sub_133;
  int sub_134;
  int sub_135;
  int sub_136;
  int sub_137;
  int sub_138;
  int sub_139;
  int sub_140;
  int sub_141;
  int sub_142;
  int sub_143;
  int sub_144;
  int sub_145;
  int sub_146;
  int sub_147;
  int sub_148;
  int sub_149;
  int sub_150;
  int sub_151;
  int sub_152;
  int sub_153;
  int sub_154;
  int sub_155;
  int sub_156;
  int sub_157;
  int sub_158;
  int sub_159;
  int sub_160;
  int sub_161;
  int sub_162;
  int sub_163;
  int sub_164;
  int sub_165;
  int sub_166;
  int sub_167;
  int sub_168;
  int sub_169;
  int sub_170;
  int sub_171;
  int sub_172;
  int sub_173;
  int sub_174;
  int sub_175;
  int sub_176;
  int sub_177;
  int sub_178;
  int sub_179;
  int sub_180;
  int sub_181;
  int sub_182;
  int sub_183;
  v_137 = (supervisor_presence&&false);
  v_136 = !(supervisor_presence);
  sub_24 = (v_136&&false);
  if (supervisor_ck_1) {
    sub_23 = v_137;
  } else {
    sub_23 = sub_24;
  };
  sub_22 = sub_23;
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  if (supervisor_turn_on_rac) {
    sub_28 = sub_23;
  } else {
    sub_28 = false;
  };
  if (supervisor_v_127) {
    v_133 = sub_22;
  } else {
    v_133 = sub_28;
  };
  if (supervisor_c_rac) {
    sub_27 = sub_28;
  } else {
    sub_27 = v_133;
  };
  if (supervisor_turn_on_rac) {
    v_132 = false;
  } else {
    v_132 = sub_23;
  };
  if (supervisor_v_127) {
    sub_29 = v_132;
  } else {
    sub_29 = sub_22;
  };
  if (supervisor_v_128) {
    v_134 = sub_29;
  } else {
    v_134 = sub_27;
  };
  if (supervisor_v_127) {
    v_131 = sub_28;
  } else {
    v_131 = sub_22;
  };
  if (supervisor_c_rac) {
    sub_30 = sub_28;
    sub_31 = sub_29;
  } else {
    sub_30 = v_131;
    sub_31 = sub_22;
  };
  if (supervisor_v_128) {
    v_135 = sub_31;
  } else {
    v_135 = sub_30;
  };
  if (supervisor_c2_rac) {
    sub_26 = v_134;
  } else {
    sub_26 = v_135;
  };
  if (supervisor_c_lac) {
    sub_25 = sub_26;
  } else {
    sub_25 = sub_20;
  };
  if (supervisor_v_111) {
    v_144 = sub_25;
  } else {
    v_144 = sub_19;
  };
  if (supervisor_turn_on_lac) {
    v_145 = v_144;
  } else {
    v_145 = sub_19;
  };
  v_128 = !(supervisor_presence);
  v_129 = (v_128||false);
  sub_35 = (supervisor_presence||false);
  if (supervisor_ck_1) {
    sub_34 = v_129;
  } else {
    sub_34 = sub_35;
  };
  if (supervisor_turn_on_rac) {
    sub_33 = sub_23;
  } else {
    sub_33 = sub_34;
  };
  if (supervisor_v_127) {
    v_130 = sub_22;
  } else {
    v_130 = sub_33;
  };
  if (supervisor_c_rac) {
    sub_32 = sub_33;
  } else {
    sub_32 = v_130;
  };
  if (supervisor_turn_on_rac) {
    sub_37 = sub_34;
  } else {
    sub_37 = sub_23;
  };
  if (supervisor_v_127) {
    sub_36 = sub_37;
  } else {
    sub_36 = sub_22;
  };
  if (supervisor_c_rac) {
    v_139 = sub_36;
  } else {
    v_139 = sub_22;
  };
  if (supervisor_v_128) {
    v_138 = sub_36;
  } else {
    v_138 = sub_32;
  };
  if (supervisor_v_127) {
    v_127 = sub_33;
  } else {
    v_127 = sub_22;
  };
  if (supervisor_c_rac) {
    sub_38 = sub_33;
  } else {
    sub_38 = v_127;
  };
  if (supervisor_v_128) {
    v_140 = v_139;
  } else {
    v_140 = sub_38;
  };
  if (supervisor_c2_rac) {
    v_141 = v_138;
  } else {
    v_141 = v_140;
  };
  if (supervisor_c_lac) {
    v_142 = sub_26;
  } else {
    v_142 = v_141;
  };
  if (supervisor_v_111) {
    v_143 = v_142;
  } else {
    v_143 = sub_25;
  };
  if (supervisor_turn_on_lac) {
    sub_18 = sub_19;
  } else {
    sub_18 = v_143;
  };
  if (supervisor_v_112) {
    sub_17 = v_145;
  } else {
    sub_17 = sub_18;
  };
  if (supervisor_v_128) {
    v_120 = sub_31;
  } else {
    v_120 = sub_38;
  };
  if (supervisor_c_rac) {
    v_118 = sub_29;
  } else {
    v_118 = sub_36;
  };
  if (supervisor_v_128) {
    v_119 = v_118;
  } else {
    v_119 = sub_27;
  };
  if (supervisor_c2_rac) {
    v_121 = v_119;
  } else {
    v_121 = v_120;
  };
  if (supervisor_c_lac) {
    v_122 = sub_26;
  } else {
    v_122 = v_121;
  };
  if (supervisor_v_128) {
    v_117 = sub_31;
    v_116 = sub_31;
  } else {
    v_117 = sub_21;
    v_116 = sub_27;
  };
  if (supervisor_c2_rac) {
    sub_42 = v_116;
  } else {
    sub_42 = v_117;
  };
  if (supervisor_c_lac) {
    v_124 = false;
  } else {
    v_124 = sub_42;
  };
  sub_41 = sub_42;
  if (supervisor_v_111) {
    v_125 = v_124;
  } else {
    v_125 = sub_41;
  };
  if (supervisor_turn_on_lac) {
    v_126 = v_125;
  } else {
    v_126 = sub_41;
  };
  if (supervisor_c_lac) {
    sub_43 = sub_26;
  } else {
    sub_43 = sub_42;
  };
  if (supervisor_v_111) {
    v_123 = v_122;
  } else {
    v_123 = sub_43;
  };
  if (supervisor_turn_on_lac) {
    sub_40 = sub_41;
  } else {
    sub_40 = v_123;
  };
  if (supervisor_v_112) {
    sub_39 = v_126;
  } else {
    sub_39 = sub_40;
  };
  if (supervisor_turn_on_wm) {
    v_146 = sub_39;
    sub_16 = sub_17;
  } else {
    v_146 = sub_17;
    sub_16 = sub_39;
  };
  if (supervisor_ck_20_1) {
    sub_15 = v_146;
  } else {
    sub_15 = sub_16;
  };
  sub_47 = sub_26;
  if (supervisor_c_lac) {
    sub_49 = false;
  } else {
    sub_49 = sub_26;
  };
  if (supervisor_v_111) {
    v_114 = sub_49;
  } else {
    v_114 = sub_47;
  };
  if (supervisor_turn_on_lac) {
    v_115 = v_114;
  } else {
    v_115 = sub_47;
  };
  if (supervisor_turn_on_rac) {
    sub_52 = sub_34;
  } else {
    sub_52 = false;
  };
  sub_53 = sub_34;
  if (supervisor_v_127) {
    v_110 = sub_53;
  } else {
    v_110 = sub_52;
  };
  if (supervisor_c_rac) {
    sub_51 = sub_52;
  } else {
    sub_51 = v_110;
  };
  if (supervisor_turn_on_rac) {
    v_109 = false;
  } else {
    v_109 = sub_34;
  };
  if (supervisor_v_127) {
    sub_54 = v_109;
  } else {
    sub_54 = sub_53;
  };
  if (supervisor_v_128) {
    v_111 = sub_54;
  } else {
    v_111 = sub_51;
  };
  if (supervisor_v_127) {
    v_108 = sub_52;
  } else {
    v_108 = sub_53;
  };
  if (supervisor_c_rac) {
    sub_55 = sub_52;
    sub_56 = sub_54;
  } else {
    sub_55 = v_108;
    sub_56 = sub_53;
  };
  if (supervisor_v_128) {
    v_112 = sub_56;
  } else {
    v_112 = sub_55;
  };
  if (supervisor_c2_rac) {
    sub_50 = v_111;
  } else {
    sub_50 = v_112;
  };
  if (supervisor_c_lac) {
    v_113 = false;
  } else {
    v_113 = sub_50;
  };
  if (supervisor_v_111) {
    sub_48 = v_113;
  } else {
    sub_48 = sub_49;
  };
  if (supervisor_turn_on_lac) {
    sub_46 = sub_47;
  } else {
    sub_46 = sub_48;
  };
  if (supervisor_v_112) {
    sub_45 = v_115;
  } else {
    sub_45 = sub_46;
  };
  sub_44 = sub_45;
  if (supervisor_do_open) {
    v_147 = sub_44;
    sub_14 = sub_15;
  } else {
    v_147 = sub_15;
    sub_14 = sub_44;
  };
  if (supervisor_ck_22_1) {
    sub_13 = v_147;
  } else {
    sub_13 = sub_14;
  };
  sub_67 = false;
  sub_66 = sub_67;
  sub_65 = sub_66;
  sub_64 = sub_65;
  sub_63 = sub_64;
  if (supervisor_turn_on_rac) {
    sub_71 = sub_67;
  } else {
    sub_71 = false;
  };
  if (supervisor_v_127) {
    v_95 = sub_66;
  } else {
    v_95 = sub_71;
  };
  if (supervisor_c_rac) {
    sub_70 = sub_71;
  } else {
    sub_70 = v_95;
  };
  if (supervisor_turn_on_rac) {
    v_94 = false;
  } else {
    v_94 = sub_67;
  };
  if (supervisor_v_127) {
    sub_72 = v_94;
  } else {
    sub_72 = sub_66;
  };
  if (supervisor_v_128) {
    v_96 = sub_72;
  } else {
    v_96 = sub_70;
  };
  if (supervisor_v_127) {
    v_93 = sub_71;
  } else {
    v_93 = sub_66;
  };
  if (supervisor_c_rac) {
    sub_73 = sub_71;
    sub_74 = sub_72;
  } else {
    sub_73 = v_93;
    sub_74 = sub_66;
  };
  if (supervisor_v_128) {
    v_97 = sub_74;
  } else {
    v_97 = sub_73;
  };
  if (supervisor_c2_rac) {
    sub_69 = v_96;
  } else {
    sub_69 = v_97;
  };
  if (supervisor_c_lac) {
    sub_68 = sub_69;
  } else {
    sub_68 = sub_64;
  };
  if (supervisor_v_111) {
    v_104 = sub_68;
  } else {
    v_104 = sub_63;
  };
  if (supervisor_turn_on_lac) {
    v_105 = v_104;
  } else {
    v_105 = sub_63;
  };
  sub_77 = true;
  if (supervisor_turn_on_rac) {
    sub_76 = sub_67;
  } else {
    sub_76 = sub_77;
  };
  if (supervisor_v_127) {
    v_92 = sub_66;
  } else {
    v_92 = sub_76;
  };
  if (supervisor_c_rac) {
    sub_75 = sub_76;
  } else {
    sub_75 = v_92;
  };
  if (supervisor_turn_on_rac) {
    sub_79 = sub_77;
  } else {
    sub_79 = sub_67;
  };
  if (supervisor_v_127) {
    sub_78 = sub_79;
  } else {
    sub_78 = sub_66;
  };
  if (supervisor_c_rac) {
    v_99 = sub_78;
  } else {
    v_99 = sub_66;
  };
  if (supervisor_v_128) {
    v_98 = sub_78;
  } else {
    v_98 = sub_75;
  };
  if (supervisor_v_127) {
    v_91 = sub_76;
  } else {
    v_91 = sub_66;
  };
  if (supervisor_c_rac) {
    sub_80 = sub_76;
  } else {
    sub_80 = v_91;
  };
  if (supervisor_v_128) {
    v_100 = v_99;
  } else {
    v_100 = sub_80;
  };
  if (supervisor_c2_rac) {
    v_101 = v_98;
  } else {
    v_101 = v_100;
  };
  if (supervisor_c_lac) {
    v_102 = sub_69;
  } else {
    v_102 = v_101;
  };
  if (supervisor_v_111) {
    v_103 = v_102;
  } else {
    v_103 = sub_68;
  };
  if (supervisor_turn_on_lac) {
    sub_62 = sub_63;
  } else {
    sub_62 = v_103;
  };
  if (supervisor_v_112) {
    sub_61 = v_105;
  } else {
    sub_61 = sub_62;
  };
  if (supervisor_v_128) {
    v_84 = sub_74;
  } else {
    v_84 = sub_80;
  };
  if (supervisor_c_rac) {
    v_82 = sub_72;
  } else {
    v_82 = sub_78;
  };
  if (supervisor_v_128) {
    v_83 = v_82;
  } else {
    v_83 = sub_70;
  };
  if (supervisor_c2_rac) {
    v_85 = v_83;
  } else {
    v_85 = v_84;
  };
  if (supervisor_c_lac) {
    v_86 = sub_69;
  } else {
    v_86 = v_85;
  };
  if (supervisor_v_128) {
    v_81 = sub_74;
    v_80 = sub_74;
  } else {
    v_81 = sub_65;
    v_80 = sub_70;
  };
  if (supervisor_c2_rac) {
    sub_84 = v_80;
  } else {
    sub_84 = v_81;
  };
  if (supervisor_c_lac) {
    v_88 = false;
  } else {
    v_88 = sub_84;
  };
  sub_83 = sub_84;
  if (supervisor_v_111) {
    v_89 = v_88;
  } else {
    v_89 = sub_83;
  };
  if (supervisor_turn_on_lac) {
    v_90 = v_89;
  } else {
    v_90 = sub_83;
  };
  if (supervisor_c_lac) {
    sub_85 = sub_69;
  } else {
    sub_85 = sub_84;
  };
  if (supervisor_v_111) {
    v_87 = v_86;
  } else {
    v_87 = sub_85;
  };
  if (supervisor_turn_on_lac) {
    sub_82 = sub_83;
  } else {
    sub_82 = v_87;
  };
  if (supervisor_v_112) {
    sub_81 = v_90;
  } else {
    sub_81 = sub_82;
  };
  if (supervisor_turn_on_wm) {
    v_106 = sub_81;
    sub_60 = sub_61;
  } else {
    v_106 = sub_61;
    sub_60 = sub_81;
  };
  if (supervisor_ck_20_1) {
    sub_59 = v_106;
  } else {
    sub_59 = sub_60;
  };
  sub_89 = sub_69;
  if (supervisor_c_lac) {
    sub_91 = false;
  } else {
    sub_91 = sub_69;
  };
  if (supervisor_v_111) {
    v_78 = sub_91;
  } else {
    v_78 = sub_89;
  };
  if (supervisor_turn_on_lac) {
    v_79 = v_78;
  } else {
    v_79 = sub_89;
  };
  if (supervisor_turn_on_rac) {
    sub_94 = sub_77;
  } else {
    sub_94 = false;
  };
  sub_95 = sub_77;
  if (supervisor_v_127) {
    v_74 = sub_95;
  } else {
    v_74 = sub_94;
  };
  if (supervisor_c_rac) {
    sub_93 = sub_94;
  } else {
    sub_93 = v_74;
  };
  if (supervisor_turn_on_rac) {
    v_73 = false;
  } else {
    v_73 = sub_77;
  };
  if (supervisor_v_127) {
    sub_96 = v_73;
  } else {
    sub_96 = sub_95;
  };
  if (supervisor_v_128) {
    v_75 = sub_96;
  } else {
    v_75 = sub_93;
  };
  if (supervisor_v_127) {
    v_72 = sub_94;
  } else {
    v_72 = sub_95;
  };
  if (supervisor_c_rac) {
    sub_97 = sub_94;
    sub_98 = sub_96;
  } else {
    sub_97 = v_72;
    sub_98 = sub_95;
  };
  if (supervisor_v_128) {
    v_76 = sub_98;
  } else {
    v_76 = sub_97;
  };
  if (supervisor_c2_rac) {
    sub_92 = v_75;
  } else {
    sub_92 = v_76;
  };
  if (supervisor_c_lac) {
    v_77 = false;
  } else {
    v_77 = sub_92;
  };
  if (supervisor_v_111) {
    sub_90 = v_77;
  } else {
    sub_90 = sub_91;
  };
  if (supervisor_turn_on_lac) {
    sub_88 = sub_89;
  } else {
    sub_88 = sub_90;
  };
  if (supervisor_v_112) {
    sub_87 = v_79;
  } else {
    sub_87 = sub_88;
  };
  sub_86 = sub_87;
  if (supervisor_do_open) {
    v_107 = sub_86;
    sub_58 = sub_59;
  } else {
    v_107 = sub_59;
    sub_58 = sub_86;
  };
  if (supervisor_ck_22_1) {
    sub_57 = v_107;
  } else {
    sub_57 = sub_58;
  };
  if (supervisor_turn_on_tv) {
    v_148 = sub_57;
    sub_12 = sub_13;
  } else {
    v_148 = sub_13;
    sub_12 = sub_57;
  };
  if (supervisor_ck_18_1) {
    sub_11 = v_148;
  } else {
    sub_11 = sub_12;
  };
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  if (supervisor_c_l) {
    v_70 = sub_11;
  } else {
    v_70 = false;
  };
  if (supervisor_turn_on_l) {
    v_71 = v_70;
  } else {
    v_71 = false;
  };
  if (supervisor_c_l5) {
    sub_100 = v_71;
  } else {
    sub_100 = sub_9;
  };
  if (supervisor_c_l) {
    v_69 = false;
  } else {
    v_69 = sub_11;
  };
  if (supervisor_turn_on_l) {
    sub_101 = v_69;
  } else {
    sub_101 = sub_10;
  };
  if (supervisor_ck_16_1) {
    sub_99 = sub_101;
  } else {
    sub_99 = sub_100;
  };
  if (supervisor_turn_on_rl) {
    v_149 = sub_99;
    sub_7 = sub_8;
  } else {
    v_149 = sub_8;
    sub_7 = sub_99;
  };
  if (supervisor_ck_14_1) {
    sub_6 = v_149;
  } else {
    sub_6 = sub_7;
  };
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_109 = sub_57;
  sub_108 = sub_109;
  sub_107 = sub_108;
  sub_106 = sub_107;
  if (supervisor_c_l) {
    v_65 = sub_109;
  } else {
    v_65 = false;
  };
  if (supervisor_turn_on_l) {
    v_66 = v_65;
  } else {
    v_66 = false;
  };
  if (supervisor_c_l5) {
    sub_111 = v_66;
  } else {
    sub_111 = sub_107;
  };
  if (supervisor_c_l) {
    v_64 = false;
  } else {
    v_64 = sub_109;
  };
  if (supervisor_turn_on_l) {
    sub_112 = v_64;
  } else {
    sub_112 = sub_108;
  };
  if (supervisor_ck_16_1) {
    sub_110 = sub_112;
  } else {
    sub_110 = sub_111;
  };
  if (supervisor_turn_on_rl) {
    v_67 = sub_110;
    sub_105 = sub_106;
  } else {
    v_67 = sub_106;
    sub_105 = sub_110;
  };
  if (supervisor_ck_14_1) {
    sub_104 = v_67;
  } else {
    sub_104 = sub_105;
  };
  if (supervisor_ck_12_1) {
    sub_103 = false;
    v_63 = sub_104;
  } else {
    sub_103 = sub_104;
    v_63 = false;
  };
  if (supervisor_c_l4) {
    sub_113 = v_63;
  } else {
    sub_113 = sub_103;
  };
  if (supervisor_c_l3) {
    v_68 = sub_103;
  } else {
    v_68 = sub_113;
  };
  if (supervisor_turn_on_l2) {
    sub_102 = v_68;
  } else {
    sub_102 = sub_113;
  };
  if (supervisor_ck_10_1) {
    sub_2 = sub_102;
    v_62 = sub_3;
  } else {
    sub_2 = sub_3;
    v_62 = sub_102;
  };
  if (supervisor_c_l2) {
    sub_114 = v_62;
  } else {
    sub_114 = sub_2;
  };
  if (supervisor_c_l1) {
    v_150 = sub_2;
  } else {
    v_150 = sub_114;
  };
  if (supervisor_turn_on_l1) {
    sub_1 = v_150;
  } else {
    sub_1 = sub_114;
  };
  sub_134 = sub_53;
  sub_133 = sub_134;
  if (supervisor_c_lac) {
    v_54 = sub_50;
  } else {
    v_54 = sub_133;
  };
  sub_132 = sub_133;
  if (supervisor_v_127) {
    v_49 = sub_53;
  } else {
    v_49 = sub_37;
  };
  if (supervisor_c_rac) {
    sub_136 = sub_37;
  } else {
    sub_136 = v_49;
  };
  if (supervisor_v_127) {
    sub_137 = sub_33;
  } else {
    sub_137 = sub_53;
  };
  if (supervisor_c_rac) {
    v_51 = sub_137;
  } else {
    v_51 = sub_53;
  };
  if (supervisor_v_128) {
    v_50 = sub_137;
  } else {
    v_50 = sub_136;
  };
  if (supervisor_v_127) {
    v_48 = sub_37;
  } else {
    v_48 = sub_53;
  };
  if (supervisor_c_rac) {
    sub_138 = sub_37;
  } else {
    sub_138 = v_48;
  };
  if (supervisor_v_128) {
    v_52 = v_51;
  } else {
    v_52 = sub_138;
  };
  if (supervisor_c2_rac) {
    v_53 = v_50;
  } else {
    v_53 = v_52;
  };
  if (supervisor_c_lac) {
    sub_135 = sub_50;
  } else {
    sub_135 = v_53;
  };
  if (supervisor_v_111) {
    v_56 = sub_135;
  } else {
    v_56 = sub_132;
  };
  if (supervisor_turn_on_lac) {
    v_57 = v_56;
  } else {
    v_57 = sub_132;
  };
  if (supervisor_v_111) {
    v_55 = v_54;
  } else {
    v_55 = sub_135;
  };
  if (supervisor_turn_on_lac) {
    sub_131 = sub_132;
  } else {
    sub_131 = v_55;
  };
  if (supervisor_v_112) {
    sub_130 = v_57;
  } else {
    sub_130 = sub_131;
  };
  if (supervisor_v_128) {
    v_43 = sub_56;
  } else {
    v_43 = sub_138;
  };
  if (supervisor_c_rac) {
    v_41 = sub_54;
  } else {
    v_41 = sub_137;
  };
  if (supervisor_v_128) {
    v_42 = v_41;
  } else {
    v_42 = sub_51;
  };
  if (supervisor_c2_rac) {
    v_44 = v_42;
  } else {
    v_44 = v_43;
  };
  if (supervisor_c_lac) {
    v_45 = false;
  } else {
    v_45 = v_44;
  };
  if (supervisor_v_128) {
    v_38 = sub_56;
    v_37 = sub_56;
  } else {
    v_38 = sub_134;
    v_37 = sub_51;
  };
  if (supervisor_c2_rac) {
    sub_142 = v_37;
  } else {
    sub_142 = v_38;
  };
  if (supervisor_c_lac) {
    v_39 = sub_26;
  } else {
    v_39 = sub_142;
  };
  if (supervisor_v_111) {
    v_40 = v_39;
  } else {
    v_40 = sub_43;
  };
  sub_141 = sub_142;
  if (supervisor_v_111) {
    v_46 = v_45;
  } else {
    v_46 = sub_141;
  };
  if (supervisor_turn_on_lac) {
    v_47 = v_46;
    sub_140 = sub_141;
  } else {
    v_47 = sub_141;
    sub_140 = v_40;
  };
  if (supervisor_v_112) {
    sub_139 = v_47;
  } else {
    sub_139 = sub_140;
  };
  if (supervisor_turn_on_wm) {
    v_58 = sub_139;
    sub_129 = sub_130;
  } else {
    v_58 = sub_130;
    sub_129 = sub_139;
  };
  if (supervisor_ck_20_1) {
    sub_128 = v_58;
  } else {
    sub_128 = sub_129;
  };
  sub_146 = sub_50;
  if (supervisor_v_111) {
    v_35 = sub_49;
  } else {
    v_35 = sub_146;
  };
  if (supervisor_turn_on_lac) {
    v_36 = v_35;
    sub_145 = sub_146;
  } else {
    v_36 = sub_146;
    sub_145 = sub_48;
  };
  if (supervisor_v_112) {
    sub_144 = v_36;
  } else {
    sub_144 = sub_145;
  };
  sub_143 = sub_144;
  if (supervisor_do_open) {
    v_59 = sub_143;
    sub_127 = sub_128;
  } else {
    v_59 = sub_128;
    sub_127 = sub_143;
  };
  if (supervisor_ck_22_1) {
    sub_126 = v_59;
  } else {
    sub_126 = sub_127;
  };
  sub_155 = sub_95;
  sub_154 = sub_155;
  if (supervisor_c_lac) {
    v_29 = sub_92;
  } else {
    v_29 = sub_154;
  };
  sub_153 = sub_154;
  if (supervisor_v_127) {
    v_24 = sub_95;
  } else {
    v_24 = sub_79;
  };
  if (supervisor_c_rac) {
    sub_157 = sub_79;
  } else {
    sub_157 = v_24;
  };
  if (supervisor_v_127) {
    sub_158 = sub_76;
  } else {
    sub_158 = sub_95;
  };
  if (supervisor_c_rac) {
    v_26 = sub_158;
  } else {
    v_26 = sub_95;
  };
  if (supervisor_v_128) {
    v_25 = sub_158;
  } else {
    v_25 = sub_157;
  };
  if (supervisor_v_127) {
    v_23 = sub_79;
  } else {
    v_23 = sub_95;
  };
  if (supervisor_c_rac) {
    sub_159 = sub_79;
  } else {
    sub_159 = v_23;
  };
  if (supervisor_v_128) {
    v_27 = v_26;
  } else {
    v_27 = sub_159;
  };
  if (supervisor_c2_rac) {
    v_28 = v_25;
  } else {
    v_28 = v_27;
  };
  if (supervisor_c_lac) {
    sub_156 = sub_92;
  } else {
    sub_156 = v_28;
  };
  if (supervisor_v_111) {
    v_31 = sub_156;
  } else {
    v_31 = sub_153;
  };
  if (supervisor_turn_on_lac) {
    v_32 = v_31;
  } else {
    v_32 = sub_153;
  };
  if (supervisor_v_111) {
    v_30 = v_29;
  } else {
    v_30 = sub_156;
  };
  if (supervisor_turn_on_lac) {
    sub_152 = sub_153;
  } else {
    sub_152 = v_30;
  };
  if (supervisor_v_112) {
    sub_151 = v_32;
  } else {
    sub_151 = sub_152;
  };
  if (supervisor_v_128) {
    v_18 = sub_98;
  } else {
    v_18 = sub_159;
  };
  if (supervisor_c_rac) {
    v_16 = sub_96;
  } else {
    v_16 = sub_158;
  };
  if (supervisor_v_128) {
    v_17 = v_16;
  } else {
    v_17 = sub_93;
  };
  if (supervisor_c2_rac) {
    v_19 = v_17;
  } else {
    v_19 = v_18;
  };
  if (supervisor_c_lac) {
    v_20 = false;
  } else {
    v_20 = v_19;
  };
  if (supervisor_v_128) {
    v_13 = sub_98;
    v_12 = sub_98;
  } else {
    v_13 = sub_155;
    v_12 = sub_93;
  };
  if (supervisor_c2_rac) {
    sub_163 = v_12;
  } else {
    sub_163 = v_13;
  };
  if (supervisor_c_lac) {
    v_14 = sub_69;
  } else {
    v_14 = sub_163;
  };
  if (supervisor_v_111) {
    v_15 = v_14;
  } else {
    v_15 = sub_85;
  };
  sub_162 = sub_163;
  if (supervisor_v_111) {
    v_21 = v_20;
  } else {
    v_21 = sub_162;
  };
  if (supervisor_turn_on_lac) {
    v_22 = v_21;
    sub_161 = sub_162;
  } else {
    v_22 = sub_162;
    sub_161 = v_15;
  };
  if (supervisor_v_112) {
    sub_160 = v_22;
  } else {
    sub_160 = sub_161;
  };
  if (supervisor_turn_on_wm) {
    v_33 = sub_160;
    sub_150 = sub_151;
  } else {
    v_33 = sub_151;
    sub_150 = sub_160;
  };
  if (supervisor_ck_20_1) {
    sub_149 = v_33;
  } else {
    sub_149 = sub_150;
  };
  sub_167 = sub_92;
  if (supervisor_v_111) {
    v_10 = sub_91;
  } else {
    v_10 = sub_167;
  };
  if (supervisor_turn_on_lac) {
    v_11 = v_10;
    sub_166 = sub_167;
  } else {
    v_11 = sub_167;
    sub_166 = sub_90;
  };
  if (supervisor_v_112) {
    sub_165 = v_11;
  } else {
    sub_165 = sub_166;
  };
  sub_164 = sub_165;
  if (supervisor_do_open) {
    v_34 = sub_164;
    sub_148 = sub_149;
  } else {
    v_34 = sub_149;
    sub_148 = sub_164;
  };
  if (supervisor_ck_22_1) {
    sub_147 = v_34;
  } else {
    sub_147 = sub_148;
  };
  if (supervisor_turn_on_tv) {
    v_60 = sub_147;
    sub_125 = sub_126;
  } else {
    v_60 = sub_126;
    sub_125 = sub_147;
  };
  if (supervisor_ck_18_1) {
    sub_124 = v_60;
  } else {
    sub_124 = sub_125;
  };
  sub_123 = sub_124;
  sub_122 = sub_123;
  sub_121 = sub_122;
  if (supervisor_c_l) {
    v_8 = sub_124;
  } else {
    v_8 = false;
  };
  if (supervisor_turn_on_l) {
    v_9 = v_8;
  } else {
    v_9 = false;
  };
  if (supervisor_c_l5) {
    sub_169 = v_9;
  } else {
    sub_169 = sub_122;
  };
  if (supervisor_c_l) {
    v_7 = false;
  } else {
    v_7 = sub_124;
  };
  if (supervisor_turn_on_l) {
    sub_170 = v_7;
  } else {
    sub_170 = sub_123;
  };
  if (supervisor_ck_16_1) {
    sub_168 = sub_170;
  } else {
    sub_168 = sub_169;
  };
  if (supervisor_turn_on_rl) {
    v_61 = sub_168;
    sub_120 = sub_121;
  } else {
    v_61 = sub_121;
    sub_120 = sub_168;
  };
  if (supervisor_ck_14_1) {
    sub_119 = v_61;
  } else {
    sub_119 = sub_120;
  };
  sub_118 = sub_119;
  sub_117 = sub_118;
  sub_116 = sub_117;
  sub_178 = sub_147;
  sub_177 = sub_178;
  sub_176 = sub_177;
  sub_175 = sub_176;
  if (supervisor_c_l) {
    v_3 = sub_178;
  } else {
    v_3 = false;
  };
  if (supervisor_turn_on_l) {
    v_4 = v_3;
  } else {
    v_4 = false;
  };
  if (supervisor_c_l5) {
    sub_180 = v_4;
  } else {
    sub_180 = sub_176;
  };
  if (supervisor_c_l) {
    v_2 = false;
  } else {
    v_2 = sub_178;
  };
  if (supervisor_turn_on_l) {
    sub_181 = v_2;
  } else {
    sub_181 = sub_177;
  };
  if (supervisor_ck_16_1) {
    sub_179 = sub_181;
  } else {
    sub_179 = sub_180;
  };
  if (supervisor_turn_on_rl) {
    v_5 = sub_179;
    sub_174 = sub_175;
  } else {
    v_5 = sub_175;
    sub_174 = sub_179;
  };
  if (supervisor_ck_14_1) {
    sub_173 = v_5;
  } else {
    sub_173 = sub_174;
  };
  if (supervisor_ck_12_1) {
    sub_172 = false;
    v_1 = sub_173;
  } else {
    sub_172 = sub_173;
    v_1 = false;
  };
  if (supervisor_c_l4) {
    sub_182 = v_1;
  } else {
    sub_182 = sub_172;
  };
  if (supervisor_c_l3) {
    v_6 = sub_172;
  } else {
    v_6 = sub_182;
  };
  if (supervisor_turn_on_l2) {
    sub_171 = v_6;
  } else {
    sub_171 = sub_182;
  };
  if (supervisor_ck_10_1) {
    sub_115 = sub_171;
    v = sub_116;
  } else {
    sub_115 = sub_116;
    v = sub_171;
  };
  if (supervisor_c_l2) {
    sub_183 = v;
  } else {
    sub_183 = sub_115;
  };
  if (supervisor_c_l1) {
    v_151 = sub_115;
  } else {
    v_151 = sub_183;
  };
  if (supervisor_turn_on_l1) {
    v_152 = v_151;
  } else {
    v_152 = sub_183;
  };
  if (p_supervisor_c2_lac) {
    sub_0 = v_152;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c2_lac = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c2_rac_out* _out) {
  
  int v_240;
  int v_239;
  int v_238;
  int v_237;
  int v_236;
  int v_235;
  int v_234;
  int v_233;
  int v_232;
  int v_231;
  int v_230;
  int v_229;
  int v_228;
  int v_227;
  int v_226;
  int v_225;
  int v_224;
  int v_223;
  int v_222;
  int v_221;
  int v_220;
  int v_219;
  int v_218;
  int v_217;
  int v_216;
  int v_215;
  int v_214;
  int v_213;
  int v_212;
  int v_211;
  int v_210;
  int v_209;
  int v_208;
  int v_207;
  int v_206;
  int v_205;
  int v_204;
  int v_203;
  int v_202;
  int v_201;
  int v_200;
  int v_199;
  int v_198;
  int v_197;
  int v_196;
  int v_195;
  int v_194;
  int v_193;
  int v_192;
  int v_191;
  int v_190;
  int v_189;
  int v_188;
  int v_187;
  int v_186;
  int v_185;
  int v_184;
  int v_183;
  int v_182;
  int v_181;
  int v_180;
  int v_179;
  int v_178;
  int v_177;
  int v_176;
  int v_175;
  int v_174;
  int v_173;
  int v_172;
  int v_171;
  int v_170;
  int v_169;
  int v_168;
  int v_167;
  int v_166;
  int v_165;
  int v_164;
  int v_163;
  int v_162;
  int v_161;
  int v_160;
  int v_159;
  int v_158;
  int v_157;
  int v_156;
  int v_155;
  int v_154;
  int v_153;
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
  int sub_40;
  int sub_41;
  int sub_42;
  int sub_43;
  int sub_44;
  int sub_45;
  int sub_46;
  int sub_47;
  int sub_48;
  int sub_49;
  int sub_50;
  int sub_51;
  int sub_52;
  int sub_53;
  int sub_54;
  int sub_55;
  int sub_56;
  int sub_57;
  int sub_58;
  int sub_59;
  int sub_60;
  int sub_61;
  int sub_62;
  int sub_63;
  int sub_64;
  int sub_65;
  int sub_66;
  int sub_67;
  int sub_68;
  int sub_69;
  int sub_70;
  int sub_71;
  int sub_72;
  int sub_73;
  int sub_74;
  int sub_75;
  int sub_76;
  int sub_77;
  int sub_78;
  int sub_79;
  int sub_80;
  int sub_81;
  int sub_82;
  int sub_83;
  int sub_84;
  int sub_85;
  int sub_86;
  int sub_87;
  int sub_88;
  int sub_89;
  int sub_90;
  int sub_91;
  int sub_92;
  int sub_93;
  int sub_94;
  int sub_95;
  int sub_96;
  int sub_97;
  int sub_98;
  int sub_99;
  int sub_100;
  int sub_101;
  int sub_102;
  int sub_103;
  int sub_104;
  int sub_105;
  int sub_106;
  int sub_107;
  int sub_108;
  int sub_109;
  int sub_110;
  int sub_111;
  int sub_112;
  int sub_113;
  int sub_114;
  int sub_115;
  int sub_116;
  int sub_117;
  int sub_118;
  int sub_119;
  int sub_120;
  int sub_121;
  int sub_122;
  int sub_123;
  int sub_124;
  int sub_125;
  int sub_126;
  int sub_127;
  int sub_128;
  int sub_129;
  int sub_130;
  int sub_131;
  int sub_132;
  int sub_133;
  int sub_134;
  int sub_135;
  int sub_136;
  int sub_137;
  int sub_138;
  int sub_139;
  int sub_140;
  int sub_141;
  int sub_142;
  int sub_143;
  int sub_144;
  int sub_145;
  int sub_146;
  int sub_147;
  int sub_148;
  int sub_149;
  int sub_150;
  int sub_151;
  int sub_152;
  int sub_153;
  int sub_154;
  int sub_155;
  int sub_156;
  int sub_157;
  v_231 = (supervisor_presence&&false);
  v_230 = !(supervisor_presence);
  sub_23 = (v_230&&false);
  if (supervisor_ck_1) {
    sub_22 = v_231;
  } else {
    sub_22 = sub_23;
  };
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  if (supervisor_turn_on_rac) {
    v_228 = sub_22;
  } else {
    v_228 = false;
  };
  v_226 = !(supervisor_presence);
  v_227 = (v_226||false);
  sub_29 = (supervisor_presence||false);
  if (supervisor_ck_1) {
    sub_28 = v_227;
  } else {
    sub_28 = sub_29;
  };
  if (supervisor_turn_on_rac) {
    sub_27 = sub_22;
  } else {
    sub_27 = sub_28;
  };
  if (supervisor_v_127) {
    v_229 = sub_27;
  } else {
    v_229 = sub_21;
  };
  if (supervisor_c_rac) {
    sub_26 = v_228;
  } else {
    sub_26 = v_229;
  };
  if (supervisor_turn_on_rac) {
    v_224 = false;
  } else {
    v_224 = sub_22;
  };
  if (supervisor_v_127) {
    v_225 = v_224;
  } else {
    v_225 = sub_21;
  };
  if (supervisor_c_rac) {
    sub_30 = v_225;
  } else {
    sub_30 = sub_21;
  };
  if (supervisor_v_128) {
    sub_25 = sub_30;
  } else {
    sub_25 = sub_26;
  };
  if (supervisor_c_lac) {
    sub_24 = sub_25;
  } else {
    sub_24 = sub_20;
  };
  if (supervisor_v_111) {
    v_232 = sub_24;
  } else {
    v_232 = sub_19;
  };
  if (supervisor_turn_on_lac) {
    v_233 = v_232;
    sub_18 = sub_19;
  } else {
    v_233 = sub_19;
    sub_18 = sub_24;
  };
  if (supervisor_v_112) {
    sub_17 = v_233;
  } else {
    sub_17 = sub_18;
  };
  if (supervisor_v_128) {
    sub_34 = sub_30;
  } else {
    sub_34 = sub_20;
  };
  if (supervisor_c_lac) {
    v_221 = false;
    v_220 = sub_25;
  } else {
    v_221 = sub_34;
    v_220 = sub_34;
  };
  sub_33 = sub_34;
  if (supervisor_v_111) {
    v_222 = v_221;
  } else {
    v_222 = sub_33;
  };
  if (supervisor_turn_on_lac) {
    v_223 = v_222;
    sub_32 = sub_33;
  } else {
    v_223 = sub_33;
    sub_32 = v_220;
  };
  if (supervisor_v_112) {
    sub_31 = v_223;
  } else {
    sub_31 = sub_32;
  };
  if (supervisor_turn_on_wm) {
    v_234 = sub_31;
    sub_16 = sub_17;
  } else {
    v_234 = sub_17;
    sub_16 = sub_31;
  };
  if (supervisor_ck_20_1) {
    sub_15 = v_234;
  } else {
    sub_15 = sub_16;
  };
  sub_38 = sub_25;
  if (supervisor_c_lac) {
    sub_39 = false;
  } else {
    sub_39 = sub_25;
  };
  if (supervisor_v_111) {
    v_218 = sub_39;
  } else {
    v_218 = sub_38;
  };
  if (supervisor_turn_on_lac) {
    v_219 = v_218;
    sub_37 = sub_38;
  } else {
    v_219 = sub_38;
    sub_37 = sub_39;
  };
  if (supervisor_v_112) {
    sub_36 = v_219;
  } else {
    sub_36 = sub_37;
  };
  sub_35 = sub_36;
  if (supervisor_do_open) {
    v_235 = sub_35;
    sub_14 = sub_15;
  } else {
    v_235 = sub_15;
    sub_14 = sub_35;
  };
  if (supervisor_ck_22_1) {
    sub_13 = v_235;
  } else {
    sub_13 = sub_14;
  };
  sub_49 = false;
  sub_48 = sub_49;
  sub_47 = sub_48;
  sub_46 = sub_47;
  if (supervisor_turn_on_rac) {
    v_212 = sub_49;
  } else {
    v_212 = false;
  };
  sub_54 = true;
  if (supervisor_turn_on_rac) {
    sub_53 = sub_49;
  } else {
    sub_53 = sub_54;
  };
  if (supervisor_v_127) {
    v_213 = sub_53;
  } else {
    v_213 = sub_48;
  };
  if (supervisor_c_rac) {
    sub_52 = v_212;
  } else {
    sub_52 = v_213;
  };
  if (supervisor_turn_on_rac) {
    v_210 = false;
  } else {
    v_210 = sub_49;
  };
  if (supervisor_v_127) {
    v_211 = v_210;
  } else {
    v_211 = sub_48;
  };
  if (supervisor_c_rac) {
    sub_55 = v_211;
  } else {
    sub_55 = sub_48;
  };
  if (supervisor_v_128) {
    sub_51 = sub_55;
  } else {
    sub_51 = sub_52;
  };
  if (supervisor_c_lac) {
    sub_50 = sub_51;
  } else {
    sub_50 = sub_47;
  };
  if (supervisor_v_111) {
    v_214 = sub_50;
  } else {
    v_214 = sub_46;
  };
  if (supervisor_turn_on_lac) {
    v_215 = v_214;
    sub_45 = sub_46;
  } else {
    v_215 = sub_46;
    sub_45 = sub_50;
  };
  if (supervisor_v_112) {
    sub_44 = v_215;
  } else {
    sub_44 = sub_45;
  };
  if (supervisor_v_128) {
    sub_59 = sub_55;
  } else {
    sub_59 = sub_47;
  };
  if (supervisor_c_lac) {
    v_207 = false;
    v_206 = sub_51;
  } else {
    v_207 = sub_59;
    v_206 = sub_59;
  };
  sub_58 = sub_59;
  if (supervisor_v_111) {
    v_208 = v_207;
  } else {
    v_208 = sub_58;
  };
  if (supervisor_turn_on_lac) {
    v_209 = v_208;
    sub_57 = sub_58;
  } else {
    v_209 = sub_58;
    sub_57 = v_206;
  };
  if (supervisor_v_112) {
    sub_56 = v_209;
  } else {
    sub_56 = sub_57;
  };
  if (supervisor_turn_on_wm) {
    v_216 = sub_56;
    sub_43 = sub_44;
  } else {
    v_216 = sub_44;
    sub_43 = sub_56;
  };
  if (supervisor_ck_20_1) {
    sub_42 = v_216;
  } else {
    sub_42 = sub_43;
  };
  sub_63 = sub_51;
  if (supervisor_c_lac) {
    sub_64 = false;
  } else {
    sub_64 = sub_51;
  };
  if (supervisor_v_111) {
    v_204 = sub_64;
  } else {
    v_204 = sub_63;
  };
  if (supervisor_turn_on_lac) {
    v_205 = v_204;
    sub_62 = sub_63;
  } else {
    v_205 = sub_63;
    sub_62 = sub_64;
  };
  if (supervisor_v_112) {
    sub_61 = v_205;
  } else {
    sub_61 = sub_62;
  };
  sub_60 = sub_61;
  if (supervisor_do_open) {
    v_217 = sub_60;
    sub_41 = sub_42;
  } else {
    v_217 = sub_42;
    sub_41 = sub_60;
  };
  if (supervisor_ck_22_1) {
    sub_40 = v_217;
  } else {
    sub_40 = sub_41;
  };
  if (supervisor_turn_on_tv) {
    v_236 = sub_40;
    sub_12 = sub_13;
  } else {
    v_236 = sub_13;
    sub_12 = sub_40;
  };
  if (supervisor_ck_18_1) {
    sub_11 = v_236;
  } else {
    sub_11 = sub_12;
  };
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  if (supervisor_c_l) {
    v_202 = sub_11;
  } else {
    v_202 = false;
  };
  if (supervisor_turn_on_l) {
    v_203 = v_202;
  } else {
    v_203 = false;
  };
  if (supervisor_c_l5) {
    sub_66 = v_203;
  } else {
    sub_66 = sub_9;
  };
  if (supervisor_c_l) {
    v_201 = false;
  } else {
    v_201 = sub_11;
  };
  if (supervisor_turn_on_l) {
    sub_67 = v_201;
  } else {
    sub_67 = sub_10;
  };
  if (supervisor_ck_16_1) {
    sub_65 = sub_67;
  } else {
    sub_65 = sub_66;
  };
  if (supervisor_turn_on_rl) {
    v_237 = sub_65;
    sub_7 = sub_8;
  } else {
    v_237 = sub_8;
    sub_7 = sub_65;
  };
  if (supervisor_ck_14_1) {
    sub_6 = v_237;
  } else {
    sub_6 = sub_7;
  };
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_75 = sub_40;
  sub_74 = sub_75;
  sub_73 = sub_74;
  sub_72 = sub_73;
  if (supervisor_c_l) {
    v_197 = sub_75;
  } else {
    v_197 = false;
  };
  if (supervisor_turn_on_l) {
    v_198 = v_197;
  } else {
    v_198 = false;
  };
  if (supervisor_c_l5) {
    sub_77 = v_198;
  } else {
    sub_77 = sub_73;
  };
  if (supervisor_c_l) {
    v_196 = false;
  } else {
    v_196 = sub_75;
  };
  if (supervisor_turn_on_l) {
    sub_78 = v_196;
  } else {
    sub_78 = sub_74;
  };
  if (supervisor_ck_16_1) {
    sub_76 = sub_78;
  } else {
    sub_76 = sub_77;
  };
  if (supervisor_turn_on_rl) {
    v_199 = sub_76;
    sub_71 = sub_72;
  } else {
    v_199 = sub_72;
    sub_71 = sub_76;
  };
  if (supervisor_ck_14_1) {
    sub_70 = v_199;
  } else {
    sub_70 = sub_71;
  };
  if (supervisor_ck_12_1) {
    sub_69 = false;
    v_195 = sub_70;
  } else {
    sub_69 = sub_70;
    v_195 = false;
  };
  if (supervisor_c_l4) {
    sub_79 = v_195;
  } else {
    sub_79 = sub_69;
  };
  if (supervisor_c_l3) {
    v_200 = sub_69;
  } else {
    v_200 = sub_79;
  };
  if (supervisor_turn_on_l2) {
    sub_68 = v_200;
  } else {
    sub_68 = sub_79;
  };
  if (supervisor_ck_10_1) {
    sub_2 = sub_68;
    v_194 = sub_3;
  } else {
    sub_2 = sub_3;
    v_194 = sub_68;
  };
  if (supervisor_c_l2) {
    sub_80 = v_194;
  } else {
    sub_80 = sub_2;
  };
  if (supervisor_c_l1) {
    v_238 = sub_2;
  } else {
    v_238 = sub_80;
  };
  if (supervisor_turn_on_l1) {
    sub_1 = v_238;
  } else {
    sub_1 = sub_80;
  };
  sub_100 = sub_28;
  sub_99 = sub_100;
  sub_98 = sub_99;
  if (supervisor_v_127) {
    v_186 = sub_27;
  } else {
    v_186 = sub_100;
  };
  if (supervisor_turn_on_rac) {
    v_185 = sub_28;
    sub_105 = sub_28;
  } else {
    v_185 = false;
    sub_105 = sub_22;
  };
  if (supervisor_v_127) {
    sub_104 = sub_100;
  } else {
    sub_104 = sub_105;
  };
  if (supervisor_c_rac) {
    sub_103 = v_185;
  } else {
    sub_103 = sub_104;
  };
  if (supervisor_turn_on_rac) {
    v_184 = false;
  } else {
    v_184 = sub_28;
  };
  if (supervisor_v_127) {
    sub_106 = v_184;
  } else {
    sub_106 = sub_100;
  };
  if (supervisor_c_rac) {
    v_187 = sub_106;
  } else {
    v_187 = v_186;
  };
  if (supervisor_v_128) {
    sub_102 = v_187;
  } else {
    sub_102 = sub_103;
  };
  if (supervisor_c_lac) {
    sub_101 = sub_102;
  } else {
    sub_101 = sub_99;
  };
  if (supervisor_v_111) {
    v_188 = sub_101;
  } else {
    v_188 = sub_98;
  };
  if (supervisor_turn_on_lac) {
    v_189 = v_188;
    sub_97 = sub_98;
  } else {
    v_189 = sub_98;
    sub_97 = sub_101;
  };
  if (supervisor_v_112) {
    sub_96 = v_189;
  } else {
    sub_96 = sub_97;
  };
  if (supervisor_c_rac) {
    v_179 = sub_106;
    sub_111 = sub_105;
  } else {
    v_179 = sub_100;
    sub_111 = sub_104;
  };
  if (supervisor_v_128) {
    sub_110 = v_179;
  } else {
    sub_110 = sub_111;
  };
  if (supervisor_c_lac) {
    v_181 = false;
    v_180 = sub_102;
  } else {
    v_181 = sub_110;
    v_180 = sub_110;
  };
  sub_109 = sub_110;
  if (supervisor_v_111) {
    v_182 = v_181;
  } else {
    v_182 = sub_109;
  };
  if (supervisor_turn_on_lac) {
    v_183 = v_182;
    sub_108 = sub_109;
  } else {
    v_183 = sub_109;
    sub_108 = v_180;
  };
  if (supervisor_v_112) {
    sub_107 = v_183;
  } else {
    sub_107 = sub_108;
  };
  if (supervisor_turn_on_wm) {
    v_190 = sub_107;
    sub_95 = sub_96;
  } else {
    v_190 = sub_96;
    sub_95 = sub_107;
  };
  if (supervisor_ck_20_1) {
    sub_94 = v_190;
  } else {
    sub_94 = sub_95;
  };
  sub_115 = sub_102;
  if (supervisor_c_lac) {
    sub_116 = false;
  } else {
    sub_116 = sub_102;
  };
  if (supervisor_v_111) {
    v_177 = sub_116;
  } else {
    v_177 = sub_115;
  };
  if (supervisor_turn_on_lac) {
    v_178 = v_177;
    sub_114 = sub_115;
  } else {
    v_178 = sub_115;
    sub_114 = sub_116;
  };
  if (supervisor_v_112) {
    sub_113 = v_178;
  } else {
    sub_113 = sub_114;
  };
  sub_112 = sub_113;
  if (supervisor_do_open) {
    v_191 = sub_112;
    sub_93 = sub_94;
  } else {
    v_191 = sub_94;
    sub_93 = sub_112;
  };
  if (supervisor_ck_22_1) {
    sub_92 = v_191;
  } else {
    sub_92 = sub_93;
  };
  sub_125 = sub_54;
  sub_124 = sub_125;
  sub_123 = sub_124;
  if (supervisor_v_127) {
    v_171 = sub_53;
  } else {
    v_171 = sub_125;
  };
  if (supervisor_turn_on_rac) {
    v_170 = sub_54;
    sub_130 = sub_54;
  } else {
    v_170 = false;
    sub_130 = sub_49;
  };
  if (supervisor_v_127) {
    sub_129 = sub_125;
  } else {
    sub_129 = sub_130;
  };
  if (supervisor_c_rac) {
    sub_128 = v_170;
  } else {
    sub_128 = sub_129;
  };
  if (supervisor_turn_on_rac) {
    v_169 = false;
  } else {
    v_169 = sub_54;
  };
  if (supervisor_v_127) {
    sub_131 = v_169;
  } else {
    sub_131 = sub_125;
  };
  if (supervisor_c_rac) {
    v_172 = sub_131;
  } else {
    v_172 = v_171;
  };
  if (supervisor_v_128) {
    sub_127 = v_172;
  } else {
    sub_127 = sub_128;
  };
  if (supervisor_c_lac) {
    sub_126 = sub_127;
  } else {
    sub_126 = sub_124;
  };
  if (supervisor_v_111) {
    v_173 = sub_126;
  } else {
    v_173 = sub_123;
  };
  if (supervisor_turn_on_lac) {
    v_174 = v_173;
    sub_122 = sub_123;
  } else {
    v_174 = sub_123;
    sub_122 = sub_126;
  };
  if (supervisor_v_112) {
    sub_121 = v_174;
  } else {
    sub_121 = sub_122;
  };
  if (supervisor_c_rac) {
    v_164 = sub_131;
    sub_136 = sub_130;
  } else {
    v_164 = sub_125;
    sub_136 = sub_129;
  };
  if (supervisor_v_128) {
    sub_135 = v_164;
  } else {
    sub_135 = sub_136;
  };
  if (supervisor_c_lac) {
    v_166 = false;
    v_165 = sub_127;
  } else {
    v_166 = sub_135;
    v_165 = sub_135;
  };
  sub_134 = sub_135;
  if (supervisor_v_111) {
    v_167 = v_166;
  } else {
    v_167 = sub_134;
  };
  if (supervisor_turn_on_lac) {
    v_168 = v_167;
    sub_133 = sub_134;
  } else {
    v_168 = sub_134;
    sub_133 = v_165;
  };
  if (supervisor_v_112) {
    sub_132 = v_168;
  } else {
    sub_132 = sub_133;
  };
  if (supervisor_turn_on_wm) {
    v_175 = sub_132;
    sub_120 = sub_121;
  } else {
    v_175 = sub_121;
    sub_120 = sub_132;
  };
  if (supervisor_ck_20_1) {
    sub_119 = v_175;
  } else {
    sub_119 = sub_120;
  };
  sub_140 = sub_127;
  if (supervisor_c_lac) {
    sub_141 = false;
  } else {
    sub_141 = sub_127;
  };
  if (supervisor_v_111) {
    v_162 = sub_141;
  } else {
    v_162 = sub_140;
  };
  if (supervisor_turn_on_lac) {
    v_163 = v_162;
    sub_139 = sub_140;
  } else {
    v_163 = sub_140;
    sub_139 = sub_141;
  };
  if (supervisor_v_112) {
    sub_138 = v_163;
  } else {
    sub_138 = sub_139;
  };
  sub_137 = sub_138;
  if (supervisor_do_open) {
    v_176 = sub_137;
    sub_118 = sub_119;
  } else {
    v_176 = sub_119;
    sub_118 = sub_137;
  };
  if (supervisor_ck_22_1) {
    sub_117 = v_176;
  } else {
    sub_117 = sub_118;
  };
  if (supervisor_turn_on_tv) {
    v_192 = sub_117;
    sub_91 = sub_92;
  } else {
    v_192 = sub_92;
    sub_91 = sub_117;
  };
  if (supervisor_ck_18_1) {
    sub_90 = v_192;
  } else {
    sub_90 = sub_91;
  };
  sub_89 = sub_90;
  sub_88 = sub_89;
  sub_87 = sub_88;
  if (supervisor_c_l) {
    v_160 = sub_90;
  } else {
    v_160 = false;
  };
  if (supervisor_turn_on_l) {
    v_161 = v_160;
  } else {
    v_161 = false;
  };
  if (supervisor_c_l5) {
    sub_143 = v_161;
  } else {
    sub_143 = sub_88;
  };
  if (supervisor_c_l) {
    v_159 = false;
  } else {
    v_159 = sub_90;
  };
  if (supervisor_turn_on_l) {
    sub_144 = v_159;
  } else {
    sub_144 = sub_89;
  };
  if (supervisor_ck_16_1) {
    sub_142 = sub_144;
  } else {
    sub_142 = sub_143;
  };
  if (supervisor_turn_on_rl) {
    v_193 = sub_142;
    sub_86 = sub_87;
  } else {
    v_193 = sub_87;
    sub_86 = sub_142;
  };
  if (supervisor_ck_14_1) {
    sub_85 = v_193;
  } else {
    sub_85 = sub_86;
  };
  sub_84 = sub_85;
  sub_83 = sub_84;
  sub_82 = sub_83;
  sub_152 = sub_117;
  sub_151 = sub_152;
  sub_150 = sub_151;
  sub_149 = sub_150;
  if (supervisor_c_l) {
    v_155 = sub_152;
  } else {
    v_155 = false;
  };
  if (supervisor_turn_on_l) {
    v_156 = v_155;
  } else {
    v_156 = false;
  };
  if (supervisor_c_l5) {
    sub_154 = v_156;
  } else {
    sub_154 = sub_150;
  };
  if (supervisor_c_l) {
    v_154 = false;
  } else {
    v_154 = sub_152;
  };
  if (supervisor_turn_on_l) {
    sub_155 = v_154;
  } else {
    sub_155 = sub_151;
  };
  if (supervisor_ck_16_1) {
    sub_153 = sub_155;
  } else {
    sub_153 = sub_154;
  };
  if (supervisor_turn_on_rl) {
    v_157 = sub_153;
    sub_148 = sub_149;
  } else {
    v_157 = sub_149;
    sub_148 = sub_153;
  };
  if (supervisor_ck_14_1) {
    sub_147 = v_157;
  } else {
    sub_147 = sub_148;
  };
  if (supervisor_ck_12_1) {
    sub_146 = false;
    v_153 = sub_147;
  } else {
    sub_146 = sub_147;
    v_153 = false;
  };
  if (supervisor_c_l4) {
    sub_156 = v_153;
  } else {
    sub_156 = sub_146;
  };
  if (supervisor_c_l3) {
    v_158 = sub_146;
  } else {
    v_158 = sub_156;
  };
  if (supervisor_turn_on_l2) {
    sub_145 = v_158;
  } else {
    sub_145 = sub_156;
  };
  if (supervisor_ck_10_1) {
    sub_81 = sub_145;
    v = sub_82;
  } else {
    sub_81 = sub_82;
    v = sub_145;
  };
  if (supervisor_c_l2) {
    sub_157 = v;
  } else {
    sub_157 = sub_81;
  };
  if (supervisor_c_l1) {
    v_239 = sub_81;
  } else {
    v_239 = sub_157;
  };
  if (supervisor_turn_on_l1) {
    v_240 = v_239;
  } else {
    v_240 = sub_157;
  };
  if (p_supervisor_c2_rac) {
    sub_0 = v_240;
  } else {
    sub_0 = sub_1;
  };
  _out->supervisor_c2_rac = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c_lac_out* _out) {
  
  int v_312;
  int v_311;
  int v_310;
  int v_309;
  int v_308;
  int v_307;
  int v_306;
  int v_305;
  int v_304;
  int v_303;
  int v_302;
  int v_301;
  int v_300;
  int v_299;
  int v_298;
  int v_297;
  int v_296;
  int v_295;
  int v_294;
  int v_293;
  int v_292;
  int v_291;
  int v_290;
  int v_289;
  int v_288;
  int v_287;
  int v_286;
  int v_285;
  int v_284;
  int v_283;
  int v_282;
  int v_281;
  int v_280;
  int v_279;
  int v_278;
  int v_277;
  int v_276;
  int v_275;
  int v_274;
  int v_273;
  int v_272;
  int v_271;
  int v_270;
  int v_269;
  int v_268;
  int v_267;
  int v_266;
  int v_265;
  int v_264;
  int v_263;
  int v_262;
  int v_261;
  int v_260;
  int v_259;
  int v_258;
  int v_257;
  int v_256;
  int v_255;
  int v_254;
  int v_253;
  int v_252;
  int v_251;
  int v_250;
  int v_249;
  int v_248;
  int v_247;
  int v_246;
  int v_245;
  int v_244;
  int v_243;
  int v_242;
  int v_241;
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
  int sub_40;
  int sub_41;
  int sub_42;
  int sub_43;
  int sub_44;
  int sub_45;
  int sub_46;
  int sub_47;
  int sub_48;
  int sub_49;
  int sub_50;
  int sub_51;
  int sub_52;
  int sub_53;
  int sub_54;
  int sub_55;
  int sub_56;
  int sub_57;
  int sub_58;
  int sub_59;
  int sub_60;
  int sub_61;
  int sub_62;
  int sub_63;
  int sub_64;
  int sub_65;
  int sub_66;
  int sub_67;
  int sub_68;
  int sub_69;
  int sub_70;
  int sub_71;
  int sub_72;
  int sub_73;
  int sub_74;
  int sub_75;
  int sub_76;
  int sub_77;
  int sub_78;
  int sub_79;
  int sub_80;
  int sub_81;
  int sub_82;
  int sub_83;
  int sub_84;
  int sub_85;
  int sub_86;
  int sub_87;
  int sub_88;
  int sub_89;
  int sub_90;
  int sub_91;
  int sub_92;
  int sub_93;
  int sub_94;
  int sub_95;
  int sub_96;
  int sub_97;
  int sub_98;
  int sub_99;
  int sub_100;
  int sub_101;
  int sub_102;
  int sub_103;
  int sub_104;
  int sub_105;
  int sub_106;
  int sub_107;
  int sub_108;
  int sub_109;
  int sub_110;
  int sub_111;
  int sub_112;
  int sub_113;
  int sub_114;
  int sub_115;
  int sub_116;
  int sub_117;
  int sub_118;
  int sub_119;
  int sub_120;
  int sub_121;
  int sub_122;
  int sub_123;
  int sub_124;
  int sub_125;
  int sub_126;
  int sub_127;
  v_305 = (supervisor_presence&&false);
  v_304 = !(supervisor_presence);
  sub_21 = (v_304&&false);
  if (supervisor_ck_1) {
    sub_20 = v_305;
  } else {
    sub_20 = sub_21;
  };
  sub_19 = sub_20;
  sub_18 = sub_19;
  sub_17 = sub_18;
  if (supervisor_turn_on_rac) {
    v_302 = false;
  } else {
    v_302 = sub_20;
  };
  if (supervisor_v_127) {
    v_303 = v_302;
  } else {
    v_303 = sub_19;
  };
  if (supervisor_c_rac) {
    sub_24 = v_303;
  } else {
    sub_24 = sub_19;
  };
  if (supervisor_v_128) {
    sub_23 = sub_24;
  } else {
    sub_23 = sub_18;
  };
  sub_22 = sub_23;
  if (supervisor_turn_on_wm) {
    v_306 = sub_22;
    sub_16 = sub_17;
  } else {
    v_306 = sub_17;
    sub_16 = sub_22;
  };
  if (supervisor_ck_20_1) {
    sub_15 = v_306;
  } else {
    sub_15 = sub_16;
  };
  if (supervisor_turn_on_rac) {
    v_301 = sub_20;
  } else {
    v_301 = false;
  };
  if (supervisor_c_rac) {
    sub_28 = v_301;
  } else {
    sub_28 = sub_19;
  };
  if (supervisor_v_128) {
    sub_27 = sub_24;
  } else {
    sub_27 = sub_28;
  };
  sub_26 = sub_27;
  sub_25 = sub_26;
  if (supervisor_do_open) {
    v_307 = sub_25;
    sub_14 = sub_15;
  } else {
    v_307 = sub_15;
    sub_14 = sub_25;
  };
  if (supervisor_ck_22_1) {
    sub_13 = v_307;
  } else {
    sub_13 = sub_14;
  };
  sub_36 = false;
  sub_35 = sub_36;
  sub_34 = sub_35;
  sub_33 = sub_34;
  if (supervisor_turn_on_rac) {
    v_297 = false;
  } else {
    v_297 = sub_36;
  };
  if (supervisor_v_127) {
    v_298 = v_297;
  } else {
    v_298 = sub_35;
  };
  if (supervisor_c_rac) {
    sub_39 = v_298;
  } else {
    sub_39 = sub_35;
  };
  if (supervisor_v_128) {
    sub_38 = sub_39;
  } else {
    sub_38 = sub_34;
  };
  sub_37 = sub_38;
  if (supervisor_turn_on_wm) {
    v_299 = sub_37;
    sub_32 = sub_33;
  } else {
    v_299 = sub_33;
    sub_32 = sub_37;
  };
  if (supervisor_ck_20_1) {
    sub_31 = v_299;
  } else {
    sub_31 = sub_32;
  };
  if (supervisor_turn_on_rac) {
    v_296 = sub_36;
  } else {
    v_296 = false;
  };
  if (supervisor_c_rac) {
    sub_43 = v_296;
  } else {
    sub_43 = sub_35;
  };
  if (supervisor_v_128) {
    sub_42 = sub_39;
  } else {
    sub_42 = sub_43;
  };
  sub_41 = sub_42;
  sub_40 = sub_41;
  if (supervisor_do_open) {
    v_300 = sub_40;
    sub_30 = sub_31;
  } else {
    v_300 = sub_31;
    sub_30 = sub_40;
  };
  if (supervisor_ck_22_1) {
    sub_29 = v_300;
  } else {
    sub_29 = sub_30;
  };
  if (supervisor_turn_on_tv) {
    v_308 = sub_29;
    sub_12 = sub_13;
  } else {
    v_308 = sub_13;
    sub_12 = sub_29;
  };
  if (supervisor_ck_18_1) {
    sub_11 = v_308;
  } else {
    sub_11 = sub_12;
  };
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  if (supervisor_c_l) {
    v_294 = sub_11;
  } else {
    v_294 = false;
  };
  if (supervisor_turn_on_l) {
    v_295 = v_294;
  } else {
    v_295 = false;
  };
  if (supervisor_c_l5) {
    sub_45 = v_295;
  } else {
    sub_45 = sub_9;
  };
  if (supervisor_c_l) {
    v_293 = false;
  } else {
    v_293 = sub_11;
  };
  if (supervisor_turn_on_l) {
    sub_46 = v_293;
  } else {
    sub_46 = sub_10;
  };
  if (supervisor_ck_16_1) {
    sub_44 = sub_46;
  } else {
    sub_44 = sub_45;
  };
  if (supervisor_turn_on_rl) {
    v_309 = sub_44;
    sub_7 = sub_8;
  } else {
    v_309 = sub_8;
    sub_7 = sub_44;
  };
  if (supervisor_ck_14_1) {
    sub_6 = v_309;
  } else {
    sub_6 = sub_7;
  };
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_54 = sub_29;
  sub_53 = sub_54;
  sub_52 = sub_53;
  sub_51 = sub_52;
  if (supervisor_c_l) {
    v_289 = sub_54;
  } else {
    v_289 = false;
  };
  if (supervisor_turn_on_l) {
    v_290 = v_289;
  } else {
    v_290 = false;
  };
  if (supervisor_c_l5) {
    sub_56 = v_290;
  } else {
    sub_56 = sub_52;
  };
  if (supervisor_c_l) {
    v_288 = false;
  } else {
    v_288 = sub_54;
  };
  if (supervisor_turn_on_l) {
    sub_57 = v_288;
  } else {
    sub_57 = sub_53;
  };
  if (supervisor_ck_16_1) {
    sub_55 = sub_57;
  } else {
    sub_55 = sub_56;
  };
  if (supervisor_turn_on_rl) {
    v_291 = sub_55;
    sub_50 = sub_51;
  } else {
    v_291 = sub_51;
    sub_50 = sub_55;
  };
  if (supervisor_ck_14_1) {
    sub_49 = v_291;
  } else {
    sub_49 = sub_50;
  };
  if (supervisor_ck_12_1) {
    sub_48 = false;
    v_287 = sub_49;
  } else {
    sub_48 = sub_49;
    v_287 = false;
  };
  if (supervisor_c_l4) {
    sub_58 = v_287;
  } else {
    sub_58 = sub_48;
  };
  if (supervisor_c_l3) {
    v_292 = sub_48;
  } else {
    v_292 = sub_58;
  };
  if (supervisor_turn_on_l2) {
    sub_47 = v_292;
  } else {
    sub_47 = sub_58;
  };
  if (supervisor_ck_10_1) {
    sub_2 = sub_47;
    v_286 = sub_3;
  } else {
    sub_2 = sub_3;
    v_286 = sub_47;
  };
  if (supervisor_c_l2) {
    sub_59 = v_286;
  } else {
    sub_59 = sub_2;
  };
  if (supervisor_c_l1) {
    v_310 = sub_2;
  } else {
    v_310 = sub_59;
  };
  if (supervisor_turn_on_l1) {
    sub_1 = v_310;
  } else {
    sub_1 = sub_59;
  };
  v_278 = !(supervisor_presence);
  v_279 = (v_278||false);
  sub_80 = (supervisor_presence||false);
  if (supervisor_ck_1) {
    sub_79 = v_279;
  } else {
    sub_79 = sub_80;
  };
  sub_78 = sub_79;
  sub_77 = sub_78;
  if (supervisor_turn_on_rac) {
    v_275 = sub_20;
  } else {
    v_275 = sub_79;
  };
  if (supervisor_v_127) {
    v_276 = v_275;
  } else {
    v_276 = sub_78;
  };
  if (supervisor_c_rac) {
    v_277 = v_276;
  } else {
    v_277 = sub_78;
  };
  if (supervisor_turn_on_rac) {
    v_274 = sub_79;
  } else {
    v_274 = sub_20;
  };
  if (supervisor_c_rac) {
    sub_82 = v_274;
  } else {
    sub_82 = sub_78;
  };
  if (supervisor_v_128) {
    sub_81 = v_277;
  } else {
    sub_81 = sub_82;
  };
  if (supervisor_v_111) {
    v_280 = sub_81;
  } else {
    v_280 = sub_77;
  };
  if (supervisor_turn_on_lac) {
    v_281 = v_280;
    sub_76 = sub_77;
  } else {
    v_281 = sub_77;
    sub_76 = sub_81;
  };
  if (supervisor_v_112) {
    sub_75 = v_281;
  } else {
    sub_75 = sub_76;
  };
  if (supervisor_turn_on_rac) {
    v_269 = false;
  } else {
    v_269 = sub_79;
  };
  if (supervisor_v_127) {
    v_270 = v_269;
  } else {
    v_270 = sub_78;
  };
  if (supervisor_c_rac) {
    sub_86 = v_270;
  } else {
    sub_86 = sub_78;
  };
  if (supervisor_v_128) {
    v_271 = sub_86;
    sub_85 = sub_86;
  } else {
    v_271 = sub_82;
    sub_85 = sub_77;
  };
  if (supervisor_v_111) {
    v_272 = sub_23;
  } else {
    v_272 = sub_85;
  };
  if (supervisor_turn_on_lac) {
    v_273 = v_272;
    sub_84 = sub_85;
  } else {
    v_273 = sub_85;
    sub_84 = v_271;
  };
  if (supervisor_v_112) {
    sub_83 = v_273;
  } else {
    sub_83 = sub_84;
  };
  if (supervisor_turn_on_wm) {
    v_282 = sub_83;
    sub_74 = sub_75;
  } else {
    v_282 = sub_75;
    sub_74 = sub_83;
  };
  if (supervisor_ck_20_1) {
    sub_73 = v_282;
  } else {
    sub_73 = sub_74;
  };
  if (supervisor_turn_on_rac) {
    v_266 = sub_79;
  } else {
    v_266 = false;
  };
  if (supervisor_c_rac) {
    sub_91 = v_266;
  } else {
    sub_91 = sub_78;
  };
  if (supervisor_v_128) {
    sub_90 = sub_86;
  } else {
    sub_90 = sub_91;
  };
  if (supervisor_v_111) {
    v_267 = sub_27;
  } else {
    v_267 = sub_90;
  };
  if (supervisor_turn_on_lac) {
    v_268 = v_267;
    sub_89 = sub_90;
  } else {
    v_268 = sub_90;
    sub_89 = sub_27;
  };
  if (supervisor_v_112) {
    sub_88 = v_268;
  } else {
    sub_88 = sub_89;
  };
  sub_87 = sub_88;
  if (supervisor_do_open) {
    v_283 = sub_87;
    sub_72 = sub_73;
  } else {
    v_283 = sub_73;
    sub_72 = sub_87;
  };
  if (supervisor_ck_22_1) {
    sub_71 = v_283;
  } else {
    sub_71 = sub_72;
  };
  sub_100 = true;
  sub_99 = sub_100;
  sub_98 = sub_99;
  if (supervisor_turn_on_rac) {
    v_259 = sub_36;
  } else {
    v_259 = sub_100;
  };
  if (supervisor_v_127) {
    v_260 = v_259;
  } else {
    v_260 = sub_99;
  };
  if (supervisor_c_rac) {
    v_261 = v_260;
  } else {
    v_261 = sub_99;
  };
  if (supervisor_turn_on_rac) {
    v_258 = sub_100;
  } else {
    v_258 = sub_36;
  };
  if (supervisor_c_rac) {
    sub_102 = v_258;
  } else {
    sub_102 = sub_99;
  };
  if (supervisor_v_128) {
    sub_101 = v_261;
  } else {
    sub_101 = sub_102;
  };
  if (supervisor_v_111) {
    v_262 = sub_101;
  } else {
    v_262 = sub_98;
  };
  if (supervisor_turn_on_lac) {
    v_263 = v_262;
    sub_97 = sub_98;
  } else {
    v_263 = sub_98;
    sub_97 = sub_101;
  };
  if (supervisor_v_112) {
    sub_96 = v_263;
  } else {
    sub_96 = sub_97;
  };
  if (supervisor_turn_on_rac) {
    v_253 = false;
  } else {
    v_253 = sub_100;
  };
  if (supervisor_v_127) {
    v_254 = v_253;
  } else {
    v_254 = sub_99;
  };
  if (supervisor_c_rac) {
    sub_106 = v_254;
  } else {
    sub_106 = sub_99;
  };
  if (supervisor_v_128) {
    v_255 = sub_106;
    sub_105 = sub_106;
  } else {
    v_255 = sub_102;
    sub_105 = sub_98;
  };
  if (supervisor_v_111) {
    v_256 = sub_38;
  } else {
    v_256 = sub_105;
  };
  if (supervisor_turn_on_lac) {
    v_257 = v_256;
    sub_104 = sub_105;
  } else {
    v_257 = sub_105;
    sub_104 = v_255;
  };
  if (supervisor_v_112) {
    sub_103 = v_257;
  } else {
    sub_103 = sub_104;
  };
  if (supervisor_turn_on_wm) {
    v_264 = sub_103;
    sub_95 = sub_96;
  } else {
    v_264 = sub_96;
    sub_95 = sub_103;
  };
  if (supervisor_ck_20_1) {
    sub_94 = v_264;
  } else {
    sub_94 = sub_95;
  };
  if (supervisor_turn_on_rac) {
    v_250 = sub_100;
  } else {
    v_250 = false;
  };
  if (supervisor_c_rac) {
    sub_111 = v_250;
  } else {
    sub_111 = sub_99;
  };
  if (supervisor_v_128) {
    sub_110 = sub_106;
  } else {
    sub_110 = sub_111;
  };
  if (supervisor_v_111) {
    v_251 = sub_42;
  } else {
    v_251 = sub_110;
  };
  if (supervisor_turn_on_lac) {
    v_252 = v_251;
    sub_109 = sub_110;
  } else {
    v_252 = sub_110;
    sub_109 = sub_42;
  };
  if (supervisor_v_112) {
    sub_108 = v_252;
  } else {
    sub_108 = sub_109;
  };
  sub_107 = sub_108;
  if (supervisor_do_open) {
    v_265 = sub_107;
    sub_93 = sub_94;
  } else {
    v_265 = sub_94;
    sub_93 = sub_107;
  };
  if (supervisor_ck_22_1) {
    sub_92 = v_265;
  } else {
    sub_92 = sub_93;
  };
  if (supervisor_turn_on_tv) {
    v_284 = sub_92;
    sub_70 = sub_71;
  } else {
    v_284 = sub_71;
    sub_70 = sub_92;
  };
  if (supervisor_ck_18_1) {
    sub_69 = v_284;
  } else {
    sub_69 = sub_70;
  };
  sub_68 = sub_69;
  sub_67 = sub_68;
  sub_66 = sub_67;
  if (supervisor_c_l) {
    v_248 = sub_69;
  } else {
    v_248 = false;
  };
  if (supervisor_turn_on_l) {
    v_249 = v_248;
  } else {
    v_249 = false;
  };
  if (supervisor_c_l5) {
    sub_113 = v_249;
  } else {
    sub_113 = sub_67;
  };
  if (supervisor_c_l) {
    v_247 = false;
  } else {
    v_247 = sub_69;
  };
  if (supervisor_turn_on_l) {
    sub_114 = v_247;
  } else {
    sub_114 = sub_68;
  };
  if (supervisor_ck_16_1) {
    sub_112 = sub_114;
  } else {
    sub_112 = sub_113;
  };
  if (supervisor_turn_on_rl) {
    v_285 = sub_112;
    sub_65 = sub_66;
  } else {
    v_285 = sub_66;
    sub_65 = sub_112;
  };
  if (supervisor_ck_14_1) {
    sub_64 = v_285;
  } else {
    sub_64 = sub_65;
  };
  sub_63 = sub_64;
  sub_62 = sub_63;
  sub_61 = sub_62;
  sub_122 = sub_92;
  sub_121 = sub_122;
  sub_120 = sub_121;
  sub_119 = sub_120;
  if (supervisor_c_l) {
    v_243 = sub_122;
  } else {
    v_243 = false;
  };
  if (supervisor_turn_on_l) {
    v_244 = v_243;
  } else {
    v_244 = false;
  };
  if (supervisor_c_l5) {
    sub_124 = v_244;
  } else {
    sub_124 = sub_120;
  };
  if (supervisor_c_l) {
    v_242 = false;
  } else {
    v_242 = sub_122;
  };
  if (supervisor_turn_on_l) {
    sub_125 = v_242;
  } else {
    sub_125 = sub_121;
  };
  if (supervisor_ck_16_1) {
    sub_123 = sub_125;
  } else {
    sub_123 = sub_124;
  };
  if (supervisor_turn_on_rl) {
    v_245 = sub_123;
    sub_118 = sub_119;
  } else {
    v_245 = sub_119;
    sub_118 = sub_123;
  };
  if (supervisor_ck_14_1) {
    sub_117 = v_245;
  } else {
    sub_117 = sub_118;
  };
  if (supervisor_ck_12_1) {
    sub_116 = false;
    v_241 = sub_117;
  } else {
    sub_116 = sub_117;
    v_241 = false;
  };
  if (supervisor_c_l4) {
    sub_126 = v_241;
  } else {
    sub_126 = sub_116;
  };
  if (supervisor_c_l3) {
    v_246 = sub_116;
  } else {
    v_246 = sub_126;
  };
  if (supervisor_turn_on_l2) {
    sub_115 = v_246;
  } else {
    sub_115 = sub_126;
  };
  if (supervisor_ck_10_1) {
    sub_60 = sub_115;
    v = sub_61;
  } else {
    sub_60 = sub_61;
    v = sub_115;
  };
  if (supervisor_c_l2) {
    sub_127 = v;
  } else {
    sub_127 = sub_60;
  };
  if (supervisor_c_l1) {
    v_311 = sub_60;
  } else {
    v_311 = sub_127;
  };
  if (supervisor_turn_on_l1) {
    v_312 = v_311;
  } else {
    v_312 = sub_127;
  };
  if (p_supervisor_c_lac) {
    sub_0 = v_312;
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
  Supervisor_controller__supervisor_controller_supervisor_c_rac_out* _out) {
  
  int v_335;
  int v_334;
  int v_333;
  int v_332;
  int v_331;
  int v_330;
  int v_329;
  int v_328;
  int v_327;
  int v_326;
  int v_325;
  int v_324;
  int v_323;
  int v_322;
  int v_321;
  int v_320;
  int v_319;
  int v_318;
  int v_317;
  int v_316;
  int v_315;
  int v_314;
  int v_313;
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
  int sub_40;
  int sub_41;
  int sub_42;
  int sub_43;
  int sub_44;
  int sub_45;
  int sub_46;
  int sub_47;
  int sub_48;
  int sub_49;
  int sub_50;
  int sub_51;
  int sub_52;
  int sub_53;
  int sub_54;
  int sub_55;
  int sub_56;
  int sub_57;
  int sub_58;
  int sub_59;
  v_328 = !(supervisor_presence);
  v_329 = (v_328||false);
  v_327 = (supervisor_presence&&false);
  v_326 = !(supervisor_presence);
  sub_20 = (v_326&&false);
  if (supervisor_ck_1) {
    sub_19 = v_327;
  } else {
    sub_19 = sub_20;
  };
  sub_21 = (supervisor_presence||false);
  if (supervisor_ck_1) {
    v_330 = v_329;
  } else {
    v_330 = sub_21;
  };
  if (p_supervisor_c_rac) {
    sub_18 = v_330;
  } else {
    sub_18 = sub_19;
  };
  sub_17 = sub_18;
  sub_16 = sub_17;
  if (supervisor_turn_on_rac) {
    v_325 = sub_19;
  } else {
    v_325 = sub_18;
  };
  if (supervisor_v_127) {
    sub_24 = v_325;
  } else {
    sub_24 = sub_17;
  };
  if (supervisor_v_128) {
    sub_23 = sub_24;
  } else {
    sub_23 = sub_17;
  };
  sub_22 = sub_23;
  if (supervisor_turn_on_wm) {
    v_331 = sub_22;
    sub_15 = sub_16;
  } else {
    v_331 = sub_16;
    sub_15 = sub_22;
  };
  if (supervisor_ck_20_1) {
    sub_14 = v_331;
  } else {
    sub_14 = sub_15;
  };
  if (supervisor_turn_on_rac) {
    sub_28 = sub_18;
  } else {
    sub_28 = sub_19;
  };
  if (supervisor_v_128) {
    sub_27 = sub_24;
  } else {
    sub_27 = sub_28;
  };
  sub_26 = sub_27;
  sub_25 = sub_26;
  if (supervisor_do_open) {
    v_332 = sub_25;
    sub_13 = sub_14;
  } else {
    v_332 = sub_14;
    sub_13 = sub_25;
  };
  if (supervisor_ck_22_1) {
    sub_12 = v_332;
  } else {
    sub_12 = sub_13;
  };
  sub_36 = false;
  if (p_supervisor_c_rac) {
    sub_35 = true;
  } else {
    sub_35 = sub_36;
  };
  sub_34 = sub_35;
  sub_33 = sub_34;
  if (supervisor_turn_on_rac) {
    v_322 = sub_36;
  } else {
    v_322 = sub_35;
  };
  if (supervisor_v_127) {
    sub_39 = v_322;
  } else {
    sub_39 = sub_34;
  };
  if (supervisor_v_128) {
    sub_38 = sub_39;
  } else {
    sub_38 = sub_34;
  };
  sub_37 = sub_38;
  if (supervisor_turn_on_wm) {
    v_323 = sub_37;
    sub_32 = sub_33;
  } else {
    v_323 = sub_33;
    sub_32 = sub_37;
  };
  if (supervisor_ck_20_1) {
    sub_31 = v_323;
  } else {
    sub_31 = sub_32;
  };
  if (supervisor_turn_on_rac) {
    sub_43 = sub_35;
  } else {
    sub_43 = sub_36;
  };
  if (supervisor_v_128) {
    sub_42 = sub_39;
  } else {
    sub_42 = sub_43;
  };
  sub_41 = sub_42;
  sub_40 = sub_41;
  if (supervisor_do_open) {
    v_324 = sub_40;
    sub_30 = sub_31;
  } else {
    v_324 = sub_31;
    sub_30 = sub_40;
  };
  if (supervisor_ck_22_1) {
    sub_29 = v_324;
  } else {
    sub_29 = sub_30;
  };
  if (supervisor_turn_on_tv) {
    v_333 = sub_29;
    sub_11 = sub_12;
  } else {
    v_333 = sub_12;
    sub_11 = sub_29;
  };
  if (supervisor_ck_18_1) {
    sub_10 = v_333;
  } else {
    sub_10 = sub_11;
  };
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  if (supervisor_c_l) {
    v_320 = sub_10;
  } else {
    v_320 = false;
  };
  if (supervisor_turn_on_l) {
    v_321 = v_320;
  } else {
    v_321 = false;
  };
  if (supervisor_c_l5) {
    sub_45 = v_321;
  } else {
    sub_45 = sub_8;
  };
  if (supervisor_c_l) {
    v_319 = false;
  } else {
    v_319 = sub_10;
  };
  if (supervisor_turn_on_l) {
    sub_46 = v_319;
  } else {
    sub_46 = sub_9;
  };
  if (supervisor_ck_16_1) {
    sub_44 = sub_46;
  } else {
    sub_44 = sub_45;
  };
  if (supervisor_turn_on_rl) {
    v_334 = sub_44;
    sub_6 = sub_7;
  } else {
    v_334 = sub_7;
    sub_6 = sub_44;
  };
  if (supervisor_ck_14_1) {
    sub_5 = v_334;
  } else {
    sub_5 = sub_6;
  };
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_54 = sub_29;
  sub_53 = sub_54;
  sub_52 = sub_53;
  sub_51 = sub_52;
  if (supervisor_c_l) {
    v_315 = sub_54;
  } else {
    v_315 = false;
  };
  if (supervisor_turn_on_l) {
    v_316 = v_315;
  } else {
    v_316 = false;
  };
  if (supervisor_c_l5) {
    sub_56 = v_316;
  } else {
    sub_56 = sub_52;
  };
  if (supervisor_c_l) {
    v_314 = false;
  } else {
    v_314 = sub_54;
  };
  if (supervisor_turn_on_l) {
    sub_57 = v_314;
  } else {
    sub_57 = sub_53;
  };
  if (supervisor_ck_16_1) {
    sub_55 = sub_57;
  } else {
    sub_55 = sub_56;
  };
  if (supervisor_turn_on_rl) {
    v_317 = sub_55;
    sub_50 = sub_51;
  } else {
    v_317 = sub_51;
    sub_50 = sub_55;
  };
  if (supervisor_ck_14_1) {
    sub_49 = v_317;
  } else {
    sub_49 = sub_50;
  };
  if (supervisor_ck_12_1) {
    sub_48 = false;
    v_313 = sub_49;
  } else {
    sub_48 = sub_49;
    v_313 = false;
  };
  if (supervisor_c_l4) {
    sub_58 = v_313;
  } else {
    sub_58 = sub_48;
  };
  if (supervisor_c_l3) {
    v_318 = sub_48;
  } else {
    v_318 = sub_58;
  };
  if (supervisor_turn_on_l2) {
    sub_47 = v_318;
  } else {
    sub_47 = sub_58;
  };
  if (supervisor_ck_10_1) {
    sub_1 = sub_47;
    v = sub_2;
  } else {
    sub_1 = sub_2;
    v = sub_47;
  };
  if (supervisor_c_l2) {
    sub_59 = v;
  } else {
    sub_59 = sub_1;
  };
  if (supervisor_c_l1) {
    v_335 = sub_1;
  } else {
    v_335 = sub_59;
  };
  if (supervisor_turn_on_l1) {
    sub_0 = v_335;
  } else {
    sub_0 = sub_59;
  };
  _out->supervisor_c_rac = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c_l5_out* _out) {
  
  int v_358;
  int v_357;
  int v_356;
  int v_355;
  int v_354;
  int v_353;
  int v_352;
  int v_351;
  int v_350;
  int v_349;
  int v_348;
  int v_347;
  int v_346;
  int v_345;
  int v_344;
  int v_343;
  int v_342;
  int v_341;
  int v_340;
  int v_339;
  int v_338;
  int v_337;
  int v_336;
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
  int sub_40;
  int sub_41;
  int sub_42;
  int sub_43;
  int sub_44;
  int sub_45;
  int sub_46;
  int sub_47;
  int sub_48;
  int sub_49;
  int sub_50;
  int sub_51;
  int sub_52;
  int sub_53;
  int sub_54;
  v_355 = (supervisor_presence&&false);
  v_354 = !(supervisor_presence);
  sub_17 = (v_354&&false);
  if (supervisor_ck_1) {
    sub_16 = v_355;
  } else {
    sub_16 = sub_17;
  };
  sub_15 = sub_16;
  sub_14 = sub_15;
  sub_13 = sub_14;
  sub_12 = sub_13;
  sub_22 = false;
  sub_21 = sub_22;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  if (supervisor_turn_on_tv) {
    v_356 = sub_18;
    sub_11 = sub_12;
  } else {
    v_356 = sub_12;
    sub_11 = sub_18;
  };
  if (supervisor_ck_18_1) {
    sub_10 = v_356;
  } else {
    sub_10 = sub_11;
  };
  sub_9 = sub_10;
  sub_8 = sub_9;
  v_351 = !(supervisor_presence);
  v_352 = (v_351||false);
  sub_31 = (supervisor_presence||false);
  if (supervisor_ck_1) {
    sub_30 = v_352;
  } else {
    sub_30 = sub_31;
  };
  sub_29 = sub_30;
  sub_28 = sub_29;
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_36 = true;
  sub_35 = sub_36;
  sub_34 = sub_35;
  sub_33 = sub_34;
  sub_32 = sub_33;
  if (supervisor_turn_on_tv) {
    v_353 = sub_32;
    sub_25 = sub_26;
  } else {
    v_353 = sub_26;
    sub_25 = sub_32;
  };
  if (supervisor_ck_18_1) {
    sub_24 = v_353;
  } else {
    sub_24 = sub_25;
  };
  sub_23 = sub_24;
  if (p_supervisor_c_l5) {
    sub_7 = sub_23;
  } else {
    sub_7 = sub_8;
  };
  if (supervisor_c_l) {
    v_348 = false;
  } else {
    v_348 = sub_24;
  };
  if (supervisor_turn_on_l) {
    v_349 = v_348;
  } else {
    v_349 = sub_23;
  };
  if (supervisor_c_l) {
    v_346 = sub_24;
  } else {
    v_346 = sub_10;
  };
  if (supervisor_turn_on_l) {
    v_347 = v_346;
  } else {
    v_347 = sub_9;
  };
  if (p_supervisor_c_l5) {
    sub_38 = v_347;
  } else {
    sub_38 = sub_8;
  };
  if (supervisor_c_l) {
    v_345 = false;
  } else {
    v_345 = sub_10;
  };
  if (supervisor_turn_on_l) {
    sub_39 = v_345;
  } else {
    sub_39 = sub_9;
  };
  if (p_supervisor_c_l5) {
    v_350 = v_349;
  } else {
    v_350 = sub_39;
  };
  if (supervisor_ck_16_1) {
    sub_37 = v_350;
  } else {
    sub_37 = sub_38;
  };
  if (supervisor_turn_on_rl) {
    v_357 = sub_37;
    sub_6 = sub_7;
  } else {
    v_357 = sub_7;
    sub_6 = sub_37;
  };
  if (supervisor_ck_14_1) {
    sub_5 = v_357;
  } else {
    sub_5 = sub_6;
  };
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_47 = sub_18;
  sub_46 = sub_47;
  sub_45 = sub_46;
  sub_49 = sub_32;
  sub_48 = sub_49;
  if (p_supervisor_c_l5) {
    sub_44 = sub_48;
  } else {
    sub_44 = sub_45;
  };
  if (supervisor_c_l) {
    v_340 = false;
  } else {
    v_340 = sub_49;
  };
  if (supervisor_turn_on_l) {
    v_341 = v_340;
  } else {
    v_341 = sub_48;
  };
  if (supervisor_c_l) {
    v_338 = sub_49;
  } else {
    v_338 = sub_47;
  };
  if (supervisor_turn_on_l) {
    v_339 = v_338;
  } else {
    v_339 = sub_46;
  };
  if (p_supervisor_c_l5) {
    sub_51 = v_339;
  } else {
    sub_51 = sub_45;
  };
  if (supervisor_c_l) {
    v_337 = false;
  } else {
    v_337 = sub_47;
  };
  if (supervisor_turn_on_l) {
    sub_52 = v_337;
  } else {
    sub_52 = sub_46;
  };
  if (p_supervisor_c_l5) {
    v_342 = v_341;
  } else {
    v_342 = sub_52;
  };
  if (supervisor_ck_16_1) {
    sub_50 = v_342;
  } else {
    sub_50 = sub_51;
  };
  if (supervisor_turn_on_rl) {
    v_343 = sub_50;
    sub_43 = sub_44;
  } else {
    v_343 = sub_44;
    sub_43 = sub_50;
  };
  if (supervisor_ck_14_1) {
    sub_42 = v_343;
  } else {
    sub_42 = sub_43;
  };
  if (supervisor_ck_12_1) {
    sub_41 = false;
    v_336 = sub_42;
  } else {
    sub_41 = sub_42;
    v_336 = false;
  };
  if (supervisor_c_l4) {
    sub_53 = v_336;
  } else {
    sub_53 = sub_41;
  };
  if (supervisor_c_l3) {
    v_344 = sub_41;
  } else {
    v_344 = sub_53;
  };
  if (supervisor_turn_on_l2) {
    sub_40 = v_344;
  } else {
    sub_40 = sub_53;
  };
  if (supervisor_ck_10_1) {
    sub_1 = sub_40;
    v = sub_2;
  } else {
    sub_1 = sub_2;
    v = sub_40;
  };
  if (supervisor_c_l2) {
    sub_54 = v;
  } else {
    sub_54 = sub_1;
  };
  if (supervisor_c_l1) {
    v_358 = sub_1;
  } else {
    v_358 = sub_54;
  };
  if (supervisor_turn_on_l1) {
    sub_0 = v_358;
  } else {
    sub_0 = sub_54;
  };
  _out->supervisor_c_l5 = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c_l_out* _out) {
  
  int v_371;
  int v_370;
  int v_369;
  int v_368;
  int v_367;
  int v_366;
  int v_365;
  int v_364;
  int v_363;
  int v_362;
  int v_361;
  int v_360;
  int v_359;
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
  int sub_40;
  int sub_41;
  int sub_42;
  int sub_43;
  sub_16 = p_supervisor_c_l;
  if (supervisor_presence) {
    v_368 = false;
    sub_15 = sub_16;
  } else {
    v_368 = sub_16;
    sub_15 = false;
  };
  if (supervisor_ck_1) {
    sub_14 = v_368;
  } else {
    sub_14 = sub_15;
  };
  sub_13 = sub_14;
  sub_12 = sub_13;
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_21 = sub_16;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  sub_17 = sub_18;
  if (supervisor_turn_on_tv) {
    v_369 = sub_17;
    sub_9 = sub_10;
  } else {
    v_369 = sub_10;
    sub_9 = sub_17;
  };
  if (supervisor_ck_18_1) {
    sub_8 = v_369;
  } else {
    sub_8 = sub_9;
  };
  sub_7 = sub_8;
  v_364 = (supervisor_presence&&false);
  v_363 = !(supervisor_presence);
  sub_29 = (v_363&&false);
  if (supervisor_ck_1) {
    sub_28 = v_364;
  } else {
    sub_28 = sub_29;
  };
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_25 = sub_26;
  sub_24 = sub_25;
  sub_34 = false;
  sub_33 = sub_34;
  sub_32 = sub_33;
  sub_31 = sub_32;
  sub_30 = sub_31;
  if (supervisor_turn_on_tv) {
    v_365 = sub_30;
    sub_23 = sub_24;
  } else {
    v_365 = sub_24;
    sub_23 = sub_30;
  };
  if (supervisor_ck_18_1) {
    v_366 = v_365;
  } else {
    v_366 = sub_23;
  };
  if (supervisor_turn_on_l) {
    v_367 = v_366;
  } else {
    v_367 = sub_8;
  };
  if (supervisor_ck_16_1) {
    sub_22 = v_367;
  } else {
    sub_22 = sub_7;
  };
  if (supervisor_turn_on_rl) {
    v_370 = sub_22;
    sub_6 = sub_7;
  } else {
    v_370 = sub_7;
    sub_6 = sub_22;
  };
  if (supervisor_ck_14_1) {
    sub_5 = v_370;
  } else {
    sub_5 = sub_6;
  };
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_40 = sub_17;
  sub_39 = sub_40;
  if (supervisor_turn_on_l) {
    v_360 = sub_30;
  } else {
    v_360 = sub_40;
  };
  if (supervisor_ck_16_1) {
    sub_41 = v_360;
  } else {
    sub_41 = sub_39;
  };
  if (supervisor_turn_on_rl) {
    v_361 = sub_41;
    sub_38 = sub_39;
  } else {
    v_361 = sub_39;
    sub_38 = sub_41;
  };
  if (supervisor_ck_14_1) {
    sub_37 = v_361;
  } else {
    sub_37 = sub_38;
  };
  if (supervisor_ck_12_1) {
    sub_36 = false;
    v_359 = sub_37;
  } else {
    sub_36 = sub_37;
    v_359 = false;
  };
  if (supervisor_c_l4) {
    sub_42 = v_359;
  } else {
    sub_42 = sub_36;
  };
  if (supervisor_c_l3) {
    v_362 = sub_36;
  } else {
    v_362 = sub_42;
  };
  if (supervisor_turn_on_l2) {
    sub_35 = v_362;
  } else {
    sub_35 = sub_42;
  };
  if (supervisor_ck_10_1) {
    sub_1 = sub_35;
    v = sub_2;
  } else {
    sub_1 = sub_2;
    v = sub_35;
  };
  if (supervisor_c_l2) {
    sub_43 = v;
  } else {
    sub_43 = sub_1;
  };
  if (supervisor_c_l1) {
    v_371 = sub_1;
  } else {
    v_371 = sub_43;
  };
  if (supervisor_turn_on_l1) {
    sub_0 = v_371;
  } else {
    sub_0 = sub_43;
  };
  _out->supervisor_c_l = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c_l4_out* _out) {
  
  int v_376;
  int v_375;
  int v_374;
  int v_373;
  int v_372;
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
  int sub_40;
  sub_14 = p_supervisor_c_l4;
  if (supervisor_presence) {
    v_374 = false;
    sub_13 = sub_14;
  } else {
    v_374 = sub_14;
    sub_13 = false;
  };
  if (supervisor_ck_1) {
    sub_12 = v_374;
  } else {
    sub_12 = sub_13;
  };
  sub_11 = sub_12;
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_19 = sub_14;
  sub_18 = sub_19;
  sub_17 = sub_18;
  sub_16 = sub_17;
  sub_15 = sub_16;
  if (supervisor_turn_on_tv) {
    v_375 = sub_15;
    sub_7 = sub_8;
  } else {
    v_375 = sub_8;
    sub_7 = sub_15;
  };
  if (supervisor_ck_18_1) {
    sub_6 = v_375;
  } else {
    sub_6 = sub_7;
  };
  sub_5 = sub_6;
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_23 = sub_15;
  sub_22 = sub_23;
  sub_21 = sub_22;
  if (supervisor_ck_12_1) {
    v_372 = false;
  } else {
    v_372 = sub_21;
  };
  sub_32 = false;
  sub_31 = sub_32;
  sub_30 = sub_31;
  sub_29 = sub_30;
  sub_28 = sub_29;
  sub_27 = sub_28;
  sub_26 = sub_27;
  sub_25 = sub_26;
  sub_39 = true;
  sub_38 = sub_39;
  sub_37 = sub_38;
  sub_36 = sub_37;
  sub_35 = sub_36;
  sub_34 = sub_35;
  sub_33 = sub_34;
  if (supervisor_ck_12_1) {
    sub_24 = sub_33;
  } else {
    sub_24 = sub_25;
  };
  if (supervisor_c_l3) {
    v_373 = v_372;
  } else {
    v_373 = sub_24;
  };
  if (supervisor_turn_on_l2) {
    sub_20 = v_373;
  } else {
    sub_20 = sub_24;
  };
  if (supervisor_ck_10_1) {
    sub_1 = sub_20;
    v = sub_2;
  } else {
    sub_1 = sub_2;
    v = sub_20;
  };
  if (supervisor_c_l2) {
    sub_40 = v;
  } else {
    sub_40 = sub_1;
  };
  if (supervisor_c_l1) {
    v_376 = sub_1;
  } else {
    v_376 = sub_40;
  };
  if (supervisor_turn_on_l1) {
    sub_0 = v_376;
  } else {
    sub_0 = sub_40;
  };
  _out->supervisor_c_l4 = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c_l2_out* _out) {
  
  int v_399;
  int v_398;
  int v_397;
  int v_396;
  int v_395;
  int v_394;
  int v_393;
  int v_392;
  int v_391;
  int v_390;
  int v_389;
  int v_388;
  int v_387;
  int v_386;
  int v_385;
  int v_384;
  int v_383;
  int v_382;
  int v_381;
  int v_380;
  int v_379;
  int v_378;
  int v_377;
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
  int sub_40;
  int sub_41;
  int sub_42;
  int sub_43;
  int sub_44;
  int sub_45;
  int sub_46;
  int sub_47;
  int sub_48;
  int sub_49;
  int sub_50;
  int sub_51;
  int sub_52;
  int sub_53;
  int sub_54;
  int sub_55;
  int sub_56;
  int sub_57;
  int sub_58;
  int sub_59;
  int sub_60;
  int sub_61;
  int sub_62;
  int sub_63;
  int sub_64;
  int sub_65;
  int sub_66;
  int sub_67;
  int sub_68;
  int sub_69;
  int sub_70;
  int sub_71;
  sub_13 = p_supervisor_c_l2;
  if (supervisor_presence) {
    v_393 = false;
    sub_12 = sub_13;
  } else {
    v_393 = sub_13;
    sub_12 = false;
  };
  if (supervisor_ck_1) {
    sub_11 = v_393;
  } else {
    sub_11 = sub_12;
  };
  sub_10 = sub_11;
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_18 = sub_13;
  sub_17 = sub_18;
  sub_16 = sub_17;
  sub_15 = sub_16;
  sub_14 = sub_15;
  if (supervisor_turn_on_tv) {
    v_394 = sub_14;
    sub_6 = sub_7;
  } else {
    v_394 = sub_7;
    sub_6 = sub_14;
  };
  if (supervisor_ck_18_1) {
    sub_5 = v_394;
  } else {
    sub_5 = sub_6;
  };
  sub_4 = sub_5;
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_21 = sub_14;
  sub_20 = sub_21;
  sub_19 = sub_20;
  if (supervisor_ck_12_1) {
    v_395 = false;
  } else {
    v_395 = sub_19;
  };
  if (supervisor_c_l3) {
    v_396 = v_395;
  } else {
    v_396 = sub_19;
  };
  if (supervisor_turn_on_l2) {
    v_397 = v_396;
  } else {
    v_397 = sub_19;
  };
  if (supervisor_ck_10_1) {
    v_398 = v_397;
  } else {
    v_398 = sub_1;
  };
  v_386 = (supervisor_presence||sub_13);
  v_385 = !(supervisor_presence);
  sub_33 = (v_385||sub_13);
  if (supervisor_ck_1) {
    sub_32 = v_386;
  } else {
    sub_32 = sub_33;
  };
  sub_31 = sub_32;
  sub_30 = sub_31;
  sub_29 = sub_30;
  sub_28 = sub_29;
  if (supervisor_turn_on_tv) {
    v_387 = sub_14;
    sub_27 = sub_28;
  } else {
    v_387 = sub_28;
    sub_27 = sub_14;
  };
  if (supervisor_ck_18_1) {
    sub_26 = v_387;
  } else {
    sub_26 = sub_27;
  };
  sub_25 = sub_26;
  sub_24 = sub_25;
  v_383 = (supervisor_presence&&false);
  v_382 = !(supervisor_presence);
  sub_42 = (v_382&&false);
  if (supervisor_ck_1) {
    sub_41 = v_383;
  } else {
    sub_41 = sub_42;
  };
  sub_40 = sub_41;
  sub_39 = sub_40;
  sub_38 = sub_39;
  sub_37 = sub_38;
  sub_47 = false;
  sub_46 = sub_47;
  sub_45 = sub_46;
  sub_44 = sub_45;
  sub_43 = sub_44;
  if (supervisor_turn_on_tv) {
    v_384 = sub_43;
    sub_36 = sub_37;
  } else {
    v_384 = sub_37;
    sub_36 = sub_43;
  };
  if (supervisor_ck_18_1) {
    sub_35 = v_384;
  } else {
    sub_35 = sub_36;
  };
  sub_34 = sub_35;
  if (supervisor_ck_12_1) {
    v_388 = sub_34;
  } else {
    v_388 = sub_24;
  };
  if (supervisor_c_l3) {
    v_389 = v_388;
  } else {
    v_389 = sub_24;
  };
  if (supervisor_turn_on_l2) {
    sub_23 = v_389;
  } else {
    sub_23 = sub_24;
  };
  v_379 = !(supervisor_presence);
  v_380 = (v_379&&sub_13);
  sub_57 = (supervisor_presence&&sub_13);
  if (supervisor_ck_1) {
    sub_56 = v_380;
  } else {
    sub_56 = sub_57;
  };
  sub_55 = sub_56;
  sub_54 = sub_55;
  sub_53 = sub_54;
  sub_52 = sub_53;
  if (supervisor_turn_on_tv) {
    v_381 = sub_14;
    sub_51 = sub_52;
  } else {
    v_381 = sub_52;
    sub_51 = sub_14;
  };
  if (supervisor_ck_18_1) {
    sub_50 = v_381;
  } else {
    sub_50 = sub_51;
  };
  sub_49 = sub_50;
  sub_48 = sub_49;
  v = !(supervisor_presence);
  v_377 = (v||false);
  sub_66 = (supervisor_presence||false);
  if (supervisor_ck_1) {
    sub_65 = v_377;
  } else {
    sub_65 = sub_66;
  };
  sub_64 = sub_65;
  sub_63 = sub_64;
  sub_62 = sub_63;
  sub_61 = sub_62;
  sub_71 = true;
  sub_70 = sub_71;
  sub_69 = sub_70;
  sub_68 = sub_69;
  sub_67 = sub_68;
  if (supervisor_turn_on_tv) {
    v_378 = sub_67;
    sub_60 = sub_61;
  } else {
    v_378 = sub_61;
    sub_60 = sub_67;
  };
  if (supervisor_ck_18_1) {
    sub_59 = v_378;
  } else {
    sub_59 = sub_60;
  };
  sub_58 = sub_59;
  if (supervisor_ck_12_1) {
    v_390 = sub_58;
  } else {
    v_390 = sub_48;
  };
  if (supervisor_c_l3) {
    v_391 = v_390;
  } else {
    v_391 = sub_48;
  };
  if (supervisor_turn_on_l2) {
    v_392 = v_391;
  } else {
    v_392 = sub_48;
  };
  if (supervisor_ck_10_1) {
    sub_22 = v_392;
  } else {
    sub_22 = sub_23;
  };
  if (supervisor_c_l1) {
    v_399 = v_398;
  } else {
    v_399 = sub_22;
  };
  if (supervisor_turn_on_l1) {
    sub_0 = v_399;
  } else {
    sub_0 = sub_22;
  };
  _out->supervisor_c_l2 = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c_l3_out* _out) {
  
  int v_408;
  int v_407;
  int v_406;
  int v_405;
  int v_404;
  int v_403;
  int v_402;
  int v_401;
  int v_400;
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
  sub_12 = p_supervisor_c_l3;
  if (supervisor_presence) {
    v_403 = false;
    sub_11 = sub_12;
  } else {
    v_403 = sub_12;
    sub_11 = false;
  };
  if (supervisor_ck_1) {
    sub_10 = v_403;
  } else {
    sub_10 = sub_11;
  };
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_17 = sub_12;
  sub_16 = sub_17;
  sub_15 = sub_16;
  sub_14 = sub_15;
  sub_13 = sub_14;
  if (supervisor_turn_on_tv) {
    v_404 = sub_13;
    sub_5 = sub_6;
  } else {
    v_404 = sub_6;
    sub_5 = sub_13;
  };
  if (supervisor_ck_18_1) {
    sub_4 = v_404;
  } else {
    sub_4 = sub_5;
  };
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_20 = sub_13;
  sub_19 = sub_20;
  sub_18 = sub_19;
  sub_27 = false;
  sub_26 = sub_27;
  sub_25 = sub_26;
  sub_24 = sub_25;
  sub_23 = sub_24;
  sub_22 = sub_23;
  sub_21 = sub_22;
  if (supervisor_ck_12_1) {
    v_405 = sub_21;
  } else {
    v_405 = sub_18;
  };
  if (supervisor_turn_on_l2) {
    v_406 = v_405;
  } else {
    v_406 = sub_18;
  };
  if (supervisor_ck_10_1) {
    v_407 = v_406;
  } else {
    v_407 = sub_1;
  };
  v = !(supervisor_presence);
  v_400 = (v&&sub_12);
  sub_37 = (supervisor_presence&&sub_12);
  if (supervisor_ck_1) {
    sub_36 = v_400;
  } else {
    sub_36 = sub_37;
  };
  sub_35 = sub_36;
  sub_34 = sub_35;
  sub_33 = sub_34;
  sub_32 = sub_33;
  if (supervisor_turn_on_tv) {
    v_401 = sub_13;
    sub_31 = sub_32;
  } else {
    v_401 = sub_32;
    sub_31 = sub_13;
  };
  if (supervisor_ck_18_1) {
    sub_30 = v_401;
  } else {
    sub_30 = sub_31;
  };
  sub_29 = sub_30;
  if (supervisor_ck_12_1) {
    v_402 = sub_29;
  } else {
    v_402 = sub_18;
  };
  if (supervisor_turn_on_l2) {
    sub_28 = v_402;
  } else {
    sub_28 = sub_18;
  };
  if (supervisor_c_l1) {
    v_408 = v_407;
  } else {
    v_408 = sub_28;
  };
  if (supervisor_turn_on_l1) {
    sub_0 = v_408;
  } else {
    sub_0 = sub_28;
  };
  _out->supervisor_c_l3 = sub_0;;
}

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
  Supervisor_controller__supervisor_controller_supervisor_c_l1_out* _out) {
  
  int v_411;
  int v_410;
  int v_409;
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
  v = !(supervisor_presence);
  sub_12 = p_supervisor_c_l1;
  v_409 = (v&&sub_12);
  sub_11 = (supervisor_presence&&sub_12);
  if (supervisor_ck_1) {
    sub_10 = v_409;
  } else {
    sub_10 = sub_11;
  };
  sub_9 = sub_10;
  sub_8 = sub_9;
  sub_7 = sub_8;
  sub_6 = sub_7;
  sub_17 = sub_12;
  sub_16 = sub_17;
  sub_15 = sub_16;
  sub_14 = sub_15;
  sub_13 = sub_14;
  if (supervisor_turn_on_tv) {
    v_410 = sub_13;
    sub_5 = sub_6;
  } else {
    v_410 = sub_6;
    sub_5 = sub_13;
  };
  if (supervisor_ck_18_1) {
    sub_4 = v_410;
  } else {
    sub_4 = sub_5;
  };
  sub_3 = sub_4;
  sub_2 = sub_3;
  sub_1 = sub_2;
  sub_21 = sub_13;
  sub_20 = sub_21;
  sub_19 = sub_20;
  sub_18 = sub_19;
  if (supervisor_ck_10_1) {
    v_411 = sub_18;
  } else {
    v_411 = sub_1;
  };
  if (supervisor_turn_on_l1) {
    sub_0 = v_411;
  } else {
    sub_0 = sub_18;
  };
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
                                                       Supervisor_controller__supervisor_controller_out* _out) {
  Supervisor_controller__supervisor_controller_supervisor_c_lac_out Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c2_lac_out Supervisor_controller__supervisor_controller_supervisor_c2_lac_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l1_out Supervisor_controller__supervisor_controller_supervisor_c_l1_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l_out Supervisor_controller__supervisor_controller_supervisor_c_l_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l4_out Supervisor_controller__supervisor_controller_supervisor_c_l4_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c_l5_out Supervisor_controller__supervisor_controller_supervisor_c_l5_out_st;
  Supervisor_controller__supervisor_controller_supervisor_c2_rac_out Supervisor_controller__supervisor_controller_supervisor_c2_rac_out_st;
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
                                                                    supervisor_ck_10_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_12_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_14_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_16_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_18_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_20_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_22_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_128,
                                                                    supervisor_v_127,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_112,
                                                                    supervisor_v_111,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c2_lac,
                                                                    p_supervisor_c2_rac,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l1_out_st);
  _out->supervisor_c_l1 = Supervisor_controller__supervisor_controller_supervisor_c_l1_out_st.supervisor_c_l1;
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
                                                                    supervisor_ck_10_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_12_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_14_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_16_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_18_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_20_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_22_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_128,
                                                                    supervisor_v_127,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_112,
                                                                    supervisor_v_111,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c2_lac,
                                                                    p_supervisor_c2_rac,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l3_out_st);
  _out->supervisor_c_l3 = Supervisor_controller__supervisor_controller_supervisor_c_l3_out_st.supervisor_c_l3;
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
                                                                    supervisor_ck_10_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_12_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_14_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_16_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_18_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_20_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_22_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_128,
                                                                    supervisor_v_127,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_112,
                                                                    supervisor_v_111,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c2_lac,
                                                                    p_supervisor_c2_rac,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l3,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l2_out_st);
  _out->supervisor_c_l2 = Supervisor_controller__supervisor_controller_supervisor_c_l2_out_st.supervisor_c_l2;
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
                                                                    supervisor_ck_10_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_12_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_14_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_16_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_18_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_20_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_22_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_128,
                                                                    supervisor_v_127,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_112,
                                                                    supervisor_v_111,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c2_lac,
                                                                    p_supervisor_c2_rac,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l2,
                                                                    _out->supervisor_c_l3,
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
                                                                   supervisor_ck_10_1,
                                                                   supervisor_pnr_8,
                                                                   supervisor_ck_12_1,
                                                                   supervisor_pnr_7,
                                                                   supervisor_ck_14_1,
                                                                   supervisor_pnr_6,
                                                                   supervisor_ck_16_1,
                                                                   supervisor_pnr_5,
                                                                   supervisor_ck_18_1,
                                                                   supervisor_pnr_4,
                                                                   supervisor_ck_20_1,
                                                                   supervisor_pnr_3,
                                                                   supervisor_ck_22_1,
                                                                   supervisor_pnr_2,
                                                                   supervisor_v_128,
                                                                   supervisor_v_127,
                                                                   supervisor_pnr_1,
                                                                   supervisor_v_112,
                                                                   supervisor_v_111,
                                                                   supervisor_pnr,
                                                                   p_supervisor_c2_lac,
                                                                   p_supervisor_c2_rac,
                                                                   p_supervisor_c_lac,
                                                                   p_supervisor_c_rac,
                                                                   p_supervisor_c_l5,
                                                                   p_supervisor_c_l,
                                                                   p_supervisor_c_l4,
                                                                   p_supervisor_c_l2,
                                                                   p_supervisor_c_l3,
                                                                   p_supervisor_c_l1,
                                                                   _out->supervisor_c_l4,
                                                                   _out->supervisor_c_l2,
                                                                   _out->supervisor_c_l3,
                                                                   _out->supervisor_c_l1,
                                                                   &Supervisor_controller__supervisor_controller_supervisor_c_l_out_st);
  _out->supervisor_c_l = Supervisor_controller__supervisor_controller_supervisor_c_l_out_st.supervisor_c_l;
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
                                                                    supervisor_ck_10_1,
                                                                    supervisor_pnr_8,
                                                                    supervisor_ck_12_1,
                                                                    supervisor_pnr_7,
                                                                    supervisor_ck_14_1,
                                                                    supervisor_pnr_6,
                                                                    supervisor_ck_16_1,
                                                                    supervisor_pnr_5,
                                                                    supervisor_ck_18_1,
                                                                    supervisor_pnr_4,
                                                                    supervisor_ck_20_1,
                                                                    supervisor_pnr_3,
                                                                    supervisor_ck_22_1,
                                                                    supervisor_pnr_2,
                                                                    supervisor_v_128,
                                                                    supervisor_v_127,
                                                                    supervisor_pnr_1,
                                                                    supervisor_v_112,
                                                                    supervisor_v_111,
                                                                    supervisor_pnr,
                                                                    p_supervisor_c2_lac,
                                                                    p_supervisor_c2_rac,
                                                                    p_supervisor_c_lac,
                                                                    p_supervisor_c_rac,
                                                                    p_supervisor_c_l5,
                                                                    p_supervisor_c_l,
                                                                    p_supervisor_c_l4,
                                                                    p_supervisor_c_l2,
                                                                    p_supervisor_c_l3,
                                                                    p_supervisor_c_l1,
                                                                    _out->supervisor_c_l,
                                                                    _out->supervisor_c_l4,
                                                                    _out->supervisor_c_l2,
                                                                    _out->supervisor_c_l3,
                                                                    _out->supervisor_c_l1,
                                                                    &Supervisor_controller__supervisor_controller_supervisor_c_l5_out_st);
  _out->supervisor_c_l5 = Supervisor_controller__supervisor_controller_supervisor_c_l5_out_st.supervisor_c_l5;
  Supervisor_controller__supervisor_controller_supervisor_c_rac_step(
  supervisor_presence, supervisor_turn_on_l1, supervisor_turn_on_l2,
  supervisor_turn_on_rl, supervisor_turn_on_l, supervisor_turn_on_rac,
  supervisor_turn_on_lac, supervisor_turn_on_tv, supervisor_turn_on_wm,
  supervisor_do_open, supervisor_ck_1, supervisor_pnr_9, supervisor_ck_10_1,
  supervisor_pnr_8, supervisor_ck_12_1, supervisor_pnr_7, supervisor_ck_14_1,
  supervisor_pnr_6, supervisor_ck_16_1, supervisor_pnr_5, supervisor_ck_18_1,
  supervisor_pnr_4, supervisor_ck_20_1, supervisor_pnr_3, supervisor_ck_22_1,
  supervisor_pnr_2, supervisor_v_128, supervisor_v_127, supervisor_pnr_1,
  supervisor_v_112, supervisor_v_111, supervisor_pnr, p_supervisor_c2_lac,
  p_supervisor_c2_rac, p_supervisor_c_lac, p_supervisor_c_rac,
  p_supervisor_c_l5, p_supervisor_c_l, p_supervisor_c_l4, p_supervisor_c_l2,
  p_supervisor_c_l3, p_supervisor_c_l1, _out->supervisor_c_l5,
  _out->supervisor_c_l, _out->supervisor_c_l4, _out->supervisor_c_l2,
  _out->supervisor_c_l3, _out->supervisor_c_l1,
  &Supervisor_controller__supervisor_controller_supervisor_c_rac_out_st);
  _out->supervisor_c_rac = Supervisor_controller__supervisor_controller_supervisor_c_rac_out_st.supervisor_c_rac;
  Supervisor_controller__supervisor_controller_supervisor_c_lac_step(
  supervisor_presence, supervisor_turn_on_l1, supervisor_turn_on_l2,
  supervisor_turn_on_rl, supervisor_turn_on_l, supervisor_turn_on_rac,
  supervisor_turn_on_lac, supervisor_turn_on_tv, supervisor_turn_on_wm,
  supervisor_do_open, supervisor_ck_1, supervisor_pnr_9, supervisor_ck_10_1,
  supervisor_pnr_8, supervisor_ck_12_1, supervisor_pnr_7, supervisor_ck_14_1,
  supervisor_pnr_6, supervisor_ck_16_1, supervisor_pnr_5, supervisor_ck_18_1,
  supervisor_pnr_4, supervisor_ck_20_1, supervisor_pnr_3, supervisor_ck_22_1,
  supervisor_pnr_2, supervisor_v_128, supervisor_v_127, supervisor_pnr_1,
  supervisor_v_112, supervisor_v_111, supervisor_pnr, p_supervisor_c2_lac,
  p_supervisor_c2_rac, p_supervisor_c_lac, p_supervisor_c_rac,
  p_supervisor_c_l5, p_supervisor_c_l, p_supervisor_c_l4, p_supervisor_c_l2,
  p_supervisor_c_l3, p_supervisor_c_l1, _out->supervisor_c_rac,
  _out->supervisor_c_l5, _out->supervisor_c_l, _out->supervisor_c_l4,
  _out->supervisor_c_l2, _out->supervisor_c_l3, _out->supervisor_c_l1,
  &Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st);
  _out->supervisor_c_lac = Supervisor_controller__supervisor_controller_supervisor_c_lac_out_st.supervisor_c_lac;
  Supervisor_controller__supervisor_controller_supervisor_c2_rac_step(
  supervisor_presence, supervisor_turn_on_l1, supervisor_turn_on_l2,
  supervisor_turn_on_rl, supervisor_turn_on_l, supervisor_turn_on_rac,
  supervisor_turn_on_lac, supervisor_turn_on_tv, supervisor_turn_on_wm,
  supervisor_do_open, supervisor_ck_1, supervisor_pnr_9, supervisor_ck_10_1,
  supervisor_pnr_8, supervisor_ck_12_1, supervisor_pnr_7, supervisor_ck_14_1,
  supervisor_pnr_6, supervisor_ck_16_1, supervisor_pnr_5, supervisor_ck_18_1,
  supervisor_pnr_4, supervisor_ck_20_1, supervisor_pnr_3, supervisor_ck_22_1,
  supervisor_pnr_2, supervisor_v_128, supervisor_v_127, supervisor_pnr_1,
  supervisor_v_112, supervisor_v_111, supervisor_pnr, p_supervisor_c2_lac,
  p_supervisor_c2_rac, p_supervisor_c_lac, p_supervisor_c_rac,
  p_supervisor_c_l5, p_supervisor_c_l, p_supervisor_c_l4, p_supervisor_c_l2,
  p_supervisor_c_l3, p_supervisor_c_l1, _out->supervisor_c_lac,
  _out->supervisor_c_rac, _out->supervisor_c_l5, _out->supervisor_c_l,
  _out->supervisor_c_l4, _out->supervisor_c_l2, _out->supervisor_c_l3,
  _out->supervisor_c_l1,
  &Supervisor_controller__supervisor_controller_supervisor_c2_rac_out_st);
  _out->supervisor_c2_rac = Supervisor_controller__supervisor_controller_supervisor_c2_rac_out_st.supervisor_c2_rac;
  Supervisor_controller__supervisor_controller_supervisor_c2_lac_step(
  supervisor_presence, supervisor_turn_on_l1, supervisor_turn_on_l2,
  supervisor_turn_on_rl, supervisor_turn_on_l, supervisor_turn_on_rac,
  supervisor_turn_on_lac, supervisor_turn_on_tv, supervisor_turn_on_wm,
  supervisor_do_open, supervisor_ck_1, supervisor_pnr_9, supervisor_ck_10_1,
  supervisor_pnr_8, supervisor_ck_12_1, supervisor_pnr_7, supervisor_ck_14_1,
  supervisor_pnr_6, supervisor_ck_16_1, supervisor_pnr_5, supervisor_ck_18_1,
  supervisor_pnr_4, supervisor_ck_20_1, supervisor_pnr_3, supervisor_ck_22_1,
  supervisor_pnr_2, supervisor_v_128, supervisor_v_127, supervisor_pnr_1,
  supervisor_v_112, supervisor_v_111, supervisor_pnr, p_supervisor_c2_lac,
  p_supervisor_c2_rac, p_supervisor_c_lac, p_supervisor_c_rac,
  p_supervisor_c_l5, p_supervisor_c_l, p_supervisor_c_l4, p_supervisor_c_l2,
  p_supervisor_c_l3, p_supervisor_c_l1, _out->supervisor_c2_rac,
  _out->supervisor_c_lac, _out->supervisor_c_rac, _out->supervisor_c_l5,
  _out->supervisor_c_l, _out->supervisor_c_l4, _out->supervisor_c_l2,
  _out->supervisor_c_l3, _out->supervisor_c_l1,
  &Supervisor_controller__supervisor_controller_supervisor_c2_lac_out_st);
  _out->supervisor_c2_lac = Supervisor_controller__supervisor_controller_supervisor_c2_lac_out_st.supervisor_c2_lac;
}


/* --- Generated the 18/7/2018 at 10:33 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s supervisor project.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "project_types.h"

Project__st_18 Project__st_18_of_string(char* s) {
  if ((strcmp(s, "St_18_Occupied")==0)) {
    return Project__St_18_Occupied;
  };
  if ((strcmp(s, "St_18_Empty")==0)) {
    return Project__St_18_Empty;
  };
}

char* string_of_Project__st_18(Project__st_18 x, char* buf) {
  switch (x) {
    case Project__St_18_Occupied:
      strcpy(buf, "St_18_Occupied");
      break;
    case Project__St_18_Empty:
      strcpy(buf, "St_18_Empty");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_17 Project__st_17_of_string(char* s) {
  if ((strcmp(s, "St_17_On")==0)) {
    return Project__St_17_On;
  };
  if ((strcmp(s, "St_17_Off")==0)) {
    return Project__St_17_Off;
  };
}

char* string_of_Project__st_17(Project__st_17 x, char* buf) {
  switch (x) {
    case Project__St_17_On:
      strcpy(buf, "St_17_On");
      break;
    case Project__St_17_Off:
      strcpy(buf, "St_17_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_16 Project__st_16_of_string(char* s) {
  if ((strcmp(s, "St_16_On")==0)) {
    return Project__St_16_On;
  };
  if ((strcmp(s, "St_16_Off")==0)) {
    return Project__St_16_Off;
  };
}

char* string_of_Project__st_16(Project__st_16 x, char* buf) {
  switch (x) {
    case Project__St_16_On:
      strcpy(buf, "St_16_On");
      break;
    case Project__St_16_Off:
      strcpy(buf, "St_16_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_15 Project__st_15_of_string(char* s) {
  if ((strcmp(s, "St_15_On")==0)) {
    return Project__St_15_On;
  };
  if ((strcmp(s, "St_15_Off")==0)) {
    return Project__St_15_Off;
  };
}

char* string_of_Project__st_15(Project__st_15 x, char* buf) {
  switch (x) {
    case Project__St_15_On:
      strcpy(buf, "St_15_On");
      break;
    case Project__St_15_Off:
      strcpy(buf, "St_15_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_14 Project__st_14_of_string(char* s) {
  if ((strcmp(s, "St_14_On")==0)) {
    return Project__St_14_On;
  };
  if ((strcmp(s, "St_14_Off")==0)) {
    return Project__St_14_Off;
  };
}

char* string_of_Project__st_14(Project__st_14 x, char* buf) {
  switch (x) {
    case Project__St_14_On:
      strcpy(buf, "St_14_On");
      break;
    case Project__St_14_Off:
      strcpy(buf, "St_14_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_13 Project__st_13_of_string(char* s) {
  if ((strcmp(s, "St_13_On")==0)) {
    return Project__St_13_On;
  };
  if ((strcmp(s, "St_13_Off")==0)) {
    return Project__St_13_Off;
  };
}

char* string_of_Project__st_13(Project__st_13 x, char* buf) {
  switch (x) {
    case Project__St_13_On:
      strcpy(buf, "St_13_On");
      break;
    case Project__St_13_Off:
      strcpy(buf, "St_13_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_12 Project__st_12_of_string(char* s) {
  if ((strcmp(s, "St_12_Washing")==0)) {
    return Project__St_12_Washing;
  };
  if ((strcmp(s, "St_12_Off")==0)) {
    return Project__St_12_Off;
  };
}

char* string_of_Project__st_12(Project__st_12 x, char* buf) {
  switch (x) {
    case Project__St_12_Washing:
      strcpy(buf, "St_12_Washing");
      break;
    case Project__St_12_Off:
      strcpy(buf, "St_12_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_11 Project__st_11_of_string(char* s) {
  if ((strcmp(s, "St_11_Opened")==0)) {
    return Project__St_11_Opened;
  };
  if ((strcmp(s, "St_11_Closed")==0)) {
    return Project__St_11_Closed;
  };
}

char* string_of_Project__st_11(Project__st_11 x, char* buf) {
  switch (x) {
    case Project__St_11_Opened:
      strcpy(buf, "St_11_Opened");
      break;
    case Project__St_11_Closed:
      strcpy(buf, "St_11_Closed");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_10 Project__st_10_of_string(char* s) {
  if ((strcmp(s, "St_10_Wait")==0)) {
    return Project__St_10_Wait;
  };
  if ((strcmp(s, "St_10_On")==0)) {
    return Project__St_10_On;
  };
  if ((strcmp(s, "St_10_Off")==0)) {
    return Project__St_10_Off;
  };
}

char* string_of_Project__st_10(Project__st_10 x, char* buf) {
  switch (x) {
    case Project__St_10_Wait:
      strcpy(buf, "St_10_Wait");
      break;
    case Project__St_10_On:
      strcpy(buf, "St_10_On");
      break;
    case Project__St_10_Off:
      strcpy(buf, "St_10_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_9 Project__st_9_of_string(char* s) {
  if ((strcmp(s, "St_9_Wait")==0)) {
    return Project__St_9_Wait;
  };
  if ((strcmp(s, "St_9_On")==0)) {
    return Project__St_9_On;
  };
  if ((strcmp(s, "St_9_Off")==0)) {
    return Project__St_9_Off;
  };
}

char* string_of_Project__st_9(Project__st_9 x, char* buf) {
  switch (x) {
    case Project__St_9_Wait:
      strcpy(buf, "St_9_Wait");
      break;
    case Project__St_9_On:
      strcpy(buf, "St_9_On");
      break;
    case Project__St_9_Off:
      strcpy(buf, "St_9_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_8 Project__st_8_of_string(char* s) {
  if ((strcmp(s, "St_8_Opened")==0)) {
    return Project__St_8_Opened;
  };
  if ((strcmp(s, "St_8_Closed")==0)) {
    return Project__St_8_Closed;
  };
}

char* string_of_Project__st_8(Project__st_8 x, char* buf) {
  switch (x) {
    case Project__St_8_Opened:
      strcpy(buf, "St_8_Opened");
      break;
    case Project__St_8_Closed:
      strcpy(buf, "St_8_Closed");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_7 Project__st_7_of_string(char* s) {
  if ((strcmp(s, "St_7_Washing")==0)) {
    return Project__St_7_Washing;
  };
  if ((strcmp(s, "St_7_Off")==0)) {
    return Project__St_7_Off;
  };
}

char* string_of_Project__st_7(Project__st_7 x, char* buf) {
  switch (x) {
    case Project__St_7_Washing:
      strcpy(buf, "St_7_Washing");
      break;
    case Project__St_7_Off:
      strcpy(buf, "St_7_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_6 Project__st_6_of_string(char* s) {
  if ((strcmp(s, "St_6_On")==0)) {
    return Project__St_6_On;
  };
  if ((strcmp(s, "St_6_Off")==0)) {
    return Project__St_6_Off;
  };
}

char* string_of_Project__st_6(Project__st_6 x, char* buf) {
  switch (x) {
    case Project__St_6_On:
      strcpy(buf, "St_6_On");
      break;
    case Project__St_6_Off:
      strcpy(buf, "St_6_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_5 Project__st_5_of_string(char* s) {
  if ((strcmp(s, "St_5_Wait")==0)) {
    return Project__St_5_Wait;
  };
  if ((strcmp(s, "St_5_On")==0)) {
    return Project__St_5_On;
  };
  if ((strcmp(s, "St_5_Off")==0)) {
    return Project__St_5_Off;
  };
}

char* string_of_Project__st_5(Project__st_5 x, char* buf) {
  switch (x) {
    case Project__St_5_Wait:
      strcpy(buf, "St_5_Wait");
      break;
    case Project__St_5_On:
      strcpy(buf, "St_5_On");
      break;
    case Project__St_5_Off:
      strcpy(buf, "St_5_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_4 Project__st_4_of_string(char* s) {
  if ((strcmp(s, "St_4_Wait")==0)) {
    return Project__St_4_Wait;
  };
  if ((strcmp(s, "St_4_On")==0)) {
    return Project__St_4_On;
  };
  if ((strcmp(s, "St_4_Off")==0)) {
    return Project__St_4_Off;
  };
}

char* string_of_Project__st_4(Project__st_4 x, char* buf) {
  switch (x) {
    case Project__St_4_Wait:
      strcpy(buf, "St_4_Wait");
      break;
    case Project__St_4_On:
      strcpy(buf, "St_4_On");
      break;
    case Project__St_4_Off:
      strcpy(buf, "St_4_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_3 Project__st_3_of_string(char* s) {
  if ((strcmp(s, "St_3_On")==0)) {
    return Project__St_3_On;
  };
  if ((strcmp(s, "St_3_Off")==0)) {
    return Project__St_3_Off;
  };
}

char* string_of_Project__st_3(Project__st_3 x, char* buf) {
  switch (x) {
    case Project__St_3_On:
      strcpy(buf, "St_3_On");
      break;
    case Project__St_3_Off:
      strcpy(buf, "St_3_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_2 Project__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_On")==0)) {
    return Project__St_2_On;
  };
  if ((strcmp(s, "St_2_Off")==0)) {
    return Project__St_2_Off;
  };
}

char* string_of_Project__st_2(Project__st_2 x, char* buf) {
  switch (x) {
    case Project__St_2_On:
      strcpy(buf, "St_2_On");
      break;
    case Project__St_2_Off:
      strcpy(buf, "St_2_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st_1 Project__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_On")==0)) {
    return Project__St_1_On;
  };
  if ((strcmp(s, "St_1_Off")==0)) {
    return Project__St_1_Off;
  };
}

char* string_of_Project__st_1(Project__st_1 x, char* buf) {
  switch (x) {
    case Project__St_1_On:
      strcpy(buf, "St_1_On");
      break;
    case Project__St_1_Off:
      strcpy(buf, "St_1_Off");
      break;
    default:
      break;
  };
  return buf;
}

Project__st Project__st_of_string(char* s) {
  if ((strcmp(s, "St_Occupied")==0)) {
    return Project__St_Occupied;
  };
  if ((strcmp(s, "St_Empty")==0)) {
    return Project__St_Empty;
  };
}

char* string_of_Project__st(Project__st x, char* buf) {
  switch (x) {
    case Project__St_Occupied:
      strcpy(buf, "St_Occupied");
      break;
    case Project__St_Empty:
      strcpy(buf, "St_Empty");
      break;
    default:
      break;
  };
  return buf;
}


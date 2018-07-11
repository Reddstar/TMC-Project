/* --- Generated the 11/7/2018 at 10:53 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s supervisor project.ept --- */

#ifndef PROJECT_TYPES_H
#define PROJECT_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "supervisor_controller.h"
typedef enum {
  Project__St_18_Occupied,
  Project__St_18_Empty
} Project__st_18;

Project__st_18 Project__st_18_of_string(char* s);

char* string_of_Project__st_18(Project__st_18 x, char* buf);

typedef enum {
  Project__St_17_On,
  Project__St_17_Off
} Project__st_17;

Project__st_17 Project__st_17_of_string(char* s);

char* string_of_Project__st_17(Project__st_17 x, char* buf);

typedef enum {
  Project__St_16_On,
  Project__St_16_Off
} Project__st_16;

Project__st_16 Project__st_16_of_string(char* s);

char* string_of_Project__st_16(Project__st_16 x, char* buf);

typedef enum {
  Project__St_15_On,
  Project__St_15_Off
} Project__st_15;

Project__st_15 Project__st_15_of_string(char* s);

char* string_of_Project__st_15(Project__st_15 x, char* buf);

typedef enum {
  Project__St_14_On,
  Project__St_14_Off
} Project__st_14;

Project__st_14 Project__st_14_of_string(char* s);

char* string_of_Project__st_14(Project__st_14 x, char* buf);

typedef enum {
  Project__St_13_On,
  Project__St_13_Off
} Project__st_13;

Project__st_13 Project__st_13_of_string(char* s);

char* string_of_Project__st_13(Project__st_13 x, char* buf);

typedef enum {
  Project__St_12_Washing,
  Project__St_12_Off
} Project__st_12;

Project__st_12 Project__st_12_of_string(char* s);

char* string_of_Project__st_12(Project__st_12 x, char* buf);

typedef enum {
  Project__St_11_Opened,
  Project__St_11_Closed
} Project__st_11;

Project__st_11 Project__st_11_of_string(char* s);

char* string_of_Project__st_11(Project__st_11 x, char* buf);

typedef enum {
  Project__St_10_Wait,
  Project__St_10_On,
  Project__St_10_Off
} Project__st_10;

Project__st_10 Project__st_10_of_string(char* s);

char* string_of_Project__st_10(Project__st_10 x, char* buf);

typedef enum {
  Project__St_9_Wait,
  Project__St_9_On,
  Project__St_9_Off
} Project__st_9;

Project__st_9 Project__st_9_of_string(char* s);

char* string_of_Project__st_9(Project__st_9 x, char* buf);

typedef enum {
  Project__St_8_Opened,
  Project__St_8_Closed
} Project__st_8;

Project__st_8 Project__st_8_of_string(char* s);

char* string_of_Project__st_8(Project__st_8 x, char* buf);

typedef enum {
  Project__St_7_Washing,
  Project__St_7_Off
} Project__st_7;

Project__st_7 Project__st_7_of_string(char* s);

char* string_of_Project__st_7(Project__st_7 x, char* buf);

typedef enum {
  Project__St_6_On,
  Project__St_6_Off
} Project__st_6;

Project__st_6 Project__st_6_of_string(char* s);

char* string_of_Project__st_6(Project__st_6 x, char* buf);

typedef enum {
  Project__St_5_Wait,
  Project__St_5_On,
  Project__St_5_Off
} Project__st_5;

Project__st_5 Project__st_5_of_string(char* s);

char* string_of_Project__st_5(Project__st_5 x, char* buf);

typedef enum {
  Project__St_4_Wait,
  Project__St_4_On,
  Project__St_4_Off
} Project__st_4;

Project__st_4 Project__st_4_of_string(char* s);

char* string_of_Project__st_4(Project__st_4 x, char* buf);

typedef enum {
  Project__St_3_On,
  Project__St_3_Off
} Project__st_3;

Project__st_3 Project__st_3_of_string(char* s);

char* string_of_Project__st_3(Project__st_3 x, char* buf);

typedef enum {
  Project__St_2_On,
  Project__St_2_Off
} Project__st_2;

Project__st_2 Project__st_2_of_string(char* s);

char* string_of_Project__st_2(Project__st_2 x, char* buf);

typedef enum {
  Project__St_1_On,
  Project__St_1_Off
} Project__st_1;

Project__st_1 Project__st_1_of_string(char* s);

char* string_of_Project__st_1(Project__st_1 x, char* buf);

typedef enum {
  Project__St_Occupied,
  Project__St_Empty
} Project__st;

Project__st Project__st_of_string(char* s);

char* string_of_Project__st(Project__st x, char* buf);

#endif // PROJECT_TYPES_H

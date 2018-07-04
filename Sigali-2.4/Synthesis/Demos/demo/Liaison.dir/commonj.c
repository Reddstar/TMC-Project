#include "ansi.h"
#include "commonj_e.h" 

#define NUL_CODE 0
#define EXP_CODE 1
#define LIN_CODE 2

typedef int Widget;
typedef int GC;

struct rhythm_descr {
/*     ------------*/
Widget discount;
GC dgc;
int dgchi,dgcwi,x,y;
boolean vupdown; 
int vcode;
};

extern boolean RUPDOWN(int *w_pt)
/********************** Called by the SIGNAL program to get indicator*/
{
  long int off4;
  struct rhythm_descr *widgst_pt;

  widgst_pt = (struct rhythm_descr *)w_pt;
  off4 = (*widgst_pt).vupdown;
  return(off4);
}

extern int RCHANGE(int *w_pt)
/********************* Called by the SIGNAL program to get event*/
{
  long int off4;
  struct rhythm_descr *widgst_pt;

  widgst_pt = (struct rhythm_descr *)w_pt;
  off4 =(*widgst_pt).vcode;
  (*widgst_pt).vcode = NUL_CODE;
  return(off4);
}


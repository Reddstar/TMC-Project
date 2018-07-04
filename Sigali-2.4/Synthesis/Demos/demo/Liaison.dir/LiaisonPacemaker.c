#include <jni.h>
#include <iostream.h> /**** test test test test test test test ****/
#include "ansi.h"
#include "LiaisonPacemaker.h"
#include "commonj.c"   
#include "LiaisonPacemaker_e.h"
boolean vstop=FALSE;
boolean vauto=FALSE;
boolean vtick=FALSE;

struct rhythm_descr pace_count;

JNIEXPORT void JNICALL Java_LiaisonPacemaker_n_1inter_1pace_1up_1p
    (JNIEnv *env, jobject obj){
    (pace_count).vupdown = TRUE;
    (pace_count).vcode   = LIN_CODE;
}


JNIEXPORT void JNICALL Java_LiaisonPacemaker_n_1inter_1pace_1down_1p
    (JNIEnv *env, jobject obj){
    (pace_count).vupdown = FALSE;
    (pace_count).vcode   = LIN_CODE;
}

JNIEXPORT void JNICALL Java_LiaisonPacemaker_n_1inter_1pace_1up_1m
    (JNIEnv *env, jobject obj){
    (pace_count).vupdown = TRUE;
    (pace_count).vcode   = EXP_CODE;
}

JNIEXPORT void JNICALL Java_LiaisonPacemaker_n_1inter_1pace_1down_1m
    (JNIEnv *env, jobject obj){
    (pace_count).vupdown = FALSE;
    (pace_count).vcode   = EXP_CODE;
}

JNIEXPORT void JNICALL Java_LiaisonPacemaker_n_1inter_1auto
    (JNIEnv *env, jobject obj){
    vauto = TRUE;
    vstop = FALSE;
    vtick = FALSE;
}

JNIEXPORT void JNICALL Java_LiaisonPacemaker_n_1inter_1stop
    (JNIEnv *env, jobject obj){
    vstop = TRUE;
}

JNIEXPORT void JNICALL Java_LiaisonPacemaker_n_1inter_1tick
    (JNIEnv *env, jobject obj){
    vtick = TRUE;

}


extern boolean RAUTO(void)
/*********** Called by the SIGNAL program 
             to get switching auto events */
{
  long int off4;
  off4 = vauto;
  vauto = FALSE;
  return(off4);
}

extern boolean RSTOP(void)
/*********** Called by the SIGNAL program 
             to get stop events */
{
  long int off4;
  off4 = vstop;
  vstop = FALSE;
  return(off4);
}

extern boolean RTICK(void)
/*********** Called by the SIGNAL program 
             to get manual ticks */
{
  long int off4;
  off4 = vtick;
  vtick = FALSE;
  return(off4);
}

/*
|-------------------|
| DISPLAYING RHYTHM |
|-------------------|
*/

#define PACE_PI_0 4      /* Initial period */
#define SCALEXWIWRITE 2
#define SCALEYWIWRITE 15 

extern void GET_PACE_RHYTHM(int **descr,int * pi_0)
/************************* Starting function called by the SIGNAL program */
{ 
  /* make_display_scale((int *)&pace_count,SCALEXWIWRITE,SCALEYWIWRITE); */
  *descr= (int *)&pace_count;
  *pi_0= PACE_PI_0;
}

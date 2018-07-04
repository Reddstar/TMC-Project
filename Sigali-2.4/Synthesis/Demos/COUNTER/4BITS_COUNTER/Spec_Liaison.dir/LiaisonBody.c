#include <jni.h>
#include <sys/types.h>
#include "iostream.h"
#include "ansi.h"
#include "LiaisonBody.h"
#include "LiaisonBody_e.h"

EXTERN int vt_initialize(void); /*definie dans vt_body.c */
EXTERN int vt_iterate(void);    /*definie dans vt_body.c */

JNIEnv *env_appel_vt;
jobject obj_appel_vt;
jclass cls;
jmethodID mid_wstop;  /* identifie la methode wstop */
jmethodID mid_dca1;   /* identifie la methode dessine_chat */
jmethodID mid_dca2;   /* identifie la methode dessine_souris */ 
jmethodID mid_dca3;   /* identifie la methode dessine_porte_chat */ 
jmethodID mid_dca4;   /* identifie la methode dessine_porte_souris */
jmethodID mid_ac;     /* identifie la methode Draw_Conflict */
jmethodID mid_rp;     /* identifie la methode reset_panel */
jmethodID mid_resolv; /* identifie la methode resolveur */
jmethodID mid_ev;     /* identifie la methode ecritVitesse */

int nb_etat, nb_cond, nb_ent_cont, nb_ent_incont;


JNIEXPORT void JNICALL Java_LiaisonBody_connexionBody
    (JNIEnv *env, jobject obj){
    cls=env->GetObjectClass(obj);
    env_appel_vt=env;
    obj_appel_vt=obj;

    mid_dca2=env->GetMethodID(cls,"Draw","(ZZZZZ)V");
    if (mid_dca2 == 0) {cout << "GetMethodID a echoue avec Draw \n";}; 


    mid_wstop=env->GetMethodID(cls,"wstop","()V");
    if (mid_wstop == 0) {cout << "GetStaticMethodID a echoue avec wstop \n";};

    mid_rp=env->GetMethodID(cls,"reset_panel","(Z)V");
    if (mid_rp == 0) {cout << "GetMethodID a echoue avec reset_panel \n";};

    mid_resolv=env->GetMethodID(cls,"resolver","([I[I[I[I[Z)V");
    if (mid_resolv == 0) {cout << "GetMethodID a echoue avec resolver \n";};

    mid_ev=env->GetMethodID(cls,"ecritVitesse","(I)V");
    if (mid_ev == 0) {cout << "GetMethodID a echoue avec ecritVitesse \n";};

}

JNIEXPORT void JNICALL Java_LiaisonBody_n_1set_1variable
    (JNIEnv *env, jobject obj, jint nbEtat, jint nbCond, jint nbEntCont , jint nbEntIncont ){
    nb_etat = (int) nbEtat;
    nb_cond = (int) nbCond;
    nb_ent_cont = (int) nbEntCont; 
    nb_ent_incont = (int) nbEntIncont;
}

JNIEXPORT jboolean JNICALL Java_LiaisonBody_n_1vt_1initialise
    (JNIEnv *env, jobject obj){
    return (jboolean) vt_initialize();
}

JNIEXPORT jboolean JNICALL Java_LiaisonBody_n_1vt_1iterate
    (JNIEnv *env, jobject obj){
    return (jboolean) vt_iterate();
}

extern void WSTOP(long int *b){
    env_appel_vt->CallVoidMethod(obj_appel_vt,mid_wstop);
}


extern void Draw_Conflict(int Conflict)
{ 
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_ac,Conflict); 
}

/* Lecture de l'horloge */
extern boolean r_vt_HE(int  *h1){ 
    *h1 = TRUE; 
   return TRUE; 
} 

extern void RESET_PANEL(boolean cauto){
    jboolean bool_auto = (cauto==TRUE);
    env_appel_vt->CallVoidMethod(obj_appel_vt,mid_rp,bool_auto); 
}


/*------------------ write an integer number */
/* Dans la version original (C++/Motif), */
/* cette procedure etait dans common.c */
/* elle permetait d'afficher un nombre */
/* dans un widget passe en parametre. */
/* Pour simplifier, et etant donne que */
/* vt_body n'utilise cette fonction que */
/* pour ecrire la vitesse dans le pacemaker, */
/* on ne va pas utiliser le pointeur sur le widget. */
extern void WIWRITE(int *w_pt, int v){
    env_appel_vt->CallVoidMethod(obj_appel_vt,mid_ev,v);
}


extern void Draw(boolean b1, boolean  b2, boolean  b3, boolean b4, boolean b5)
{
  env_appel_vt->CallVoidMethod(obj_appel_vt, mid_dca2, b1, b2, b3, b4, b5);
}


extern void resolver(int cod_cond[], int cod_x[], int cod_u[],
			   int cod_y[], boolean *fin_resolver)
{
  int i;
  /* preparation des parametres */

  jint *tampon_cod_cond;
  tampon_cod_cond  = new jint[nb_cond];
  for (i=0; i<nb_cond; i++) tampon_cod_cond[i]=(jint)cod_cond[i];
  jintArray Cod_cond = env_appel_vt->NewIntArray(nb_cond);
  env_appel_vt->SetIntArrayRegion(Cod_cond,0,nb_cond,&*tampon_cod_cond);
  
  jint *tampon_cod_x;
  tampon_cod_x  = new jint[nb_etat];
  for ( i=0; i<nb_etat; i++) tampon_cod_x[i]=(jint)cod_x[i];
  jintArray Cod_x = env_appel_vt->NewIntArray(nb_etat);
  env_appel_vt->SetIntArrayRegion(Cod_x,0,nb_etat,&*tampon_cod_x);
  
  jint *tampon_cod_u;
  tampon_cod_u  = new jint[nb_ent_cont];
  for ( i=0; i<nb_ent_cont; i++) tampon_cod_u[i]=(jint)cod_u[i];
  jintArray Cod_u = env_appel_vt->NewIntArray(nb_ent_cont);
  env_appel_vt->SetIntArrayRegion(Cod_u,0,nb_ent_cont,&*tampon_cod_u);
  
  jint *tampon_cod_y;
  tampon_cod_y  = new jint[nb_ent_incont];

  for ( i=0; i<nb_ent_incont; i++) tampon_cod_y[i]=(jint)cod_y[i];
  jintArray Cod_y = env_appel_vt->NewIntArray(nb_ent_incont);
  env_appel_vt->SetIntArrayRegion(Cod_y,0,nb_ent_incont,&*tampon_cod_y);
  
  jboolean tampon_fin_r[1]; 
  tampon_fin_r[0]=(jboolean)*fin_resolver;
  jbooleanArray Fin_resolver = env_appel_vt->NewBooleanArray(1);
  env_appel_vt->SetBooleanArrayRegion(Fin_resolver,0,1,tampon_fin_r); 
  
  /* appel de la methode resolver ecrite en java */
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_resolv,Cod_cond,Cod_x,Cod_u,Cod_y,Fin_resolver);
  
  /* recuperation des valeurs */
  
  jint *t_cod_cond=env_appel_vt->GetIntArrayElements(Cod_cond,0);
  for ( i=0; i<nb_cond; i++) cod_cond[i]=(int)t_cod_cond[i];
  jint *t_cod_x=env_appel_vt->GetIntArrayElements(Cod_x,0);
  for ( i=0; i<nb_etat; i++) cod_x[i]=(int)t_cod_x[i];
  jint *t_cod_u=env_appel_vt->GetIntArrayElements(Cod_u,0);
  for ( i=0; i<nb_ent_cont; i++) cod_u[i]=(int)t_cod_u[i];
  jint *t_cod_y=env_appel_vt->GetIntArrayElements(Cod_y,0);
  for ( i=0; i<nb_ent_incont; i++) cod_y[i]=(int)t_cod_y[i];
  
  jboolean *fin_r=env_appel_vt->GetBooleanArrayElements(Fin_resolver,0);    
  *fin_resolver = (boolean)*fin_r;          
} 

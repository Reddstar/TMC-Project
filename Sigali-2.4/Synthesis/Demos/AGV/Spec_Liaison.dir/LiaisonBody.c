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
jmethodID mid_dca1;   /* identifie la methode dessine_chariot_agv1 */
jmethodID mid_dca2;   /* identifie la methode dessine_chariot_agv2 */
jmethodID mid_dca3;   /* identifie la methode dessine_chariot_agv3 */
jmethodID mid_dca4;   /* identifie la methode dessine_chariot_agv4 */
jmethodID mid_dca5;   /* identifie la methode dessine_chariot_agv5 */
jmethodID mid_dcw1;   /* identifie la methode dessine_chariot_wst1 */
jmethodID mid_dcw2;   /* identifie la methode dessine_chariot_wst2 */
jmethodID mid_dcw3;   /* identifie la methode dessine_chariot_wst3 */
jmethodID mid_dcw4;   /* identifie la methode dessine_chariot_wst4 */
jmethodID mid_dcw5;   /* identifie la methode dessine_chariot_wst5 */
jmethodID mid_ac;     /* identifie la methode affiche_conflit */
jmethodID mid_rp;     /* identifie la methode reset_panel */
jmethodID mid_resolv; /* identifie la methode resolveur */
jmethodID mid_ev;     /* identifie la methode ecritVitesse */

int nb_etat, nb_cond, nb_ent_cont, nb_ent_incont;


JNIEXPORT void JNICALL Java_LiaisonBody_connexionBody
    (JNIEnv *env, jobject obj){
    cls=env->GetObjectClass(obj);
    env_appel_vt=env;
    obj_appel_vt=obj;
    mid_wstop=env->GetMethodID(cls,"wstop","()V");
    if (mid_wstop == 0) {cout << "GetStaticMethodID a echoue avec wstop \n";};
    mid_dca1=env->GetMethodID(cls,"dessine_chariot_agv1","([I)V");
    if (mid_dca1 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_agv1 \n";};

    mid_dca2=env->GetMethodID(cls,"dessine_chariot_agv2","([I)V");
    if (mid_dca2 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_agv2 \n";};

    mid_dca3=env->GetMethodID(cls,"dessine_chariot_agv3","([I)V");
    if (mid_dca3 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_agv3 \n";};

    mid_dca4=env->GetMethodID(cls,"dessine_chariot_agv4","([I)V");
    if (mid_dca4 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_agv4 \n";};

    mid_dca5=env->GetMethodID(cls,"dessine_chariot_agv5","([I)V");
    if (mid_dca5 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_agv5 \n";};

    mid_dcw1=env->GetMethodID(cls,"dessine_chariot_wst1","([I)V");
    if (mid_dcw1 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_wst1 \n";};

    mid_dcw2=env->GetMethodID(cls,"dessine_chariot_wst2","([I)V");
    if (mid_dcw2 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_wst2 \n";};

    mid_dcw3=env->GetMethodID(cls,"dessine_chariot_wst3","([I)V");
    if (mid_dcw3 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_wst3 \n";};

    mid_dcw4=env->GetMethodID(cls,"dessine_chariot_wst4","([I)V");
    if (mid_dcw4 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_wst4 \n";};

    mid_dcw5=env->GetMethodID(cls,"dessine_chariot_wst5","([I)V");
    if (mid_dcw5 == 0) {cout << "GetMethodID a echoue avec dessine_chariot_wst5 \n";};

    mid_ac=env->GetMethodID(cls,"affiche_conflit","(IIII)V");
    if (mid_ac == 0) {cout << "GetMethodID a echoue avec affiche_conflit \n";};
    mid_rp=env->GetMethodID(cls,"reset_panel","(Z)V");
    if (mid_rp == 0) {cout << "GetMethodID a echoue avec reset_panel \n";};
    mid_resolv=env->GetMethodID(cls,"resolver","([I[I[I[I[Z)V");
    if (mid_resolv == 0) {cout << "GetMethodID a echoue avec resolver \n";};
    mid_ev=env->GetMethodID(cls,"ecritVitesse","(I)V");
    if (mid_ev == 0) {cout << "GetMethodID a echoue avec ecritVitesse \n";};
}

JNIEXPORT void JNICALL Java_LiaisonBody_n_1set_1variable
    (JNIEnv *env, jobject obj, jint nbEtat, jint nbCond, jint nbEntCont , jint nbEntIncont ){
  //   cout<<"Debut Java_LiaisonBody_n_1set_1variable "<<  endl;
    nb_etat = (int) nbEtat;
    nb_cond = (int) nbCond;
    nb_ent_cont = (int) nbEntCont;
    nb_ent_incont = (int) nbEntIncont;
  //    cout<<"Fin Java_LiaisonBody_n_1set_1variable "<<  endl;
}

JNIEXPORT jboolean JNICALL Java_LiaisonBody_n_1vt_1initialise
    (JNIEnv *env, jobject obj){
   //   cout<<"Debut Java_LiaisonBody_n_1vt_1initialise "<<  endl;
    return (jboolean) vt_initialize();
   //   cout<<"Fin Java_LiaisonBody_n_1vt_1initialise "<<  endl;
}

JNIEXPORT jboolean JNICALL Java_LiaisonBody_n_1vt_1iterate
    (JNIEnv *env, jobject obj){ 
    return (jboolean) vt_iterate(); 
}

extern void WSTOP(long int *b){
  //    cout<<"Debut WSTOP "<<  endl;
    env_appel_vt->CallVoidMethod(obj_appel_vt,mid_wstop);
   //   cout<<"Fin WSTOP "<<  endl;
}


extern void dessine_chariot_agv1(int Pos_AGV1[])
{
  const int taille = 7; /* taille du tableau Pos_AGV1 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_AGV1[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dca1,pos);
}


extern void dessine_chariot_agv2(int Pos_AGV2[])
{
  const int taille = 13; /* taille du tableau Pos_AGV2 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_AGV2[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dca2,pos);
}

extern void dessine_chariot_agv3(int Pos_AGV3[])
{
  const int taille = 7; /* taille du tableau Pos_AGV3 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_AGV3[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dca3,pos);
}

extern void dessine_chariot_agv4(int Pos_AGV4[])
{
  const int taille = 11; /* taille du tableau Pos_AGV4 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_AGV4[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dca4,pos);
}


extern void dessine_chariot_agv5(int Pos_AGV5[])
{

  const int taille = 9; /* taille du tableau Pos_AGV5 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_AGV5[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dca5,pos);
}

extern void dessine_chariot_wst1(int Pos_WST1[])
{
  const int taille = 5; /* taille du tableau Pos_WST1 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_WST1[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dcw1,pos);
}

extern void dessine_chariot_wst2(int Pos_WST2[])
{
  const int taille = 5; /* taille du tableau Pos_WST2 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_WST2[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dcw2,pos);
}

extern void dessine_chariot_wst3(int Pos_WST3[])
{
  const int taille = 5; /* taille du tableau Pos_WST3 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_WST3[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dcw3,pos);
}


extern void dessine_chariot_wst4(int Pos_WST4[])
{
  const int taille = 3; /* taille du tableau Pos_WST4 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_WST4[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dcw4,pos);
}


extern void dessine_chariot_wst5(int Pos_WST5[])
{
  const int taille = 7; /* taille du tableau Pos_WST5 */
  jint tampon[taille];
  for (int i=0; i<taille; i++) tampon[i]=(jint)Pos_WST5[i];
  jintArray pos = env_appel_vt->NewIntArray(taille);
  env_appel_vt->SetIntArrayRegion(pos,0,taille,&*tampon);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_dcw5,pos);
}


extern void affiche_conflit(int a, int b, int c, int d){ 
    env_appel_vt->CallVoidMethod(obj_appel_vt,mid_ac,a,b,c,d); 
}

/* Lecture de l'horloge */
extern boolean r_vt_HE(int  *h1)
{ 
  *h1 = TRUE; 
  return TRUE; 
} 

extern void RESET_PANEL(boolean cauto)
{
  jboolean bool_auto = (cauto==TRUE);
  env_appel_vt->CallVoidMethod(obj_appel_vt,mid_rp,bool_auto);
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

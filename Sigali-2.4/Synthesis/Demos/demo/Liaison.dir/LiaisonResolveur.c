#include <jni.h>
#include <iostream.h>
#include "LiaisonResolveur.h"
#include "resolveur.h"
#include "ansi.h"

typedef int boolean;
#define TRUE 1
#define FALSE 0

resolveur RR;   /* objet resolveur */

static char* copyString(const char *str, int size)
{
  char * c_name;
  int    i;
  c_name = new char[size+1];
  for (i =0; i < size; i++) c_name[i] = str[i];
  c_name[size] = '\0';
  return c_name;
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1chargement(JNIEnv *env, jobject obj, jstring file_name)
{
  /* Conversion de file_name qui est de type java String en chaine de caractere C++. */
    const char *str = (env)->GetStringUTFChars(file_name, 0);
    int size = (env)->GetStringUTFLength(file_name);
    char* name= copyString(str, size); 
    //    char name[size+1]; for (int i=0; i<size; i++) name[i]=str[i]; name[size]='\0';
    cout<<" Resolver loading ("<< name << ")" << endl;
    /* appel de la methode de RR correspondante */
    RR.chargement(name); 
    /* liberation de la memoire utilisee par la chaine de caractere C++. */
    (env)->ReleaseStringUTFChars(file_name, str);
    cout<<" End resolver loading "<<  endl;
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1raz
    (JNIEnv *env, jobject obj)
{
  RR.raz();
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1set_1config(JNIEnv *env, jobject obj, jint n)
{
  int n_c = (int) n;
  RR.set_config(n_c);
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1set_1etats(JNIEnv *env, jobject obj, jintArray etats, jint nb_etats)
{
  int i, nb_etats_c;
  // int etats_c[nb_etats_c]; 
  int *etats_c; 

  jint *body = (env)->GetIntArrayElements(etats,0); // pointeur sur le 1er element du tableau
  nb_etats_c = (int) nb_etats;
  etats_c = new int [nb_etats_c];
  for (i=0; i<nb_etats_c; i++) etats_c[i]=(int)body[i];
  RR.set_etats(etats_c,nb_etats_c);
  for (i=0; i<nb_etats_c; i++) body[i]=(jint)etats_c[i];
  (env)->ReleaseIntArrayElements(etats ,body, 0);  
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1set_1conditions(JNIEnv *env, jobject obj, jintArray conds, jint nb_conds)
{
  //  int conds_c[nb_conds_c];
  int *conds_c;
  int i;
  jint *body = (env)->GetIntArrayElements(conds,0);// pointeur sur le 1er element du tableau
  int nb_conds_c = (int) nb_conds;
  conds_c = new int [nb_conds_c];
  for (i=0; i<nb_conds_c; i++) conds_c[i]=(int)body[i];
  RR.set_conditions(conds_c,nb_conds_c);
  for (i=0; i<nb_conds_c; i++) body[i]=(jint)conds_c[i];
  (env)->ReleaseIntArrayElements(conds ,body, 0);
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1set_1une_1condition (JNIEnv *env, jobject obj, jint num_ext, jint val)
{
    int num_ext_c = (int) num_ext;
    int val_c =(int) val;
    RR.set_une_condition(num_ext_c,val_c);
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1set_1mesures    (JNIEnv *env, jobject obj, jintArray yyy, jint nb_yyy)
{
  //    int yyy_c[nb_yyy_c];
  int *yyy_c;
  int i;
  jint *body = (env)->GetIntArrayElements(yyy,0);// pointeur sur le 1er element du tableau
  int nb_yyy_c = (int) nb_yyy;
  yyy_c = new int[nb_yyy_c];
  for (i=0; i<nb_yyy_c; i++) yyy_c[i]=(int)body[i];
  RR.set_mesures(yyy_c,nb_yyy_c);
  for (i=0; i<nb_yyy_c; i++) body[i]=(jint)yyy_c[i];
  (env)->ReleaseIntArrayElements(yyy ,body, 0); 
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1set_1une_1incontrolable(JNIEnv *env, jobject obj, jint num_ext, jint val)
{
  int num_ext_c = (int) num_ext;
  int val_c =(int) val;
  RR.set_une_incontrolable(num_ext_c,val_c);
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1set_1inconnue(JNIEnv *env, jobject obj, jint num_ext, jint val)
{
  int num_ext_c = (int) num_ext;
  int val_c =(int) val;
  RR.set_inconnue(num_ext_c,val_c);
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1init_1resolution(JNIEnv *env, jobject obj)
{
  RR.init_resolution();
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1init_1resolution_1par_1defaut(JNIEnv *env, jobject obj)
{
  RR.init_resolution_par_defaut();
}

JNIEXPORT jboolean JNICALL Java_LiaisonResolveur_n_1get_1valperm(JNIEnv *env, jobject obj, jintArray sol, jint nb_sol)
{
  //int sol_c[nb_sol_c*3];
  int * sol_c;
  int i;

  jboolean resultat = false;
  jint *body = (env)->GetIntArrayElements(sol,0);// pointeur sur le 1er element du tableau
  int nb_sol_c = (int) nb_sol;
  sol_c = new int[nb_sol_c*3];
  for (i=0; i<nb_sol_c*3; i++) sol_c[i]=(int)body[i];
  resultat = (RR.get_valperm(sol_c,nb_sol_c)==TRUE);
  for (i=0; i<nb_sol_c*3; i++) body[i]=(jint)sol_c[i];
  (env)->ReleaseIntArrayElements(sol ,body, 0);  
  return resultat;
}

JNIEXPORT void JNICALL Java_LiaisonResolveur_n_1get_1solution(JNIEnv *env, jobject obj, jintArray sol, jint nb_sol)
{
  int * sol_c;
  // int sol_c[nb_sol_c*3];
  int i;

  jint *body = (env)->GetIntArrayElements(sol,0);// pointeur sur le 1er element du tableau
  int nb_sol_c = (int) nb_sol;

  sol_c = new int[nb_sol_c*3];
  for (i=0; i<nb_sol_c*3; i++) sol_c[i]=(int)body[i];
  RR.get_solution(sol_c,nb_sol_c);
  for (i=0; i<nb_sol_c*3; i++) body[i]=(jint)sol_c[i];
  (env)->ReleaseIntArrayElements(sol ,body, 0); 
}

/* tddint.h TDD definitions internes
================================== */


#if !defined(_TDDINTH)
#define _TDDINTH

#include <setjmp.h>
#include "tddresolv.h"

/* Index 
=========*/

typedef unsigned short tdd_index_type;


/* Type des champs d'un noeud tdd 
==================================*/

typedef unsigned short tdd_indexindex_type;
typedef unsigned char tdd_refcount_type;
typedef unsigned char tdd_mark_type;
typedef unsigned long  tdd_range;


/* Noeud TDD 
=============*/

struct tdd_
{ 
  struct tdd_ *next;            /* Chainage dans table */
  tdd_indexindex_type indexindex;
				/* Index de la variable */
  tdd_refcount_type refs;	/* Compteur de references externes */
  tdd_mark_type mark;		/* Marquage et references temporaires*/
  long data[3];			/* tableau des fils (pointeur)*/

 
};


/* Maxima des compteurs de references
=====================================*/

#define TDD_MAX_REFS ((tdd_refcount_type)((1l << (8*sizeof(tdd_refcount_type))) - 1))
#define TDD_MAX_TEMP_REFS ((tdd_mark_type)((1l << (8*sizeof(tdd_mark_type)-1)) - 1))

#define TDD_GC_MARK ((tdd_mark_type)(1l << (8*sizeof(tdd_mark_type)-1)))

/* Et voici l'infini
====================*/

/*#define ADD_INFTY ((1l << (8*sizeof(long)-1)))*/
#define ADD_INFTY 0x7FFFFFFFl

/* Indexindex et index particuliers 
===================================*/

#define TDD_CONST_INDEXINDEX 0
#define ADD_CONST_INDEXINDEX 1
#define TDD_MAX_INDEXINDEX ((tdd_indexindex_type)((1l << (8*sizeof(tdd_indexindex_type)-1)) - 1))
#define TDD_MAX_INDEX ((tdd_index_type)((1l << (8*sizeof(tdd_index_type)-1)) - 2))
				/* le bit le plus faible sert a typer le noeud */
#define ADD_TYPE_MASK (1l << (8*sizeof(tdd_index_type)-1))
#define TDD_TYPE 0
#define ADD_TYPE 1

/* Acces aux champs d'un noeud TDD
===================================*/

  /* acces aux champs */
#define TDD_INDEXINDEX(f) ((f->indexindex) >> 1)
#define TADD_TYPE(f) ((f->indexindex) & 0x1)
#define TDD_DATA(f) (f->data)
#define TDD_DATAI(f,i) (f->data[i])

#define TDD_REFS(f) (f->refs)
#define TDD_MARK(f) (f->mark)
#define TDD_TEMP_REFS(f) (f->mark)

#define SET_ADD_TYPE(f) ((f->indexindex) = ((f->indexindex) | 0x1))

/* acces de base pour index ... et test elementaires 
===================================================*/

#define TDD_INDEX(tddm, f) ((tddm)->indexes[TDD_INDEXINDEX(f)])
#define TDD_P0(f) ((tdd)(TDD_DATAI(f,0)))
#define TDD_P1(f) ((tdd)(TDD_DATAI(f,1)))
#define TDD_PM1(f) ((tdd)(TDD_DATAI(f,2)))
#define TDD_IS_CONST(f) (TDD_INDEXINDEX(f) == TDD_CONST_INDEXINDEX)
#define ADD_IS_CONST(f) (TDD_INDEXINDEX(f) == ADD_CONST_INDEXINDEX)
#define TADD_IS_CONST(f)(TDD_IS_CONST(f) || ADD_IS_CONST(f))

/* Variable (index) de la racine
===============================*/

#define TDD_ROOTVAR(tddm, f) ((tddm)->variables[TDD_INDEXINDEX(f)])

/* Macros pour definitions des pas de recurrence
===============================================*/
#define TDD_TOP_VAR2(top_indexindex,tddm,f,g)\
do\
   if(TDD_INDEX(tddm,f)<TDD_INDEX(tddm,g))\
     top_indexindex = TDD_INDEXINDEX(f);\
   else\
     top_indexindex = TDD_INDEXINDEX(f);\
while(0)

#define TDD_TOP_VAR4(top_indexindex,tddm,f,g1,g2,g3)\
do\
{\
   if(TDD_INDEX(tddm,f)<TDD_INDEX(tddm,g1))\
     {\
      top_indexindex = TDD_INDEXINDEX(f);\
      if((tddm)->indexes[top_indexindex]>TDD_INDEX(tddm,g2))\
        {top_indexindex = TDD_INDEXINDEX(g2);\
         if((tddm)->indexes[top_indexindex]>TDD_INDEX(tddm,g3))\
            top_indexindex = TDD_INDEXINDEX(g3);\
        }\
        else\
	{\
         if((tddm)->indexes[top_indexindex]>TDD_INDEX(tddm,g3))\
            top_indexindex = TDD_INDEXINDEX(g3);\
        }\
     }\
   else\
     {\
      top_indexindex = TDD_INDEXINDEX(g1);\
      if((tddm)->indexes[top_indexindex]>TDD_INDEX(tddm,g2))\
        {top_indexindex = TDD_INDEXINDEX(g2);\
         if((tddm)->indexes[top_indexindex]>TDD_INDEX(tddm,g3))\
            top_indexindex = TDD_INDEXINDEX(g3);\
        }\
        else\
	{\
         if((tddm)->indexes[top_indexindex]>TDD_INDEX(tddm,g3))\
            top_indexindex = TDD_INDEXINDEX(g3);\
        }\
     }\
}\
while(0)

#define TDD_COFACTOR(top_indexindex,f,pf0,pf1,pfm1)\
do\
  if (TDD_INDEXINDEX(f) == top_indexindex)\
    {\
      pf0 = TDD_P0(f);\
      pf1 = TDD_P1(f);\
      pfm1 = TDD_PM1(f);\
    }\
  else\
    {\
      pf0 = f;\
      pf1 = f;\
      pfm1 = f;\
    }\
while(0)
/* Macros de manipulation des compteurs de references
=====================================================*/

#define TDD_INCREFS(f)\
do\
  {\
    if ((int)TDD_REFS(f) >= (int)TDD_MAX_REFS-1)\
      {\
	TDD_REFS(f)=TDD_MAX_REFS;\
	TDD_TEMP_REFS(f)=0;\
      }\
   else\
     TDD_REFS(f)++;\
  }\
while (0)

#define TDD_DECREFS(f)\
do\
  {\
    if ((int)TDD_REFS(f) < (int)TDD_MAX_REFS)\
      TDD_REFS(f)--;\
  }\
while (0)

#define TDD_TEMP_INCREFS(f)\
do\
  {\
    if ((int)TDD_REFS(f) < (int)TDD_MAX_REFS)\
      {\
	TDD_TEMP_REFS(f)++;\
	if (TDD_TEMP_REFS(f) == TDD_MAX_TEMP_REFS)\
	  {\
	    TDD_REFS(f)=TDD_MAX_REFS;\
	    TDD_TEMP_REFS(f)=0;\
	  }\
      }\
  }\
while (0)

#define TDD_TEMP_DECREFS(f)\
do\
  {\
    if ((int)TDD_REFS(f) < (int)TDD_MAX_REFS)\
      TDD_TEMP_REFS(f)--;\
  }\
while (0)

#define TDD_IS_USED(f) ((TDD_MARK(f) & TDD_GC_MARK) != 0)


/* Macros pour les constantes 
============================*/

#define TDD_ZERO(tddm) ((tddm)->zero)
#define TDD_ONE(tddm) ((tddm)->one)
#define TDD_MONE(tddm) ((tddm)->mone)
extern void tdd_reorder(iri_tdd_manager tddm);

/* Table associee a une variable
================================ */

struct var_table_
{
  tdd *table;			/* Tableau des buckets */
  int size_index;		/* Index du nombre de buckets */
  long size;			/* Nombre de buckets */
  long entries;			/* Nombre de noeuds dans la table */
};

typedef struct var_table_ *var_table;

/* Table des noeuds TDD 
=======================*/

struct unique_
{
  var_table *tables;		/* Tableau des tables par variables */
  long entries;			/* Nombre de noeuds TDD */
  long gc_limit;		/* Declenchement du GC */
  long node_limit;		/* Nombre maxi de noueds TDD autorise */
  long gcs;			/* Nombre de GC */
  long freed;			/* Nombre de noeuds liberes */
  long finds;			/* Nombre de noeuds trouves */
};

typedef struct unique_ unique;

/* Structures de donnees pour les associations
==============================================*/

struct var_assoc_
{
  tdd *assoc;			/* Tableau: indexindex -> TDD associe */
  tdd_index_type first;         /* Plus petit index des var. associées */
  tdd_index_type last;		/* Index de la variable la grande associee */
  int refs;			/* Compteur de references */
  struct var_assoc_ *next;	/* Pour gestion en liste chainee */
};


/* Structures de donnees pour le cache
======================================*/

/* Element du cache
===================*/
struct cache_entry_
{
  long opcode;  /* code de l'operation */
  unsigned char  com;        /* 0 si operateur non commutatif */
  unsigned char cache_type;  /* type permettant de selectionner les fonc. de controle */ 
  long slot1;    /* premier operande */
  long slot2;    /* second operande */
  long slot3;   /* resultat */ 
};

typedef struct cache_entry_ *cache_entry;

/* opcodes: operations unaires code inferieur a 100
==================================================*/
#define OPCODE_SUM     100
#define OPCODE_DIF     101
#define OPCODE_PROD    102
#define OPCODE_AND     103
#define OPCODE_OR      104
#define OPCODE_WHEN2   105
#define OPCODE_WHENOT2 106
#define OPCODE_DEFAULT 107
#define OPCODE_PROCOMP 108
#define OPCODE_SSQUARE 109
#define OPCODE_PSQUARE 110
#define OPCODE_EQUIV   111

#define OPCODE_CASE    10001
#define OPCODE_SUBST    1001

#define OPCODE_EXIST   20011
#define OPCODE_FORALL  20022

#define OP_NBSOL       20033

#define OP_COM    1
#define OP_NCOM   0
#define NOT_TDD   2

#define ADD_OPCODE_PLUS  30001  
#define ADD_OPCODE_MUL   30002
#define ADD_OPCODE_MIN   30003
#define ADD_OPCODE_MAX   30004
#define ADD_MARG_MIN     30100
#define ADD_MARG_MAX     30101
#define ADD_MARG_SUM     30102
#define ADD_MARG_PROD    30103
#define ADD_OPCODE_IMINV 30104
#define ADD_OPCODE_MAXIM 30105
#define ADD_OPCODE_MINIM 30106
#define ADD_OPCODE_C2R   30107 // added lbesnard
#define ADD_OPCODE_IMSUP 30108 // added lbesnard
#define ADD_OPCODE_IMINF 30109 // added lbesnard

/* Transformation en une reference externe
==========================================*/
#define RETURN_TDD(tddm,thing)			\
  return (tdd_make_external(tddm,thing))


#define CACHE_TYPE_UN     0
#define CACHE_TYPE_BIN    1

#define MIN_CACHE_TYPE    2
#define MAX_CACHE_TYPE    8

#define CACHE4_TYPE_CASE  0 // added lbesnard

#define MIN_CACHE4_TYPE   1 // added lbesnard
#define MAX_CACHE4_TYPE   8 // added lbesnard

#define MIN_OP_BIN 100
#define BIN_INDEX(p)((int)((p)-MIN_OP_BIN))

/* paire d'operations memorisees
================================*/
struct cache_bin_
{
  cache_entry entry[2];		/* Le dernier entre a pour index 1 */
};

typedef struct cache_bin_ cache_bin;

/* Le cache 
===========*/

struct cache_
{
  cache_bin *table;		/* Table des paires */
  int size_index;		/* Index donnant le nombre de paires */
  long size;			/* Nombre de paires memorisables */
  int cache_level;		/* Indicateur de la politique d'allocation */
				/* Fonctions de controle du cache */
  long (*rehash_fn[8]) (iri_tdd_manager, cache_entry);
				/* Fonctions de hashage pour rehash */
  int (*gc_fn[8]) (iri_tdd_manager, cache_entry);
				/* Fonction d'exploration pour GC */
  int cache_ratio;		/* Ratio taille table/ taille cache */
  long entries;			/* Nombre d'enregistrements */
  long lookups;			/* Nombre de consultations */
  long hits;			/* Nombre de consultations avec succes */
  long inserts;			/* Nombre d'insertions */
  long collisions;		/* Nombre de collisions */
};

typedef struct cache_ cache;

/* Constantes pour le gestionnaire de TDD 
=========================================*/

#define MIN_REC_SIZE ALLOC_ALIGNMENT
#define MAX_REC_SIZE 64

#define REC_MGRS (((MAX_REC_SIZE-MIN_REC_SIZE)/ALLOC_ALIGNMENT)+1)


/* Wrapper for jmp_buf since we may need to copy it sometimes and */
/* we can't easily do it if it happens to be an array. */

struct jump_buf_
{
  jmp_buf context;
};

typedef struct jump_buf_ jump_buf;


/* Gestionnaire de TDD
======================*/

struct tdd_manager_
{
  unique tdd_table;	      /* Table des noeuds                                     */

  tdd one;		      /* TDD 1                                                */
  tdd zero;		      /* TDD 0                                                */
  tdd mone;		      /* TDD -1                                               */
  tdd add_0;                  /* MODIF: ADD 0 , ADD 1 et l'infini                     */
  tdd add_1;
  tdd add_infty;
  long vars;		      /* Nombre de variables+1 i.e. dernier indexindex occupe */
  long maxvars;		      /* Maximum number of variables w/o resize               */
  tdd *variables;	      /* Tableau des TDD reduits a une variable par indexindex*/
  tdd_index_type *indexes;    /* Table de conversion indexindex -> index              */
  tdd_indexindex_type *indexindexes;
			      /* Table de conversion index -> indexindex              */
  cache op_cache;             /* Cache 3 slots pour la memorisation des operations    */
  var_assoc  assocs;	      /* Associations variables->TDD                          */
  int overflow;               /* indicateur d'overflow                                */
  jump_buf abort;             /* contexte utilise en cas de long jump                 */
  int check;                  /* compteur des verifications etat memoire              */
  int checkinfo;              /* emission d'infos sur la memoire                      */
  rec_mgr rms[REC_MGRS];      /* Gestionnaire d'enregistrements (gestion memoire)     */
};


/* Trucs pour recuperation d'echecs
==================================*/

#define TDD_ABORTED 1
#define TDD_OVERFLOWED 2
#define TDD_REORDERED 3


/* la macro suivante permet de definir un contexte de retour en cas d'echec
d'une operation (voir tdd_check par exemple). La restauration du contexte se 
fait apres nettoyage de tous les noeuds temporaires. */

#define FIREWALL(tddm)\
do\
  {\
    int retcode;\
    while ((retcode=(setjmp((tddm)->abort.context))))\
      {\
	tdd_clear_temps(tddm);\
	if (retcode == TDD_ABORTED || retcode == TDD_OVERFLOWED)\
	  return ((tdd)0);\
      }\
  }\
while (0)

#define FIREWALL1(tddm, cleanupcode)\
do\
  {\
    int retcode;\
    while ((retcode=(setjmp((tddm)->abort.context))))\
      {\
	tdd_clear_temps(tddm);\
	cleanupcode\
      }\
  }\
while (0)


/* Fonction de hash 
===================*/

#define HASH_NODE(f, g, h) (((f) << 2)+((g) << 1) + (h))


/* Dimensions de la table (puissance de 2 pour le moment)
========================================================*/

#define TABLE_SIZE(size_index) (1l << (size_index))
#define REDUCE(i, size) (i)&=(size)-1
/*
#define TABLE_SIZE(size_index) (tdd_primes[size_index])
#define REDUCE(i, size)\
do\
  {\
    (i)%=(size);\
    if ((i) < 0)\
      (i)= -(i);\
  }\
while (0)
*/

/* Structures pour le type table a clefs TDD 
============================================*/

struct hash_rec_
{
  tdd key;
  struct hash_rec_ *next;
};

typedef struct hash_rec_ *hash_rec;


struct hash_table_
{
  hash_rec *table;
  int size_index;
  long size;
  long entries;
  int item_size;
  iri_tdd_manager tddm;
};

/* Declaration du type table 
============================*/

typedef struct hash_table_ *hash_table;

/* Gestion des enregistrements: allocation et liberation d'un enregistrement TDD
================================================================================*/

#define TDD_NEW_REC(tddm, size) mem_new_rec((tddm)->rms[(ROUNDUP(size)-MIN_REC_SIZE)/ALLOC_ALIGNMENT])
#define TDD_FREE_REC(tddm, rec, size) mem_free_rec((tddm)->rms[(ROUNDUP(size)-MIN_REC_SIZE)/ALLOC_ALIGNMENT], (rec))



/* Fonctions d'acces a la table des noeuds 
==========================================*/
extern void iri_init_tdd_table(iri_tdd_manager);
extern void iri_free_tdd_table(iri_tdd_manager);
extern var_table tdd_new_var_table(iri_tdd_manager tddm);
extern void tdd_rehash_var_table(var_table table, int grow);
extern tdd  tdd_find_aux(iri_tdd_manager, tdd_indexindex_type, int, long, long, long);
extern tdd  tdd_find(iri_tdd_manager, tdd_indexindex_type, tdd, tdd, tdd);
extern tdd  tdd_find_const(iri_tdd_manager ,long);
extern void tdd_clear_temps(iri_tdd_manager tddm);
extern tdd  add_dieu(iri_tdd_manager);

/* Fonctions d'acces aux caches
==============================*/
extern void tdd_init_cache(iri_tdd_manager tddm);
extern void tdd_init_cache4(iri_tdd_manager tddm);
extern void tdd_insert_in_cache21(iri_tdd_manager tddm, 
                        long opcode,
                        char type,
                        char comut, 
                        long d1,
                        long d2,
                        long result);
extern int tdd_lookup_in_cache21(iri_tdd_manager tddm, 
                        long opcode,
                        long d1,
                        long d2,
                        long *result);
extern void tdd_insert_in_cache11(iri_tdd_manager tddm, 
                        long opcode,
                        char type,
                        long d1,
                        long result);
extern int tdd_lookup_in_cache11(iri_tdd_manager tddm, long opcode, long d1, long *result);
extern void tdd_insert_in_cache41(iri_tdd_manager tddm, long opcode, char type, long d1, long d2, long d3, long d4, long result);
extern int tdd_lookup_in_cache41(iri_tdd_manager tddm, long opcode, long d1, long d2, long d3, long d4, long *result);
extern void tdd_purge_cache(iri_tdd_manager tddm);
extern void tdd_purge_cache4(iri_tdd_manager tddm);
extern void tdd_flush_assoc(iri_tdd_manager tddm, var_assoc a);
extern void tdd_flush_all(iri_tdd_manager tddm);
extern void tdd_flush_all4(iri_tdd_manager tddm);
extern void tdd_rehash_cache(iri_tdd_manager tddm, int grow);
extern void tdd_rehash_cache4(iri_tdd_manager tddm, int grow);
extern void tdd_free_cache(iri_tdd_manager tddm);

/* Fonctions internes TDD
=========================*/
extern tdd tdd_make_external(iri_tdd_manager tddm, tdd f);
extern tdd tdd_identity(iri_tdd_manager tddm, tdd f);
extern tdd tdd_carre_int(iri_tdd_manager tddm, tdd p);
extern tdd tdd_case_step(iri_tdd_manager tddm, tdd f, tdd g1, tdd g2, tdd g3);
extern tdd tdd_oper2_step(iri_tdd_manager tddm, tdd f, tdd g, int *tabop2, int commut);
extern int *tdd_tabop2(long opcode);


/* Fonctions d'erreur 
=====================*/
extern void tdd_warning(char *message);
extern void tdd_fatal(char *message);

/* Acces au type table a clefs TDD 
==================================*/

extern void tdd_insert_in_hash_table(hash_table h, tdd f, pointer data);
extern pointer tdd_lookup_in_hash_table(hash_table h, tdd f);
extern hash_table tdd_new_hash_table(iri_tdd_manager tddm, int item_size);
extern void tdd_free_hash_table(hash_table h);


/* Fonctions diverses
=====================*/
extern int  tdd_type_aux(iri_tdd_manager tddm, tdd f);
extern int  tdd_check_arguments(int count, ...);
extern int  tdd_check_array(tdd *fs);
extern void tdd_mark_shared_nodes(iri_tdd_manager tddm, tdd f);
extern void tdd_number_shared_nodes(iri_tdd_manager tddm, tdd f, hash_table h, long *next);
extern void tdd_unmark_all_nodes(iri_tdd_manager tddm, tdd f);
extern char *tdd_terminal_id(iri_tdd_manager tddm, tdd f);
extern char *tdd_var_name(iri_tdd_manager tddm, tdd v, char *(*var_naming_fn)(iri_tdd_manager, tdd));
extern var_assoc tdd_rec_assoc(iri_tdd_manager tddm, var_assoc a);
extern int tdd_nb_assoc(iri_tdd_manager tddm, var_assoc a);

#endif

/* tdduser.h Interface utilisateur du module TDD 
===============================================*/


#if !defined(_TDDRESOLVH)
#define _TDDRESOLVH


#include <cstdio>
#include "memuser.h"
#include<fstream>
#include "integer.h"


/* Types */

typedef struct tdd_ *tdd;
typedef struct tdd_manager_  *iri_tdd_manager;
typedef struct var_assoc_ *var_assoc;
typedef unsigned char val_perm;

/* Valeurs pour les types de TDD
================================*/

#define TDD_TYPE_NONTERMINAL 0
#define TDD_TYPE_ZERO 1
#define TDD_TYPE_ONE 2
#define TDD_TYPE_MONE 3
#define TDD_TYPE_POSVAR 4
#define TDD_TYPE_NPOSVAR 5
#define TDD_TYPE_OVERFLOW 6
#define TDD_TYPE_CONSTANT 7

/* Codage des solutions 
=======================*/

#define NOVAL 0x0
#define VAL0  0x1
#define VAL1  0x2
#define VAL2  0x4
#define TOVAL 0x7

/*Codes d'erreur pour tdd_undump_tdd
====================================*/

#define TDD_UNDUMP_FORMAT 1
#define TDD_UNDUMP_OVERFLOW 2
#define TDD_UNDUMP_IOERROR 3
#define TDD_UNDUMP_EOF 4


/* Fonctions d'acces aux gestionnaires de TDD
=============================================*/
extern iri_tdd_manager iri_tdd_init (void);
extern void iri_tdd_quit( iri_tdd_manager );
extern integer tdd_man_nb_vars(iri_tdd_manager tddm);

/* Manipulation des compteurs de reference 
=========================================*/
extern void tdd_unfree(iri_tdd_manager tddm, tdd f);
extern void tdd_free(iri_tdd_manager tddm, tdd f);

/* Garbage collector
====================*/
extern void tdd_gc(iri_tdd_manager tddm);

/* Fonctions d'acces aux TDD  
============================*/
extern tdd tdd_new_var_last(iri_tdd_manager tddm);
extern tdd tdd_const(iri_tdd_manager tddm, integer val);
extern integer const_tdd(iri_tdd_manager tddm, tdd f);

/* operations sur tdd 
----------------------*/
extern tdd tdd_eval(iri_tdd_manager tddm, tdd g, var_assoc va);
extern tdd tdd_eval_un(iri_tdd_manager tddm, tdd g, integer index, integer val);

extern void tdd_solve(iri_tdd_manager tddm, tdd f, val_perm *vp, integer nbvar);

/* Gestion des associations
===========================*/
extern var_assoc tdd_new_assoc(iri_tdd_manager tddm, tdd *ass_inf, integer pairs);
extern void tdd_free_assoc(iri_tdd_manager tddm, var_assoc a);

/* Fonctions de chargement
==========================*/
extern tdd tdd_undump_tdd_re(iri_tdd_manager tddm, FILE *fp, integer *error);

#endif




/* tdduser.h Interface utilisateur du module TDD 
===============================================*/


#if !defined(_TDDUSERH)
#define _TDDUSERH


#include <cstdio>

#include "memuser.h"

/* Types */

typedef struct tdd_ *tdd;
typedef struct tdd_manager_  *iri_tdd_manager;
typedef struct var_assoc_ *var_assoc;

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
extern void tddman_set_reorder(iri_tdd_manager tddm, integer mode);
extern integer info_tdd_vars(iri_tdd_manager tddm);
extern integer info_tdd_total_size(iri_tdd_manager tddm);
extern integer infoset_tdd_node_limit(iri_tdd_manager tddm, integer new_limit);
extern integer  info_tdd_overflow(iri_tdd_manager tddm);
extern void tdd_stats_screen(iri_tdd_manager tddm);

/* Manipulation des compteurs de reference 
=========================================*/

extern void tdd_count_temps(iri_tdd_manager tddm);
extern integer tdd_extref(iri_tdd_manager tddm, tdd f);
extern void tdd_unfree(iri_tdd_manager tddm, tdd f);
extern void tdd_free(iri_tdd_manager tddm, tdd f);

/* Garbage collector
====================*/

extern void tdd_gc(iri_tdd_manager tddm);

/* Reordonnancement
====================*/

extern void tdd_exchange_test(iri_tdd_manager tddm, integer index);
extern void tdd_reorder(iri_tdd_manager tddm);

/* Fonctions d'acces aux TDD  
============================*/
extern tdd tdd_one(iri_tdd_manager);
extern tdd tdd_zero(iri_tdd_manager);
extern tdd tdd_mone(iri_tdd_manager tddm);
extern tdd tdd_new_var_first(iri_tdd_manager tddm);
extern tdd tdd_new_var_last(iri_tdd_manager tddm);
extern tdd tdd_new_var_before(iri_tdd_manager tddm, tdd var);
extern tdd tdd_new_var_after(iri_tdd_manager tddm, tdd var);
extern tdd tdd_var_with_index(iri_tdd_manager tddm, integer index);
extern tdd tdd_var_with_id(iri_tdd_manager tddm, integer n);

extern integer tdd_rootvar_index(iri_tdd_manager tddm, tdd f);
extern integer tdd_num( tdd f);

/* operations sur tdd 
----------------------*/
extern tdd tdd_oppose(iri_tdd_manager tddm, tdd p);
extern tdd tdd_carre(iri_tdd_manager tddm, tdd p);
extern tdd tdd_not(iri_tdd_manager tddm, tdd p);
extern tdd tdd_when(iri_tdd_manager tddm, tdd p);
extern tdd tdd_whenot(iri_tdd_manager tddm, tdd p);
extern tdd tdd_complement(iri_tdd_manager tddm, tdd p);

extern tdd tdd_sum(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_dif(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_prod(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_and(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_or(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_when2(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_whenot2(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_default(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_procomp(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_ssquare(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_psquare(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_equiv(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd tdd_case(iri_tdd_manager tddm, tdd f, tdd g1, tdd g2, tdd g3);

/* Substitutions et evaluations
==============================*/
extern tdd tdd_subst(iri_tdd_manager tddm, tdd g, var_assoc va);
extern tdd tdd_eval(iri_tdd_manager tddm, tdd g, var_assoc va);
extern tdd tdd_rename(iri_tdd_manager tddm, tdd g, var_assoc va);

/* Elimination des quantificateurs
================================*/
extern tdd tdd_exists(iri_tdd_manager tddm, tdd f, var_assoc vars);
extern tdd tdd_forall(iri_tdd_manager tddm, tdd f, var_assoc vars);

/* Reduction
============*/
extern tdd tdd_reduce(iri_tdd_manager tddm, tdd f, tdd c);

/* Gestion des associations
===========================*/
extern var_assoc tdd_new_assoc(iri_tdd_manager tddm, tdd *ass_inf, integer pairs);
extern void tdd_free_assoc(iri_tdd_manager tddm, var_assoc a);

/* Fonctions d'impression
==========================*/
/* Un des arguments de la fonction d'impression est une fonction associant
un nom de variable au numero de variable. Si cette fonction n'existe pas,
il faut passer NULL. La macro suivante defini un pointeur nul du bon type*/
/*=======================================================================*/

#define tdd_naming_fn_none ((char *(*)(iri_tdd_manager, tdd))0)

extern void tdd_print_tdd  (iri_tdd_manager,
				tdd,
				char *(*) (iri_tdd_manager, tdd),
				FILE *);
extern char *sexp_standard_name(integer i);
extern void tdd_signal_print_tdd(iri_tdd_manager tddm,tdd f,
	      char *(*var_naming_fn)(iri_tdd_manager, tdd),
	      char *(*sexp_naming_fn)(integer), FILE *fp);
extern void tdd_heptagon_print_tdd(iri_tdd_manager tddm,
                                   tdd * f,
                                   char ** ctrlable_names,
                                   integer nb_ctrlables,
                                   char *(*var_naming_fn)(iri_tdd_manager, tdd),
                                   char *(*sexp_naming_fn)(integer),
                                   FILE *fp);
extern integer tdd_dump_tdd(iri_tdd_manager tddm, tdd f, tdd *vars, FILE *fp);
extern integer tdd_sig_dump_tdd(iri_tdd_manager tddm, tdd f, integer *index_norm,
			    integer nbvar, FILE *fp);
extern tdd tdd_undump_tdd(iri_tdd_manager tddm, tdd *vars, FILE *fp, integer *error);

/* Exploration des tdd
======================*/

extern integer  tdd_size(tdd f);
extern integer  tdd_size_list(tdd *fs);
extern void  tdd_profile(iri_tdd_manager tddm, tdd f, integer *count);
extern void  tdd_profile_list(iri_tdd_manager tddm, tdd *fs, integer *count);
extern integer   *tdd_variables_poly(iri_tdd_manager tddm, tdd f);
extern void  tdd_support(iri_tdd_manager tddm, tdd f, tdd *support);
extern integer   tdd_nb_variables_poly(iri_tdd_manager tddm, tdd f);
extern integer  tdd_solutions_size(iri_tdd_manager tddm, tdd f, var_assoc a);

/* Creation et operations sur add
=================================*/
extern tdd   add_zero(iri_tdd_manager tddm);
extern tdd   add_one(iri_tdd_manager tddm);
extern tdd   add_infty(iri_tdd_manager tddm);
extern tdd   add_find_const(iri_tdd_manager tddm,integer v);
extern tdd   add_one_var_func(iri_tdd_manager tddm, tdd var, 
			      integer v1, integer v2, integer v3);
extern tdd   add_sum(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd   add_mul(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd   add_min(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd   add_max(iri_tdd_manager tddm, tdd f, tdd g);
extern tdd   add_part(iri_tdd_manager tddm, tdd f, tdd g1, tdd g2, tdd g3);
extern tdd   add_marg_min(iri_tdd_manager tddm, tdd f, var_assoc vars);
extern tdd   add_marg_max(iri_tdd_manager tddm, tdd f, var_assoc vars);
extern tdd   add_marg_sum(iri_tdd_manager tddm, tdd f, var_assoc vars);
extern tdd   add_marg_prod(iri_tdd_manager tddm, tdd f, var_assoc vars);
extern tdd   add_image_inverse(iri_tdd_manager tddm, tdd f, integer k);
extern tdd   add_image_inverse2(iri_tdd_manager tddm, tdd f, integer k);
extern tdd   add_image_inverse3(iri_tdd_manager tddm, tdd f, integer k);
extern integer   add_min_val(iri_tdd_manager tddm, tdd f);
extern integer   add_max_val(iri_tdd_manager tddm, tdd f);
extern tdd   add_cost2relation(iri_tdd_manager tddm, tdd c1, tdd c2, var_assoc UU);
extern tdd   add_cost2relation2(iri_tdd_manager tddm, tdd c1, tdd c2, var_assoc UU);

//hany add
extern void save_tdd(FILE *file,tdd x);
#endif




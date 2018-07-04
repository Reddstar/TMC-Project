
#include <cstdlib>
#include "integer.h"
/* tddeval.c: fonctions implementant instantiation et resolution */

#include "tddint.h"
#include "tddresolv.h"


/*****************************************************************
 *  EVALUATION: substitution de constantes a certaines variables  *
 *****************************************************************/

static tdd
tdd_eval_step(iri_tdd_manager tddm, tdd f, integer op, var_assoc subst)
{
  tdd_index_type f_index;
  tdd g;
  tdd temp0, temp1, temp2;
  tdd result;

  /* les variables a substituer sont-elles variables de f ??*/

  f_index=TDD_INDEX(tddm, f);
  if ((long)f_index > (long)subst->last)
    {
      TDD_TEMP_INCREFS(f);
      return (f);
    }

  /* oui -> evaluation deja calcule ?? */

  if (tdd_lookup_in_cache21(tddm, op, (integer)f, (integer)subst, (integer *)&result))
    return (result);

  g=subst->assoc[TDD_INDEXINDEX(f)];

  /* non -> cas general */
  if (!g) /* la variable de la racine n'est pas affectee */
    {
      temp0=tdd_eval_step(tddm, TDD_P0(f), op, subst);
      temp1=tdd_eval_step(tddm, TDD_P1(f), op, subst);
      temp2=tdd_eval_step(tddm, TDD_PM1(f), op, subst);
      result=tdd_find(tddm, TDD_INDEXINDEX(f), temp0, temp1, temp2);
    }
  else  /* la variable de la racine est affectee */
    {
      if (g==TDD_ZERO(tddm)) 
	result=tdd_eval_step(tddm, TDD_P0(f), op, subst);
      if (g==TDD_ONE(tddm)) 
	result=tdd_eval_step(tddm, TDD_P1(f), op, subst);
      if (g==TDD_MONE(tddm)) 
	result=tdd_eval_step(tddm, TDD_PM1(f), op, subst);

    } 

  tdd_insert_in_cache21(tddm, op, CACHE_TYPE_UN, OP_NCOM, 
			(long)f, (long)subst, (long)result);
  return (result);
}


/* tdd_eval(iri_tdd_manager tddm, tdd g, var_assoc va) :  substitution
   de polynomes aux variables - l'association va definit le morphisme
   ==========================================================================*/
tdd tdd_eval(iri_tdd_manager tddm, tdd g, var_assoc va)

{
  tdd resu;
  if (tdd_check_arguments(1,g))
    {
      FIREWALL(tddm);
      resu = tdd_eval_step(tddm, g, OPCODE_SUBST, va);
      RETURN_TDD(tddm,resu);
    }
  return (tdd)0;
} 

/*==========================================================================
  Substitution d'une constante a une variable
  ============================================================================*/

static tdd
tdd_eval_step_un(iri_tdd_manager tddm, tdd f, integer index, integer val)

{
  tdd_index_type f_index;
  tdd temp0, temp1, temp2;
  tdd result;

  /* la variable a substituer est-elle variable de f ??*/

  f_index=TDD_INDEX(tddm, f);
  if ((long)f_index > index)
    {
      TDD_TEMP_INCREFS(f);
      return (f);
    }

  /* oui -> evaluation deja calcule ?? */

  if (tdd_lookup_in_cache21(tddm, 76537674, (integer)f, (integer)((index<<8)+val),
			    (integer *)&result))
    return (result); /* MAUVAISE RESOLUTION AVEC CACHE - A REVOIR*/

  /* non -> cas general */
  if (f_index != index) /* la variable de la racine n'est pas affectee */
    {
      temp0=tdd_eval_step_un(tddm, TDD_P0(f), index, val);
      temp1=tdd_eval_step_un(tddm, TDD_P1(f), index, val);
      temp2=tdd_eval_step_un(tddm, TDD_PM1(f), index, val);
      result=tdd_find(tddm, TDD_INDEXINDEX(f), temp0, temp1, temp2);
    }
  else  /* la variable de la racine est affectee */
    {
      if (val == 0) 
	result=TDD_P0(f);
      if (val == 1) 
	result=TDD_P1(f);
      if (val == 2) 
	result=TDD_PM1(f);
      TDD_TEMP_INCREFS(result);
    }
  tdd_insert_in_cache21(tddm,  76537674, CACHE_TYPE_UN, OP_NCOM, 
			(long)f, (long)((index<<8)+val), (long)result);
  return (result);
}


/* tdd_eval(iri_tdd_manager tddm, tdd g, var_assoc va) :  substitution
   d'une valeur aux variables 
   ==========================================================================*/
tdd
tdd_eval_un(iri_tdd_manager tddm, tdd g, integer index, integer val)
{
  tdd resu;
  
  if ((val!=0)&&(val!=1)&&(val!=2))
    {
      printf("\n Erreur sur valeur :%d\n",val);
      exit(1);
    }
  if (tdd_check_arguments(1,g))
    {
      FIREWALL(tddm);
      resu = tdd_eval_step_un(tddm, g, index, val);
      RETURN_TDD(tddm,resu);
    }
  return (tdd)0;
} 


/*========================================================================
  MODULE DE RESOLUTION D"EQUATIONS POUR RESOLVER
  L'algorithme de recherche de solutions n'est correct que si le TDD 
  representant l'equation est normalise i.e. ne prend que les valeurs 0,1.
  Le tableau vp doit etre dimensionne au nombre de variables total
  ou les index des variables de l'equation doivent etre dans l'intervalle
  [0,nbvar-1]. vp[i] code alors toutes les valeurs de la variable
  d'index i qui apparaissent dans au moins une solution de l'equation.
  ===========================================================================*/

/* Codage des solutions d'une equation
   ======================================*/
void set_val_perm(val_perm *valperm,integer valeur)
{
  switch (valeur) 
    {
    case 0: *valperm = *valperm | VAL0; break;
    case 1: *valperm = *valperm | VAL1; break;
    case 2: *valperm = *valperm | VAL2; break;
    }
}

/* Recherche de valeurs autorisees pour une equation
   =====================================================*/
void tdd_solve_step(iri_tdd_manager tddm, tdd f, tdd_index_type index_attendu, integer nbvar, val_perm *vp)
{
  tdd_index_type index;
  val_perm *vv;
  integer i;

  index = TDD_INDEX(tddm, f);
  vv = vp+index_attendu;
 
  /* cas d'arret */

  if (TDD_IS_CONST(f))         /* noeud feuille */
    {
      if(f == TDD_ZERO(tddm))  /* toutes les valeurs conviennent */
	{                      /* pour les variables restantes */
	  for(i=index_attendu; i<nbvar; i++) vp[i]=TOVAL;
	  return;
	}
      else return;             /* pas de solution */
    }
  if (!TDD_MARK(f)) return;    /* noeud deja explore */

  /* cas general */
  /* L'index de f est l'index attendu */
  if (index == index_attendu)
    {
      if ((TDD_P0(f)!= TDD_ONE(tddm)))
	set_val_perm(vv, 0);
      if ((TDD_P1(f)!= TDD_ONE(tddm)))
	set_val_perm(vv, 1);
      if ((TDD_PM1(f)!= TDD_ONE(tddm)))
	set_val_perm(vv, 2);
      tdd_solve_step(tddm,TDD_P0(f),index_attendu+1,nbvar,vp);
      tdd_solve_step(tddm,TDD_P1(f),index_attendu+1,nbvar,vp);
      tdd_solve_step(tddm,TDD_PM1(f),index_attendu+1,nbvar,vp);
    }
  /* l'index attendu n'apparait pas: toutes les valeurs sont permises
     pour cette variable car f n'est pas constant (0,1 !!) */
  else
    {
      *vv = TOVAL;
      tdd_solve_step(tddm,f,index_attendu+1,nbvar,vp);
    }
  TDD_MARK(f) = 0;
}

/*  tdd_mark_shared_node : marquage des noeuds partages notamment avant impression
    =================================================================================*/

void tdd_mark_shared_nodes(iri_tdd_manager tddm, tdd f)
{
  /* on ne marque ni constante ni variable  */
  if (TADD_IS_CONST(f) || tdd_type_aux(tddm, f) == TDD_TYPE_POSVAR) return; 
  
  if (TDD_MARK(f))
    {
      if (TDD_MARK(f) == 1) TDD_MARK(f)=2; /* on indique: le noeud sert au moins 2 fois */
      return;
    }
  TDD_MARK(f)=1;
  tdd_mark_shared_nodes(tddm, TDD_P0(f));
  tdd_mark_shared_nodes(tddm, TDD_P1(f));
  tdd_mark_shared_nodes(tddm, TDD_PM1(f));
}


void tdd_solve(iri_tdd_manager tddm, tdd f, val_perm *vp, integer nbvar)
{
  integer i;

  if (tdd_check_arguments(1,f))
    {
      if (TDD_IS_CONST(f))
	{
	  if(f == TDD_ZERO(tddm))
	    /* initialisation du tableau a TOVAL (toutes valeurs permises)*/
	    for(i=0;i<nbvar;i++) vp[i]= TOVAL;
	  else
	    /* mise du tableau a 0 (aucune valeur permise) */
	    for(i=0;i<nbvar;i++) vp[i] = NOVAL;
	}
      else
	{
	  /* initialisation du tableau a NOVAL */
	  for(i=0;i<nbvar;i++) vp[i] = NOVAL;
	  tdd_mark_shared_nodes(tddm, f);
	  tdd_solve_step(tddm,f,0,nbvar,vp);
	}
    }
}

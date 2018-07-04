
/* tddmanager.c: acces du type iri_tdd_manager
   ============================================*/

#include "tddint.h"

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  Gestionnaires de TDD: creation et destruction
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*==============================================================================
  iri_tdd_init (): Creation d'un gestionnaire de TDD - retourne ce gestionnaire
  ================================================================================*/
iri_tdd_manager iri_tdd_init (void)
{
  iri_tdd_manager tddm;
  long i;

  tddm=(iri_tdd_manager)mem_get_block((long)sizeof(struct tdd_manager_));

  /* Initialisation parametres des variables 
     ------------------------------------------*/
  tddm->vars=1; 
  /* MODIF ADD: deux indices pour constantes bool(0) et ent (1) */
  tddm->maxvars=10;

  /* Init. du tableau des variables et des tableaux d'index 
     ---------------------------------------------------------*/
  tddm->variables=(tdd *)mem_get_block((tddm->maxvars+1)*sizeof(tdd));
  tddm->indexes=(tdd_index_type *)mem_get_block((tddm->maxvars+2)*sizeof(tdd_index_type));
  tddm->indexes[TDD_CONST_INDEXINDEX]=TDD_MAX_INDEX+1; /* constantes = max pour l'ordre */
  tddm->indexes[ADD_CONST_INDEXINDEX]=TDD_MAX_INDEX; /* MODIF */
  tddm->indexindexes=(tdd_indexindex_type *)mem_get_block(tddm->maxvars*sizeof(tdd_indexindex_type));

  /* Record manager: gestion memoire
     ----------------------------------*/
  for (i=0; i < REC_MGRS; ++i)
    tddm->rms[i]=mem_new_rec_mgr(MIN_REC_SIZE+ALLOC_ALIGNMENT*i);
  tddm->check = 100;

  /* Table des noeuds TDD 
     ------------------------*/
  iri_init_tdd_table(tddm);

  /* Caches: pas de cache4 pour le resolver
     ----------------------------------------*/
  tdd_init_cache(tddm);

  /* Liste des associations var->polynomes
     ----------------------------------------*/
  tddm->assocs = (var_assoc)0;

  /* TDD constants 
     -----------------*/
  tddm->zero=tdd_find_const(tddm, 0l);
  tddm->zero->refs=TDD_MAX_REFS;
  tddm->zero->mark=0;
  tddm->one=tdd_find_const(tddm, 1l);
  tddm->one->refs=TDD_MAX_REFS;
  tddm->one->mark=0;
  tddm->mone=tdd_find_const(tddm, -1l);
  tddm->mone->refs=TDD_MAX_REFS;
  tddm->mone->mark=0;

  /* RESOLVER: VERSION SANS ADD */
  /*  tddm->add_0=add_find_const(tddm,0l);
      tddm->add_0->refs=TDD_MAX_REFS;
      tddm->add_0->mark=0;

      tddm->add_1=add_find_const(tddm,1l);
      tddm->add_1->refs=TDD_MAX_REFS;
      tddm->add_1->mark=0;

      tddm->add_infty=add_dieu(tddm);
      tddm->add_infty->refs=TDD_MAX_REFS;
      tddm->add_infty->mark=0; */

  /* Init des differents indicateurs d'exceptions et handler associes
     ------------------------------------------------------------------*/
  tddm->overflow=0;

  return (tddm);
}

/*===================================================================================
  integer tdd_man_nb_vars(iri_tdd_manager tddm): retourne le nombre de variables utilisees
  =====================================================================================*/
integer tdd_man_nb_vars(iri_tdd_manager tddm)
{
  return (tddm->vars)-1;
}

/*===================================================================================
  void iri_tdd_quit(tddm): liberation de la place memoire occupee par un gestionnaire
  =====================================================================================*/
void iri_tdd_quit(iri_tdd_manager tddm)

{
  integer i;

  iri_free_tdd_table(tddm);                    /* liberation de la table des noeuds */
  tdd_free_cache(tddm);                        /* liberation du cache */
  mem_free_block((pointer)tddm->variables);    /* liberation du tableau des variables */
  mem_free_block((pointer)tddm->indexes);      /* lib. tableaux de conversion */
  mem_free_block((pointer)tddm->indexindexes);
  for (i=0; i < REC_MGRS; ++i)                 /* lib. record manager */
    mem_free_rec_mgr(tddm->rms[i]);
  mem_free_block((pointer)tddm);               /* lib. du gestionnaire */
}


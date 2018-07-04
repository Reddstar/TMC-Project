/* TDD library dump/undump routines */

#include "tddint.h"
#include <cstdio>
#include "tdddump_m.c"


/* Module special resolver
==========================*/


/* lecture recursive d'un fichier et reconstruction du TDD
==========================================================*/
static tdd tdd_undump_tdd_step_re(iri_tdd_manager tddm,
		    FILE *fp,
		    tdd_index_type number_vars,
		    tdd *shared,
		    long number_shared,
		    long *shared_so_far,
		    integer index_size,
		    integer node_number_size,
		    integer *error)

{
  long node_number;
  long encoding;
  tdd_index_type i;
  tdd v;
  tdd temp1, temp2, temp3;
  tdd result;

  i=read(error, index_size, fp);       /* lecture des premiers octets */
  if (*error)
    return ((tdd)0);
  if (i == index_mask[index_size-1])   /* c'est un mot clef */
    {
      encoding=0xffffff00l+read(error, 1, fp);
      if (*error)
	return ((tdd)0);
      switch (encoding)                /* decriptage du mot clef */
	{
	case ZERO_ENCODING:
	  return (TDD_ZERO(tddm));
	case ONE_ENCODING:
	  return (TDD_ONE(tddm));
	case MONE_ENCODING:
	  return (TDD_MONE(tddm));
	case POSVAR_ENCODING:          /* variable d'index normalise i */
	  i=read(error, index_size, fp);
	  if (!*error && i >= number_vars)
	    *error=TDD_UNDUMP_FORMAT;
	  if (*error)
	    return ((tdd)0);
	  v=tddm->variables[i+2];      /* renvoie la ieme variable d'indexindex i+2*/
	  return (v);
	case POSNODE_ENCODING:         /* noeud multiple deja decode */
	  node_number=read(error, node_number_size, fp);
	  if (!*error && (node_number >= number_shared || !shared[node_number]))
	    *error=TDD_UNDUMP_FORMAT;
	  if (*error)
	    return ((tdd)0);
	  v=shared[node_number];
	  TDD_TEMP_INCREFS(v);
	  return (v);
	case NODELABEL_ENCODING:       /* premiere apparition d'un noeud multiple */
	  node_number= *shared_so_far;
	  ++*shared_so_far;
	  v=tdd_undump_tdd_step_re(tddm, fp, number_vars, shared, number_shared,
				shared_so_far, index_size, node_number_size, error);
	  if(*error) return (tdd)0;
	  shared[node_number]=v;
	  TDD_TEMP_INCREFS(v);
	  return (v);
	default:
	  *error=TDD_UNDUMP_FORMAT;
	  return ((tdd)0);
	}
    }
  /* ce doit etre un index de variable */
  if (i >= number_vars)
    {
      *error=TDD_UNDUMP_FORMAT;
      return ((tdd)0);
    }
  temp1=tdd_undump_tdd_step_re(tddm, fp, number_vars, shared, number_shared,
			    shared_so_far, index_size, node_number_size, error);
  if(*error) return (tdd)0;
  temp2=tdd_undump_tdd_step_re(tddm, fp, number_vars, shared, number_shared,
			    shared_so_far, index_size, node_number_size, error);
  if(*error)
    {
      TDD_TEMP_DECREFS(temp1); 
      return (tdd)0;
    }
  temp3=tdd_undump_tdd_step_re(tddm, fp, number_vars, shared, number_shared,
			    shared_so_far, index_size, node_number_size, error);
  if(*error)
    {
      TDD_TEMP_DECREFS(temp1); 
      TDD_TEMP_DECREFS(temp2);
      return (tdd)0;
    }
  result=tdd_find(tddm, i+2, temp1, temp2,temp3); /* 0:const logiques; 1: const ent. */
  return (result);
}


/* fonction de lecture d'un fichier TDD
=======================================*/
tdd
tdd_undump_tdd_re(iri_tdd_manager tddm, FILE *fp, integer *error)

{
  long i;
  tdd_index_type number_vars;
  long number_shared;
  integer index_size;
  integer node_number_size;
  tdd *shared;
  long shared_so_far;
  tdd v;
  tdd result;


  /* verification du code identifiant un fichier TDD */
  if (read(error, sizeof(long), fp) != MAGIC_COOKIE)
    {
      if (!*error)
	*error=TDD_UNDUMP_FORMAT;
      return ((tdd)0);
    }
  /* lecture et verification du nombre de variables. 
     Il doit etre egal au nombre de variables du tdd manager */
  number_vars=read(error, sizeof(tdd_index_type), fp);
  if (*error)
    return ((tdd)0);
  if (number_vars != tddm->vars-1) /* attention: 0=const logiques,1=const ent. ADD */
    {
      *error=TDD_UNDUMP_FORMAT;
      return ((tdd)0);
    }

  /* lecture et verification du nombre de noeuds partages */
  number_shared=read(error, sizeof(long), fp);
  if (*error)
    return ((tdd)0);
  index_size=bytes_needed(number_vars+1);
  node_number_size=bytes_needed(number_shared);
  if (number_shared < 0)
    {
      *error=TDD_UNDUMP_FORMAT;
      return ((tdd)0);
    }

  /* mise en place de la memoire des noeuds partages */
  shared=(tdd *)mem_get_block(number_shared*sizeof(tdd));
  for (i=0; i < number_shared; ++i)
    shared[i]=0;
  shared_so_far=0;

  /* on y va */
  result=tdd_undump_tdd_step_re(tddm, fp, number_vars, shared, number_shared,
			     &shared_so_far, index_size, node_number_size, error);

  /*nettoyage et dernieres verif */
  for (i=0; i < number_shared; ++i)
    if ((v=shared[i]))TDD_TEMP_DECREFS(v);
  if (!*error && shared_so_far != number_shared)
    *error=TDD_UNDUMP_FORMAT;
  mem_free_block((pointer)shared);
  if (*error)
    {
      if (result)
	TDD_TEMP_DECREFS(result);
      return ((tdd)0);
    }
  RETURN_TDD(tddm,result);  
}


/* programme de test des modules tdd du resolver */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "tddint.h"
#include "tddresolv.h"
#include "random.c"

#define NBVARS 5

void affiche_choix(val_perm *vp, integer *choix, integer nbvar)

{
  integer i;
  printf("\n Valeurs possibles pour la variable:\n");
  for(i=0;i<nbvar;i++)
    {
      if(!choix[i])
	{
	  printf("%d ->",i);
	  if( vp[i] & VAL0) printf(" %d ", 0); else printf(" x ");
	  if( vp[i] & VAL1) printf(" %d ", 1); else printf(" x ");
	  if( vp[i] & VAL2) printf(" %d \n", 2); else printf(" x \n");
	};
    }
}



/* le choix automatique recoit en entrees les variables deja choisies
  codees dans le tableau choix. Une variable est tiree au hasard parmi
  les variables non envcore choisies et une valeur est tiree parmi celles
  autorisees pour cette variable. Le tableau choix est actualise.
-----------------------------------------------------------------------*/
void choix_automatique(val_perm *vp, integer nbvar, integer *vari, integer *choix)
{
  integer i, n,  nbvar_inst, sol[3];

  for(i=0;i<3;i++) sol[i]=0;
  /* determination du nombre de variables restant a instancier */
  nbvar_inst = 0;
  for (i=0; i<nbvar; i++)
    {if(!choix[i]) nbvar_inst++;};
  
  /* tirage de la variable a instancier */
  n = choix_parmi(nbvar_inst);
  i=0; *vari=nbvar+1;
  while((i<nbvar)&&(*vari==nbvar+1))
    { 
      if ((!n)&&(!choix[i])) *vari=i;
      if (!choix[i]) n--;
      i++;
    };

  /* choix de la valeur */
  n = 0;
  if( vp[*vari] & VAL0)
    {sol[0] = 1; n++;};
  if( vp[*vari] & VAL1)
    {sol[1] = 1; n++;};
  if( vp[*vari] & VAL2)
    {sol[2] = 1; n++;};
  n = choix_parmi(n);
  for(i=0;i<3;i++)
    {
      if (!n&&sol[i]) choix[*vari]=i+1;
      if (sol[i]) n--;
    };
}



integer main()
{
  integer nbvar,i,error, isolved,val,choix[NBVARS],var_choix,aut,jj;
  char cc;
  iri_tdd_manager tddm;
  tdd f,f_origine,temp,var[6],assoc[6];
  var_assoc va;
  FILE *fp;
  val_perm vp[NBVARS];
  
  /* Initialisations */
  tddm = iri_tdd_init();
  srand(675388);

  /* lecture du fichier contenant un tdd */
  fp=fopen("tdd.dump","r");

  for(i=0;i<NBVARS;i++)
    f = tdd_new_var_last(tddm);

  error=0;
  f_origine = tdd_undump_tdd_re(tddm,fp,&error);
  printf(" UNDUMP_ERROR: %d\n",error);

  /*  printf("\n Choix automatique (1) ou manuel (0)?\n");
  scanf("%d",&aut);
  printf("\nChoix:%d\n",aut);*/
  aut = 1;
  /* resolution interactive de l'equation */
  for(jj=0;jj<10000; jj++)
    {
      printf("\n %d",jj);
      f = f_origine; tdd_unfree(tddm,f);
      for(i=0;i<NBVARS;i++) choix[i]=0;
      var_choix = 0;
      while (var_choix<NBVARS)
	{
	  tdd_solve(tddm,f,vp,NBVARS);
	  if (aut)
	    { 
	      /*	  affiche_choix(vp, choix, NBVARS);*/
	      choix_automatique( vp, NBVARS, &i, choix);
	      var_choix++;
	      val = choix[i]-1;
	    }
	  else
	    {
	      affiche_choix(vp, choix, NBVARS);
	      printf("\n Entrez n0 de variable et choix \n");
	      scanf("%d\n%d",&i,&val);
	      choix[i] = val+1;
	      var_choix++;
	    };
	  
	  /* instanciation */
	  printf("\n Instanciation : %d",i);
	  temp = tdd_eval_un(tddm,f,i,val);
	  tdd_free(tddm,f);
	  f = temp;
	};
      if (f != TDD_ZERO(tddm))
	{
	printf("\n Equation mal resolue *************\n ");
	exit(3);
	};
    };
      /*  else printf("\n Bonne solution\n"); */
  return 0;
}


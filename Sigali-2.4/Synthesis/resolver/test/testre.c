#include "resolveur.h"

void affiche_choix(int *vp, int nbvar)

{
  int i;
  printf("\n Valeurs possibles pour la variable:\n");
  for(i=0;i<nbvar;i++)
    {
      printf("%d ->",i);
      if( vp[3*i] ) printf(" %d ", 0); else printf(" x ");
      if( vp[3*i+1]) printf(" %d ", 1); else printf(" x ");
      if( vp[3*i+2]) printf(" %d \n", 2); else printf(" x \n");
    }
}


int main()
{
  int valetat[]= {2},//,2,2,2,1,2,2,1,2,2,
		  //                  2,2,2,2,2,2,2,2,2,2,
		  //                  2,2},
		   valmes[]={1},
		   valcond[]={1},
		   sol[2]; 
  resolveur RR;
  int isolved,i,val,aut, mes;

  printf("\n Test de resolution manuelle \n");
  RR.chargement("fich_test");
  RR.raz();
  RR.set_config(1);
  RR.set_etats(valetat,1);
  RR.set_mesures(valmes,1);
  RR.set_conditions(valcond,1);


  //  test de resolution
  RR.init_resolution();

  //    printf("\n Automatique (1) ou manuel (0) \n");
  //    scanf("%d",&aut);
  aut = 0;
 while(1)
   { 
  isolved = 0;
  while (!isolved)
  {
    if (aut)
      {
	RR.get_solution(sol,2);
	affiche_choix(sol,2);
	isolved = 1;
      }
    else
      {
	if (RR.get_valperm(sol,2))
	  {
	    printf("\n Choix termine \n");
	    affiche_choix(sol,2);
	    isolved = 1;
	  }
	else 
	  {
	    affiche_choix(sol,2);
	    printf("\n Entrez n0 de variable et choix \n");
	    scanf("%d\n%d",&i,&val);
	    printf("var %d = %d \n",i,val);
	    RR.set_inconnue(i, val);
	  };
      };
  };
  RR.bien_resolue();
   } 
    // changement de configuration
  //   RR.set_config(0);

  // test de resolution automatique
  //  printf("\n Test de resolution automatique \n");
  
  //  for (i=0;i<0;i++)
  //    {
  //      printf("\n ->%d",i);
  //      RR.raz();
  //      RR.set_etats(valetat,1);
  //      RR.set_conditions(valcond,1);
  //      RR.set_mesures(valmes,1);
      
  //     RR.init_resolution();
  //   RR.get_solution(sol,1);
      //      affiche_choix(sol,3);
  //    RR.resolue();
  //  };

  return 0;
}

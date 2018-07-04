#include "equation.h"
//====================================================================
// METHODES DE LA CLASSE EQUATION
//====================================================================


// Chargement
//-----------
void equation::set(iri_tdd_manager tddm, tdd eq, 
		   vector<ptvariable> param, vector<ptvariable> indeter)
{
  eq_init = eq;
  eq_courant = eq; 
  tdd_unfree(tddm, eq_courant); // deux references sur eq
  parametres = param;
  nb_par =  param.size();
  par_inst = 0;                 // pas de parametres instancies
  inconnues = indeter;
  nb_inc = indeter.size() ;
  inc_inst = 0;                 // pas d'inconnue instanciee
  nb_var = tdd_man_nb_vars(tddm);
  vp = (val_perm *)mem_get_block(nb_var*sizeof(val_perm));
}

// recherche si une variable est une inconnue
//-------------------------------------------
int equation::is_inconnue(variable &v_inst)
{
  vector<ptvariable>::iterator first,last;

  first = inconnues.begin();
  last = inconnues.end();
  while (first != last)
    {
      if(v_inst.numero == (*(*first)).numero) return 1;
      first++;
    }
  return 0;
}

// Instanciation d'une inconnue
//-----------------------------
void equation::instancier_une_inc(variable &v_inst, iri_tdd_manager tddm)
{
  int index, val;
  tdd temp;

  // NB: l'instanciation de la variable est a la charge de la configuration.
  if (is_inconnue(v_inst))
    {
      index = v_inst.numero;
      if (v_inst.inst_pred()) val = v_inst.valeur;
      else 
	{
	  printf("\n equation::instancier_une_inc - Variable non instanciee \n");
	  exit(1);
	}
      temp = tdd_eval_un(tddm,eq_courant,index,val);
      tdd_free(tddm, eq_courant);
      eq_courant = temp;
      inc_inst++;
    }
}


// Instanciation des parametres
//-----------------------------

void equation::instancier_parametres(iri_tdd_manager tddm)
{
  int i;
  tdd *assoc,temp;
  var_assoc v_ass;
  vector<ptvariable>::iterator first,last;

  if (nb_par > 0)
    {
      // NB: l'instanciation des variables est a la charge de la configuration
      assoc = (tdd *) mem_get_block(2*nb_par*sizeof(tdd)+1);
      assoc[2*nb_par] = (tdd)0;
      
      // Construction de l'association
      first = parametres.begin();
      last = parametres.end();
      i = 0;
      while (first != last)
	{
	  if((*(*first)).inst_pred())
	    {
	      assoc[i] = (*(*first)).poly;
	      assoc[i+1] = tdd_const(tddm,(*(*first)).valeur);
	      i+=2; first++; par_inst++;
	    }
	  else 
	    {
	      printf("\n equation::instancier_parametres - Parametre non instancie \n");
	      printf(" Variable : %d\n", (*(*first)).numero);
	      exit(1);
	    }
	}
      v_ass = tdd_new_assoc(tddm,assoc,1);
      temp = tdd_eval(tddm,eq_courant,v_ass);
      tdd_free(tddm,eq_courant);
      eq_courant = temp;
      
      tdd_free_assoc(tddm,v_ass);
      mem_free_block((pointer) assoc);
    }
}
// Desinstanciation
//-----------------
void equation::desinstancier(iri_tdd_manager tddm)
{
  tdd_free(tddm,eq_courant);
  eq_courant = eq_init;
  tdd_unfree(tddm, eq_courant); // il y a deux references sur eq_init
  par_inst = 0;
  inc_inst = 0;
  // NB: la desinstanciation des variables est a la charge de
  // la configuration.
}

// Resolution
//-----------
int equation::resoudre(iri_tdd_manager tddm)
{
  int i,nn;
  tdd temp;

  // Les parametres sont-ils tous instancies?
  if (par_inst != nb_par)
    {
      printf("\n Erreur fatale: resolution d'equation dont tous les parametres\n
                                ne sont pas instancies!!!");
      exit(1);
    }
  // Resolution
  tdd_solve(tddm,eq_courant,vp,nb_var);

  // Mise a jour des inconnues
  for(i=0; i<nb_inc; i++)
    { 
      nn = (*inconnues[i]).numero;
      if((*inconnues[i]).set_sol(vp[nn])) // une nouvelle inconnue instanciee
	{
	  temp = tdd_eval_un(tddm,eq_courant,nn,(*inconnues[i]).valeur);
	  tdd_free(tddm, eq_courant);
	  eq_courant = temp;
	  inc_inst++;
	}
    }
   return( inc_inst == nb_inc);
}

// Resolution automatique
//-----------------------
/* tirage aleatoire d'un entier parmi [0 .. n-1]
-----------------------------------------------*/
int choix_parmi(int n)
{
  int ii;
  
  ii = rand();
  if (ii == RAND_MAX) return (n-1);
  return (int)floor((ii*n)/RAND_MAX);
}


void equation::resoudre_automatiquement(iri_tdd_manager tddm)
{
  int i, nbvar_inst, nn, vari_inst, sol[3], index, val;
  unsigned char ii;
  tdd temp;

  // Les parametres sont-ils tous instancies?
  if (par_inst != nb_par)
    {
      printf("\n Erreur fatale: resolution d'equation dont tous les parametres\n
                                ne sont pas instancies!!!");
      exit(1);
    }

  // Resolution
  while(inc_inst != nb_inc)
    {
      tdd_solve(tddm,eq_courant,vp,nb_var);

      // determination du nombre d'inconnues restant a instancier 
      nbvar_inst = nb_inc - inc_inst;

      // tirage de la variable a instancier 
      nn = choix_parmi(nbvar_inst);
      i=0; vari_inst=nb_inc+1;
      while((i<nb_inc)&&(vari_inst==nb_inc+1))
	{ 
	  if ((!nn)&&(!(*inconnues[i]).inst_pred())) vari_inst=i;
	  if (!(*inconnues[i]).inst_pred()) nn--;
	  i++;
	}
      // tirage de la valeur 
      index = (*inconnues[vari_inst]).numero;
      for(i=0;i<3;i++) sol[i]=0;
      nn = 0;
      if( vp[index] & VAL0)
	{sol[0] = 1; nn++;}
      if( vp[index] & VAL1)
	{sol[1] = 1; nn++;}
      if( vp[index] & VAL2)
	{sol[2] = 1;nn++;}
      nn = choix_parmi(nn);
      
      for(ii=0;ii<3;ii++)
	{
	  if ((!nn)&&sol[ii])
	    {
	      val = ii;
	      (*(inconnues[vari_inst])).instancier(ii);
	    }
	  if (sol[ii]) nn--;
	}

      // substitution dans l'equation
      
      temp = tdd_eval_un(tddm,eq_courant,index,val);
      tdd_free(tddm, eq_courant);
      eq_courant = temp;
      inc_inst++;
    }
}

// Pour debug

void equation::resolue(iri_tdd_manager tddm)
{

  int i;
  tdd *assoc,temp;
  var_assoc v_ass;
  vector<ptvariable>::iterator first,last;


  if (eq_courant != tdd_zero(tddm))
  // substitution des inconnues eventuellement non substituees dans eq_courant
    {
      assoc = (tdd *) mem_get_block(2*nb_inc*sizeof(tdd)+1);
      assoc[2*nb_inc] = (tdd)0;
      
      // Construction de l'association
      first = inconnues.begin();
      last = inconnues.end();
      i = 0;
      while (first != last)
	{
	  if((*(*first)).inst_pred())
	    {
	      assoc[i] = (*(*first)).poly;
	      assoc[i+1] = tdd_const(tddm,(*(*first)).valeur);
	      i+=2; first++;
	    }
	  else 
	    {
	      printf("\n equation::debug  - Inconnue non instanciee \n");
	      printf(" Variable : %d\n", (*(*first)).numero);
	      mem_free_block((pointer) assoc);
	      return;
	    }
	}
      v_ass = tdd_new_assoc(tddm,assoc,1);
      temp = tdd_eval(tddm,eq_courant,v_ass);

      if (temp == tdd_zero(tddm))
	printf("\n equation::debug - equation bien resolue\n");
      else
	{
	  printf("\n equation::debug - equation mal resolue **************\n");
	  exit(3);
	}
      tdd_free_assoc(tddm,v_ass);
      mem_free_block((pointer) assoc);
    }
  else
    printf("\n equation::debug - equation bien resolue\n");
}

#include "configuration.h"
//=====================================================================
// METHODES DE LA CLASSE CONFIGURATION
//=====================================================================

// set
//----
// Initialisation d'une configuration.
// La liste $P se trouve dans param, $I dans indeter
// eq represente l'equation de la config.

void configuration::set(iri_tdd_manager tddm, tdd eq,
			vector<ptvariable> param, vector<ptvariable> indeter,
			vector<ptvariable> out, vector<fonction> fonc)
{
  eq_conf.set(tddm, eq,param,indeter);
  nb_sorties = out.size();
  var_out = out; 
  fonctions = fonc;
}

// desinstancier
//--------------
// desinstancie l'equation.
void configuration::desinstancier(iri_tdd_manager tddm)
{
  eq_conf.desinstancier(tddm);
}

// instancier_inconnue
//--------------------
// Instancie une inconnue: version optimisee pour une valeur  
void configuration::instancier_inconnue(int numero ,unsigned char val,
					iri_tdd_manager tddm)
{
  if ((numero >= nb_sorties)||(numero<0))
    {
      printf("\n configuration::instancier_inconnue - Mauvais numero de variable \n");
      exit(1);
    }
  (*(var_out[numero])).instancier(val);
  eq_conf.instancier_une_inc((*(var_out[numero])),tddm);
}

// instancier_param
//-----------------
// Les fonctions doivent avoir leurs arguments instancies et sont calculees
// Les parametres de l'equation sont utilises pour la simplifier
// Les sorties sont dans un premier temps desinstanciees,
// Apres cette operation, les sorties fonctionnelles sont instanciees.
// Une sortie fonctionnelle peut servir de parametre a l'equation.

void configuration::instancier_param(iri_tdd_manager tddm)
{
  int i;
  vector<fonction>::iterator first,last;

  // desinstanciation des sorties
  for (i=0; i<nb_sorties; i++)
    (*(var_out[i])).desinstancier();

  // Instanciation des sorties fonctionnelles
  first = fonctions.begin();
  last = fonctions.end();
  while(first != last)
    {
      (*first).instancier(tddm);
      first++;
    }

  // Instanciation equation
  eq_conf.instancier_parametres(tddm);
}


// Proposition de solutions pour l'equation
//------------------------------------------
// Donne pour les inconnues de la configuration les valeurs possibles
// Si une inconnue a ete prealablement instanciee, elle reste inchangee
// Retourne 0 si plusieurs solutions, 1 si solution unique
int configuration::get_valperm(unsigned char *sol, int nb_sol, iri_tdd_manager tddm)
{
  int i, result;

  if(nb_sol != nb_sorties)
    {
      printf("\n configuration::get_valperm - nombre d'inconnues errone \n");
      exit(1);
    }
  else
    {
      result = eq_conf.resoudre(tddm);
    }
  // Affectation sur sortie: materialisation de la liaison des out
  for (i=0; i<nb_sol; i++)
    if((*(var_out[i])).pre_inst())
      sol[i]=(*(var_out[i])).val_possible;
    else
      {
	// sortie non contrainte => resolution non terminee
	sol[i] = TOVAL;
	result = 0;
      }
  return result;
}

// Resolution automatique
//-----------------------
// Semblable a la precedente mais une solution est choisie par tirage aleatoire
void configuration::get_solution(unsigned char *sol, int nb_sol, iri_tdd_manager tddm)
{
  int i, ii;

  if(nb_sol != nb_sorties)
    {
      printf("\n configuration::get_solution - nombre d'inconnues errone \n");
      exit(1);
    }
  else
    {
      eq_conf.resoudre_automatiquement(tddm);
    }
  // Affectation sur sortie: materialisation de la liaison des out
  for (i=0; i<nb_sol; i++)
    if((*(var_out[i])).pre_inst())
      sol[i]=(*(var_out[i])).val_possible;
    else
      {
	// sortie non contrainte => resolution aleatoire
	ii = rand();
	if (ii == RAND_MAX) 
	  ii = 2;
	else
	  ii = (int)floor((ii*3)/RAND_MAX);
	switch (ii)
	  {
	  case 0: sol[i] = VAL0; break;
	  case 1: sol[i] = VAL1; break;
	  case 2: sol[i] = VAL2; break;
	  }
      }
}

// pour debug
void configuration::resolue(iri_tdd_manager tddm)
{
  eq_conf.resolue(tddm);
}



#ifndef _CONFIGURATION_
#define _CONFIGURATION_

#include "equation.h"
#include "fonction.h"

#include "integer.h"

#include <vector>
#include <iterator>
#include "tddresolv.h"
#include "memuser.h"

//===================================================================
//  Definition de la classe des configurations
//
//  Une configuration comprend une liste de variables, 
//  une liste de fonctions et une equation.
//  Une configuration peut donc implementer un controleur
//  comportant une partie fonctionnelle et une partie relationnelle.
//  Une partie des variables represente des sorties, les autres sont
//  des entrees ou parametres
//  L'ordre des variables dans la liste var_out materialise la liaison
//  avec l'exterieur: les methodes get_valperm ou get_solution produisent
//  les valeurs de sortie dans cet ordre.
//  Les variables de sortie d'une configuration sont definies par
//  la liste suivant le mot clef $I dans le fichier de description.
//  Les autres variables sont enumerees apres $P
//===================================================================

class configuration 
{
  std::vector<ptvariable> var_out;          // liste des variables a calculer
  integer nb_sorties;
  std::vector<fonction> fonctions;          // Expression des variables fonctionnelles
  equation eq_conf;                    // Partie equationnelle

public:
  void set(iri_tdd_manager tddm, tdd eq, std::vector<ptvariable> param, 
	   std::vector<ptvariable> indeter, std::vector<ptvariable> out, std::vector<fonction> fonc);
  void instancier_inconnue(integer numero, unsigned char val, iri_tdd_manager tddm);
  void instancier_param(iri_tdd_manager tddm);
  void instancier_param_par_defaut(iri_tdd_manager tddm);
  void desinstancier(iri_tdd_manager tddm);
  integer  get_valperm(unsigned char *sol, integer nb_sol, iri_tdd_manager tddm);
  void get_solution(unsigned char *sol, integer nb_sol, iri_tdd_manager tddm);

  void resolue(iri_tdd_manager tddm);
  void bien_resolue(iri_tdd_manager tddm);
};

#endif

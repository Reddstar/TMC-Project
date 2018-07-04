#ifndef _RESOLVEUR_
#define _RESOLVEUR_

#include<ctype.h>
#include <cstdio>
#include<fstream>

#include "integer.h"
#include "configuration.h"
#include <vector>
#include <iterator>
#include "tddresolv.h"
#include "memuser.h"

//======================================================================
// Definition de la classe resolveur. 
// 
// Un resolveur comprend des tables de correspondance qui permettent
// d'assurer la liaison entre les variables du programme de simulation
// et les variables symboliques des equations et fonctions.
// La liste de ces variables symboliques et leurs attributs (etat, valeur,
// valeurs possibles) constitue une partie de l'etat du resolveur.
// Cet etat evolue sous l'action de differentes methodes comme
// l'instanciation d'une variable, la resolution de l'equation de la 
// configuration courante ou l'instanciation des fonctions de cette meme 
// configuration.
// L'instanciation d'une variable et l'instanciation des fonctions ou
// des parametres de l'equation on ete separes par souci d'efficacite.
//=======================================================================

class resolveur
{
  iri_tdd_manager tddm_re;
  std::vector<integer> liaison_C2R;
  std::vector<integer> liaison_E2R;
  std::vector<integer> liaison_Y2R;
  integer nb_E_lie;
  integer nb_C_lie;
  integer nb_Y_lie;

  std::vector<ptvariable> var_re;        // ensemble des variables gerees
  std::vector<configuration> config_re;  // ensemble des configurations gerees
  integer conf_cour_re;

  // automate pour lecture du fichier de description.

  void lecture_variables();
  void lecture_liaison_etats();
  void lecture_liaison_conditions();
  void lecture_liaison_capteurs();
  void lecture_listevar(std::vector<ptvariable> &lp);
  void lecture_equation();
  void lecture_configuration();
  fonction lecture_fonction();

public:

  resolveur();
  void chargement(char *file_name);
  void raz();
  void set_config(integer n);
  void set_etats(integer etats[], integer nb_etats);
  void set_conditions(integer conds[], integer nb_cond);
  void set_une_condition(integer num_ext, integer val);
  void set_mesures(integer yyy[], integer nb_yyy);
  void set_une_incontrolable(integer num_ext, integer val);
  void set_inconnue(integer num_ext, integer val);
  void init_resolution();
  void init_resolution_par_defaut();
  integer  get_valperm(integer *sol, integer nb_sol);
  void get_solution(integer *sol, integer nb_sol);

  // Pour debug
  void stat();
  void resolue();
  void bien_resolue();
};

#endif

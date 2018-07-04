#ifndef _RESOLVEUR_
#define _RESOLVEUR_

#include<ctype.h>
#include <cstdio>
#include<fstream>

#include "configuration.h"
#include <vector.h>
#include <iterator.h>
#include "tddresolv.h"

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
  vector<int> liaison_C2R;
  vector<int> liaison_E2R;
  vector<int> liaison_Y2R;
  int nb_E_lie;
  int nb_C_lie;
  int nb_Y_lie;

  vector<ptvariable> var_re;        // ensemble des variables gerees
  vector<configuration> config_re;  // ensemble des configurations gerees
  int conf_cour_re;

  // automate pour lecture du fichier de description.

  void resolveur::lecture_variables();
  void lecture_liaison_etats();
  void lecture_liaison_conditions();
  void lecture_liaison_capteurs();
  void lecture_init_memoires();
  void lecture_listevar(vector<ptvariable> &lp);
  void lecture_equation();
  void lecture_configuration();
  fonction lecture_fonction();

public:

  resolveur();
  void chargement(char *file_name);
  void raz();
  void set_config(int n);
  void set_etats(int etats[], int nb_etats);
  void set_conditions(int conds[], int nb_cond);
  void set_mesures(int yyy[], int nb_yyy);
  void set_inconnue(int num_ext, int val);
  void init_resolution();
  int  get_valperm(int *sol, int nb_sol);
  void get_solution(int *sol, int nb_sol);

  // Pour debug
  void stat();
  void resolue();
}

#endif

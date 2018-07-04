#ifndef _EQUATION_
#define _EQUATION_

#include "variable.h"

#include <cstdlib>
#include <vector>
#include <iterator>
#include "integer.h"
#include "tddresolv.h"
#include "memuser.h"

#include <cmath>

//========================================================================
//   Definition de la classe des equations
//========================================================================

class equation {
  tdd eq_init;                       // TDD representant l'equation
  tdd eq_courant;                    // TDD representant l'equation courante
  std::vector<ptvariable> parametres;     // parametres: inst. avant resolution
  integer nb_par;                        // nb de parametres
  integer par_inst;                      // nb de parametres instanties
  std::vector<ptvariable> inconnues;      // inconnues 
  integer nb_inc;                        // nb d'inconnues
  integer inc_inst;                      // nb d'inconnues calculees
  integer nb_var;                        // nb total de variables dans resolveur
  val_perm *vp;                      // memoire pour la resolution 

public:

  void set(iri_tdd_manager tddm, tdd eq, std::vector<ptvariable> param, std::vector<ptvariable> indeter);
  integer  is_inconnue(variable &v_inst);
  void instancier_une_inc(variable &v_inst, iri_tdd_manager tddm);
  void instancier_parametres(iri_tdd_manager tddm);
  void instancier_parametres_par_defaut(iri_tdd_manager tddm);
  void desinstancier(iri_tdd_manager tddm);
  integer  resoudre(iri_tdd_manager tddm);
  void resoudre_automatiquement(iri_tdd_manager tddm);
  void resolue(iri_tdd_manager tddm);
  void bien_resolue(iri_tdd_manager tddm);
};

#endif

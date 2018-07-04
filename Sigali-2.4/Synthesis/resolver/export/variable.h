//==========================================================================
//  Definition de la classe variable
//==========================================================================


#ifndef _VARIABLE_
#define _VARIABLE_

#include <cstdlib>
#include "tddresolv.h"

#define S_ABSENT 1
#define S_TRUE   2
#define S_FALSE  4

class variable {
  unsigned char etat;          // instantiee:2 ;partiellement inst.:1; non:0

public:

  tdd poly;                     // TDD associe
  unsigned char valeur;         // valeur instantiation
  int numero;                   // numero ordre dans ensemble des variables
  val_perm val_possible;        // valeurs proposees

  variable(int num, iri_tdd_manager tddm);

  void instancier( unsigned char val);
  void instancier_par_defaut();
  void desinstancier();
  int  set_sol(val_perm vp);
  int  inst_pred();
  int pre_inst();
};

typedef variable *ptvariable;

#endif

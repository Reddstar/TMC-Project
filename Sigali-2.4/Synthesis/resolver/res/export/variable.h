//==========================================================================
//  Definition de la classe variable
//==========================================================================


#ifndef _VARIABLE_
#define _VARIABLE_

#include <cstdlib>
#include "integer.h"
#include "tddresolv.h"

#define S_ABSENT 1
#define S_TRUE   2
#define S_FALSE  4

class variable {
  unsigned char etat;          // instantiee:2 ;partiellement inst.:1; non:0

public:

  tdd poly;                     // TDD associe
  unsigned char valeur;         // valeur instantiation
  integer numero;                   // numero ordre dans ensemble des variables
  val_perm val_possible;        // valeurs proposees

  variable(integer num, iri_tdd_manager tddm);

  void instancier( unsigned char val);
  void instancier_par_defaut();
  void desinstancier();
  integer  set_sol(val_perm vp);
  integer  inst_pred();
  integer pre_inst();
};

typedef variable *ptvariable;

#endif

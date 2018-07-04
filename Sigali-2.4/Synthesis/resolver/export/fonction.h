#ifndef _FONCTION_
#define _FONCTION_

#include <vector>
#include <iterator>
#include "tddresolv.h"
#include "memuser.h"

#include "variable.h"

//==========================================================================
// Definition de la classe fonction
// Une fonction est definie par la liste de ses arguments, la variable 
// qu'elle instancie et son corps defini par un TDD
//==========================================================================

class fonction
{
  tdd corps;
  ptvariable sortie;
  std::vector<ptvariable> arguments;
  int nb_arg;

public:

  void set(std::vector<ptvariable> arg, tdd poly, ptvariable out);
  void instancier(iri_tdd_manager tddm);
  void instancier_par_defaut(iri_tdd_manager tddm);
};

#endif

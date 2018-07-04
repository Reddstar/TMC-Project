#ifndef _FONCTION_
#define _FONCTION_

#include <vector.h>
#include <iterator.h>
#include "tddresolv.h"

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
  vector<ptvariable> arguments;
  int nb_arg;

public:

  void set(vector<ptvariable> arg, tdd poly, ptvariable out);
  void instancier(iri_tdd_manager tddm);
}

#endif

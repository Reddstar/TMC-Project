#include <cstdlib>
#include "integer.h"
#include "fonction.h"

//==================================================================
//  METHODES DE LA CLASSE FONCTION
//==================================================================

// Initialisation d'une fonction
//------------------------------
void fonction::set(std::vector<ptvariable> arg, tdd poly, ptvariable out)
{
  corps = poly;
  sortie = out;
  arguments = arg;
  nb_arg = arg.size();
}


// Instanciation d'une fonction
//-----------------------------
// Les arguments sont verifies et la valeur de la fonction calculee
// La variable de sortie est instanciee
  void fonction::instancier(iri_tdd_manager tddm)
{
  integer i;
  tdd *assoc,temp;
  var_assoc v_ass;
  std::vector<ptvariable>::iterator first,last;

  assoc = (tdd *) mem_get_block(2*nb_arg*sizeof(tdd)+1);
  assoc[2*nb_arg] = (tdd)0;
      
  // Construction de l'association => verif des arguments
  first = arguments.begin();
  last = arguments.end();
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
	  printf("\n fonction::instancie  - Argument non instancie \n");
	  printf(" Variable : %d\n", (*(*first)).numero);
	  mem_free_block((pointer) assoc);
	  exit(1);
	};
    };
  v_ass = tdd_new_assoc(tddm,assoc,1);

  // Evaluation et instanciation de la sortie
  temp = tdd_eval(tddm,corps,v_ass);
  (*sortie).instancier(const_tdd(tddm,temp));
  
  // Liberation
  tdd_free_assoc(tddm,v_ass);
  mem_free_block((pointer) assoc);
}

// Instanciation d'une fonction avec arguments par defaut
//-------------------------------------------------------
// Les arguments non instancies sont mis a absent et la valeur de la fonction calculee
// La variable de sortie est instanciee
  void fonction::instancier_par_defaut(iri_tdd_manager tddm)
{
  integer i;
  tdd *assoc,temp;
  var_assoc v_ass;
  std::vector<ptvariable>::iterator first,last;

  assoc = (tdd *) mem_get_block(2*nb_arg*sizeof(tdd)+1);
  assoc[2*nb_arg] = (tdd)0;
      
  // Construction de l'association => instantiation des arguments
  first = arguments.begin();
  last = arguments.end();
  i = 0;
  while (first != last)
    {
      (*(*first)).instancier_par_defaut();
      assoc[i] = (*(*first)).poly;
      assoc[i+1] = tdd_const(tddm,(*(*first)).valeur);
      i+=2; first++;
    };
  v_ass = tdd_new_assoc(tddm,assoc,1);

  // Evaluation et instanciation de la sortie
  temp = tdd_eval(tddm,corps,v_ass);
  (*sortie).instancier(const_tdd(tddm,temp));
  
  // Liberation
  tdd_free_assoc(tddm,v_ass);
  mem_free_block((pointer) assoc);
}

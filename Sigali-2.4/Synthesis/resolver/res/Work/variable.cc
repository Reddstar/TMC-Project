#include "variable.h"

#define INST 2
#define INDETER 0
#define PRE_INST 1
#define PERM 3
//================================================================
//  METHODES DE LA CLASSE VARIABLE
//================================================================

// Le constructeur de variable cree la variable tdd correspondante
variable::variable(int num, iri_tdd_manager tddm)
{
  etat = INDETER;
  poly = tdd_new_var_last(tddm);
  valeur = 0;
  numero = num;
  val_possible = 0;
}

// Passage au statut permanent
//----------------------------
void variable::set_perm(int valeur_init)
{
  etat = PERM;
  valeur = valeur_init;
}

// instancier
//-----------
// associe une valeur a une variable
// une tentative d'associer une valeur a une variable instanciee conduit a une erreur
// fatale.
void variable::instancier( unsigned char val)
{
  if (etat==INST) 
    {
      printf("\n Tentative de reinstantiation d'une variable instanciee \n");
      exit(1);
    }
  etat = INST;
  valeur = val;
  switch (val)
    {
    case 0: val_possible = S_ABSENT; break;
    case 1: val_possible = S_TRUE; break;
    case 2: val_possible = S_FALSE; break;
    default: { printf("\n variable::instancier  Erreur dans valeur\n"); exit(1);}
    }
    
}

// Desinstancier
//--------------
// Libere la liaison valeur - variable pouvant exister
void variable::desinstancier()
{
  if (etat != PERM) etat = INDETER;
}

// inst_pred
//----------
// teste si une variable est instanciee
int variable::inst_pred()
{
  return ((etat == INST)||(etat == PERM));
}

// pre_inst
//---------
// teste si la variable a ete pre-instanciee: instanciee ou valeurs proposees
int variable::pre_inst()
{
  return ((etat == PERM)||(etat == INST)||(etat == PRE_INST));
}
// set_sol
//--------
// associe a une variable un ensemble de valeurs possibles
// Si une seule valeur est proposee, la variable est instanciee
// par cette valeur. Dans ce cas la valeur retournee est 1(0 autrement).
int variable::set_sol(val_perm vp)
{
  int i,nbsol, result;

  if ((etat==INST) || (etat == PERM))  return 0; 
  // la variable est instanciee - pas de modif

  result = 0;
  etat = PRE_INST;
  nbsol = 0;
  if ( vp & VAL0) nbsol++;
  if ( vp & VAL1) nbsol++;
  if ( vp & VAL2) nbsol++;
  if (nbsol == 1)          // une seule solution => instanciation
    {
      etat = INST;
      if( vp == VAL0 ) valeur = 0;
      if( vp == VAL1 ) valeur = 1;
      if( vp == VAL2 ) valeur = 2;
      result = 1;
    }
  val_possible = vp;
  return result;
}



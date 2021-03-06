#include <cstdio>

#include "resolveur.h"
#include "variable.h"

resolveur::resolveur()
{
  tddm_re = iri_tdd_init();
}
// Desinstanciation generale
//--------------------------

void resolveur::raz()
{
  vector<configuration>::iterator first,last;
  vector<ptvariable>::iterator firstv,lastv;

  // desinstanciation des variables
  firstv = var_re.begin();
  lastv = var_re.end();
  while(firstv != lastv)
    {
      (*(*firstv)).desinstancier();
      firstv++;
    }

  // desinstanciation des equations
  first = config_re.begin();
  last = config_re.end();
  while (first != last)
    {
      (*first).desinstancier(tddm_re);
      first++;
    }
}

// Ensemble de fonctions assurant le chargement
//=============================================

//static char carlu; // dernier caractere lu
//static ifstream  entree;
static int carlu;
static FILE *fich;

// La fonction suivante passe les blancs et \n et positionne 
// carlu sur le premier caractere significatif non consomme
// sur zero si fin de fichier.
static void next_char()
{ 
    do
      {
	//	if(!(entree.get(carlu))) carlu = (char) 0;
	carlu = getc(fich);
	if(carlu == EOF) carlu = 0;
      } 
    while (isspace(carlu)|| carlu=='\n');
}

// Lecture d'un entier
//--------------------
static int lire_entier()
{
  int resu;
  resu = 0;

  while(isdigit(carlu))
    {
      resu = 10*resu +(carlu - '0');
      //      entree.get(carlu);
      carlu = getc(fich);
    }
  return resu;
}

// Lecture du nombre de variables et initialisation
//-------------------------------------------------
void resolveur::lecture_variables()
{
  int nbvar, i;
  ptvariable var;

  next_char();
  nbvar = lire_entier();

  // Creation des variables du resolveur
  for (i=0;i<nbvar;i++)
    {
      var = new variable(i, tddm_re);
      var_re.push_back(var);
    }
}

// Lecture de la table de liaison des etats
//-----------------------------------------
void resolveur::lecture_liaison_etats()
{
  int i,n, nb;

  next_char();
  nb = 0;
  while (isdigit(carlu))
    {
      n = lire_entier();
      liaison_E2R.push_back(n);
      nb++;
      next_char();
    }
  nb_E_lie = nb;
}

// Lecture de la table de liaison des conditions
//----------------------------------------------
void resolveur::lecture_liaison_conditions()
{
  int i,n, nb;

  next_char();
  nb = 0;
  while (isdigit(carlu))
    {
      n = lire_entier();
      liaison_C2R.push_back(n);
      nb++;
      next_char();
    }
  nb_C_lie = nb;
}

// Lecture de la table de liaison des capteurs
//--------------------------------------------
void resolveur::lecture_liaison_capteurs()
{
  int i,n, nb;

  next_char();
  nb = 0;
  while (isdigit(carlu))
    {
      n = lire_entier();
      liaison_Y2R.push_back(n);
      nb++;
      next_char();
    }
  nb_Y_lie = nb;
}

// Lecture d'une liste de variables
//---------------------------------
void resolveur::lecture_listevar(vector<ptvariable> &li)
{
  int ip;

  next_char();
  while (isdigit(carlu))
    {
      ip = lire_entier();
      li.push_back(var_re[ip]);
      next_char();
    }
}

// Lecture d'une fonction
//-----------------------
fonction resolveur::lecture_fonction()
{
  tdd poly;
  int ierror,non_termine, output;
  vector<ptvariable>  arguments;
  fonction fonc;

  non_termine = 1;
  next_char();
  while (non_termine)
    {
      if (carlu != '$') 
	{
	  printf("\n Resolveur::chargement/F - Erreur dans fichier \n");
	  exit(1);
	}
      else
	{
	  next_char();
	  switch (carlu)
	    {
	    case 'Q' :
	      {
		ierror = 0;
		//		poly = tdd_undump_tdd_re(tddm_re, entree, &ierror);
		poly = tdd_undump_tdd_re(tddm_re, fich, &ierror);
		if(ierror) 
		  {
		    printf("\n Erreur lecture TDD \n");
		    exit(1);
		  }

		next_char();
		break;
	      }
	    case 'A' :
	      {
		lecture_listevar(arguments);
		break;
	      }
	    case 'O' :
	      {
		next_char();
		output = lire_entier();
		next_char();
		break;
	      }
	    case '$':
	      {
		non_termine = 0;
		next_char();
		break;
	      }
	    default:
	      {
		printf("\n Resolveur::chargement/F -  Mauvais format de fichier \n");
		exit(1);
	      }
	    }
	}
    }
  fonc.set(arguments, poly, var_re[output]);
  return fonc;
}



// Lecture d'une configuration
//---------------------------- 
void resolveur::lecture_configuration()
{
  tdd equa;
  int ierror,non_termine;
  vector<ptvariable> parametres, inconnues, output_conf;
  vector<fonction> fonctions;
  configuration conf;

  equa = tdd_const(tddm_re,0);/* au cas ou il n'y en aurait pas */
  non_termine = 1;
  next_char();
  while (non_termine)
    {
      if (carlu != '$') 
	{
	  printf("\n Resolveur::chargement/C - Erreur dans fichier \n");
	  exit(1);
	}
      else
	{
	  next_char();
	  switch (carlu)
	    {
	    case 'Q' :
	      {
		ierror = 0;
		//equa = tdd_undump_tdd_re(tddm_re, entree, &ierror);
		equa = tdd_undump_tdd_re(tddm_re, fich, &ierror);
		if(ierror) 
		  {
		    printf("\n Erreur lecture TDD \n");
		    exit(1);
		  }

		next_char();
		break;
	      }
	    case 'O' :
	      {
		lecture_listevar(output_conf);
		break;
	      }
	    case 'P' :
	      {
		lecture_listevar(parametres);
		break;
	      }
	    case 'I' :
	      {
		lecture_listevar(inconnues);
		break;
	      }
	    case 'F' :
	      {
		fonctions.push_back(lecture_fonction());
		break;
	      }

	    case '$':
	      {
		non_termine = 0;
		next_char();
		break;
	      }
	    default:
	      {
		printf("\n Resolveur::chargement/C -  Mauvais format de fichier \n");
		exit(1);
	      }
	    }
	}
    }
  conf.set(tddm_re,equa,parametres,inconnues,output_conf,fonctions);
  config_re.push_back(conf);
}

// Lecture et initialisation des memoires
//---------------------------------------
void resolveur::lecture_init_memoires()
{
  int valeur, numero;

  next_char();
  while(carlu != '$')
    {
      numero = lire_entier();
      if (carlu != ':')
	{
	  printf("\n Mauvaise syntaxe pour l'initialisation des memoires");
	  exit(1);
	}
      next_char();
      valeur = lire_entier();
      (*(var_re[numero])).set_perm(valeur);
      next_char();
    }
  
}

// Chargement d'un fichier de description d'un resolveur
//------------------------------------------------------
void resolveur::chargement(char *file_name)
{
  int non_termine;
  int error;

  non_termine = 1;
  //  entree.open(file_name);
  //  if ( !entree.is_open())
  //    {
  //      printf("\n Resolveur::chargement/R - Erreur ouverture fichier \n");
  //      exit(1);
  //    }
  fich = fopen(file_name, "r");
  if ( fich == NULL )
     {
       printf("\n Resolveur::chargement/R - Erreur ouverture fichier \n");
       exit(1);
     }
  
  next_char(); 
  while (non_termine)
    {
      if (carlu != '$') 
	{
	  printf("\n Resolveur::chargement/R - Erreur dans fichier \n");
	  exit(1);
	}
      else
	{
	  next_char();
	  switch (carlu)
	    {
	    case 'V' :
	      {
		lecture_variables();
		next_char();
		break;
	      }
	    case 'E' :
	      {
		lecture_liaison_etats();
		break;
	      }
	    case 'C' :
	      {
		lecture_liaison_conditions();
		break;
	      }
	    case 'Y' :
	      {
		lecture_liaison_capteurs();
		break;
	      }
	    case 'T':
	      {
		printf("\n  T Not yet implemented ...\n");
		exit(1);  // Pour tables de liaison anonymes ??
		break;
	      }
	    case 'M':
	      {
		lecture_init_memoires();
		break;
	      }
	    case 'R':
	      {
		lecture_configuration();
		break;
	      }
	    case '$':
	      {
		non_termine = 0;
		break;
	      }

	    default:
	      {
		printf("\n Resolveur::chargement/R -  Mauvais format de fichier \n");
		exit(1);
	      }
	    }
	}
    }
}

// Exploitation du resolveur
//==========================
// Choix de la configuration courante
//-----------------------------------
void resolveur::set_config(int n)
{
  int nb_config;

  nb_config = config_re.size();
  if((n<0)||(n>(nb_config-1)))
    {
      printf("\n resolveur::set_config - numero de configuration incorrect \n");
      return;
    }
  else
    conf_cour_re = n;
}

// Instantiation des variables etat (E)
//-------------------------------------
void resolveur::set_etats(int etats[], int nb_etats)
{
  int i;
  
  if(nb_etats > nb_E_lie)
    {
      printf("\n Erreur sur le nombre d'etats \n");
      exit(1);
    }
  for (i=0;i<nb_etats; i++)
    {
      (*(var_re[liaison_E2R[i]])).instancier((unsigned char) etats[i]);
    }
}

// Instanciation des conditions
//-----------------------------
void resolveur::set_conditions(int conds[], int nb_cond)
{
  int i;
  
  if(nb_cond > nb_C_lie)
    {
      printf("\n Erreur sur le nombre de conditions \n");
      exit(1);
    }
  for (i=0;i<nb_cond; i++)
    {
      (*(var_re[liaison_C2R[i]])).instancier((unsigned char) conds[i]);
    }
}

// Instantiation des fonctions et de l'equation avant resolution
//--------------------------------------------------------------
void resolveur::init_resolution()
{
  config_re[conf_cour_re].instancier_param(tddm_re);
}

// Instanciation des non-controlables
//-----------------------------------
void resolveur::set_mesures(int yyy[], int nb_yyy)
{
  int i;
  
  if(nb_yyy > nb_Y_lie)
    {
      printf("\n Erreur sur le nombre de non-controlables \n");
      exit(1);
    }
  for (i=0;i<nb_yyy; i++)
    {
      (*(var_re[liaison_Y2R[i]])).instancier((unsigned char) yyy[i]);
    }
}


// Instanciation d'une inconnue
//-----------------------------
void resolveur::set_inconnue(int num_ext, int val)
{
  config_re[conf_cour_re].instancier_inconnue(num_ext,(unsigned char)val,tddm_re);
}


// propositions de valeurs pour les indeterminees
//-----------------------------------------------
int resolveur::get_valperm(int *sol, int nb_sol)
{
  unsigned char *sol_cod;
  int fini,i;

  sol_cod = (unsigned char *)malloc(nb_sol*sizeof(unsigned char));
  fini = config_re[conf_cour_re].get_valperm(sol_cod,nb_sol,tddm_re);
  for(i=0;i<nb_sol;i++)
    {
      sol[3*i] = (int)sol_cod[i]&VAL0;
      sol[3*i+1] = (int)(sol_cod[i]&VAL1)>>1;
      sol[3*i+2] = (int)(sol_cod[i]&VAL2)>>2;
    }
  free(sol_cod);
  return fini;
}

// resolution automatique
//-----------------------
void resolveur::get_solution(int *sol, int nb_sol)
{
  unsigned char *sol_cod;
  int fini,i;

  sol_cod = (unsigned char *)malloc(nb_sol*sizeof(unsigned char));
  config_re[conf_cour_re].get_solution(sol_cod,nb_sol,tddm_re);
  for(i=0;i<nb_sol;i++)
    {
      sol[3*i] = (int)sol_cod[i]&VAL0;
      sol[3*i+1] = (int)(sol_cod[i]&VAL1)>>1;
      sol[3*i+2] = (int)(sol_cod[i]&VAL2)>>2;
    }
  free(sol_cod);
}


//=================================
// Methodes utilisees pour le debug
//---------------------------------
void resolveur::stat()
{
  printf("\n liaisons_C : %d \n", liaison_C2R.size());
  printf("\n liaisons_E : %d \n", liaison_E2R.size());
  printf("\n liaisons_Y : %d \n", liaison_Y2R.size());
  printf("\n nb variables : %d \n", var_re.size());
  printf("\n nb configurations : %d \n", config_re.size());
}

void resolveur::resolue()
{
  config_re[conf_cour_re].resolue(tddm_re);
}

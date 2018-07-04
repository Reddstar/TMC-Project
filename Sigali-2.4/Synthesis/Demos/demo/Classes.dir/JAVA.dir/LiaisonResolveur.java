/**
 * LiaisonResolveur.java
 * <dt> Cette classe permet de faire le lien entre le code ecrit en C++ par SIGNAL
 * et la classe InteResolv.java.
 * <dt> Cette classe n'existe que par souci de clarte et de modularite, 
 * en effet, InteResolv.java aurait tres bien pu appeler directement des fonctions en C++
 * du resolveur en les declarant natives. 
 * La classe LiaisonResolveur.java evite donc de meler des fonctions natives au code java de
 * InteResolv.java.
 * <dt>Le principe est simple : 
 * <pre>
 *   La classe InteResolv.java possede une instance LR de la classe LiaisonResolveur.java.
 *   Si InteResolv.java a besoin d'une fonction ecrite en C++, il l'appelle en prefixant
 *   le nom de la fonction C++ de "LR.". 
 *   A chaque methode de LiaisonResolveur.java, appelee par InteResolv.java, 
 *   corresponds une fonction native.
 *   Le code de chaque fonction native se trouve dans le fichier LiaisonResolveur.c,
 *   et, dans ce code ecrit en C++, 
 *   on trouve l'appel a la fonction voulu du resolveur et les conversions necessaires
 *   au passage des parametres.
 * </pre>
 * <dt>
 * Created: Wed Jul 22 10:50:13 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see InteResolv
 * 
 */

public class LiaisonResolveur {

    //***********************************
    // Declarations des fonctions natives
    //***********************************

    /** Chargement d'un fichier de description d'un resolveur */
    native void n_chargement(String file_name);
    /** Desinstanciation generale */
    native void n_raz();
    /** Choix de la configuration courante */
    native void n_set_config(int n);
    /** Instantiation des variables etat (E) */
    native void n_set_etats(int etats[],int nb_etats);
    /** Instanciation des conditions */
    native void n_set_conditions(int conds[],int nb_cond);
    /** instanciation d'une condition */
    native void n_set_une_condition(int num_ext, int val);
    /** Instanciation des non-controlables */
    native void n_set_mesures(int yyy[], int nb_yyy);
    /** Instanciation d'une incontrolable */
    native void n_set_une_incontrolable(int num_ext, int val);
    /** Instanciation d'une inconnue */
    native void n_set_inconnue(int num_ext, int val);
    /** Instantiation des fonctions et de l'equation avant resolution */
    native void n_init_resolution();
    /** Instantiation des fonctions et de l'equation avant resolution */
    native void n_init_resolution_par_defaut();
    /** propositions de valeurs pour les indeterminees */
    native boolean n_get_valperm(int[] sol, int nb_sol);
    /** resolution automatique */
    native void n_get_solution(int[] sol, int nb_sol);

    //**************************************
    // Constructeur de classe qui appelle le
    // chargement de la librairie VTAGVLIB
    //**************************************

    static {
   	System.loadLibrary("VTAGVLIB");
   };

     
    //***********************************
    // Methodes appelees par InteResolv
    //***********************************

    public synchronized void chargement(String file_name){
	n_chargement(file_name);
    }

    public synchronized void raz(){
	n_raz();
    }

    public synchronized void set_config(int n){
	n_set_config(n);
    }

    public synchronized void set_etats(int[] etats,int nb_etats){
	n_set_etats(etats,nb_etats);
    }

    public synchronized void set_conditions(int[] conds,int nb_cond){
	n_set_conditions(conds,nb_cond);
    }

    public synchronized void set_une_condition(int num_ext, int val){
	n_set_une_condition(num_ext,val);
    }

    public synchronized void set_mesures(int[] yyy, int nb_yyy){
	n_set_mesures(yyy,nb_yyy);
    }

    public synchronized void set_une_incontrolable(int num_ext, int val){
	n_set_une_incontrolable(num_ext,val);
    }

    public synchronized void set_inconnue(int num_ext, int val){
	n_set_inconnue(num_ext,val);
    }

    public synchronized void init_resolution(){
	n_init_resolution();
    }

    public synchronized void init_resolution_par_defaut(){
	n_init_resolution_par_defaut();
    }

    public synchronized boolean get_valperm(int[] sol, int nb_sol){
	return n_get_valperm(sol,nb_sol);
    }

    public synchronized void  get_solution(int[] sol, int nb_sol){
	n_get_solution(sol, nb_sol);
    }

    public LiaisonResolveur(){
    }

    
} // LiaisonResolveur

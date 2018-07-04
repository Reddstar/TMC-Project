/**
 * LiaisonBody.java
 * <dt> Cette classe permet de faire le lien entre le code ecrit en C++ par SIGNAL
 * et la classe vt.java. Deplus elle gere aussi tous les appels SIGNAl aux methodes java.
 * <dt> Le principe d'utilisation des methodes natives est similaire 
 * au principe explique dans le fichier LiaisonResolveur.java.
 * <dt>
 * Created: Thu Jul 30 12:23:03 1998
 *
 * @author Herve Marchand
 * @version
 * @see vt
 */

public class LiaisonBody {

    // DEBUT PARTIE NON GENERIQUE
   
    //******************************************
    // Methodes java appelees par LiaisonBody.c
    //****************************************** 
    public void wstop(){ vt.wstop();}
    public void Draw(boolean CC, boolean B1, boolean B2, boolean B3, boolean B4){ 
	vt.Draw(CC,B1,B2,B3,B4);} 

    // FIN PARTIE NON GENERIQUE

    public void reset_panel(boolean cauto){PacemakerAction.reset_panel(cauto);}

    /** Cette methode appelle la methode du meme nom de la classe InteResolv.
     *  Cette methode n'a pas ete ecrite dans la classe LiaisonResolveur.java,
     *  car c'est la seule methode de InteResolv qui est appelee par la patie en C++.
     *  Il aurait donc fallu ajouter a LiaisonResolveur.java une methode native de 
     *  connection pour cette seule methode (resolver). 
     *  J'ai donc preferer la mettre ici pour profiter de la methode 
     *  connectionBody.
     */
    public void resolver(int cod_cond[], int cod_x[], int cod_u[],
			   int cod_y[], boolean fin_resolver[]){
	vt.IR.resolver(cod_cond, cod_x, cod_u, cod_y, fin_resolver);
    }

    /** Cette methode appelle la methode du meme nom de la classe PacemakerVitesse.java
     *  Cette methode n'a pas ete ecrite dans la classe PacemakerVitesse.java
     *  pour les memes raisons que la methode resolver n'a pas ete ecrite dans la 
     *  classe LiaisonResolveur.java.
     */
    public void ecritVitesse(int v){
	vt.IR.pacemaker.paceV.ecrit(v);
    }

    //***********************************
    // Declarations des fonctions natives
    //*********************************** 

    /** Cette fonction sert a initialiser la liaison.
     *  et doit etre appele regulierement, car les adresses
     *  des objets java peuvent etre desalouees et changees.
     *  Cette initialisation consiste a indiquer au code C++ 
     *  les adresses des objets java dont il a besoin.
     */
    native void connexionBody();

    native boolean n_vt_initialise();
    native boolean n_vt_iterate();
    native void n_set_variable(int nbEtat, int nbCond, int nbEntCont, int nbEntIncont);

    //**************************************
    // Constructeur de classe qui appelle le
    // chargement de la librairie VTAGVLIB
    //**************************************

    static {
	System.loadLibrary("VTAGVLIB");
    };

    //***********************************
    // Methodes appelees par vt.java
    //***********************************

    public synchronized boolean vt_initialize(){
	return n_vt_initialise();
    }

    public synchronized boolean vt_iterate(){
	return n_vt_iterate();
    }

    public synchronized void set_variables(int nbEtat, int nbCond, int nbEntCont, int nbEntIncont){
	n_set_variable(nbEtat, nbCond, nbEntCont , nbEntIncont);
    }

    public LiaisonBody(){
	connexionBody();
    }
    
} // LiaisonBody

/**
 * LiaisonBody.java
 * <dt> Cette classe permet de faire le lien entre le code ecrit en C++ par SIGNAL
 * et la classe vt.java. Deplus elle gere aussi tous les appels SIGNAl aux methodes java.
 * <dt> Le principe d'utilisation des methodes natives est similaire 
 * au principe explique dans le fichier LiaisonResolveur.java.
 * <dt>
 * Created: Thu Jul 30 12:23:03 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see vt
 */

public class LiaisonBody {
   
    //******************************************
    // Methodes java appelees par LiaisonBody.c
    //****************************************** 
    public void wstop(){ vt.wstop();} 
    public void dessine_chariot_agv1(int Pos_AGV1[]){ vt.dessine_chariot_agv1(Pos_AGV1);}
    public void dessine_chariot_agv2(int Pos_AGV2[]){ vt.dessine_chariot_agv2(Pos_AGV2);}
    public void dessine_chariot_agv3(int Pos_AGV3[]){ vt.dessine_chariot_agv3(Pos_AGV3);}
    public void dessine_chariot_agv4(int Pos_AGV4[]){ vt.dessine_chariot_agv4(Pos_AGV4);}
    public void dessine_chariot_agv5(int Pos_AGV5[]){ vt.dessine_chariot_agv5(Pos_AGV5);}
    public void dessine_chariot_wst1(int Pos_WST1[]){ vt.dessine_chariot_wst1(Pos_WST1);}
    public void dessine_chariot_wst2(int Pos_WST2[]){ vt.dessine_chariot_wst2(Pos_WST2);}
    public void dessine_chariot_wst3(int Pos_WST3[]){ vt.dessine_chariot_wst3(Pos_WST3);}
    public void dessine_chariot_wst4(int Pos_WST4[]){ vt.dessine_chariot_wst4(Pos_WST4);}
    public void dessine_chariot_wst5(int Pos_WST5[]){ vt.dessine_chariot_wst5(Pos_WST5);}
    public void affiche_conflit(int a, int b, int c, int d){ vt.affiche_conflit(a,b,c,d);}

    public void reset_panel(boolean cauto){ 
	PacemakerAction.reset_panel(cauto);
    }

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

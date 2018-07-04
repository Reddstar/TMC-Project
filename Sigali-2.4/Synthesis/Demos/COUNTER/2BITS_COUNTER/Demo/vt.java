import java.awt.*;
import javax.swing.*;

/**
 * vt.java
 * Programme principal : Control of an excavation Machine
 * <dt>
 * Created:  Jan   2001
 *
 * @author Hervé Marchand
 * @version
 * @see State
 * @see Plan
 * @see InteResolv
 */

public class vt extends Fenetre implements Runnable {

    
 
    /** lien avec le vt_body ecrit en C */
    static LiaisonBody LV = new LiaisonBody();

    /** Interface du resolver */
    static InteResolv IR = new InteResolv("vt.sim","vt.res");

    /** represente le plan de l'application */
    static Plan plan = new Plan();
  
    static State state[] = new State[1]; 

    /* Dessine les taches du bras */
    public static void Draw(boolean CC, boolean B1, boolean B2){
	state[0].Dessine(B1,B2); 
    }  

    /** methode externe pour quitter l'application */
    public static void wstop(){
	System.out.println("FIN");
	System.exit(0);
   }

    /** iteration : appelee a chaque instant */
    public void run(){
	while (true) {
            try {Thread.sleep(10*IR.pacemaker.paceV.vitesse);} catch (InterruptedException ie){};
            ModesResolv.verif();
            /* pour garder en vie les references des methodes
               appelees par les modules ecrits en C++ */
            LV.connexionBody();
            if(LV.vt_iterate()){};
        }
    }


    /** initialisation */
    public vt() { 
	super("Control of an Excavation Machine");
	add(plan);
	if(LV.vt_initialize()){};
	Thread iterateur = new Thread(this);

 	// initialisation des etats et coordonnees de ceux-ci
	int[] chemin2x = {75-18,
			  352-22,
			  352-20,
			  75-18};
  	int[] chemin2y = {76,
			  76,
			  285,
			  285};
	state[0]  = new State(chemin2x,chemin2y,0);

	setBackground(Color.gray);
	setVisible(true);
       	setSize(plan.largeur+10,plan.hauteur+20); 
	iterateur.start();
	setLocation(5,5);
    }


    /** lancement de l'application */
    public static void main(String[] args) {
	vt application = new vt();
    }
} // vt

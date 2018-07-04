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
  
    static Bit bit[] = new Bit[4];
    static Carry c[] = new Carry[1]; 

    /* Dessine les taches du bras */
    public static void Draw(boolean CC, boolean B1, boolean B2, boolean B3, boolean B4){
	bit[0].Dessine(B1); 
	bit[1].Dessine(B2); 
	bit[2].Dessine(B3); 
	bit[3].Dessine(B4); 
	c[0].Dessine(CC); 
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
	super("");
	add(plan);
	if(LV.vt_initialize()){};
	Thread iterateur = new Thread(this);

 	// initialisation des etats et coordonnees de ceux-ci 
	bit[3]  = new Bit(10,20);   
	bit[2]  = new Bit(30,20);
	bit[1]  = new Bit(50,20);
	bit[0]  = new Bit(70,20);
	c[0]    = new Carry(95,20);
	setBackground(Color.gray);
	setVisible(true);
       	setSize(plan.largeur+10,plan.hauteur+20); 
	iterateur.start();
	setLocation(15,45);
    }


    /** lancement de l'application */
    public static void main(String[] args) {
	vt application = new vt();
    }
} // vt

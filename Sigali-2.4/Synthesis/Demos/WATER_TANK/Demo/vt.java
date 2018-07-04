import java.awt.*;
import javax.swing.*;

/**
 * vt.java
 * Programme principal : Controle et diagnostic d'une Pompe
 * <dt>
 * Created: Tue Jul 28 11:28:05 1998
 *
 * @author Hervé Marchand
 * @version
 * @see Flow
 * @see State
 * @see Valve
 * @see Plan
 * @see InteResolv
 */

public class vt extends Fenetre implements Runnable {

    /** lien avec le vt_body ecrit en C */
    static LiaisonBody LV = new LiaisonBody();

    /** Interface du resolver */
    static InteResolv IR = new InteResolv("vt.sim","vt.res");

    /** represente le plan de la maison */
    static Plan plan = new Plan();
  
    /** l'etat du flot de la valve */
    static  Flow  flow;
    static  Valve[] val = new Valve[2];
    static  State  state;

    /** methode externe pour dessiner le flot de la pompe  */ 
    public static void Draw(boolean  Flow_Pump, boolean  Flow_Valve2, boolean  Valve2,boolean Valve3, boolean Valve4){
 		flow.Dessine(Flow_Pump, Flow_Valve2,Valve2);
		val[0].Dessine(Valve3);
		val[1].Dessine(Valve4);
		
    } 

    /** methode externe pour dessiner le flot de la pompe  */ 
    public static void Draw_State(boolean X0,boolean X1,boolean X2,boolean X3,boolean X4,boolean X5,boolean X6,boolean Flow){
	state.Dessine( X0, X1, X2, X3, X4, X5, X6, Flow); 
    } 


    /** methode externe pour quitter l'application */
    public static void wstop(){
	System.out.println("END");
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
	super("A Water Tank Example");
	add(plan);
	if(LV.vt_initialize()){};
	Thread iterateur = new Thread(this);

	int[] chemin0x = {330,
			  502};
  	int[] chemin0y = {505,
			  505};
	int[] chemin1x = {390,
			  525,
	                  457};
  	int[] chemin1y = {215,
			  215};
	flow = new Flow();   
	val[0] = new Valve(433,400);  
	val[1] = new Valve(592,400);  
	state = new State(); 
	setBackground(Color.gray);
	setVisible(true);
       	setSize(plan.largeur+10,plan.hauteur+20);
	iterateur.start();
	setLocation(20,20);
    }


    /** lancement de l'application */
    public static void main(String[] args) {
	vt application = new vt();
    }
} // vt

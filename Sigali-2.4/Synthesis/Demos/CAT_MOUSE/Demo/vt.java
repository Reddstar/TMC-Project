import java.awt.*;
import javax.swing.*;

/**
 * vt.java
 * Programme principal : LES CHARIOTS FILOGUIDES
 * <dt>
 * Created: Tue Jul 28 11:28:05 1998
 *
 * @author Hervé Marchand
 * @version
 * @see Animal
 * @see Plan
 * @see InteResolv
 */

public class vt extends Fenetre implements Runnable {
    static  final int Coef=1;

    /** codage de la valeur TRUE */
    static int TRUE = 1;

    /** codage de la valeur FALSE */
    static int FALSE = 0;

    /** lien avec le vt_body ecrit en C */
    static LiaisonBody LV = new LiaisonBody();

    /** Interface du resolver */
    static InteResolv IR = new InteResolv("vt.sim","vt.res");

    /** represente le plan de la maison */
    static Plan plan = new Plan();

    /** les 2 animaux */
    static Animal[] animal = new Animal[2];

    /** methode externe pour dessiner le chat */
    public static void Draw_Cat(int Pos_Cat[]){
        animal[0].Dessine(Pos_Cat);
    }
    /** methode externe pour dessiner la souris  */
    public static void Draw_Mouse(int Pos_Mouse[]){
	animal[1].Dessine(Pos_Mouse);
    }

    /** portes du chat  */
    static Porte[] porte_chat = new Porte[6];
    /** methode externe pour dessiner les portes du chat  */
    public static void Draw_Door_Cat(int Door_Cat[]){
	int pos;
	for (int i=0; i<6; i++){
	    pos=Door_Cat[i+1];
	    porte_chat[i].Dessine(pos);}
    }

    /** portes de la souris  */
    static Porte[] porte_souris = new Porte[6];
    /** methode externe pour dessiner les portes de la souris  */
    public static void Draw_Door_Mouse(int Door_Mouse[]){
	int pos;
	for (int i=0; i<6; i++){
	    pos=Door_Mouse[i+1];
	    porte_souris[i].Dessine(pos);}
    }


    /** methode externe pour quitter l'application */
    public static void wstop(){
	System.out.println("END");
	System.exit(0);
   }

    /** methode externe pour afficher Conflit */
    public static void Draw_Conflict(int Conflict){
	if ((Conflict==1)) JOptionPane.showMessageDialog(plan, "Conflict Cat/Mouse");
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
	super("Supervisory Control Problem: The Cat and Mouse Example");
	add(plan);
	if(LV.vt_initialize()){};
	Thread iterateur = new Thread(this); 

 	// initialisation du chat et de la souris
	// Le chat
	int[] chemin1x = {380/Coef-100,100/Coef-50,380/Coef-95,100/Coef-50,380/Coef-100};
  	int[] chemin1y = {290/Coef,75/Coef,75/Coef,300/Coef,410/Coef};
	animal[0] = new Animal(chemin1x,chemin1y,5,0,2);
	// La Souris
	int[] chemin2x = {300/Coef,100/Coef,300/Coef,100/Coef,300/Coef};
  	int[] chemin2y = {220/Coef,180/Coef,100/Coef,450/Coef,460/Coef};
	animal[1] = new Animal(chemin2x,chemin2y,5,1,4);
	// portes de la souris
	// porte 1
	int chemin9x = 325;
	int chemin9y = 190;
	porte_souris[0] = new Porte(chemin9x,chemin9y,Color.red,0);
	// porte 2
	int chemin10x = 250;
	int chemin10y = 127;
	porte_souris[1] = new Porte(chemin10x,chemin10y,Color.red,1);
	// porte 3
	int chemin11x = 250;
	int chemin11y = 210;
	porte_souris[2] = new Porte(chemin11x,chemin11y,Color.red,1);
	// porte 4
	int chemin12x = 325;
	int chemin12y = 390;
	porte_souris[3] = new Porte(chemin12x,chemin12y,Color.red,0);
	// porte 5
	int chemin13x = 250;
	int chemin13y = 431;
	porte_souris[4] = new Porte(chemin13x,chemin13y,Color.red,1);
	// porte 6
	int chemin14x = 250;
	int chemin14y = 305;
	porte_souris[5] = new Porte(chemin14x,chemin14y,Color.red,1);
	// portes du chat //
	// porte 1
	int chemin3x = 250;
	int chemin3y = 240;
	porte_chat[0] = new Porte(chemin3x,chemin3y,Color.blue,1);
	// porte 2
	int chemin4x = 250;
	int chemin4y = 66;
	porte_chat[1] = new Porte(chemin4x,chemin4y,Color.blue,1);
	// porte 3
	int chemin5x = 410;
	int chemin5y = 190;
	porte_chat[2] = new Porte(chemin5x,chemin5y,Color.blue,0);
	// porte 4
	int chemin6x = 250;
	int chemin6y = 345;
	porte_chat[3] = new Porte(chemin6x,chemin6y,Color.blue,1);
	// porte 5
	int chemin7x = 250;
	int chemin7y = 491;
	porte_chat[4] = new Porte(chemin7x,chemin7y,Color.blue,1);
	// porte 6
	int chemin8x = 410;
	int chemin8y = 390;
	porte_chat[5] = new Porte(chemin8x,chemin8y,Color.blue,0);



	setBackground(Color.gray);
	setVisible(true);
       	setSize(plan.largeur+10,plan.hauteur+20);
	IR.fenCont.setLocation(600,200);
	iterateur.start();
	setLocation(20,100); 
    }


    /** lancement de l'application */
    public static void main(String[] args) {
	vt application = new vt();
    }
} // vt

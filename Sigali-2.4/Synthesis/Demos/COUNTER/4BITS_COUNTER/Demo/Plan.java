import java.awt.*;

/**
 * Plan.java
 * Affichage de l'etat courant des differentes taches.
 *
 * Created: Tue Jul 28 12:02:35 1998
 *
 * @author Herve Marchand
 * @version
 * @see vt
 */

public class Plan extends Panel {
    Image state; 
 
  
    static String gifDir = "Demo/";
    public Font fontSelected; //fonte qui sera selectionnee
  
    Image Fond;
  
    /** largeur de l'appli en pixels */
    static final int largeur = 100;

    /** hauteur de l'appli en pixels */
    static final int hauteur = 30;
   
    /** affiche l'image de l'appli */
    public void paint(Graphics g){
      g.drawString("Compteur 4bits",5,12);
      g.drawRect( 8, 18, 80, 23);	     
    }

    /** reaffiche l'appli.
     *  Cette methode est redefini, car par defaut, 
     *  elle efface le composant avant de le repeindre.
     *  Ce qui est une perte de temps.
     */
    public void update(Graphics g){
	paint(g);
    }

    /** initialisation */
    public Plan() {
	setBackground(Color.white);
	setSize(largeur,hauteur);	  	
	setLayout(null);
    }
    
} // Maison

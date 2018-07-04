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
 
  
    static String gifDir = "Demo/";
    public Font fontSelected; //fonte qui sera selectionnee
  
    Image Fond;
  
    /** largeur de l'appli en pixels */
    static final int largeur = 680;

    /** hauteur de l'appli en pixels */
    static final int hauteur = 370;
  
    /**
     *  @param g contexte graphique necessaire a l'affichage.
     *  @param x1 coordonnee horizontale de la 1ere extremitee du mur.
     *  @param y1 coordonnee verticale de la 1ere extremitee du mur.
     *  @param x2 coordonnee horizontale de la 2nde extremitee du mur.
     *  @param y2 coordonnee verticale de la 2nde extremitee du mur.
     */
  
    /** affiche l'image de l'appli */
    public void paint(Graphics g){ 

// 	DrawRectangle(g,01,10,730,360);

        Fond = this.getToolkit().getImage(gifDir + "compt2bit.gif");  
		     g.drawImage(Fond,5,5,660,355,this);
		     
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

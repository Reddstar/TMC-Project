import java.awt.*;

/**
 * Feu.java
 * Cette classe est utilise pour construire une instance de la classe Feux.
 * Une instance de la classe Feux comporte trois objets de la classe Feu.
 *
 * Created: Tue Aug 18 11:51:34 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see Feux
 */

public class Feu{
    static final int Coef =1 ;

    /** indique si l'utilisateur peut cliquer sur le feu pour l'allumer*/
    boolean selectionnable = false;

    /** Couleur du feu lorsqu'il est allume */
    Color couleur;

    /** Couleur d'affichage du feu */
    Color coulCourant;

    /** Codage de la couleur du feu lorsqu'il n'est pas allume */
    static final Color coulEteint = Color.white;

    /** Coordonnee horizontale du Feu */
    int coordX;

    /** Coordonnee verticale du Feu */
    int coordY;

    /** Coeficient du zoom */
    public int coef = 1;

    /** Diametre du feu en pixels */
    static final int diametre = 10/Coef;

    /** largeur du feu en pixels */
    static final int l = (diametre+2)/Coef;

    /** largeur d'affichage du feu en pixels */
    int largeur = l/Coef;

    /** trace un disque de la couleur coulCourant */
    public void paint(Graphics g){
	g.setColor(coulCourant);
	g.fillOval((coordX+coef)/Coef,(coordY*coef+coef)/Coef,(diametre*coef)/Coef,(diametre*coef)/Coef);
    }

    /** @param ok si vrai alors le feu est agrandi sinon il a une taille normale */
    public void zoom(boolean ok){
	if (ok) {coef=2;} else coef=1;
	largeur = l*coef;
    }

    /** change la couleur du feu
     *  @param coul nouvelle couleur du fond
     */
    public void changCoul(Color coul){
	coulCourant=coul;
    }

    /** allume le feu ou eteint le feu*/
    public void allume(boolean ok){
	if (ok) {changCoul(couleur);} else changCoul(coulEteint);
    }

    /** Verifie si un point appartient a la zone d'affichage du feu.
     *  @param x coordonnee horizontale du point.
     *  @param y coordonnee verticale du point.
     *  @return vrai si le point est dans la zone d'affichage du feu.
     */
    public synchronized boolean appartient(int x, int y){
	return (x>coordX && x<coordX+largeur && y>coordY*coef && y<coordY*coef+largeur);	
    }

    /** Construction d'un feu.
     *  @param couleur couleur du feu lorsqu'il est allume.
     *  @param coordX coordonnee horizontale du Feu
     *  @param coordY coordonnee verticale du Feu
     */
    public Feu(Color couleur, int coordX, int coordY) {
	this.couleur = couleur;	        
	this.coordX = coordX;
	this.coordY = coordY;
	coulCourant=couleur;
    }
    
} // Feu

import java.awt.*;

/**
 * Bouton.java
 * decrit l'allure des boutons.
 *
 * Created: Wed Jul 15 17:40:12 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class Bouton extends Button{

    /** Codage de la couleur par defaut des boutons */
    static final Color coulFondDefault =  new Color(200,200,255); //Color.white;

    /** Codage de la couleur des boutons cliques par l'utilisateur */
    static final Color coulChoixUser   = Color.blue; // new Color(200,200,255); // bleu clair

    /** Codage de la couleur des boutons cliquable par l'utilisateur */
    static final Color coulChoixPossible   = Color.blue; //new Color(200,255,200); // vert clair

    /** change la couleur du fond du bouton 
     *  @param coul nouvelle couleur du fond
     */
    public void changCoulFond(Color coul){
	setBackground(coul);
    }

    /** change la couleur du label du bouton .
     *  @param coul nouvelle couleur du label.
     */
    public void changCoulLabel(Color coul){
	setForeground(coul);
    } 

    /** constructions d'un objet Bouton */
    public Bouton(String label){
	super(label);
	setBackground(coulChoixUser);
    }
    
} // Bouton

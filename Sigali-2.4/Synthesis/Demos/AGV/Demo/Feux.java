import java.awt.*;
import java.awt.event.*;
import java.util.*;


/**
 * Feux.java
 * represente l'etat d'une porte selon l'etat de l'entree corespondante.. 
 *
 * Created: Tue Aug 18 10:31:34 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class Feux extends Panel implements Observer, MouseListener {

    /** a chaque objet Feux est associe une entree */
    Entrees entree;

    /** feu corespondant a la valeur False de l'entree */
    Feu feuRouge;

    /** feu corespondant a la valeur Absent de l'entree */
    Feu feuNoir;

    /** feu corespondant a la valeur True de l'entree */
    Feu feuVert;

    /** Coordonnee horizontale du Feux */
    int coordX;

    /** Coordonnee verticale du Feux */
    int coordY;

    /** Codage de la couleur du fond des feux */
    static final Color coulFond = Color.blue;

    /** Cette methode est appelee chaque fois que l'objet observe (le temoin de l'entree) change. 
     *  c'est une methode de l'interface Observer.
     *  Les changements du temoin son signaler grace a la methode notifyObservers().
     *  @param o  l'objet observable.
     *  @param arg un argument passe a la methode notifyObservers. 
     *  @see Temoin
     *  @see Entrees
     *  @see InteResolv
     */
    public synchronized void update(Observable o, Object arg) {

	// Verification de la possiblite de presser les boutons de l'entree :
	feuRouge.selectionnable = entree.boutFalse.isEnabled();
	feuNoir.selectionnable = entree.boutAbs.isEnabled();
	feuVert.selectionnable = entree.boutTrue.isEnabled();

	// Verification de la couleur des boutons de l'entree :
	Color c;
	c = entree.boutFalse.getBackground();
	if (c == Bouton.coulFondDefault && feuRouge.coulCourant!=Feu.coulEteint)
	    feuRouge.allume(false); 
	else if (c == Bouton.coulChoixUser && feuRouge.coulCourant!=feuRouge.couleur)
	    feuRouge.allume(true); 
	c = entree.boutAbs.getBackground();
	if (c == Bouton.coulFondDefault && feuNoir.coulCourant!=Feu.coulEteint)
	    feuNoir.allume(false); 
	else if (c == Bouton.coulChoixUser && feuNoir.coulCourant!=feuNoir.couleur)
	    feuNoir.allume(true); 
	c = entree.boutTrue.getBackground();
	if (c == Bouton.coulFondDefault && feuVert.coulCourant!=Feu.coulEteint)
	    feuVert.allume(false); 
	else if (c == Bouton.coulChoixUser && feuVert.coulCourant!=feuVert.couleur)
	    feuVert.allume(true); 
	repaint();
    }

    /** Verifie si un point appartient a la zone d'affichage des feux.
     *  @param x coordonnee horizontale du point.
     *  @param y coordonnee verticale du point.
     *  @return vrai si le point est dans la zone d'affichage des feux.
     */
    private boolean appartient(int x, int y){
	return (x>0 && x<feuRouge.largeur && y>0 && y<feuRouge.largeur*3);	
    }

    /** egal a faux si les feux sont agrandi et a vrai sinon */
    private boolean finZoom = true;

    /** affiche les Feux. */
    public void paint(Graphics g){
	feuRouge.paint(g);
 	feuNoir.paint(g);
 	feuVert.paint(g);
  }

    /** @param ok si vrai alors les feux sont agrandis sinon ils ont une taille normale */
    private void zoom(boolean ok){
	feuRouge.zoom(ok);
	feuNoir.zoom(ok);
	feuVert.zoom(ok);
   	setSize(feuRouge.largeur,feuRouge.largeur*3);
	repaint();
    }

    /** cette methode est appelee si un bouton de la sourie est enfonce */ 
    public void mousePressed(MouseEvent evt){
    }

    /** cette methode est appelee si un bouton de la sourie est relache */ 
    public void mouseReleased(MouseEvent evt){
    }

    /** cette methode est appelee si le curseur de la sourie entre 
     *  dans la zone du composant. */ 
    public synchronized void mouseEntered(MouseEvent evt){
	if (finZoom) {
   	    finZoom = false;	
  	    zoom(false); // agrandi les Feux
  	}	
    }

    /** cette methode est appelee si le curseur de la sourie sort 
     *  de la zone du composant. */  
    public synchronized void mouseExited(MouseEvent evt){
	int x = evt.getX(); int y = evt.getY();
  	if (!appartient(x,y)){
  	    finZoom = true;
  	    zoom(false); 
   	}
    }

    /** cette methode est appelee si un bouton de la sourie a ete clique */ 
    public void mouseClicked(MouseEvent evt){	
	int x = evt.getX(); int y = evt.getY();
	if (feuRouge.appartient(x,y) && feuRouge.selectionnable) {
	    InteResolv.noEntreeCliquee = ListEntrees.recherche_elem_list(entree);
	    InteResolv.valeurEntreeCliquee = InteResolv.codeFalse;
	    InteResolv.changCoulUser(entree.boutFalse);
	    InteResolv.resolver_interne(InteResolv.isEntreeCont);
	}
	else if (feuNoir.appartient(x,y) && feuNoir.selectionnable) {
	    InteResolv.noEntreeCliquee = ListEntrees.recherche_elem_list(entree);
	    InteResolv.valeurEntreeCliquee = InteResolv.codeAbs;
	    InteResolv.changCoulUser(entree.boutAbs);
	    InteResolv.resolver_interne(InteResolv.isEntreeCont);
	}
	else if (feuVert.appartient(x,y) && feuVert.selectionnable) {
	    InteResolv.noEntreeCliquee = ListEntrees.recherche_elem_list(entree);
	    InteResolv.valeurEntreeCliquee = InteResolv.codeTrue;
	    InteResolv.changCoulUser(entree.boutTrue);
	    InteResolv.resolver_interne(InteResolv.isEntreeCont);
	}
    }

    /** initialisation.
     *  @param entree l'entree associe.
     *  @param coordX Coordonnee horizontal du Feux.
     *  @param coordY Coordonnee verticale du Feux.
     */
    public Feux(Entrees entree, int coordX, int coordY) {
	this.entree = entree;
	this.coordX = coordX;
	this.coordY = coordY;
	setLocation(coordX,coordY); // positionne le Feux
	entree.temoin.addObserver(this);
        setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
	feuRouge = new Feu(Color.red, 0, 0);
	feuNoir = new Feu(Color.black, 0, feuRouge.largeur);
  	feuVert = new Feu(Color.green, 0, feuRouge.largeur*2);
	addMouseListener(this);  
	setBackground(coulFond);
	zoom(false); // affiche en petit 
	setVisible(true);
    }
    
} // Feux

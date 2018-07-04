import java.awt.*;

/**
 * ChariotAGV.java
 * <dt> Cette classe decrit les chariots filoguides (apparance et deplacements).
 * <dt>
 * Created: Tue Jul 28 15:48:25 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see Piece
 * @see Plan
 */

public class ChariotAGV extends Canvas{

    /** Coef de reduction de l'appli */
    static final int Coef = 1;

    /** represente la direction OUEST vers laquel se dirige le chariot */
    static final int OUEST = 0;

     /** represente la direction SUD vers laquel se dirige le chariot */
    static final int SUD   = 1;

    /** represente la direction EST vers laquel se dirige le chariot  */
    static final int EST   = 2;

    /** represente la direction NORD vers laquel se dirige le chariot */
    static final int NORD  = 3;

    /** direction courante. 
     *  direction prend sa valeur dans {OUEST, SUD, EST, NORTH}.
     */
    int direction = OUEST;

    /** suite de directions. */
    private final int[] cheminDirection;

    /** suite d'abcisses des endroits par lesquels passe le chariot. */
    protected final int[] cheminX;

    /** suite d'ordonnees des endroits par lesquels passe le chariot. */
    protected final int[] cheminY;

    /** nombres d'etapes dans le chemin du chariot. */
    protected final int nbPositions;

    /** ancienne position (permet de savoir si le chariot a avance) */
    protected int oldPosition = 0;

    /** verifie si le chariot a bouge depuis la derniere verification 
     *	@return vrai si le chariot n'a pas bouge et faux sinon 
     */
    private boolean surPlace(int pos){
	return oldPosition==pos;
    }

    /** vrai si le chariot est en train d'avancer
     *  (ie:il est dans une position intermediaire entre son point 
     *   de depart et son point d'arrive).
     *  faux sinon. 
     */
    public boolean enMouvement = false;

    /** fait avancer le chariot */
    public void avance(){
	if (!enMouvement) {
	    dessine(oldPosition*2);
	    enMouvement=true;
	}
	else {
	    dessine(oldPosition*2+1);
	    enMouvement=false;
	}
    }

    /** la piece que le chariot transporte */
    private final Piece piece;

    /** suite d'entiers indiquant si le chariot est charge on non.
     *  Les entiers de cette suite sont code comme suit :
     *  <pre>
     *         0 => le chariot est vide;
     *    i != 0 => le chariot transporte une piece en i eme phase de construction;
     *  </pre>
     */
    private final int[] cheminCharge;
    
    /** charge courante.
     *  Code comme suit :
     *  <pre>
     *         0 => le chariot est vide;
     *    i != 0 => le chariot transporte une piece en i eme phase de construction;
     *  </pre>     
     */
    int charge = 0;

    /** couleur du chariot */
    public Color coul;

    /** largeur du chariot en pixels */
    static final int largeur = 30/Coef;

    /** hauteur du chariot en pixels */
    static final int hauteur = 30/Coef;    
    
    /** representation graphique du chariot se dirigeant vers l'ouest*/
    public void dessinOUEST(Graphics g){
	g.setColor(coul);	 
	int xp[] = new int [6]; int yp[] = new int[6];
	xp[0]= 4/Coef; yp[0]= 0/Coef; 
	xp[1]= 29/Coef; yp[1]= 0/Coef; 
	xp[2]= 29/Coef; yp[2]= 29/Coef; 
	xp[3]= 5/Coef; yp[3]= 29/Coef; 
	xp[4]= 0; yp[4]= 24/Coef; 
	xp[5]= 0; yp[5]= 4/Coef;
	Polygon p = new Polygon(xp,yp,6);
	g.drawPolygon(p);
	g.fillRect(27/Coef,2/Coef,2/Coef,26/Coef);
    } 

    /** representation graphique du chariot se dirigeant vers l'est */
    public void dessinEST(Graphics g){
	g.setColor(coul);	 
	int xp[] = new int [6]; int yp[] = new int[6];
	xp[0]= 0; yp[0]= 0; 
	xp[1]= 24/Coef; yp[1]= 0; 
	xp[2]= 29/Coef; yp[2]= 4/Coef; 
	xp[3]= 29/Coef; yp[3]= 24/Coef; 
	xp[4]= 24/Coef; yp[4]= 29/Coef; 
	xp[5]= 0; yp[5]= 29/Coef;
	Polygon p = new Polygon(xp,yp,6);
	g.drawPolygon(p);
	g.fillRect(1/Coef,2/Coef,2/Coef,26/Coef);
    }

    /** representation graphique du chariot se dirigeant vers le sud */
    public void dessinSUD(Graphics g){
	g.setColor(coul);	 
	int xp[] = new int [6]; int yp[] = new int[6];
	xp[0]= 0; yp[0]= 0; 
	xp[1]= 29/Coef; yp[1]= 0; 
	xp[2]= 29/Coef; yp[2]= 24/Coef; 
	xp[3]= 24/Coef; yp[3]= 29/Coef; 
	xp[4]= 4/Coef; yp[4]= 29/Coef; 
	xp[5]= 0; yp[5]= 24/Coef;
	Polygon p = new Polygon(xp,yp,6);
	g.drawPolygon(p);
 	g.fillRect(2/Coef,1/Coef,26/Coef,2/Coef);
   }

    /** representation graphique du chariot se dirigeant vers le nord */
    public void dessinNORD(Graphics g){
	g.setColor(coul);	 
	int xp[] = new int [6]; int yp[] = new int[6];
	xp[0]= 4/Coef; yp[0]= 0; 
	xp[1]= 24/Coef; yp[1]= 0; 
	xp[2]= 29/Coef; yp[2]= 4/Coef; 
	xp[3]= 29/Coef; yp[3]= 29/Coef; 
	xp[4]= 0; yp[4]= 29/Coef; 
	xp[5]= 0; yp[5]= 4/Coef;
	Polygon p = new Polygon(xp,yp,6);
	g.drawPolygon(p);
   	g.fillRect(2/Coef,27/Coef,26/Coef,2/Coef);
  }

    /** dessine le chariot sur son chemin.
     *  @param position numero de l'endroit ou l'on veut afficher le chariot.
     */
    public void dessine(int position){
	direction = cheminDirection[position];
	charge    = cheminCharge[position];
	dessine_chariot(cheminX[position],cheminY[position]);
    }

    /** dessine le chariot sur son chemin.
     *  @param position tableau d'entiers avec, au plus, un seul entier egal a 1. 
     */
    public void dessine(int position[]){
	for (int i=0; i<nbPositions; i++) 
	    if (position[i+1]==1 && !surPlace(i)) {
		oldPosition++; if (oldPosition==nbPositions) oldPosition=0;
		avance();
	    }
    }

    /** dessine le chariot a la position (<strong>x</strong>,<strong>y</strong>) 
     *  s'il est <strong>present</strong> a cette position.
     *  @param x coordonnee horizontal de la position.
     *  @param y coordonnee vertical de la position.
     *  @param present si a vrai alors le chariot est dessine sinon il ne l'est pas.
     */
    public void dessine_chariot(int x, int y){
	setLocation(x,y);
	repaint();
    }


    /** representation graphique du chariot */
    public void paint(Graphics g){
	switch(direction){
	    case  SUD  : dessinSUD(g); break;
	    case  EST  : dessinEST(g); break;
	    case  NORD : dessinNORD(g); break;
	    default    : dessinOUEST(g); break;
	}
	piece.paint(g,charge,direction);
    }

    /** reafiche le chariot.
     *  Cette methode est redefini, car par defaut, 
     *  elle efface le composant avant de le repaindre.
     *  Ce qui est une perte de temps.
     */
    public void update(Graphics g){
	paint(g);
    }

    /** initialisation du chemin et de la charge du chariot, et de sa couleur.
     *  @param cheminX suite d'abcisses des endroits par lesquels passe le chariot.
     *  @param cheminY suite d'ordonnees des endroits par lesquels passe le chariot.
     *  @param cheminDirection suite des directions du chariot. 
     *  @param nbPositions nombres d'etapes dans le chemin du chariot.
     *  @param coul couleur du chariot.
     */
    public ChariotAGV(int[] cheminX, int[] cheminY, 
		      int[] cheminDirection, int[] cheminCharge, 
		      Piece piece, int nbPositions, Color coul) {
	this.nbPositions=nbPositions;
	this.cheminX = cheminX;
	this.cheminY = cheminY;
	this.cheminDirection = cheminDirection;
	this.cheminCharge = cheminCharge;
	this.piece = piece;
	this.coul=coul;
	setBackground(Color.white);
	setSize(largeur,hauteur);
	vt.plan.add(this);	
	dessine(1);
	
    }      
  
} // ChariotAGV

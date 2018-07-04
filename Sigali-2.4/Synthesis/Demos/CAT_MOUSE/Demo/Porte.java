import java.awt.*;

/**
 * Porte.java
 * <dt> Cette classe decrit les portes du chat et de la souris (apparance et deplacements).
 * <dt>
 * Created: Tue Jul 28 15:48:25 1998
 *
 * @author Herve Marchand
 * @version
 * @see Plan
 */

public class Porte extends Canvas{

    /** represente l'état ouvert de la porte */
    static final int OUVERT = 1;

     /** represente l'état fermé de la porte */
    static final int FERME  = 0;


    /** invoqué si l'on veut dessiner une porte horinzontale */
    static final int HORIZONTAL = 0;
    /** invoqué si l'on veut dessiner une porte verticale */
    static final int VERTICAL  = 1;

    /*  etat prend sa valeur dans (OUVERT,FERME).
     */
    int etat = FERME;
    
    /*  Vert_horiz prend sa valeur dans (HORIZONTAL,VERTICAL)
     */
    int Vert_horiz = VERTICAL;

    /** suite d'abcisses des endroits par lesquels passe le chariot. */
    protected final int cheminX;
    /** suite d'ordonnees des endroits par lesquels passe le chariot. */
    protected final int cheminY;

    /** couleur du chariot */
    public Color coul;
    /** largeur et hauteur du chariot en pixels */
    static final int largeur_h = 24; static final int hauteur_h = 13; 
    static final int largeur_v = 13; static final int hauteur_v = 24;   
 

    public void DrawPorte(Graphics g,int x1, int y1, int x2, int y2){
	int h = 3;
	int xp[] = new int[4]; int yp[] = new int[4];
	xp[0]= x1; yp[0]= y1;
	xp[1]= x1+h; yp[1]= y1+h;
	xp[2]= x2+h; yp[2]= y2+h;
	xp[3]= x2; yp[3]= y2;
	Polygon p = new Polygon(xp,yp,4);
	g.fillPolygon(p);
    }
    
    public void dessinOUVERT_HORIZONTAL(Graphics g){
	g.setColor(coul);
	g.fillRect(0,0,3,13);
	g.fillRect(21,0,24,13);
	}
    public void dessinFERME_HORIZONTAL(Graphics g){
	g.setColor(coul);
	g.fillRect(0,0,24,13);
	}

    public void dessinOUVERT_VERTICAL(Graphics g){
	g.setColor(coul);
	g.fillRect(0,0,13,3);
	g.fillRect(0,21,13,24);
	}
    public void dessinFERME_VERTICAL(Graphics g){
	g.setColor(coul);
	g.fillRect(0,0,13,24);
	}


    /** dessine le chariot sur son chemin.
     *  @param position numero de l'endroit ou l'on veut afficher le chariot.
     */
    public void dessine(int etat){
	dessine_porte(cheminX,cheminY,etat);
    }

    /** dessine le chariot sur son chemin.
     *  @param position tableau d'entiers 
     */
    public void Dessine(int position){
	etat = position;
	dessine(etat);
    }

    /** dessine le chariot a la position (<strong>x</strong>,<strong>y</strong>) 
     *  s'il est <strong>present</strong> a cette position.
     *  @param x coordonnee horizontal de la position.
     *  @param y coordonnee vertical de la position.
     *  @param present si a vrai alors le chariot est dessine sinon il ne l'est pas.
     */
    public void dessine_porte(int x, int y, int etat){
	setLocation(x,y);
	repaint();
    }


    /** representation graphique du chariot */
    public void paint(Graphics g){
	if ((etat==OUVERT) && (Vert_horiz==VERTICAL)) dessinOUVERT_VERTICAL(g);
	if ((etat==FERME)  && (Vert_horiz==VERTICAL)) dessinFERME_VERTICAL(g);
	if ((etat==OUVERT) && (Vert_horiz==HORIZONTAL)) dessinOUVERT_HORIZONTAL(g);
	if ((etat==FERME)  && (Vert_horiz==HORIZONTAL)) dessinFERME_HORIZONTAL(g);
	}


    /** initialisation du chemin et de la charge du chariot, et de sa couleur.
     *  @param cheminX suite d'abcisses des endroits par lesquels passe le chariot.
     *  @param cheminY suite d'ordonnees des endroits par lesquels passe le chariot.
     *  @param nbPositions nombres d'etapes dans le chemin du chariot.
     *  @param coul couleur du chariot.
     */
    public Porte(int cheminX, int cheminY, Color coul, int Vert_horiz) {
	this.Vert_horiz = Vert_horiz;
	this.cheminX = cheminX;
	this.cheminY = cheminY;
	this.coul=coul;
	setBackground(Color.white);
	if (Vert_horiz== HORIZONTAL) setSize(largeur_h,hauteur_h); else setSize(largeur_v,hauteur_v);
	vt.plan.add(this);
	dessine(FERME);
	
    }      
  
} // Porte

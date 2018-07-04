import java.awt.*;

/**
 * Animal.java
 * 
 * @author Herve Marchand
 * @version
 */

public class Animal extends Canvas{
    static String gifDir = "../demo/Images.dir/";
    static final int CHAT = 0;
    static final int SOURIS = 1;
    int chat_souris = CHAT;
    Image chat;
    Image souris;
    int largeurImage_chat = 189; 
    int hauteurImage_chat = 89; 
    int largeurImage_souris = 80; 
    int hauteurImage_souris = 73; 
    int piece_occupee = 4;

  
    /** Suite d'abcisse des endroits par lesquels passe l'animal */
    protected final int[] cheminX;

    /** Suite d'ordonn�e des endroits par lesquels passe l'animal */
    protected final int[] cheminY;

    /** Nombres d'�tapes dans le chemin de l'animal */
    protected final int nbPositions;

    /** Dessine l'animal sur son chemin.
     *  @param position numero de l'endroit ou l'on veut afficher l'animal.
     */
    public void dessine(int position, int piece_occupee){
	dessine_animal(cheminX[position],cheminY[position],piece_occupee);
    }
    
   /** dessine l'animal sur son chemin.
     *  @param position tableau d'entiers avec un seul entier est egal a 1 
     *  et son indice est le num�ro de l'endroit ou l'on veut afficher l'animal
     */
    public void Dessine(int position[]){
	for (int i=0; i<nbPositions; i++)  
	    if (position[i+1]==1) {piece_occupee = i; dessine(i,piece_occupee);}
    }

    /** Dessine l'animal � la position (<strong>x</strong>,<strong>y</strong>) 
     *  s'il est <strong>present</strong> a cette position.
     *  @param x coordonnee horizontal de la position.
     *  @param y coordonnee vertical de la position.
     */

    public void dessine_animal(int x, int y, int piece_occupee){
	setLocation(x,y);
	repaint();
    }

    /** representation graphique des animaux
     *  Chargement des diff�rentes images suivant la pi�ce ou se trouve l'animal 
     */
    public void paint(Graphics g){
	if (chat_souris==SOURIS) {  souris = this.getToolkit().getImage(gifDir + "souris.jpg"); 
		       g.drawImage(souris, 0, 0, getBounds().width, getBounds().height,this); 
	}

	if (chat_souris==CHAT) {  chat = this.getToolkit().getImage(gifDir + "chat.gif");
		       g.drawImage(chat, 0, 0, getBounds().width, getBounds().height,this); 
	}
    }


    /** reaffiche les animaux
     *  Cette m�thode est red�finie, car par defaut, 
     *  elle efface le composant avant de le repeindre.
     *  Ce qui est une perte de temps.
     */
    public void update(Graphics g){
	paint(g);
    }
    /** initialisation du chemin des animaux
     *  @param cheminX     : suite d'abcisse des endroits par lesquels passe l'animal.
     *  @param cheminY     : suite d'ordonnee des endroits par lesquels passe l'animal.
     *  @param nbPositions : nombres d'etapes dans le chemin de l'animal.
     *  @param chat_souris : indique si on invoque cette m�thode 
     *                       avec un chat comme animal ou avec une souris. 
     *  @param initial     : pi�ce initial ou se trouve l'animal
     */
    public Animal(int[] cheminX, int[] cheminY, int nbPositions, int chat_souris, int initial) {
	this.cheminX=cheminX;
	this.cheminY=cheminY;
	this.nbPositions=nbPositions;
	this.chat_souris=chat_souris;
	setBackground(Color.white);
	if (chat_souris==SOURIS) setSize(largeurImage_souris,hauteurImage_souris);
	  else setSize(largeurImage_chat,hauteurImage_chat);
	vt.plan.add(this);	
 	dessine(initial,initial);
    }      
  
} // Animal

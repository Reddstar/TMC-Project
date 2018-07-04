import java.awt.*;

/**
 * State.java
 * 
 * @author Herve Marchand
 * @version
 */

public class State extends Canvas{ 
    static String gifDir = "Demo/";
    Image state; 
    int largeurImage_state = 38; 
    int hauteurImage_state = 37;  

  
    /** Suite d'abcisse des etats */
    protected final int[] Coord_X;

    /** Suite d'ordonnée des etats */
    protected final int[] Coord_Y;
 
 
    /** Dessine l'etat courant 
     *  @param position numero de l'etat.
     */
    public void dessine(int position){
	setLocation(Coord_X[position],Coord_Y[position]);
	repaint();
    }
   /** dessine l'etat
     *  @param position tableau d'entiers 
     */
    public void Dessine(boolean B1, boolean B2){
	if (!(B1)&& !(B2)) {setLocation(Coord_X[0],Coord_Y[0]);}
	if (B1 && !(B2)) {setLocation(Coord_X[1],Coord_Y[1]);}
	if (!(B1) && B2) {setLocation(Coord_X[2],Coord_Y[2]);}
	if (B1 && B2) {setLocation(Coord_X[3],Coord_Y[3]);}
	repaint();
    }  

    /** representation graphique des etats 
     */
    public void paint(Graphics g)  
    { state = this.getToolkit().getImage(gifDir + "state.gif");  
      g.drawImage(state, 0, 0, getBounds().width, getBounds().height,this);  
    }
 
    public void update(Graphics g){
	paint(g);
    }

    /** initialisation 
     *  @param Coord_X     : suite d'abcisse des  etats 
     *  @param Coord_Y     : suite d'ordonnee des etats  
     *  @param initial     : etat initial 
     */
    public State(int[] Coord_X, int[] Coord_Y, int initial) {
	this.Coord_X=Coord_X;
	this.Coord_Y=Coord_Y; 
	setBackground(Color.white); 
	setSize(largeurImage_state-1,hauteurImage_state);
	vt.plan.add(this);	
 	dessine(initial);
    }      
  
} // State

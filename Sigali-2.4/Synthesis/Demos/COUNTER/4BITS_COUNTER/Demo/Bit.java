import java.awt.*;

/**
 * Bit.java
 * 
 * @author Herve Marchand
 * @version
 */

public class Bit extends Canvas{ 
    static String gifDir = "Demo/";
    Image state; 
    boolean B1 = false; 
    /** Suite d'abcisse des etats */
    protected final int Coord_X;

    /** Suite d'ordonnée des etats */
    protected final int Coord_Y;

    public void dessine(int position){ 
	repaint();
    } 
    public void Dessine(boolean B){
	if (B) {B1=true;} else B1=false;
	repaint();
	    
    }
   
    public void paint(Graphics g) { 
	    if (B1)
		{ state = this.getToolkit().getImage(gifDir + "un.gif");  
	     g.drawImage(state, 0, 0, getBounds().width, getBounds().height,this);  
		}
	    else { state = this.getToolkit().getImage(gifDir + "zero.gif");  
	     g.drawImage(state, 0, 0, getBounds().width, getBounds().height,this);  
		}   
    }

    public void update(Graphics g){
	paint(g);
    } 

    public Bit(int Coord_X, int Coord_Y) {
	this.Coord_X=Coord_X;
	this.Coord_Y=Coord_Y; 
	setBackground(Color.white); 
        setLocation(Coord_X,Coord_Y); 
	setSize(15,20); 
	vt.plan.add(this); 	
 	dessine(0);
    }      
  
} //  Valve

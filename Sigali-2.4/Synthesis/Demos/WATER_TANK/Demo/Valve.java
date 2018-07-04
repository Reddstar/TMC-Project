import java.awt.*;

/**
 * State.java
 * 
 * @author Herve Marchand
 * @version
 */

public class Valve extends Canvas{ 
  
    /** Suite d'abcisse des etats */
    protected final int Coord_X;

    /** Suite d'ordonnée des etats */
    protected final int Coord_Y;

    public void Dessine(boolean Valve){
		Graphics g = getGraphics(); 
	    if (Valve)
		{  g.setColor(Color.blue); 
		   g.fillRect(0,0,29,100); 
		}
	    else {  g.setColor(Color.blue); 
		    g.fillRect(0,0,29,55); 
		    g.setColor(Color.black); 
		    g.fillRect(0,55,29,20);
		    g.setColor(Color.white); 
		    g.fillRect(0,75,28,80); 
	    }
	    
    }
   
    public void paint(Graphics g)  
    {   
    }

    public void update(Graphics g){
	paint(g);
    } 

    public Valve(int Coord_X, int Coord_Y) {
	this.Coord_X=Coord_X;
	this.Coord_Y=Coord_Y; 
	setBackground(Color.white); 
        // setLocation(433,400);  
        setLocation(Coord_X,Coord_Y); 
	setSize(27,110);
	vt.plan.add(this); 
    }      
  
} //  Valve

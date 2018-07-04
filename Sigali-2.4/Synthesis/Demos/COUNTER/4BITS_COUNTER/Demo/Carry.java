import java.awt.*; 
import java.awt.*; 

public class Carry extends Canvas{ 
  
     protected final int Coord_X;
     protected final int Coord_Y;
  boolean CC1 = false; 

    public void Dessine(boolean CC){
	if (CC) {CC1=true;} else CC1=false;
		repaint();
	    
    }
   
    public void paint(Graphics g)  
    {  if (CC1) {  g.setColor(Color.red); 
                  g.drawRect(0,0,5,5);	   
		}
	    else {  g.setColor(Color.white);
	            g.drawRect(0,0,5,5);	
	    }
		repaint();
    } 

    public void update(Graphics g){
	paint(g);
    } 

    public Carry(int Coord_X, int Coord_Y) {
	this.Coord_X=Coord_X;
	this.Coord_Y=Coord_Y; 
	setBackground(Color.white); 
        setLocation(Coord_X,Coord_Y); 
	setSize(10,10);
	vt.plan.add(this); 
    }      
  
} //  Valve

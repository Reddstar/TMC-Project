import java.awt.*;

/**
 * State.java
 * 
 * @author Herve Marchand
 * @version
 */

public class Flow extends Canvas{
  
    public void Dessine(boolean Flow_Pump, boolean Flow_Valve2, boolean Valve2){
		Graphics g = getGraphics(); 
	    if (Flow_Pump)
		{  g.setColor(Color.blue); 
		   g.fillRect(0,0,150,21);
		    if (Flow_Valve2) {g.fillRect(150,0,93,21);}
		    else {
			if (Valve2) {
			    g.setColor(Color.white);
			    g.fillRect(150,0,120,23);}
			else {
			    g.setColor(Color.black);
			    g.fillRect(150,0,20,23);
			    g.setColor(Color.white);
			    g.fillRect(170,0,100,23);}
		    }
		}
	    else {  g.setColor(Color.black); 
		    g.fillRect(0,0,20,23);
		    g.setColor(Color.white); 
		    g.fillRect(20,0,150,21);
			if (Valve2) {
			    g.setColor(Color.white);
			    g.fillRect(150,0,120,23);}
			else {
			    g.setColor(Color.black);
			    g.fillRect(150,0,20,23);
			    g.setColor(Color.white);
			    g.fillRect(170,0,100,23);}
	    }
	    
    }
   
    public void paint(Graphics g)  
    {   
    }

    public void update(Graphics g){
	paint(g);
    } 

    public Flow() { 
	setBackground(Color.white); 
	setLocation(170,150); 
	setSize(400,21);
	vt.plan.add(this); 
    }      
  
} //  Valve

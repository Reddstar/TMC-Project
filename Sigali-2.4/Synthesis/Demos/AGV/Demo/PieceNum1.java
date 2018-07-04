import java.awt.*;

/**
 * PieceNum1.java
 * Cette classe decrit les pieces qui vont etre usinees dans la work station 2
 * Ces pieces sont usinees en trois etapes.
 * Created: Fri Aug 21 11:54:39 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class PieceNum1 extends Piece{
    static final int Coef=1;

    /** couleur de la piece. */
    public Color coul = Color.black; 

    public void dessineEtape1(Graphics g, int direction){
	g.setColor(coul);
	g.fillRect(5/Coef,5/Coef,20/Coef,20/Coef);
    }

    public void dessineEtape2(Graphics g, int direction){
	g.setColor(coul);
	switch(direction){
	case ChariotAGV.OUEST: 
	    g.fillRect(5/Coef,15/Coef,20/Coef,10/Coef);
	    g.fillRect(20/Coef,5/Coef,5/Coef,10/Coef);
	    break;
	case ChariotAGV.SUD: 
	    g.fillRect(15/Coef,5/Coef,10/Coef,20/Coef);
	    g.fillRect(5/Coef,5/Coef,10/Coef,5/Coef);
	    break;
	case ChariotAGV.NORD: 
	    g.fillRect(5/Coef,5/Coef,10/Coef,20/Coef);
	    g.fillRect(15/Coef,20/Coef,10/Coef,5/Coef);
	    break;
	default: //EST
	    g.fillRect(5/Coef,5/Coef,20/Coef,10/Coef);
	    g.fillRect(5/Coef,15/Coef,5/Coef,10/Coef);
	    break;	
	}

    }
    public void dessineEtape3(Graphics g, int direction){
	g.setColor(coul); 
	switch(direction){
	case ChariotAGV.OUEST: 
	    g.fillRect(10/Coef,15/Coef,15/Coef,10/Coef);
	    g.fillRect(20/Coef,5/Coef,5/Coef,10/Coef);
	    break;
	case ChariotAGV.SUD: 
	    g.fillRect(15/Coef,5/Coef,10/Coef,15/Coef);
	    g.fillRect(5/Coef,5/Coef,10/Coef,5/Coef);
	    break;
	case ChariotAGV.NORD: 
	    g.fillRect(5/Coef,10/Coef,10/Coef,15/Coef);
	    g.fillRect(15/Coef,20/Coef,10/Coef,5/Coef);
	    break;
	default: //EST
	    g.fillRect(5/Coef,5/Coef,15/Coef,10/Coef);
	    g.fillRect(5/Coef,15/Coef,5/Coef,10/Coef);
	    break;	
       	}
    }

    public void paint(Graphics g, int etape, int direction){
	switch(etape){
	case 0: break; // on affiche rien.
	case 1: dessineEtape1(g, direction); break;
	case 2: dessineEtape2(g, direction); break;
	default: dessineEtape3(g, direction); break;
	}
	
    }

} // PieceNum1

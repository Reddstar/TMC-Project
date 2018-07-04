import java.awt.*;

/**
 * PieceNum3.java
 * Cette classe decrit les pieces qui vont etre usinees dans la work station 5
 * et qui sont construites en assemblant des pieces des classes PieceNum1 et 
 * PieceNum2.
 * Ces pieces sont usinees en trois etapes. *
 * Created: Fri Aug 21 15:09:27 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class PieceNum3 extends Piece{
    static final int Coef=1;
    
    private PieceNum1 piece1 = new PieceNum1();

    private PieceNum2 piece2 = new PieceNum2();

    public void dessineEtape3(Graphics g, int direction){
	piece1.dessineEtape3(g, direction);
	piece2.dessineEtape3(g, direction);
	switch(direction){
	case ChariotAGV.OUEST: 	
	    g.setColor(piece1.coul);
	    g.fillOval(13/Coef,8/Coef,4/Coef,4/Coef);
	    g.setColor(piece2.coul);
	    g.fillOval(13/Coef,18/Coef,4/Coef,4/Coef);
	    break;
	case ChariotAGV.SUD: 
	    g.setColor(piece1.coul);
	    g.fillOval(8/Coef,13/Coef,4/Coef,4/Coef);
	    g.setColor(piece2.coul);
	    g.fillOval(18/Coef,13/Coef,4/Coef,4/Coef);
	    break;
	case ChariotAGV.NORD: 
	    g.setColor(piece2.coul);
	    g.fillOval(8/Coef,13/Coef,4/Coef,4/Coef);
	    g.setColor(piece1.coul);
	    g.fillOval(18/Coef,13/Coef,4/Coef,4/Coef);
	    break;
	default: //EST
	    g.setColor(piece2.coul);
	    g.fillOval(13/Coef,8/Coef,4/Coef,4/Coef);
	    g.setColor(piece1.coul);
	    g.fillOval(13/Coef,18/Coef,4/Coef,4/Coef);
	    break;
	}
    }

    public void paint(Graphics g, int etape, int direction){
	switch(etape){
	case 1: piece1.dessineEtape3(g, direction); break;
	case 2:
	    piece1.dessineEtape3(g, direction);
	    piece2.dessineEtape3(g, direction);
	    break;
	case 3: dessineEtape3(g, direction);  break;
	default:break; // on affiche rien.
	}
    }
    
} // PieceNum3

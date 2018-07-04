import java.awt.*;

/**
 * Piece.java
 * Les pieces sont des objets usines et qui sont transportes 
 * par des chariots filoguides.
 * Pour creer une sorte de piece on cree une nouvelle class
 * qui herite de la classe Piece et qui surcharge la methode 
 * paint.
 * Created: Fri Aug 21 15:30:56 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see PieceNum1
 * @see PieceNum2
 * @see PieceNum3
 * @see ChariotAGV
 */

public abstract class Piece {

    /** dessin de la piece */
    public abstract void paint(Graphics g, int etape, int direction);

} // Piece

import java.awt.*;

/**
 * State.java
 * 
 * @author Herve Marchand
 * @version
 */

public class State extends Canvas{
   

    public void Dessine(boolean X0,boolean X1,boolean X2,boolean X3,boolean X4,boolean X5,boolean X6,boolean Flow)
    {
	Graphics g = getGraphics(); 
	if (Flow){g.setColor(Color.blue); g.fillRect(0,30,10,300); } else {g.setColor(Color.white); g.fillRect(0,0,10,300); }
	g.setColor(Color.blue);
	if (X6) { g.fillRect(0,0,249,55*5);}
	if (X5) { g.fillRect(0,55,249,55*4); g.setColor(Color.white);g.fillRect(10,0,249,55); }
	if (X4) { g.fillRect(0,110,249,55*3); g.setColor(Color.white);g.fillRect(10,0,249,55*2); }
	if (X3) { g.fillRect(0,165,249,55*2); g.setColor(Color.white);g.fillRect(10,0,249,55*3); }
	if (X2) { g.fillRect(0,220,249,55); g.setColor(Color.white);g.fillRect(10,0,249,55*4); }
	if (X1) { g.setColor(Color.white);g.fillRect(10,0,249,55*5); }
    }


    public void paint(Graphics g)  
    {   
    }


    /** reaffichage
     *  Cette méthode est redéfinie, car par defaut, 
     *  elle efface le composant avant de le repeindre.
     *  Ce qui est une perte de temps.
     */
    public void update(Graphics g){
	paint(g);
    }
    /** initialisation 
     *  @param Coord_X     : suite d'abcisse des  etats 
     *  @param Coord_Y     : suite d'ordonnee des etats  
     *  @param nbPositions : nombres d'etats differents 
     *  @param initial     : etat initial
     *  @param nbPositions nombres d'etapes dans le chemin du chariot.
     */
    public State() {
	setBackground(Color.white);  
	setLocation(403,120); 
	setSize(247,55*5);
	vt.plan.add(this);
    }      
  
} // Animal

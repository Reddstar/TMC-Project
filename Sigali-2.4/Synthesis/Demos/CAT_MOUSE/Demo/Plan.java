import java.awt.*;

/**
 * Plan.java
 * Plan de la maison.
 *
 * Created: Tue Jul 28 12:02:35 1998
 *
 * @author Herve Marchand
 * @version
 * @see vt
 */

public class Plan extends Panel {

    /** couleur des murs de la maison */
    static final Color coulMur = Color.black;

    /** largeur de la maison en pixels */
    static final int largeur = 536;

    /** hauteur de la maison en pixels */
    static final int hauteur = 660;
  
    /** dessine un mur de la maison
     *  @param g contexte graphique necessaire a l'affichage.
     *  @param x1 coordonnee horizontale de la 1ere extremitee du mur.
     *  @param y1 coordonnee verticale de la 1ere extremitee du mur.
     *  @param x2 coordonnee horizontale de la 2nde extremitee du mur.
     *  @param y2 coordonnee verticale de la 2nde extremitee du mur.
     */
    public void DrawLine(Graphics g,int x1, int y1, int x2, int y2){
	int h = 3;
	int xp[] = new int[4]; int yp[] = new int[4];
	xp[0]= x1; yp[0]= y1;
	xp[1]= x1+h; yp[1]= y1+h;
	xp[2]= x2+h; yp[2]= y2+h;
	xp[3]= x2; yp[3]= y2;
	Polygon p = new Polygon(xp,yp,4);
	g.fillPolygon(p);
    }

    /** affiche l'image de la maison */
    public void paint(Graphics g){

	// Nom de L'application + Explication
	g.drawRect(60,560,410,80);
	g.drawRect(60+1,560+1,410-2,80-2);
	g.drawString("SUPERVISORY CONTROL PROBLEM :The Cat and Mouse Example",67,582);
	g.drawString("Cat Doors: ",100+13,600);
	g.setColor(Color.blue); 
	g.fillRect(170+13,589,24,13);
	g.drawString("(Closed), ",200+13,600);
	g.fillRect(260+13,587,3,13);
	g.fillRect(260+13+13,587,3,13);
	g.drawString("(Opened)",283+13,600);
	g.setColor(Color.black); 
	g.drawString("Mouse Doors: ",100,600+25);
	g.setColor(Color.red); 
	g.fillRect(170+13,589+25,24,13);
	g.drawString("(Closed), ",200+13,600+25);
	g.fillRect(260+13,587+25,3,13);
	g.fillRect(260+13+13,587+25,3,13);
	g.drawString("(Opened)",283+13,600+25);

         // Murs principaux entourant la maison
	 g.setColor(coulMur);
	 
         DrawLine(g,20,20,500,20);DrawLine(g,500,20,500,550);
         DrawLine(g,500,550,20,550);DrawLine(g,20,550,20,20);

	 // piece 0
         DrawLine(g,495,200,495,390); // mur de droite
 
	 DrawLine(g,260,200,325,200);
	 DrawLine(g,349,200,410,200); // mur du haut
	 g.setColor(Color.blue);
	 g.drawLine(410,200,422,217); // mur du haut
	 g.drawLine(422,217,434,200); // mur du haut
	 g.setColor(coulMur);
	 DrawLine(g,430,200,495,200); // mur du haut

	 DrawLine(g,260,390,325,390); // mur du bas
	 DrawLine(g,345,390,410,390); // mur du bas
	 g.setColor(Color.blue);
	 g.drawLine(410,390,421,373); // mur du bas
	 g.drawLine(421,373,432,390); // mur du bas
	 g.setColor(coulMur);
	 DrawLine(g,430,390,495,390); // mur du bas
	 
	 DrawLine(g,260,200,260,210); // mur de gauche haut
	 g.setColor(Color.red);
	 g.drawLine(260,210,277,222); // mur de gauche haut
	 g.drawLine(277,222,260,234); // mur de gauche haut
	 g.setColor(coulMur);
	 DrawLine(g,260,230,260,240); // mur de gauche haut
	 DrawLine(g,260,260,260,290); // mur de gauche haut
	 
	 DrawLine(g,260,285,260,305);       // mur de gauche bas
	 g.setColor(Color.red);
	 g.drawLine(260,305,260+17,305+12); // mur de gauche bas
	 g.drawLine(260+17,305+12,260,329); // mur de gauche bas
	 g.setColor(coulMur);
	 DrawLine(g,260,325,260,345);       // mur de gauche bas
	 DrawLine(g,260,365,260,390);       // mur de gauche bas
	// piece 1
         DrawLine(g,25,25,250,25);   // mur haut 
         DrawLine(g,25,25,25,275);   // mur gauche
         DrawLine(g,25,275,90,275);// mur bas
	 g.setColor(Color.blue);// mur bas
	 g.fillRect(90,275,3,13);// mur bas
	 g.fillRect(112,275,3,13);// mur bas
	 g.setColor(coulMur);// mur bas
	 DrawLine(g,112,275,165,275);// mur bas
	 g.setColor(Color.blue);// mur bas
	 g.fillRect(165,275,3,13);// mur bas
	 g.drawLine(165,275,165+12,275-17); // mur de gauche bas
	 g.drawLine(165+12,275-17,186+4,275); // mur de gauche bas
	 g.fillRect(187,275,3,13);// mur bas
	 g.setColor(coulMur);// mur bas
	 DrawLine(g,188,275,250,275);// mur bas

	 DrawLine(g,250,25,250,66);   // mur droite haut
	 DrawLine(g,250,86,250,127);  // mur droite haut
	 g.setColor(Color.red);
	 g.drawLine(250,127,250-17,127+12); // mur droite haut
	 g.drawLine(250-17,127+12,250,147+4); // mur droite haut
	 g.setColor(coulMur);
	 DrawLine(g,250,147,250,210);// mur droite bas
	 DrawLine(g,250,230,250,240);// mur droite bas
	 g.setColor(Color.blue);
	 g.drawLine(250,240,250-17,240+12); // mur droite haut
	 g.drawLine(250-17,240+12,250,260+4); // mur droite haut
	 g.setColor(coulMur);
	 DrawLine(g,250,260,250,275);// mur droite bas
	 
	// piece 2
         DrawLine(g,260,25,495,25);
         DrawLine(g,495,25,495,190);

	 DrawLine(g,260,25,260,66);  // mur gauche
	 g.setColor(Color.blue);
	 g.drawLine(260,66,260+17,66+12); // mur du haut
	 g.drawLine(260+17,66+12,260,86+4); // mur du haut
	 g.setColor(coulMur);
	 DrawLine(g,260,86,260,127); // mur gauche
	 DrawLine(g,260,147,260,190);// mur gauche

	 DrawLine(g,260,190,325,190); // mur du bas
	 g.setColor(Color.red);
	 g.drawLine(325,190,325+12,190-17); // mur du  bas
	 g.drawLine(325+12,190-17,345+4,190); // mur du bas
	 g.setColor(coulMur);
	 DrawLine(g,345,190,410,190);// mur du bas
	 DrawLine(g,430,190,495,190); // mur du bas
	 
	// piece 3
         DrawLine(g,25,285,25,545);   // mur gauche
         DrawLine(g,25,545,250,545);  // mur du bas

         DrawLine(g,25,285,90,285);          // mur du haut  
	 g.setColor(Color.blue);             // mur du haut  
	 g.drawLine(90,285,90+12,285+17);    // mur du haut 
	 g.drawLine(90+12,285+17,110+4,285); // mur du haut 
	 g.setColor(coulMur);
	 DrawLine(g,112,285,165,285);        // mur du haut 
	 DrawLine(g,188,285,250,285);        // mur du haut 

	 DrawLine(g,250,285,250,305); // mur de droite haut
	 DrawLine(g,250,325,250,345); // mur de droite haut 
	 g.setColor(Color.blue);
	 g.drawLine(250,345,250-17,345+12); // mur du haut
	 g.drawLine(250-17,345+12,250,365+4); // mur du haut
	 g.setColor(coulMur);
	 DrawLine(g,250,365,250,400); // mur de droite haut

	 DrawLine(g,250,400,250,431); // mur de droite bas
	 g.setColor(Color.red);
	 g.drawLine(250,431,250-17,431+12);  // mur de droite bas
	 g.drawLine(250-17,431+12,250,451+4); // mur de droite bas
	 g.setColor(coulMur);
	 DrawLine(g,250,451,250,491);  // mur de droite bas
	 DrawLine(g,250,511,250,545);  // mur de droite bas
	 
	// piece 4
         DrawLine(g,260,545,495,545);
         DrawLine(g,495,400,495,545);
	 DrawLine(g,260,400,325,400); // mur du haut
	 g.setColor(Color.red);
	 g.drawLine(325,400,325+12,400+17); // mur du haut
	 g.drawLine(325+12,400+17,345+4,400); // mur du haut
	 g.setColor(coulMur);
	 DrawLine(g,345,400,410,400); // mur du haut
	 DrawLine(g,430,400,495,400); // mur du haut

	 DrawLine(g,260,400,260,431);// mur de gauche
	 DrawLine(g,260,451,260,491);// mur de gauche
	 g.setColor(Color.blue);
	 g.drawLine(260,491,260+17,491+12); // mur  de gauche
	 g.drawLine(260+17,491+12,260,511+4); // mur  de gauche
	 g.setColor(coulMur);
	 DrawLine(g,260,511,260,545);// mur de gauche

	 // Affichage du nom des portes 
	 g.drawString("C1",265,258);
	 g.drawString("C2",230,86);
	 g.drawString("C4",265,365);
	 g.drawString("C5",230,511);
	 g.drawString("C3",415,185);
	 g.drawString("C6",415,415);
	 g.drawString("C7",170,297);
	 g.drawString("C7",95,272);

	 
	 g.drawString("M1",330,215);
	 g.drawString("M2",265,150);
	 g.drawString("M3",230,230);
	 g.drawString("M4",330,386);
	 g.drawString("M5",265,447);
	 g.drawString("M6",230,321);

	 
        
    }

    /** reaffiche la maison.
     *  Cette methode est redefini, car par defaut, 
     *  elle efface le composant avant de le repeindre.
     *  Ce qui est une perte de temps.
     */
    public void update(Graphics g){
	paint(g);
    }

    /** initialisation */
    public Plan() { 
	setBackground(Color.white);
	setSize(largeur,hauteur);	  	
	setLayout(null); 
    }
    
} // Maison

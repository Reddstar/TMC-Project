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
  
    static String gifDir = "../demo/Images.dir/";
 
    public Font fontSelected; //fonte qui sera selectionnee
  
    Image Fond;
  
    /** largeur de l'appli en pixels */
    static final int largeur = 720;

    /** hauteur de l'appli en pixels */
    static final int hauteur = 550;
  
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
    public void DrawRectangle(Graphics g,int x, int y, int l, int h){
	DrawLine(g,x,y,x+l,y);
	DrawLine(g,x+l,y,x+l,y+h);
	DrawLine(g,x+l,y+h,x,y+h);
	DrawLine(g,x,y+h,x,y);
    }
   

    /** affiche l'image de l'appli */
    public void paint(Graphics g){

	//Contour
	DrawRectangle(g,10,10,700,550);  

	// Pump 
	DrawRectangle(g,100,100,170,130);  
	DrawLine(g,10,147,400,147);
	DrawLine(g,10,171,400,171); 
	g.fillRect(150,130,60,19);
	g.fillRect(150,171,60,19);

	// Valve 2
	g.fillRect(300,130,60,19);
	g.fillRect(300,171,60,19); 
	
	// Water Tank
       	DrawLine(g,400,171,400,400); 
	DrawLine(g,400,400,430,400);
	DrawLine(g,460,400,590,400);
	DrawLine(g,618,400,650,400); 
	DrawLine(g,650,400,650,175);
	DrawLine(g,400,147,400,100);

	// Valve 3 
	DrawLine(g,430,398,430,500);
	DrawLine(g,460,400,460,500); 
	g.fillRect(410,440,20,50);  
	g.fillRect(460,440,20,50); 

	// Valve 4
	DrawLine(g,589,398,589,500); 
	DrawLine(g,619,400,619,500); 
	g.fillRect(570,440,20,50);  
	g.fillRect(620,440,20,50);  



        g.setColor(Color.blue);
	g.fillRect(13,100+50,170,21);
	g.fillRect(403,390,247,11);   
	
	g.setColor(Color.black);
	g.drawString("X1",660,400);
	g.drawString("X2",660,340);
	g.drawString("X3",660,290);
	g.drawString("X4",660,240);
	g.drawString("X5",660,190);
	g.setColor(Color.red);
	g.drawString("X0",660,430);
	g.drawString("X6",660,160);
	g.setColor(Color.blue);
	g.drawString("U1",150+20,138+70);
	g.drawString("U2",290+35,138+70);
	g.drawString("U3",410+30,545);
	g.drawString("U4",570+30,545);
	fontSelected = new Font ("Helvetica",Font.PLAIN,24);
        g.setFont(fontSelected);
        g.setColor(Color.blue);  
	g.drawString("Pump",150,123);
	g.drawString("Valve 2",290,123);
	g.drawString("Valve 3",410,530);
	g.drawString("Valve 4",570,530);
        g.setColor(Color.red); 
	g.drawString("Supervisory Control Problem",40,300);
	g.drawString("Control of a Water Tank",60,330);  
	fontSelected = new Font ("Helvetica",Font.PLAIN,18);
        g.setFont(fontSelected);
        g.setColor(Color.blue); 
	g.drawString(" + Forbidden States : X0 and X6",50,360);
	g.drawString(" + Control Tasks :",50,380); 
	g.drawString(" Task 1 : From X1 to X5 ",100,400); 
	g.drawString(" Task 2 : From X5 to X1 ",100,420); 
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

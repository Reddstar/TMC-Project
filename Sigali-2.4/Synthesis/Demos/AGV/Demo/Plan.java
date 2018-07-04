import java.awt.*;

/**
 * Plan.java
 * Plan de l'usine.
 *
 * Created: Tue Jul 28 12:02:35 1998
 *
 * @author Herve Marchand
 * @version
 * @see vt
 */

public class Plan extends Panel {

    /** coef pour reduire la taille de l'application */
    static final  float Coef = 1;

    /** couleur des murs des stations de travails */
    static final Color coulWST = Color.black;

    /** couleur des zones de conflits */
    static final Color coulZoneConflit = Color.darkGray;

    /** largeur de l'usine en pixels */
    static final int largeur = 536 ;

    /** hauteur de l'usine en pixels */
    static final int hauteur = 688 ;

    /** dessine un mur de station de travail
     *  @param g contexte graphique necessaire a l'affichage.
     *  @param x1 coordonnee horizontale de la 1ere extremitee du mur.
     *  @param y1 coordonnee verticale de la 1ere extremitee du mur.
     *  @param x2 coordonnee horizontale de la 2nde extremitee du mur.
     *  @param y2 coordonnee verticale de la 2nde extremitee du mur.
     */
    public void dessineMurStation(Graphics g,int x1, int y1, int x2, int y2){
	int h =  10;
	int xp[] = new int[4]; int yp[] = new int[4];
	xp[0]= x1; yp[0]= y1;
	xp[1]= x1+h; yp[1]= y1+h;
	xp[2]= x2+h; yp[2]= y2+h;
	xp[3]= x2; yp[3]= y2 ;
	Polygon p = new Polygon(xp,yp,4);
	g.fillPolygon(p);
    }

    /** dessine une zone de conflit.
     *  @param g contexte graphique necessaire a l'affichage.
     *  @param x coordonnee horizontale du coin superieur gauche de la zone de conflit.
     *  @param y coordonnee verticale du coin superieur gauche de la zone de conflit.
     *  @param l largeur de la zone de conflit.
     *  @param h hauteur de la zone de conflit.
     */
    public void dessineZoneConflit(Graphics g,int x, int y, int l, int h){
	g.setColor(coulZoneConflit);
	g.drawRect(x, y,l, h);
 	g.drawRect(x+1, y+1, l-2,h-2);
	g.setColor(Color.white);
        g.fillRect(x+1, y+1, l-1, h-1);
   }

    public void dessine_rectangle(Graphics g,int x, int y, int l, int h){
	g.drawRect( x, y, l, h);
    }

    public void dessine_ligne(Graphics g,int x, int y,int xx, int yy){
	g.drawLine( x, y, xx, yy);
    }

    public void dessine_rectangle_rond(Graphics g,int x,int y,int z,int t,int u,int v){
	 g.drawRoundRect( x, y, z, t, u, v);
    }

    public void dessine_arc(Graphics g, int x, int y, int z,int t,int u,int v){
	g.drawArc( x, y, z, t,u,v);
    }

    public void dessine_oval(Graphics g,int x, int y, int z,int t){
	 g.drawOval( x, y, z, t);
    }

    /** affiche l'image de l'usine */
    public void paint(Graphics g){

	// Nom de L'application
	dessine_rectangle(g,8,620,240,40);
	dessine_rectangle(g,8+1,620+1,240-2,40-2);
	g.drawString("SUPERVISORY CONTROL PROBLEM",18,635);
	g.drawString("The Production Cell Example",28,650);

	// affichage de la work station numero 1
	g.setColor(coulWST);
	dessineMurStation(g,0,0,95,0);
	dessineMurStation(g,95,0,95,11);
	dessineMurStation(g,95,71,95,95);
	dessineMurStation(g,95,155,95,163);
	dessineMurStation(g,95,163,0,163);
	dessineMurStation(g,0,163,0,0);
	g.drawString("WST 1",25,20);
	dessine_oval(g,23,23,48,48);
	dessine_oval(g,23,100,48,48);

	// affichage de la work station numero 2
	g.setColor(coulWST);
	dessineMurStation(g,431,0,527,0);     // mur du haut
	dessineMurStation(g,527,0,527,275);   // mur de droite
	dessineMurStation(g,431,275,527,275); // mur du bas
	dessineMurStation(g,431,0,431,11);    // petit mur haut a gauche
	dessineMurStation(g,431,73,431,190);  // mur du milieu a gauche
	dessineMurStation(g,431,250,431,275); // mur du bas a gauche
	g.drawString("WST 2",431+25,20);
	dessine_rectangle_rond(g,455,47,48,180,24,24);

	// affichage de la work station numero 3
	 g.setColor(coulWST);
	 dessineMurStation(g,431,299,527,299); // mur du haut
	 dessineMurStation(g,527,299,527,551); // mur de droite
	 dessineMurStation(g,431,551,527,551); // mur du bas
	 dessineMurStation(g,431,299,431,316); // petit mur haut a gauche
	 dessineMurStation(g,431,373,431,479); // mur du milieu a gauche
	 dessineMurStation(g,431,533,431,551); // mur du bas a gauche
	 g.drawString("WST 3",431+25,299+20);
	 dessine_rectangle_rond(g,455,347,48,160,24,24);


	// affichage de la work station numero 4
	 g.setColor(coulWST);
	 dessineMurStation(g,431,587,527,587); // mur du haut
	 dessineMurStation(g,527,587,527,671);
	 dessineMurStation(g,431,671,527,671);
	 dessineMurStation(g,431,587,431,599);
	 dessineMurStation(g,431,659,431,671);
	 g.drawString("WST 4",431+25,587+20);
	 dessine_oval(g,455,611,48,48);

	// affichage de la work station numero 5
	 g.setColor(coulZoneConflit);
	 dessineMurStation(g,0,178,95,178);
	 dessineMurStation(g,95,178,95,187);
	 dessineMurStation(g,95,244,95,257);
	 dessineMurStation(g,95,257,143,257);
	 dessineMurStation(g,143,257,143,335);
	 dessineMurStation(g,143,395,143,479);
	 dessineMurStation(g,143,479,120,479);
	 dessineMurStation(g,120,479,120,503);
	 dessineMurStation(g,120,560,120,575);
	 dessineMurStation(g,120,575,0,575);
	 dessineMurStation(g,0,575,0,178);
	 g.drawString("WST 5",30,178+20);
	 dessine_ligne(g,35,220,59,220);
	 dessine_arc(g,23,220,24,24,90,90);
	 dessine_arc(g,23,347,24,24,90,90);
	 dessine_ligne(g,23,232,23,527);
	 dessine_arc(g,23,515,24,24,-90,-90);
	 dessine_ligne(g,35,539,83,539);
	 dessine_arc(g,71,515,24,24,0,-90);
	 dessine_ligne(g,95,455,95,527);
	 dessine_arc(g,71,443,24,24,0,90);
	 dessine_arc(g,95,443,24,24,90,90);
	 dessine_arc(g,71,419,24,24,-90,-90);
	 dessine_arc(g,95,419,24,24,0,-90);
	 dessine_ligne(g,71,232,71,431);
	 dessine_ligne(g,119,359,119,431);
	 dessine_arc(g,47,220,24,24,0,90);
	 dessine_arc(g,95,347,24,24,0,90);
	 dessine_ligne(g,35,347,107,347);

	 // affichage des zones de conflits
	 dessineZoneConflit(g,178,0,48,180);
	 dessineZoneConflit(g,240,178,98,98);
	 dessineZoneConflit(g,240,299,98,120);
	 dessineZoneConflit(g,240,467,98,120);

	// affichage du circuit AGV1
	 g.setColor(Color.red);
	 dessine_rectangle_rond(g,95,23,343,48,24,24);
	 g.drawString("AGV1",378,50);

	// affichage du circuit AGV2
	 g.setColor(Color.blue);
	 dessine_ligne(g,107,107,299,107);      // fil du haut
	 dessine_arc(g,95,107,24,24,90,90);    // arc haut gauche
	 dessine_ligne(g,95,119,95,142);        // fil extreme gauche
	 dessine_arc(g,95,131,24,24,-90,-90);  // arc bas  gauche
	 dessine_ligne(g,107,155,251,155);      // fil milieu haut gauche
	 dessine_arc(g,240,155,24,24,0,90);    // arc milieu vers le bas
	 dessine_ligne(g,264,167,264,359);      // fil milieu gauche vers bas
	 dessine_arc(g,264,347,24,24,-90,-90); // arc milieu vers droite
	 dessine_ligne(g,277,372,425,372);      // fil bas milieu
         dessine_arc(g,415,348,24,24,0,-90);   // arc droite vers haut
	 dessine_ligne(g,439,360,439,337);      // file extreme droite
	 dessine_arc(g,415,325,24,24,0,90);    //  arc droite vers gauche
	 dessine_ligne(g,325,324,426,324);      // file milieu bas
	 dessine_arc(g,313,299,24,24,-90,-90);
	 dessine_ligne(g,313,119,313,313);
	 dessine_arc(g,289,107,24,24,0,90);
	 g.drawString("AGV2",378,350);

	// affichage du circuit AGV3
	 g.setColor(Color.red);
	 dessine_rectangle_rond(g,95,200,343,48,24,24);
	 g.drawString("AGV3",378,231);

	// affichage du circuit AGV4
	 g.setColor(Color.red);
	 dessine_ligne(g,155,347,299,347); // fil du haut
	 dessine_arc(g,143,347,24,24,90,90); // arc haut gauche
	 dessine_ligne(g,143,359,143,383);  // fil extreme gauche
	 dessine_arc(g,143,371,24,24,-90,-90); // arc bas  gauche
	 dessine_ligne(g,155,396,251,396); // fil milieu haut gauche
	 dessine_arc(g,238,396,24,24,0,90);  // arc milieu vers le bas
	 dessine_ligne(g,263,408,263,520); // fil milieu gauche vers bas
	 dessine_arc(g,263,508,24,24,-90,-90);  // arc milieu vers droite
	 dessine_ligne(g,275,532,426,532); // fil bas milieu
 	 dessine_arc(g,415,508,24,24,0,-90); // arc droite vers haut
 	 dessine_ligne(g,439,520,439,497); // file extreme droite
 	 dessine_arc(g,414,484,24,24,0,90); //  arc droite vers gauche
 	 dessine_ligne(g,325,484,426,484); // file milieu bas
 	 dessine_arc(g,313,460,24,24,-90,-90);
	 dessine_ligne(g,313,359,313,471);
	 dessine_arc(g,288,347,24,24,0,90);
	 g.drawString("AGV4",378,512);

	// affichage du circuit AGV5
	 g.setColor(Color.blue);
	 dessine_ligne(g,131,515,299,515);       // fil du haut
	 dessine_arc(g,119,515,24,24,90,90);    // arc haut gauche
	 dessine_ligne(g,119,527,119,551);       // fil extreme gauche
	 dessine_arc(g,119,539,24,24,-90,-90);  // arc bas  gauche
	 dessine_ligne(g,131,563,251,563);       // fil milieu haut gauche
	 dessine_arc(g,238,563,24,24,0,90);     // arc milieu vers le bas
	 dessine_ligne(g,263,575,263,647);       // fil milieu gauche vers bas
	 dessine_arc(g,263,635,24,24,-90,-90);  // arc milieu vers droite

	 dessine_ligne(g,275,659,426,659);       // fil bas milieu
 	 dessine_arc(g,415,635,24,24,0,-90);    // arc droite vers haut
 	 dessine_ligne(g,439,647,439,624);       // file extreme droite
 	 dessine_arc(g,414,611,24,24,0,90);     //  arc droite vers gauche
 	 dessine_ligne(g,325,611,426,611);       // file milieu bas
 	 dessine_arc(g,313,587,24,24,-90,-90);
	 dessine_ligne(g,313,527,313,599);
	 dessine_arc(g,288,515,24,24,0,90);
	 g.drawString("AGV5",378,639);

	// affichage des noms des feux
	// (les feux sont crees dans vt.java)
	 g.setColor(Color.black);
	 g.drawString("C10", 325, 600-2);
	 g.drawString("C9", 219, 550-2);
	 g.drawString("C8", 347, 474-2 );
	 g.drawString("C7", 219 , 376-2 );
	 g.drawString("C6", 347 , 180-2 );
	 g.drawString("C5", 219 , 235-2 );
	 g.drawString("C4", 347 , 312-2 );
	 g.drawString("C3", 159 , 143-2 );
	 g.drawString("C2", 233 , 11-2 );
	 g.drawString("C1", 159 , 59-2 );

    }

    /** reaffiche l'usine.
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

} // Plan

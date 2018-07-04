import java.awt.*;
import javax.swing.*;

/**
 * vt.java
 * Programme principal : LES CHARIOTS FILOGUIDES
 * <dt>
 * Created: Tue Jul 28 11:28:05 1998
 *
 * @author Hervé Marchand
 * @version
 * @see ChariotAGV
 * @see ChariotWST
 * @see WST
 * @see Plan
 * @see InteResolv
 */

public class vt extends Fenetre implements Runnable {
    static  final int Coef=1;

    static final int OUEST = 0;
    static final int SUD   = 1;
    static final int EST   = 2;
    static final int NORD  = 3;

    /** codage de la valeur TRUE */
    static int TRUE = 1;

    /** codage de la valeur FALSE */
    static int FALSE = 0;

    /** lien avec la vt_body ecrit en C */
    static LiaisonBody LV = new LiaisonBody();

    /** Interface du resolver */
    static InteResolv IR = new InteResolv("vt.sim","vt.res");
    /** represente l'usine */
    static Plan plan = new Plan();

    /** represente les 10 feux signalant l'etat des portes */
    static Feux[] feux = new Feux[10];

    /** les 5 chariots AGV */
    static ChariotAGV[] chariotAGV = new ChariotAGV[5];

    /** methode externe pour dessiner le chariot AGV1 */
    public static void dessine_chariot_agv1(int Pos_AGV[]){
	chariotAGV[0].dessine(Pos_AGV);
    }

    /** methode externe pour dessiner le chariot AGV2 */
    public static void dessine_chariot_agv2(int Pos_AGV[]){
	chariotAGV[1].dessine(Pos_AGV);
    }

    /** methode externe pour dessiner le chariot AGV3 */
    public static void dessine_chariot_agv3(int Pos_AGV[]){
	chariotAGV[2].dessine(Pos_AGV);
    }

    /** methode externe pour dessiner le chariot AGV4 */
    public static void dessine_chariot_agv4(int Pos_AGV[]){
	chariotAGV[3].dessine(Pos_AGV);
    }

    /** methode externe pour dessiner le chariot AGV5 */
    public static void dessine_chariot_agv5(int Pos_AGV[]){
	chariotAGV[4].dessine(Pos_AGV);
    }

    /** methode externe pour dessiner les chariots du WST1 */
    public static void dessine_chariot_wst1(int Pos_WST[]){
        int[] pos = new int[3];
	pos[1]=Pos_WST[1];
	pos[2]=Pos_WST[2];
	WST.S[0].chariots[0].dessine(pos);
	pos[1]=Pos_WST[3];
	pos[2]=Pos_WST[4];
	WST.S[0].chariots[1].dessine(pos);
    }

    /** methode externe pour dessiner le chariot du WST2 */
    public static void dessine_chariot_wst2(int Pos_WST[]){
	WST.S[1].chariots[0].dessine(Pos_WST);
    }

    /** methode externe pour dessiner le chariot du WST3 */
    public static void dessine_chariot_wst3(int Pos_WST[]){
	WST.S[2].chariots[0].dessine(Pos_WST);
    }

    /** methode externe pour dessiner le chariot du WST4 */
    public static void dessine_chariot_wst4(int Pos_WST[]){
	WST.S[3].chariots[0].dessine(Pos_WST);
    }

    /** methode externe pour dessiner les chariots du WST5 */
    public static void dessine_chariot_wst5(int Pos_WST[]){
	// dessin du premier chariot:
	int[] pos = new int[5];
	pos[1]=Pos_WST[1];
	pos[2]=Pos_WST[2];
	pos[3]=Pos_WST[5];
	pos[4]=Pos_WST[6];
	WST.S[4].chariots[0].dessine(pos);

	// dessin du second chariot:
	pos = new int[3];
	pos[1]=Pos_WST[3];
	pos[2]=Pos_WST[4];
	boolean present = (pos[1]+pos[2]!=0);
	if (present) {
	    WST.S[4].chariots[1].setVisible(true);
	    WST.S[4].chariots[1].dessine(pos);
	} else  WST.S[4].chariots[1].setVisible(false);
    }

    /** methode externe pour afficher Conflit */
    public static void affiche_conflit(int a, int b, int c, int d){
	// a completer
	if ((a==1)) JOptionPane.showMessageDialog(plan, "Conflict Zone 1");
	if ((b==1)) JOptionPane.showMessageDialog(plan, "Conflict Zone 2");
	if ((c==1)) JOptionPane.showMessageDialog(plan, "Conflict Zone 3");
	if ((d==1)) JOptionPane.showMessageDialog(plan, "Conflict Zone 4");
    }

    /** methode externe pour quitter l'application */
    public static void wstop()
    {
	System.out.println("END");
	System.exit(0);
    }
    
    /** iteration : appelee a chaque instant */
    public void run(){
	boolean top = true;
	while (true) {
	    try {Thread.sleep(IR.pacemaker.paceV.vitesse);} catch (InterruptedException ie){};
	    // une fois sur deux on lance une iteration de signal
	    if (top){
		ModesResolv.verif();
		// pour garder en vie les references des methodes
		//  appelees par les modules ecrits en C++
		LV.connexionBody();
		if(LV.vt_iterate()){};
		top = false;
		try {Thread.sleep(40*IR.pacemaker.paceV.vitesse);} catch (InterruptedException ie){};
	    }
	    else { // une fois sur deux on fait avancer les chariots qui sont en mouvement
		for (int i=0; i<5; i++)
		    if (chariotAGV[i].enMouvement) chariotAGV[i].avance();
		for (int i=0; i<5; i++)
		    if (WST.S[i].chariots[0].enMouvement) WST.S[i].chariots[0].avance();
		if (WST.S[0].chariots[1].enMouvement) WST.S[0].chariots[1].avance();
		if (WST.S[4].chariots[1].enMouvement) WST.S[4].chariots[1].avance();
		top = true;
	    }
	}
    }

    /** initialisation */
    public vt() {
	super("Supervisory Control Problem: The Production Cell Example");
	// setLayout(null);
	// IR.pacemaker.paceV.setLocation(10,25);
	// IR.pacemaker.paceA.setLocation(250,25);
	// IR.pacemaker.paceA.setSize(240,31);
	// IR.modes.setLocation(500,25);
	// IR.modes.setSize(175,31);
	// add(IR.pacemaker.paceV);
  	// BoutonCommande boutonCommande = new BoutonCommande();
	// // IR.pacemaker.paceA.add(boutonCommande);
	// add(IR.pacemaker.paceA);
 	// add(IR.modes);
	// IR.fenCont.pack();
	// IR.fenCont.setVisible(false);
	add(plan);
	if(LV.vt_initialize()){};
	Thread iterateur = new Thread(this);
	ListEntrees.Cont.debut();
	 feux[9] = new Feux(ListEntrees.Cont.eltCourant(),159,59); // feux de l'entree C1
	 ListEntrees.Cont.avance();
	 feux[8] = new Feux(ListEntrees.Cont.eltCourant(),233,11); // feux de l'entree C2
	 ListEntrees.Cont.avance();
	 feux[7] = new Feux(ListEntrees.Cont.eltCourant(),159,143); // feux de l'entree C3
	 ListEntrees.Cont.avance();
	 feux[6] = new Feux(ListEntrees.Cont.eltCourant(),347,312); // feux de l'entree C4
	 ListEntrees.Cont.avance();
	 feux[5] = new Feux(ListEntrees.Cont.eltCourant(),219,235); // feux de l'entree C5
	 ListEntrees.Cont.avance();
	 feux[4] = new Feux(ListEntrees.Cont.eltCourant(),347,180); // feux de l'entree C6
	 ListEntrees.Cont.avance();
	 feux[3] = new Feux(ListEntrees.Cont.eltCourant(),219,376); // feux de l'entree C7
	 ListEntrees.Cont.avance();
	 feux[2] = new Feux(ListEntrees.Cont.eltCourant(),347,474); // feux de l'entree C8
	 ListEntrees.Cont.avance();
	 feux[1] = new Feux(ListEntrees.Cont.eltCourant(),219,550); // feux de l'entree C9
	 ListEntrees.Cont.avance();
	 feux[0] = new Feux(ListEntrees.Cont.eltCourant(),325,600); // feux de l'entree C10
	 ListEntrees.Cont.avance();
	for (int i=0; i<10; i++) plan.add(feux[i]);

 	// initialisation des chariots AGV
	// chariot 1
	int[] chemin1x = {150,120,80,120 ,130,187,
			  280,378,425 ,260  ,230  ,187};
  	int[] chemin1y = {11,11,33,55    ,55 ,55 ,
			  55 ,55 ,30  ,11   ,11   ,11};
	int[] chemin1d = {OUEST,OUEST,SUD,EST,EST,EST,EST,EST,NORD,OUEST,OUEST,OUEST};
	int[] chemin1c = {0,0,1,1,1,1,1,1,0,0,0,0};
	chariotAGV[0] = new ChariotAGV(chemin1x,chemin1y,chemin1d,chemin1c,
				       new PieceNum1(),6,Color.red);
	// chariot 2
	int[] chemin2x = {150,120,80,120,160,187,
			  218,248,248,248,248,248,
			  315, 378,425,378,350,300,
			  300,300,300,300, 250,190};
  	int[] chemin2y = {95 ,95 ,117,139,139,139,
			  139,139,170,210,300,353,
			  353, 353,329,310,310,310,
			  275,210,130,95,95, 95};
	int[] chemin2d = {OUEST,OUEST,SUD,EST,EST,EST,EST,SUD,SUD,SUD,SUD,EST,
			  EST,EST,NORD,OUEST,OUEST,NORD,NORD,NORD,NORD,OUEST,OUEST,OUEST};
	int[] chemin2c = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0};
	chariotAGV[1] = new ChariotAGV(chemin2x,chemin2y,chemin2d,chemin2c,
				       new PieceNum2(),12,Color.blue);

	// chariot 3
	int[] chemin3x = {215,130,80,180,  210,274,
			  338,378, 425,378,334,274};
  	int[] chemin3y = {190,190,212,234, 234,234,
			  234,234, 212,190,190,190};
	int[] chemin3d = {OUEST,OUEST,SUD,EST,EST,EST,EST,EST,NORD,OUEST,OUEST,OUEST};
	int[] chemin3c = {3,3,0,0,0,0,0,0,3,3,3,3};
	chariotAGV[2] = new ChariotAGV(chemin3x,chemin3y,chemin3d,chemin3c,
				       new PieceNum1(),6,Color.red);

	// chariot 4
	int[] chemin4x = {200,180, 130,180, 218,248,
			  248,248, 248,268,347,378,425,
			  378, 330,300, 300,300,300,300};
  	int[] chemin4y = {335,335, 357,379, 379,379,
			  415,430, 480,517,517,517,489,
			  470, 472, 472, 435,420,370,330};
	int[] chemin4d = {OUEST,OUEST,SUD,EST,EST,SUD,SUD,SUD,SUD,EST,
			  EST,EST,NORD,OUEST,OUEST,NORD,NORD,NORD,NORD,OUEST};
	int[] chemin4c = {3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3};
	chariotAGV[3] = new ChariotAGV(chemin4x,chemin4y,chemin4d,chemin4c,
				       new PieceNum2(),10,Color.red);

	// chariot 5
	int[] chemin5x = {200,160,110,180, 220,248, 250,
			  250, 308,378, 435,378, 360,340,
			  295,295};
  	int[] chemin5y = {500,500,522,550, 550,550, 600,
			  642, 642,642, 615,598, 598,598,
			  550,498};
	int[] chemin5d = {OUEST,OUEST,SUD,EST,EST,SUD,SUD,EST,EST,EST,
			  NORD,OUEST,OUEST,OUEST,NORD,OUEST};
	int[] chemin5c = {0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,0};
	chariotAGV[4] = new ChariotAGV(chemin5x,chemin5y,chemin5d,chemin5c,
				       new PieceNum3(),8,Color.blue);

	setBackground(Color.gray);
	setVisible(true);
	// plan.setLocation(10,30);
       	setSize(plan.largeur+10,plan.hauteur+20);
	IR.fenCont.setLocation(600,200);
	iterateur.start();
	setLocation(20,40);
    }


    /** lancement de l'application */
    public static void main(String[] args) {
	vt application = new vt();
    }
} // vt

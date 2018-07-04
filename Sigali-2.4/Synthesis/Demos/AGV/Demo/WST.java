import java.awt.*;

/**
 * WST.java
 * Cette classe decrit les station de travail avec leurs chariots.
 * L'aspect graphique d'une station de travail se trouve dans la classe Usine.
 * Created: Thu Jul 30 09:50:33 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see ChariotAGV
 * @see Usine
 */

public class WST {

    static final int OUEST = 0;
    static final int SUD   = 1;
    static final int EST   = 2;
    static final int NORD  = 3;
    static final int Coef = 1;
    /** les 5 stations */
    static WST[] S = new WST[5];

    /** initialisation des stations */
    static{
	// station numero 1 (avec 2 chariots):		
	ChariotAGV[] chariots1 = new ChariotAGV[2];
        int[] chemin1x = {12/Coef,55/Coef,30/Coef,12/Coef};
  	int[] chemin1y = {30/Coef,30/Coef,60/Coef,30/Coef};
	int[] chemin1d = {NORD,SUD,OUEST,NORD};
	int[] chemin1c = {0,1,0,0};
	chariots1[0] = new ChariotAGV(chemin1x,chemin1y,chemin1d,chemin1c,
				      new PieceNum1(),2,Color.black);

	int[] chemin1bisx = {12/Coef,55/Coef,30/Coef,12/Coef};
  	int[] chemin1bisy = {110/Coef,110/Coef,130/Coef,110/Coef};
	int[] chemin1bisd = {NORD,SUD,OUEST,NORD};
	int[] chemin1bisc = {0,1,0,0};
	chariots1[1] = new ChariotAGV(chemin1bisx,chemin1bisy,chemin1bisd,chemin1bisc,
				      new PieceNum2(),2,Color.black);
	S[0] = new WST(chariots1,2);
	// station numero 2 (avec 1 chariot):	
	ChariotAGV[] chariots2 = new ChariotAGV[1];
	int[] chemin2x = {443/Coef,443/Coef, 490/Coef, 490/Coef, 490/Coef, 490/Coef, 490/Coef, 443/Coef};
  	int[] chemin2y = {120/Coef,35/Coef,35/Coef,100/Coef, 160/Coef, 180/Coef, 210/Coef, 210/Coef};
	int[] chemin2d = {NORD,EST,SUD,SUD,SUD,SUD,OUEST,NORD};
	int[] chemin2c = {0,0,1,1,2,2,3,3};
	chariots2[0] = new ChariotAGV(chemin2x,chemin2y,chemin2d,chemin2c,
				      new PieceNum1(),4,Color.black);
	S[1] = new WST(chariots2,1);
	// station numero 3 (avec 1 chariot):	
	ChariotAGV[] chariots3 = new ChariotAGV[1];
	int[] chemin3x = {443/Coef,443/Coef, 490/Coef, 490/Coef, 490/Coef, 490/Coef, 490/Coef, 443/Coef};
  	int[] chemin3y = {380/Coef,335/Coef, 335/Coef,375/Coef, 420/Coef, 460/Coef, 490/Coef, 490/Coef};
	int[] chemin3d = {NORD,EST,SUD,SUD,SUD,SUD,OUEST,NORD};
	int[] chemin3c = {0,0,1,1,2,2,3,3};
	chariots3[0] = new ChariotAGV(chemin3x,chemin3y,chemin2d,chemin2c,
				      new PieceNum2(),4,Color.black);
	S[2] = new WST(chariots3,1);
	// station numero 4 (avec 1 chariot):	
	ChariotAGV[] chariots4 = new ChariotAGV[1];
	int[] chemin4x = {490/Coef,490/Coef, 466/Coef, 443/Coef};
  	int[] chemin4y = {619/Coef,619/Coef, 640/Coef, 619/Coef};
	int[] chemin4d = {SUD,SUD,OUEST,NORD};
	int[] chemin4c = {3,3,0,0};
	chariots4[0] = new ChariotAGV(chemin4x,chemin4y,chemin4d,chemin4c,
				      new PieceNum3(),2,Color.black);
	S[3] = new WST(chariots4,1);
	// station numero 5 (avec 2 chariots):	
	ChariotAGV[] chariots5 = new ChariotAGV[2];
	int[] chemin5x = { 14/Coef, 55/Coef, 55/Coef, 55/Coef, 80/Coef, 80/Coef, 80/Coef, 80/Coef};
  	int[] chemin5y = {390/Coef,210/Coef, 280/Coef,390/Coef, 460/Coef,480/Coef, 510/Coef, 530/Coef};
	int[] chemin5d = {NORD,SUD,SUD,SUD,SUD,SUD,SUD,SUD};
	int[] chemin5c = {0,0,1,1,2,2,3,3};
	chariots5[0] = new ChariotAGV(chemin5x,chemin5y,chemin5d,chemin5c,
				      new PieceNum3(),4,Color.black);

	int[] chemin5bisx = {50/Coef,105/Coef, 105/Coef, 105/Coef};
  	int[] chemin5bisy = {330/Coef,355/Coef, 390/Coef, 390/Coef};
	int[] chemin5bisd = {EST,SUD,SUD,SUD};
	int[] chemin5bisc = {0,0,3,3};
	chariots5[1] = new ChariotAGV(chemin5bisx,chemin5bisy,chemin5bisd,chemin5bisc,
				      new PieceNum2(),2,Color.black);
	S[4] = new WST(chariots5,2);
    }

    /** les chariots de la station */
    ChariotAGV[] chariots;
    
    /** le nombre de chariots de la station */
    int nbChariots;

    /** construction d'une station de travail.
     * @param chariots les chariots de la station de travail.
     * @param nbChariots le nombre de chariots de la station.
     */
    public WST(ChariotAGV[] chariots, int nbChariots) {
	this.chariots=chariots;
	this.nbChariots=nbChariots;		        
    }
    
} // WST

/**
 * LiaisonPacemaker.java
 * <dt> Cette classe permet de faire le lien entre le code ecrit en C++ par SIGNAL
 * et la classe Pacemaker.java.*
 * Le principe est le meme que celui de LiaisonResolveur.java
 * <dt>
 * Created: Tue Aug  4 09:43:47 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see Pacemaker
 * @see PacemakerAction
 * @see PacemakerVitesse
 * @see LiaisonResolveur pour plus d'explications.
 */

public class LiaisonPacemaker {

    //***********************************
    // Declarations des fonctions natives
    //***********************************     
    native void n_inter_pace_up_p();
    native void n_inter_pace_down_p();
    native void n_inter_pace_up_m();
    native void n_inter_pace_down_m();
    native void n_inter_auto();
    native void n_inter_stop();
    native void n_inter_tick();

    //**************************************
    // Constructeur de classe qui appelle le
    // chargement de la librairie VTAGVLIB
    //**************************************

    static {
  	System.loadLibrary("VTAGVLIB");
    };

    //***********************************
    // Methodes appelees par Pacemaker*.java
    //***********************************

    public synchronized void inter_pace_up_p(){
	n_inter_pace_up_p();
    }

    public synchronized void inter_pace_down_p(){
	n_inter_pace_down_p();
    }

    public synchronized void inter_pace_up_m(){
	n_inter_pace_up_m();
    }

    public synchronized void inter_pace_down_m(){
	n_inter_pace_down_m();
    }

    public synchronized void inter_auto(){
	n_inter_auto();
    }

    public synchronized void inter_stop(){
	n_inter_stop();
    }

    public synchronized void inter_tick(){
	n_inter_tick();
    }

    public LiaisonPacemaker() {	
    }
    
} // LiaisonPacemaker

import java.awt.*;
import java.awt.event.*;

/**
 * PacemakerAction.java
 * gere le mode de fonctionnement (Automatique/Manuel)
 * et permet de quiter l'application.
 *
 * Created: Mon Aug  3 11:37:58 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class PacemakerAction extends Panel implements ActionListener{

    /** Codage de la couleur du fond des entrees. */
    static final Color coulFond   = Color.blue;
    
    /** pour quiter la simulation. */
    static public Bouton boutQuit;

    /** pour passer du mode manuel au mode automatique et viceversa. */
    static public Bouton boutMode;

    /** pour faire avancer la simulation d'un pas. */
    static public Bouton boutTick;

    /** est charge de surveiller si l'utilisateur touche au boutons.
     *  @param evenement l'evenement declancheur
     */
    public synchronized void actionPerformed(ActionEvent evenement){
	String nomBouton = evenement.getActionCommand(); // nom du bouton presse
	if (nomBouton.equals("QUIT")) {
	    Pacemaker.LP.inter_stop();
	}
	else if (nomBouton.equals("AUTO")) { // on passe en mode automatique
	    //    ModesResolv.etat_continu=true;
	    // 	  ModesResolv.boxContinu.setState(true);
	    Pacemaker.LP.inter_auto();
	}
	else if (nomBouton.equals("MANU")) { // on passe en mode manuel
	    //   ModesResolv.etat_continu=false;
	    // 	 ModesResolv.boxContinu.setState(false);
	    Pacemaker.LP.inter_auto();
	}
	else if (nomBouton.equals("TICK")) { 
	    Pacemaker.LP.inter_tick();
	} 
    }

    /** mets a jour le comportement des boutons.
     *  @param cauto si a vrai le bouton du milieu est le seul accesible 
     *               et est marque "MANU".
     *               sinon les trois boutons : (QUIT,AUTO,TICK) sont accessibles.
     */
    static public synchronized void reset_panel(boolean cauto){
	if (cauto) {
	    boutMode.setLabel("MANU");
	    boutQuit.setEnabled(false);
	    boutTick.setEnabled(false);
	}
	else {
	    boutMode.setLabel("AUTO");
	    boutQuit.setEnabled(true);
	    boutTick.setEnabled(true);
	}
    }

    /** construction du panneau interactif. */
    public PacemakerAction() {
	boutQuit  = new Bouton("QUIT"); boutQuit.addActionListener(this);	
  	boutMode  = new Bouton("AUTO"); boutMode.addActionListener(this);	
	boutTick  = new Bouton("TICK"); boutTick.addActionListener(this);
	setBackground(coulFond); 
	//placement des differents composants
	GridBagLayout gbl = new GridBagLayout();
	GridBagConstraints gbc = new GridBagConstraints(); 
 	setLayout(gbl);
	gbc.insets = new Insets(1,1,1,1);//defini les espaces entre les composants.
	gbc.gridx=0; gbc.gridy=0;     
        gbl.setConstraints(boutQuit,gbc);   
        add(boutQuit);  
	gbc.gridx=1;     
        gbl.setConstraints(boutMode,gbc);   
        add(boutMode);  
	gbc.gridx=2;     
        gbl.setConstraints(boutTick,gbc);   
        add(boutTick);  	
	reset_panel(false);
  }
    
} // PacemakerAction

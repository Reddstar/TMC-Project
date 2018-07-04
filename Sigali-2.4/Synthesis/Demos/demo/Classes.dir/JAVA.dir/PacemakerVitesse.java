import java.awt.*;
import java.awt.event.*;

/**
 * PacemakerVitesse.java
 * Gere la vitesse de la simulation interactivement.
 *
 * Created: Mon Aug  3 10:05:27 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class PacemakerVitesse extends Panel implements ActionListener{
    /** Codage de la couleur du fond */
    static final Color coulFond   = Color.blue;

    /** Codage de la couleur du fond du champ indiquant la vitesse*/
    static final Color coulFondVitesse = new Color(0,50,50);

    /** Codage de la couleur d'ecriture du champ indiquant la vitesse*/
    static final Color coulVitesse   = new Color(255,100,100);

    /** affiche la vitesse de la simulation*/
    public TextField champvitesse;

    /** valeur de la vitesse */
    public int vitesse = 1;

    /** pour augmenter graduellement la vitesse de simulation */
    public Bouton boutPlus;

    /** pour reduire graduellement la vitesse de simulation */
    public Bouton boutMoins;

    /** pour reduire la vitesse de simulation en la divisant par 2*/
    public Bouton boutDiv;

    /** pour augmenter la vitesse de simulation en la multipliant par 2*/
    public Bouton boutMult;

    /** ecrit un nombre dans champvitesse. 
     *  @param v nouvelle vitesse a afficher.
     */
    public synchronized void ecrit(int v){
	champvitesse.setText(String.valueOf(v));
	vitesse = v;
    }

    /** est charge de surveiller si l'utilisateur touche au boutons.
     *  @param evenement l'evenement declancheur
     */
    public synchronized void actionPerformed(ActionEvent evenement){
	String nomBouton = evenement.getActionCommand(); // nom du bouton presse
	if (nomBouton.equals(">")) {
	    Pacemaker.LP.inter_pace_up_p();
	}
	else if (nomBouton.equals("<")) { 
	    Pacemaker.LP.inter_pace_down_p();
	}
	else if (nomBouton.equals("<<")) { 
	    Pacemaker.LP.inter_pace_down_m();
	}
	else if (nomBouton.equals(">>")) { 
	    Pacemaker.LP.inter_pace_up_m();
	}
   }

    /** construction du panneau interactif. */
    public PacemakerVitesse() {
	champvitesse = new TextField(10);
	champvitesse.setEditable(false);
	champvitesse.setBackground(coulFondVitesse);
	champvitesse.setForeground(coulVitesse);
	boutPlus  = new Bouton(">"); boutPlus.addActionListener(this);	
	boutMoins = new Bouton("<"); boutMoins.addActionListener(this);	
	boutDiv   = new Bouton("<<"); boutDiv.addActionListener(this);	
 	boutMult  = new Bouton(">>"); boutMult.addActionListener(this);	
	setBackground(coulFond); 
	//placement des differents composants
	GridBagLayout gbl = new GridBagLayout();
	GridBagConstraints gbc = new GridBagConstraints(); 
 	setLayout(gbl);
	gbc.insets = new Insets(1,1,1,1);//defini les espaces entre les composants.
	gbc.gridx=0; gbc.gridy=0;     
        gbl.setConstraints(champvitesse,gbc);   
        add(champvitesse);  
	gbc.gridx=1;  
	gbl.setConstraints(boutDiv,gbc);   
        add(boutDiv);  	
 	gbc.gridx=2;     
	gbl.setConstraints(boutMoins,gbc);   
        add(boutMoins);  
	gbc.gridx=3;     
        gbl.setConstraints(boutPlus,gbc);   
        add(boutPlus);  
	gbc.gridx=4;    
 	gbl.setConstraints(boutMult,gbc);   
        add(boutMult);    }
    
} // PacemakerVitesse

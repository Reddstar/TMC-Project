import java.awt.*;
import java.awt.event.*;

/**
 * ModeResolv.java
 * Boite contenant des case a cochers.
 * Ces cases permettent de choisir les modes de fonctionnement
 * du resolveur.
 * Created: Thu Jul 23 10:59:22 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see InteResolv
 * @see vt
 */

public class ModesResolv extends Panel implements ItemListener{
    
    
    /** Codage de la couleur du fond du panel */
    static final Color coulFond   = Color.blue;

    /** Codage de la couleur du fond des cases a cochers */
    static final Color coulFondBox = Color.white;
    
    /** si a vrai alors on est en mode continu sinon on ne l'est pas */
    static boolean etat_continu = false;
    
    /** si a vrai alors les entrees controlables sont aleatoires sinon elles ne le sont pas*/
    static boolean alea_contr = false;

    /** si a vrai alors les entrees incontrolables sont aleatoires sinon elles ne le sont pas*/
    static boolean alea_incontr = false;

    /** case a cocher "Continu" */
    static Checkbox boxContinu = new Checkbox("Continous",etat_continu);

    /** case a cocher "Aleatoire" pour les entrees controlables  */
    static Checkbox boxAleaCont;

    /** case a cocher "Aleatoire" pour les entrees incontrolables  */
    static Checkbox boxAleaIncont;

    /** differents cas de configuration.
     *  3 cas possibles :
     *  <pre>
     *     1 : l'application ne comporte que des entrees controlables (des commandes);
     *     2 : l'application ne comporte que des entrees incontrolables (des mesures);
     *     3 : l'application comporte des entrees controlables et incontrolables;
     *  </pre>
     */
    static private int cas;

    /** initialise les composantes de la zone de boites a cocher. 
     *  @param cas les differents cas possibles.
     *  @see ModesResolv#cas
     */
    public ModesResolv(int cas) {
	this.cas = cas;
	if (cas==3) {
	    boxAleaCont = new Checkbox("Random Controls",etat_continu);
	    boxAleaIncont = new Checkbox("Random Events",etat_continu);
	} 
	else {
	    boxAleaCont = new Checkbox("Random",etat_continu);
	    boxAleaIncont = new Checkbox("Random",etat_continu);
	}
	
	setBackground(coulFond);
	GridBagLayout gbl = new GridBagLayout();
 	GridBagConstraints gbc = new GridBagConstraints(); 
	setLayout(gbl);	
	gbc.insets = new Insets(2,2,2,2);
       	gbc.fill = GridBagConstraints.BOTH;
	gbc.gridx=0; gbc.gridy=0;
        gbl.setConstraints(boxContinu,gbc);   
	boxContinu.setBackground(coulFondBox);
	add(boxContinu);	    
	boxContinu.addItemListener(this);
	switch (cas) {
	case 1: 
	    gbc.gridx=1; gbc.gridy=0;
	    gbl.setConstraints(boxAleaCont,gbc);   
	    boxAleaCont.setBackground(coulFondBox);
	    add(boxAleaCont);
	    boxAleaCont.addItemListener(this);
	    break;
	case 2: 
	    gbc.gridx=1; gbc.gridy=0;
	    gbl.setConstraints(boxAleaIncont,gbc);   
	    boxAleaIncont.setBackground(coulFondBox);
	    add(boxAleaIncont);
	    boxAleaIncont.addItemListener(this);
	    break;
	case 3:	   
	    gbc.gridx=0;gbc.gridy=1;
	    gbl.setConstraints(boxAleaCont,gbc);   
	    boxAleaCont.setBackground(coulFondBox);
	    add(boxAleaCont);	
	    boxAleaCont.addItemListener(this);
	    gbc.gridx=0;gbc.gridy=2;
	    gbl.setConstraints(boxAleaIncont,gbc);   
	    boxAleaIncont.setBackground(coulFondBox);
	    add(boxAleaIncont);
	    boxAleaIncont.addItemListener(this);
	    break;
	}
    }

    
    /** Verifie si on est en mode continu et si on est en mode aleatoire.
     *  Cette methode est appelee a chaque iteration par vt.java
     *  Si on est en mode continu on force le mode aleatoire du resolveur
     *  et le mode automatique du pacemaker.
     *  Si un mode aleatoire est active, la case correspondante doit etre cochee.
     */
    static synchronized void verif(){
 	if (etat_continu) {
 	    alea_contr=true;	
 	    boxAleaCont.setState(true); //on coche la boite correspondante 
 	    alea_incontr=true;
 	    boxAleaIncont.setState(true);
 	}
	if (alea_contr){boxAleaCont.setState(true);} 
	else boxAleaCont.setState(false);
	if (alea_incontr) {boxAleaIncont.setState(true);} 
	else boxAleaIncont.setState(false);
    }


   /** Procedure appelee une fois que l'utilisateur a clique sur le bouton
    *  "Aleatoires" (en mode non continu), c'est-a-dire qu'il laisse le choix au resolveur pour
    *  les entrees controlables ou incontrolables non encore selectionnees.
    *  @param is_e_contr si a vrai alors les entrees controlables sont aleatoires
    *                    sinon les entrees incontrolables sont aleatoires
    */
    static void traitement_alea(boolean is_e_contr){
	if (is_e_contr)
	    {
		InteResolv.LR.get_solution(InteResolv.tab_choix_U, ListEntrees.Cont.nbEntrees);
		InteResolv.fin_U = true;
		alea_contr = false; // on remet a faux car on n'est pas en mode continu.
		boxAleaCont.setState(false);
	    }
	else
	    {
		InteResolv.LR.get_solution(InteResolv.tab_choix_Y, ListEntrees.Incont.nbEntrees);
		InteResolv.fin_Y = true;
		alea_incontr = false; // on remet a faux car on n'est pas en mode continu.
		boxAleaIncont.setState(false);
	    }
    } 

   

    /** est charge de surveiller si l'utilisateur touche au cases a cocher
     *  et traites les variables concernees en concequence.
     *  @param evenement l'evenement declancheur
     */
    public synchronized void itemStateChanged(ItemEvent evenement){
	String selection =(String)evenement.getItem();
	if (selection=="Continous") {
	    etat_continu = boxContinu.getState();
	    if (etat_continu) {
		if ((cas==1 || cas==3) && alea_contr!=true){
		    boxAleaCont.setState(true);
		    alea_contr = true;
		}
		if ((cas==2 || cas==3) && alea_incontr!=true) {
		    boxAleaIncont.setState(true);
		    alea_incontr = true;
		}
	    }
	} 
	else
	    if ((selection=="Random" && cas==1) || selection=="Random Controls"){
		alea_contr = boxAleaCont.getState();
		if (!alea_contr && etat_continu) {
		    boxContinu.setState(false);
		    etat_continu = false;
		}
	    } 
	    else
		if ((selection=="Random" && cas==2) || selection=="Random Events"){
		    alea_incontr = boxAleaIncont.getState();
		    if (!alea_incontr && etat_continu) {
			boxContinu.setState(false);
			etat_continu = false;
		    }
		} 
   }
    
    
} // ModesResolv

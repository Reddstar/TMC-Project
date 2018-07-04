import java.awt.*;

/**
 * Pacemaker.java
 * permet de gerer interactivement le debut, la fin et le rythme 
 * de la simulation.
 *
 * Created: Mon Aug  3 09:40:38 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class Pacemaker extends Panel {
    
    /** permet de faire la liaison avec les parties ecrites en C++ */
    static LiaisonPacemaker LP = new LiaisonPacemaker();

    /** Codage de la couleur du fond du Pacemaker. */
    static final Color coulFond   = Color.blue;

    /** pour gerer la vitesse de la simulation interactivement. */
    static PacemakerVitesse paceV = new PacemakerVitesse();

    /** pour gerer le mode de fonctionnement interactivement. */
    static PacemakerAction paceA = new PacemakerAction();
    
    /** construction du Pacemaker. */
    public Pacemaker() {
	setBackground(coulFond);
	GridBagLayout gbl = new GridBagLayout(); 
	GridBagConstraints gbc = new GridBagConstraints(); 
	gbc.insets = new Insets(2,2,2,2);
	gbc.fill = GridBagConstraints.BOTH;
	setLayout(gbl);
	gbl.setConstraints(paceV,gbc); 
 	add(paceV);
	gbc.gridy=1;     
	gbl.setConstraints(paceA,gbc);   
	add(paceA);       
    }
    
} // Pacemaker

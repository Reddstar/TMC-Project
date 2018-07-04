import java.awt.*;
import java.awt.event.*;
import java.util.*;

/**
 * Entrees.java
 * <dt> Cette classe decrit les entrees du resolveur.
 * <dt>
 * Created: Wed Jul 15 15:47:07 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see ListEntrees
 * @see InteResolv
 */

public class Entrees extends Panel implements ActionListener{
    
    /** Cet objet est modifie dans InteResolv des que l'entree a change d'etat.
     *  Ce qui permet de creer des objets Observer (comme les Feux dans l'application vt) 
     *  qui reagissent en fonction des etats des entrees.
     *  @see Feux
     *  @see InteResolv
     */
    Temoin temoin = new Temoin();
   
    /** Codage de la couleur du fond des entrees */
    static final Color coulFond   = Color.blue;

    /** Codage de la couleur du texte du nom des entrees */
    static final Color coulTextLabel   = Color.red;

    /** Codage de la couleur du fond du nom des entrees */
    static final Color coulFondLabel   = Color.white;

    /** vrai si l'entree a ete cliquee et faux sinon */
    public boolean aEteCliquee = false;

    /** valeur de l'entree, c'est a dire true, false ou absent */    
    public int valCliquee;

    /** vrai si l'entree est controlable et faux sinon */
    public boolean isControlable; 

    /** nom de l'entree */
    public Label  label;

    public Bouton boutTrue;
    public Bouton boutFalse;
    public Bouton boutAbs;

    /** rang de l'entree dans sa liste */
    public int rang;

    /** est charge de surveiller si l'utilisateur touche au boutons True, False et Absent
     *  @param evenement l'evenement declancheur
     */
    public synchronized void actionPerformed(ActionEvent evenement){
      String nomBouton = evenement.getActionCommand(); // nom du bouton presse	
      InteResolv.noEntreeCliquee = ListEntrees.recherche_elem_list(this);
      if (nomBouton.equals("True")) { 
	  InteResolv.valeurEntreeCliquee = InteResolv.codeTrue;
	  InteResolv.changCoulUser(boutTrue);
      }
      else if (nomBouton.equals("False")) { 
	  InteResolv.valeurEntreeCliquee = InteResolv.codeFalse;
	  InteResolv.changCoulUser(boutFalse);
      }
      else {
	  InteResolv.valeurEntreeCliquee = InteResolv.codeAbs;
          InteResolv.changCoulUser(boutAbs);
      }
      InteResolv.resolver_interne(InteResolv.isEntreeCont);
    }

    /** Construction d'une entree.
     *  @param nom nom de l'entree.
     *  @param isCont si vrai alors l'entree est controlable
     *                sinon l'entree est incontrolable.
     */
    public Entrees(String nom, boolean isCont) {
        isControlable = isCont;
	label     = new Label(nom);
	label.setForeground(coulTextLabel);
	label.setBackground(coulFondLabel);
	boutTrue  = new Bouton("True"); boutTrue.addActionListener(this);
	boutFalse = new Bouton("False"); boutFalse.addActionListener(this);
	boutAbs   = new Bouton("Absent"); boutAbs.addActionListener(this);
        ListEntrees list;
        if (isControlable) {list=ListEntrees.Cont;} else list=ListEntrees.Incont;
        list.ajoutEnfin(this);
        rang=list.nbEntrees;

	setBackground(coulFond); 
        
	//placement des differents composants
	GridBagLayout gbl = new GridBagLayout();
	GridBagConstraints gbc = new GridBagConstraints(); 
 	setLayout(gbl);
	gbc.insets = new Insets(1,1,1,1);//defini les espaces entre les composants.
	gbc.gridx=0; gbc.gridy=0;     
        gbl.setConstraints(label,gbc);   
        add(label);  
	gbc.gridx=1;     
        gbl.setConstraints(boutTrue,gbc);   
        add(boutTrue);  
	gbc.gridx=2;     
        gbl.setConstraints(boutFalse,gbc);   
        add(boutFalse);  
	gbc.gridx=3;     
        gbl.setConstraints(boutAbs,gbc);   
        add(boutAbs);  	
    }
    
} // Entrees

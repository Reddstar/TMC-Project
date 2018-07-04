import java.awt.*;
import java.io.*;
import java.util.*;

/**
 * InteResolv.java
 * Interface du resolveur
 *
 *
 * Created: Thu Jul 16 11:43:24 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see LiaisonResolveur
 * @see Entrees
 * @see ListEntrees
 * @see ModesResolv
 * @see Bouton
 */

public class InteResolv {

    /** permet de gerer interactivement le debut, la fin et le rythme 
     *  de la simulation. 
     */
    static Pacemaker pacemaker = new Pacemaker();

    /** Codage de la valeur <strong>absent</strong> parmis 
     *  les  valeurs possibles pour les booleens. 
     */
    static final int codeAbs = 0;
    /** Codage de la valeur <strong>true</strong> parmis 
     *  les  valeurs possibles pour les booleens. 
     */
    static final int  codeTrue = 1;
    /** Codage de la valeur <strong>false</strong> parmis 
     *  les  valeurs possibles pour les booleens. 
     */
    static final int codeFalse = 2;

    /** permet de faire le lien avec la partie code en C++ par SIGNAL */
    static LiaisonResolveur LR = new LiaisonResolveur();

    static int nb_etat, nb_cond;

    static boolean fin_U, fin_Y,
	           premiere_fois, premier_ttick, premier_ttick1;
    
    /** permet de savoir si on est en train de gerer
     *  les entrees incontrolables ou les commandes.x
     */ 
    static boolean etat_contr;

    /** numero de la derniere entree cliquee par 
     *  l'utilisateur, c'est-a-dire son rang dans la liste 
     */
    static int noEntreeCliquee;

    /** tableau pour l'affichage des entrees U */
    static int tab_choix_U[]; 

    /** tableau pour l'affichage des entrees U */
    static int tab_choix_Y[]; 

    /** valeur de la derniere entree cliquee,
     * c'est-a-dire true, false ou absent. 
     */
    static int valeurEntreeCliquee; 
  
    /** vrai si la derniere entree cliquee est controlable
     *  et faux sinon.
     */
    static boolean isEntreeCont; 

    /** fenetre contenant les entrees controlables */
    static Fenetre fenCont;
    
    /** fenetre contenant les entrees incontrolables */
    static Fenetre fenIncont;

    /** zone de selection des modes (aleatoire, continu) */
    static ModesResolv modes;

    /** fenetre contenant la zone de selection des modes (aleatoire, continu) */
    static Fenetre fenModes;


    /** Change la couleur du fond de bouton lorsque l'utilisateur a clique
     *  dessus.
     *  @param bouton le bouton a repeindre.
     */
    static void changCoulUser(Bouton bouton){
	bouton.changCoulFond(Bouton.coulChoixUser);
    }

    /** Change la couleur du fond d'un bouton lorsque l'utilisateur a clique
     *  dessus ou lorsque le resolveur a choisi la valeur designee par ce bouton.
     *  @param bouton le bouton a repeindre.
     */
    static void changCoulResolv(Bouton bouton){
	bouton.changCoulFond(Bouton.coulChoixUser);
    }

    /** Remet la couleur d'un bouton a la couleur par default
     *  @param bouton le bouton a repeindre.
     */
    static void changCoulDefaut(Bouton bouton){
	bouton.changCoulFond(Bouton.coulFondDefault);
    }

    /** Remet les couleurs de tous les boutons associes aux entrees controlables 
     *  ou incontrolables a la valeur par default.
     *  @param isEntreeCont si vrai alors traite les entrees controlables sinon traite 
     *         les entrees incontrolables.
     */
    static void reInitCouleur(boolean isEntreeCont){
	ListEntrees list; Entrees e;
	if (isEntreeCont) {list = ListEntrees.Cont;} else list = ListEntrees.Incont;
        list.debut(); 
        while (!list.isEnFin()) { // parcours de list
	    e = list.eltCourant();
	    e.boutTrue.changCoulFond(Bouton.coulFondDefault);
	    e.boutFalse.changCoulFond(Bouton.coulFondDefault);
	    e.boutAbs.changCoulFond(Bouton.coulFondDefault);
	    list.avance();
	}
    }

    /** Affichage des choix possibles fournis a l'utilisateur pour les commandes
     *  @param choix :
     *  choix[nombre d'entrees controlables][3] :  choix[i][1] represente l'absence de l'entree i
     *  choix[i][2] represente la valeur a vrai de i
     *  choix[i][3] represente la valeur a faux de i
     *  Si choix[i][1] vaut 1 alors l'absence est autorisee (l'utilisateur 
     *  peut cliquer dessus, s'il vaut 0, l'absence est interdite et la touche
     *  est insensible.
     *  idem pour choix[i][2] et choix[i][3]
     */
    static void set_U(int choix[]) {
      Entrees entree;
      boolean boutActif, entreeIsContrainte;
      ListEntrees.Cont.debut(); 
      // parcours de la liste des entrees controlables
      for (int i = 0; i < ListEntrees.Cont.nbEntrees; i++) { 
	  entree = ListEntrees.Cont.eltCourant();

          if (choix[3*i] == 1) {changCoulResolv(entree.boutAbs);}
	  else changCoulDefaut(entree.boutAbs); 

          if (choix[3*i+1] == 1) {changCoulResolv(entree.boutTrue);}
	  else changCoulDefaut(entree.boutTrue); 

          if (choix[3*i+2] == 1) {changCoulResolv(entree.boutFalse);}
	  else changCoulDefaut(entree.boutFalse); 

	  entreeIsContrainte = ((choix[3*i]+choix[3*i+1]+choix[3*i+2]) == 1);
	  if (entreeIsContrainte) {
	      entree.boutAbs.setEnabled(false);
	      entree.boutTrue.setEnabled(false);
	      entree.boutFalse.setEnabled(false);	      
	  }
	  else {
	      boutActif = (choix[3*i] == 1); entree.boutAbs.setEnabled(boutActif);
	      boutActif = (choix[3*i+1] == 1); entree.boutTrue.setEnabled(boutActif);
	      boutActif = (choix[3*i+2] == 1); entree.boutFalse.setEnabled(boutActif);	      
	  }
	  entree.temoin.setChanged();      // indique au temoin un changement d'etat
	  entree.temoin.notifyObservers(); // signal aux observateurs du temoin (s'il y en a) de verifier l'etat du temoin.
	  ListEntrees.Cont.avance(); // passe a l'entree suivante de la liste
      }
   
    }

    
    /** Affichage des choix possibles fournis a l'utilisateur pour les entrees incontrolables.
     *  @param choix :
     *  choix[nombre d'entrees incontrolables][3] :  choix[i][1] represente l'absence de l'entree i
     *  choix[i][2] represente la valeur a vrai de i
     *  choix[i][3] represente la valeur a faux de i
     *  Si choix[i][1] vaut 1 alors l'absence est autorisee (l'utilisateur 
     *  peut cliquer dessus, s'il vaut 0, l'absence est interdite et la touche
     *  est insensible.
     *  idem pour choix[i][2] et choix[i][3]
     */
    static void set_Y(int choix[]) {
      Entrees entree;
      boolean boutActif, entreeIsContrainte;
      ListEntrees.Incont.debut(); 
      // parcours de la liste des entrees controlables
      for (int i = 0; i < ListEntrees.Incont.nbEntrees; i++) { 
	  entree = ListEntrees.Incont.eltCourant();

          if (choix[3*i] == 1) {changCoulResolv(entree.boutAbs);}
	  else changCoulDefaut(entree.boutAbs); 

          if (choix[3*i+1] == 1) {changCoulResolv(entree.boutTrue);}
	  else changCoulDefaut(entree.boutTrue); 

          if (choix[3*i+2] == 1) {changCoulResolv(entree.boutFalse);}
	  else changCoulDefaut(entree.boutFalse); 

	  entreeIsContrainte = ((choix[3*i]+choix[3*i+1]+choix[3*i+2]) == 1);
	  if (entreeIsContrainte) {
	      entree.boutAbs.setEnabled(false);
	      entree.boutTrue.setEnabled(false);
	      entree.boutFalse.setEnabled(false);
	      entree.aEteCliquee = true;
	      if (choix[3*i] == 1) {entree.valCliquee = codeAbs;}
	      else if (choix[3*i+1] == 1) {entree.valCliquee = codeTrue;}
	      else entree.valCliquee = -1;
	  }
          else {
	      boutActif = (choix[3*i] == 1); entree.boutAbs.setEnabled(boutActif);
	      boutActif = (choix[3*i+1] == 1); entree.boutTrue.setEnabled(boutActif);
	      boutActif = (choix[3*i+2] == 1); entree.boutFalse.setEnabled(boutActif);	      
	  }
	  entree.temoin.setChanged();      // indique au temoin un changement d'etat
	  entree.temoin.notifyObservers(); // signal aux observateurs du temoin (s'il y en a) de verifier l'etat du temoin.
	  ListEntrees.Incont.avance();
      }
    }

    /**  Fonction appelee a partir des call-back, c'est-a-dire des que 
     *	 l'utilisateur a clique sur une des entrees.
     *   @param is_e_contr l'utilisateur a clique sur une des entrees controlables si 
     *   is_e_entr est a vrai, incontrolables si ?is_e_entr est a faux).
     */
    static void resolver_interne(boolean is_e_contr){
	int i,j;
	LR.set_inconnue(noEntreeCliquee-1, valeurEntreeCliquee);
	if (is_e_contr)
	    {
		fin_U = LR.get_valperm(tab_choix_U, ListEntrees.Cont.nbEntrees);
		set_U(tab_choix_U);
	    }
	else
	    {
		fin_Y = LR.get_valperm(tab_choix_Y, ListEntrees.Incont.nbEntrees);
		set_Y(tab_choix_Y);
	    }
    }


    /** Constante utilisee pour differencier les differentes variables 
     *  du resolveur : etat, condition, mesure (ou entree incontrolable)
     *  sortie (ou entree controlable) dans le fichier "fich.sim".
     */
    static final int var_etat = 1;
    /** Constante utilisee pour differencier les differentes variables 
     *  du resolveur : etat, condition, mesure (ou entree incontrolable)
     *  sortie (ou entree controlable) dans le fichier "fich.sim".
     */
    static final int var_cond = 2;
    /** Constante utilisee pour differencier les differentes variables 
     *  du resolveur : etat, condition, mesure (ou entree incontrolable)
     *  sortie (ou entree controlable) dans le fichier "fich.sim".
     */
    static final int var_mesu = 3;
    /** Constante utilisee pour differencier les differentes variables 
     *  du resolveur : etat, condition, mesure (ou entree incontrolable)
     *  sortie (ou entree controlable) dans le fichier "fich.sim".
     */
    static final int var_sort = 4;
    /** Constante utilisee pour differencier les differentes variables 
     *  du resolveur : etat, condition, mesure (ou entree incontrolable)
     *  sortie (ou entree controlable) dans le fichier "fich.sim".
     */
    static final int var_config = 5;

    /**  Cette fonction lit le fichier fourni par sigali ".sim" pour
     *	 connaitre le nombre de variables (entrees, etats, conditions) et 
     *   le nom des entrees incontrolables ou controlables et cree les entrees.
     *	 Pour les entrees controlables (ou commandes ou U), on les prend
     *	 dans la deuxieme configuration.
     *   @param nomSim nom du fichier fourni par sigali.
     */
    static void recup_variables(String nomSim){
	boolean fini, premiere_config;
	String line;
	String nom_var="";
	char c = ' ';
	int index = 0;
	int longueur = 0;
	int val_automate = 0;
	Entrees entree;
	fini = false;
	premiere_config = true;
	nb_etat = 0;
	nb_cond = 0;
	File fich; //fichier "fich.sim" pour le resolveur.
	try {
	    fich = new File(".",nomSim);
	    if (! fich.exists() || ! fich.isFile()) 
		throw new IOException("Le fichier " + nomSim + " n'existe pas"); 
	    if (! fich.canRead()) 
		throw new IOException("Le fichier " + nomSim + " n'est pas lisible"); 
	    try {
		FileReader source = new FileReader(fich);
		BufferedReader flux = new BufferedReader(source);
		while(!fini){
		    try {line = flux.readLine();} 
		    catch(IOException ioe2) { System.out.println(ioe2.getMessage()); break;};
		    longueur=line.length();
		    line=line+" fin";
		    index=0;
		    c = line.charAt(index);
		    while (index<=longueur) {	
			if (c!=' ') {nom_var = nom_var+String.valueOf(c);} 
			else {
			    c=nom_var.charAt(0); 
			    if (c == '$'){
				c=nom_var.charAt(1);
				switch (c){ 
				case 'Y':
				    val_automate = var_mesu;
				    break;
				case 'E':
				    val_automate = var_etat;
				    break;
				case 'C':
				    val_automate = var_cond;
				    break;
				case 'R':
				    val_automate = var_config;
				    break;
				case 'O':
				    val_automate = var_sort;
				    break;
				case '$':
				    if (premiere_config)
					premiere_config = false;
				    else
					fini = true;
				}
			    }
			    else {
				switch (val_automate) {
				case var_mesu:
				    entree = new Entrees(nom_var,false);
				    break;
				case var_etat:
				    nb_etat++;
				    break;
				case var_cond:
				    nb_cond++;
				    break;
				case var_sort:
				    if (!premiere_config) entree = new Entrees(nom_var,true);
				    break;
				}
			    }
			    nom_var = "";
			}		
			index++;	
			c=line.charAt(index); 
		    }
		}
		source.close();	
	    } catch (Exception e) {System.out.println(e.getMessage());}
	}  catch (IOException ioe1) {System.out.println(ioe1.getMessage());}
    }

    /** Creation et affichage des fenetres contenant les entrees controlables
     *   et les entrees incontrolables utilisees par le resolveur.
     */
    static void creation_fen(){	
	// affichage de la fenetre de selection des modes (aleatoire et continu)
	int cas = 0;
	if (!ListEntrees.Cont.isVide()) cas = 1;
	if (!ListEntrees.Incont.isVide()) cas += 2;
	modes = new ModesResolv(cas);

	GridBagLayout gbl; GridBagConstraints gbc; 
	Entrees entree;
	// Creation de la fenetre contenant les entrees controlables s'il y en a
	if (!ListEntrees.Cont.isVide()) {
	    fenCont = new Fenetre("Control Panel");
	    fenCont.setBackground(Color.blue); 
	    gbl = new GridBagLayout(); gbc = new GridBagConstraints(); 
	    gbc.insets = new Insets(2,2,2,2);
	    gbc.fill = GridBagConstraints.BOTH;
	    fenCont.setLayout(gbl);
	    ListEntrees.Cont.debut();
	    while (!ListEntrees.Cont.isEnFin()) { // parcours de ListEntrees.Cont
		entree = ListEntrees.Cont.eltCourant();
		gbc.gridy++;
		gbl.setConstraints(entree,gbc); 
		fenCont.add(entree);
		ListEntrees.Cont.avance();
	    }
	    if (cas==1) { 
		/* on n'a que des commandes, on affiche la zone de selection des modes 
		   dans la fenetre fenCont*/
		gbc.gridy++;
		gbl.setConstraints(modes,gbc); 
		fenCont.add(modes);	
		gbc.gridy++;
		gbl.setConstraints(pacemaker,gbc); 
		fenCont.add(pacemaker);
	    }
	    fenCont.setLocation(600,0);
	    fenCont.pack();
	    fenCont.setVisible(true);   	  
	}
	// Creation de la fenetre contenant les entrees incontrolables s'il y en a
	if (!ListEntrees.Incont.isVide()) {
	    fenIncont = new Fenetre("Uncontrollable Panel");
	    fenIncont.setBackground(Color.green); 
	    gbl = new GridBagLayout(); gbc = new GridBagConstraints(); 
	    gbc.insets = new Insets(2,2,2,2);
	    gbc.fill = GridBagConstraints.BOTH;
	    fenIncont.setLayout(gbl);
	    ListEntrees.Incont.debut();
	    while (!ListEntrees.Incont.isEnFin()) { // parcours de ListEntrees.Incont
		entree = ListEntrees.Incont.eltCourant();
		gbc.gridy++;
		gbl.setConstraints(entree,gbc); 
		fenIncont.add(entree);
		ListEntrees.Incont.avance();
	    }

	    if (cas==2) { 
		/* on n'a que des mesures, on affiche la zone de selection des modes 
		   dans la fenetre fenIncont*/
		gbc.gridy++;
		gbl.setConstraints(modes,gbc); 
		fenIncont.add(modes);
		gbc.gridy++;
		gbl.setConstraints(pacemaker,gbc); 
		fenIncont.add(pacemaker);
	    }
	    fenIncont.setLocation(700,50);
	    fenIncont.pack();
	    fenIncont.setVisible(true);   	        
	}
	if (cas==3){
	    /* on a des commandes et des mesures, on affiche la zone de selection des modes 
		   dans la fenetre fenModes*/
	    fenModes = new Fenetre("Modes");
	    fenModes.setBackground(Color.green); 
	    gbl = new GridBagLayout(); gbc = new GridBagConstraints(); 
	    gbc.insets = new Insets(2,2,2,2);
	    gbc.fill = GridBagConstraints.BOTH;
	    fenModes.setLayout(gbl);
	    gbl.setConstraints(modes,gbc); 
	    fenModes.add(modes);
	    gbc.gridy=1;
	    gbl.setConstraints(pacemaker,gbc); 
	    fenModes.setLocation(600,500);
	    fenModes.add(pacemaker);
	    fenModes.pack();
	    fenModes.setVisible(true);   
	}
	

    }

    /** appelee par le programme Signal par l'intermediaire de la classe LiaisonBody.java
     *  @param cod_cond codage des conditions
     *  @param cod_x codage des etats
     *  @param fin_resolver a vrai quand le resolveur a donne une solution
     *                      unique pour cod_U et cod_Y
     *  @param !cod_u tableau contenant les nouvelles commandes.
     *  @param !cod_y tableau contenant les nouvelles entrees incontrolables.
     *  @see LiaisonBody
     */
    public void resolver(int cod_cond[], int cod_x[], int cod_u[],
			   int cod_y[], boolean fin_resolver[]){
	int i,j;
	if (etat_contr)   /* on s'occupe des commandes ou entrees controlables */
	    {
		if (premier_ttick)  /* 1ier traitement pour les commandes */
		    {
			LR.set_config(1);
			LR.init_resolution();
			reInitCouleur(true);
			if (ModesResolv.etat_continu)
			    {
				LR.get_solution(tab_choix_U, ListEntrees.Cont.nbEntrees);
				fin_U = true;
			    }
			else
			    if (ModesResolv.alea_contr)
				ModesResolv.traitement_alea(true);
			    else
				fin_U = LR.get_valperm(tab_choix_U,ListEntrees.Cont.nbEntrees);
			for (i = 0; i < ListEntrees.Cont.nbEntrees; i++)
			    cod_u[i] = tab_choix_U[3*i+1] - tab_choix_U[3*i+2];
			set_U(tab_choix_U);
			premier_ttick = false;
			premier_ttick1 = false;
		    }
		else               /* traitement suivant pour les commandes */
		    {
			if (ModesResolv.alea_contr)
			    {
				ModesResolv.traitement_alea(true);
				set_U(tab_choix_U);
			    }
			premier_ttick = premier_ttick1;
			if (premier_ttick1)
			    fin_U = false;
		    }
		fin_resolver[0] = fin_U;
		if (fin_U) /* c'est fini, on renvoie les donnees au programme Signal */
		    {
			premier_ttick1 = true;
			premiere_fois = true;
			etat_contr = false;
			for (i = 0; i <ListEntrees.Cont.nbEntrees; i++)
			    cod_u[i] = tab_choix_U[3*i+1] - tab_choix_U[3*i+2];
			for (i = 0; i <ListEntrees.Incont.nbEntrees; i++)
			    cod_y[i] = tab_choix_Y[3*i+1] - tab_choix_Y[3*i+2];
		    }
	    }
	else                    /* on s'occupe des entrees incontrolables */
	    {
		fin_resolver[0] = false;
		if (premiere_fois)  /* 1ier traitement pour les incontrolables */
		    {
			LR.raz();
			if (nb_etat != 0) 
			    LR.set_etats(cod_x, nb_etat);
			LR.set_config(0);
			LR.init_resolution(); 
			premiere_fois = false;
			reInitCouleur(false); 
			if (ModesResolv.etat_continu)
			    {
				LR.get_solution(tab_choix_Y,ListEntrees.Incont.nbEntrees);
				fin_Y = true;
			    }
			else
			    if (ModesResolv.alea_incontr)
				ModesResolv.traitement_alea(false);
			    else 
				fin_Y = LR.get_valperm(tab_choix_Y,ListEntrees.Incont.nbEntrees);
			set_Y(tab_choix_Y);
		    }
		else                /* traitements suivants pour les incontrolables */
		    {
			if (ModesResolv.alea_incontr)
			    {
				ModesResolv.traitement_alea(false);
				set_Y(tab_choix_Y);
			    }
		    }
		if (fin_Y)
		    {
			premier_ttick = true;
			fin_Y = false;
			etat_contr = true;
		    }
	    }
    }


    /** charge un fichier res et un fichier sim pour le resolveur 
     *  et initialise les variables "globales".
     *	@param nomSim nom du fichier sim
     *  @param nomRes nom du fichier res
     */
    public InteResolv(String nomSim, String nomRes) { 
	LR.chargement(nomRes);

        recup_variables(nomSim);        
	
	vt.LV.set_variables(nb_etat,nb_cond,ListEntrees.Cont.nbEntrees,ListEntrees.Incont.nbEntrees);

	creation_fen();

	tab_choix_U = new int[ListEntrees.Cont.nbEntrees*3];
        tab_choix_Y = new int[ListEntrees.Incont.nbEntrees*3];
	premier_ttick = true;
	premiere_fois = true;      
	etat_contr = false;	        
    }
    
} // InteResolv

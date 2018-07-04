/**
 * ListEntrees.java
 * Listes d'entrees dotes d'un etat de parcours
 *
 * Created: Wed Jul 15 15:53:26 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see Entrees
 * @see Maillon
 */

public class ListEntrees {
    
    /** permet d'identifier le debut de la liste. */
    private Maillon premier;

    /** permet d'identifier la fin de la liste. */
    private Maillon dernier;

    /** permet d'identifier le maillon courant dans un parcours de la liste. */
    private Maillon courant;

    /** nombre d'entrees de la liste */
    public int nbEntrees = 0;
    
    /** initialise la liste a vide */
    public ListEntrees() {
	premier=null; courant=null;
    }

    /** positionne le parcours en debut de liste */
    public void debut() {courant=premier;}

    /** fait avancer le parcours d'une position,
     *  ne fait rien si le parcours est en fin de liste
     */
    public void avance() {if (courant!=null) courant=courant.suivt;}

    /** indique que le parcours est en fin de liste (au dela du dernier).
     *  @return vrai si le parcours est en fin et faux sinon.
     */
    public boolean isEnFin() {return courant==null;}

    /** @return element courant du parcours, rend null si le parcours est
     *                  en fin de liste.	
     */
    public Entrees eltCourant(){
	if (courant!=null) {return courant.entree;} else return null;
    }
    
     
    /** ajoute elt en fin de liste	
     *  @param elt element ajoute en fin de liste
     */
    public void ajoutEnfin(Entrees elt){
	Maillon nouveau = new Maillon(elt,null);
	if (premier==null) {premier=nouveau;} else {dernier.suivt=nouveau;};
	dernier=nouveau;
        nbEntrees++;         
    }

    /** verifie si la liste est vide.
     *	@return vrai si la liste est vide et faux sinon
     */
    public boolean isVide(){
	return (nbEntrees==0);
    }


    /** liste d'entrees controlables */
    public static ListEntrees Cont = new ListEntrees();
   
    /** liste d'entrees incontrolables */
    public static ListEntrees Incont = new ListEntrees();

    /** appelee pour retrouver a quelle 
     *  entree appartient le  bouton sur lequel a clique l'utilisateur.
     *  Rend le rang dans la liste et met a jour le booleen qui permet de savoir
     *  s'il s'agit d'une entree controlable ou non.
     *  @param entree entree au quel appartient le bouton clique.
     *  @return le rang dans la liste.
     */
    static int recherche_elem_list(Entrees entree){
      InteResolv.isEntreeCont=entree.isControlable;	
      return entree.rang;
    }

    
} // ListEntrees

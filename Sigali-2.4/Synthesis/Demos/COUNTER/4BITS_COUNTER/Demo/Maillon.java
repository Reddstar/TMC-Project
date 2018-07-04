/**
 * Maillon.java
 * Defini un maillon d'une liste d'entrees
 *
 * Created: Wed Jul 15 17:02:41 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see Entrees
 * @see ListEntrees
 */

public class Maillon {

    /** entree associee au maillon. */
    public Entrees entree; 

    /** suivt est le maillon qui suit dans la liste. */
    public Maillon suivt;

    /** construction d'un maillon.
     *  @param e entree associee au maillon.
     *  @param s maillon qui suit dans la liste.
     */
    public Maillon(Entrees e, Maillon s) {
	entree=e; 
	suivt=s;
    }
    
} // Maillon

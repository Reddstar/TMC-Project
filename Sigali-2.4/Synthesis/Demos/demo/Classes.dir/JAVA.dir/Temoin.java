 import java.util.*;

/**
 * Temoin.java
 * Un objet Temoin est un objet observable par un objet Observer 
 * (exemple d'objets Observer: les Feux dans l'application vt).
 * On utilise cette classe pour savoir si le resolveur a changer l'etat des entrees.
 * Principe : 
 *  <pre>
 *    Chaque objet Entrees possede une instance de la classe Temoin.   
 *    Lorsque Signal demande a l'objet InteResolv d'afficher les Entrees,
 *    on indique au temoin de chaque objet Entrees qu'il y a eu un changement 
 *    (meme si il n'y en a pas). On utilise pour cela, la methode setChanged().
 *    Ensuite, avec la methode notifyObservers(), 
 *    on envoie un signal aux observateurs du temoin, 
 *    (dans l'application vt, c'est un objet Feux).
 *    A la reception d'un tel signal, l'observateur execute sa methode update().
 *    (Dans l'application vt, la methode update() de la classe Feux
 *    remet a jour l'etat d'un objet Feux en fonction de l'etat de l'entree correspondante.).
 *  </pre>
 *
 * Created: Tue Aug 18 16:24:39 1998
 *
 * @author Stephane Tudoret
 * @version
 * @see Entrees
 * @see Feux
 * @see InteResolv
 */

public class Temoin extends Observable{

    protected synchronized void setChanged(){
    }
   
    public synchronized boolean hasChanged(){
 	return true;
    }
    
} // Temoin

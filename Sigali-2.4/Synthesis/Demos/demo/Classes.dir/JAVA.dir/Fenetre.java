import java.awt.*;
import java.awt.event.*;

/**
 * Fenetre.java
 * Cette classe ajoute a la classe Frame
 * la possibilite de fermer l'application.
 * Created: 11 juin 1998
 *
 * @author Stephane Tudoret
 * @version
 */

public class Fenetre extends Frame implements WindowListener {   
     // Constructeurs :
  public Fenetre(String nom){ super(nom); addWindowListener(this);}
  public Fenetre(){ super(); addWindowListener(this);} 

     // Methode de fin :
  private  void quitter(){ System.exit(0);}  
 
     // Methodes de l'interface WindowListener :
  public void windowClosing(WindowEvent event) { quitter();}
  public void windowClosed(WindowEvent event) { }
  public void windowDeiconified(WindowEvent event) { }
  public void windowIconified(WindowEvent event) { }
  public void windowActivated(WindowEvent event) { }
  public void windowDeactivated(WindowEvent event) { }
  public void windowOpened(WindowEvent event) { } 
}
                   
 

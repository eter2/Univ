//  Circles.java
import javax.swing.JFrame;

public class Circles extends JFrame 
{
	public Circles() {
		super("Concentric Circles");	
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new CirclesJPanel());
		setSize(200, 250);
		setVisible(true);
	}
	
   public static void main(String args[])
   {
      new Circles();
   } // end main
} // end class Circles
// Requirement 1:  the title for the frame is 밅oncentric Circles�.  
// Requirement 2:  the size for the frame is 200 x 250.
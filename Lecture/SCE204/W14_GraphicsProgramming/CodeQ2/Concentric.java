//  Concentric.java
// This program draws concentric circles using Graphics2D
import javax.swing.JFrame;

public class Concentric extends JFrame 
{
	public Concentric() {
		super("Concentric Circles");	
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new CirclesJPanel());
		setSize(250, 250);
		setVisible(true);
	}
	
   public static void main(String args[])
   {
	   new Concentric();
   } 
} // end class Concentric


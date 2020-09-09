//  Circle.java
// Program calculates the area, circumference
// and diameter for a circle and draws the circle
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Circle extends JFrame
{
   public static void main(String args[])
   {
      String msg = JOptionPane.showInputDialog("Enter radius:");
      double inputRadius = Double.parseDouble(msg);
      
      msg = JOptionPane.showInputDialog("Enter x-coordinate:");
      int inputX = Integer.parseInt(msg);
      
      msg = JOptionPane.showInputDialog("Enter y-coordinate:");
      int inputY = Integer.parseInt(msg);
      
      CirclesJPanel p = new CirclesJPanel(inputRadius, inputX, inputY);

      new Circle(p);
   }
   
   public Circle(CirclesJPanel p) {
		super("Circle");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(p);
		setSize(300, 450);
		setVisible(true);
	}
} // end class Circle


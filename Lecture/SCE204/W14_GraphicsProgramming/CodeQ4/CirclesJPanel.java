 // CirclesJPanel.java
// Program calculates the area, circumference
// and diameter for a circle and draws the circle
import java.awt.geom.Ellipse2D;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JPanel;

public class CirclesJPanel extends JPanel
{
   private double radius;
   private int x;
   private int y;

   // constructor initialize applet by obtaining values from user
   public CirclesJPanel(double inputRadius, int inputX, int inputY)
   {
      radius = inputRadius;
      x = inputX;
      y = inputY;
   } 

   // draw results on applet's background
   public void paintComponent(Graphics g)
   {
      Graphics2D g2d = (Graphics2D) g;
        // to display string, do not use System.out.println();
      g.drawString(String.format(
         "Diameter is %f", (2 * radius)), 25, 30);
      g.drawString(String.format(
         "Area is %f", (Math.PI * radius * radius)), 25, 45);
      g.drawString(String.format(
         "Circumference is %f", (2 * Math.PI * radius)), 25, 60);
      
      g2d.draw(new Ellipse2D.Double(x, y, radius, radius));
   } 
} // end class CirclesJPanel



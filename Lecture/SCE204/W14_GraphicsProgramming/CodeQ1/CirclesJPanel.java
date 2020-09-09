//  CirclesJPanel.java
// This program draws concentric circles
import java.awt.Graphics;
import javax.swing.JPanel;

public class CirclesJPanel extends JPanel 
{
   // draw eight Circles separated by 10 pixels
   public void paintComponent(Graphics g)
   {
      super.paintComponent(g);

      // create 8 concentric circles
      for (int topLeft = 0; topLeft < 80; topLeft += 10)
      {
         int radius = 160 - (topLeft * 2);
         // read drawArc() method of Graphics class from java API
         g.drawArc(topLeft + 10, topLeft + 25, radius, radius, 0, 360);
      } 
   } 
} // end class CirclesJPanel


 

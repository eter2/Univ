
// Draw nested rectangles
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JPanel;

public class RectanglesPanel extends JPanel
{
	
	public void paintComponent(Graphics g)
	{
	 super.paintComponent(g);
	 Graphics2D g2d = (Graphics2D)g;
	 
	 int x=150, y=150; // coordinates of upper-left vertex of central rectangle
	 int width=50; int height=30;// width and height of central rectangle
	 
	   for(int i=1;i<=10;i++)
	  {
		   g2d.drawRect(x, y, width, height);
		   x -= 10;
		   y -= 10;
		   width += 20;
		   height += 20;
	  }
	
  }
}

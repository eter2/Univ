// ColorTest.java
// Class that uses a ColorChooser to pick the color to draw a square.
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.Color;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.ListSelectionEvent;

public class ColorTest extends JFrame 
{
   private JList<String> colorList;
   private ColorChooser chooser;
   private JPanel drawPanel;
   
   public ColorTest() 
   {
      super("List Test");

      setLayout(new GridLayout(2, 1));
      chooser = new ColorChooser();

      // create a list with items in colorNames array
      colorList = new JList<String>(chooser.getKeySet().toArray(new String[0]));
      colorList.setVisibleRowCount(5);
      colorList.setSelectedIndex(0);
      
      // do not allow multiple selections
      colorList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
      
      JPanel choosePanel = new JPanel();

      // add a JScrollPane containing JList to content pane
      choosePanel.add(new JScrollPane(colorList));

      // set up event handler
      colorList.addListSelectionListener(

         new ListSelectionListener() // anonymous inner class
         {
            // handle list selection events
            public void valueChanged(ListSelectionEvent event)
            {
               repaint();
            } 
         } 
     ); // end call to addListSelectionListener

      drawPanel = new JPanel(); // create a drawing panel
      drawPanel.setBackground(Color.WHITE);
      
      // add the panels to the window
      add(drawPanel);
      add(choosePanel);

      setSize(300, 300);
      setVisible(true);
   }

   public void paint(Graphics g) 
   {
      super.paint(g);
      
      // obtain the selected value
      Object selected = colorList.getSelectedValue();
      
      // set the color
      g.setColor(chooser.getColor((String)selected));
      
      // draw the rectangle
      Rectangle bounds = drawPanel.getVisibleRect();
      g.fillRect(bounds.x + 10, bounds.y + 30, bounds.width - 15, 
         bounds.height - 15);
   } 

   public static void main(String[] args) 
   {
      ColorTest application = new ColorTest();
      application.setDefaultCloseOperation(EXIT_ON_CLOSE);
   }
} // end class ColorTest


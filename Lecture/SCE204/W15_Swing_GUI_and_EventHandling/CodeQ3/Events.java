//  Events.java
// Program displays events that occur during execution.
import javax.swing.JFrame;

public class Events extends JFrame
{
   public static void main(String[] args)
   {
     EventsFrame ef = new EventsFrame();
     ef.setSize(375, 325);
     ef.setVisible(true);
     ef.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   } // end class Events
}

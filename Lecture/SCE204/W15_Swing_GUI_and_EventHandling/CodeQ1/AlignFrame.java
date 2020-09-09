//  AlignFrame.java
// Program creates a simple GUI.
import java.awt.GridLayout;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JCheckBox;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class AlignFrame extends JFrame 
{
        
   /* Step 0: Declare  all the necessary GUI componets here.
   ----------------------------------------------------   
    */
	
   // constructor sets up GUI
   public AlignFrame()
   {
	  super("Align");
	  setVisible(true);
	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
       // Sep 1.create two check boxes and store them in a panel_1 
      JPanel panel_1 = new JPanel();
      panel_1.setLayout(new GridLayout(2, 1, 0, 0));
      panel_1.add(new JCheckBox("Snap to Grid"));
      panel_1.add(new JCheckBox("Show Grid"));
      
      /*Step 2.1 Create text fieled and its label and store then in Panel_2
       -----------------------------------------------------------
       */
      JPanel panel_2 = new JPanel();
      panel_2.setLayout(new FlowLayout());
      panel_2.add(new JLabel("X: "));
      panel_2.add(new JTextField("8", 3));
      
      /*Step 2.2.Create text fieled and its label and store then in Panel_3
      -------------------------------------------------------
      */
      JPanel panel_3 = new JPanel();
      panel_3.setLayout(new FlowLayout());
      panel_3.add(new JLabel("Y: "));
      panel_3.add(new JTextField("8", 3));
      /* 2.3.Store  Panel_2  and Panel_3 inside panel_4
        by putting panel_2 at North and panel_3 at South.
        ------------------------------------------------------
     */
      JPanel panel_4 = new JPanel();
      panel_4.setLayout(new BorderLayout(0, 0));
      panel_4.add(panel_2, BorderLayout.NORTH);
      panel_4.add(panel_3, BorderLayout.SOUTH);
      
      /*Step 3. Creating three Buttons and store them  in panel_5
       -------------------------------------------------- 
       */
      JPanel panel_5 = new JPanel();
      panel_5.setLayout(new GridLayout(3, 1, 10, 5));
      panel_5.add(new JButton("Ok"));
      panel_5.add(new JButton("Cancel"));
      panel_5.add(new JButton("Help"));
      
      /* Step 4:Put Panel_1, panel_4 and panel_5 inside frame
       -----------------------------------------------
      */
      setLayout(new FlowLayout(FlowLayout.CENTER, 10, 5));
      add(panel_1);
      add(panel_4);
      add(panel_5);
      
      setSize(300, 140);
   } // end AlignFrame constructor
} // end class AlignFrame



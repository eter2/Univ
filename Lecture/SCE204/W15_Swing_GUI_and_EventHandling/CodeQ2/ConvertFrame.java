// ConvertFrame.java
// Temperature-conversion program
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class ConvertFrame extends JFrame
{
	/* Step 1: Declare necessary Fields( GUI elements) of  a frame 
    ----------------------------------------------------------
    */
	JFrame f = new JFrame();
	// constructor sets up GUI
   public ConvertFrame()
   {
      super("Temperature converter");
      f.setVisible(true);
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
      /* Step 2:  
      a) Cretae label with text string "Enter Fahrenheit temperature:"
      b) Create  textfield with size 10 to store value of temperature
      ------------------------------------------------ 
      */
      JTextField t = new JTextField(10);
      f.add(new JLabel("Enter Fahrenheit temperature:"), BorderLayout.NORTH);
      f.add(t, BorderLayout.CENTER);

      /* Step 3: register anonymous action listener
        a) inside  actionPerformed() method, do the convertion.
        b) in actionPerformed() method, "Temperature in Celsius" is included.
       --------------------------------------------------
       */
      JLabel cel = new JLabel("Temperature in Celsius is: ");
      f.add(cel, BorderLayout.SOUTH);
      t.addActionListener(new ActionListener() {
    	  public void actionPerformed(ActionEvent e) {
    		  String str = t.getText();
    		  double fa = Double.parseDouble(str);
    		  fa = (5 * (fa - 32.0)) / 9;
    		  cel.setText("Temperature in Celsius is: " + fa);
    	  }
      });

      /* Step 4: Add the Enter Fahrenheit temperure(Jlabel),
      blank textfiled(JTextField) and Temperature in Celsius(JTextFiled)
      at north, center and South location of BorderLayout Manager
     -----------------------------------------------------------
     */
      t.addKeyListener(new KeyListener() {
    	@Override
  		public void keyPressed(KeyEvent e) {
  			if(e.getKeyCode() == KeyEvent.VK_ENTER)
  		      f.add(cel, BorderLayout.SOUTH);
  		}
    	  
		@Override
		public void keyTyped(KeyEvent e) {
			
		}

		@Override
		public void keyReleased(KeyEvent e) {
			
		}
    	  
      });
      
      f.setSize(225, 90);
   } // end ConvertFrame constructor
} // end class ConvertFrame




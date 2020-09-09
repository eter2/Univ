import javax.swing.JFrame;


public class DrawRectangles extends JFrame
{
	public DrawRectangles() {
		super("Nested Rectangles");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new RectanglesPanel());
		setSize(400, 400);
		setVisible(true);
	}
	
	public static void main(String arg[])
	{
		new DrawRectangles();
	}

}

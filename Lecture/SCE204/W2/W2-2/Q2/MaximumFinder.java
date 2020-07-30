// Fig. 6.3: MaximumFinder.java
// Programmer-declared method maximum with three double parameters.
import java.util.Scanner;

public class MaximumFinder
{
	// obtain three floating-point values and locate the maximum value
	public static void main(String[] args)
	{
		// create Scanner for input from command window
		Scanner input = new Scanner(System.in);
		
		// prompt for and input three floating-point values
		System.out.print("Enter three floating-point values seperated by spaces: ");
		double number1 = input.nextDouble(); // read first double
		double number2 = input.nextDouble(); // read second double
		double number3 = input.nextDouble(); // read third double
		
		// determine the maximum value
		double maximum = maximum(number1, number2, number3);
		
		// determine the average value
		double average = average(number1, number2, number3);
		
		// display maximum value
		System.out.println("Maximum is " + maximum);
		
		// display average value
		System.out.printf("Average is %f", average);
	}
	
// returns the maximum of its three double parameters
	public static double maximum(double x, double y, double z)
	{
		double maximumValue = x; // assume x is the largest to star
	
		// determine whether y is greater than maximumValue
		if (y > maximumValue)
			maximumValue = y;
	
		// determine whether z is greater that maximumValue
		if (z > maximumValue)
			maximumValue = z;
	
		return maximumValue;
	}
	
	public static double average(double x, double y, double z)
	{
		return ( x + y + z ) / 3;
	}
}

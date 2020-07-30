// Fig. 6.10: MethodOverload.java
// Overloaded method declarations.

public class MethodOverload 
{
	// test overloaded square methods
	public static void main(String[] args)
	{
		System.out.printf("Square of integer 7 is %d%n", square(7));
		System.out.printf("Square of double 7.5 is %f%n", square(7.5));
		System.out.printf("Square of string 'hello' is %s%n", square("hello"));
	}
	
	// square method with int argument
	public static int square(int intValue)
	{
		System.out.printf("%nCalled square with int argument: %d%n", intValue);
		return intValue * intValue;
	}

	// square method with double argument
	public static double square(double doubleValue)
	{
		System.out.printf("%nCalled square with double argument: %f%n", doubleValue);
		return doubleValue * doubleValue;
	}
	
	public static String square(String stringValue)
	{
		System.out.printf("%nCalled square with string argument: %s%n", stringValue);
		return stringValue + stringValue;
	}
} // end class MethodOverload

//  MethodisEqualToTest.java
// Combined solution to entire problem
import java.util.Scanner;

public class MethodisEqualToTest
{
   public static void main(String[] args)
   {
      Scanner scanner = new Scanner(System.in);

      Integer a; // Integers used for
      Integer b; // testing equality

      // test if two Integers input by user are equal
      System.out.print("Enter two integer values: ");
      a = scanner.nextInt(); // get first integer
      b = scanner.nextInt(); // get second integer
      System.out.printf("%d and %d are %s\n", a, b, 
         (isEqualTo(a, b) ? "equal" : "not equal"));

      String c; // Strings used for
      String d; // testing equality

      // test if two Strings input by user are equal
      System.out.print("\nEnter two string values: ");
      c = scanner.next(); // get first String
      d = scanner.next(); // get second String
      System.out.printf("%s and %s are %s\n", c, d, 
         (isEqualTo(c, d) ? "equal" : "not equal"));

      Double e; // Double values used for
      Double f; // testing equality

      // test if two doubles input by user are equal
      System.out.print("\nEnter two double values: ");
      e = scanner.nextDouble(); // get first double
      f = scanner.nextDouble(); // get second double
      System.out.printf("%.1f and %.1f are %s\n", e, f, 
         (isEqualTo(e, f) ? "equal" : "not equal"));

      Object g = new Object(); // Object objects used
      Object h = new Object(); // for testing equality

      // test if two Object objects are equal
      System.out.printf("\n%s and %s are %s\n", g, h, 
         (isEqualTo(g, h) ? "equal" : "not equal"));
      
      scanner.close();
   } 

   // test whether two generic types are equal
   	private static <T> boolean isEqualTo(T a, T b) {
   		if (a.equals(b)) 
   			return true;
   		
   		return false;
   }
}
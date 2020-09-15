// GenericMethodTest.java
// Overloading generic methods.

public class GenericMethodTest 
{
   private static final Exception InvalidSubscriptException = null;

public static void main(String[] args) 
   {
      // create arrays of Integer, Double and Character
      Integer[] integerArray = {1, 2, 3, 4, 5};
      Double[] doubleArray = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
      Character[] characterArray = {'H', 'E', 'L', 'L', 'O'};

      test("integerArray", integerArray);
      test("doubleArray", doubleArray);
      test("characterArray", characterArray);
   } 

   // generic original printArray method
   private static <T> void printArray(T[] array) 
   {
	   for (T element: array)
		   System.out.printf("%s ", element);
		
	   System.out.println();
   }

   // overload generic method printArray
   private static <T> int printArray(T[] inputArray, int lowSubscript, int highSubscript) throws Exception
   {
      // check if subscript is negative or out of range
      if (lowSubscript < 0 || highSubscript >= inputArray.length) {
    	  String message = "Invalid subscript.";
    	  throw new InvalidSubscriptException(message);
      }

      int count = 0;

      // display array
      for (int i = lowSubscript; i <= highSubscript; i++) 
      {
         count++;
         System.out.printf("%s ", inputArray[i]);
      } // end for

      System.out.println();
      return count;  // number or elements output
   } 

   // generic method that tests both printArray methods
   public static <T> void test(String name, T[] array)// fill the blank spaces 
   {
      // print array
      try
      {
         int elements = 0; // store value returned by printArray

         // display array using original printArray method
         System.out.println("\n\nUsing original printArray method");
         printArray(array); // print array

         // display intAarray using overloaded  printArray method
         System.out.printf("Array %s contains:\n", name);
         elements = printArray(array, 0, array.length - 1);
         System.out.printf("%d elements were output\n", elements);

         // display elements 1-3 of array
         System.out.printf(
            "Array %s from positions 1 to 3 is:\n", name);
         elements = printArray(array, 1, 3);
         System.out.printf("%d elements were output\n", elements);

         // try to print an invalid element
         System.out.printf(
            "Array %s output with invalid subscripts:\n", name);
         elements = printArray(array, -1, 10);
      } 
      catch(Exception e)
      {
    	  System.out.println(e.getMessage());
      } 
   }
} // end class GenericMethodTest

//Indicates an invalid subscript.
class InvalidSubscriptException extends RuntimeException
{
   // no-argument constructor
  public InvalidSubscriptException()
  {
      this("Invalid subscript.");
  } 

// one-argument constructor
 public InvalidSubscriptException(String message)
 {
    super(message);
 } 

// two-argument constructor
  public InvalidSubscriptException(String message, Throwable cause)
  {
    super(message, cause);
  } 
} // end class EmptyStackException


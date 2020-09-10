// GenericMethodTest.java
// Overloading generic methods.

public class GenericMethodTest 
{
   public static void main(String[] args) 
   {
      // create arrays of Integer, Double and Character
      Integer[] integerArray = {1, 2, 3, 4, 5};
      Double[] doubleArray = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
      Character[] characterArray = {'H', 'E', 'L', 'L', 'O'};
      String[] stringArray = {"one", "two", "three", "four", 
         "five", "six", "seven", "eight"};

      System.out.println("Array integerArray contains:");
      printArray(integerArray); // call generic with an Integer array

      System.out.println("\nArray doubleArray contains:");
      printArray(doubleArray); // call generic with a Double array

      System.out.println("\nArray characterArray contains:");
      printArray(characterArray); // call generic with a Character array

      System.out.println("\nArray stringArray contains:");
      printArray(stringArray); // method specific to string arrays
   }
   
   // generic method printArray
   private static <T> void printArray(T[] array)// fill the blank spaces
   {
      // write code to display array elements
      for (T element : array)
    	  System.out.printf("%s ", element);
      
      System.out.println();
   } 

   // method that prints array of strings in tabular format
   private static void printArray(String[] stringArray)// fill the blank space
   {
      //  write code to display elements of array
     for(int i = 0; i < stringArray.length; i++) {
    	 System.out.printf("%s ", stringArray[i]);
    	 
    	 if ((i + 1) % 4 == 0) {
    		 System.out.println();
    	 }
     }
   } 
} // end class GenericMethodTest



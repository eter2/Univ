// ListTest.java
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ListTest 
{
   private static Scanner scanner = new Scanner(System.in);

   public static void main(String args[])
   {
      Set<String> names = new HashSet<String>();
      getNames(names); // get input from user
      searchNames(names); // search for names 
   }

   // get names
   public static void getNames(Set<String> names)
   {
      // get name from standard input
      System.out.println(
         "Add a name to set, use end to terminate input:");
      String inputName = scanner.next();

      // obtain input until end entered
      while (!inputName.equals("end"))
      {
          //  write code to insert new name by filling the blank lines. 
    	  
    	  if(!names.contains(inputName)) //name did not exists in list
          {
        	names.add(inputName);
            System.out.println(inputName + " inserted");
          }
          else  //name already exists in list
          {
        	System.out.println(inputName + " exists in set");
          }
            // get next name
         System.out.println(
            "Add a name to set, use end to terminate input:");
         inputName = scanner.next();
      } 
   } 
   // search names from list
   private static void searchNames(Set<String> names)
   {
      // get name from standard input
      System.out.println(
         "Search a name, use end to terminate searching:");
      String inputName = scanner.next();

      // obtain input until end entered
      while (!inputName.equals("end"))
      {
         // write code fill the blank space 

          if(names.contains(inputName)) // name found
          {
        	 System.out.println(inputName + " found in set");  
          }
          else // name not found
          {
        	System.out.println(inputName + " not found in set");  
          }  
         // get next search name
         System.out.println(
            "Search a name, use end to terminate searching:");
         inputName = scanner.next();
      }
   } 
} // end class ListTest


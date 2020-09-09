 // TreeTest.java
// Program tokenizes text input by user and places each
// token in a tree. Sorted tree elements are then printed.
import java.util.Scanner;
import java.util.TreeSet;
import java.util.StringTokenizer;

public class TreeTest 
{
   public static void main(String args[])
   {
      Scanner scanner = new Scanner(System.in); // create scanner

      System.out.println("Please enter a line of text:");
      String input = scanner.nextLine(); // get input text

      TreeSet<String> tree = new TreeSet<String>();
      StringTokenizer tokenizer = new StringTokenizer(input);
       // add text to tree by filling the folowing blank spaces
      /* Hint: StringTokenizer class has hasMoreTokens() and nextToken() methods.
         you can refer these methods from Java API(java.util.StringTokenizer).
       */
       
      while (tokenizer.hasMoreTokens())//  
      {
        tree.add(tokenizer.nextToken()); // add text to tree
      }

      // print tree elements after adding each token 
      System.out.println("Elements in tree: " + tree);
   } 
} // end class TreeTest



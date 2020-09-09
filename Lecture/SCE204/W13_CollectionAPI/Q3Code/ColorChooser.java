// ColorChooser.java
// Class that uses a HashMap to store color-nameand object pairs.
import java.awt.Color;
import java.util.HashMap;
import java.util.Set;

public class ColorChooser 
{
   private HashMap<String , Color> hashMap;
   
   public ColorChooser() 
   {
      hashMap = new HashMap<String, Color>();
      
      // add the 13 colors to the hashMap
      hashMap.put("black", Color.BLACK);
      hashMap.put("blue", Color.BLUE);
      hashMap.put("cyan", Color.CYAN);
      hashMap.put("darkGray", Color.DARK_GRAY);
      hashMap.put("gray", Color.GRAY);
      hashMap.put("green", Color.GREEN);
      hashMap.put("lightGray", Color.LIGHT_GRAY);
      hashMap.put("magenta", Color.MAGENTA);
      hashMap.put("orange", Color.ORANGE);
      hashMap.put("pink", Color.PINK);
      hashMap.put("red", Color.RED);
      hashMap.put("white", Color.WHITE);
      hashMap.put("yellow", Color.YELLOW);
   } 

   // return the selected color
   public Color getColor(String name) 
   {
      return hashMap.get(name);
   }

   // return all the color names
   public Set<String> getKeySet() 
   {
     return hashMap.keySet();
   }
} // end class ColorChooser

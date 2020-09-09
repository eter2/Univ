// SetOperations.java
import java.util.HashSet;
import java.util.Set;

public class SetOperations
{
  public static Set<String> union(Set<String> s1, Set<String> s2)
  {
	  Set<String> un=new HashSet<String>();
	  
	  un.addAll(s1);
	  un.addAll(s2);
	  
	  return un;
  }
  
  public static Set<String> intersection(Set<String> s1, Set<String> s2)
  {
	  Set<String> un=new HashSet<String>();
	  
	  un.addAll(s1);
	  un.retainAll(s2);
	  
	  return un;
  }
  
  public static Set<String> difference(Set<String> s1, Set<String> s2)
  {
	  Set<String> un=new HashSet<String>();
	  
	  un.addAll(s1);
	  un.removeAll(s2);
	  
	  return un;	
  }
 public static void main(String args[])
 {
	Set<String> footBallTeam=new HashSet<String>();
	footBallTeam.add("Frank");
	footBallTeam.add("Amjad");
	footBallTeam.add("Jim");
	
	Set<String> basketBallTeam=new HashSet<String>();
	basketBallTeam.add("David");
	basketBallTeam.add("Frank");
	basketBallTeam.add("Scott");
	
	Set<String> unionSet=union(footBallTeam,basketBallTeam);
	System.out.println("Union Set");
	for(String member:unionSet)
		System.out.println(member);
	System.out.println();
	
	Set<String> intersectionSet=intersection(footBallTeam,basketBallTeam);
	System.out.println("Intersection Set");
	for(String member:intersectionSet)
		System.out.println(member);
	System.out.println();
	
	Set<String> differenceSet=difference(footBallTeam,basketBallTeam);
	System.out.println("Difference Set");
	for(String member:differenceSet)
		System.out.println(member);
  }

}// end of the class 

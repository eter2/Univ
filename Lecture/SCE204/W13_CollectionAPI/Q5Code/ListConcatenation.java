import java.util.List;
import java.util.LinkedList;

public class ListConcatenation 
{
 public static LinkedList<String> listConcatenate(LinkedList<String> list1,LinkedList<String> list2)
  {
	 LinkedList<String> list=new LinkedList<String>();
	 
	 list.addAll(list1);
	 list.addAll(list2);
	 
	 return list;
  }
 public static void main(String arg[])
 {
	LinkedList<String> list1=new LinkedList<String>();
	
	list1.add("Java");
	list1.add("C++");
	
   LinkedList<String> list2=new LinkedList<String>();
	
	list1.add("Pascal");
	list1.add("Fortran");
	
	LinkedList<String> list3=listConcatenate(list1,list2);
	
	for (String s:list3)
		System.out.println(s);
	
	
 }
}

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.ListIterator;

public class ListTest
{
	public static void main(String[] args)
	{
		String[] colors =
			{"black", "yellow", "green", "blue", "violet", "silver"};
		List<String> list1 = new ArrayList<>(Arrays.asList(colors));
		
		String[] colors2 =
			{"gold", "white", "brown", "blue", "gray", "silver"};
		List<String> list2 = new ArrayList<>(Arrays.asList(colors2));
		
		list1.addAll(list2);
		list2 = null;
		printList(list1);
		
		convertToUppercaseStrings(list1);
		printList(list1);
		
		System.out.printf("%nDeleting elements 4 to 6...");;
		removeItems(list1, 4, 7);
		printList(list1);
		printReversedList(list1);
	}
	
	private static void printList(List<String> list)
	{
		System.out.printf("%nlist:%n");
		
		for (String color : list)
			System.out.printf("%s ", color);
		
		System.out.println();
	}
	
	private static void convertToUppercaseStrings(List<String> list)
	{
		ListIterator<String> iterator = list.listIterator();
		
		while (iterator.hasNext())
		{
			String color = iterator.next();
			iterator.set(color.toUpperCase());
		}
	}
	
	private static void removeItems(List<String> list, int start, int end)
	{
		list.subList(start, end).clear();
	}
	
	private static void printReversedList(List<String> list)
	{
		ListIterator<String> iterator = list.listIterator(list.size());
		
		System.out.printf("%nReversed List:%n");
		
		while(iterator.hasPrevious())
			System.out.printf("%s ", iterator.previous());
	}
}
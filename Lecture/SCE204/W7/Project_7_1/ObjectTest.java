import java.lang.reflect.Method;

public class ObjectTest 
{
	public static void main (String []args) throws Exception
	{
		int count = 0;
		Class c= Class.forName ("java.lang.Object");
		Method[] m = c.getDeclaredMethods();
		for( Method mi: m)
		{
			System.out.println(mi.getName());
			count++;
		}
		System.out.println("number of methods in Object class:" + count);
	}
}


public class EmployeeTest 
{
	public static void main(String[] args)
	{
		Date birth = new Date(7, 24, 1949);
		Date hire = new Date(3, 12, 1988);
		Employee employee = new Employee("Bob", "Blue", birth, hire);
		
		System.out.println(employee);
		
		Date b = new Date(7, 7, 1977);
		Date h = new Date(8, 8, 1988);
		
		Employee e2 = new Employee("kim", "lee", b, h);
		
		e2.SetBirthDate(9, 9, 1999);
		e2.SetHireDate(3, 3, 1993);
		
		System.out.println(e2);
	}
}


public class Employee 
{
	private String firstName;
	private String lastName;
	private final Date birthDate;
	private final Date hireDate;
	
	public Employee(String firstName, String lastName, Date birthDate, Date hireDate)
	{
		this.firstName = firstName;
		this.lastName = lastName;
		this.birthDate = birthDate;
		this.hireDate = hireDate;
	}
	
	void SetBirthDate(int date, int month, int year)
	{
		this.birthDate = new Date(date, month, year);
	}
	
	void SetHireDate(int date, int month, int year)
	{
		this.hireDate = new Date(date, month, year);
	}
	
	public String toString()
	{
		return String.format("%s, %s Hired: %s Birthday: %s", lastName, firstName, hireDate, birthDate);
	}
}

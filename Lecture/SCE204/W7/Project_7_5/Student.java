
class Student {
	String name;
	int ID;
	public Student (String name, int ID)
	{
		this.name = name;
		this.ID = ID;
	}
	

	
	public static void main (String[] args) {
		Student S1 = new Student("kim", 101);
		Student S2 = new Student("Homin", 102);
		Student S3 = new Student("Homin", 102);
		Student S4 = S1;
		System.out.println(S1.equals(S2));
		System.out.println(S1.equals(S3));
		System.out.println(S1.equals(S4));
		System.out.println(S1.equals("kim"));
		System.out.println(S1.equals(null));
	}
}

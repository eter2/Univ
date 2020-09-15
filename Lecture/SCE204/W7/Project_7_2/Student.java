// Student.java

public class Student {
	String name;
	int ID;
	
	public Student(String name, int ID) {
		this.name = name;
		this.ID = ID;
	}
	
//	public String toString() {
//		return "Student name:" + name + " and ID:" + ID;
//	}
	
	public static void main (String[] args) {
		Student S1 = new Student("kim", 101);
		Student S2 = new Student("Homin", 102);
		
		System.out.println(S1);
		System.out.println(S1.toString());
		System.out.println(S2);
	}
}

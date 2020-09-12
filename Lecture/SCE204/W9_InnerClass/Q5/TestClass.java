
class Outer {
	class Inner {
		public void M1() {
			System.out.println("inner class method is running");
		}
	}
}

class TestClass
{
	public static void main(String[] args)
	{
		Outer a = new Outer();
		Outer.Inner b = a.new Inner();
		b.M1();
	}
}

class Outer {
	class Inner
	{
		public void M1()
		{
			System.out.println("inner class method is running");
		}
	}
	
	public void M2()
	{
		Inner b = new Inner();
		b.M1();
	}
	
	public static void main(String[] args)
	{
		Outer a = new Outer();
		a.M2();
	}
}

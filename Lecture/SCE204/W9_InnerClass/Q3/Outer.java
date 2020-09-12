class Outer {
	class inner
	{
		public void M1()
		{
			System.out.println("inner class method is running");
		}
	}
	
	public static void main(String[] args)
	{
		Outer a = new Outer();
		inner b = a.new inner();
		b.M1();
	}
}

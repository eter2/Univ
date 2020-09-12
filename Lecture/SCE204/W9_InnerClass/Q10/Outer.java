class Outer {
	static class StaticInner
	{
		public void M1()
		{
			System.out.println("running a method of Static inner class");
		}
	}
	
	public static void main(String[] args)
	{
		StaticInner a = new StaticInner();
		a.M1();
	}
}

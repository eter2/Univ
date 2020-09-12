class Outer {
	static class StaticInner
	{
		public void M1()
		{
			System.out.println("running a method of Static inner class");
		}
	}
}

class TestOuter
{
	public static void main(String[] args)
	{
		Outer.StaticInner a = new Outer.StaticInner();
		a.M1();
	}
}

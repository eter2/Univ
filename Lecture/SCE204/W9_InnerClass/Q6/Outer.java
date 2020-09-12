class Outer {
	private int x = 10;
	private static int y = 20;
	class Inner
	{
		public void M1()
		{
			System.out.println(x);
			System.out.println(y);
		}
	}
	public static void main(String[] args)
	{
		Outer O = new Outer();
		Outer.Inner i = O.new Inner();
		i.M1();
	}
}

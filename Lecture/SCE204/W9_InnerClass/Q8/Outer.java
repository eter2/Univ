
class Outer {
	private int x = 10;
	private static int y = 20;
	public void M1()
	{
		int z = 30;
		class Inner
		{
			public void M2()
			{
				System.out.println("sum:"+(x+y+z));
			}
		}
		
		Inner i = new Inner();
		i.M2();
		i.M2();
		i.M2();
	}
	
	public static void main(String[] args)
	{
		Outer O = new Outer();
		O.M1();
	}
}

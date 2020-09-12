
class Outer {
	int x = 10;
	class Inner
	{
		int x = 20;
		public void M1()
		{
			int x = 30;
			System.out.println(x);
			System.out.println(this.x);
			System.out.println(Outer.this.x);
		}
	}
	
	public static void main(String[] args)
	{
		Outer a = new Outer();
		Inner b = a.new Inner();
		b.M1();
	}
}

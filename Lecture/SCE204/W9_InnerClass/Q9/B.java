class A {
	public void M1() {
		System.out.println("travel by plane");
	}
	
	public void M2()
	{
		System.out.println("Visit Historical Places");
	}
}

class B {
	public static void main(String[] args)
	{
		A a1 = new A()
		{
			public void M1()
			{
				System.out.println("travel by ship");
			}
		};
		
		a1.M1();
		A a2 = new A();
		a2.M1();
	}
}

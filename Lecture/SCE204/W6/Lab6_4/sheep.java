
public class sheep extends Animal
{	
	public sheep(String cry)
	{
		super(cry);
	}

	@Override
	public void cry() 
	{
		System.out.printf("sound of sheep: \"%s %s %s\"%n%n", cry, cry, cry);
	}
}

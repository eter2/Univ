
public class dog extends Animal
{
	public dog(String cry)
	{
		super(cry);
	}

	@Override
	public void cry() 
	{
		System.out.printf("sound of dog: \"%s %s %s\"%n", cry, cry, cry);
	}
}

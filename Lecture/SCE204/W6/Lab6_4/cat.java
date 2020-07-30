
public class cat extends Animal
{
	public cat(String cry)
	{
		super(cry);
	}

	@Override
	public void cry() 
	{
		System.out.printf("sound of cat: \"%s %s %s\"%n", cry, cry, cry);
	}
}

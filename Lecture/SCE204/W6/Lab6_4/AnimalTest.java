
public class AnimalTest 
{
	public static void main(String[] args)
	{
		dog dog = new dog("waw");
		cat cat = new cat("Miyaw");
		sheep sheep = new sheep("Ba");
		
		dog.cry();
		cat.cry();
		sheep.cry();
		
		Animal[] animals = new Animal[3];
		
		animals[0] = dog;
		animals[1] = cat;
		animals[2] = sheep;
		
		for (Animal currentAnimal : animals)
		{
			currentAnimal.cry();
		}
	}
}

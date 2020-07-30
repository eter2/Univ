import java.util.Scanner;

public class ProductManager {
	
	public static void main(String[] args) {
		
		Manager m = new Manager();

		Scanner scan = new Scanner(System.in);
		System.out.println("1. View the unit price");
		System.out.println("2. Add a purchasing product");
		System.out.println("3. Calculate the total price\n");
		
		int mode = 0, sum = 0;
		while (true) {
			System.out.print("Typing number to select menu: ");
			mode = scan.nextInt();
			
			if (mode == 1) {
				System.out.print("Scanning product identification number: ");
				int uid = scan.nextInt();
				Product p = m.getProduct(uid);
				System.out.println(p.getPrice());
				
			} else if (mode == 2) {
				System.out.print("Scanning product identification number: ");
				int uid = scan.nextInt();
				System.out.print("Typing quantity of the product: ");
				int quantity = scan.nextInt();
				
				Product p = m.getProduct(uid);
				int stock = p.getStock();
				if (stock < quantity)
					System.out.println("The product is out of stock");
				else {
					p.setStock(stock - quantity);
					sum += p.getPrice() * quantity;
				}
				
			} else if (mode == 3) {
				System.out.println("Total Price: " + sum);
				break;
			}
			
			System.out.println();
		}

		scan.close();
	}
}

// Fig. 3.9: AccountTest.java
// Inputting and outputting loating-point numbers with Account objects.
import java.util.Scanner;

public class AccountTest {
	public static void main(String[] args)
	{
		Account account1 = new Account("Jane Green", 50.00);
		Account account2 = new Account("John Blue", -7.53);
	
		// display initial balance of each object
		System.out.printf("%s balance: $%.2f%n", account1.getName(), account1.getBalance());
		System.out.printf("%s balance: $%.2f%n%n", account2.getName(), account2.getBalance());
		
		// create a Scanner to obtain input from the command window
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter deposit amount from account1 to account2: "); // prompt
		double depositAmount = input.nextDouble(); // obtain user input
		if (account1.transfer(account2, depositAmount))
			System.out.printf("%nadding %.2f to account2 balance%n%n", depositAmount);
		else
			System.out.printf("%nout of account1 balance%n%n");
		
		// display balances
		System.out.printf("%s balance: $%.2f%n", account1.getName(), account1.getBalance());
		System.out.printf("%s balance: $%.2f%n%n", account2.getName(), account2.getBalance());
		
		System.out.print("Enter deposit amount from account2 to account1: "); // prompt
		depositAmount = input.nextDouble(); // obtain user input
		if (account2.transfer(account1, depositAmount))
			System.out.printf("%nadding %.2f to account1 balance%n%n", depositAmount);
		else
			System.out.printf("%nout of account2 balance%n%n");
		
		System.out.printf("%s balance: $%.2f%n", account1.getName(), account1.getBalance());
		System.out.printf("%s balance: $%.2f%n%n", account2.getName(), account2.getBalance());
		
		input.close();
	} // end main
} // end class AccountTest

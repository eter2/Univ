
public class Transfer extends Transaction {
	private int amount; // amount to transfer
	private Keypad keypad;
	
	private final static int CANCELED = 6;
	
	public Transfer(int userAccountNumber, Screen atmScreen, BankDatabase atmBankDatabase, Keypad atmKeypad)
	{
		super(userAccountNumber, atmScreen, atmBankDatabase);
		
		keypad = atmKeypad;
	}
	
	@Override
	public void execute() {
		boolean success  = false;
		double availableBalance;
		
		BankDatabase bankDatabase = getBankDatabase();
		Screen screen = getScreen();
		
		do
		{
			amount = displayMenuOfAmounts();
			
			if (amount != CANCELED) {
				availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());
				
				if (amount <= availableBalance) {
					screen.displayMessageLine("\nPlease enter account number to transfer: ");
					int receiverAccountNumber = keypad.getInput();
					boolean isValid = bankDatabase.isValid(receiverAccountNumber);
					
					if (isValid) {
						screen.displayMessageLine("\nPlease confirm account number and amount.");
						screen.displayMessageLine("Account number: " + receiverAccountNumber + "\nAmount: " + amount);
						screen.displayMessageLine("\n1 - Go to next step");
						screen.displayMessageLine("2 - Cancel");
						screen.displayMessage("Enter a choice: ");
						int menuSelection = keypad.getInput();
						
						switch (menuSelection)
						{
							case 1:
								bankDatabase.Transfer(getAccountNumber(), receiverAccountNumber, amount);
								success = true;
								screen.displayMessageLine("\nTransfer success.");
								screen.displayMessageLine("Available balance: " + bankDatabase.getAvailableBalance(getAccountNumber()));
								screen.displayMessageLine("Total balance: " + bankDatabase.getTotalBalance(getAccountNumber()));
								break;
							case 2:
								screen.displayMessageLine("\nCanceling transaction...");
								return;
							default:
								screen.displayMessageLine("\nYou did not enter a valid selection. Try again.");
								break;
						}
					}
					else {
						screen.displayMessageLine("\nPlease check account number");
					}
				}
				else {
					screen.displayMessageLine("\nInsufficient funds in your account." + "\n\nPlease choose a smaller amount.");
				}
			}
			else
			{
				screen.displayMessageLine("\nCanceling transaction...");
				return;
			}
		} while (!success);
	}

	private int displayMenuOfAmounts() {
		int userChoice = 0;
		
		Screen screen = getScreen();
		
		int[] amounts = {0, 20, 40, 60, 100, 200};
		
		while (userChoice == 0) {
			screen.displayMessageLine("\nTransfer Menu:");
			screen.displayMessageLine("1 - $20");
	        screen.displayMessageLine("2 - $40");
	        screen.displayMessageLine("3 - $60");
	        screen.displayMessageLine("4 - $100");
	        screen.displayMessageLine("5 - $200");
	        screen.displayMessageLine("6 - Cancel transaction");
	        screen.displayMessage("\nChoose a transfer amount: ");
	        
	        int input = keypad.getInput();
	        
	        switch(input) {
	        	case 1:
	        	case 2:
	        	case 3:
	        	case 4:
	        	case 5:
	        		userChoice = amounts[input];
	        		break;
	        	case CANCELED:
	        		userChoice = CANCELED;
	        		break;
	        	default:
	        		screen.displayMessageLine("\nInvalid selection. Try again.");
	        }
		}
		
		return userChoice;
	}
}

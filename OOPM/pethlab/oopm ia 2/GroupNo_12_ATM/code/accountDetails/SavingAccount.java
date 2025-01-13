package accountDetails;

public class SavingAccount extends Account{
    final double MAX_AMOUNT;
    final int MAX_TRANSACTIONS;
    int transactionCount;
    String type = "saving";

    SavingAccount(int accNum, double balance, double maxAmount, int maxTransactions){
	super(accNum, balance);
	MAX_AMOUNT = maxAmount;
	MAX_TRANSACTIONS = maxTransactions;
    }

    public void withdraw(double amount){
	if(transactionCount >= MAX_TRANSACTIONS){
	    System.out.println("Reached maximum number of daily withdrawals. Can not withdraw any more for the day.");
	    return;
	}

	if(amount > MAX_AMOUNT){
	    System.out.println("Can not withdraw " + amount + ".Withdrawal Limit for account is set to " + MAX_AMOUNT);
	    return;
	}

	balance -= amount;
	transactionCount += 1;
	System.out.println(amount + " Withdrawn from account " + accountNumber);
    }
}


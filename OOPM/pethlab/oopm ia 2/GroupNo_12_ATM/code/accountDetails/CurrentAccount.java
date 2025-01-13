package accountDetails;

public class CurrentAccount extends Account{
    String type = "current";

    CurrentAccount(int accNum, double balance){
	super(accNum, balance);
    }

    public void withdraw(double amount){
	balance -= amount;
	System.out.println(amount + " Withdrawn from account " + accountNumber);
    }
}


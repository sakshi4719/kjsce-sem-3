package accountDetails;

public class Account{
    int accountNumber;
    double balance;

    Account(int accNum, double balance){
	accountNumber = accNum;
	this.balance = balance;
    }

    public void deposit(double amount){
	balance += amount;
	System.out.println(amount + " Deposited to account " + accountNumber);
    }

    public int getAccountNumber(){
	return accountNumber;
    }

    public double getBalance(){
	return balance;
    }
}


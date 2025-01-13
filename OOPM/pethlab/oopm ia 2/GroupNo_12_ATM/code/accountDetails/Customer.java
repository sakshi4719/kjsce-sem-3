package accountDetails;

public class Customer{
    public String name;
    public int cardNumber;
    private int pin;
    public CurrentAccount current;
    public SavingAccount saving;
    public String accountType;

    public Customer(String name, String accountType, int cardNumber, int pin, double balance){
	this.name = name;
	this.cardNumber = cardNumber;
	this.pin = pin;
	this.accountType = accountType;

	if(accountType.equals("current")){
	    current = new CurrentAccount(cardNumber, balance);
	    saving = null;
	}
	else{
	    saving = new SavingAccount(cardNumber, balance, 5000, 3);
	    current = null;
	}
    }

    public boolean verifyPin(int pin){
	return this.pin == pin;
    }
}


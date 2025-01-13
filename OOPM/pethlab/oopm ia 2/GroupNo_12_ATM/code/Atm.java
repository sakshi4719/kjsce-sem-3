import accountDetails.*;

import java.util.Scanner;
import java.util.Vector;

public class Atm{
    Vector<AtmTransaction> transactions = new Vector<AtmTransaction>(5,5);
    Vector<Customer> customerList = new Vector<Customer>(3);

    Atm(){
	customerList.add(new Customer("Peeth", "current", 1234, 1234, 25000.00));
	customerList.add(new Customer("Dhruv", "saving", 7890, 4567, 30000.00));
	customerList.add(new Customer("admin", "saving", 0000, 0000, 0));
    }
    
    class AtmTransaction{
	int transactionId;
	int cardNumber;
	String transactionType;
	double amount;

	AtmTransaction(int id, int cardNum, String type, double amount){
	    transactionId = id;
	    cardNumber = cardNum;
	    transactionType = type;
	    this.amount = amount;
	}

	void display(){
	    System.out.println("Transaction ID: " + transactionId);
	    System.out.println("Card Associated with Transaction: " + cardNumber);
	    System.out.println("Type of Transaction: " + transactionType);
	    System.out.println("Amount transacted: " + amount);
	}
    }
    
    void transact(Customer customer, Scanner sc){
	int option;
	while(true){
	    System.out.println("Enter Number to do the Associated Transaction:");
	    System.out.println("[1] Withdraw");
	    System.out.println("[2] Deposit");
	    option = sc.nextInt();
	    if(option == 1 || option == 2){
		break;
	    }
	    System.out.println("Enter a valid option.");
	}
	
	double amount;
	String transactionType;
	if(option == 1){
	    while(true){
		System.out.println("Enter Amount to Withdraw: ");
		amount = sc.nextDouble();
		if(amount < 0){
		    System.out.println("Amount can not be less than zero.");
		    continue;
		}
		break;
	    }
	    if(customer.accountType.equals("current"))
		customer.current.withdraw(amount);
	    else
		customer.saving.withdraw(amount);
	    transactionType = "Withdawal";
	}
	else{
	    while(true){
		System.out.println("Enter Amount to Withdraw: ");
		amount = sc.nextDouble();
		if(amount < 0){
		    System.out.println("Amount can not be less than zero.");
		    continue;
		}
		break;
	    }
	    if(customer.accountType.equals("current"))
		customer.current.deposit(amount);
	    else
		customer.saving.deposit(amount);
	    transactionType = "Deposit";
	}
	transactions.add(new AtmTransaction(transactions.size() + 1, customer.cardNumber, transactionType, amount));
    } 

    void viewBalance(Customer customer){
	int accountNum;
	String balance;
	if(customer.accountType.equals("current")){
	    accountNum = customer.current.getAccountNumber();
	    balance = String.format("%.02f", customer.current.getBalance());
	}
	else{
	    accountNum = customer.saving.getAccountNumber();
	    balance = String.format("%.02f", customer.saving.getBalance());
	}
	System.out.println("Balance in account " + accountNum + ": " + balance);
    }

    void listTransactions(){
	for(AtmTransaction transaction : transactions){
	    System.out.println();
	    transaction.display();
	    System.out.println();
	}
    }
    
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	Atm atm = new Atm();
	while(true){
	    System.out.println("\n---------------ATM---------------");
	    System.out.println("Enter Card Number: ");
	    int cardNum = sc.nextInt();
	    
	    int customerIndex = 0;

	    for(int i = 0; i < atm.customerList.size(); i++){
		if(cardNum == atm.customerList.get(i).cardNumber){
		    customerIndex = i;
		    break;
		}
	    }
	    
	    System.out.println("Enter PIN: ");
	    int pin = sc.nextInt();

	    if(atm.customerList.get(customerIndex).verifyPin(pin)){
		if(atm.customerList.get(customerIndex).name.equals("admin")){
		    atm.listTransactions();
		    System.out.println("Shutdown ATM [y/N]?");
		    String shutdown = sc.next();
		    if(shutdown.equals("y")){
			System.exit(0);
		    }
		}
		else{
		    boolean check = true;
		    while(check){
			System.out.println("Enter Number to do the Associated Action:");
			System.out.println("[1] Transact (Withdraw/Deposit)");
			System.out.println("[2] View Balance");
			String option = sc.next();
			switch(option){
			case "1":
			    atm.transact(atm.customerList.get(customerIndex), sc);
			    check = false;
			    break;
			case "2":
			    atm.viewBalance(atm.customerList.get(customerIndex));
			    check = false;
			    break;
			default:
			    System.out.println("Enter a valid option.");
			}
		    }
		}
	    }
	    else{
		System.out.println("Incorrect PIN. Exiting Session.");
	    }

	    System.out.println("---------------------------------\n");
	}
    }
}

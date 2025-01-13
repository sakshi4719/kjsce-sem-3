import java.util.*;

class account{
    Scanner sc = new Scanner();
    String name;
    int acc_id;
    float balance;

    account(String name, int acc_id, float balance){
	this.name = name;
	this.acc_id = acc_id;
	this.balance = balance;
    }

    void printer(){
	System.out.println(this.acc_id);
	System.out.println(this.name);
	System.out.println(this.balance);
    }

    void compare(int accoun){	
	name.equals(account.name);
    }
}

class arrOfObj{
    public static void main(String args[]){
	account accountArray[] = new account[4];

	for(int i = 0; i < accountArray.length; i++){
	    accountArray[i] = new account();
	}

	accountArray[0].name = "sak";
	accountArray[0].acc_id = 158;
	accountArray[0].balance = 15000.0;

	accountArray[1].name = "peth";
	accountArray[1].acc_id = 034;
	accountArray[1].balance = 16000.0;

	accountArray[2].name = "shrok";
	accountArray[2].acc_id = 144;
	accountArray[2].balance = 17000.0;

	accountArray[3].name = "sa";
	accountArray[3].acc_id = 100;
	accountArray[3].balance = 1000.0;

	boolean check = false;
	for (int i = 0; i <= 3; i++){
	    if(accountArray[i].name.equals(nameCheck))
	    {
		check = true;
		break;
	    }
	}

	if(check){
	    System.out.println(accountArray[i].acc_id);
	    System.out.println(accountArray[i].balance);	
	}
	else
	{
	    System.out.println("record doesnt exist");
	}
    }
}

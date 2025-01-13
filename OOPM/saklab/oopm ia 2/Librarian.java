import java.util.Scanner;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import library.*;

class MailFormatException extends Exception{
    public MailFormatException(String message){
	super(message);
    }

    public String toString(){
	return getMessage();
    }
}

public class Librarian{
    DataManager data = new DataManager();

    static boolean verifyMail(String email){
	// Regular Expression to check if mail is of valid format
	String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$"; 
        Pattern pat = Pattern.compile(emailRegex); 
        if (email == null) 
            return false; 
        return pat.matcher(email).matches();
    }

    static boolean verifyNum(String num){
	for (int i = 0; i < num.length(); i++){
	    if (Character.isDigit(num.charAt(i)) == false){
		return false;
	    }
	}
	return true;
    }

    void issueBook(Scanner sc){
	System.out.println("\nBook/E-Book Issue Processing");

	System.out.println("Enter name of book: ");
	String bookName = sc.nextLine();

	System.out.println("Enter name of book's author: ");
	String author = sc.nextLine();

	System.out.println("Enter the e-mail id of issuer: ");
	String mail;

	while(true){
	    try{
		mail = sc.nextLine();
		if(verifyMail(mail)){
		    break;
		}
		throw new MailFormatException("The Inputted E-Mail ID is of an invalid format.");
	    }
	    catch(MailFormatException e){
		System.out.println(e.toString());
		System.out.println("Enter a valid e-mail: ");
		continue;
	    }
	}

	if(data.searchDigitalCatalog(bookName, author)){
	    System.out.println("Access for " + bookName + " by " + author + "granted to " + mail);
	    return;
	}
	else{
	    int index = data.searchPhysicalCatalog(bookName, author);
	    if(index > -1){
		DataManager.Book issueBook = data.catalog.get(index);

		int num;
		while(true){
		    System.out.println("Enter the number of copies to be issued[must be >0]: ");
		    String copies = sc.nextLine();
		    
		    if(verifyNum(copies)){
			num = Integer.parseInt(copies);
			if(num > 0){
			    break;
			}
		    }
		    System.out.println("The input given is not valid. It must be a number more than zero");
		}

		if(issueBook.quantity < num){
		    System.out.println("Only " + issueBook.quantity + " of this book are available. Do you want to issue them all [y/N]?");
		    String choice = sc.nextLine();
		    if(choice.equals("y") == false)
			return;
		    num = issueBook.quantity;
		}

		System.out.println("Enter the name of the Issuer: ");
		String iname = sc.nextLine();

		System.out.println("Enter the Issuer's address: ");
		String iaddr = sc.nextLine();

		System.out.println("Enter the Form of Identification shown: ");
		String ikyc = sc.nextLine();

		data.issueList.add(data.new Issue(bookName, author, num, iname, mail, iaddr, ikyc));

		issueBook.quantity -= num;

		return;
	    }
	}
	
	System.out.println(bookName + " by " + author + " is unavailable.");
    }

    void returnBook(Scanner sc){
	System.out.println("Enter name of person returning the book: ");
	String rname = sc.nextLine();

	System.out.println("Following are the list of issues by people with the same name:");
	
	for (int i = 0; i < data.issueList.size(); i++){
	    if(rname.equals(data.issueList.get(i).issuerName)){
		System.out.println("\nIssue Number " + (i + 1));
		data.issueList.get(i).display();
	    }
	}
	
	int rnum;
	while(true){
	    System.out.println("Enter the associated Issue Number with the books being returned or 0 if no option matches: ");
	    String inum = sc.nextLine();
	    
	    if(verifyNum(inum)){
		rnum = Integer.parseInt(inum) - 1;
		break;
	    }
	    System.out.println("The input given is not valid.");
	}

	if(rnum > 0){
	    String bookName = data.issueList.get(rnum).name;
	    String author = data.issueList.get(rnum).author;
	    int index = data.searchPhysicalCatalog(bookName, author);
	    data.catalog.get(index).quantity += data.issueList.get(rnum).quantity;
	    data.issueList.removeElementAt(rnum);	    
	}
    }

    void addBook(Scanner sc){
	System.out.println("Enter the name of the book: ");
	String bookName = sc.nextLine();

	System.out.println("Enter the name of the author: ");
	String author = sc.nextLine();

	int quantity;
	while(true){
	    System.out.println("Enter the quantity: ");
	    String quan = sc.nextLine();
	    
	    if(verifyNum(quan)){
		quantity = Integer.parseInt(quan);
		if(quantity > 0){
		    break;
		}
	    }
	    System.out.println("The input given is not valid.");
	}

	int index = data.searchPhysicalCatalog(bookName, author);
	if(index > -1){
	    data.catalog.get(index).quantity += quantity;
	}
	else{
	    data.catalog.add(data.new Book(bookName, author, quantity));
	}

	System.out.println(quantity + " " + bookName + " by " + author + " added to the record.");	
    }

    void removeBook(Scanner sc){
	System.out.println("Enter the name of the book: ");
	String bookName = sc.nextLine();

	System.out.println("Enter the name of the author: ");
	String author = sc.nextLine();

	int quantity;
	int index = data.searchPhysicalCatalog(bookName, author);
	if(index > -1){
	    System.out.println("Quantity of " + bookName + " by " + author + " in records: " + data.catalog.get(index).quantity);
	    while(true){
		System.out.println("Enter quantity to remove from records[0-" +data.catalog.get(index).quantity + "]: ");
		String quan = sc.nextLine();
	    
		if(verifyNum(quan)){
		    quantity = Integer.parseInt(quan);
		    break;
		}
		System.out.println("The input given is not valid.");
	    }
	    data.catalog.get(index).quantity -= quantity;
	    System.out.println(quantity + " " + bookName + " by " + author + " removed from the record.");	
	}
	else{
	    System.out.println(bookName + " by " + author + " does not exist in records.");
	}
    }

    void addEbook(Scanner sc){
	System.out.println("Enter the name of the book: ");
	String bookName = sc.nextLine();

	System.out.println("Enter the name of the author: ");
	String author = sc.nextLine();

	if(data.searchDigitalCatalog(bookName, author)){
	    System.out.println(bookName + " by " + author + " already exists in the digital record.");
	}
	else{
	    System.out.println("Enter the File Size of the book in Mb");
	    float mb = sc.nextFloat();

	    data.digitalCatalog.add(data.new Ebook(bookName, author, mb));
	    System.out.println(bookName + " by " + author + " added to the digital record.");
	}
    }

    void removeEbook(Scanner sc){
	System.out.println("Enter the name of the book: ");
	String bookName = sc.nextLine();

	System.out.println("Enter the name of the author: ");
	String author = sc.nextLine();

	if(data.searchDigitalCatalog(bookName, author)){
	    for(int i = 0; i < data.digitalCatalog.size(); i++){
		if(bookName.equals(data.digitalCatalog.get(i).name) && author.equals(data.digitalCatalog.get(i).author)){
		    data.digitalCatalog.removeElementAt(i);
		    break;
		}
	    } 
	    System.out.println(bookName + " by " + author + " removed from the digital record.");	
	}
	else{
	    System.out.println(bookName + " by " + author + " does not exist in records.");
	}
	
    }

    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	Librarian lib = new Librarian();
	while(true){
	    System.out.println("Enter Associated Number to Execute that Action: ");
	    System.out.println("[1] Add Book to Catalog");
	    System.out.println("[2] Remove Book from Catalog");
	    System.out.println("[3] Add Book to Digital Catalog");
	    System.out.println("[4] Remove Book from Digital Catalog");
	    System.out.println("[5] Issue Book");
	    System.out.println("[6] Return Book");

	    String option = sc.nextLine();
	    
	    switch(option){
		case "1":
		    lib.addBook(sc);
		    break;
		case "2":
		    lib.removeBook(sc);
		    break;
		case "3":
		    lib.addEbook(sc);
		    break;
		case "4":
		    lib.removeEbook(sc);
		    break;
		case "5":
		    lib.issueBook(sc);
		    break;
		case "6":
		    lib.returnBook(sc);
		    break;
		default:
		    System.out.println("Enter a valid option");
	    }
	    System.out.println();
	}
    }
}

package library;

import java.util.Vector;

public class DataManager{
    public Vector<Book> catalog = new Vector<Book>(3, 2);
    public Vector<Ebook> digitalCatalog = new Vector<Ebook>(3, 2);
    public Vector<Issue> issueList = new Vector<Issue>(3, 2);

    public boolean searchDigitalCatalog(String book, String author){
	for(Ebook ebook : digitalCatalog){
	    if(book.equals(ebook.name) && author.equals(ebook.author)){
		String formattedFileSize = String.format("%.02f", ebook.fileSize);
		System.out.println(book + " by " + author + " [of size " + formattedFileSize + " Mb] is present in Digital Catalog.");
		return true;
	    }
	}
	return false;
    }

    public int searchPhysicalCatalog(String book, String author){
	for(int i = 0; i < catalog.size(); i++){
	    if(book.equals(catalog.get(i).name) && author.equals(catalog.get(i).author)){
		if(catalog.get(i).quantity > 1){
		    System.out.println(catalog.get(i).quantity + " copies of " + book + " by " + author + " is available in the Physical Catalog.");
		}
		else{
		    System.out.println("A copy of " + book + " by " + author + " is available in the Physical Catalog.");
		}
		return i;
	    }
	}
	return -1;
    }

    public class Book{
	public String name;
	public String author;
	public int quantity;

	public Book(String name, String author, int quantity){
	    this.name = name;
	    this.author = author;
	    this.quantity = quantity;
	}
    }

    public class Ebook extends Book{
	public float fileSize;

	public Ebook(String name, String author, float size){
	    super(name, author, 1);
	    fileSize = size;
	}
    }

    public class Issue extends Book{
	public String issuerName;
	public String issuerMail;
	public String issuerAddress;
	public String issuerIdentificationMethod;

	public Issue(String name, String author, int quantity, String iname, String imail, String iaddr, String ikyc){
	    super(name, author, quantity);
	    issuerName = iname;
	    issuerMail = imail;
	    issuerAddress = iaddr;
	    issuerIdentificationMethod = ikyc;
	}

	public void display(){
	    System.out.println("Details of the Issue of " + quantity + " " + name + " by " + author);
	    System.out.println("Issuer's Name: " + issuerName);
	    System.out.println("Issuer's E-mail id: " + issuerMail);
	    System.out.println("Issuer's Address: " + issuerAddress);
	    System.out.println("Method of Identification: " + issuerIdentificationMethod);
	    System.out.println();
	}
    }

}

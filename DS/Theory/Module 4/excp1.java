import java.util.*;

class NoMatchException extends Exception
{
NoMatchException(String abc)
{
super(abc);
}
}

class excp1
{
	public void match(String abc) throws NoMatchException
	{
	if (inp != "Computer")
	{throw new NoMatchException("User input is not Computer");}
	else
	{System.out.println("no exception");}
	}

	public static void main(String args[])
	{
	System.out.println("Enter the name of any electronic device");
	Scanner sc = new Scanner(System.in);
	String inp = sc.nextLine();

	try 
	{match(inp);} 
	catch (Exception e) 
	{System.out.println("caught");}
}
}



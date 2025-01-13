import java.util.*;

class ZeroException extends Exception
{
	public ZeroException(String str)
	{
	super(str);
	}
}

class TestException
{
	static void divide() throws ZeroException
	
	{
	Scanner sc = new Scanner(System.in);

	int a = sc.nextInt();
	int b = sc.nextInt();
	int c = sc.nextInt();
	int d = sc.nextInt();

	int denominator = (b*d);

	int result = ((a*b) + (b*c))/denominator;

		if (denominator == 0)
		{
			throw new ZeroException("/ by 0");
		}
		else
		{
			System.out.println(result);
		}
	}


	public static void main(String args[])
	{	
		try{divide();}

		catch(ZeroException ze)
			{System.out.println(ze);}

		System.out.println("rest of the code1");}
}

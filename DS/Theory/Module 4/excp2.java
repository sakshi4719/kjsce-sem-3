class InvalidAgeException extends Exception
{
	public InvalidAgeException(String str)
	{
	super(str);
	}
}

class TestCustomException
{
	static void validate (int age) throws InvalidAgeException
	{	
		if (age < 18)
		{
			throw new InvalidAgeException("age is not valid");
		}
		else
		{
			System.out.println("can vote");
		}
	}

	public static void main(String args[])
	{	
		try{validate(34);
		System.out.println("rest of the code");
		//not printed only if exception is there
		}


		catch(InvalidAgeException iae)
			{System.out.println(iae);}

		System.out.println("rest of the code1");}
}

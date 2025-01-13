import java.util.*;

class reverser{

	public static void main (String args[])
	{
	Scanner sc = new Scanner(System.in);
	int num = sc.nextInt();
	
	int i; 

	while(num>0)
	{
	i = num % 10 ;
	System.out.print(i);
	num = num / 10;
	}
	}
}



	



	
	

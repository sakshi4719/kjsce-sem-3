import java.util.*;
class sum
{
	public static void main (String args[])
	{
		Scanner sc = new Scanner(System.in);

		int no = 0;
		int sum = 0;
		System.out.println("enter int values except -999");

		while(true){
			no = sc.nextInt();
			if (no == -999)
				break;
			sum = sum + no;
			}
		System.out.println(sum);
	}
}


		

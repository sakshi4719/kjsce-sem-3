import java.util.Scanner;

class palindrome{

	public static void main(String args[])
	{
	Scanner sc = new Scanner(System.in);
	
	String pal = sc.nextLine();
	char ch[] = new char[pal.length()];
	
	for (int i = 0; i < pal.length(); i++) 
	{ch[i] = pal.charAt(i);}
	
	int j=0;
	if (ch[j] == ch[pal.length() - j-1])
	{System.out.println("PALINDROME");}
	else
	{System.out.println("NOT");}	
}
}


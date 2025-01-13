import java.io.*;
class Sample{
public static void main(String args[])throws Exception
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

System.out.println("Enter your name");
String name=br.readLine();
System.out.println("Welcome "+name);
System.out.println("Enter your number");
int n=Integer.parseInt(br.readLine());
System.out.println("Number is "+n);
}
}

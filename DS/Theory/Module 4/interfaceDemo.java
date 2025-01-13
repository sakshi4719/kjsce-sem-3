import java.util.*;

interface iface
{
	void areaTri();
	void areaSquare();
}

public class interfaceDemo implements iface
{
	Scanner sc = new Scanner(System.in);

	public void areaTri(){
		System.out.println("tri base and height");
		int base = sc.nextInt();
		int height = sc.nextInt();
		int area = base * height / 2;
		System.out.println(area);}

	public void areaSquare(){
		System.out.println("square");			
		int side = sc.nextInt();
		int area = side * side;
		System.out.println(area);}
		
	public static void main(String args[]){
	interfaceDemo i1 = new interfaceDemo();
	i1.areaTri();
	i1.areaSquare();}
}
	

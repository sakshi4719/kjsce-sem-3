import java.util.*;

abstract class abs
{
	abstract void areaTri();
	abstract void areaSquare();
	String printer(){
	String str = "this is how abs and iface are different";
	return str;}
}

public class absDemo extends abs
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
	absDemo i1 = new absDemo();
	i1.areaTri();
	i1.areaSquare();
	String a = i1.printer();
	System.out.println(a);
	}
}

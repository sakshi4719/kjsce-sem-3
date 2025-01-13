import java.util.*;

class overloading{

		static double pi = 3.14;

		int area(int length, int breadth){
		int areaR = length * breadth;
		System.out.println(areaR);
		return areaR;}

		double area(double radius){
		double areaC = pi * radius * radius;
		System.out.println(areaC);
		return areaC;}

		double area(double base, double height){
		double areaTri = base * height / 2;
		System.out.println(areaTri);
		return areaTri;}

	
	public static void main(String args[]){

		overloading triangle1 = new overloading();
		overloading rectangle1 = new overloading();
		overloading circle1 = new overloading();

		triangle1.area(10,20);
		rectangle1.area(15,40);
		circle1.area(10);
}
}


class Rectangle
{
	double length, breadth, area, perimeter;
	
	Rectangle (double length, double breadth)
	{
		this.length = length;
		this.breadth = breadth;
	}
	
	double area()
	{
		area = length * breadth;
		return area;
	}

	double perimeter()
	{
		perimeter = 2 * (length + breadth);
		return perimeter;
	}

	public static void main(String[] args) 
	{
		Rectangle R1 = new Rectangle(10,20);
		System.out.println("The area of the rectangle is" + R1.area());
		System.out.println("The perimeter of the rectangle is" + R1.perimeter());


	}
}

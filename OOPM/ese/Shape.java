import java.util.*;

class Shape
{

double dimension;
final double pi = 3.14;

    Shape(double dimension)
    {
	this.dimension = dimension;
    }

class Circle extends Shape
{   
    Circle(double circleRadius)
    {
    super(circleRadius);
    }

    double getCircleArea() {
    double circleArea = pi * Math.pow(dimension,2);
    return circleArea; }

    double getCircumference() {
    double Circumference = 2 * pi * dimension;
    return Circumference; }
}

class Square extends Shape
{
    Square(double sideLength)
    {
    super(sideLength);
    }

    double getSquareArea() {
    double squareArea = Math.pow(dimension,2);
    return squareArea; }

    double getDiagonalLength() {
    double diagonalLength = Math.pow(2,(1/2)) * dimension;
    return diagonalLength; }
}

class Sphere extends Shape
{
    this.dimension = sphereRadius;

    double getVolume() {
    double Volume = 4 / 3 * pi * Math.pow(dimension,3);
    return Volume; }

    double getSurfaceArea() {
    double surfaceArea = 4 * pi * Math.pow(dimension,2);
    return surfaceArea; }
    }
}

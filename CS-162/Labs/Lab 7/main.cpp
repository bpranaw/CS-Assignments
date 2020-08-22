#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include <iostream>

using namespace std;

int main()
{

	cout << endl << "Lab 6 Component" << endl << endl;
	Shape shape;
	
	shape.set_name("bob");

	cout << "Shape's name: " << shape.get_name() << endl;

	Rectangle rectangle;

	rectangle.set_width(20);

	rectangle.set_height(20);

	Rectangle rectangle2;

	rectangle2.set_width(50);

	rectangle2.set_height(50);

	rectangle.set_name("rectangle");
	
	cout << "Rectangle's name: " << rectangle.get_name() << endl;

	cout << "Rectangle's area: " << rectangle.area() << endl;

	cout << "Rectangle 2's area: " << rectangle2.area() << endl;
	
	Circle circle;

	circle.set_name("circle");

	circle.set_radius(1000);

	cout << "Circle's name: " << circle.get_name() << endl;

	cout << "Circle's area: " << circle.area() << endl;

	Square square(12);

	square.set_name("square");

	cout << "Square's name: " << square.get_name() << endl;
	
	cout << "Square's area: " << square.area() << endl << endl;

	cout << "**********************************************************" << endl;

	cout << endl << "Lab 7 - Operator Overload" << endl;
	
	cout << "Is rectangle greater than rectangle2?\nThe Answer: " << endl;
	if(rectangle > rectangle2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}


	cout << "Is rectangle less than rectangle2?\nThe Answer: " << endl;
	if(rectangle < rectangle2)
	{
		cout << "Yes" << endl << endl;
	}
	else
	{
		cout << "No" << endl << endl;
	}
	

	cout << "**********************************************************" << endl;

	cout << endl << "Lab 7 - Polymorphism" << endl;

	cout << endl << "Rectangle's Info:" << endl;

	rectangle.print_shape_info(rectangle);

	cout << endl << "Circle's Info:" << endl;

	circle.print_shape_info(circle);
	
	cout << endl << "Square's Info:" << endl;

	square.print_shape_info(square);

	cout << endl;
}

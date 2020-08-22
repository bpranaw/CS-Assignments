#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include <iostream>

using namespace std;

int main()
{
	Shape shape;
	
	shape.set_name("bob");

	cout << "Shape's name: " << shape.get_name() << endl;

	Rectangle rectangle;

	rectangle.set_width(20);

	rectangle.set_height(20);

	cout << "Rectangle's area: " << rectangle.area() << endl;

	Circle circle;

	circle.set_radius(1000);

	cout << "Circle's area: " << circle.area() << endl;

	Square square(12);

	cout << "Square's area: " << square.area() << endl;
}

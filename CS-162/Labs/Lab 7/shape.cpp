#include "shape.h"

using namespace std;

Shape::Shape()
{
	this->name = "shape";
	this->color = "red";
}

Shape::Shape(const Shape & previous_shape)
{
	this->name = previous_shape.name;
	this->color = previous_shape.color;
}

Shape & Shape::operator = (const Shape & previous_shape)
{
	this->name = previous_shape.name;
	this->color = previous_shape.color;
}

Shape::~Shape()
{
	//Destructor
}

const float Shape::area()
{
	return 0;
}

void Shape::set_name(const string name)
{
	this->name = name;	
	return;
}

const string Shape::get_name()
{
	return this->name;	
}

void  Shape::set_color(const string color)
{
	this->color = color;
	return;
}

const string Shape::get_color()
{
	return this->color;
}


bool operator > (Shape& first_shape, Shape & second_shape)
{
	return (first_shape.area() > second_shape.area());
}

bool operator < (Shape& first_shape, Shape & second_shape)
{
	return (first_shape.area() < second_shape.area());
}


void Shape::print_shape_info(Shape & shape)
{
	std::cout << shape.get_name() << std::endl;
	std::cout << shape.get_color() << std::endl;
	std::cout << shape.area() << std::endl;		
}





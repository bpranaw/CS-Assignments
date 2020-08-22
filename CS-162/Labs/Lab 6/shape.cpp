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

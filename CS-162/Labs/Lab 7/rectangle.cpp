#include "rectangle.h"

Rectangle::Rectangle()
{
	this->width = 1.0;
	this->height = 1.0;
}
	
Rectangle::Rectangle(const Rectangle & previous_rectangle)
{
	this->width = previous_rectangle.width;
	this->height = previous_rectangle.height;
}

Rectangle & Rectangle::operator = (const Rectangle & previous_rectangle)
{
	this->width = previous_rectangle.width;
	this->height = previous_rectangle.height;
}

Rectangle::~Rectangle()
{
	//Destructor
}

		
const float Rectangle::area()
{
	float area = 1.0;
	
	area = get_width() * get_height();	

	return area;
}

void Rectangle::set_width(const float width)
{
	this->width = width;
	return;
}

const float Rectangle::get_width()
{
	return this->width;
}

void Rectangle::set_height(const float height)
{
	this->height = height;
}

const float Rectangle::get_height()
{
	return this->height;
}

/*
bool Rectangle::operator > (Rectangle & old_rectangle)
{
	return this->area() > old_rectangle.area();
}

bool Rectangle::operator < (Rectangle & old_rectangle)
{
	return this->area() < old_rectangle.area();
}
*/


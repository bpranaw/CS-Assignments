#include "circle.h"

Circle::Circle()
{
	this->radius = 1;
}

Circle::Circle(const Circle & previous_circle)
{
	this->radius = previous_circle.radius;
}

Circle & Circle::operator = (const Circle & previous_circle)
{
	this->radius = previous_circle.radius;
}

Circle::~Circle()
{
	//Destructor
}

const float Circle::area()
{
	return get_radius() * 3.1415926;
}

void Circle::set_radius(const float radius)
{
	this->radius = radius;
	return;
}

const float Circle::get_radius()
{
	return this->radius;
}


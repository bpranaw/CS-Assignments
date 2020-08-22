#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape
{
	private:
		float width;
		float height;

	public:
		Rectangle();
	
		Rectangle(const Rectangle &);

		Rectangle & operator = (const Rectangle &);

		~Rectangle();
		
		const float area();

		void set_width(const float);
		const float get_width();

		void set_height(const float);
		const float get_height(); 

	/*
		bool operator > (Rectangle &);

		bool operator < (Rectangle &);
	*/
};

#endif

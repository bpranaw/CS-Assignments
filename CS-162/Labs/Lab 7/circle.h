#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"


class Circle: public Shape
{
	private:
		float radius;
	public:
		Circle();

		Circle(const Circle &);

		Circle & operator = (const Circle &);

		~Circle();

		const float area();

		void set_radius(const float);
		const float get_radius();

};

#endif

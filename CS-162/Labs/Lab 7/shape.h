#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>


class Shape
{
	protected:
		std::string name;
		std::string color;

	public:

		Shape();

		Shape(const Shape &);

		Shape & operator = (const Shape &);

		~Shape(); 

		virtual const float area();

		void set_name(const std::string);
		const std::string get_name();

		void set_color(const std::string);
		const std::string get_color();

		friend bool operator > (Shape&, Shape &);

		friend bool operator < (Shape&, Shape &);
		
		void print_shape_info(Shape &);

};


#endif

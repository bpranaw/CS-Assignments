#ifndef OTTER_H
#define OTTER_H

#include "animal.h"

class Otter : public Animal
{
	public:
		//-Default Constructor-Copy Constructor-Assignment Opterator Overload-Destructor-
		Otter();
	
		Otter(Otter &);

		Otter & operator = (Otter &);

		~Otter();
};

#endif

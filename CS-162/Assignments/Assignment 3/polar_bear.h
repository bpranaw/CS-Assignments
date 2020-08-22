#ifndef POLAR_BEAR_H
#define POLAR_BEAR_H

#include "animal.h"

class Polar_Bear : public Animal
{
	public:
		//-Default Constructor-Copy Constructor-Assignment Opterator Overload-Destructor-
		Polar_Bear();
	
		Polar_Bear(Polar_Bear &);

		Polar_Bear & operator = (Polar_Bear &);

		~Polar_Bear();
};

#endif

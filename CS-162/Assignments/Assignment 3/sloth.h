#ifndef SLOTH_H
#define SLOTH_H

#include "animal.h"

class Sloth : public Animal
{
	public:
		//-Default Constructor-Copy Constructor-Assignment Opterator Overload-Destructor-
		Sloth();
	
		Sloth(Sloth &);

		Sloth & operator = (Sloth &);

		~Sloth();
};

#endif

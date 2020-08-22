#ifndef MONKEY_H
#define MONKEY_H

#include "animal.h"

class Monkey : public Animal
{
	public:
		//-Default Constructor-Copy Constructor-Assignment Opterator Overload-Destructor-
		Monkey();
	
		Monkey(Monkey &);

		Monkey & operator = (Monkey &);

		~Monkey();
};

#endif

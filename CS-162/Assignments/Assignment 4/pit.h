#ifndef PIT_H
#define PIT_H

#include "event.h" 

class Pit : public Event
{
	public:	
		
		Pit();

		bool encounter();

		void precept();

		string get_name();

}; 

#endif

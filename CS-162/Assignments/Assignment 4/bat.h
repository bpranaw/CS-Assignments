#ifndef BAT_H
#define BAT_H

#include "event.h" 

class Bat : public Event
{
	public:		
		
		Bat();

		bool encounter();

		void precept();

		string get_name(); 
};

#endif

#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

class Wumpus : public Event
{
	public:
				
		Wumpus();

		bool encounter();

		void precept();

		string get_name(); 
	

};

#endif

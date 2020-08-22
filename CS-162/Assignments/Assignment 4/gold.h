#ifndef GOLD_H
#define GOLD_H

#include "event.h"

class Gold : public Event
{
	public:		
		
		Gold();

		bool encounter();

		void precept();

		string get_name(); 
};

#endif

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;

using std::string;

class Event
{
	protected:
		string name;

	public:
	
		virtual bool encounter() = 0;
	
		virtual void precept() = 0;

		virtual string get_name() = 0;


};

#endif

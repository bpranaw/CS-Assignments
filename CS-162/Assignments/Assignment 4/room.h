#ifndef ROOM_H
#define ROOM_H

#include "event.h" 
#include "wumpus.h"
#include "pit.h"
#include "bat.h"
#include "gold.h"

class Room
{
	private:
		Event* room_event;

		bool has_wumpus;
		bool has_pit;
		bool has_bat;
		bool has_gold;

		bool has_player;
		bool is_start_room;


	public:
		
		Room();

		Room(const Room &);
		
		Room & operator = (const Room &);
		
		~Room();
		
		void set_room_event(int);
		Event* get_room_event();

		void set_has_wumpus(bool);
		bool get_has_wumpus();

		void set_has_pit(bool);
		bool get_has_pit();

		void set_has_bat(bool);
		bool get_has_bat();

		void set_has_gold(bool);
		bool get_has_gold();
		
		void set_has_player(bool);
		bool get_has_player();
	
		void set_is_start_room(bool);
		bool get_is_start_room();
		
		bool is_wumpus_dead();
};

#endif

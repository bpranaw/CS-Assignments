#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "event.h" 
#include "room.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Gameplay
{
	private:
		int start_room;
	
		int dimensions;
		bool is_debug;

		int direction;
		
		bool has_died;
		int player_arrows;
		int player_location;

		bool is_wumpus_dead;
		bool has_gold;
	
		int wumpus_room;

		Room* map;
		Room* map_spare;

	public:

		Gameplay(int,bool);
		
		~Gameplay();

		void view_map();

		bool player_turn();

		bool play_game();

		void create_random_map();					

		void move_player(int);	

		int check_precept();
	
		bool check_move(string);
	
		int player_move(string);

		void make_equal(Room*,Room*&);

		void event_encounter();

		void wumpus_pit_event();

		void bat_event();

		void gold_event();

		void player_attack(string);	

		void north_attack();

		void west_attack();

		void south_attack();

		void east_attack();

		void wumpus_death(int);

		void wumpus_move();

		void game_reset(int);

		bool get_has_died();

		bool computer_play();

		void computer_move();

		void computer_attack(int);

		bool computer_turn();
};

#endif

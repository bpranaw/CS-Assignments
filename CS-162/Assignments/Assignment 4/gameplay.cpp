#include "gameplay.h" 

Gameplay::Gameplay(int input_dimensions, bool input_debug)
{

	//Initializing all the values
	this->wumpus_room = 0;
	this->player_arrows = 3;
	this->is_wumpus_dead = false;
	this->has_gold = false;
	this->player_location = 0;

	this->has_died = false;

	this->dimensions = input_dimensions;
	this->is_debug = input_debug;
	srand(time(NULL));
	
	this->map = NULL;
	this->map_spare = NULL;

	//Creating the map
	create_random_map();
	make_equal(map, map_spare);	

	this->direction == 0;
}

Gameplay::~Gameplay()
{	
	if(this->map != NULL)
		delete [] this->map;

	if(this->map_spare != NULL)
		delete[] this->map_spare;
}

/*************************************************************************************
 * Function Name: view_map
 * Description: Displays the map to the user through the console.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::view_map()
{

	//This is for the first "row" for aesthetic
	cout << " ___";
	
	for(int i = 1; i < dimensions; i++)
	{
		cout << "____";	
	}

	//For each of the individual rows
	int i = 0;
	
	for(i = 0; i < dimensions*dimensions; i++)
	{
		//First part of the row
		if(i % dimensions == 0)
			cout << endl << "|";

		//This checks to see if this is "cheat" mode (debug mode)
		if((map[i].get_room_event() != NULL) && is_debug)
			cout << "_" << map[i].get_room_event()->get_name() << "_|";
		else if(map[i].get_has_player())
			cout << "_+_|";
		else if(map[i].get_is_start_room() && is_debug)
			cout << "_X_|";
		else
			cout << "___|";
	}
	
	cout << endl;	
	
	return;
}

/*************************************************************************************
 * Function Name: check_precept
 * Description: Looks around the player for encounters 
 * Inputs: N/A
 * Outputs: Direction where the precept was encountered (int)
 ************************************************************************************/
int Gameplay::check_precept()
{
	int check = 0;

	//Checks to see if accessing it is legal
	if(check_move("w"))
	{
		if(map[player_location - dimensions].get_room_event() != NULL)
			map[player_location - dimensions].get_room_event()->precept();


		//This is EXTRA
		//Just so the AI can "READ" the precepts
		check = 1;
	}
	//Checks to see if accessing it is legal
	if(check_move("a"))
	{
		if(map[player_location -1].get_room_event() != NULL)
			map[player_location - 1].get_room_event()->precept();

		//This is EXTRA
		//Just so the AI can "READ" the precepts
		check = 2;
	}
	//Checks to see if accessing it is legal
	if(check_move("s"))
	{
		if(map[player_location + dimensions].get_room_event() != NULL)
			map[player_location + dimensions].get_room_event()->precept();

		//This is EXTRA
		//Just so the AI can "READ" the precepts
		check = 3;
	}
	//Checks to see if accessing it is legal
	if(check_move("d"))
	{
		if(map[player_location + 1].get_room_event() != NULL)
			map[player_location + 1].get_room_event()->precept();

		//This is EXTRA
		//Just so the AI can "READ" the precepts
		check = 4;
	}

	return check;
}

/*************************************************************************************
 * Function Name: check_move
 * Description: Makes sure the move is valid 
 * Inputs: The player's move (string)
 * Outputs: Whether the move is valid (bool)
 ************************************************************************************/
bool Gameplay::check_move(string move)
{	
	if((move == "w" || move == "W") && (player_location >= dimensions))
		return true;
	if((move == "a" || move == "A") && ((player_location % dimensions) - 1 >=0))
		return true;
	if((move == "s" || move == "S") && ((player_location + dimensions) < (dimensions * dimensions)))
		return true;
	if((move == "d" || move == "D") && ((player_location + 1) % dimensions != 0))
		return true;
}
/*************************************************************************************
 * Function Name: player_move
 * Description: Executes the player's move (string)
 * Inputs: The player's move
 * Outputs: Direction where a precept has been encountered (int)
 ************************************************************************************/
int Gameplay::player_move(string move)
{
	bool direction = 0;

	//Checks to see if the move is what it is and if it's legal
	if(move == "w" && check_move("w"))
	{
		//Does move
		move_player(player_location - dimensions);
		direction = check_precept();				

	}
	//Checks to see if the move is what it is and if it's legal
	else if(move == "a" && check_move("a"))
	{
		//Does move
		move_player(player_location - 1);
		direction = check_precept();				
	}
	//Checks to see if the move is what it is and if it's legal
	else if(move == "s" && check_move("s"))	
	{
		//Does move
		move_player(player_location + dimensions);
		direction = check_precept();				
	}
	//Checks to see if the move is what it is and if it's legal
	else if(move == "d" && check_move("d"))
	{
		//Does move
		move_player(player_location + 1);
		direction = check_precept();				
	}
}

/*************************************************************************************
 * Function Name: player_attack
 * Description: Facilitates the player's attack 
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::player_attack(string move)
{
	//Removes an arrow
	if(player_arrows > 0)
		this->player_arrows--;

	//So the wumpus doesn't magically come back to life
	if(is_wumpus_dead)
		return;
	
	//Checks to see if the move is what it is and if it's legal
	if(move == "W" && check_move("W") && player_arrows > 0)
	{
		//Shoots Arrow up
		north_attack();
	}
	//Checks to see if the move is what it is and if it's legal
	else if(move == "A" && check_move("A") && player_arrows > 0)
	{
		//Shoots Arrow left
		west_attack();
	}
	//Checks to see if the move is what it is and if it's legal
	else if(move == "S" && check_move("S") && player_arrows > 0)	
	{
		//Shoots Arrow down
		south_attack();
	}
	//Checks to see if the move is what it is and if it's legal
	else if(move == "D" && check_move("D") && player_arrows > 0)
	{
		//Shoots Arrow right
		east_attack();
	}
	
	return;
}

/*************************************************************************************
 * Function Name: north_attack
 * Description: Facilitates the player's attack but only in the north direction 
 * Inputs: N/A
 * Outputs: Whether the player has died
 ************************************************************************************/
void Gameplay::north_attack()
{
	//This position is so the arrow can "move through the map"
	int position = player_location;
	int room_count = 4;
	
	//makes sure the move is legal
	while(position >= dimensions && room_count > 0)
	{
		//Prevents errors
		if(map[position].get_room_event() != NULL)
		{
			//Checks for wumpus	
			if(map[position].get_room_event()->get_name() == "W")
			{
			
				//Kills the wumpus
				wumpus_death(position);
				return;
			}
		}

		//Contributes to the 3 block limit
		position -= dimensions;
		room_count--;
	}

	//Wumpus might move
	wumpus_move();	

	return;
}

/*************************************************************************************
 * Function Name: west_attack
 * Description: Facilitates the player's attack but only in the west direction 
 * Inputs: N/A
 * Outputs: Whether the player has died
 ************************************************************************************/
void Gameplay::west_attack()
{
	//This position is so the arrow can "move through the map"
	int position = player_location;
	int room_count = 4;

	//makes sure the move is legal
	while(((position % dimensions) >= 0 ) && room_count > 0)
	{
		//Prevents errors
		if(map[position].get_room_event() != NULL)
		{
			//Checks for wumpus	
			if(map[position].get_room_event()->get_name() == "W")
			{
				//Kills the wumpus
				wumpus_death(position);
				return;
			}
		}
		
		//Contributes to the 3 block limit
		position -= 1;
		room_count--;
	}

	//Wumpus might move
	wumpus_move();	

	return;
}

/*************************************************************************************
 * Function Name: south_attack
 * Description: Facilitates the player's attack but only in the south direction 
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::south_attack()
{
	//This position is so the arrow can "move through the map"
	int position = player_location;
	int room_count = 4;

	cout << player_location << " " << wumpus_room << endl;

	//Makes sure the moves are legal
	while(((position + dimensions) < (dimensions * dimensions) ) && room_count > 0)
	{
		//Prevents errors
		if(map[position].get_room_event() != NULL)
		{
			//Checks for wumpus	
			if(map[position].get_room_event()->get_name() == "W")
			{
				cout << "Dang my guy" << endl;
				//Kills the wumpus
				wumpus_death(position);
				return;
			}
		}
		
		cout << cout << "position " << position << endl;
		//Contributes to the 3 block limit
		position += dimensions;
		room_count--;
	}

	//Wumpus might move
	wumpus_move();	

	return;
}

/*************************************************************************************
 * Function Name: east_attack
 * Description: Facilitates the player's attack but only in the east direction 
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::east_attack()
{
//This position is so the arrow can "move through the map"
	int position = player_location;
	int room_count = 4;

	//Makes sure the moves are legal
	while((((position + 1) % dimensions) != 0) && room_count > 0)
	{
		//Prevents errors
		if(map[position].get_room_event() != NULL)
		{
			//Checks for wumpus	
			if(map[position].get_room_event()->get_name() == "W")
			{
				//Kills the wumpus
				wumpus_death(position);
				return;
			}
		}
		
		//Contributes to the 3 block limit
		position += 1;
		room_count--;
	}

	//Wumpus might move
	wumpus_move();	

	return;
}
/*************************************************************************************
 * Function Name: wumpus_move
 * Description: Makes the wumpus move into a random empty room 
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::wumpus_move()
{
	//Calculates the probability of wumpus leaving
	int probability = rand() % 4;

	//Doesn't act on it
	if(probability == 0)
	{
		cout << endl << "The wumpus went back to sleep" << endl << endl;
	}
	//Wumpus wakes up.
	else
	{
		cout << endl << "The wumpus has woken up and moved to another room!" << endl << endl;
		
		//Cleans up heap
		delete map[wumpus_room].get_room_event();
		
		//Sets room event to null
		map[wumpus_room].set_room_event(-1);
		
		//Makes sure the wumpus has a new home
		while(1)
		{
			//Chooses the room the wumpus will go to	
			int new_room = rand() % (dimensions * dimensions);
			if(map[new_room].get_room_event() == NULL)
			{
				//Actually moves wumpus to the room
				map[new_room].set_room_event(0);
				wumpus_room = new_room;
				break;
			}
		}
				
	}
}

/*************************************************************************************
 * Function Name: wumpus_death
 * Description: Facilitates the wumpus' death 
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::wumpus_death(int position)
{
	//Lets the game know that the wumpus is dead
	is_wumpus_dead = true;

	//Lets the player know that the wumpus is dead
	cout << endl << "*************************************************************" << endl << endl << endl <<"You have killed the wumpus!!!" << endl << endl << endl;

	if(map[position].get_room_event() != NULL)
	{
		//Deletes the wumpus event
		delete this->map[position].get_room_event();
	}

	//Sets the room to null
	this->map[position].set_room_event(-1);

	return;
}

/*************************************************************************************
 * Function Name: player_turn
 * Description: Facilitates the player's turn 
 * Inputs: N/A
 * Outputs: Whether the player has died
 ************************************************************************************/
bool Gameplay::player_turn()
{
	
	bool turn_result = false;
	
	//Shows the player the map
	view_map();	

	//Tells them about the stuff they have
	
	cout << endl << "***********************************************" << endl;
	cout << "Arrows: " << player_arrows << endl << "***********************************************" << endl;

	cout << "Wumpeses Defeated: " << is_wumpus_dead << endl << "***********************************************" << endl;
	
	cout << "Treature Chests Acquire: " << has_gold << endl << "***********************************************" << endl;

	cout << "What would you like to do?" << endl << "***********************************************" << endl;

	//Prompts Playyer MOve
	string move;

	cin >> move;	

	//Let's the player leave
	if(move == "E" || move == "e")
		return true;

	//Lets the player attack or move
	if(move.at(0) < 91)
		player_attack(move);
	else
		player_move(move);

	return turn_result;
}

/*************************************************************************************
 * Function Name: play_game
 * Description: Checks to see if the game is won.
 * Inputs: N/A
 * Outputs: Whether the player has won.
 ************************************************************************************/
bool Gameplay::play_game()
{
	
	bool variable = false;

	//Win condition of the game
	if((player_location == start_room) && has_gold && is_wumpus_dead) 
	{
		cout << endl <<"You have won!!!!!" << endl << endl;
		variable = true;
	
	}
	//What happens when they die
	else if(has_died)
	{
		return true;
	}
	else	
		//the player's turn.
		variable = player_turn();
	
	
	return variable;
}
/*************************************************************************************
 * Function Name: event_encounter 
 * Description: Deals with when a player encounters each event
 * Inputs: N/A
 * Outputs: N/A
*************************************************************************************/
void Gameplay::event_encounter()
{
	if(map[player_location].get_room_event() != NULL)
	{
		string room_type = map[player_location].get_room_event()->get_name();
		if(room_type == "W" || room_type == "P")
			wumpus_pit_event();
		else if(room_type == "B")
			bat_event();
		else if(room_type == "G")
			gold_event();
	}
	
	return;
}

/*************************************************************************************
 * Function Name: wumpus_pit_encounter 
 * Description: Deals with when a player encounters a pit or wumpus
 * Inputs: N/A
 * Outputs: N/A
*************************************************************************************/
void Gameplay::wumpus_pit_event()
{
	//Tells the user they encountered the gold	
	map[player_location].get_room_event()->encounter();
	
	has_died = true;

	return;
}

/*************************************************************************************
 * Function Name: bat_encounter 
 * Description: Deals with when a player encounters a bat
 * Inputs: N/A
 * Outputs: N/A
*************************************************************************************/
void Gameplay::bat_event()
{
	//Tells the user they encountered the gold	
	map[player_location].get_room_event()->encounter();

	int new_room = rand() % (dimensions * dimensions);

	move_player(new_room);
}

/*************************************************************************************
 * Function Name: gold_event 
 * Description: Deals with when a player encounters the gold
 * Inputs: N/A
 * Outputs: N/A
*************************************************************************************/
void Gameplay::gold_event()
{

	//Tells the user they encountered the gold	
	map[player_location].get_room_event()->encounter();
	
	//Deletes the old event
	delete map[player_location].get_room_event();
	
	//Sets the event to nothing
	map[player_location].set_room_event(-1);
	
	//Makes the player have the gold
	has_gold = true;

	
}
/*************************************************************************************
 * Function Name: create_random_map 
 * Description: Makes a randomized map and returns it
 * Inputs: N/A
 * Outputs: A randomized map (vector<Room>)
*************************************************************************************/
void Gameplay::create_random_map()
{

	//LENGTH JUSTIFICATION: A lot of the length here comes from the fact
	//that there are multiple events (wumpus, pit, bats, gold, and start room
	//to assign). Each of these takes at least 2 lines by themselves and it just
	//feels unncessary to split their assignments into diffrent functions when
	//this function can serve that purpose but just at the cost of a few extra
	//lines of code (4 extra).

	//Determines the size of the map	
	int map_size = (this->dimensions)*(this->dimensions);
	
	//Creates the map of that size
	this->map = new Room[map_size];
	
	//For all the things that will go into the map
	int wumpuses = 1, pits = 2, bats = 2, gold = 1, start = 1;


	//Loops through until every thing has been placed within the map
	while(wumpuses > 0 || pits > 0 || bats > 0 || gold > 0 || start > 0)
	{		
		//Chooses random index
		int index = rand() % map_size;

		//Makes sure the index is empty and the item has to actually be placed
		if(wumpuses > 0 && map[index].get_room_event() == NULL)
		{
			//Sets the wumpus room
			map[index].set_room_event(0);
			wumpus_room = index;
			wumpuses--;
			continue;
		}

		//Makes sure the index is empty and the item has to actually be placed
		if(pits > 0 && map[index].get_room_event() == NULL)
		{
			//Sets the pit room
			map[index].set_room_event(1);
			pits--;
			continue;
		}

		//Makes sure the index is empty and the item has to actually be placed
		if(bats > 0 && map[index].get_room_event() == NULL)
		{
			//Sets the bat room
			map[index].set_room_event(2);
			bats--;
			continue;
		}

		//Makes sure the index is empty and the item has to actually be placed
		if(gold > 0 && map[index].get_room_event() == NULL)
		{
			//Sets the gold room
			map[index].set_room_event(3);
			gold--;
			continue;
		}
	
		//Makes sure the index is empty and the item has to actually be placed
		if(start > 0 && map[index].get_room_event() == NULL)
		{
			start--;
			//Sets the start room
			map[index].set_is_start_room(true);
			player_location = index;
			start_room = index;
		}
	}

	return;

}
					
/*************************************************************************************
 * Function Name: move_player 
 * Description: Moves the player to a new location
 * Inputs: The player's new location (int)
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::move_player(int new_location)
{
	map[player_location].set_has_player(false);
	
	map[new_location].set_has_player(true);
	player_location = new_location;

	//Check encounter
	event_encounter();
}

/*************************************************************************************
 * Function Name: make_equal 
 * Description: Makes of the first map and makes the second one equal to that copy
 * Inputs: The original map (Room*)
 * 	   The spare map (Room*)
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::make_equal(Room* original, Room*& spare) 
{
	//Checks to make sure we aren't gonna allocate
	//memory to a pointer that is already pointing
	if(spare != NULL)
	{
		delete[] spare;
		spare = NULL;
	}	
	

	//Allocates a new map
	spare = new Room[dimensions * dimensions];
	
	//Just so we don't access memory that doens't exist
	if(original != NULL)
	{
		//Copies it over
		for(int i = 0; i < dimensions*dimensions; i++)
			spare[i] = original[i];
	}

	return;
}

/*************************************************************************************
 * Function Name: game_rest 
 * Description: resets all the values of the game class
 * Inputs: Whether the person wants to keep their previous map (0)
 * 	   Or make a new one (1) (int)
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::game_reset(int choice)
{

	//Deletes the old map so a new one can be made
	delete[] map;

	//Resets all the information changed during the game
	has_died = false;
	player_arrows = 3;

	has_gold = false;
	is_wumpus_dead = false;
	player_location = start_room;

	//Sets the pointers to null
	map = NULL;

	//Executes the user's choice
	if(choice == 0)
	{
		map = new Room[dimensions * dimensions];
		make_equal(map_spare, map);
	}
	else
	{
		
		//Makes the spare maps usable egain
		delete[] map_spare;
		map_spare = NULL;
		
		//Prompts the user for a new size
		cout << "What size map? Please enter only valid values." << endl;
		cin >> dimensions;

		//Creates the new map.
		create_random_map();
		make_equal(map, map_spare);	
	}	
}

/*************************************************************************************
 * Function Name: get_has_died 
 * Description: Returns whether the user has died or not
 * Inputs: N/A
 * Outputs: Whether the user has died or not (bool)
 ************************************************************************************/
bool Gameplay::get_has_died()
{
	return this->has_died;
}


/*************************************************************************************
 * Function Name: computer_play 
 * Description: Where the computer plays the game for the user
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
bool Gameplay::computer_play()
{

	//Shows the player the map
	view_map();	

	bool turn_result = false;
	
	//Tells them about the stuff they have
	
	cout << endl << "***********************************************" << endl;
	cout << "Arrows: " << player_arrows << endl << "***********************************************" << endl;

	cout << "Wumpeses Defeated: " << is_wumpus_dead << endl << "***********************************************" << endl;
	
	cout << "Treature Chests Acquire: " << has_gold << endl << "***********************************************" << endl;

	cout << "Would you like the computer to make a move?\nEnter E to leave and anything else to stay" << endl << "***********************************************" << endl;

	string move;

	cin >> move;	

	if(move == "E" || move == "e")
		return true;

	computer_move();

	return false;

}

/*************************************************************************************
 * Function Name: computer_turn
 * Description: Determines if the computer's win conditions are met
 * Inputs: N/A
 * Outputs: Whether the win conditions are met or CPU has died (bool)
 ************************************************************************************/
bool Gameplay::computer_turn()
{

	bool variable = false;

	//Win condition of the game
	if((player_location == start_room) && has_gold && is_wumpus_dead) 
	{
		cout << endl <<"You have won!!!!!" << endl << endl;
		variable = true;
	
	}
	//What happens when they die
	else if(has_died)
	{
		return true;
	}
	else	
		//the computer's turn.
		variable = computer_play();
	
	return variable;	
}



/*************************************************************************************
 * Function Name: computer_Move
 * Description: Determines the computer's moves
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::computer_move()
{
	//Computer chooses a random position to move to
	int move = 2; 
	move = (rand() % 5) + 1;

	//If it hasn't "read" a precept yet, it won't attack
	if(direction != 0)
	{
		computer_attack(direction);
		direction = 0;
	}
	else
	{
		if(move == 1)
			direction = player_move("w");
		else if(move == 2)
			direction = player_move("a");
		else if(move == 3)
			direction = player_move("s");
		else if (move == 4)
			direction = player_move("d");

	}

	return;
}

/*************************************************************************************
 * Function Name: computer_attack
 * Description: Executes the computer's main method of attack
 * Inputs: The direction the computer is attacking in (int)
 * Outputs: N/A
 ************************************************************************************/
void Gameplay::computer_attack(int direction)
{

	//Removes an arrow
	if(player_arrows > 0)
		this->player_arrows--;

	//So the wumpus doesn't magically come back to life
	if(is_wumpus_dead)
		return;
	
	//Checks to see if the move is what it is and if it's legal
	if(direction == 1 && check_move("W") && player_arrows > 0)
	{
		//Shoots Arrow up
		north_attack();
	}
	//Checks to see if the move is what it is and if it's legal
	else if(direction == 2 && check_move("A") && player_arrows > 0)
	{
		//Shoots Arrow left
		west_attack();
	}
	//Checks to see if the move is what it is and if it's legal
	else if(direction == 3 && check_move("S") && player_arrows > 0)	
	{
		//Shoots Arrow down
		south_attack();
	}
	//Checks to see if the move is what it is and if it's legal
	else if(direction == 4 && check_move("D") && player_arrows > 0)
	{
		//Shoots Arrow right
		east_attack();
	}
	
	direction = 0;

	return;
}

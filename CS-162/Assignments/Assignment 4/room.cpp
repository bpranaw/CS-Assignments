#include "room.h"

Room::Room()
{
	this->room_event = NULL;
	
	this->has_wumpus = false;
	this->has_pit = false;
	this->has_bat = false;
	this->has_gold = false;
	this->has_player = false;
	this->is_start_room = false;

}

Room::Room(const Room & previous_room)
{

	if(this != & previous_room)
	{
		//Makes sure there the memory for the current
		//event is taken care of
		if(this->room_event != NULL)
		{
			delete this->room_event;
			this->room_event = NULL;
		}

		//"Copies" the event
		if(previous_room.room_event != NULL)
		{
			string option = previous_room.room_event->get_name();
			if(option == "W")
				this->room_event = new Wumpus;
			else if(option == "P")
				this->room_event = new Pit;
			else if(option == "B")
				this->room_event = new Bat;
			else if(option == "G")
				this->room_event = new Gold;
			else
				this->room_event = NULL;
		}
		
		//For Regular Variables
		this->has_wumpus = previous_room.has_wumpus;
		this->has_pit = previous_room.has_pit;
		this->has_bat = previous_room.has_bat;
		this->has_gold = previous_room.has_gold;
		this->has_player = previous_room.has_player;
		this->is_start_room = previous_room.is_start_room;
	}

}

Room & Room::operator = (const Room & previous_room)
{

	if(this != & previous_room)
	{
		//Makes sure there the memory for the current
		//event is taken care of
		if(this->room_event != NULL)
		{
			delete this->room_event;
			this->room_event = NULL;
		}

		//"Copies" the event
		if(previous_room.room_event != NULL)
		{
			string option = previous_room.room_event->get_name();
			if(option == "W")
				set_room_event(0);
			else if(option == "P")
				set_room_event(1);
			else if(option == "B")
				set_room_event(2);
			else if(option == "G")
				set_room_event(3);
			else
				set_room_event(-1);
		}
		
		//For Regular Variables
		this->has_wumpus = previous_room.has_wumpus;
		this->has_pit = previous_room.has_pit;
		this->has_bat = previous_room.has_bat;
		this->has_gold = previous_room.has_gold;
		this->has_player = previous_room.has_player;
		this->is_start_room = previous_room.is_start_room;

	}
	
}

Room::~Room()
{

//	if(this->room_event != NULL)
//	{
		delete this->room_event;
//	}

	set_room_event(-1);

}

/*************************************************************************************
 * Function Name: set_room_event
 * Description: Sets the room to nothing, wumpus, pit, bat, or gold depending on input
 * Inputs: The option(int): Wumpus (0), Pit (1), Bat (2), Gold (3), Empty  (anything else)
 * Outputs: N/A
 ************************************************************************************/
void Room::set_room_event(int option)
{
	//Just so I don't accidently cause memory leaks
//	if(this->room_event != NULL)
//		delete room_event;
	
	//Wumpus
	if(option == 0)
		this->room_event = new Wumpus;
	//Bottomless Pit
	else if(option == 1)
		this->room_event = new Pit;
	//Super Bat
	else if(option == 2)
		this->room_event = new Bat;
	//Gold
	else if(option == 3)
		this->room_event = new Gold;
	//An empty room
	else
		this->room_event = NULL; 

	return;		
}

/*************************************************************************************
 * Function Name: get_room_event
 * Description: Returns the room event pointer
 * Inputs: N/A
 * Outputs: The room event pointer (Event*)
 ************************************************************************************/
Event* Room::get_room_event()
{
	return this->room_event;
}
		
/*************************************************************************************
 * Function Name: set_has_wumpus
 * Description: Sets the fact that the wumpus exists within this room
 * Inputs: Whether the wumpus exits in the room (bool)
 * Outputs: N/A
 ************************************************************************************/
void Room::set_has_wumpus(bool does_exist)
{
	this->has_wumpus = does_exist;
	return;
}

/*************************************************************************************
 * Function Name: get_has_wumpus
 * Description: Returns whether the room has the wumpus or not
 * Inputs: N/A
 * Outputs: Whether the room has the wumpus (bool)
 ************************************************************************************/
bool Room::get_has_wumpus()
{
	return this->has_wumpus;
}

/*************************************************************************************
 * Function Name: set_has_pit
 * Description: Sets whether the room has the pit or not
 * Inputs: Whether the pit exists within the room (booL)
 * Outputs: N/A
 ************************************************************************************/
void Room::set_has_pit(bool does_exist)
{
	this->has_pit = does_exist;
	return;
}

/*************************************************************************************
 * Function Name: get_has_pit
 * Description: Returns whether or not the room has the pit
 * Inputs: N/A
 * Outputs: Whether or not the room has the pit (bool)
 ************************************************************************************/
bool Room::get_has_pit()
{
	return this->has_pit;
}

/*************************************************************************************
 * Function Name: set_has_bat
 * Description: Sets whether this room has a bat or not
 * Inputs: Whether this room has a bat (bool)
 * Outputs: N/A
 ************************************************************************************/
void Room::set_has_bat(bool does_exist)
{
	this->has_bat = does_exist;
	return;
}

/*************************************************************************************
 * Function Name: get_has_bat
 * Description: Returns whether or not the room has a bat
 * Inputs: N/A
 * Outputs: Whether or not the room has a bat (bool)
 ************************************************************************************/
bool Room::get_has_bat()
{
	return this->has_bat;
}

/*************************************************************************************
 * Function Name: set_has_gold
 * Description: Sets whether or not this room has the gold
 * Inputs: Whether or not the room has the gold (bool)
 * Outputs: N/A
 ************************************************************************************/
void Room::set_has_gold(bool does_exist)
{
	this->has_gold = does_exist;
	return;
}

/*************************************************************************************
 * Function Name: get_has_gold
 * Description: Returns whether the room has the gold
 * Inputs: N/A
 * Outputs: Whether the room has the gold or not (bool)
 ************************************************************************************/
bool Room::get_has_gold()
{
	return this->has_gold;
}

/*************************************************************************************
 * Function Name: set_has_player
 * Description: Sets whether the room has the player
 * Inputs: Whether the room has the player (bool)
 * Outputs: N/A
 ************************************************************************************/
void Room::set_has_player(bool does_exist)
{
	this->has_player = does_exist;
	return;	
}

/*************************************************************************************
 * Function Name: get_has_player
 * Description: Returns whether the room has the player or not
 * Inputs: N/A
 * Outputs: Whether the room has the player (bool)
 ************************************************************************************/
bool Room::get_has_player()
{
	return this->has_player;
}

/*************************************************************************************
 * Function Name: set_is_start_room
 * Description: Returns whether the room is the start room or not
 * Inputs: N/A
 * Outputs: Whether the room is the start room (bool)
 ************************************************************************************/
void Room::set_is_start_room(bool does_exist)
{
	this->is_start_room = does_exist;
	this->has_player = does_exist;
	return;
}

/*************************************************************************************
 * Function Name: get_is_start_room
 * Description: Returns whether the room is the start room or not
 * Inputs: N/A
 * Outputs: Whether the room is the start room (bool)
 ************************************************************************************/
bool Room::get_is_start_room()
{
	return this->is_start_room;
}
	
/*************************************************************************************
 * Function Name: is_wumpus_dead 
 * Description: Determines if the wumpus has been killed. This is called when an arrow is shot
 * Inputs: N/A
 * Outputs: Whether or not the wumpus has been kiled (bool)
 ************************************************************************************/
bool Room::is_wumpus_dead()
{
	//Means that the wumpus has died
	if(this->has_wumpus)
		return true;
	//The wumpus has not died
	else
		return false;
}


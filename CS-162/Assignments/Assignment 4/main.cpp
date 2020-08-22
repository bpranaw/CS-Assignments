#include "gameplay.h"
#include <iostream>
#include <stdlib.h>

#include "room.h"

using std::cout;
using std::cin;


void facilitate_game(int, bool, int);

int main(int argc, char* argv [])
{
	int dimensions = 3;
	bool debug = false;

	//Light Error Handing_________________________________________________________________________________________________________________________________________________________
	

	//In case the user enters something incorrect
	//It's not an exhaustive check but it should do the trick
	if(argc < 3)
	{
		cout << "You have entered an incorrect value somewhere, so the default settings of\nDimensions: 3\nDebug: false\nwill be used..." << endl;
	}
	else
	{
	
		char c = argv[2][0];
	
		//This is inside so it doesn't cause a seg fault
		if((c != 84 && c != 116 && c != 70 && c != 102 ) || argv[1][0] > 57 || atoi(argv[1]) < 3)
		{
			cout << "You have entered an incorrect value somewhere, so the default settings of\nDimensions: 3\nDebug: false\nwill be used..." << endl;
		}
		else
		{
			//Sets the command line arguments as the arguments
			//that will go into the game
			dimensions = atoi(argv[1]);		
		
			if(c == 84 || c== 116)
				debug = true;
		}
	
	}

	facilitate_game(dimensions, debug, argc);	

	return 0;
}

/*************************************************************************************
 * Function Name: facilitate_game
 * Description: Allows the players (CPU or human) to play the same
 * 		This was put here to save space in main, which has the error 
 * 		handling
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void facilitate_game(int dimensions, bool debug, int argc)
{

	//Actual Gameplay_____________________________________________________________________________________________________________________________________________________________

	cout << endl << "********************************************************************************************************" << endl << "Welcome to the Wumpus game!!!\n\nStory: You are an explorer in a WUMPUS CAVE. You must explore the cave and find the Treasure\nFinding a WUMPUS or a bottomless pit room will kill you immediately. Bats will movve you to another orom when you encounter them.\nYou can kill the wumpus by shooting an arrow through rooms in cardinal directions.\n\nInstructions:\nMovement: You can move around north, west, south and east by entering the wasd keys when prompted. LOWERCASE = Movement.\nAttacking: You can fire your arrows north, west, south or east by entering the WASD keys respectively. UPPERCASE = Attacking.\nLEAVING: You may exit the game at any turn by entering either (E) or (e).\nWIN CONDITION: In order to win you need to:\n	1) Kill the Wumpus\n	2) Find the Treasure\n	3) Go back to the start room\n " << endl << endl;	
	
	//Iniates the game with these parameters
	Gameplay game(dimensions, debug);
	
	string choice;

	//Computer gameplay
	if(argc > 3)
	{
		bool check = false;
		while(!check)
		{
			//Checks for death	
			if(game.get_has_died())
			{
				//Allows the player to choose a new map for the computer
				cout << "Would you like to play again with your same map? If so, enter Y, and N if not. Enter E to exit.\nAny false entry is treated as E" << endl;
	
				//Prompts them
				cin >> choice;
				
				//Executes the reset			
				if(choice == "Y" || choice == "y")
					game.game_reset(0);
				else if(choice == "N" || choice == "n")
					game.game_reset(1);		
				else
					break;				
			}
			//Lets the computer play the game
			check = game.computer_turn();
		}
	}
	else
	{
		bool check = false;
		while(!check)
		{
			//Checks for death
			if(game.get_has_died())
			{
				//Prompts the user as to whether they want to play again on the same map
				cout << "Would you like to play again with your same map? If so, enter Y, and N if not. Enter E to exit.\nAny false entry is treated as E" << endl;
	
				cin >> choice;

				//Executes the reset
				if(choice == "Y" || choice == "y")
					game.game_reset(0);
				else if(choice == "N" || choice == "n")
					game.game_reset(1);		
				else
					break;				
			}
			
			//Allows the user to play the game
			check = game.play_game();
		}

	}

}

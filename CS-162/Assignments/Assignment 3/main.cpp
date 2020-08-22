#include "zoo.h"
#include "animal.h"
#include "monkey.h"
#include "otter.h"
#include "sloth.h"
#include "polar_bear.h"

#include <iostream>

//Function declaration
bool start_game();

//MAIN
int main()
{
	
	bool am_leaving_game = false;

	while(!am_leaving_game)
	{
		am_leaving_game = start_game();	

	}

	return 0;
}

//Function Definition

/*************************************************************************************
 * Name: start_game
 * Description: Starts the zoo game (this is the home screen)
 * Inputs: N/A
 * Outputs: Returns whether or not the user has decided to end the program.
 ************************************************************************************/
bool start_game()
{

	//Technically this part could have been made into 1 line but I split it up for readability purposes. It really only takes up so much
	//space because there is a bit of things to say. It just adds on more lines than is necessary.
	//Welcome Message
	std::cout << "**********************************************************************************************\n\n Welcome to the Zoo Tycoon Game!!!!" << std::endl;
	std::cout <<"	This program is a text based game. The game is as follows: \n\n		You play as a zookeepr for Krusty Krab Zoo. Your goal is to make the zoo as much money as possible." << std::endl;
	std::cout << "You will start with $50,000 at the start. Each turn will consist of:\n     1) A month passing\n     2) The recieval of Monthly Revenue for each animal" << std::endl;
	std::cout << "     3) A special Event\n     4) The option to buy animals\n     5) The option to sell animals\n     6) The requirement of buying next month's animal feed\n		There are some choices of feed\n" << std::endl;
	std::cout << "	If you loose too much money (the zoo's balance is < 0), you will become bankrupt and the game will end." << std::endl;
	
	//Asks the user whether they would like to play and prompts them for their answer.
	std::cout << std::endl << "What would you like to do?\n     1) Start a new game\n     2) Exit the program\n\nIf you enter anything invalid, the program will exit by defualt." << std::endl;

		
	int choice = 2;
	
	std::cin >> choice;

	//Checks to see if the player wants to play
	if(choice == 1)
	{
		Zoo krusty_krabs;

		int am_leaving_game = false;

		//This cycles through the player's turn
		while(!am_leaving_game)
		{
			am_leaving_game = krusty_krabs.play_game();	
		}
		return false;
	}
	else
	//This will cause the program to exit
		return true;
}

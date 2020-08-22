#include "restaurant.h"

using namespace std;

int main()
{

	//Repeats until the user chooses to leave
	while(1)
	{

		//Initializes the krusty krab pizza shop
		Restaurant krustyKrab;

		//Takes all the information form the files and puts them into the krusty krab's books
		krustyKrab.loadData();
	
		//Message to the user
		cout << endl << "************************************************************************************************************************************************" << endl << endl << "Welcome to the Krusty Krab Pizza Portal" << endl << endl;

		//Finds out if the user is a customer or employee
		krustyKrab.personPrompt();

		//Prompts the user for input
		char choice;
		cout << endl << "Would you like to leave the program?\nType N to stay and anything else to leave" << endl;
		cin >> choice;

		//Lets the user leave
		if(choice != 'N' && choice != 'n')
			break;
	
	}	
	return 0;
}



/*************************************************************************************************************************************************************************************
 * PROGRAM NAME: Pizza Portal
 *
 * AUTHOR: Pranaw Bajracharya
 *
 * Description: This is a pizza portal, designed to allow customers and employees of a pizza place interact with the store through the console. The program
 * 		looks at the files (order.txt, menu.txt, employees.txt, restaurant.txt) and distributes the information form the files to the Restaurant's books. 
 * 		The portal allows employees to login using their credentials.
 * 		Employees can do all the basic stuff, like veiwing the restaurant's information. Additionally, they can change the files, such as the orders, and the menu.
 *		Customers can also check out all of the restaurant's public information, search through the menu, filter the menu by price, or by ingredients.
 * Classes:
 * 	Pizza - The lowest class. Just contains information about a specific pizza.
 * 	Menu - The middle class. Has a list of all the pizzas.
 * 	Restaurant - the highest class. It has all the restaurant's information and the processes that make up the Pizza Portal.
 *
 * Structs:
 * 	Employee - Contains all the information related to an employee such as name, ID, and password.
 * 	Hours - Contains the informatin about open and closing times on specific days.
 *
 * Files:
 * 	orders.txt - Contains all the orders
 * 	employees.txt - Contains all the information on the employees
 * 	restaurant_info.txt - Contains all the public information about the restaurant
 ************************************************************************************************************************************************************************************/
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



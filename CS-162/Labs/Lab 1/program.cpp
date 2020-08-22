#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "multdiv.h"

using namespace std;

int main(int argc, char *argv[1])
{

	while(1)
	{

		int incorrectRows = -1;
		int incorrectColumns = -1;

		int rows = -1;
		int columns = -1;
	
		//Checks for too little arguments
		if(argc < 3)
		{
			cout << "You've entered too little parameters." << endl;
			isValidDimensions(&incorrectRows, &incorrectColumns);

			//Creates table
			multdivEntry** table = createTable(incorrectRows, incorrectColumns);

			//Calculates the math and prints out the table
			printTable(table, incorrectRows, incorrectColumns);

			//Clears the heap
			deleteTable(table, incorrectRows);
	
		}		
		else
		{
		
			rows = atoi(argv[1]);
			columns = atoi(argv[2]);

			isValidDimensions(&rows, &columns);	

			//Creates table
			multdivEntry** table = createTable(rows, columns);

			//Calculates the math and prints out the table
			printTable(table, rows, columns);

			//Clears the heap
			deleteTable(table, rows);	
		}
		cout << "Do you want to try again with a different sized table?";
		cout << endl << "Type in lowercase y for yes and anything else for no" << endl;
		char answer = 'n';
		cin >> answer;
		
		if(answer != 'y')
		{
			break;
		}
		else
		{
			rows = -1;
			columns = -1;
	
		}
		
	}
			
}


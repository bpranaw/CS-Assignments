#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "multdiv.h"

using namespace std;



bool isValidDimensions(int* rows, int* columns)
{
	bool check = false;
	
	//Checks for invalid arguments
	while(!check)
	{
		//Reprompts the user for a correct number of rows
		if(*rows < 0)
		{
			cout << "You've entered invalid parameters\nPlease enter an integer greater than zero for the rows." << endl;
			cin >> *rows;
			cin.clear();
			cin.ignore(1000000,'\n');
		}

		//Reprompts the user for a correct number of tables
		if(*columns < 0)
		{
			cout << "You've entered invalid parameters\nPlease enter an integer greater than zero for the columns." << endl;
			cin >> *columns;
			cin.clear();
			cin.ignore(1000000,'\n');
		}
		
		if(rows >= 0 & columns >= 0)
			check = true;	
	}

}

multdivEntry** createTable(int rows, int columns)
{
	multdivEntry** table = new multdivEntry*[rows];
	for(int i = 0; i < rows; i++)
	{
			table[i] = new multdivEntry[columns];
	}
	return table;
}

void printTable(multdivEntry** table, int rows, int columns)
{
	//Calculations
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			table[i][j].mult = (i + 1) * (j + 1);
			table[i][j].div = float(i + 1.00) / float(j + 1.00);
		}
	}

	//Printing Multiplication Table
	cout << "**********Multiplication Table**********" << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			if(table[i][j].mult > 9)
				cout << table[i][j].mult << "   ";
			else
				cout << table[i][j].mult << "    ";
		}
		cout << endl;
	}

	//Printing Division Table
	cout << "*************Division Table*************" << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout << setprecision(3) << table[i][j].div << "    ";
		}
		cout << endl;
	}
}

void deleteTable(multdivEntry** table, int rows)
{
	for(int i = 0; i < rows; i++)
	{
		delete[] table[i];
	}
	
	delete[] table;
}

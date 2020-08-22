//#include "restaurant.h"
#include "pizza.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	//Making a pizza
	Pizza pep;

//____________________________________________________________________________________

//ORIGINAL

	//File inputs
	ifstream inputFile;
	string file = argv[1];

	inputFile.open(file.c_str());
	
	int numberOfPizzas;
	
	inputFile >> numberOfPizzas;
	
	pep.populatePizza(inputFile);

	inputFile.close();

	cout << pep.getName() << "   " << pep.getSmallCost() << "   " << pep.getMediumCost() << "   ";
	cout << pep.getLargeCost() << "   " <<  pep.getNumberOfIngredients() << "   ";
	
	inputFile.close();
	
	for(int i = 0; i < pep.getNumberOfIngredients(); i++)
	{
		cout <<	pep.getIngredients()[i] << "   ";
	}

	cout << endl;

//____________________________________________________________________________________

//COPY CONSTRUCTOR

	Pizza cheese(pep);

	cout << cheese.getName() << "   " << cheese.getSmallCost() << "   " << cheese.getMediumCost() << "   ";
	cout << cheese.getLargeCost() << "   " <<  cheese.getNumberOfIngredients() << "   ";

	for(int i = 0; i < cheese.getNumberOfIngredients(); i++)
	{
		cout <<	cheese.getIngredients()[i] << "   ";
	}

	cout << endl;

//____________________________________________________________________________________

//ASSIGNMENT OPERATOR

	Pizza supreme;

	supreme = cheese;

	cout << supreme.getName() << "   " << supreme.getSmallCost() << "   " << supreme.getMediumCost() << "   ";
	cout << supreme.getLargeCost() << "   " <<  supreme.getNumberOfIngredients() << "   ";

	
	for(int i = 0; i < supreme.getNumberOfIngredients(); i++)
	{
		cout <<	supreme.getIngredients()[i] << "   ";
	}
	
	cout << endl;

	return 0;
}

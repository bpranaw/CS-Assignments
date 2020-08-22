//#include "restaurant.h"
#include "pizza.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	//Making a pizza
	Pizza pep;


	//File inputs
	ifstream inputFile;
	string file = argv[1];

	inputFile.open(file.c_str());
	
	int numberOfPizzas;
	
	inputFile >> numberOfPizzas;
	
	pep.populatePizza(inputFile);

	inputFile.close();

	cout << pep.getName() << "   " << pep.getSmallCost() << "   " << pep.getMediumCost() << "   "  << pep.getLargeCost() << "   " <<  pep.getNumberOfIngredients() << "   ";
	
	inputFile.close();
	
	for(int i = 0; i < pep.getNumberOfIngredients(); i++)
	{
		cout <<	pep.getIngredients()[i] << "   ";
	}

	cout << endl;

	return 0;
}

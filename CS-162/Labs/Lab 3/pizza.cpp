#include "pizza.h"

Pizza::Pizza()
{


		this->name = "bob";
		this->small_cost = 2;
		this->medium_cost = 2;
		this->large_cost = 2;
		this->num_ingredients = 2;
		this->ingredients = &this->name;

}

Pizza::~Pizza()
{
	delete[] this->ingredients;
}

void Pizza::setName( const string name) 
{
	this->name = name;
	return;
}

const string Pizza::getName()
{
	return this->name;
}



void Pizza::setSmallCost(const float cost)
{
	this->small_cost = cost;
	return;
}

const float Pizza::getSmallCost()
{
	return this->small_cost;
}

void Pizza::setMediumCost(const float cost)
{
	this->medium_cost = cost;
	return;
}

const float Pizza::getMediumCost()
{
	return this->medium_cost;
}
void Pizza::setLargeCost(const float cost)
{
	this->large_cost = cost;
	return;
}

const float Pizza::getLargeCost()
{
	return this->large_cost;
}

void Pizza::setNumberOfIngredients(const int number)
{
	this-> num_ingredients = number;
}

const int Pizza::getNumberOfIngredients()
{
	return this->num_ingredients;
}

void Pizza::setIngredients(const int numberOfIngredients)
{
	
	this->ingredients = new string[numberOfIngredients];
	return;
}


const string* Pizza::getIngredients()
{
	return this->ingredients;
}


void Pizza::populatePizza(ifstream & inputFile)
{

	string Name;
	inputFile >> Name;
	this->setName(Name);


	float smallCost;
	inputFile >> smallCost;
	this->setSmallCost(smallCost);

	
	float mediumCost;
	inputFile >> mediumCost;
	this->setMediumCost(mediumCost);

	float largeCost;
	inputFile >> largeCost;
	this->setLargeCost(largeCost);

	int numberOfIngredients;
	inputFile >> numberOfIngredients;
	this->setNumberOfIngredients(numberOfIngredients);

	this->setIngredients(numberOfIngredients);
	for(int i = 0; i < numberOfIngredients; i++)
	{
		string ingredient;
		inputFile >> ingredient;
		this->ingredients[i] = ingredient;
	}

	return;
	
}






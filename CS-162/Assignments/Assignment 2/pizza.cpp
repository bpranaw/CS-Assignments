#include "pizza.h"


/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
Pizza::Pizza()
{


		this->name = "bob";
		this->small_cost = 2;
		this->medium_cost = 2;
		this->large_cost = 2;
		this->num_ingredients = 2;
		this->ingredients = &this->name;

}


/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
Pizza::~Pizza()
{
	delete[] this->ingredients;
	this->ingredients = NULL;
}


/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
Pizza::Pizza(const Pizza & old_pizza)
{
	this->name = old_pizza.name;
	this->small_cost = old_pizza.small_cost;
	this->medium_cost = old_pizza.medium_cost;
	this->large_cost = old_pizza.large_cost;
	this->num_ingredients = old_pizza.num_ingredients;

	this->ingredients = new string[num_ingredients];
	for(int i = 0; i < num_ingredients; i++)
	{
		this->ingredients[i] = old_pizza.ingredients[i];
	}
	
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
Pizza& Pizza::operator=(const Pizza & old_pizza)
{
	if(this != &old_pizza)
	{
		this->name = old_pizza.name;
		this->small_cost = old_pizza.small_cost;
		this->medium_cost = old_pizza.medium_cost;
		this->large_cost = old_pizza.large_cost;
		this->num_ingredients = old_pizza.num_ingredients;

/*
		if(this->ingredients != NULL)
			delete[] this->ingredients;
*/	

		this->ingredients = new string[num_ingredients];
		
		for(int i = 0; i < this->num_ingredients; i++)
		{
			this->ingredients[i] = old_pizza.ingredients[i];
		}

	}



	return *this;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
void Pizza::setName(const string name) 
{
	this->name = name;
	return;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
const string Pizza::getName()
{
	return this->name;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
void Pizza::setSmallCost(const float cost)
{
	this->small_cost = cost;
	return;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
const float Pizza::getSmallCost()
{
	return this->small_cost;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
void Pizza::setMediumCost(const float cost)
{
	this->medium_cost = cost;
	return;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
const float Pizza::getMediumCost()
{
	return this->medium_cost;
}


/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
void Pizza::setLargeCost(const float cost)
{
	this->large_cost = cost;
	return;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
const float Pizza::getLargeCost()
{
	return this->large_cost;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
void Pizza::setNumberOfIngredients(const int number)
{
	this-> num_ingredients = number;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
const int Pizza::getNumberOfIngredients()
{
	return this->num_ingredients;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
void Pizza::setIngredients(const int numberOfIngredients)
{
	
	this->ingredients = new string[numberOfIngredients];
	return;
}


/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
const string* Pizza::getIngredients()
{
	return this->ingredients;
}

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
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






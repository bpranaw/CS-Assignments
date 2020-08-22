#include "menu.h"

//CONSTRUCTORS________________________________________________________________________________________________________________________________________________________________________

//Default Constructor
/*************************************************************************************
 * Name: (DEFAULT CONSTRUCTOR)
 * Description: This is the default constructor. It is called when an instance of the
 * 		menu is created and it just initialzes the values of the variables
 * 		to something.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
Menu::Menu()
{
	numberOfPizzas = 0;
	Pizza* pizzas = NULL;
}

//COPY CONSTRUCTOR
//JUST IN CASE I NEED TO PASS A MENU OBJECT INTO SOMETHING
/*************************************************************************************
 * Name: (COPY CONSTRUCTOR)
 * Description: This is the copy constructor. It is called when a new menu class 
 * 		instance is declared and made equal to something else (Menu bobBurger
 * 		= krustyKrabs;) or when it is specifically called (bobBuger(mcdonalds)
 * Inputs: Address of the old menu that the information is being copied from (Menu)
 * Outputs: N/A
 ************************************************************************************/
Menu::Menu(const Menu & previousMenu)
{	
	this->numberOfPizzas = previousMenu.numberOfPizzas;

	this->pizzas = new Pizza[numberOfPizzas];	
	for(int i = 0; i < numberOfPizzas; i++)
	{
		this->pizzas[i] = previousMenu.pizzas[i];
	}
}

//ASSIGNMENT OPERATOR OVERLOAD
/*************************************************************************************
 * Name: (ASSIGNMENT OPERATOR OVERLOAD)
 * Description: This is just an overloading of the assignment operator "="
 * 		This just defines the behavior for when an a menu is set = to another
 * Inputs: The address of the menu that the information is being copied from (& Menu)
 * Outputs: A deferenced pointer to this new information (Basically a new copy
 * 	    of the old information).
 ************************************************************************************/
Menu& Menu::operator = (const Menu & previousMenu)
{	
	if(this != &previousMenu)
	{

		this->numberOfPizzas = previousMenu.numberOfPizzas;
		this->pizzas = new Pizza[numberOfPizzas];	
		for(int i = 0; i < numberOfPizzas; i++)
		{
			this->pizzas[i] = previousMenu.pizzas[i];
		}

	}

	return *this;
}

//DESTRUCTOR
/*************************************************************************************
 * Name: (DESTRUCTOR)
 * Description: This is the destructor for the menu. This is called when the object
 * 		goes out of scope. It clears up the dynamic memory that is allocated
 * 		for the menu class instance.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
Menu::~Menu()
{
	delete[] this->pizzas;
	this-> pizzas = NULL;
}

//ACCESSORS/MUTATORS__________________________________________________________________________________________________________________________________________________________________

//FOR NUMBER OF PIZZAS
	
//Accessor

/*************************************************************************************
 * Function Name: getNumberOfPizzas
 * Description: Returns the number of pizzas value
 * Inputs: N/A
 * Outputs: Number of pizzas (const int)
 ************************************************************************************/
const int Menu::getNumberOfPizzas()
{
	return this->numberOfPizzas;
}

//Mutator

/*************************************************************************************
 * Function Name: setNumberOfPizzas
 * Description: Takes in the number of pizzas and updates the variable within the
 * 		instance of the menu class to that input number
 * Inputs: The number of pizzas (const int)
 * Outputs: N/A
 ************************************************************************************/
void Menu::setNumberOfPizzas(const int numberOfPizzas)
{
	this->numberOfPizzas = numberOfPizzas;
	return;
}

//FOR PIZZA ARRAY
	
//Accessor

/*************************************************************************************
 * Function Name: getPizzas
 * Description: Returns the pizza array that constains all the pizzas on the menu
 * Inputs: N/A
 * Outputs: The pizzas on the menu (Pizza *)
 ************************************************************************************/
Pizza* Menu::getPizzas()
{
	return this->pizzas;
}

//Mutator

/*************************************************************************************
 * Function Name: setPizzaArray
 * Description: Takes in a array of pizzas and makes the menu equal to that array of
 * 		pizzas. Also sets the number of pizzas to the array length that was
 * 		inputted (manually inputted not calculated array length)
 * Inputs: An array of pizzas (const Pizza*)
 * 	   The length of the array (const int)
 * Outputs: N/A
 ************************************************************************************/
void Menu::setPizzaArray(const Pizza* pizzaArray, const int arrayLength)
{
	setNumberOfPizzas(arrayLength);
	this->pizzas = new Pizza[this->numberOfPizzas];
	
	for(int i = 0; i < numberOfPizzas; i++)
	{
		this->pizzas[i] = pizzaArray[i];
	}
	
	return;
} 	






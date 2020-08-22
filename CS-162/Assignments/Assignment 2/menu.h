#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "pizza.h"

using namespace std;

class Menu {
private:
	int numberOfPizzas;
	Pizza* pizzas;

public:

//CONSTRUCTORS________________________________________________________________________________________________________________________________________________________________________

	//Default Constructor
	Menu();

	//COPY CONSTRUCTOR
	//JUST IN CASE I NEED TO PASS A MENU OBJECT INTO SOMETHING
	Menu(const Menu &);

	//ASSIGNMENT OPERATOR OVERLOAD
	Menu& operator = (const Menu &);

	//DESTRUCTOR
	~Menu();

//ACCESSORS/MUTATORS__________________________________________________________________________________________________________________________________________________________________

	//FOR NUMBER OF PIZZAS
	
	//Accessor
	const int getNumberOfPizzas();

	//Mutator
	void setNumberOfPizzas(const int);

	//FOR PIZZA ARRAY
	
	//Accessor
	Pizza* getPizzas();

	//Mutator
	void setPizzaArray(const Pizza*,const int); 	

/*I forgot these were here and accidently made them in the Restaurant class with different interpretation. It would be entirely possible to move it over to here, but Honestly it would be very annoying

//SEARCHING FUNCTIONS_________________________________________________________________________________________________________________________________________________________________
    
	//int upper bound
	Menu searchPizzaByCost(const int);

	Menu searchPizzaByIncludingIngredients(string*, const int);

	Menu searchPizzaByExcludingIngredients(string*, const int);



//MENU EDITORS________________________________________________________________________________________________________________________________________________________________________

	void addToMenu(Pizza);

	void removeFromMenu(int);
*/
};

#endif

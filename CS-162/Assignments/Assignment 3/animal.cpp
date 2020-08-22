#include "animal.h"

//-Default Constructor-Copy Constructor-Assignment Operator Overload-Destructor-------

//Default Constructor
Animal::Animal()
{
	age_in_months = 24;
	number_of_possible_babies = 1;
		
	monthly_revenue = 1000;
	monthly_food_cost = 100;

	market_price = 1000;
	sell_price = 500; 
}

//Copy Constructor		
Animal::Animal(const Animal & previous_animal)
{
	//Not really necessary but did it anyway.
	this->age_in_months = previous_animal.age_in_months;
	this->number_of_possible_babies = previous_animal.number_of_possible_babies;
		
	this->monthly_revenue = previous_animal.monthly_revenue;
	this->monthly_food_cost = previous_animal.monthly_food_cost;

	this->market_price = previous_animal.market_price;
	this->sell_price = previous_animal.sell_price; 
}

//Assignment operator overload
Animal & Animal::operator = (const Animal & previous_animal)
{
	//Not really necessary but did it anyway.
	this->age_in_months = previous_animal.age_in_months;
	this->number_of_possible_babies = previous_animal.number_of_possible_babies;
		
	this->monthly_revenue = previous_animal.monthly_revenue;
	this->monthly_food_cost = previous_animal.monthly_food_cost;

	this->market_price = previous_animal.market_price;
	this->sell_price = previous_animal.sell_price; 
}

//Destructor
Animal::~Animal()
{

}

//-Accessors-Mutators-----------------------------------------------------------------

//Age_________________________________________________________________________________

void Animal::set_age_in_months(const int age)
{
	this->age_in_months = age;
	return;
}

const int Animal::get_age_in_months()
{
	return this->age_in_months;
}

//Number Of Possible Babies___________________________________________________________
		
void Animal::set_number_of_possible_babies(const int number)
{
	this->number_of_possible_babies = number;
	return;
}

const int Animal::get_number_of_possible_babies()
{
	return this->number_of_possible_babies;
}

//Monthly Revenue_____________________________________________________________________

void Animal::set_monthly_revenue(const int revenue)
{
	this->monthly_revenue = revenue;
	return;
}

const int Animal::get_monthly_revenue()
{
	return this->monthly_revenue;
}
		
//Monthly Food Cost___________________________________________________________________
	
void Animal::set_monthly_food_cost(const int cost)
{
	this->monthly_food_cost = cost;	
	return;
}

const int Animal::get_monthly_food_cost()
{
	return this->monthly_food_cost;
}

//Market Price________________________________________________________________________

void Animal::set_market_price(const int price)
{
	this->market_price = price;	
	return;
}

const int Animal::get_market_price()
{
	return this->market_price;
}

//Sell Price__________________________________________________________________________

void Animal::set_sell_price(const int price)
{
	this->sell_price = price;
	return;
}

const int Animal::get_sell_price()
{
	return this->sell_price;
}






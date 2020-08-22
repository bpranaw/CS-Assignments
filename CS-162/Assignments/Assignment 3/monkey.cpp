#include "monkey.h"

//-Default Constructor-Copy Constructor-Assignment Operator Overload-Destructor-------

//Default Constructor
Monkey::Monkey()
{
	//This are the only factors that need to be edited from the animal class
	
	set_monthly_revenue(1500);
	set_monthly_food_cost(4);

	set_market_price(15000);
	set_sell_price(7500); 
}

//Copy Constructor		
Monkey::Monkey(Monkey & previous_monkey)
{
	//These aren't really necessary but did them anything
	int age = previous_monkey.get_age_in_months();
	
	set_age_in_months(age);
	set_number_of_possible_babies(previous_monkey.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_monkey.get_monthly_revenue());
	set_monthly_food_cost(previous_monkey.get_monthly_food_cost());

	set_market_price(previous_monkey.get_market_price());
	set_sell_price(previous_monkey.get_sell_price()); 
}

Monkey & Monkey::operator = (Monkey & previous_monkey)
{
	//These aren't really necessary but did them anyway.
	
	set_age_in_months(previous_monkey.get_age_in_months());
	set_number_of_possible_babies(previous_monkey.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_monkey.get_monthly_revenue());
	set_monthly_food_cost(previous_monkey.get_monthly_food_cost());

	set_market_price(previous_monkey.get_market_price());
	set_sell_price(previous_monkey.get_sell_price()); 
}

//Destructor
Monkey::~Monkey()
{

}










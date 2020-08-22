#include "sloth.h"

//-Default Constructor-Copy Constructor-Assignment Operator Overload-Destructor-------

//Default Constructor
Sloth::Sloth()
{
	//This are the only factors that need to be edited from the animal class
	
	set_monthly_revenue(100);
	set_monthly_food_cost(1);

	set_market_price(2000);
	set_sell_price(1000); 
}

//Copy Constructor		
Sloth::Sloth(Sloth & previous_sloth)
{
	//These aren't really necessary but did them anything
	int age = previous_sloth.get_age_in_months();
	
	set_age_in_months(age);
	set_number_of_possible_babies(previous_sloth.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_sloth.get_monthly_revenue());
	set_monthly_food_cost(previous_sloth.get_monthly_food_cost());

	set_market_price(previous_sloth.get_market_price());
	set_sell_price(previous_sloth.get_sell_price()); 
}

Sloth & Sloth::operator = (Sloth & previous_sloth)
{
	//These aren't really necessary but did them anyway.
	
	set_age_in_months(previous_sloth.get_age_in_months());
	set_number_of_possible_babies(previous_sloth.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_sloth.get_monthly_revenue());
	set_monthly_food_cost(previous_sloth.get_monthly_food_cost());

	set_market_price(previous_sloth.get_market_price());
	set_sell_price(previous_sloth.get_sell_price()); 
}

//Destructor
Sloth::~Sloth()
{

}



#include "polar_bear.h"

//-Default Constructor-Copy Constructor-Assignment Operator Overload-Destructor-------

//Default Constructor
Polar_Bear::Polar_Bear()
{
	//This are the only factors that need to be edited from the animal class
	
	set_monthly_revenue(5000);
	set_monthly_food_cost(3);

	set_market_price(100000);
	set_sell_price(50000); 
}

//Copy Constructor		
Polar_Bear::Polar_Bear(Polar_Bear & previous_bear)
{
	//These aren't really necessary but did them anyway for practice
	int age = previous_bear.get_age_in_months();
	
	set_age_in_months(age);
	set_number_of_possible_babies(previous_bear.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_bear.get_monthly_revenue());
	set_monthly_food_cost(previous_bear.get_monthly_food_cost());

	set_market_price(previous_bear.get_market_price());
	set_sell_price(previous_bear.get_sell_price()); 
}

Polar_Bear & Polar_Bear::operator = (Polar_Bear & previous_bear)
{
	//These aren't really necessary but did them anyway.
	
	set_age_in_months(previous_bear.get_age_in_months());
	set_number_of_possible_babies(previous_bear.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_bear.get_monthly_revenue());
	set_monthly_food_cost(previous_bear.get_monthly_food_cost());

	set_market_price(previous_bear.get_market_price());
	set_sell_price(previous_bear.get_sell_price()); 
}

//Destructor
Polar_Bear::~Polar_Bear()
{

}


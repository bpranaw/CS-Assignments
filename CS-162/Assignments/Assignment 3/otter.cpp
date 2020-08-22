#include "otter.h"

//-Default Constructor-Copy Constructor-Assignment Operator Overload-Destructor-------

//Default Constructor
Otter::Otter()
{
	//This are the only factors that need to be edited from the animal class
	
	set_monthly_revenue(250);
	set_monthly_food_cost(2);

	set_market_price(5000);
	set_sell_price(2500); 
}

//Copy Constructor		
Otter::Otter(Otter & previous_otter)
{
	//These aren't really necessary but did them anything
	int age = previous_otter.get_age_in_months();
	
	set_age_in_months(age);
	set_number_of_possible_babies(previous_otter.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_otter.get_monthly_revenue());
	set_monthly_food_cost(previous_otter.get_monthly_food_cost());

	set_market_price(previous_otter.get_market_price());
	set_sell_price(previous_otter.get_sell_price()); 
}

Otter & Otter::operator = (Otter & previous_otter)
{
	//These aren't really necessary but did them anyway.
	
	set_age_in_months(previous_otter.get_age_in_months());
	set_number_of_possible_babies(previous_otter.get_number_of_possible_babies());
		
	set_monthly_revenue(previous_otter.get_monthly_revenue());
	set_monthly_food_cost(previous_otter.get_monthly_food_cost());

	set_market_price(previous_otter.get_market_price());
	set_sell_price(previous_otter.get_sell_price()); 
}

//Destructor
Otter::~Otter()
{

}




#include "animal.h"
#include "monkey.h"
#include "otter.h"
#include "sloth.h"
#include "polar_bear.h"
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>

class Zoo
{
	private:
		Monkey * monkey_array;
		int number_of_monkeys;

		Otter * otter_array;
		int number_of_otters;

		Sloth * sloth_array;
		int number_of_sloths;

		Polar_Bear * polar_bear_array;
		int number_of_polar_bears;

		int month;
	
		float bank_value, food_cost;

		int reduce_sick_factor;
		

	public:
	
//_________________________Constructors/Destructor___________________________________

	//There's only ever going to be one zoo so the Big three aren't necessary

	Zoo();

	~Zoo();


//_________________________Accessors/Mutators________________________________________
//In hindsight I realized there are quite unnecessary.


//Monkey

	const Monkey* get_monkey_array();

	void set_number_of_monkeys(const int);
	const int get_number_of_monkeys();

//Otters

	const Otter * get_otter_array();

	void set_number_of_otters(const int);
	const int get_number_of_otters();

//Sloth

	const Sloth * get_sloth_array();

	void set_number_of_sloths(const int);
	const int get_number_of_sloths();

//Polar Bears
	
	const Polar_Bear * get_polar_bear_array();

	void set_number_of_polar_bears(const int);
	const int get_number_of_polar_bears();

//Bank
	void set_bank_value(const float);
	const float get_bank_value();

//Food Cost

	void set_food_cost(const float);
	const float get_food_cost();

//Month

	void set_months(const int);
	const int get_months();

//_________________________Turn Components___________________________________________

	bool play_game();

	bool turn_part_one_and_two();
	bool am_returning_to_home_screen();
	void increase_age();
	float calculate_revenue();

	void turn_special_event();
	int calculate_random();
	void find_sick_animal();

	void find_pregnant_animal();
	bool monkey_has_adult();
	bool otter_has_adult();
	bool sloth_has_adult();
	bool polar_bear_has_adult();
	
	void monkey_is_pregnant();
	void otter_is_pregnant();
	void sloth_is_pregnant();
	void polar_bear_is_pregnant();	

	void deal_with_sick_monkey();
	void deal_with_sick_otter();
	void deal_with_sick_sloth();
	void deal_with_sick_polar_bear();
	
	void remove_monkey(int);
	void remove_otter(int);
	void remove_sloth(int);
	void remove_polar_bear(int);

	void turn_buy_animals();
	
	void buy_monkey();
	bool hasMoney(float);
	void add_monkey();

	void buy_otter();
	void add_otter();

	void buy_sloth();
	void add_sloth();

	void buy_polar_bear();
	void add_polar_bear();

	void turn_sell_animals();
	void sell_monkey();
	void sell_otter();
	void sell_sloth();
	void sell_polar_bear();

	void turn_feeding();
	float calculate_food_cost(float);

	void display_animals();

};





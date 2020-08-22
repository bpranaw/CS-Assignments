#include "zoo.h"

//There's only ever going to be one zoo so the Big three aren't necessary

//DEFAULT CONSTRUCTOR
Zoo::Zoo()
{
	this->monkey_array = NULL;
	this->number_of_monkeys = 0;	

	this->otter_array = NULL;
	this->number_of_otters = 0;	

	this->sloth_array = NULL;
	this->number_of_sloths = 0;	

	this->polar_bear_array = NULL;
	this->number_of_polar_bears = 0;	

	this->bank_value = 50000;
	this->food_cost = 100;
	this->month = 0;	
	

	srand(time(NULL));
	
	this->reduce_sick_factor = 0;
}

//DESTRUCTOR
Zoo::~Zoo()
{
	if(monkey_array != NULL)
		delete[] this->monkey_array;
	if(otter_array != NULL)
		delete[] this->otter_array;
	if(sloth_array != NULL)
		delete[] this->sloth_array;
	if(polar_bear_array != NULL)
		delete[] this->polar_bear_array;	
}

//_________________________Accessors/Mutators________________________________________

/*************************************************************************************
 * Name: set_monkey_array
 * Description: Takes in an animal array of a certain size, makes the monkey array
 * 		into a copy of that array and sets the monkey pointer to that array.
 * Inputs: The array that with the values that will become the new monkey array 
 * 		(Animal *)
 * 	   The length of the array (int)
 * Outputs: N/A
 ************************************************************************************/
/*
void Zoo::set_monkey_array(const Monkey * animal_pointer, const int number_of_animals)
{
	this->monkey_array = new Monkey[number_of_animals];
	
	for(int i = 0; i < number_of_animals; i++)
		this->monkey_array[i] = animal_pointer[i];
	return;
}
*/
/*************************************************************************************
 * Name: get_monkey_array
 * Description: Returns the pointer to the monkey array
 * Inputs: N/A
 * Outputs: The pointer to the monkey array (Animal*)
 ************************************************************************************/
const Monkey* Zoo::get_monkey_array()
{
	return this->monkey_array;
}

/*************************************************************************************
 * Name: set_number_of_monkeys
 * Description: Takes in a number and sets the number of monkeys to that number
 * Inputs: The number of animals (int)
 * Outputs: N/A
 ************************************************************************************/
void Zoo::set_number_of_monkeys(const int number_of_animals)
{
	this->number_of_monkeys = number_of_animals;
	return;
}

/*************************************************************************************
 * Name: get_number_of_monkeys
 * Description: Returns the number of Monkeys
 * Inputs: N/A
 * Outputs: The number of monkeys
 ************************************************************************************/
const int Zoo::get_number_of_monkeys()
{
	return this->number_of_monkeys;
}

/*************************************************************************************
 * Name: set_otter_array
 * Description: Takes in an animal array and number of animals. Sets the zoo's array
 * 		equal to the pointer array.
 * Inputs: The pointer to the array of animals (int)
 * 	   Thea number of animals (int)
 * Outputs: N/A
 ************************************************************************************/
/*
void Zoo::set_otter_array(const Otter * animal_pointer, const int number_of_animals)
{
	this->otter_array = new Otter[number_of_animals];
	
	for(int i = 0; i < number_of_animals; i++)
		this->otter_array[i] = animal_pointer[i];
	return;
}
*/
/*************************************************************************************
 * Name: get_otter_array
 * Description: Returns the pointer to the otter array
 * Inputs: N/A
 * Outputs: The pointer to the otter array (Animal*)
 ************************************************************************************/
const Otter * Zoo::get_otter_array()
{
	return this->otter_array;
}

/*************************************************************************************
 * Name: set_number_of_otters
 * Description: Takes in a number and sets the number of otters to that number
 * Inputs: The number of animals (int)
 * Outputs: N/A
 ************************************************************************************/
void Zoo::set_number_of_otters(const int number_of_animals)
{
	this->number_of_otters = number_of_animals;	
	return;
}

/*************************************************************************************
 * Name: get_number_of_otters
 * Description: Returns the number of otters
 * Inputs: N/A
 * Outputs: The number of otters (int)
 ************************************************************************************/
const int Zoo::get_number_of_otters()
{
	return this->number_of_otters;
}

/*************************************************************************************
 * Name: set_sloth_array 
 * Description: Takes in an animal array and number of animals. Sets the zoo's array
 * 		equal to the pointer array.
 * Inputs: The pointer to the array of animals (int)
 * 	   Thea number of animals (int)
 * Outputs: N/A
 ************************************************************************************/
/*
void  Zoo::set_sloth_array(const Sloth * animal_pointer, const int number_of_animals)
{
	this->sloth_array = new Sloth[number_of_animals];
	
	for(int i = 0; i < number_of_animals; i++)
		this->sloth_array[i] = animal_pointer[i];
	return;
}
*/
/*************************************************************************************
 * Name: get_sloth_array
 * Description: Returns the pointer to the solth array
 * Inputs: N/A
 * Outputs: The pointer to the sloth array (Animal)
 ************************************************************************************/
const Sloth * Zoo::get_sloth_array()
{
	return this->sloth_array;
}

/*************************************************************************************
 * Name: set_number_of_sloths 
 * Description: Takes in a number and sets the number of sloths to that number
 * Inputs: Number of animals (int)
 * Outputs: N/A
 ************************************************************************************/
void Zoo::set_number_of_sloths(const int number_of_animals)
{
	this->number_of_sloths = number_of_animals;
	return;
}

/*************************************************************************************
 * Name: get_number_of_sloths
 * Description: Returns the number of sloths
 * Inputs: N/A
 * Outputs: The number of sloths (int)
 ************************************************************************************/
const int Zoo::get_number_of_sloths()
{
	return this->number_of_sloths;
}

/*************************************************************************************
 * Name: 
 * Description: Takes in an animal array and number of animals. Sets the zoo's array
 * 		equal to the pointer array.
 * Inputs: The pointer to the array of animals (int)
 * 	   Thea number of animals (int)
 * Outputs: N/A
 ************************************************************************************/
/*
void Zoo::set_polar_bear_array(const Polar_Bear * animal_pointer, const int number_of_animals)
{
	this->polar_bear_array = new Polar_Bear[number_of_animals];
	
	for(int i = 0; i < number_of_animals; i++)
		this->polar_bear_array[i] = animal_pointer[i];
	return;
}
*/
/*************************************************************************************
 * Name: get_polar_bear_array
 * Description: Returns the pointer to the polar bear array
 * Inputs: N/A
 * Outputs: The pointer to the polar bear array (Animal*)
 ************************************************************************************/
const Polar_Bear * Zoo::get_polar_bear_array()
{
	return this->polar_bear_array;
}

/*************************************************************************************
 * Name: set_number_of_polar_bears
 * Description: Takes in the number and sets the number of polar bears to that
 * 		number
 * Inputs: Number of animals (int)
 * Outputs: N/A
 ************************************************************************************/
void Zoo::set_number_of_polar_bears(const int number_of_animals)
{
	this->number_of_polar_bears = number_of_animals;
	return;
}

/*************************************************************************************
 * Name: get_number_of_polar_bears
 * Description: Returns the number of polar bears
 * Inputs: N/A
 * Outputs: The number of polar bears (int)
 ************************************************************************************/
const int Zoo::get_number_of_polar_bears()
{
	return this->number_of_polar_bears;
}

/*************************************************************************************
 * Name: set_bank_value
 * Description: Sets the amount of money the person has in the bank in dollars
 * Inputs: The amount of money the person now has (float)
 * Outputs: N/A
 ************************************************************************************/
void Zoo::set_bank_value(const float money)
{
	this->bank_value = money;	
	return;
}

/*************************************************************************************
 * Name: get_bank_value
 * Description: Returns the amount of money in the bank in dollars
 * Inputs: N/A
 * Outputs: The money in the bank (float)
 ************************************************************************************/
const float Zoo::get_bank_value()
{
	return this->bank_value;
}

/*************************************************************************************
 * Name: set_food_cost
 * Description: Takes in food and sets the base price of food. 
 * Inputs: The updated base price of food.
 * Outputs: N/A
 ************************************************************************************/
void Zoo::set_food_cost(const float price)
{
	this->food_cost = price;
	return;
}

/*************************************************************************************
 * Name: get_food_cost
 * Description: Returns the base cost of the food
 * Inputs: N/A
 * Outputs: The base cost of the food (float)
 ************************************************************************************/
const float Zoo::get_food_cost()
{
	return this->food_cost;
}

/*************************************************************************************
 * Name: set_months
 * Description: Takes in the month it currently is and sets the zoo's variable to that
 * Inputs: The current count of months
 * Outputs: N/A
 ************************************************************************************/
void Zoo::set_months(const int number)
{
	this->month = number;
	return;	
}

/*************************************************************************************
 * Name: get_months
 * Description: Returns the current number of months
 * Inputs: N/A
 * Outputs: The current number of months
 ************************************************************************************/
const int Zoo::get_months()
{
	return this->month;
}

//_________________________Turn Components___________________________________________

/*************************************************************************************
 * Name: play_game 
 * Description: Plays through a turn of the game and returns true or false depending
 * 		on whether the person wants to keep playing or leave
 * Inputs: N/A
 * Outputs: Whether the person wants to stop playing or not (bool)
 ************************************************************************************/
bool Zoo::play_game()
{
	//Initiates the 1) and 2) parts of a turn
	//Additionall, checks to see if user is leaving
	bool am_returning = turn_part_one_and_two();
	if(am_returning)
		return true;
		
	turn_special_event();
	
	turn_buy_animals();

	turn_sell_animals();

	turn_feeding();
	
	return false;	
}

/*************************************************************************************
 * Name: turn_part_one_and_two
 * Description: Lets the user leave the game to the home screen or iniate the turn.
 * 		Then calls the function that increases the age of the animals in the
 * 		zoo.
 * 		Then calculates, displays, and distributes the revenue for each 
 * 		animal.
 *		If the user decides to leave the game, it will return true, else it
 *		will return false.
 * Inputs: N/A
 * Outputs: Whether the user is leaving or not
 ************************************************************************************/
bool Zoo::turn_part_one_and_two()
{
	//Tells the user what turn this is
	std::cout << std::endl << "********************************************************************************************\nTurn #" << this->month << std::endl << std::endl;

	//Displays the animals
	display_animals();

	//Returing to homescreen:
	bool am_returning = am_returning_to_home_screen();
	if(am_returning)
		return true;

	//Increases age of animals
	increase_age();

	//Displays the user's wealth
	float total_revenue = calculate_revenue();
	this->bank_value += total_revenue;
	std::cout << "Your zoo has made: $" << total_revenue << std::endl << "Your bank balance: $" << this->bank_value << std::endl;
	
		
	return false;
}


/*************************************************************************************
 * Name: am_returning_to_home_screen 
 * Description: Determines if the user is returning to the home screen
 * Inputs: N/A
 * Outputs: Whether the user is returning to the home screen (bool)
 ************************************************************************************/
bool Zoo::am_returning_to_home_screen()
{
	int choice = 2;

	std::cout << "Would you like to:\n1) Continue Playing\n2) Exit the game by returning to the home screen\n\nIf you enter an invalid value, your game will return by default." << std::endl;	

	std::cin >> choice;

	//Prompts the user's choice
	if(choice == 1)
		return false;
	else
	{
		std::cin.clear();
		std::cin.ignore(1000000, '\n');

		return true;
	}
	//Just in case it gets here somehow
	return false;	
}

/*************************************************************************************
 * Name: increase_age
 * Description: Increases the age of all the animals and adds one to the month
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::increase_age()
{
	//Length justification - It would be shorter if there wasn't a polar bear.
	//The entire function just does 1 thing anyhow, it's simple but since there
	//are multiple animals, it just takes a few lines

		

	//Checks to see if there are monkeys
	if(this->number_of_monkeys > 0)
	{
		for(int i = 0; i < number_of_monkeys; i++)
		{
			//Adds one to the age of the animal
			this->monkey_array[i].set_age_in_months(this->monkey_array[i].get_age_in_months() + 1);
		}	
	}

	//Checks to see of there are otters
	if(this->number_of_otters > 0)
	{
		//Increases their ages
		for(int i = 0; i < number_of_otters; i++)
		{
			this->otter_array[i].set_age_in_months(this->otter_array[i].get_age_in_months() + 1);
		}
	}

	//Checks to see if there are sloths
	if(this->number_of_sloths > 0)
	{
		//Increases their ages
		for(int i = 0; i < number_of_sloths; i++)
		{
			//Adds one to the age of the animal
			this->sloth_array[i].set_age_in_months(this->sloth_array[i].get_age_in_months() + 1);
		}
	}

	//Checks to see if there are polar bears
	if(this->number_of_polar_bears > 0)
	{
		//Increases their ages
		for(int i = 0; i < number_of_polar_bears; i++)
		{
			//Adds one to the age of the animal
			this->polar_bear_array[i].set_age_in_months(this->polar_bear_array[i].get_age_in_months() + 1);
		}
	}

	//Increases the month
	this->month += 1;

	return;
}

float Zoo::calculate_revenue()
{
	
	//Length Justification
	//This one looks long again but technically it is 13 lines
	//I used the terniary operator to differentiate between babies and adults to save some line
	//space with if-else statements
	//I just didn't want to have to make separate functions just because of the line requirements

	float total_revenue = 0;
	//Checks to see if there are monkeys
	if(this->number_of_monkeys > 0)
	{
		for(int i = 0; i < number_of_monkeys; i++)
		{
			//Differentiates between babies and adults
			//Then adds money into the toal accordingly
			(this->monkey_array[i].get_age_in_months() <= 6)? total_revenue += 2*(this->monkey_array[i].get_monthly_revenue()) : total_revenue += this->monkey_array[i].get_monthly_revenue();
		}	
	}

	//Checks to see of there are otters
	if(this->number_of_otters > 0)
	{
		//Increases their ages
		for(int i = 0; i < number_of_otters; i++)
		{
			//Differentiates between babies and adults
			//Then adds money into the toal accordingly
			(this->otter_array[i].get_age_in_months() <= 6)? total_revenue += 2*(this->otter_array[i].get_monthly_revenue()) : total_revenue += this->otter_array[i].get_monthly_revenue();
		}
	}

	//Checks to see if there are sloths
	if(this->number_of_sloths > 0)
	{
		//Increases their ages
		for(int i = 0; i < number_of_sloths; i++)
		{
			//Differentiates between babies and adults
			//Then adds money into the toal accordingly
			(this->sloth_array[i].get_age_in_months() <= 6)? total_revenue += 2*(this->sloth_array[i].get_monthly_revenue()) : total_revenue += this->sloth_array[i].get_monthly_revenue();
		}
	}

	//Checks to see if there are polar bears
	if(this->number_of_polar_bears > 0)
	{
		//Increases their ages
		for(int i = 0; i < number_of_polar_bears; i++)
		{
			//Differentiates between babies and adults
			//Then adds money into the toal accordingly
			(this->polar_bear_array[i].get_age_in_months() <= 6)? total_revenue += 2*(this->polar_bear_array[i].get_monthly_revenue()) : total_revenue += this->polar_bear_array[i].get_monthly_revenue();
		}
	}

	return total_revenue;
}

/*************************************************************************************
 * Name: turn_special_event
 * Description: A special event occurs (an animal gets sick, an adult gives birth,
 * 		a boom in attendence occurs, or nothing happens).
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::turn_special_event()
{
	//Calculates probability
	int probability = calculate_random();

	if(probability >= 0 && probability < 8 + this->reduce_sick_factor)
	{
		find_sick_animal();
	}
	else if(probability >= 16 && probability < 24)
	{
		std::cout << "\nAn animal might have been secretly pregnant this whole time!!!" << std::endl << std::endl << std::endl;
		find_pregnant_animal();
	}
	else if(probability >= 24 && probability < 32)
	{
		
		std::cout << "\nA boom in attendence occurred!!!" << std::endl << std::endl << std::endl;
		int bonus = (rand() % 400) + 300;
		set_bank_value(get_bank_value() + get_number_of_monkeys() * bonus);

		std::cout << "If you had any monkeys, they each would earn a bonus revenue of: $" << bonus << "\nResulting in a bank balance of: $" << get_bank_value() << std::endl;

	}
	else
		std::cout << std::endl << "No special event this turn...\n" << std::endl;
	return;
}

/*************************************************************************************
 * Name: calculate_random
 * Description: Calculates a random number between 0 and 40.
 * Inputs: N/A
 * Outputs: Returns the random number (int)
 ************************************************************************************/
int Zoo::calculate_random()
{
	int random = 0;
	
	random = rand() % 40;

	return random;	
}

/*************************************************************************************
 * Name: find_pregnant_animal
 * Description: Randomly chooses an adult for pregnancy
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::find_pregnant_animal()
{
	bool check = false;	

	if( !monkey_has_adult() && !otter_has_adult() && !sloth_has_adult() && !polar_bear_has_adult())
	{
		std::cout << "You have no pregnant animals because you have no adult animals" << std::endl;
		return;

	}
	else
	{
		while(!check)
		{
			int probability = rand() % 4;
		
			if(probability == 0 && monkey_has_adult())
			{
				monkey_is_pregnant();
				check = true;
			}
			else if(probability == 1 && otter_has_adult())
			{
				otter_is_pregnant();
				check = true;
			}		
			else if(probability == 2 && sloth_has_adult())
			{
				sloth_is_pregnant();
				check = true;
			}
			else if(probability == 3 && polar_bear_has_adult())
			{
				polar_bear_is_pregnant();
				check = true;
			}	
		}			
	}

	return;
	
}

/*************************************************************************************
 * Name: bool monkey_has_adult
 * Description: Checks to see if the specific species has an adult who magically gets
 * 		pregnant
 * Inputs: N/A
 * Outputs: Whether there is an adult or not (bool)
 ************************************************************************************/
bool Zoo::monkey_has_adult()
{
	bool check = false;

	//Checks to see if there are just monkeys in general
	if(get_number_of_monkeys() > 0)
	{
		//Goes through all the monkeys
		for(int i = 0; i < get_number_of_monkeys(); i++)
		{
			//Checks for an adult
			if(this->monkey_array[i].get_age_in_months() > 23)
				check = true;		
		}
	}

	return check;	
}

/*************************************************************************************
 * Name: monkey_is_pregnant() 
 * Description: Deals with the situation where a monkey is pregnant
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::monkey_is_pregnant()
{
	std::cout << "\nYour monkey gave birth to 1 baby(s)!!!!!!!!!\n" << std::endl;
	add_monkey();
	this->monkey_array[get_number_of_monkeys() - 1].set_age_in_months(0);
}

/*************************************************************************************
 * Name: bool otter_has_adult
 * Description: Checks to see if the specific species has an adult who magically gets
 * 		pregnant
 * Inputs: N/A
 * Outputs: Whether there is an adult or not (bool)
 ************************************************************************************/
bool Zoo::otter_has_adult()
{
	bool check = false;

	//Checks to see if there are just otterss in general
	if(get_number_of_otters() > 0)
	{
		//Goes through all the otterss
		for(int i = 0; i < get_number_of_otters(); i++)
		{
			//Checks for an adult
			if(this->otter_array[i].get_age_in_months() > 23)
				check = true;		
		}
	}

	return check;	
}

/*************************************************************************************
 * Name: otter_is_pregnant() 
 * Description: Deals with the situation where an otter is pregnant
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::otter_is_pregnant()
{
	//Messages the user
	std::cout << "\nYour otter gave birth to 2 baby(s)!!!!!!!!!\n" << std::endl;
	
	//Makes the babies
	add_otter();
	add_otter();

	//Sets the babies' ages to zero
	this->otter_array[get_number_of_otters() - 1].set_age_in_months(0);
	this->otter_array[get_number_of_otters() - 2].set_age_in_months(0);

}

/*************************************************************************************
 * Name: bool sloth_has_adult
 * Description: Checks to see if the specific species has an adult who magically gets
 * 		pregnant
 * Inputs: N/A
 * Outputs: Whether there is an adult or not (bool)
 ************************************************************************************/
bool Zoo::sloth_has_adult()
{
	bool check = false;

	//Checks to see if there are just sloths in general
	if(get_number_of_sloths() > 0)
	{
		//Goes through all the sloths
		for(int i = 0; i < get_number_of_sloths(); i++)
		{
			//Checks for an adult
			if(this->sloth_array[i].get_age_in_months() > 23)
				check = true;		
		}
	}

	return check;	
}

/*************************************************************************************
 * Name: sloth_is_pregnant() 
 * Description: Deals with the situation where a sloth is pregnant
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::sloth_is_pregnant()
{
	//Messages the user
	std::cout << "\nYour sloth gave birth to 5 baby(s)!!!!!!!!!\n" << std::endl;
	
	//Makes the babies
	add_sloth();
	add_sloth();
	add_sloth();
	add_sloth();
	add_sloth();

	//Makes the babies young
	for(int i = 1; i < 6; i++)
	{
		this->sloth_array[get_number_of_sloths() - i].set_age_in_months(0);
	}
}

/*************************************************************************************
 * Name: bool polar_bear_has_adult
 * Description: Checks to see if the specific species has an adult who magically gets
 * 		pregnant
 * Inputs: N/A
 * Outputs: Whether there is an adult or not (bool)
 ************************************************************************************/
bool Zoo::polar_bear_has_adult()
{
	bool check = false;

	//Checks to see if there are just polar bears in general
	if(get_number_of_polar_bears() > 0)
	{
		//Goes through all the polar bears
		for(int i = 0; i < get_number_of_polar_bears(); i++)
		{
			//Checks for an adult
			if(this->polar_bear_array[i].get_age_in_months() > 23)
				check = true;		
		}
	}

	return check;	
}

/*************************************************************************************
 * Name: polar_bear_is_pregnant() 
 * Description: Deals with the situation where a polar bear is pregnant
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::polar_bear_is_pregnant()
{
	std::cout << "\nYour polar bear gave birth to 1 baby(s)!!!!!!!!!\n" << std::endl;
	add_polar_bear();

	this->polar_bear_array[get_number_of_polar_bears() - 1].set_age_in_months(0);
}
/*************************************************************************************
 * Name: find_sick_animal 
 * Description: Determines which animal is sick and calls the appropriate function
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::find_sick_animal()
{
	bool check = false;

	if((get_number_of_monkeys() + get_number_of_sloths() + get_number_of_polar_bears()) == 0)
	{
		std::cout << "You have no sick animals because you have no animals" << std::endl;
		return;

	}
	else
	{
		while(!check)
		{
			int probability = rand() % 4;
		
			if(probability == 0 && get_number_of_monkeys() > 0)
			{
				deal_with_sick_monkey();
				check = true;
			}
			else if(probability == 1 && get_number_of_otters() > 0)
			{
				deal_with_sick_otter();
				check = true;
			}		
			else if(probability == 2 && get_number_of_sloths() > 0)
			{
				deal_with_sick_sloth();
				check = true;
			}
			else if(probability == 3 && get_number_of_polar_bears() > 0)
			{
				deal_with_sick_polar_bear();
				check = true;
			}
	
		}			
	}

	return;
	
}

/*************************************************************************************
 * Name: deal_with_sick_monkey 
 * Description: Calculates the cost of the sick monkey and takes appropriate action.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::deal_with_sick_monkey()
{
	float sick_price = 0;
	
	//Chooses the sick monkey
	int animal = rand() % get_number_of_monkeys();

	if(this->monkey_array[animal].get_age_in_months() < 7)
		sick_price = 15000;
	else
		sick_price = 7500;
	
	//Checks to see if they have the money
	if(get_bank_value() > sick_price)
	{
		set_bank_value(get_bank_value()-sick_price);

		std::cout << std::endl << "Your monkey has been saved!!!\nIt cost $" << sick_price << " to save your monkey.\n" << "New bank balance: $" << get_bank_value() << std::endl;
		
	}	
	else
	{
		std::cout << "Your monkey has died" << std::endl;
		remove_monkey(animal);
	}

}

/*************************************************************************************
 * Name: remove_monkey
 * Description: Removes an animal from the specific species 
 * Inputs: The index of the animal that is going to be removed.
 * Outputs: N/A
 ************************************************************************************/
void Zoo::remove_monkey(int index)
{	
	int new_counter = 0;

	Monkey * old_array = this->monkey_array;
	
	this->monkey_array = new Monkey[get_number_of_monkeys()];
	
	for(int i = 0; i < get_number_of_monkeys(); i++)
	{
		if(i != index)
		{
			this->monkey_array[new_counter] = old_array[i];
			new_counter++;
		}
	}

	set_number_of_monkeys(get_number_of_monkeys() - 1);
	
	//Frees the space of the old array
	delete[] old_array;
	old_array = NULL;
}

/*************************************************************************************
 * Name: deal_with_sick_otter 
 * Description: Calculates the cost of the sick otter and takes appropriate action.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::deal_with_sick_otter()
{
	float sick_price = 0;
	
	//Chooses the sick otter
	int animal = rand() % get_number_of_otters();

	if(this->otter_array[animal].get_age_in_months() < 7)
		sick_price = 5000;
	else
		sick_price = 2500;
	
	//Checks to see if they have the money
	if(get_bank_value() > sick_price)
	{
		set_bank_value(get_bank_value()-sick_price);

		std::cout << std::endl << "Your otter has been saved!!!\nIt cost $" << sick_price << " to save your otter.\n" << "New bank balance: $" << get_bank_value() << std::endl;
		
	}	
	else
	{
		std::cout << "Your otter has died" << std::endl;
		remove_otter(animal);
	}

}

/*************************************************************************************
 * Name: remove_otter
 * Description: Removes an animal from the specific species 
 * Inputs: The index of the animal that is going to be removed.
 * Outputs: N/A
 ************************************************************************************/
void Zoo::remove_otter(int index)
{	
	int new_counter = 0;

	Otter * old_array = this->otter_array;
	
	this->otter_array = new Otter[get_number_of_otters()];
	
	for(int i = 0; i < get_number_of_otters(); i++)
	{
		if(i != index)
		{
			this->otter_array[new_counter] = old_array[i];
			new_counter++;
		}
	}

	set_number_of_otters(get_number_of_otters() - 1);
	//Frees the space of the old array
	delete[] old_array;
	old_array = NULL;
}

/*************************************************************************************
 * Name: deal_with_sick_sloth 
 * Description: Calculates the cost of the sick sloth and takes appropriate action.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::deal_with_sick_sloth()
{
	float sick_price = 0;
	
	//Chooses the sick sloth
	int animal = rand() % get_number_of_sloths();

	if(this->sloth_array[animal].get_age_in_months() < 7)
		sick_price = 2000;
	else
		sick_price = 1000;
	
	//Checks to see if they have the money
	if(get_bank_value() > sick_price)
	{
		set_bank_value(get_bank_value()-sick_price);

		std::cout << std::endl << "Your sloth has been saved!!!\nIt cost $" << sick_price << " to save your sloth.\n" << "New bank balance: $" << get_bank_value() << std::endl;
		
	}	
	else
	{
		std::cout << "Your sloth has died" << std::endl;
		remove_sloth(animal);
	}

}

/*************************************************************************************
 * Name: remove_sloth
 * Description: Removes an animal from the specific species 
 * Inputs: The index of the animal that is going to be removed.
 * Outputs: N/A
 ************************************************************************************/
void Zoo::remove_sloth(int index)
{	
	int new_counter = 0;

	Sloth * old_array = this->sloth_array;
	
	this->sloth_array = new Sloth[get_number_of_sloths()];
	
	for(int i = 0; i < get_number_of_sloths(); i++)
	{
		if(i != index)
		{
			this->sloth_array[new_counter] = old_array[i];
			new_counter++;
		}
	}

	set_number_of_sloths(get_number_of_sloths() - 1);
	
	//Frees the space of the old array
	delete[] old_array;
	old_array = NULL;
}

/*************************************************************************************
 * Name: deal_with_sick_polar_bear 
 * Description: Calculates the cost of the sick bear and takes appropriate action.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::deal_with_sick_polar_bear()
{
	float sick_price = 0;
	
	//Chooses the sick polar_bear
	int animal = rand() % get_number_of_polar_bears();

	if(this->polar_bear_array[animal].get_age_in_months() < 7)
		sick_price = 15000;
	else
		sick_price = 7500;
	
	//Checks to see if they have the money
	if(get_bank_value() > sick_price)
	{
		set_bank_value(get_bank_value()-sick_price);

		std::cout << std::endl << "Your polar bear has been saved!!!\nIt cost $" << sick_price << " to save your polar bear.\n" << "New bank balance: $" << get_bank_value() << std::endl;
		
	}	
	else
	{
		std::cout << "Your polar bear has died" << std::endl;
		remove_polar_bear(animal);
	}

}

/*************************************************************************************
 * Name: remove_polar_bear
 * Description: Removes an animal from the specific species 
 * Inputs: The index of the animal that is going to be removed.
 * Outputs: N/A
 ************************************************************************************/
void Zoo::remove_polar_bear(int index)
{	
	int new_counter = 0;

	Polar_Bear * old_array = this->polar_bear_array;
	
	this->polar_bear_array = new Polar_Bear[get_number_of_polar_bears()];
	
	for(int i = 0; i < get_number_of_polar_bears(); i++)
	{
		if(i != index)
		{
			this->polar_bear_array[new_counter] = old_array[i];
			new_counter++;
		}
	}


	set_number_of_polar_bears(get_number_of_polar_bears() - 1);

	//Frees the space of the old array
	delete[] old_array;
	old_array = NULL;
}

/*************************************************************************************
 * Name: turn_buy_animals 
 * Description: Let's the player buy animals
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::turn_buy_animals()
{
	int choice;

	std::cout << "What would you like to do\n1) Buy Nothing\n2) Buy Monkeys ($15,000)\n3) Buy Otters ($5,000)\n4) Buy Sloths ($2,000)\n5) Buy Polar Bears ($100,000)\nAny invalid choice will be treated as buying nothing. " << std::endl;
	
	std::cin >> choice;

	if(choice == 2)
	{
		buy_monkey();
	}
	else if(choice == 3)
	{
		buy_otter();
	}
	else if(choice == 4)
	{
		buy_sloth();
	}
	else if(choice == 5)
	{
		buy_polar_bear();	
	}
	else
		return;		

	return;
}

/*************************************************************************************
 * Name: hasMoney 
 * Description: Checks to see if the player has the specified amount of money
 * Inputs: The money required (float)
 * Outputs: Whether or not the player has it (bool)
 ************************************************************************************/
bool Zoo::hasMoney(float money)
{
	if(money > get_bank_value())
	{
		std::cout << "You don't have enough money for this purchase." << std::endl;
		return false;
	}

	return true;

}

/*************************************************************************************
 * Name: buy_monkey
 * Description: Asks the user how many of the said animal they want to buy
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::buy_monkey()
{
	std::cout << "Do you want to buy one or two? Any incorrect entry will be treated as buying none.\nAdditionally, if you don't have enough money, your buy will be invalidated." << std::endl;
	int choice = 0;
	
	std::cin >> choice;

	if(choice == 1 && hasMoney(15000))
	{
		add_monkey();
		set_bank_value(get_bank_value() - 15000);
		std::cout << "One monkey has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else if(choice == 2 && hasMoney(30000))
	{
		add_monkey();
		add_monkey();

		set_bank_value(get_bank_value() - 30000);
		std::cout << "Two monkeys has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else
	{
		std::cout << "Purchasing nothing" << std::endl;
		return;
	}
}

/*************************************************************************************
 * Name: add_monkey
 * Description: Updates the animal array specified to have one more animal in it
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::add_monkey()
{
	Monkey * old_array = this->monkey_array;
	
	this->monkey_array = new Monkey[get_number_of_monkeys() + 1];

	for(int i = 0; i < get_number_of_monkeys(); i++)
	{
		this->monkey_array[i] = old_array[i];
	}

	set_number_of_monkeys(get_number_of_monkeys() + 1);
	
	delete[] old_array;
	old_array = NULL;

	return;
}

/*************************************************************************************
 * Name: buy_otter
 * Description: Asks the user how many of the said animal they want to buy
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::buy_otter()
{
	std::cout << "Do you want to buy one or two? Any incorrect entry will be treated as buying none.\nAdditionally, if you don't have enough money, your buy will be invalidated." << std::endl;
	int choice = 0;
	
	std::cin >> choice;

	if(choice == 1 && hasMoney(15000))
	{
		add_otter();
		set_bank_value(get_bank_value() - 15000);
		std::cout << "One otter has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else if(choice == 2 && hasMoney(30000))
	{
		add_otter();
		add_otter();

		set_bank_value(get_bank_value() - 30000);
		std::cout << "Two otters has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else
	{
		std::cout << "Purchasing nothing" << std::endl;
		return;
	}
}

/*************************************************************************************
 * Name: add_otter
 * Description: Updates the animal array specified to have one more animal in it
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::add_otter()
{
	Otter * old_array = this->otter_array;
	
	this->otter_array = new Otter[get_number_of_otters() + 1];

	for(int i = 0; i < get_number_of_otters(); i++)
	{
		this->otter_array[i] = old_array[i];
	}

	set_number_of_otters(get_number_of_otters() + 1);
	
	delete[] old_array;
	old_array = NULL;

	return;
}

/*************************************************************************************
 * Name: buy_sloth
 * Description: Asks the user how many of the said animal they want to buy
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::buy_sloth()
{
	std::cout << "Do you want to buy one or two? Any incorrect entry will be treated as buying none.\nAdditionally, if you don't have enough money, your buy will be invalidated." << std::endl;
	int choice = 0;
	
	std::cin >> choice;

	if(choice == 1 && hasMoney(1000))
	{
		add_sloth();
		set_bank_value(get_bank_value() - 1000);
		std::cout << "One sloth has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else if(choice == 2 && hasMoney(2000))
	{
		add_sloth();
		add_sloth();

		set_bank_value(get_bank_value() - 2000);
		std::cout << "Two sloths has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else
	{
		std::cout << "Purchasing nothing" << std::endl;
		return;
	}
}

/*************************************************************************************
 * Name: add_sloth
 * Description: Updates the animal array specified to have one more animal in it
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::add_sloth()
{
	Sloth * old_array = this->sloth_array;
	
	this->sloth_array = new Sloth[get_number_of_sloths() + 1];

	for(int i = 0; i < get_number_of_sloths(); i++)
	{
		this->sloth_array[i] = old_array[i];
	}

	set_number_of_sloths(get_number_of_sloths() + 1);
	
	delete[] old_array;
	old_array = NULL;

	return;
}

/*************************************************************************************
 * Name: buy_polar_bear
 * Description: Asks the user how many of the said animal they want to buy
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::buy_polar_bear()
{
	std::cout << "Do you want to buy one or two? Any incorrect entry will be treated as buying none.\nAdditionally, if you don't have enough money, your buy will be invalidated." << std::endl;
	int choice = 0;
	
	std::cin >> choice;

	if(choice == 1 && hasMoney(100000))
	{
		add_polar_bear();
		set_bank_value(get_bank_value() - 100000);
		std::cout << "One polar bear has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else if(choice == 2 && hasMoney(200000))
	{
		add_polar_bear();
		add_polar_bear();

		set_bank_value(get_bank_value() - 200000);
		std::cout << "Two polar bear has been purchased! New Bank Balance: $" << get_bank_value() << std::endl;
	}
	else
	{
		std::cout << "Purchasing nothing" << std::endl;
		return;
	}
}

/*************************************************************************************
 * Name: add_polar_bear
 * Description: Updates the animal array specified to have one more animal in it
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::add_polar_bear()
{
	Polar_Bear * old_array = this->polar_bear_array;
	
	this->polar_bear_array = new Polar_Bear[get_number_of_polar_bears() + 1];

	for(int i = 0; i < get_number_of_polar_bears(); i++)
	{
		this->polar_bear_array[i] = old_array[i];
	}

	set_number_of_polar_bears(get_number_of_polar_bears() + 1);
	
	delete[] old_array;
	old_array = NULL;

	return;
}
/*************************************************************************************
 * Name: turn_sell_animals
 * Description: Prompts the user as to whether or not they want to sell animals
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::turn_sell_animals()
{

	int choice;

	std::cout << "What would you like to do\n1) Sell Nothing\n2) Sell Monkey ($7,500)\n3) Sell Otter ($2,500)\n4) Sell Sloth ($1,000)\n5) Sell Polar Bear ($50,000)\nAny invalid choice will be treated as selling nothing. " << std::endl;
	
	std::cin >> choice;

	if(choice == 2)
	{
		sell_monkey();
	}
	else if(choice == 3)
	{
		sell_otter();
	}
	else if(choice == 4)
	{
		sell_sloth();
	}
	else if(choice == 5)
	{
		sell_polar_bear();	
	}
	else
		return;		

	return;
}

/*************************************************************************************
 * Name: sell_monkey
 * Description: Let's the user sell a single monkey
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::sell_monkey()
{

	if(get_number_of_monkeys() > 0)
	{
		//Prompts the user
		std::cout << "Which monkey do you want to sell? They are listed by an index number and age. Any incorrect input will assume that you want to sell # 1." << std::endl;
		//Shows them their options
		for(int i = 0; i < get_number_of_monkeys(); i++)
		{
			std::cout << i + 1 << ") " << this->monkey_array[i].get_age_in_months() << std::endl;
		}

		int choice;
		
		//Let's them pick
		std::cin >> choice;

		//Makes sure they pick right
		if(!std::cin || choice > get_number_of_monkeys() || choice < 0)
			choice = 1;
		
		//Sells the monkey
		set_bank_value(get_bank_value() + this->monkey_array[0].get_sell_price());
		remove_monkey(choice - 1);

		std::cout << "That monkey has been sold!!!" << std::endl << std::endl;	
	}
	else
		std::cout << "You have none of this animal to sell" << std::endl;

	return;
}

/*************************************************************************************
 * Name: sell_otter
 * Description: Let's the user sell a single otter
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::sell_otter()
{

	if(get_number_of_otters() > 0)
	{
		//Prompts the user
		std::cout << "Which otter do you want to sell? They are listed by an index number and age. Any incorrect input will assume that you want to sell # 1." << std::endl;
		//Shows them their options
		for(int i = 0; i < get_number_of_otters(); i++)
		{
			std::cout << i + 1 << ") " << this->otter_array[i].get_age_in_months() << std::endl;
		}

		int choice;
		
		//Let's them pick
		std::cin >> choice;

		//Makes sure they pick right
		if(!std::cin || choice > get_number_of_otters() || choice < 0)
			choice = 1;
		
		//Sells the otters
		set_bank_value(get_bank_value() + this->otter_array[0].get_sell_price());
		remove_otter(choice - 1);

		std::cout << "That otter has been sold!!!" << std::endl << std::endl;	
	}
	else
		std::cout << "You have none of this animal to sell" << std::endl;

	return;
}

/*************************************************************************************
 * Name: sell_sloth
 * Description: Let's the user sell a single sloth
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::sell_sloth()
{

	if(get_number_of_sloths() > 0)
	{
		//Prompts the user
		std::cout << "Which sloth do you want to sell? They are listed by an index number and age. Any incorrect input will assume that you want to sell # 1." << std::endl;
		//Shows them their options
		for(int i = 0; i < get_number_of_sloths(); i++)
		{
			std::cout << i + 1 << ") " << this->sloth_array[i].get_age_in_months() << std::endl;
		}

		int choice;
		
		//Let's them pick
		std::cin >> choice;

		//Makes sure they pick right
		if(!std::cin || choice > get_number_of_sloths() || choice < 0)
			choice = 1;
		
		//Sells the sloth
		set_bank_value(get_bank_value() + this->sloth_array[0].get_sell_price());
		remove_sloth(choice - 1);

		std::cout << "That sloth has been sold!!!" << std::endl << std::endl;	
	}
	else
		std::cout << "You have none of this animal to sell" << std::endl;

	return;
}

/*************************************************************************************
 * Name: sell_polar_bear
 * Description: Let's the user sell a single polar bear
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::sell_polar_bear()
{

	if(get_number_of_polar_bears() > 0)
	{
		//Prompts the user
		std::cout << "Which polar bear do you want to sell? They are listed by an index number and age. Any incorrect input will assume that you want to sell # 1." << std::endl;
		//Shows them their options
		for(int i = 0; i < get_number_of_polar_bears(); i++)
		{
			std::cout << i + 1 << ") " << this->polar_bear_array[i].get_age_in_months() << std::endl;
		}

		int choice;
		
		//Let's them pick
		std::cin >> choice;

		//Makes sure they pick right
		if(!std::cin || choice > get_number_of_polar_bears() || choice < 0)
			choice = 1;
		
		//Sells the polar bear
		set_bank_value(get_bank_value() + this->polar_bear_array[0].get_sell_price());
		remove_polar_bear(choice - 1);

		std::cout << "That polar bear has been sold!!!" << std::endl << std::endl;	
	}
	else
		std::cout << "You have none of this animal to sell" << std::endl;

	return;
}
	
/*************************************************************************************
 * Name: turn_feeding
 * Description: Forces the play to buy food. They have three options.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::turn_feeding()
{
	std::cout << "\nYou must buy food for all your animals!!! You have three options.\n1) Regular\n2) Premium - Costs 2x as much but reduces probability of sickness\n3) Cheap - Costs (1/2)x as much but increases probability of sickness.\n\nAny invalid answers will be assumed to be regular food." << std::endl;

	int choice = 3;
	float cost = 0;
	float variability = (float((rand() % 50)*0.01)) + 0.75;
	set_food_cost(variability * get_food_cost());
	
	std::cout << "\nMonkeys have a 4x multiplier of the base cost, otters a 2x, sloths a 1x and polar bears a 3x.\n\nThe current base cost of a regular bag of feed is: $" << get_food_cost() << std::endl;

	std::cin >> choice;

	if(choice == 2)
	{
		this->reduce_sick_factor = -4;		
		cost = 2 * (calculate_food_cost(get_food_cost()));	
	}
	else if(choice == 3)
	{
		this->reduce_sick_factor = 8;		
		cost = 0.5 * (calculate_food_cost(get_food_cost()));	
	}
	else 
	{
		this->reduce_sick_factor = 0;		
		cost = calculate_food_cost(get_food_cost());	
	}

	return;
}

/*************************************************************************************
 * Name: calculate_food_cost 
 * Description: Takes in the current base cost, calculates the food cost based on teh
 * 		current animals, then returns the total cost.
 * Inputs: The current base cost (float)
 * Outputs: The cost of all the food (float)
 ************************************************************************************/
float Zoo::calculate_food_cost(float base_cost)
{
	float cost = 0;
	cost += get_number_of_monkeys() * 4 + get_number_of_otters() * 2;
	cost += get_number_of_sloths() * 1 + get_number_of_polar_bears() * 3;
	cost *= base_cost;

	return cost;
}

/*************************************************************************************
 * Name: display_animal 
 * Description: Displays each species of animals if they exist
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Zoo::display_animals()
{

	if(get_number_of_monkeys() > 0)
	{
		for(int i = 0; i < get_number_of_monkeys(); i++)
		{
			std::cout << i + 1 << ") Monkey, Age: " << this->monkey_array[i].get_age_in_months() << std::endl;
		}
	}

	if(get_number_of_otters() > 0)
	{
		for(int i = 0; i < get_number_of_otters(); i++)
		{
			std::cout << i + 1 << ") Otter, Age: " << this->otter_array[i].get_age_in_months() << std::endl;
		}
	}

	if(get_number_of_sloths() > 0)
	{
		for(int i = 0; i < get_number_of_sloths(); i++)
		{
			std::cout << i + 1 << ") Sloth, Age: " << this->sloth_array[i].get_age_in_months() << std::endl;
		}
	}

	if(get_number_of_polar_bears() > 0)
	{
		for(int i = 0; i < get_number_of_polar_bears(); i++)
		{
			std::cout << i + 1 << ") Polar Bear, Age: " << this->polar_bear_array[i].get_age_in_months() << std::endl;
		}
	}
	
	std::cout << "\nBank Balance: $" << get_bank_value() << std::endl << std::endl;
}
/*************************************************************************************
 * Name: 
 * Description:
 * Inputs: 
 * Outputs: 
 ************************************************************************************/

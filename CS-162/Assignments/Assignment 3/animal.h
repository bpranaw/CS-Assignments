#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	private:
		int age_in_months;
		int number_of_possible_babies;
		
		int monthly_revenue;
		int monthly_food_cost;

		int market_price;
		int sell_price; 

	public:
		//-Default Constructor-Copy Constructor-Assignment Operator Overload-Destructor-

		Animal();
		
		Animal(const Animal &);

		Animal & operator = (const Animal &);

		~Animal();

		//Age_________________________________________

		void set_age_in_months(const int);
		const int get_age_in_months();

		//Number Of Possible Babies___________________
		
		void set_number_of_possible_babies(const int);
		const int get_number_of_possible_babies();

		//Monthly Revenue_____________________________

		void set_monthly_revenue(const int);
		const int get_monthly_revenue();
		
		//Monthly Food Cost___________________________
	
		void set_monthly_food_cost(const int);
		const int get_monthly_food_cost();

		//Market Price________________________________
		
		void set_market_price(const int);
		const int get_market_price();

		//Sell Price__________________________________
		
		void set_sell_price(const int);
		const int get_sell_price();

};

#endif

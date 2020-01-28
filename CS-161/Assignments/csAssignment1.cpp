/************************************************************************************
 * AUTHOR:                                   					    *
 * 	Pranaw Bajracharya		                                            *
 * 	                                                                            *
 * PROGRAM NAME:                                                                    *
 *	Calculate Taxes (CS-161 Assignment 1)                                       *
 *                                                                                  *
 * DESCRIPTION:                                                                     *
 *	Takes user input to calculate yearly income, taxes, and remaining           *
 *	money for a car salesmen in 2017 or 2018, in states a, b, and c.            *
 *                                                                                  *
 * INPUTS:                                                                          *
 *	Monthly salary, price of a car, months worked in a year, misconducts        *
 *	occured in a year, number of cars sold in a year, tax year, and state       *
 *                                                                                  *
 * OUTPUTS:                                                                         *
 *	Gross income, personal  profit (2% of total profit), average selling price  *
 *	of a car, taxes, and remaining income.                                      *
 ************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
	/*
 * 	DECLARATION OF VARIABLES
 *
	monthlySalary = Amount of money made in a month
		Data type: float:  Reasoning- Salaries can go to the decimal places  because of cents

	carCost = Price of a car
		Data Type: float: Reasoning- Car prices can go to the decimal places because of cents

	monthsWorked = Number of months worked
		Data Type: float: Reasoning- Months can be represented in fractions and demicals;
		 however there should be a restriction of the number of months to 0-12, as you can not
		 have more 12 months and less than 0 months in a year.
 
	misconductObserved = Number of misconducts observed in the year
		Data Type: int: Reasoning- The number of misconducts is whole and discrete and thus can't be represented
		in fractions. You can not have half of an incident.

	carsSold = Number of cars sold in the year
		Data Type: int: Reasoning- The number of cars sold is whole and discrete and thus can't be presented in fractions.
		You can not legitimately sell half of a car.

	taxYear = the Year in question (for tax calculations)
		Data Type: int: Reasoning- Years are whole and discrete. 
		You can not have 2017.5 

	state = The state in which the user lives
		Data Type: char: Reasoning- State here is being represented by either a,b, or c.
	*/

	float monthlySalary, carCost, monthsWorked;
	int misconductsObserved, carsSold, taxYear;
	char state;
	
	
	//A value for the while loops that will make sure the user is inputting correct values
	bool check = false;
	
	//Loops the question to make sure the user inputs a valid value for monthlySalary (All other while loops serve similar functions in this program)
	while(check == false)
	{

		//Asks for the user's monthly salary and inputs the value in monthlySalary
		cout << "What's your monthly salary?" << endl;
		cin >> monthlySalary;
	
		//Insures that monthlySalary is not negative or something other than a number,  and and provides an explanation 
		//(which is why monthlySalary is signed instead of unsigned, so the user is not confused).
		if(monthlySalary < 0 || !cin)
		{
			//Handles the instances that are not numbers
			cin.clear();
			cin.ignore(1000000, '\n');
			
			//Informs the user what they did wrong
			cout << "Your monthly salary should be a number and also it should not be a negative number. This program does not factor in your debt. Try again." << endl;
		}
		else
		{
			check = true;
		}
	}
	
	//Assign check to be false so it can be used again for the next variable test.
	check = false;

	while(check == false)
	{
		cout << "What is the price of a car?" << endl;
		cin >> carCost;
	
	
		if(carCost < 0 || !cin)
		{
			//Handles the instances where the input is not a number
			cin.clear();
			cin.ignore(1000000, '\n');
			
			//Informs the user what they did wrong
			cout << "The price of the car should be a number and it also should not be a negative number. This program does not deal with car trade-ins. Try again." << endl;
		}
		else
		{
			check = true;
		}
	}
	
	//Assign check to be false so it can be used again for the next variable test
	check = false;
	
	while(check == false)
	{
		cout << "How many months did you you work in the last year?" << endl;
		cin >> monthsWorked;
	
		if(monthsWorked < 0 || monthsWorked > 12 || !cin)
		{
			//Handles the instances where the input is not a number
			cin.clear();
			cin.ignore(1000000, '\n');

			//Informs the user what they did wrong
			cout << "You couldn't have worked negative months or more than 12 months in a year. Also make sure you enter a number. Try again." << endl;
		}
		else
		{
			check = true;	
		}
	}
		
	//Assign check to be false so it can be used again for the next variable test
	check = false;

	while(check == false)
	{
		cout << "How many misconducts have occured this year?" << endl;
		cin >> misconductsObserved;
			
		if(misconductsObserved < 0 || !cin)
		{
			//Handles the instances where the input is not a number
			cin.clear();
			cin.ignore(1000000, '\n');
			
			//Informs the user what they did wrong
			cout << "The number of misconducts should indeed be a number value. Also you can't have observed negative misconducts. This program does not factor in good deeds. Try again." << endl;
		}
		else
		{
			check = true;
		}
	}

	//Assign check to be false so it can be used again for the next variable test
	check = false;

	while(check == false)
	{
		cout << "How many cars were sold last year?" << endl;
		cin >> carsSold;
		
		if(carsSold < 0 || !cin)
		{
			//Handles the instances where the input is not a number
			cin.clear();
			cin.ignore(1000000, '\n');
			
			//Informs the user what they did wrong
			cout << "You can't have sold negative cars. This program does not factor in car trade-ins. Try again." << endl;
		}
		else
		{
			check = true;
		}
	}

	//Assign check to be false so it can be used again for the next variable test
	check = false;
	
	while(check == false)
	{
		cout << "What tax year was it?" << endl;
		cin >> taxYear;
		
		switch(taxYear)
		{
			case 2017:
				check = true;
				break;
			case 2018:
				check = true;
				break;
			default:
				//Handles the cases where the input is not a number
				cin.clear();
				cin.ignore(1000000, '\n');

				cout << "Only the 2017 and 2018 tax years are factored. Try again." << endl;
				break;
		}
	}

	//Assign check to be false so it can be used again for the next variable
	
	check = false;

	while(check == false)
	{
		cout << "What state do you live in? Enter a, b, or c" << endl;
		cin >> state;
		
		switch(state)
		{
			case 'a':
				check = true;
				break;			
			case 'b':
				check = true;
				break;
			case 'c':
				check = true;
				break;
			default:

				//Handles the cases where input is not a number
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "This program only factors in states a, b, and c. Try again." << endl;
				break;			
		}
	}

	
	//CALCULATION OF GROSS INCOME
	
	/*Declaration of Gross income related  variable
		
		grossIncome = Total net income factoring in salary profit and deduction
			Data Type: float: Reasoning- Because cents exist, this variable needs to be able to incorporate decimal places

		annualSalary = Total salary in a year.
			Data Type: float: Reasoning- Cents exist, therefore decimal places must be incorporated.

		profit = Money made from cars sold
			Data Type: float: Reasoning- As car sales involve money, cents need to be incoporated through decimal places.

		deduction = money taken away due to misconducts that occured.
			Data Type: float: Reasoning- Money is involved, therefore cents need to be incorporated through decimal places.
	
	*/
	float grossIncome, annualSalary, profit, deduction;
	
	//Initializes the seed with the variable time
	srand(time(NULL));
	
	//Random variable is calculated for a random average car selling price (between 105% or 110%
	float x = (105 + rand() % 5);
	
	//After a bit of testing, I've found for some reason it doesn't work unless I divde the 100 out of the x like this 
	//(to produce a value between 1.05 and 1.10)
	x /= 100;

	//Profit is calculated
	profit = carsSold * ((carCost * x) - carCost);
	
	//Calculates deduction (which is 0 if no misconducts are observed)
	if(misconductsObserved  == 0)
		deduction = 0;
	else
		deduction = 100 * pow(2, misconductsObserved - 1);
	
	//Annual Salary Calculation		
	annualSalary = monthlySalary * monthsWorked;
	
	//Gross income calculation (using the equation)
	grossIncome = annualSalary + (0.02 * profit) - deduction;
	
	/*TAX CALCULATION
	
	Taxes = Taxes you pay depending on whate state and what year.
		DataType: float: Reasoning- Money is involed, therefore decimals are neccessary for cents.
	*/
	float taxes;
	
	//if statement  checks to see whether it's 2017 or 2018 taxes 
	if(taxYear == 2017)
	{
		//Switch determines which state's tax laws will be applied
		switch(state)
		{
			case 'a':
				taxes = grossIncome * 0.06;	
				break;
			case 'b':
				if(grossIncome < 2000)
					taxes = 0;	
			
				else if(grossIncome >= 2000 & grossIncome < 10000)
					taxes = 100;
				else
					taxes = (grossIncome * 0.1) + 100;	

				break;
			case 'c':
				if(grossIncome < 3500)
					taxes = (grossIncome * 0.05);

				else if(grossIncome >= 3500 &  grossIncome < 9000)
					taxes = (grossIncome * 0.07) + 175;

				else if(grossIncome >= 9000 &  grossIncome <  125000)
					taxes = (grossIncome * 0.09) + 560;
				else
					taxes = (grossIncome * 0.099) + 11000;
				
				break;
			default:
				cout << "Error" << endl;
				break;
		}
	}
	else if(taxYear == 2018)
	{
		switch(state)
		{
			case 'a':
				taxes = (grossIncome * 0.08);
				break;
			case 'b':
				if(grossIncome < 2500)
					taxes = 0;

				else if(grossIncome >= 2500 &  grossIncome < 10000)
					taxes = 115;
				else
					taxes = (grossIncome * 0.105) + 115;

				break;
			case 'c':
				if(grossIncome < 3450)
					taxes = (grossIncome * 0.05);

				else if(grossIncome >= 3450 &  grossIncome < 8700)
					taxes = (grossIncome * 0.07) + 172.5;

				else if(grossIncome >= 8700 &  grossIncome < 125000)
					taxes = (grossIncome * 0.09) + 540;

				else
					taxes = (grossIncome * 0.099) + 11007;

				break;
			default:
				cout << "Error" << endl;
				break;
		}
	}

	//Prints out the Gross income, personal profit, taxes and remaining money.
	cout << "The average selling price for a car (generated randomly) is: $" << carCost * x << endl;
 
	cout << "You will earn 2% of the profit, which is $" << profit * 0.02 << endl;

	cout << "The Gross Income is: $" << grossIncome << endl;

	cout << "The Tax you need to pay is: $" << taxes << endl;

	cout << "Remaining: $" << grossIncome - taxes << endl;
    		
}

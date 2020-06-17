/*************************************************************************************
 * PROGRAM NAME: Fraction simplifier & Diamond Pattern Creator
 *
 * AUTHOR: Pranaw Bajracharya
 *
 * DESCRIPTION:
 * 	Fraction Simplifier: The user inputs a numerator and denominator. The program 
 * 			     will output a simplified fraction.
 * 	Diamond Pattern Creator: The user enters in whether they want to make a 
 * 			 	 diamond pattern with asterisks or numbers and how 
 * 			 	 many rows they want. Then the program will output 
 * 			 	 the pattern in the console
 *
 * 	The user will be able to simplify as many fractions as they want or create as
 * 	many pattern as they want.
 *
 * INPUT(S):
 * 	Fraction Simplifier:
 *		numerator - Top half of the fraction. A number
 *		denominator - Bottom half of the fraction. A number
 *
 *	Diamond Pattern Creator:
 *		patternType - a true or false (asterisk = true and number = false)
 *		rows -
 * OUTPUT(S):
 * 	Fraction Simplifier:
 *		simplifiedFraction - The simplified version of the fraction inputted
 *
 *	Diamond Pattern Creator:
 *		pattern - The diamond shape given the specified parameters
 ************************************************************************************/


#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

void simplifyFraction(int numerator, int denominator)
{
	/*
	 * Name: biggerNumber
	 * Type: float
 	 * Purpose: Stores the biggest number so it can be used as an upper limit
	 *	   for the loop function. Since we are looking for the largest
	 *	   common factor, the largest factor has to factor into this number
	 */

	int biggerNumber;
	
	//For when the numerator is larger than the denominator
	if(numerator > denominator)
	{
		//A check to see if the fraction simplifies into an integer
		if(numerator % denominator == 0)
		{
			//Prints out the simplified fraction if it is an integer
			cout << "The simplified fraction: "; 
			cout << numerator/denominator << endl << endl;
			
		}

		//The numerator is the bigger number
		biggerNumber = numerator;
	}
	else
		//The denominator is the bigger number
		biggerNumber = denominator;

	/*
	 * Name: scaleFactor
	 * Type: int
	 * Purpose: This is the variable the numerator and denominator will
	 * 	    be divided by to simplify the fraction. At the end of the loop
	 * 	    the scale factor will be the largest common factor
	 */
	int scaleFactor = 1;

	//Loop to calculate the largest common factor
	for(int i = 1; i <= biggerNumber; ++i)
	{
		//Checks to see if i is a factor of both the numerator and denominator
		if(numerator % i == 0 & denominator % i == 0)
			scaleFactor = i;
	}

	//Actual simplification of the fraction
	numerator = numerator / scaleFactor;
	denominator = denominator / scaleFactor;

	//Print out the value to the user
	cout << "The simplified fraction: " << numerator;
	cout << " / "  << denominator << endl << endl;
}

void promptFraction()
{
	/*
	 * Name: check
	 * Type: bool
	 * Purpose: Used in loops to make sure the entered values are correct
	 * 	    and reprompt them if they enter a wrong variable
	 *
	 */	 	
	bool check = false;

	/*
 	 * Name(s): numerator, denominator
 	 * Type: String
 	 * Purpose: To serve as the numerator/ denominator a fraction respectively
 	 *
 	 */
	string numerator, denominator;


	/*
	 * Name: numNumber, denomNumber
	 * Type: int
	 * Purpose: To store the values of the numerator and denominator when we've
	 * 	    concluded that they are indeed valid numbers
	 *
	 */
	float numNumber, denomNumber;


	/*
	 * Name: numDecimalScaleFactor, denomDecimalScaleFactor, absoluteDecimalScaleFactor
	 * Type: int
	 * Purpose: The number of spots after the decimal place. Determines the 
	 * 	    scale factor to turn decimal places to a whole number. Different
	 * 	    for the numerator and denominator. Whichever one that is the
	 * 	    biggest will be used as the absoluteDecimalScaleFactor
	 *
  	 */
	int numDecimalScaleFactor = 0;
	int denomDecimalScaleFactor = 0;
	
	int absoluteDecimalScaleFactor = 0;

	//NUMERATOR INPUT

	//While loop keeps repeating the numerator input until they enter a proper numerator
	while(!check)
	{
		
		cout << "Enter in a numerator" << endl;
		cin >> numerator;
		cout << endl;
		
		/*
 		 * Name: decimalCount
		 * Type: int
		 * Purpose: Counts the amount of decimals that have been entered
		 *
	 	 */
		int decimalCount = 0;

		//For loop searches through the entire string
		for(int i = 0; i < numerator.length(); i++)
		{
			
			
			/*
 			 * Name: x
			 * Type: int
			 * Purpose: Represent the integer value for the char at
			 * 	    denominator.at(i)
			 */	
			int x = int(numerator.at(i));
		
			//Checks for non numbers excluding periods	
			if(!cin || ((x < 47 ||  x > 58) & x != 46))
			{
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Enter in only numbers please." << endl << endl;
				//Exits loop
				i += 5000;
			}
		
			//Adds to the decimal count
			//Adds to the decimalScaleFactor	
			if(x == 46)
			{
				decimalCount += 1;
				numDecimalScaleFactor = numerator.length() - i + 1;
			}

			//Checks to see if there are not more than 1 decimals
			if(decimalCount > 1)
			{
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Put in only valid numbers please." << endl << endl;
				i += 5000;
			}
				
			 
			/*
 			 * If the for loop ever gets to the last number, that means 
			 * it is true up to that number, and it it gets here on the
			 * last iteration, it is a valid number and the while loop is exited
			 *
			 */
			if(i == numerator.length()- 1)
			{
				check = true;
			}

		}
	}
	
	//Converts the string to a stream that we can put
	//into an integer (We already know the string is a
	//number at this point)
	
	stringstream num(numerator);
	num >> numNumber;

	check = false;
	
	//DENOMINATOR INPUT
	
	//While loop keeps repeating the numerator input until they enter a proper numerator
	while(!check)
	{
		
		cout << "Enter in a denominator" << endl;
		cin >> denominator;
		cout << endl;
		
		/*
 		 * Name: decimalCount
		 * Type: int
		 * Purpose: Counts the amount of decimals that have been entered
		 *
	 	 */
		int decimalCount = 0;

		//For loop searches through the entire string
		for(int i = 0; i < denominator.length(); ++i)
		{
			
			
			/*
 			 * Name: x
			 * Type: int
			 * Purpose: Represent the integer value for the char at
			 * 	    denominator.at(i)
			 */	
			int x = int(denominator.at(i));
		
			//Checks for non numbers excluding periods	
			if(!cin || ((x < 47 ||  x > 58) & x != 46))
			{
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Enter in only numbers please." << endl << endl;
				//Exits loop
				i += 5000;
			}
		
			//Adds to the decimal count	
			if(x == 46)
			{
				decimalCount += 1;
				//Finds the spaces to the right left, but adds one
				//because i is offset by -1
				denomDecimalScaleFactor = denominator.length() - i;
			}
			//Checks to see if there are not more than 1 decimals
			if(decimalCount > 1)
			{
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Put in only valid numbers please." << endl << endl;
				i += 5000;
			} 
			
			/*
 			 * If the for loop ever gets to the last number, that means 
			 * it is true up to that number, and it it gets here on the
			 * last iteration, it is a valid number and the while loop is exited
			 * 
			 * The only exception is is the number ends up being 0
			 * Then the user will be reprompted to enter a denominator
			 */
			if(i == denominator.length()-1)
			{
				//Converts the string to a stream that we can put
				//into an integer (We already know the string is a
				//number at this point)
				stringstream denom(denominator);
		
				//Puts it into an integer
				denom >> denomNumber;

				//Checks to see which scale factor to use
				if(denomDecimalScaleFactor >  numDecimalScaleFactor)
					absoluteDecimalScaleFactor = denomDecimalScaleFactor;			
				else
					absoluteDecimalScaleFactor = numDecimalScaleFactor;
				//Scales the number if it has a decimal
				denomNumber = denomNumber * pow(10,absoluteDecimalScaleFactor);		
		
				if(denomNumber == 0)
				{
							
					cin.clear();
					cin.ignore(100000, '\n');
					cout << "Denominator can't be zero" << endl << endl;
					//Exits loop
					i += 5000;

				}
				else
					check = true;
			}
			 
		}
	
	}
	
	//Scales the numNumber to account for decimals
	//If there were no spots after either the decimal places it will multiply by 1
	numNumber = numNumber * pow(10,absoluteDecimalScaleFactor);

	simplifyFraction(numNumber,denomNumber);	
}

void promptPattern()
{
	int patternType;
	
	cout << "What type of pattern would you like?" << endl << "Enter 0 for asterisks and 1 for numbers" << endl << endl;
	cin >>  patternType;

	check = false;
	
	while(!check)
	{
		if(!cin || patternType > 1 || patternType < 0)
		{
			cin.clear();
			cin.ignore(1000000, '\n');

			cout << "Only enter either a 0 or a 1. Try again" << endl << endl;
				
		}
		else
			check = true;
	}
	
	int rows;
	
	cout << "How many rows would you like?" <<endl << "Rows can not be negative"  << endl;
	cin >>  rows;

	check = false;
	
	while(!check)
	{
		if(!cin || rows < 0) 
		{
			cin.clear();
			cin.ignore(1000000, '\n');

			cout << "Only enter either only positive numbers" << endl << endl;
				
		}
		else
			check = true;
	}
	

	char patternArray[rows, rows];

	
	for(int i = 0; i < rows/2; ++i)
	{
		int spaceCount = rows - (1 + 2*i)/2;
		for(int x = 0; x < spaceCount; ++x)
		{
			patternArray[i,x] = 32;
		}
	
		for(int z = 1; z <= (1 + 2*i); --z)
		{
			
		}			
	}
	
	for(int i = rows/2; i < rows; ++i)
	{
		int spaceCount = rows - (1 + 2*i)/2;
		 
		for(int x = 0; x < spaceCount; ++x)
		{
			patternArray[i,x] = 32;
		}
	
		for(int z = ; z <= (rows - 2*i); --z)
		{
			
		}			
	
	}
	
}

void homeSelection()
{
	//Welcome Message
	cout << "***************************************************************************************************************************************************" << endl << endl;
	cout << "Welcome this program!! This program has two capabilities: Fracton Simplifier and Pattern Creator" << endl << endl;
	cout << "Which program would you like? Press 0 or the Fraction Simplifier and 1 for the Pattern Creator" << endl << endl;
	cout << "If you want to exit the program, press 2" << endl << endl;
	
	int choice;
	
	
	bool check = false;

	cin >> choice;

	while(!check)
	{
		if(!cin || choice > 2 || choice < 0)
		{
			cin.clear();
			cin.ignore(1000000,'\n');
			cout << "Enter in either 0 or 1 to choose" << endl;
		}
		else
			check = true;
	}

	if(choice == 0)
		promptFraction();
	else if(choice == 1)
		promptPattern();
	else		
		exit(0);			

}


int main()
{
	while(1)
	{
		homeSelection();
	}
				

}

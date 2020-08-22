#include <iostream>
#include <stdlib.h>

using namespace std;

/***********************************************************************************************
 * Function Name:
 * Description: 
 * 		1) Takes two numbers and finds the greatest common multiple
 *
 * Inputs: Numerator Local Copy, Denominator local Copy
 * Outputs: int (Greatest common factor)
 **********************************************************************************************/
//(THIS IS int g_c_d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
int greatestCommonFactor(int number1,int number2)
{
	
	
	//In case that the numerator is zero
	if(number1 == 0)
		return 0;

	//Calculates the greatest common factor with the inherent rules in modulus
	//(if x < y, then x % y is just x)
	if(number2 != 0)
	{
		greatestCommonFactor(number2, number1 % number2);
	}
	else
		return number1;	
	
}

/***********************************************************************************************
 * Function Name: simplifyFraction
 * Description: 
 * 		1) Checks if denominator is zero and will return false if so
 * 		2) If the denominator is a factor of the numerator it will return the 
 * 		   simplified value
 *		3) Otherwise, it will call the greatestCommonFactor function and then divide 
 *		   the numearator and denominator by the greatest common factor and output 
 *		   that to the console
 * Inputs: Numerator Reference, Denominator Reference
 * Outputs: bool (Whether the denominator is equal to zero
 **********************************************************************************************/
//(THIS IS: bool to_lowest_terms!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
bool simplifyFraction(int &number1,int &number2)
{
	//Denominator can't be zero
	if(number2 == 0)
		return false;
	else
	{
		
		//This is so the fraction can be shown as a whole number if it simplifies to it
		if(number1 % number2 == 0)
		{
			cout << "The simplified value is: " << number1/number2 << endl << endl;
		}
		else
		{
			//Finds the greatest common factor	
			int divisor = greatestCommonFactor(number1, number2);

			//Changes the numbers at their 
			number1 /= divisor;
			number2 /= divisor;
		
			cout << "The simplified fraction is: " << number1 << " / " << number2 << endl << endl;
		}
	}	
}

/***********************************************************************************************
 * Function Name: promptFraction
 * Description: 
 * 		1) Prompts the user for valid numerator and denominator values
 *		2) Checks whether those values are valid and if not, tells the user why 
 *		3) Function will continually prompt until valid values are entered
 *		4) Calls the sumplifyFraction function when values are correct
 * Inputs: N/A (void)
 * Outputs: N/A (void)
 **********************************************************************************************/
void promptFraction()
{
	//Numerator and denominator variables
	int numerator, denominator;

	//Check variable for loop
	bool check = false;
			
	//Loop continues until user inputs correct values
	while(!check)
	{ 	
		
		//User Prompts
		cout << "Enter a numerator" << endl;
		cin >> numerator;
	
		cout << "Enter a denominator" << endl;
		cin >> denominator;

		//Checks for errors
		if(!cin || denominator == 0)
		{
			cin.clear();
			cin.ignore(1000000,'\n');
			cout << "One of your values was incorrect. Remember to enter only integers and the denominator can't equal 0" << endl << endl;	
		}
		else
			check = true;
			
	}	

	//Calls the simplifyFraction function to simplify the fraction
	simplifyFraction(numerator,denominator);
}


/***********************************************************************************************
 * Function Name: numbersPatternMaker
 * Description:
 * 		1) This pattern maker makes the pattern through a iteratied loops to form the 
 * 		   diamond pattern
 * Inputs: Columns (9)
 * Outputs: N/A (void) 
 **********************************************************************************************/

void numbersPatternMaker(int columns)
{
	//TOP HALF
	//This goes through each row until the end if the middle row
	for(int rows = 0; rows <= (columns - 1)/2; ++rows)
	{
		//This calculates the spaces and prints them
		for(int offset = (columns - 1)/2 - rows; offset > 0; --offset)
			cout << ' ';

		//Calculates how many numbers need to be in the row and prints the number
		for(int numbers = 1; numbers <= (rows * 2) + 1; ++numbers)
			cout << numbers;

		//Ends the row
		cout << endl;
	}
	
	//BOTTOM HALF
	//This is for the remaining rows
	for(int rows = 1; rows <= (columns - 1)/2; ++rows)
	{
		//This calculates the spaces and prints them
		for(int offset = rows; offset > 0; --offset)
			cout << ' ';

		//Calculates how many numbers need to be in the row and prints them
		for(int numbers = 1; numbers <= columns - (2*rows); ++numbers)
			cout << numbers;
		
		//Ends the row
		cout << endl;
	}	
}

/***********************************************************************************************
 * Function Name: asteriskPatternMaker
 * Description: 
 * 		1) This pattern maker makes the pattern through iteratied loops to form
 * 		   the asterisk pattern,
 * Inputs: columns
 * Outputs: N/A (void)
 **********************************************************************************************/

void asteriskPatternMaker(int columns)
{
	//TOP HALF
	//This goes through each row until the end if the middle row
	for(int rows = 0; rows <= (columns - 1)/2; ++rows)
	{
		//This calculates the spaces and prints them
		for(int offset = (columns - 1)/2 - rows; offset > 0; --offset)
			cout << ' ';

		//Calculates how many asterisks need to be in the row and prints the number
		for(int numbers = 1; numbers <= (rows * 2) + 1; ++numbers)
			cout << '*';

		//Ends the row
		cout << endl;
	}
	
	//BOTTOM HALF
	//This is for the remaining rows
	for(int rows = 1; rows <= (columns - 1)/2; ++rows)
	{
		//This calculates the spaces and prints them
		for(int offset = rows; offset > 0; --offset)
			cout << ' ';

		//Calculates how many asterisks  need to be in the row and prints them
		for(int numbers = 1; numbers <= columns - (2*rows); ++numbers)
			cout << '*';
		
		//Ends the row
		cout << endl;
	}
}

/***********************************************************************************************
 * Function Name: promptPattern
 * Description:
 * 		1) Asks the user whether they want an asterisk pattern or a numbers pattern 
 * 		   and makes sure they enter correct values 
 *		2) If they ask for numbers, it will print out the number pattern, otherwise it 
 *		   will ask for the rows and check the value
 *		3) Then it calls the patternMakerFunction
 * Inputs: N/A (void)
 * Outputs: N/A (void)
 **********************************************************************************************/
void promptPattern()
{
	//Variable declarations
	int choice, columns = 1;
	bool check = false;

	//Function is longer than the specifications state because I incorporated error handling
	while(!check)
	{
		cout << "What kind of pattern do you want? Enter 0 or Asterisk and 1 for numbers" << endl;
		cin >> choice;
		
		//The voice portion is within the same loop as the pattern so space cana be conserved.
		if(choice == 0)
		{
			cout << "Enter the amount of columns you would like" << endl;
			cin >> columns;
		}

		if(!cin || choice < 0 || choice > 1 || (columns % 2 == 0) || columns < 1)
		{
			cout << "Remember, you can only choose by entering a 0 or a 1\n\nAdditionally, if you're entering columns, remember to only enter positive odd integers\n\n";
			cin.clear();
			cin.ignore(1000000,'\n');
		}
		else
			check = true;
	}
	
	//Takes the choice and either makes the numbers pattern or calls the function that makes the asterisk pattern
	if(choice == 0)
		asteriskPatternMaker(columns);
	else
		numbersPatternMaker(9);

}

/***********************************************************************************************
 * Function Name: homeSelection
 * Description:
 * 		1) Allows you to select whether you use the Fraction Creator or Diamond 
 * 		   Pattern Maker
 * Inputs: N/A (void)
 * Outputs: N/A (void)
 **********************************************************************************************/
void homeSelection()
{
	//Welcome Message
	//This message takes up multiple lines for READABILITY
	cout << "***************************************************************************************************************************************************" << endl << endl;
	cout << "Welcome this program!! This program has two capabilities: Fracton Simplifier and Pattern Creator" << endl<< endl;
	cout << "Fraction Simplifier - Lets you input a fraction and that fraction will be simplified" << endl << endl;
	cout << "Pattern Creator - Lets you choose which diamond pattern you want to make: An adjustable asterisk diamond or a set diamond made of numbers" << endl << endl;
	cout << "You'll have as many opportunities to repeat the functions as you want" << endl << endl;
	cout << "Which program would you like? Press 0 or the Fraction Simplifier and 1 for the Pattern Creator" << endl << endl;
	cout << "If you want to exit the program, press 2" << endl << endl;

	//Stores the choice the user makes	
	int choice;
	
	//Check variable for the loop that makes sure the user enters in correct values
	bool check = false;

	//Loop that continues until the user enters valid values
	while(!check)
	{
		cin >> choice;
		//Defines a valid value
		if(!cin || choice > 2 || choice < 0)
		{
			//Clears the stream and tells the user what they did wrong
			cin.clear();
			cin.ignore(1000000,'\n');
			cout << "Enter in either 0, 1, or 2 to choose" << endl;
		}
		else
			check = true;
	}

	//Calls the appropriate funciton depending on the users' answer
	//The statement could be done as an if statement, but for some reason that breaks the infinite homeScreen loop
	//Therefore the switch, although it addes a lo of lines, is necessary
	switch(choice)
	{
		case 0:
			promptFraction();
			break;
		case 1:
			promptPattern();
			break;
		default:
			exit(0);
			break;

	}
}


int main()
{
	//Infinite loop that's broken inside the homeSelection function
	//This allows for the user to reuse the program as long as they like
	while(1)
	{
		homeSelection();
	}
				

}

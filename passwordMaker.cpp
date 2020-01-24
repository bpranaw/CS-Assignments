/* PROGRAM NAME: Password Maker
 * AUTHOR: Pranaw Bajracharya
 * DESCRIPTION: Randomly generates a password based on the user's specifications
 * START DATE: 1/21/2020
 * COMPLETION DATE: 1/24/2020
 */


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//A variable used in checks for truth
bool check = false;

/* FUNCTION NAME: solicitBool
 * DESCRIPTION: Takes in a test variable ment to represent a true or false value. 
 * 		Also ensures all values entered are correct in nature
 * INPUT: INT value (limited to either 1 or 0 by the function)
 * OUTPUT: Returns either a 1 or 0
 */

int solicitBool(int testVariable)
{
	cin >> testVariable;
	if(!cin || testVariable > 1 || testVariable < 0)
	{
		cout << "Enter a correct value" << endl;
		cin.clear();
		cin.ignore(1000000, '\n');
	}
	else
	{
		check = true;
		if(testVariable == 1)
			return 1;
		else
			return 0;
	}
}

/* FUNCTION NAME: solicitInt
 * DESCRIPTION: Takes in a test value and the maximum limit of the test value
 * 		and checks to see whether it is a correct number (not negative) 
 * 		or value
 * INPUT: INT (testVariable)
 * OUTPUT: INT (testVariable)
 *
 */
int solicitInt(int testVariable, int upperLimit)
{
	cin >> testVariable;
	if(!cin || testVariable < 0 || testVariable > upperLimit)
	{
		cout << "Enter a correct value" << endl;
		cin.clear();
		cin.ignore(1000000, '\n');
	}
	else
	{
		check = true;
		return testVariable;
	}
}

int main()
{
	cout << "Welcome to Password Maker! You will be asked information that will help you create your own randomized password!" << endl;
	
	/*Declaration of Variables
	* upperCaseBool, lowerCaseBool, and  numberBool, represent the values 0 or 1
	* 
	* passwordLength, upperCaseNumber, lowerCaseNumber, and numberNumber all represent an amount in the password
	*	with regards to either the total length, number, lower or uppercase letters 
	*
	*/

	int upperCaseBool, lowerCaseBool, numberBool, passwordLength, upperCaseNumber, lowerCaseNumber, numberNumber;
	
	//Asking the user if they would like to use  upper case letters in their password
	//Loop ensures they input real values
	while(!check)
	{
		cout << "Would you like upper case letters in your password? Enter 0 for no and 1 for yes." << endl;
		upperCaseBool = solicitBool(upperCaseBool);
	}
	
	//Setting the check variable to false so it can be used again
	check = false;
	
	//Asking the user if they would like to use lower case letters in their password
	while(!check)
	{
		cout << "Would you like lower case letters in your password? Enter 0 for no and 1 for yes." << endl;
		lowerCaseBool = solicitBool(lowerCaseBool);
	}

	check = false;
	
	//Asking the user if they would like to use numbers in their password.
	while(!check)
	{
		cout << "Would you like numbers in your password? Enter 0 for no and 1 for yes." << endl;
		numberBool = solicitBool(numberBool);
	}

	check = false;

	//Asking the user how long they would like their password to be
	while(!check)
	{
		cout << "How long would you like your password to be?\nYou can select how many uppercase and lowercase letters and numbers later.\nYou do not need to explicitly state the amount of numbers, it will be inferred from your other answers \nIf you don't specify, or enter contradictory information like wanting a 10 character password but with no numbers and only 8 letters, they will be numbers by default." << endl;
		passwordLength = solicitInt(passwordLength, 1000);
	}

	check = false;

	//Asks the user how many upper case letters they want, if they want upper case letters
	if(upperCaseBool == 1)
	{
		while(!check)
		{
			cout << "How many uppercase letters do you want in your password?\nMake sure you don't enter more than what's in your password length." << endl;
			upperCaseNumber = solicitInt(upperCaseNumber, passwordLength);		
		}	
	}


	check = false;

	//Asks the user how many lower case letters they want, if they want lower case letters
	if(lowerCaseBool == 1)
	{
		while(!check)
		{
			cout << "How many lower case letters do you want in your password?\nMake sure you don't enter more than what's left of your password length." << endl;
			lowerCaseNumber = solicitInt(lowerCaseNumber, passwordLength - upperCaseNumber);
		}
	
	}

	check = false;

 
	srand(time(NULL));

	//PASSWORD ARRAY
	//password[arraySize, checkVariable]
	int password[passwordLength][2];

	//Sets random number values for all the parts of the password and sets the check variables to 0
	for(int i = 0; i < passwordLength; i++)
	{
		password[i][0] = rand() % 10;	
		password[i][1] = 0;
	}
	

	//RANDOMIZATION PROCESS

	//DETERMINES THE UPPERCASE NUMBERS
	int i = upperCaseNumber + lowerCaseNumber;
	while(i > 0)
	{
		int x = rand() % passwordLength;
		if(password[x][1] == 0)
		{
			password[x][0] = rand()	% 26 + 65;
			password[x][1] = 1;
			i--;	
		}
	
	}

	//DETERMINES THE RANDOM LOWERCASE NUMBERS
	i = lowerCaseNumber;
	while(i > 0)
	{
		int x = rand() % passwordLength;
		if(password[x][1] == 1)
		{
			password[x][0] += 32;
			password[x][1] = 2;
			i--;
		}
	
	}


	char z;

	cout << "Your password is: ";

	//GOES THROUGH THE ENTIRE PASSWORD ARRAY TO PRINT OUT VALUES
	for(int i2 = 0; i2 < passwordLength; i2++)
	{
	
		if(password[i2][1] != 0)
		{
			//TYPECASTS THE ASCII VALUES THAT WOULD OUTPUT LETTERS
			z = char(password[i2][0]);
			cout << z;
		}
		else
			cout << password[i2][0];
		
	 
	}

	cout << endl;

}	

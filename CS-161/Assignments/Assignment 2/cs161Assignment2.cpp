#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*************************************************************************************
 *FUNCTION NAME: checkRange
 *
 *DESCRIPTION: Takes a range of  values and a test value. Then it outputs a boolean 
 *	       depending on whether the test value is within that range
 *	       
 *	       NOTE: This range allows the test value to be equal to the upper and 
 *	       	     lower bound.
 *
 *INPUTS(S): float lowerBound- Smallest number that the test value can be to have the 
 *			    function return true.
 *
 *	  float upperBound- Greatest number that the test value can be to have the
 *			    function return true.
 *
 *	  float testValue-  Value being tested.
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool checkRange(float lowerBound, float upperBound, float testValue)
{
	//This tells the user that they've enterd and incorrect value
	if(lowerBound > upperBound)
	{
		cout << "Input a valid value. Remember lowerBound < upperBound" << endl;
		cout << endl;
		return false;
	}

	//Actual test to see if the value is within the range
	if(testValue >= lowerBound & testValue <= upperBound)
		return true;	
	else
		return false;

	//This return makes sure if the user somehow enters incorrect values, the
	//program will not be stuck in the function
	cout << "It is unclear how you messed up this one." << endl;
	cout << endl;
	return false;	
}

/*************************************************************************************
 *FUNCTION NAME: isCapital
 *
 *DESCRIPTION: Takes an input character and typecasts it into an ASCII decimal value
 *	       and returns a boolean depending on if it is a capital letter or not.
 *
 *INPUTS(S): char letter- The character being tested for capitalization
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool isCapital(char letter)
{
	//Typecasts the character letter into an integer and a new variable
	int x = int(letter);
	
	//Checks for capitalization by using the ASCII range for capital letters
	//If they are capital, it returns true, if not it will return false
	if(letter > 64 & letter < 91)
		return true;
	else
		return false;

}

/*************************************************************************************
 *FUNCTION NAME: isEven
 *
 *DESCRIPTION: Takes in an integer and outputs a boolean depending on whether it is 
 *	       even or not.
 *
 *INPUTS(S): int number
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool isEven(int number)
{
	//Checks to see if it is divisible by two with no remainder (even definition)
	if(number % 2 == 0)
		return true;
	else
		return false;
}

/*************************************************************************************
 *FUNCTION NAME: isOdd
 *	
 *DESCRIPTION: Takes in an integer and outputs a boolean depending on whehter it is
 *	       odd or not.
 *
 *INPUTS(S): int number
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool isOdd(int number)
{
	//Checks to see if it is unevenly disivible by two (odd definition)
	if(number % 2 != 0)
		return true;
	else
		return false;
}

/*************************************************************************************
 *FUNCTION NAME: equalityTest
 *
 *DESCRIPTION: Takes in two integers ( number 1 and number 2) and tests number 1
 *	       against number 2. 
 *	       If number 1 < number 2, -1 will be returned
 *	       If number 1 is equal to number 2, 0 will be returned
 *	       If number 1 > number 2, 1 will be returned
 *
 *INPUTS(S): int number1 and int number2
 *
 *OUTPUT(S): One of these:
	     		-1
	      		 0
            		 1
 ************************************************************************************/

int equalityTest(int number1, int number2)
{
	if(number1 < number2)
		return -1;
	else if(number1 == number2)
		return 0;
	else
		return 1;
}

/*************************************************************************************
 *FUNCTION NAME: floatIsEqual
 *
 *DESCRIPTION: Takes in two numbers and a given precision and tests to see if they are
 *	       are equal within that plus or minus range
 *
 *INPUTS(S): float number1, float number1, float precision
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool floatIsEqual(float number1, float number2, float precision)
{
	//Finds the absolute difference between the numbers and checks to see if that
	//is less than or equal to the absolute value of the precision
	if(abs(number1 - number2) <=  abs(precision))
		return true;
	else
		false;	
}

/*************************************************************************************
 *FUNCTION NAME: isInt
 *
 *DESCRIPTION: Takes in a string and outputs a boolean depeding on if that string is
 *	       an integer
 *	       NOTE: This operates under the assumption that 1.0 is NOT AN INTEGER
 *	             but a FLOAT
 *
 *INPUTS(S): string test
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool isInt(string test)
{	
	for(int i = 0; i < test.length(); i++)
	{
		if(int(test.at(i)) <  47 || int(test.at(i)) > 57)
		{
			return false;
		}
	}
	return true;	
}

/*************************************************************************************
 *FUNCTION NAME: numbersPresent
 *
 *DESCRIPTION: This takes in a string and outputs a boolean depending on whether the
 *	       string contains numbers
 *
 *INPUTS(S): string sentence
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool numbersPresent(string sentence)
{
	for(int i = 0; i < sentence.length(); i++)
	{
		if(int(sentence.at(i)) >= 47 & int(sentence.at(i)) <= 57)
		{
			return true;
		}
	}
	return false;
}


/*************************************************************************************
 *FUNCTION NAME: lettersPresent
 *
 *DESCRIPTION: This takes in a string and outputs a boolean depending on if there are
 *	       letters in the string
 *
 *INPUTS(S): string sentence
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool lettersPresent(string sentence)
{
	for(int i = 0; i < sentence.length(); i++)
	{
		int x = int(sentence.at(i));
		if(x >= 65 & x <= 90)
			return true;
		else if(x >= 97 & x <= 122)
			return true;
	}
	return false;
}

/*************************************************************************************
 *FUNCTION NAME: containsSubString
 *
 *DESCRIPTION: Takes in two strings and tells if the second string is contained within
 *	       the first
 *	       NOTE: Both ac and da are not in the string abcd
 *INPUTS(S): string sentence
 *
 *OUTPUT(S): boolean
 ************************************************************************************/

bool containsSubString(string sentence, string subSentence)
{
	
	char x = subSentence.at(0);

	
	for(int i = 0; i < sentence.length(); i++)
	{
		if(x == sentence.at(i))
		{	
			for(int a = 1; a < sentence.length()- i; a++)
			{
				if(subSentence.at(a) != sentence.at(i+a))
					return false;
			}
		}		
	}
	return true;
}

/*************************************************************************************
 *FUNCTION NAME: wordCount
 *
 *DESCRIPTION: Takes in a string and outputs the number of words in that string (int)
 *	       NOTE: words are two words are only two if they have a space or - 
 *	       inbetween them
 *
 *INPUTS(S): string sentence
 *
 *OUTPUT(S): int
 ************************************************************************************/

int wordCount(string sentence)
{
	int count = 0;
	
	//Checks to see if there is a character that is not a space or hyphen
	//and if so and it has a space or hyphen afterwards, it will add to the count
	//But it doesn't work for the last character
	for(int i = 0; i < sentence.length(); i++)
	{
		if( i != sentence.length() - 1 & (sentence.at(i) != ' ' || sentence.at(i) != '-'))
		{
			if(sentence.at(i+1) == ' ' || sentence.at(i+1) == '-')
				count += 1;	
		}
	}

	//Checks to see if there is a word at the end
	if(sentence.at(sentence.length()-1) != ' ' || sentence.at(sentence.length()-1) != '-')
	{
		if(sentence.at(sentence.length()-2) == ' ' || sentence.at(sentence.length() - 2) == '-')
		count += 1;
	} 
	
	return count;
}

/*************************************************************************************
 *FUNCTION NAME: toUpper
 *
 *DESCRIPTION: Takes a string and makes all the lowercase letters uppercase and
	       outputs the string.
 *
 *INPUTS(S): string sentence
 *
 *OUTPUT(S): string
 ************************************************************************************/

string toUpper(string sentence)
{
	for(int i = 0; i < sentence.length(); i++)
	{
		int x = int(sentence.at(i));

		if(x >= 97 & x <= 122)
			sentence.at(i) -= 32;
		
	}
	return sentence;
}

/*************************************************************************************
 *FUNCTION NAME: toLower
 *
 *DESCRIPTION: Takes in a string and turns all capital letters to lowercase letters
 *	       and then outputs that string.
 *
 *INPUTS(S): string sentence
 *
 *OUTPUT(S): string
 ************************************************************************************/

string toLower(string sentence)
{
	for(int i =0; i < sentence.length(); i++)
	{
		int x = int(sentence.at(i));
		if(x >= 65 & x <= 90)
			sentence.at(i) += 32;
	}
	return sentence;	
}

/*************************************************************************************
 *FUNCTION NAME: getInt
 *
 *DESCRIPTION: Takes a prompt from the user and checks to see if the input 
 *	       is an integer and returns it if it is. Repeats to make sure the user 
 *	       enters an integer.
 *
 *INPUTS(S): prompt (from the user)
 *
 *OUTPUT(S): integer
 ************************************************************************************/

int getInt()
{	
	int x;

	bool check = false;
	
	//A loop that makes sure the user inputs a correct thing
	while(!check)
	{

		cout << "Please input an integer" << endl;
		cout << endl;
		cin >> x;
	
		if(!cin)
		{
			cin.clear();
			cin.ignore(1000000, '\n');
		}	
		else
			check = true;
	}

	return x;
}

/*************************************************************************************
 *FUNCTION NAME: preTestingMessage
 *
 *DESCRIPTION: Takes the function name, test value/ conditions, and the expected 
 *             value that the function should output and prints it all to the console
 *
 *INPUTS(S): string functionName, testValue, expected
 *
 *OUTPUT(S): None
 ************************************************************************************/

void preTestingMessage(string functionName, string testValue, string expected)
{
	cout << "*********************************************************************" << endl;
	cout << endl;
	
	cout << "Testing " + functionName << endl;
	cout << endl;

	cout << "Checking to see if " << testValue << endl;
	cout << endl;

	cout << "Expected Outcome: " << expected << endl;
	cout << endl;
}

/*************************************************************************************
 *FUNCTION NAME: postTestingMessage
 *
 *DESCRIPTION: Takes in the expected value and the actual value calculated by the 
 *	       function and compares them. If they are equal, it will state the test
 *	       has been PASSED and if they are not equal, it will state the test has
 *	       been FAILED.
 *
 *INPUTS(S): string expected, actual
 *
 *OUTPUT(S): None
 ************************************************************************************/

void postTestingMessage(string expected, string actual)
{
	cout << "Actual Outcome: " << actual << endl;
	cout << endl;

	(actual == expected)? cout << "PASSED"<< endl : cout << "FAILED" << endl;
	cout << endl;

	cout << "*********************************************************************" << endl;
	cout << endl;

}

int main()
{
	//INTRODUCTION MESSAGE
	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Welcome to the tests for the Helper Functions!" << endl;
	cout << endl;

	//PLACE WHERE WE WILL STORE THE RESULTS OF OUR TESTS	
		string check;


	//TESTING checkRange
	preTestingMessage("checkRange","27 is within the range of 1 and 29","true");
	
	(checkRange(1, 29, 27))? check = "true" : check = "false";

	postTestingMessage("true", check);

	check = "anything";


	//TESTING isCapital
	preTestingMessage("isCapital","j is capital","false");
	
	(isCapital('j'))? check = "true" : check = "false"; 
	
	postTestingMessage("false", check);
	
	check = "oWo";


	//TESTING isEven
	preTestingMessage("isEven","667 is an even number","false");
	
	(isEven(667))? check = "true" : check  = "false";

	postTestingMessage("false", check); 


	//TESTING isODD
	preTestingMessage("isOdd","667 is an odd number","true");
	
	(isOdd(667))? check = "true" : check = "false";

	postTestingMessage("true", check);
	
	check = "rip";


	//TESTING equalityTEST
	preTestingMessage("equalityTest","667 is greater than -555","1");
	
	int x = equalityTest(667,-555);

	if(x < 0)
		check = "-1";
	else if(x == 0)
		check = "0";
	else 
		check = "1";
		
	postTestingMessage("1", check);

	check = "dang this is taking a long time.";

	
	//TESTING floatIsEqual
	preTestingMessage("floatIsEqual","6.67 is equal to 3.14 to the precision of 2.0", "false");
	
	(floatIsEqual(6.67,3.14,2.0))? check = "true" : check = "false";
	
	postTestingMessage("false", check);

	check = "this next one seems hard";


	//TESTING isInt
	preTestingMessage("isInt","abcd is an integer", "false");
	
	(isInt("abcd"))? check = "true" : check = "false";

	postTestingMessage("false", check);

	
	check = "this next one seems hard";


	//TESTING isInt AGAIN
	preTestingMessage("isInt","123 is an integer", "true");
	
	(isInt("123"))? check = "true" : check = "false";

	postTestingMessage("true", check);

	check = "That was a doozy to figure";
	

	//TEST numbersPresent
	preTestingMessage("numbersPresent","abc123 has numbers present","true");

	(numbersPresent("abc123"))? check = "true" : check = "false";

	postTestingMessage("true", check);

	check = "ez pz";


	//TESTING lettersPresent
	preTestingMessage("lettersPresent","abc123 has letters","true");

	(lettersPresent("abc123"))? check = "true" : check = "false";
	
	postTestingMessage("true", check);

	check = "fingers gettin tired";

	
	//TESTING containsSubString
	preTestingMessage("containsSubString","abc is in abcdef", "true");

	(containsSubString("abc","abcdef"))? check = "true" : check = "false";
	
	postTestingMessage("true", check);

	check = "Dang this is getting tedious";

	
	//TESTING wordCount
	preTestingMessage("wordCount", "(a b c) has a word count of 3", "true");

	cout << "As the messaging display function being used only takes strings";
	cout << " the actual value of the word count is: " << wordCount("a b c");
	cout << endl;
	cout << endl;

	(wordCount("a b c") == 3)? check = "true" : check = "false";

	postTestingMessage("true", check);
	
	check = "it's been a long 6 hours";

	//TESTING toUpper
	preTestingMessage("toUpper", "toUpper changes all lowercase to uppercase for the sentence: abc123", "ABC123");

	postTestingMessage("ABC123", toUpper("abc123"));


	//TESTING toLower
	preTestingMessage("toLower", "toLower changes all uppercase letters to lowercase letters in the sentence: aBC123", "abc123");

	postTestingMessage("abc123", toLower("aBC123"));



	//TESTING getINT
	preTestingMessage("getInt", "you are prompted for an integer and properly enter an integer. \nPlease enter whatever you'd like to test the function. \nEventually, type in an integer. ", "(Whatever Integer you entered)");
	
	int testing = getInt();


	//This is just so I don't have to rewrite the prompt style
	postTestingMessage("Whatever integer came out", "Whatever integer came out");

	
		
}

































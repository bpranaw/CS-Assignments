/**********************************************************************************************************************************************************
 * PROGRAM NAME:
 * 	String Manipulator
 *
 * AUTHOR:
 * 	Pranaw Bajracharya 
 *
 * DESCRIPTION:
 *	Solicits the name of a text file from the user.
 *	Will reprompt user until they enter a correct
 *	filename.
 *
 *	Then the user has five options:
 *		1) Vowels vs Consonants comparison - Compares the number of vowels and
 *		   				     consonants
 *
 *		2) Letter Swap - The user enters a letter to search for and a letter
 *				 to replace the searched letter with and the program
 *				 will execute those actions.
 *
 *		3) Flip - Reverses the order of each character in the string
 *
 *		4) Palindrome Detector - Tells if the string is a palindrme
 *
 *		5) Words Frequency - Asks the user how many words they want to search for
 *				     Asks the user what those words are
 *				     Searchs the text for those words and tells the user how many of those words there are
 *
 * INPUTS:
 *	The name of a text file
 *
 * OUTPUTS:
 *	(Depends on the Option)
 * *******************************************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;


//FUNCTION PROTOTYPES*****************************************************************

//HOME SCREEN
void homeScreen();
void homeScreenMessage();
void solicitFileName();
void fileToCstring(ifstream&);
void optionSelector(char*);

//FOR WHATEVER FUNCTION NEEDS IT/MISC
int simplifyLetterASCII(char);

//FOR OPTION 1
void vowelsConsonantComparison(char*);

//FOR OPTION 2
void letterSwapPrompt(char*);
void letterSwap(char*, char searchLetter, char replaceLetter);

//FOR OPTION 3
void flip(char*);

//FOR OPTION 4
void palindromeDetector(char*, int);
void palindromePurger(char*);

//FOR OPTION 5
void wordPrompter(char*);
void frequencyPurger(char*, char**, int);
void wordChecker(char*, char**, int, int);

//END PROTOTYPES**********************************************************************

//MAIN********************************************************************************
int main()
{
	//Infinite loop to run the home screen
	while(1)
	{
		homeScreen();	
	}
}
//END MAIN****************************************************************************

//Functions***************************************************************************


//HOMESCREEN FUNCTIONS****************************************************************

/******************************************************
 * Function Name: homeScreenMessage
 * Description: Contains the message outputted to the 
 * 		console when the user is at the home
 * 		screen
 * Input(s): N/A
 * Output(s): N/A
 *****************************************************/

void homeScreenMessage()
{
	//Message for the user
	cout << "*********************************************************************"<< endl << endl;
	cout << "Welcome to the Word Manipulator Program!" << endl;
	cout << "You will be prompted for a text file and\ncan choose different options based on that text" << endl;
cout << "This program has five options:\n	1) Compare the # of vowels of a text to the # of consonants" << endl;
cout << "	2) Search for a letter and swap the instances of that letter with another" << endl;
	cout << "	3) Flip the text (Put it in the reverse order)" << endl;
	cout << "	4) Tell if a specific text is a palindrome" << endl;
	cout << "	5) Count the frequency of words in a text" << endl;
}

/******************************************************
 * Function Name: homeScreen
 * Description: The home screen which allows the user
 * 		to use the program or exit the program
 * Input(s): N/A
 * Output(s): N/A
 *
 *****************************************************/
void homeScreen()
{

	//Asks the user if they want to use the program
	
	char choice;
	
	cout << endl << "Do you want to use the program? If not type Q, otherwise enter any other value." << endl;
	cin >> choice;
	
	//Program exit condition
	if(int(choice) == 81 || int(choice) == 113)
		exit(0);
	else
	{
		//Messages the user about the program's
		//capabilities
		homeScreenMessage();
	
		//Get the file name
		solicitFileName();
	}

}

/******************************************************
 * Function Name: solicitFileName
 * Description: Asks the user for the file name and
 * 		checks to see if it actuall exists
 * Input(s): N/A
 * Output(s): N/A
 *
 *****************************************************/
void solicitFileName()
{
	//Declaration of the file name varaible and
	string fileName;
	
	//the CHECK variable for the error check loop
	bool check = false;

	//Declares object of input file stream
	ifstream inputFromFile;	
		
	cin.clear();
	cin.ignore(1000000,'\n');
	//Prompts the user for a file name until they
	//enter a real filename
	while(!check)
	{
		cout << "Enter the name of a .txt file.\nThe extension(.txt) included please." << endl;
		getline(cin,fileName);

		//Opens the file with the specific name
		inputFromFile.open(fileName.c_str());
	
		if(!inputFromFile.fail())
			check = true;
		else
		{
			//Clears the stream
			cin.clear();
			cin.ignore(10000000,'\n');

			//Tells the user what went wrong
			cout << "Error. File could not be found/could not be opened.\nPlease try again." << endl;			
		}
	}

	fileToCstring(inputFromFile);

}

/******************************************************
 * Function Name: fileToCstring
 * Description: Turns the contents of the file into a
 * 		C-Style string
 * Input(s): Address of inputFromFile (ifstream object)
 * Output(s): N/A
 *****************************************************/
void fileToCstring(ifstream &inputFromFile)
{
	/* The Assignment states we can't turn C-Style 
	 * Strings to C++ Strings, BUT NOT THE OTHER 
	 * WAY AROUND Therefore this simplifies the 
	 * process since we won't have to realloc 
	 * memory because c++ Strings do it already
	 */
	string cppStringTemp;
	string cppString;
	
	//Loop to go through the entire text file
	while(!inputFromFile.eof())
	{
		//Adds the text file to the string
		//Line by line
		getline(inputFromFile, cppStringTemp);
		cppString += cppStringTemp + '\n';	
	}

	//Closes file
	inputFromFile.close();


	//Adds 1 for the index to account for the
	//null character
	int x = cppString.length() + 1;

	//C-STYLE STRING ON THE HEAP *****************************************************************************************************
	char* usersCstring = new char[x];

	//Goes through the C-style string
	//assigns the C++ Stirng to the C-String at
	//the Index
	for(int i = 0; i < x; ++i)
	{
		usersCstring[i] = cppString[i];
	}	

	optionSelector(usersCstring);	
	
	//CLEARS THE HEAP
	delete[] usersCstring;	
}

/******************************************************
 * Function Name: optionSelector
 * Description: Selects one of the 5 options
 * Input(s): Address of cString of text (on the HEAP)
 * Output(s): N/A
 *****************************************************/
void optionSelector(char *cString)
{
	//Variable to make sure the user is entering correct values
	bool check = false;

	//Variable to hold the user's choice
	int choice = 0;
	
	//Was getting errors and these seemed to fix them
	//So they are necessary
	cin.clear();
	cin.ignore();

	while(!check)
	{
		//Message to the user and actually getting input from the user
		cout << "Select an Option (1-5)\nLook above for a reminder of what they do." << endl;
		cin >> choice;

		//Error handling
		if(!cin)
		{
			//Clears the stream
			cin.clear();
			cin.ignore();
		
			//Tells them what they did wrong
			cout << "Enter a correct integer." << endl;
		}
		else
			check = true;
	}

	/* THIS HAS TO BE THIS LONG, AN IF STATEMENT WOULD BE LONGER
	   ALTERNATIVELY, THIS COULD BE PUT INT ANOTHER FUNCTION BUT THE TASK IS SO SIMPLE
	  THAT IT MIGHT HAS WELL BE PUT HERE
	
	  IT ADDS VERY LITTLE COMPLEXITY, SO IT MAKES MORE SENSE TO PUT IT HERE INSTEAD OF
	  PASSING THE CHOCE VARIABLE TO A NEW FUNCTION AND THEN DOING THE FOLLOWING.
	
	  THEREFORE, IT MIGHT MAKE THIS FUNCTION GO OVER 15 LINES, BUT IT MAKES MORE SENSE THAN
	  CALLING ANOTHER FUNCTION.
	  
	  ALSO, THIS SPECIFIC PART INHERENTLY IS GREATER THAN 15 (UNLESS IT'S AN IF STATEMENT, BUT
	  THAT'S EVEN MORE TEDIOUS TO WRITE)
	*/
	switch(choice)
	{
		case 1: 
			vowelsConsonantComparison(cString);
			break;
		case 2:
			letterSwapPrompt(cString);
			break;
		case 3:
			flip(cString);
			break;
		case 4:
			palindromePurger(cString);
			break;
		case 5:
			wordPrompter(cString);
			break;		
		default:
			cout << "There has been an error" << endl;
			break;
	}	
}
//END HOMESCREEN**********************************************************************

//OPTION ONE FUNCTIONS****************************************************************

/******************************************************
 * Function Name: vowelsConsonantComparison
 * Description: Takes in a string array and checks the
 * 		# of vowels and consonants, then 
 * 		compares them.
 * Input(s): The user's string (a char array)
 * Output(s): N/A
 *****************************************************/
void vowelsConsonantComparison(char* cString)
{
	//Figures out the length of the array
	int length = strlen(cString);

	//Variables to hold the vowel and consonant #
	int vowelCount = 0;
	int consonantCount = 0;

	//Loops through the entire length of the array
	for(int i = 0; i < length; ++i)
	{
		//An array that contains the ASCII values of vowels
		int vowelArray[10] = { 65, 69, 73, 79, 85, 97, 101, 105, 111, 117};

		//For some reason there were hidden values adding to the consonant
		//count, so I HAD to make this STUPIDLY long array as a solution
		//An array that contains the ASCII consonant values
		int consonantArray[42] = {66, 67, 68, 70, 71, 72, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90, 98, 99, 100, 102, 103, 104, 106, 107, 108, 109, 110, 112, 113, 114, 115, 116, 118, 119, 120, 121, 122};
 
		//Loops through vowel array
		for(int j = 0; j < 10; ++j)
		{
			//Adds to vowel count if vowel
			if(cString[i] == vowelArray[j])
				vowelCount++;
		}

		//Loops through consonant array
		for(int k = 0; k < 42; ++k)
		{
			//Adds to consonant count if consonant
			if(cString[i] == consonantArray[k])
				consonantCount++;
		}		
				
	}	

	//Tells them the comparison
	if(vowelCount == 0 & consonantCount == 0)
		cout << "There are no vowels or consonants" << endl;
	else if(vowelCount == consonantCount)
		cout << "# of vowels == # of consonants" << endl;
	else
		cout << "# of vowels != # of consonants" << endl;

}




//END OPTION ONE FUNCTIONS************************************************************

//OPTION TWO FUNCTIONS****************************************************************

/******************************************************
 * Function Name: letterSwapPrompt
 * Description: Prompts the user for two letters
 * 		1) To search for in their string
 * 		2) To replace with in their string
 *
 * Input(s): C-style string (pointer)
 * Output(s): N/A 
 *****************************************************/
void letterSwapPrompt(char* cString)
{
	//Variable declarations of letters
	char searchLetter, replaceLetter;

	//Message to user
	cout << "Enter two letters.\n1) One to search for\n2) One to replace the searched letter with\nIf you enter any improper values like 1,2,3,!,], etc., the letter A will be used automatically.\nTherefore, please enter correct values." << endl;

	//Actual prompts for letters
	cout << endl << "Enter the search letter" << endl;
	cin >> searchLetter;

	cout << endl << "Enter the replace letter" << endl;
	cin >> replaceLetter;

	//Users simplify int to simplify the process
	//and deal with improper values
	searchLetter = simplifyLetterASCII(searchLetter);
	replaceLetter = simplifyLetterASCII(replaceLetter);

	//Actually searches and replaces the letters
	letterSwap(cString, searchLetter, replaceLetter);
}

/******************************************************
 * Function Name: letterSwap
 * Description: Searches for one letter and replaces
 * 		that letter with the replace letter
 * 		Maintains capitalization
 * Input(s): C-Style string (pointer)
 * 	     The search letter (char)
 * 	     The replace letter (char)
 * Output(s): N/A 
 *****************************************************/
void letterSwap(char* cString,char searchLetter,char replaceLetter)
{
	//Determines the length of the array
	int length = strlen(cString);
	
	
	cout << endl << "You new string: " << endl; 
	
	//Goes through the string
	for(int i = 0; i < length; ++i)
	{
		//For capital letters
		if(cString[i] == searchLetter)
			cString[i] = replaceLetter;
	
		//For lowercase letters
		if(cString[i] == searchLetter + 32)
			cString[i] = replaceLetter + 32;

		//Prints out the specific character
		cout << cString[i];
	}
	cout << endl;
}

//END OPTION TWO FUNCTIONS************************************************************

//OPTION THREE FUNCTIONS**************************************************************

/******************************************************
 * Function Name: flip
 * Description: Reverses a string
 * Input(s): The user's string (pointer)
 * Output(s): N/A
 *****************************************************/
void flip(char* cString)
{
	//Finds the length of the cString (strlen doesn't include the null terminator)
	int length = strlen(cString);
	
	//Made a new string on the heap anyways. +1 is for the null terminator***************************************************************************************************
	char* flippedString = new char[length + 1];

	//Loops through cString string backwards, but through the new stirng forwards
	for(int i = length - 1; i >= 0; --i)
	{
		//To go through the flipped string 
		int flippedIndex = length - 1 - i;
	
		//Actually flips
		flippedString[flippedIndex] = cString[i];

		//Prints out the string
		cout << flippedString[flippedIndex];
	}
	
	//Cleans the heap
	delete[] flippedString;

}

//END OPTION THREE FUNCTIONS**********************************************************

//OPTION FOUR FUNCTIONS***************************************************************

/******************************************************
 * Function Name: palindromePurger
 * Description: Gets rid of any non letters from a
 * 		string
 * Input(s): The user's string (pointer)
 * Output(s): N/A
 *****************************************************/
void palindromePurger(char* cString)
{
	//Variable to hold the count of the things we are
	//getting rid of
	int nonLetterCounter = 0;

	//Length of the string (not counting the null terminator)
	int length = strlen(cString);

	//Loop to go through the entire string
	for(int i = 0; i < length; ++i)
	{
		//NOT TECHNICALLY NECESSARY, BUT IT MAKES THE IF STATEMENT NICER
		char x = cString[i];
		
		//Counts the amount of nonLetters
		if(!((x > 64 & x < 91) || (x > 96 & x < 123)))
			nonLetterCounter++;
	}

	//C-STYLE CHARACTER ARRAY ON THE HEAP*********************************************************************************************
	char* purgedString = new char[length - nonLetterCounter + 1];

	//Variable for indexing of the NEW STRING
	int letterCount = 0;

	//For loop to go through the ORIGINAL STRING
	for(int i = 0; i < length; ++i)
	{
		//NOT TECHNICALLY NECESSARY, BUT IT MAKES THE IF STATEMENT NICER
		char x = cString[i];

		//If it's a letter
		if((x > 64 & x < 91) || (x > 96 & x < 123))
		{
			//Puts it into the NEW STRING
			purgedString[letterCount] = simplifyLetterASCII(x);

			//Increments the index
			letterCount++;		
		}
	}

	//Passes the NEW STRING to the detector
	palindromeDetector(purgedString, length - nonLetterCounter);

	//Cleans the heap
	delete[] purgedString;
}

/******************************************************
 * Function Name: palindromeDetector
 * Description: Checks to see if the entered string is
 * 		a palindrome
 * Input(s): The user's NEW string (pointer)
 * 	     The length of the string (int)
 * Output(s): N/A
 *****************************************************/
void palindromeDetector(char* purgedString, int length)
{
	//Index to go through the string backward
	//Is 1 to skip over the null terminator
	int reverseIndex = 1;

	//Variable to contain whether it is or is not a palindrome
	bool check = true;
	
	//Loop to go through the entire string
	for(int i = 0; i < length; ++i)
	{
		//Sets the reverse index relative to the index 
		//so the reverse comparison can go backwards 
		reverseIndex = length - 1 - i;		

		//Checks to see if the corresponding ends are the same
		if(purgedString[i] != purgedString[reverseIndex])
		{

			//They are NOT palindromes
			check = false;
		}
		//Prints out the thing it is comparing
		//THIS IS NOT NECESSARY BUT IT IS NICE FOR TESTING
		cout << purgedString[i] << ' ' << purgedString[reverseIndex] << endl;
	}

	//Will print out a message to the user depending on if it is a
	//palindrome or not.
	if(check)
		cout << endl << "This IS a palindrome" << endl;
	else
		cout << endl << "This is NOT a palindrome" << endl;
}

//END OPTION FOUR FUNCTIONS***********************************************************

//OPTION FIVE FUNCTIONS***************************************************************

/******************************************************
 * Function Name: wordPrompter
 * Description: Takes in how many words (determined by
 * 		the user) and what those words are
 * Input(s): cString (users' string)
 * Output(s): N/A 
 *****************************************************/
void wordPrompter(char* cString)
{

	//N number of words determined by user
	int wordCount;

	//Message and actual input from the user
	cout << "How many words would you like?\nEnter only positive numbers please, otherwise you will only get 1 word maximum\nAt the end of the function, the search frequency will be put into the out.txt file" << endl;
	cin >> wordCount;

	//Checks to make sure they didn't enter negative words
	if(!cin || wordCount < 0)
	{
		//Necessary so other inputs work properly
		cin.clear();
		cin.ignore(1000000, '\n');
		
		//Makes the amount of words 1 if they enter invalid values
		//(Words are C-Style strings therefore 2-D array is necessary)
		wordCount = 1;
	}
	
	//2-D array on the HEAP to store the # of words and the words****************************************************************************
	char** cStringArray = new char*[wordCount];
	
	//Goes through the nth word
	for(int i = 0; i < wordCount; ++i)
	{
		//Assigns a length (No word should be longer than the string) to
		//Each C-Style string
		cStringArray[i] = new char[strlen(cString)];

		//Gets the input from the user;
		cout << "Enter a word" << endl;
		cin >> cStringArray[i];
					
	}
	
	frequencyPurger(cString, cStringArray, wordCount);
	
	//This the deleting is REQUIRED to be done in multiple steps
	//Otherwise we would have memory leaks
	
	//For deleting the branches
	for(int i = 0; i < wordCount; ++i)	
		delete[] cStringArray[i];
	
	//Deleting the main array
	delete[] cStringArray;	
}

/******************************************************
 * Function Name: frequencyPurger
 * Description: Gets rid of any non letters excluding 
 * 		whitespace
 * Input(s): The user's string (pointer)
 * 	     The user's input words (2D array)
 * 	     The # of words (int)
 * Output(s): N/A
 *****************************************************/
void frequencyPurger(char* cString, char** cStringArray, int wordCount)
{
	//Variable declaration for the characters we're getting rid of
	int nonLetterCounter = 0;

	//Length of the input string excluding the null terminator
	int length = strlen(cString);

	//Loop to go through the user's string
	for(int i = 0; i < length; ++i)
	{
		//Variable ONLY EXISTS TO SIMPLIFY writing the if statement
		//NOT TECHNICALLY NECESSARY
		char x = cString[i];

		//Adds to the counter of things we're getting rid of
		if(!((x > 64 & x < 91) || (x > 96 & x < 123) || x == 32))
			nonLetterCounter++;
	}

	//Makes a new string on the heap to hold the original string(if we
	//got rid of all the unnecssary components)
	char* purgedString = new char[length - nonLetterCounter + 1];
	
	//A counter to work for the index of our NEW STRING
	int letterCount = 0;

	//Loop to go through the ORIGINAL STRING again
	for(int i = 0; i < length; ++i)
	{
		//Variable ONLY EXISTS TO SIMPLIFY writing the if statement
		//NOT TECHNICALLY NECESSARY
		char x = cString[i];
	
		//If the value is something we want in our NEW STRING
		if((x > 64 & x < 91) || (x > 96 & x < 123) || x == 32)
		{
			//Puts it in our NEW STRING
			purgedString[letterCount] = simplifyLetterASCII(x);
			//Increases index to next space
			letterCount++;		
		}
	}

	//Passes our cleaned up NEW STRING to the next function	
	wordChecker(purgedString, cStringArray, wordCount, length - nonLetterCounter);

	//Deletes the NEW STRING
	delete[] purgedString;

}

/******************************************************
 * Function Name: wordChecker
 * Description: Checks to see how many instances of the
 * 		word is in the string
 * 		Then prints out the results to a file
 * Input(s): The user's NEW STRING (pointer)
 * 	     The user's input words (2D array)
 * 	     The # of words (int)
 * 	     Length of the NEW STRING
 * Output(s): N/A
 *****************************************************/
void wordChecker(char* purgedString, char** cStringArray, int wordCount, int purgedLength)
{
	//IF YOU DON"T COUNT VARIABLE DECLARATIONS, THIS IS 15 LINES

	//Creates/Opens a new file called "out.txt"
	ofstream outputToFile("out.txt");
	
	//Loop to go through the nth number
	for(int i = 0; i < wordCount; ++i)
	{
		//Variable to hold the # of instances of a search letter in the file
		int counter = 0;
		
		//Variable ONLY EXISTS TO SIMPLIFY writing the if statement
		//NOT TECHNICALLY NECESSARY
		int length = strlen(cStringArray[i]);

		//Loop to go through the NEW STRING
		for(int j = 0; j < purgedLength; j++)
		{
			
			//Variable to check COUNTING of words
			int check = false;

			//Checks to see if any of characters in the string match
			//the first character of the nth search word
			//Also makes sure there is ENOUGH SPACE in the string to
			//avoid out of bounds errors
			if(purgedString[j] == simplifyLetterASCII(cStringArray[i][0]) & (purgedLength - 1 - j >= length - 1))
			{	
				//Goes through the WORD
				for(int k = 0; k < length; ++k)
				{
			
					//If the word is actually in the string
					if(simplifyLetterASCII(cStringArray[i][k]) != purgedString[j+k])
						check = false;
					else
						check = true;
			
				}
		
				//Adds one to the counter if the word exists
				if(check)
					counter++;
			
			}
	
		}
		
		//Prints the WORD to the file
		for(int k = 0; k < length; k++)
			outputToFile << cStringArray[i][k];

		//Prints out the # of these words in the string
		outputToFile << ": " << counter << endl;

	}	
			
	//Closes the file
	outputToFile.close();
		
}

//END OPTION FIVE FUNCTIONS***********************************************************

//MISC FUNCTIONS**********************************************************************

/******************************************************
 * Function Name: simplifyLetterASCII
 * Description: Turns any letter into its capital
 * 		ASCII equivalent
 * Input(s): letter (char)
 * Output(s): ASCII capital equivalent 
 *****************************************************/
int simplifyLetterASCII(char letter)
{
	//Upper case region
	if(letter > 64 & letter < 91)
		return letter;
	//Lower case region
	else if(letter > 96 & letter < 123)
		return letter -32;
	//Alloqs spaces through
	else if(letter == 32)
		return 32;
	//In case of error, returns 'A'
	else
		return 65;
}

//MISC FUNCTIONS**********************************************************************


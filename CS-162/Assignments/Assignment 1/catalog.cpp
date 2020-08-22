/*************************************************************************************
* Program Name: Wizard Catalog Sorter (catalog.cpp)
* 
* Author: Pranaw Bajracharya
*  
* Description: This program is the wizard spellbook catalog sorter. It takes in the 
* 	       names of the files for the wizard and spellbook information. It will 
* 	       look through the Spellbook data and provide a sorted list (based on
* 	       user specifications) of all the data. The program allows them to either
* 	       print the information out to the screen or into a file. It will also 
* 	       allow each user as much access as they are permitted to have based on 
* 	       their rank.
*
* Input(s): Command Line Arguments:
* 		(runWizard)  (Wizard Information.txt) (Spellbook Information.txt)
*
* Outputs(s): The sorted spells will either be printed to the console or a file.
*************************************************************************************/
#include "catalog.h"

//INFORMATION STORAGE FUNCTIONS_______________________________________________________

/*************************************************************************************
 * Function Name: createWizards
 * Description: Takes in the number of wizards and allocates space on the heap for an
 * 		array of that size. Then it returns the pointer to that array
 * Input(s): Number of wizards (int)
 * Output(s): Pointer to array (wizard *)
 ************************************************************************************/
wizard * createWizards(int numberOfWizards)
{
	wizard * wizardArray = new wizard[numberOfWizards];
	return wizardArray;
}

/*************************************************************************************
 * Function Name: createSpellbooks
 * Description: Takes in the number of spellbooks and allocates space on the heap for 
 * 		an array of that size. Then it returns the pointer to that array.
 * Input(s): Number of spellbooks (int)
 * Output(s): Pointer to array (spellbook *)
 ************************************************************************************/
spellbook * createSpellbooks(int numberOfSpellbooks)
{
	spellbook * spellbookArray = new spellbook[numberOfSpellbooks];
	return spellbookArray;	
}

/*************************************************************************************
 * Function Name: createSpells
 * Description: Takes in the number of spells and allocates space on the heap for an
 * 		array of that size. Then it returns the pointer ot that array.
 * Input(s): Number of Spells (int)
 * Output(s): Pointer to array (spell *)
 ************************************************************************************/
spell * createSpells(int numberOfSpells)
{
	spell * spellArray = new spell[numberOfSpells];
	return spellArray;
}


/***************************************************************************************************
 * THIS IS POPULATED SPELL DATA BUT RENAIMED
 **************************************************************************************************/
/*************************************************************************************
 * Function Name: assignSpellBookInformation
 * Description: Takes the spellbook data and puts it into the spellbook 
 * 		array.
 * Input(s): Spellbook pointer (spellbook*)
 * 	     Number of Spellbooks (int)
 * 	     The spellbook Data (ifstream &)
 * Output(s): N/A
 ************************************************************************************/
void assignSpellbookInformation(spellbook* spellbookArray, int numberOfSpellbooks, ifstream& spellbookData)
{
	for(int i = 0; i < numberOfSpellbooks; i++)
	{
		spellbookData >> spellbookArray[i].title;
		spellbookData >> spellbookArray[i].author;
		spellbookData >> spellbookArray[i].numberOfPages;
		spellbookData >> spellbookArray[i].edition;
		spellbookData >> spellbookArray[i].numberOfSpells;

		spellbookArray[i].spellPointer = createSpells(spellbookArray[i].numberOfSpells);
		assignSpellInformation(spellbookArray[i].spellPointer, spellbookArray[i].numberOfSpells, spellbookData);



	}
	return;
}

/*************************************************************************************
 * Function Name: assignSpellInformation
 * Description: Takes the file and puts all the spell data from the file into
 * 		a spell array.
 * Input(s): The ifstream object
 * 	     The number of Spells (int)
 * 	     The spell array (spell*)
 * Output(s): N/A
 ************************************************************************************/
void assignSpellInformation(spell* spellArray, int numberOfSpells, ifstream& spellbookData)
{
	for(int i = 0; i < numberOfSpells; i++)
	{
		spellbookData >> spellArray[i].name;
		spellbookData >> spellArray[i].successRate;
		spellbookData >> spellArray[i].effect;

	}
	return;
}

//COMMAND LINE ARGUMENT CHECKERS------------------------------------------------------

/*************************************************************************************
 * Function Name: isCorrectNumberOfArguments
 * Description: Takes in argc from main anc checks to see if the correct number of 
 * 		arguments were entered. Then acts accordingly.
 * Input(s): The number of arguments (aka argc) (int)
 * Output(s): N/A
 ************************************************************************************/
void isCorrectNumberOfArguments(int numberOfArguments)
{
	//Checks to see if there are too little arguments
	if(numberOfArguments < 3)
	{
		cout << endl << "You've entered less than the necessary amount of Arguments" << endl;
		cout << endl << "Remember it's runWizard (wizard information file name.txt) (spellbook information file.txt)" << endl << endl;
		exit(1);
	}
	
	//Not necessary but might be helpful the user
	if(numberOfArguments > 3)
		cout << "You've entered more arugments than necessary. If you're files names and the order you entered them are correct, than entereing more than two file names doesn't matter." << endl;
	return;
}

/*************************************************************************************
 * Function Name: doFilesExist
 * Description: Takes in the arguments entered for filenames and checks if those files
 * 		exist. Will then accordingly give the user a message
 * Input(s): Name of wizard file (string)
 * 	     Name of spellbook file (string)
 * Output(s): N/A
 ************************************************************************************/
void doFilesExist(string wizardFile, string spellbookFile)
{
	//We assume the files exist until proven otherwise
	bool doFilesExist = true;

	//Creates an input stream object so we can open files 
	ifstream inputFile;
	
	//Opens the wizard file
	inputFile.open(wizardFile.c_str());

	//Checks for failure to open file and enables exit if so
	if(inputFile.fail())
	{
		cout << endl << "You've entered a wizard file name for a file that doesn't exist." << endl;
		doFilesExist = false;
	}
	//Closes file
	inputFile.close();

	//Opens the spellbook file
	inputFile.open(spellbookFile.c_str());
	
	//Checks for failure to open file and enables exit if so
	if(inputFile.fail())
	{
		cout << endl <<"You've entered a spellbook file name for a file that doesn't exist." << endl; 
		doFilesExist = false;
	}
	//Closes the file
	inputFile.close();

	if(!doFilesExist)
	{
		cout << endl << "Exiting..." << endl << endl;
		exit(1);
	}

	return;
}

/*************************************************************************************
 * Function Name: parseWizardData
 * Description: This function calls other functions to take data from the wizard file
 * 		and place it into a C++ string and then into the wizard array. Then
 * 		returns the point to he wizard array.
 * Input(s): The name of the file (string)
 * Output(s): The Wizard Array (wizard *)
 ************************************************************************************/
 wizard * parseWizardData(string fileName, int& numberOfWizards)
{
	ifstream inputFile;	
	
	//Opens the file
	inputFile.open(fileName.c_str()); 	

	//Gets the number of wizards from the first line of the file
	inputFile >> numberOfWizards;	
	
	//Creates the wizard array
	wizard * wizardArray = createWizards(numberOfWizards);

	//Gets the information from the file and puts it into the wizard array
	assignWizardInformation(wizardArray, numberOfWizards, inputFile);

	//Closes the file
	inputFile.close();
	
	return wizardArray;
}

/*************************************************************************************
 * Function Name: assignWizardInformation
 * Description: Takes the wizard data and puts it into the wizard Array (all
 * 		the bits of informatio).
 * Input(s): Wizard Array (wizard*) 	     
 * 	     Wizard Data (string)
 * Output(s): N/A
 ************************************************************************************/
void assignWizardInformation(wizard* wizardArray, int numberOfWizards, ifstream &wizardData)
{

	for(int i = 0; i < numberOfWizards; i++)
	{
		wizardData >> wizardArray[i].name;
		wizardData >> wizardArray[i].ID;
		wizardData >> wizardArray[i].password;
		wizardData >> wizardArray[i].positionTitle;
		wizardData >> wizardArray[i].beardLength;

	}
	return;
}

//WIZARD LOGIN________________________________________________________________________

/*************************************************************************************
 * Function Name: wizardLogin
 * Description: Calls the other functions that lets the wizard login
 * Input(s): Wizad Array (wizard *)
 * 	     Number of wizards (int)
 * 	     Permission status (bool)
 * Output(s): N/A
 ************************************************************************************/
void wizardLogin(wizard* wizardArray, int numberOfWizards, bool& permission)
{
	bool check = false;
	int ID = 0;
	
	cout << "*********************************************************************" << endl;
	cout << endl << "Welcome to the Wizard Login Portal." << endl << endl;
	cout << "You will have three attemps to login." << endl << endl;


	for(int i = 0; i < 3; i++)
	{ 
		ID = integerCheck();
		check = loginCheck(wizardArray, numberOfWizards, ID);
		if(check)
			break;
	}
	
	if(check)
	{
		 permission = welcomeMessage(wizardArray, ID);		
	}
	else
	{
		cout << "You have failed to login too many times.\nExiting..." << endl;
		exit(1);
	}
	return;
}

/*************************************************************************************
 * Function Name: integerCheck
 * Description: Prompts the user for an ID number and checks to see if it's an integer
 * 		until they actually enter an integer ID.
 * Input(s): N/A
 * Output(s): ID number (int)
 ************************************************************************************/
int integerCheck()
{
	int ID = 0;
	bool check = false;

	while(!check)
	{
		cout << "PLease enter a valid ID numbers. ID numbers can only be integers." << endl << endl;
		cin >> ID;
		
		if(!cin)
		{
			cout << "You have entered an invalid ID number" << endl;
			cin.clear();
			cin.ignore(1000000,'\n');
		}
		else
			check = true;
	}

	return ID;	
}

/*************************************************************************************
 * Function Name: loginCheck
 * Description: Checks to see if the credentials entered match any in the Wizard Array
 * 		and will return true if so.
 * Input(s): Wizaard Array (wizard*)
 * 	     numberOfWizards(int)
 * 	     ID (int)
 * Output(s): Check if credentials match (bool)
 ************************************************************************************/
bool loginCheck(wizard * wizardArray, int numberOfWizards, int& ID)
{
	int wizardIndex = 0;
	int tempID;

	for(int i = 0; i < numberOfWizards;i++)
	{
		if(ID == wizardArray[i].ID)
			wizardIndex = i;
	}
	
	string password;

	cout << "Please enter a password." << endl;
	cin >> password;

	
	if(password.compare(wizardArray[wizardIndex].password) != 0)
	{
		cout << "You've entered invalid login credentials." << endl << endl;
		return false;
	}
	else
	{
		ID = wizardIndex;
		return true;
	}
}	

/*************************************************************************************
 * Function Name: welcomeMessage
 * Description: It will welcome the user depending on who they are. Then it will 
 * 		return either true or false baised on death access permission (rank).
 * Input(s): Wizard Array (wizard *)
 * 	     Where they are in the index (int)
 * Output(s): If they have permission or not.
 ************************************************************************************/
bool welcomeMessage(wizard* wizardArray, int wizardIndex)
{
	//Welcome message
	cout << endl << endl <<"______________________________________________________" << endl << endl;

	cout << "Successful login" << endl << endl;
	cout << "Welcome " << wizardArray[wizardIndex].name << endl;
	cout << "ID: " << wizardArray[wizardIndex].ID << endl;
	cout << "Rank: " << wizardArray[wizardIndex].positionTitle << endl;
	cout << "Beard Length: " << wizardArray[wizardIndex].beardLength << endl << endl;
	
	//Check for rank
	if(wizardArray[wizardIndex].positionTitle[0] == 83 || wizardArray[wizardIndex].positionTitle[0] == 115)
		return false;
	else
		return true;

}

//CLEARING THE HEAP FUNCTIONS_________________________________________________________

/*************************************************************************************
 * Function Name: deleteInformation
 * Description: Takes in the pointers to all the arrays allocated on the heap and 
 * 		their sizes, then calls the functions that will clear that space from
 * 		the heap.
 * Input(s): Wizard Array Pointer (wizard *)
 *
 * 	     Spellbook Array Pointer (spellbook *)
 * 	     Number of spellbooks (int)
 *
 * Output(s): N/A
 ************************************************************************************/
void deleteInformation(wizard * wizardArray, spellbook * spellbookArray, int numberOfSpellbooks)
{
	delete[] wizardArray;
	
	for(int i = 0; i < numberOfSpellbooks; i++)
	{
		delete[] spellbookArray[i].spellPointer;		
	}

	delete[] spellbookArray;
	
	return;
}


//SORTING FUNCTIONS___________________________________________________________________________________________________________________________________________________________________

/*************************************************************************************
 * Function Name: choseOptions
 * Description: Allows the user to use what sorting method they want
 * Input(s): The Spellbook Array (spellbook*)
 * 	     The number of spellbooks (int)
 * 	     User's permission level (bool)
 * Output(s): N/A 
 ************************************************************************************/
void chooseOptions(spellbook* spellbookArray, int numberOfSpellbooks, bool permission)
{
	//MEassage to the student
	cout << "How do you want the Catalog sorted?" << endl;
	cout << "1) Sort spellbooks by number of pages" << endl << "2) Sort spells by groups." << endl << "3) Sort spellbooks by average success rate of spells within" << endl;
	cout << endl <<"Enter your choice. If you don't enter 1,2, or 3, your choice will be 1 by default." << endl;
	
	//The student gets to chose his option
	char choice = 'a';
	cin >> choice;

	//Memory allocation for the sorted array
	spellbook* sortedArray = createSpellbooks(numberOfSpellbooks);

	//Default option
	int option = 1;

	//Initiates a sort based on the users' choice
	//Choice 2
	if(choice == 50)
	{

		delete [] sortedArray;
		int numberOfSpells = calculateNumberOfSpells(spellbookArray, numberOfSpellbooks);
		spell* sortedSpellArray = createSpells(numberOfSpells);
				
		sortByGroup(spellbookArray, sortedSpellArray, numberOfSpells, numberOfSpellbooks);
		printOption2(sortedSpellArray, numberOfSpells, permission);

	}
	//Choice 3	
	else if(choice == 51)
	{
		sortBySuccessRate(spellbookArray, sortedArray, numberOfSpellbooks);
		printOption3(sortedArray, numberOfSpellbooks, permission);
	}
	//Choice 1 (default)
	else
	{
		sortByPages(spellbookArray, sortedArray, numberOfSpellbooks);
		printOption1(sortedArray, numberOfSpellbooks, permission);
	}
	//Prints out our array according to the parameters (student rank and choice)

}

/*************************************************************************************
 * Function Name: sortByPages
 * Description: Sorts the spellbooks by their number of pages
 * Input(s): The spellbook array (spellbook*)
 * 	     The (not as of yet) sorted array (spellbook*)
 * 	     The number of spellbooks
 * Output(s): N/A
 ************************************************************************************/
void sortByPages(spellbook* spellbookArray, spellbook* sortedArray, int numberOfSpellbooks)
{
	int currentVariable = 0, lowestVariable = 0, previousVariable = 999999999, index = 0;


	//This will find the lowest number, loop again, find the lowest number, loop again
	//Until it has sorted them in order.
	//Outer loop represents the SORTED Array
	for(int i = 0; i < numberOfSpellbooks; i ++)
	{
		//This will allow the loop to reset when we've found our
		//lowest number 
		//Inner loop represents the NONSORTED array
		previousVariable = 999999999;
		for(int j = 0; j < numberOfSpellbooks; j++)
		{
			//Makes the current variable whatever variable the loop is 
			//on (in order but not sorted)
			currentVariable = spellbookArray[j].numberOfPages;

			//The "lowest variable" is what we calculated to be the 
			//variable directly before whatever the current "lowest variable is"
			if(currentVariable > lowestVariable & currentVariable < previousVariable)
			{		
				//Makes the value we just had as the new previous
				//If we don't get to another previous
				//That means we've found the lowest in what 
				//variables we have left to sort
				previousVariable = currentVariable;
			
				//This picks out the position of the lowest variable
				//that has yet to be sorted
				index = j;				
			}
		
		}
		
			//Updates the "floor" variable to what we had last time
			lowestVariable = previousVariable;

			//Since we've deduced this is the lowest variable of whatever
			//variables are left, we can put it into the sorted array.
			sortedArray[i] = spellbookArray[index];
	}
	return;
}

/*************************************************************************************
 * Function Name: sortByGroup
 * Description: Sorts all the spells by their effects
 * Input(s): The spellbook array (spellbook*)
 * 	     A sorted Spell array (spell*)
 * 	     The number of spells (int)
 * 	     The number of spell books (int)
 * Output(s): N/A
 ************************************************************************************/
void sortByGroup(spellbook* spellbookArray, spell* sortedArray, int numberOfSpells, int numberOfSpellbooks)
{


	spell* unsortedArray = createSpells(numberOfSpells);
	int indexU = 0;

	for(int i = 0; i < numberOfSpellbooks; i++)
	{	
		for(int j = 0; j < spellbookArray[i].numberOfSpells; j++)
		{
			unsortedArray[indexU] = spellbookArray[i].spellPointer[j];
			indexU++;
		}
	}

	int currentVariable = 0, lowestVariable = 0, indexJ = 0, previousVariable = 999999999;


	for(int i = 0; i < numberOfSpells; i++)
	{

		//This will allow the loop to reset when we've found our
		//lowest number 
		//Inner loop represents the NONSORTED array
		previousVariable = 99999999;
	

		for(int j = 0; j < numberOfSpells; j++)
		{
				
				
				//Makes the current variable whatever variable the loop is 
				//on (in order but not sorted)
				//Checks the priority of the element and spits out a number
				//comparable to our integers
			
				currentVariable = priorityChecker(unsortedArray[j]);

				//The "lowest variable" is what we calculated to be the 
				
				if(currentVariable > lowestVariable & currentVariable <  previousVariable)
				{		
					//Makes the value we just had as the new previous
					//If we don't get to another previous
					//That means we've found the lowest in what 
					//variables we have left to sort
					previousVariable = currentVariable;
			
					//This picks out the position of the lowest variable
					//that has yet to be sorted

						indexJ = j;	
						
				}
		

		}

		
		//Updates the "floor" variable to what we had last time
		lowestVariable = previousVariable;
		
		//Since we've deduced this is the lowest variable of whatever
		//variables are left, we can put it into the sorted array.
		sortedArray[i] = unsortedArray[indexJ];

	}


	delete[] unsortedArray;

	return;
}

/*************************************************************************************
 * Function Name: sortBySuccessRate
 * Description: Sorts the spellbooks by the average rate of success
 * Input(s): The spellbook array (spellbook*)
 * 	     A place to put the sorted array (spellbook*)
 * 	     The number of spellbooks (int)
 * Output(s): N/A
 ************************************************************************************/
void sortBySuccessRate(spellbook* spellbookArray, spellbook* sortedArray, int numberOfSpellbooks)
{
	calculateSuccessRate(spellbookArray, numberOfSpellbooks);

	int currentVariable = 0, lowestVariable = 0, previousVariable = 999999999, index = 0;

	//This will find the lowest number, loop again, find the lowest number, loop again
	//Until it has sorted them in order.
	//Outer loop represents the SORTED Array
	for(int i = 0; i < numberOfSpellbooks; i ++)
	{
		//This will allow the loop to reset when we've found our
		//lowest number 
		//Inner loop represents the NONSORTED array
		previousVariable = 999999999;
		for(int j = 0; j < numberOfSpellbooks; j++)
		{
			//Makes the current variable whatever variable the loop is 
			//on (in order but not sorted)
			currentVariable = spellbookArray[j].averageSuccessRate;

			//The "lowest variable" is what we calculated to be the 
			//variable directly before whatever the current "lowest variable is"
			if(currentVariable > lowestVariable & currentVariable < previousVariable)
			{		
				//Makes the value we just had as the new previous
				//If we don't get to another previous
				//That means we've found the lowest in what 
				//variables we have left to sort
				previousVariable = currentVariable;
			
				//This picks out the position of the lowest variable
				//that has yet to be sorted
				index = j;				
			}
		}
		
			
			//Updates the "floor" variable to what we had last time
			lowestVariable = previousVariable;

			//Since we've deduced this is the lowest variable of whatever
			//variables are left, we can put it into the sorted array.
			sortedArray[i] = spellbookArray[index];
	}
	return;
}

/*************************************************************************************
 * Function Name: calculateSuccessRate
 * Description: Calculates the average success rate for all the spells in a book
 * Input(s): The spellbook array
 * 	     The number of spellbooks
 * Output(s): N/A
 ************************************************************************************/
void calculateSuccessRate(spellbook* spellbookArray, int numberOfSpellbooks)
{
	float totalSum = 0;
	
	for(int i = 0; i < numberOfSpellbooks; i++)
	{
		for(int j = 0; j < spellbookArray[i].numberOfSpells; j++)
		{
			totalSum  += spellbookArray[i].spellPointer[j].successRate;
		}
			spellbookArray[i].averageSuccessRate = totalSum/ float(spellbookArray[i].numberOfSpells);
		
	}	
	return;
}

/*************************************************************************************
 * Function Name: calculateNumberOfSpells
 * Description: Calculates the total number of spells within the spellbook array
 * Input(s): The Spellbook array (spellbook*)
 * 	     The number of spellbooks (int)
 * Output(s): int
 ************************************************************************************/
int calculateNumberOfSpells(spellbook* array, int numberOfSpellbooks)
{
	int totalCount = 0;

	for(int i = 0; i < numberOfSpellbooks; i++)
		totalCount +=  array[i].numberOfSpells;

	return totalCount;
	
}

/*************************************************************************************
 * Function Name: priorityChecker
 * Description: Takes in a spell and assigns it a priority based on effect
 * Input(s): A spell (spell)
 * Output(s): Priority (int)
 ************************************************************************************/
int priorityChecker(spell currentSpell)
{
	//Checks the first letter (upper or lowercase) and returns a priority value

	//Bubbles
	if(currentSpell.effect[0] == 'b' || currentSpell.effect[0] == 'B')
		return 1;
	//Fire
	if(currentSpell.effect[0] == 'm' || currentSpell.effect[0] == 'M')
		return 2;
	//Memory loss
	if(currentSpell.effect[0] == 'f' || currentSpell.effect[0] == 'F')
		return 3;
	//Poison
	if(currentSpell.effect[0] == 'p' || currentSpell.effect[0] == 'P')
		return 4;
	//Death
	if(currentSpell.effect[0] == 'd' || currentSpell.effect[0] == 'D')
		return 5;

	//In case something somehow slips through the cracks
	return 1;
}

/*************************************************************************************
 * Function Name: safetyCheck
 * Description: Checks to see if a student is allowed to access a book
 * Input(s): The spellbook array (spellbook*)
 * 	     The current index
 * Output(s): The safe or not rating (bool)
 ************************************************************************************/
bool safetyCheck(spellbook* array, int index)
{
	//Strings to check for poison or death
	string poisonString = "poison";
	string deathString = "death";		

	//Goes through all the spells
	for(int i = 0; i < array[i].numberOfSpells; i++)
	{
		//This string is just used for writing/reading convience
		string x = array[index].spellPointer[i].effect;

		//Checks for poison or death
		if(poisonString.compare(x) == 0 || deathString.compare(x) == 0)
			return false;
	}

	//If it made it this far, it's safe
	return true;

}
/*************************************************************************************
 * Function Name: printOption1
 * Description: Prints out the results of the sort for option 1
 * Input(s): Spellbook  array (spellbook*)
 * 	     The number of Spellbooks (int)
 * 	     The level of cleareance (bool)
 * Output(s): N/A
 ************************************************************************************/
void printOption1(spellbook* array, int numberOfSpellbooks, bool permission)
{

	/* The Reason this file is needlessly long is I attempted to modularize it
 	   initially, but all the millions of different parts came up with millions
	   of different errors. They were very numerous and it was more of a viable
	   option to just restart them all in one place. I  hope this is alright and
	   somewhat readable. Sorry */


	//Message to the user_______________________________________________________
	cout << "How would you like to recieve this informatin?" << endl;
	cout << "1) Print to Console\n2) Print to File" << endl;
	cout << "If you don't enter 1 or 2, 1 will be selected by default." << endl;

	//Choice making_____________________________________________________________
		
	int choice = 1;

	cin >> choice;

	//Printing to file__________________________________________________________
	if(choice == 2)
	{

		//Set up____________________________________________________________
		//File name and ofstream object so the user can
		//Output to a file
		string fileName;
		ofstream outputFile;

		//Entering a filename_______________________________________________
		//Prompting the user for a file name
		cout << "Enter a filename" << endl;
		cin >> fileName;
		
		//Opening and writing the file______________________________________
		outputFile.open(fileName.c_str());
		
			
		//Loop to go through all the spellbooks
		for(int i = 0; i < numberOfSpellbooks; i++)
		{
			
			//PG-13 RATING______________________________________________
			//Checks if student is allowed to see the spellbooks
			bool safe = safetyCheck(array, i);
		
			//If not it will skip this book in printing
			if(!permission & !safe)
				continue;
			//Book will be printed
			else
				outputFile << array[i].numberOfPages << "  " << array[i].title << endl;
		}
		
		//Closes the file
		outputFile.close();	
	}
	//Printing to the console___________________________________________________
	else
	{
		
		for(int i = 0; i < numberOfSpellbooks; i++)
		{
			bool safe = safetyCheck(array, i);
			if(!permission & !safe)
				continue;
			else
				cout << array[i].numberOfPages << "  " << array[i].title << endl;
		}

	}

	delete[] array;

}

/*************************************************************************************
 * Function Name: printOption3
 * Description: Prints out the results of the sort for option 3
 * Input(s): Spellbook  array (spellbook*)
 * 	     The number of Spellbooks (int)
 * 	     The level of cleareance (bool)
 * Output(s): N/A
 ************************************************************************************/
void printOption3(spellbook* array, int numberOfSpellbooks, bool permission)
{

	/* The Reason this file is needlessly long is I attempted to modularize it
 	   initially, but all the millions of different parts came up with millions
	   of different errors. They were very numerous and it was more of a viable
	   option to just restart them all in one place. I  hope this is alright and
	   somewhat readable. Sorry */

	//Message to the user_______________________________________________________
	cout << "How would you like to recieve this informatin?" << endl;
	cout << "1) Print to Console\n2) Print to File" << endl;
	cout << "If you don't enter 1 or 2, 1 will be selected by default." << endl;

	//Choice making_____________________________________________________________
		
	int choice = 1;

	cin >> choice;

	//Printing to file__________________________________________________________
	if(choice == 2)
	{

		//Set up____________________________________________________________
		//File name and ofstream object so the user can
		//Output to a file
		string fileName;
		ofstream outputFile;

		//Entering a filename_______________________________________________
		//Prompting the user for a file name
		cout << "Enter a filename" << endl;
		cin >> fileName;
		
		//Opening and writing the file______________________________________
		outputFile.open(fileName.c_str());
		
			
		//Loop to go through all the spellbooks
		for(int i = 0; i < numberOfSpellbooks; i++)
		{
			
			//PG-13 RATING______________________________________________
			//Checks if student is allowed to see the spellbooks
			bool safe = safetyCheck(array, i);
		
			//If not it will skip this book in printing
			if(!permission & !safe)
				continue;
			//Book will be printed
			else
				outputFile << array[i].averageSuccessRate << "  " << array[i].title << endl;
		}
		
		//Closes the file
		outputFile.close();	
	}
	//Printing to the console___________________________________________________
	else
	{
		
		for(int i = 0; i < numberOfSpellbooks; i++)
		{
			bool safe = safetyCheck(array, i);
			if(!permission & !safe)
				continue;
			else
				cout << array[i].averageSuccessRate << "  " << array[i].title << endl;
		}

	}
	
	delete[] array;

}

/*************************************************************************************
 * Function Name: printOption2
 * Description: Prints out the results of the sort for option 2
 * Input(s): Spell array (spellbook*)
 * 	     The number of Spells (int)
 * 	     The level of cleareance (bool)
 * Output(s): N/A
 ************************************************************************************/
void printOption2(spell* array, int numberOfSpells, bool permission)
{
	

	/* The Reason this file is needlessly long is I attempted to modularize it
 	   initially, but all the millions of different parts came up with millions
	   of different errors. They were very numerous and it was more of a viable
	   option to just restart them all in one place. I  hope this is alright and
	   somewhat readable. Sorry */

	//Message to the user_______________________________________________________
	cout << "How would you like to recieve this informatin?" << endl;
	cout << "1) Print to Console\n2) Print to File" << endl;
	cout << "If you don't enter 1 or 2, 1 will be selected by default." << endl;

	//Choice making_____________________________________________________________
		
	int choice = 1;

	cin >> choice;

	//Printing to file__________________________________________________________
	if(choice == 2)
	{

		//Set up____________________________________________________________
		//File name and ofstream object so the user can
		//Output to a file
		string fileName;
		ofstream outputFile;

		//Entering a filename_______________________________________________
		//Prompting the user for a file name
		cout << "Enter a filename" << endl;
		cin >> fileName;
		
		//Opening and writing the file______________________________________
		outputFile.open(fileName.c_str());
		
			
		//Loop to go through all the spellbooks
		for(int i = 0; i < numberOfSpells; i++)
		{
			
			//PG-13 RATING______________________________________________
			//Checks if student is allowed to see the spells
			bool safe = true;

			if(array[i].effect[0] == 'd' || array[i].effect[0] == 'p')	
				safe = false; 
		
			//If not it will skip this book in printing
			if(!permission & !safe)
				continue;
			//Book will be printed
			else
				outputFile << array[i].effect << "  " << array[i].name << endl;
		}
		
		//Closes the file
		outputFile.close();	
	}
	else
	{
		
		for(int i = 0; i < numberOfSpells; i++)
		{
			
			//PG-13 RATING______________________________________________
			//Checks if student is allowed to see the spells
			bool safe = true;

			if(array[i].effect[0] == 'd' || array[i].effect[0] == 'p')	
				safe = false; 
		
			//If not it will skip this book in printing
			if(!permission & !safe)
				continue;
			//Book will be printed
			else
			cout << array[i].effect << "  " << array[i].name << endl;
		}

	}

	delete[] array;
}

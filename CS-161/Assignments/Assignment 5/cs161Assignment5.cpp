#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <string>

using namespace std;

//FUNCTION PROTOTYPES*****************************************************************************************************************************************************************

//MAIN MESSAGE
void mainMessage();

//COMMAND PROMPT CHECKER
int numberOfPlayersChecker(char*, int);
int numberOfRowsColumnsChecker(char*, int, string);

//GAMEPLAY*********************************
void playConnectFour(int, int, int);

//Board Related
char** buildBlankBoard(int&, int&);
void deleteBoard(char**, int&);
void printBoard(char**, int&, int&);

//Game Mechanics
void gameType(char**, int&, int&, int&);
void versusComputer(char**, int&, int&);
void versusHuman(char**, int&, int&);

//Moves
int piecePlacer(char**, int&, int&,char);
int playerMove(char**, int&, int&, bool*);
void computerMove(char**, int&, int&, int&, bool*, int&);

//Win Conditions
void isThereWinner(char**, int&, int&,int&, int&, bool*, char, string);
void isThereHorizontalWinner(char**, int&, int&,int&, int&, bool*, char);
void isThereVerticalWinner(char**, int&, int&,int&, int&, bool*, char);
void isThereDiagonalWinner(char**, int&, int&,int&, int&, bool*, char);
void isThereNegativeDiagonalWinner(char**, int&, int&,int&, int&, bool*, char);
bool isThereTie(char**, int&, int&, bool*);

//Player Moves
void playerOneMove(char**, int&, int&, bool*);
void playerTwoMove(char**, int&, int&, bool*);

//AI moves
void dumbAIChoice(char**, int&, int&, int&);
void smartAIChoice(char**, int&, int&, int&, int);

//MAIN********************************************************************************************************************************************************************************
int main(int argc, char* argv[])
{
	//Please disregard this to the line count. It's unnecessary but I like to include it to make the program look a bit clearn in the console.
	//It's just a message welcoming the user to the program
	mainMessage();

	int numberOfPlayers, numberOfRows, numberOfColumns;

	//Just a message to tell the user that 3+ arguments will be ignored
	if(argc > 4)
		cout << "You have entered more than 3 additional arguments(# of players, rows and columns)\nAll arguments past three additional have been disregarded\n" << endl;
	
	//Handles the cases with the right among ot arguements (all arguments past 3 additional are ignored)
	if(argc >= 4)
	{
		//Checks to see if the number of players entered were a valid value/reprompts if necessary
		numberOfPlayers = numberOfPlayersChecker(argv[1], strlen(argv[1]) + 1);

		//Checks to see if the rows entered were a valid value/reprompts if necessary
		numberOfRows = numberOfRowsColumnsChecker(argv[2], strlen(argv[2]) + 1, "Rows");

		//Checks to see if the columns entered were a valid value/reprompts if necessary
		numberOfColumns = numberOfRowsColumnsChecker(argv[3], strlen(argv[3]) + 1, "Columns"); 	
		
	}
	else
	{
		//This is an array of BAD ARGUMENTS that can be corrected in the individual functions
		//This is used as a proxy in case they enter less than the desired amounts of arguments
		char incorrectCommandArguments[] = { 'a','b', 'c', 'd'};
		
		//Tells the user what they did wrong
		cout << "You have entered less than the required number of arguments.\nYou will be prompted to enter them now." << endl << endl;	
	
		//Reprompts for a new number of players
		numberOfPlayers = numberOfPlayersChecker(incorrectCommandArguments + 1, 100);

		//Reprompts for a new number of rows
		numberOfRows = numberOfRowsColumnsChecker(incorrectCommandArguments + 2, 100, "Rows");

		//Reprompts for a new number of columns
		numberOfColumns = numberOfRowsColumnsChecker(incorrectCommandArguments + 3, 100, "Columns");
	}

	//Initiates the function to play the game
	playConnectFour(numberOfPlayers, numberOfRows, numberOfColumns);


	return 0;
}

//MAIN MESSAGE************************************************************************************************************************************************************************

/*********************************************************************************************
 * FUNCTION NAME: mainMessage
 * DESCRIPTION: It's just a message to the user
 * INPUTS: N/A
 * OUTPUTS: N/A
 ********************************************************************************************/
void mainMessage()
{
	cout << endl << "****************************************************************************************************************************************" << endl;
	cout << "Welcome to Connect Four by Pranaw Bajracharya!";
	cout << endl << "****************************************************************************************************************************************" << endl << endl;
}

//COMMAND LINE ARGUMENT CHECKER FUNCTIONS*********************************************************************************************************************************************

/*********************************************************************************************
 * FUNCTION NAME: numberOfPlayersChecker
 * DESCRIPTION: Checks to see if the number of players entered in the command prompt is a
 * 		valid value. 
 * 		If it is not, it it will reprompt the user for a value.
 * 		If it is, it will simply return that value.
 * INPUTS: The character array of the 2nd Argument/the first Additonal argument (Pointer)
 * 	   The size of the array, including the null pointer (int)	
 * OUTPUTS: The number of players (int)
 ********************************************************************************************/
int numberOfPlayersChecker(char* firstArgument,int size)
{
	//This is the variable that will ultimately be returned
	//Since the range of correct values is only 1-2, it will ONLY check the FIRST character
	//Additionally, the -48 is accounting for the ASCII number of 0 (ASCII 48)
	int numberOfPlayers = firstArgument[0] - 48;
	
	//Since above we only check the FIRST character, this will
	//make sure we don't miss bigger numbers (like 100 and 200 which would otherwise be correct)
	//as any multiple digit number will have a digit length greater than 2 (1+ digits and 1 null terminator)
	if(size > 2)
		numberOfPlayers = 100;
	
	//This is for checking if the value is correct
	//It's just used as the exit condition in a while loop
	bool check = false;
	
	while(!check)
	{
		
		if(numberOfPlayers == 1 || numberOfPlayers == 2)
			//exit condition
			check = true;
		else
		{
			//Tells the user what went wrong
			cout << "Your entry for number of players is invalid.\nPlease enter either 1 or 2." << endl;
		
			//Prompts for a new number until they enter something correct	
			cin >> numberOfPlayers; 
		
			//Clears the stream for the future
			cin.clear();
			cin.ignore(1000000, '\n');
		}
	}

	//If it gets to this point, it means the user has entered 
	//either 1 or 2 and thus a correct value has been achieved
	return numberOfPlayers; 
}

/*********************************************************************************************
 * FUNCTION NAME:numberOfRowsColumnsChecker
 * DESCRIPTION: Checks if the entered command line prompts for rows/columns are valid
 * 		If it is not, it will reprompt the user to enter correct values until they do
 * 		If it is, it will return the number of rows/columns
 * INPUTS: The cStyle String for the argument of rows/columns (pointer) 
 * 	   The size of the cStyle String (int)
 *	   A C++ string that will either be "Rows" or "Columns" (string)
 * OUTPUTS: Number of Rows/Columns (int)
 ********************************************************************************************/
int numberOfRowsColumnsChecker(char* argument, int size, string name)
{
	//This is the value that will be ultimately returned
	//It is just initialized at 4 just in case some shenanigans occur somehow
	int numberOfRowColumns = 4;

	//This is for when there's a 1 digit number/string (1 digit + null terminator)
	//Takes the character array and turns it into a manipulatable number
	if(size == 2)
		numberOfRowColumns = argument[0] - 48;
	//This is for when there's a 2 digit number/string like 15 and 20
	//Takes the character array and turns it into a manipulatable number
	else if(size == 3)
		//It takes the first digit and multiples it by 10 (as it is the tens place)
		//and adds that value to the second digit (which is the ones place so it is
		//fine as it is)
		numberOfRowColumns = (10 * (argument[0] - 48)) + (argument[1] - 48);
	//This is for bigger sizes which are no doubt too big or any other unforeseen cases
	else
		//This makes the number too big just so it will go through
		//Repromting later
		numberOfRowColumns = 100;

	//This variable is the exit condition for the while loop that checks to see if the
	//numbers are valid
	bool check = false;

	//This while loop checks to see if the numbers are valid and thus will cause 
	//continual reprompting until valid numbers are entered
	while(!check)
	{
		//This is the exit condition
		//i.e. a valid entry for rows/columns
		if(numberOfRowColumns >= 4 & numberOfRowColumns <= 20)
			check = true;
		else
		{
			//Tells the user what they did wrong
			cout << "Your entry for " << name << " is invalid.\nPlease enter a valid integer value at least 4 and at most 20." << endl;
			
			//Lets them enter another value
			cin >> numberOfRowColumns;
			
			//Cleans the stream for future use
			cin.clear();
			cin.ignore(1000000, '\n');
		}		
	}

	//If it gets to this point, we have a correct value (integer at least 4 and at most 20)
	return numberOfRowColumns;
}

//GAMEPLAY FUNCTIONS******************************************************************************************************************************************************************

/*********************************************************************************************
 * FUNCTION NAME: playConnectFour
 * DESCRIPTION: Initates the actual gameplay
 * 		Calls the function to create/ delete the board
 * 		Determines game type
 * 		and reprompts the user whether they want to play again
 * INPUTS: The number of players, rows, and columns (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void playConnectFour(int numberOfPlayers,int numberOfRows,int numberOfColumns)
{
	while(1)
	{
		char** board = buildBlankBoard(numberOfRows,numberOfColumns);
	
	
		//Game Type	
		if(numberOfPlayers ==1)
			versusComputer(board, numberOfRows, numberOfColumns);
		else
			versusHuman(board, numberOfRows, numberOfColumns);


		printBoard(board, numberOfRows, numberOfColumns);	
		//Deletes board
		deleteBoard(board, numberOfRows);
	
		cout << "Do you want to play again?\nEnter Y if so, otherwise enter anything else to exit." << endl;
			
		char choice = 'j';
		cin >> choice;


		if(choice != 'y' & choice != 'Y')
			break;
	}
	return;
}

/*********************************************************************************************
 * FUNCTION NAME: buildBlankBoard
 * DESCRIPTION: Declares a blank board on the heap with the given row and column values
 * 		Then it returns the address of the board
 * INPUTS: Rows and columns (int)
 * OUTPUTS: The address of the board (double pointer)
 ********************************************************************************************/
char** buildBlankBoard(int &rows,int &columns)
{
	char** board = new char*[rows];
	for(int i = 0; i < rows; i++)
	{
		board[i] = new char[columns];
		for(int j = 0; j < columns; j++)
			board[i][j] = ' ';
	}
	
	return board;
}

/*********************************************************************************************
 * FUNCTION NAME: deleteBoard
 * DESCRIPTION: Cleans up the heap by deleting the board
 * 		Deletes the branch arrays first (columns), then deletes the main array (rows)
 * INPUTS: Address of the board (double pointer)
 * 	   Rows and columns (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void deleteBoard(char** board,int &rows)
{
	for(int i = 0; i < rows; i++)
	{
		delete[]board[i];
	}
	delete[] board;
	
	return;
}

/*********************************************************************************************
 * FUNCTION NAME: printBoard
 * DESCRIPTION: Prints out the player's board
 * INPUTS: Address of the board (double pointer)
 * 	   Rows and columns (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void printBoard(char** board, int &rows, int &columns)
{
	//THIS FUNCTION IS 15+ (17 LINES)
	//JUSTIFICATION BELOW!!!!
	

	//This loop goes through the columns and numbers them
	for (int i = 0; i < columns; ++i)
	{
		//This if else statement separates the single digits with the double digits
		//This is technically not needed for grading, but I believe it is worth the
		//aesthetics for the two digit column labels
		//THEREFORE this is two lines more than necessary
		if (i < 9)
			cout << "  " << i + 1 << " ";
		else
			cout << " " << i + 1 << " ";		
	}

	//This is necessary because it HAS to go outside of the loops
	//to make the next row
	cout << endl;

	//This loop goes through the rows
	for (int i = 0; i < rows; i++)
	{

		//This lop goes through the columns
		for (int j = 0; j < columns; j++)
		{
			//Prints White pattern
			if (i % 2 == 0 && j % 2 == 0)
				cout << "|\033[30;47m " << board[i][j] << " "; 

			//Prints White pattern
			else if (i % 2 == 1 && j % 2 == 1)
				cout << "|\033[30;47m " << board[i][j] << " ";
			//Prints out Black pattern;
			else
				cout << "|\033[0m " << board[i][j] << " ";
			//Ends the pattern
			cout << "\033[0m";
		}
		//This is necessary because the cout HAS to be outside the lines
		//to make the next row
		cout << endl;
	}
	
	//This cout is UNECESSARY for the grading, therefore it addeds 1 line to the count
	//It is included because I simply liked the organizational space it provides 
	//AFTER the board is printed. It's just personal preference to make more spaces
	//in between the lines in the console, so it's not necessary for the line count
	cout << endl;
}

/*********************************************************************************************
 * FUNCTION NAME: gameType
 * DESCRIPTION: Determines what kind of game type (HUMAN vs COMPUTER or HUMAN vs HUMAN) it
 * 		will be
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to Rows and Columns (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void gameType(char** board, int& players, int& rows, int& columns)
{
	//Checks to see if it's 1 player or two
	if(players == 1)
		//Initiates the game against the computer
		versusComputer(board, rows, columns);
	else
		//Initiates the game against the human
		versusHuman(board, rows, columns);

	return;
}	
/*********************************************************************************************
 * FUNCTION NAME: versusComputer
 * DESCRIPTION: Iniates the game versus the computer
 * 		Asks if you would like a difficult computer or an easy one
 * 		Also asks if you would like to go first in the match
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to Rows and Columns (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void versusComputer(char** board,int& rows, int& columns)
{
	//This will determine the end condition of the game (winner existing)
	bool doesWinnerExist = false;
	
	//This is a pointer so the doesWinnerExist's address can be pass into functions
	bool* doesWinnerPointer = &doesWinnerExist;
	
	//This is used for both the difficulty choice and 
	//whether the user wants to go first choice.
	char choice;

	//This will be used as a logic condition for the the difficulty (hard or easy)
	//It could be a boolean but it's an int so the possibility of more incremental
	//bot difficulty can exist
	int difficulty = 1;


	//Sends a message to the user about how to use the program
	cout << "\nWhat difficulty of computer do you want?\nEnter H for intelligent AI, otherwise enter anything else for easy AI" << endl;
	
	//Allows them to repsend to the message
	cin >> choice;
	
	//Checks to see if they want a difficult bot
	if(choice == 'h' || choice == 'H')
		difficulty = 2;

	//Clears the stream for the next choice
	cin.clear();
	cin.ignore(1000000, '\n');

	//Gives them more information. This is for whether they want to go first or not
	cout << "\nDo you want to go first?\nEnter Y for yes, and anything else for no." << endl;
	cin >> choice;

	//This variable is used to determine the player's move for the SMART AI
	int choiceColumn = 0;

	//Prints the board
	printBoard(board, rows, columns);

	//Checks to see if they want to go first
	if(choice == 'y' || choice == 'Y')
		//Lets the player go first and also records their move in choiceColumn
		choiceColumn = playerMove(board, rows, columns, doesWinnerPointer);

	//This loop will continue until a winner has been found in the game
	while(!doesWinnerExist)
	{
		//These if statements are just to ensure that a player doesn't bypass the exit
		//condition. Had an issue with this before but this resolves it
		if(!doesWinnerExist)
			//This executes the computer's turn
			computerMove(board, rows, columns, difficulty, doesWinnerPointer, choiceColumn);
		
		//See statement above
		if(!doesWinnerExist)
			//Executes player's turn
			choiceColumn = playerMove(board, rows, columns, doesWinnerPointer);	
	}

	return;
}

/*********************************************************************************************
 * FUNCTION NAME: playerMove
 * DESCRIPTION: This function allows the player to make a move in the HUMAN vs Computer
 * 		game type
 *		It also prompts them for their turn and ensures they enter correctly
 *		Lastly it executes their turn and shows them the board
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to Rows and Columns (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * OUTPUTS: The column that the player decides to place the piece in (int)
 ********************************************************************************************/
int playerMove(char** board, int& rows, int& columns, bool* doesWinnerPointer)
{
	//This is for the columns as the user sees them
	int choiceColumn = 0;

	//This is for the actual value of the columns in the array
	//Thus it has to be offset by 1
	int actualColumn = -1;

	//Prompts the user as to where they want to place their piece
	cout << "Player's turn. Where do you want to place a piece?" << endl; 	
	cin >> choiceColumn;

	//Offsets the user's entry to factor in array index starting position (0)
	actualColumn += choiceColumn;

	//This is for error handling
	//The choiceColumn limitations ensure that the column values are within the range of actual column values
	//And the board limitations make sure that the column isn't already full
	while(!cin || choiceColumn < 1 || choiceColumn > columns || board[0][actualColumn] == 'X' || board[0][actualColumn] == 'O')
	{
		//Clears the  stream
		cin.clear();
		cin.ignore(1000000,'\n');

		//Tells the user what went wrong and lets them try again
		cout << "That is an invalid column.\nThe column is either full or nonexistent.\nTry again." << endl;
		cin >> choiceColumn;

		//Updates the variable that will be entered int other board array
		actualColumn = choiceColumn - 1;
	}

	//Actually moves the piece onto the board and stores the row that the piece fell into 
	int emptySpot = piecePlacer(board, rows, actualColumn, 'X');

	//Prints the board
	printBoard(board, rows, columns);

	//Checks to see if there's a winner
	isThereWinner(board, rows, columns, emptySpot, actualColumn, doesWinnerPointer,'O', "PLAYER" ); 

	//Returns the column the user entered so the SMART AI can act accordingly
	return actualColumn;
}

/*********************************************************************************************
 * FUNCTION NAME: computerMove
 * DESCRIPTION: This is the computer's turn in the game
 * 		Here, the computer chooses a column and places a piece in that column
 * INPUTS: The address of the board (double pointer)
 * 	   References to the Rows, Columns, Difficulty, and Player's last choice (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * OUTPUTS: N/A
 ********************************************************************************************/
void computerMove(char** board, int& rows, int& columns, int& difficulty, bool* doesWinnerPointer, int& playerChoice)
{
	//This variable is used to store the spot
	//that the computer will place its piece in
	int choiceColumn;

	//Just informs the user of what's going on
	cout << "COMPUTER'S Turn... ";

	//Checks to see what difficulty the player wanted
	if(difficulty == 2)
		//Chooses the column based on the SMART AI
		smartAIChoice(board, rows, columns, choiceColumn, playerChoice);
	else
		//Chooses the column based on the dumb AI
		dumbAIChoice(board, rows, columns, choiceColumn);	

	//Tells the user what's going onn
	cout << "COMPUTER chose: " << choiceColumn + 1  << endl;

	//Places the computer's piece based on the choice and stores the row the piece fell into
	int emptySpot = piecePlacer(board, rows, choiceColumn, 'O');

	//Prints the board for the user
	printBoard(board, rows, columns);
	
	//Checks to see if there's a winner
	isThereWinner(board, rows, columns, emptySpot, choiceColumn, doesWinnerPointer,'X', "COMPUTER" );
	
	return;
}
/*********************************************************************************************
 * FUNCTION NAME: piecePlacer
 * DESCRIPTION: This function places the pieces onto the board according to what
 * 		column the player wants the piece in and what the piece is
 * 		Then it returns the specific row in which it placed the piece
 * INPUTS: The address of the board (pointer)
 * 	   Reference of the Rows and the Column the piece is to be placed in (int)
 * OUTPUTS: The row the piece was placed in (int)
 ********************************************************************************************/
int piecePlacer(char** board, int& rows, int& columnPlace, char piece)
{
	//This is a variable to store the lowest available empty spot
	int emptySpot = 0;
	
	//This loop goes through the entire row
	for(int i = 0; i < rows; ++i)
	{
		//Checks to see if the spot is empty
		if(board[i][columnPlace] == ' ')
			//Updates the list of the empty spot
			emptySpot = i;
	}
	
	//Places the specific piece in the empty spot
	board[emptySpot][columnPlace] = piece;

	//Returns the row in which the piece was placed
	return emptySpot;	
}

/*********************************************************************************************
 * FUNCTION NAME: isThereWinner
 * DESCRIPTION: Checks all the win conditions to see if the move that just occured made
 * 		someone win.
 * 		There are four win conditions and one tie condition functions that this
 * 		function calls
 * 			Horizontal connect four
 * 			Vertical connect four
 * 			Diagonal connect four (y = -x)
 * 			Negative Diagonal connect four(y = x)
 * INPUTS:
 * OUTPUTS:
 ********************************************************************************************/
void isThereWinner(char** board, int& rows, int& columns,int& emptySpot, int& choiceColumn, bool* doesWinnerPointer, char piece, string name)
{
	//Checks if there's a win condition horizontally
	isThereHorizontalWinner(board, rows, columns, emptySpot, choiceColumn, doesWinnerPointer, piece);

	//Checks if there's a win condition vertically
	isThereVerticalWinner(board, rows, columns, emptySpot, choiceColumn, doesWinnerPointer, piece);
		
	//Checks if there are diagonal win conditions
	isThereDiagonalWinner(board, rows, columns, emptySpot, choiceColumn, doesWinnerPointer, piece);

	isThereNegativeDiagonalWinner(board, rows, columns, emptySpot, choiceColumn, doesWinnerPointer, piece);

	//Checks if there is a tie
	bool isTie = isThereTie(board, rows, columns, doesWinnerPointer);

	//Relays a message if there is a winner	
	if(*doesWinnerPointer & !isTie)
	{
		cout << endl << "********************" << endl << "The Winner is: " << name << endl << "********************" << endl << endl;
	}

	return;
}

/*********************************************************************************************
 * FUNCTION NAME: isThereHorizontalWinner
 * DESCRIPTION: Checks to see if the move that just occured caused a horizontal connect four
 * INPUTS: The address of the board (pointer)
 * 	   Reference to the Rows, Columns, and the row and column the piece was placed in
 * 	   (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * 	   The opponents piece (the opposite of the piece that was placed) (char)
 * OUTPUTS: N/A
 ********************************************************************************************/
void isThereHorizontalWinner(char** board, int& rows, int& columns,int& emptySpot, int& choiceColumn, bool* doesWinnerPointer, char piece)
{
	//Stores the variable we are checking the win condition for
	int fourCount = 0;

	//This checks the pieces to the left of the piece placed
	for(int i = choiceColumn; i >= 0; i--)
	{
		//Stops the search if the current piece is not the one we
		//are checking the win condition for
		if(board[emptySpot][i] == ' ' || board[emptySpot][i] == piece)
			break;
		//If it gets to this point, that means it is still the piece
		//we are looking for, so one is added to the counter
		fourCount++;		
	}

	//This checks the pieces to the right of the piece placed
	for(int i = choiceColumn; i < columns; i++)
	{
		//Stops the search if the current piece is not the one we
		//are checking the win condition for
		if(board[emptySpot][i] == ' ' || board[emptySpot][i] == piece)
			break;
		//If it gets to this point, that means it is still the piece
		//we are looking for, so one is added to the counter
		fourCount++;
	}

	//We overcounted by 1 because we counted the last piece placed
	//twice with the two searches, therefore we must subtract one
	fourCount--;
	
	//If the win condition has been met, this sets the doesWinnerExist
	//variable to true
	if(fourCount >= 4)
		*doesWinnerPointer = true;

	return;
}

/*********************************************************************************************
 * FUNCTION NAME: isThereVerticalWinner
 * DESCRIPTION: Checks to see if the piece placed caused a vertical win condition
 * INPUTS: The address of the board (pointer)
 * 	   Reference to the Rows, Columns, and the row and column the piece was placed in
 * 	   (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * 	   The opponents piece (the opposite of the piece that was placed) (char)
 * OUTPUTS: N/A
 ********************************************************************************************/
void isThereVerticalWinner(char** board, int& rows, int& columns,int& emptySpot, int& choiceColumn, bool* doesWinnerPointer, char piece)
{
	
	//Stores the variable we are checking the win condition for
	int fourCount = 0;

	//This starts at the row that the last piece was placed in and goes town till the bottom of the board
	for(int i = emptySpot; i < rows; i++)
	{
		//Stops the search if the current piece is not the one we
		//are checking the win condition for
		if(board[i][choiceColumn] == 32 || board[i][choiceColumn] == piece)
			break;
		//If it gets to this point, that means it is still the piece
		//we are looking for, so one is added to the counter
		fourCount++;
	}
		
	//If the win condition has been met, this sets the doesWinnerExist
	//variable to true
	if(fourCount >= 4)
		*doesWinnerPointer = true;

	return;
}

/*********************************************************************************************
 * FUNCTION NAME: isThereDiagonalWinner
 * DESCRIPTION: This function checks to see if the piece just placed caused a winner in the
 * 		y = -x diagonal
 * INPUTS: The address of the board (pointer)
 * 	   Reference to the Rows, Columns, and the row and column the piece was placed in
 * 	   (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * 	   The opponents piece (the opposite of the piece that was placed) (char)
 * OUTPUTS: N/A
 ********************************************************************************************/
void isThereDiagonalWinner(char** board, int& rows, int& columns,int& emptySpot, int& choiceColumn, bool* doesWinnerPointer, char piece)
{

	//Stores the variable we are checking the win condition for
	int fourCount = 0;
	
	//This represents the distance from the piece placed to the top of the board
	int rowCountTop = emptySpot;
	//This represents the distance from the piece placed to the left side of the board
	int columnCountTop = choiceColumn;
	
	//This represents the distance from the piece placed to the bottom of the board
	int rowCountBot = rows - 1 - emptySpot;
	//This represents the distance from the piece placed to the right side of the board
	int columnCountBot = columns - 1 - choiceColumn;

	//This checks to see which distance is less, the distance to the top or the left
	//This is because a diagonal only needs to be checked to the smallest distance
	//if we checked to the full length of the longest distance, we could cause 
	//array out of bounds errors because there might not be that many rows/columns
	//THEREFORE these two statements will make sure the SMALLER value is chosen
	if(rowCountTop > columnCountTop)
		rowCountTop = columnCountTop;

	//See explanation above
	if(rowCountBot > columnCountBot)
		rowCountBot = columnCountBot;

	
	//This goes through the upper half of the y = -x diagonal
	for(int i = 0; i <= rowCountTop; i++)
	{
		//Stops the search if the current piece is not the one we
		//are checking the win condition for
		//Minus minus represents movement towards the northwest
		if(board[emptySpot - i][choiceColumn - i] == ' ' || board[emptySpot - i][choiceColumn - i] == piece)
			break;
		//If it gets to this point, that means it is still the piece
		//we are looking for, so one is added to the counter
		fourCount++;
	}

	//This goes through the lower half of the y = -x diagonal
	for(int i = 0; i <= rowCountBot; i++)
	{
		//Stops the search if the current piece is not the one we
		//are checking the win condition for
		//Plus plus represents movement towards the southeast
		if(board[emptySpot + i][choiceColumn + i] == ' ' || board[emptySpot + i][choiceColumn + i] == piece)
			break;
		//If it gets to this point, that means it is still the piece
		//we are looking for, so one is added to the counter
		fourCount++;
	}
	
	//We overcounted the diagonal because we included the place the piece in is twice
	//Thus we have to subtract one
	fourCount--;

	//If the win condition has been met, this sets the doesWinnerExist
	//variable to true
	if(fourCount >= 4)
	*doesWinnerPointer = true;

	return;
}

/*********************************************************************************************
 * FUNCTION NAME: isThereNegativeDiagonalWinner
 * DESCRIPTION: This checks to see if the piece placed caused a winner in the y = x diagonal
 * INPUTS: The address of the board (pointer)
 * 	   Reference to the Rows, Columns, and the row and column the piece was placed in
 * 	   (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * 	   The opponents piece (the opposite of the piece that was placed) (char)
 * OUTPUTS: N/A
 ********************************************************************************************/
void isThereNegativeDiagonalWinner(char** board, int& rows, int& columns,int& emptySpot, int& choiceColumn, bool* doesWinnerPointer, char piece)
{
	//Stores the variable we are checking the win condition for
	int fourCount = 0;
	
	//This represents the distance from the spot the piece was placed in and the top of the board
	int rowCountTop = emptySpot;
	//This represents the distance from the spot the piece was placed in and the right side of the board
	int columnCountTop = columns - 1 - choiceColumn;

	//This represents the distance from the spot the piece was placed in and the bottom of the board
	int rowCountBot = rows - 1 - emptySpot;
	//This represents the distance from the spot the piece was placed in and the left side of the board
	int columnCountBot = choiceColumn;

	//This checks to see which distance is less, the distance to the top or to the right	
	//This is because a diagonal only needs to be checked to the smallest distance
	//if we checked to the full length of the longest distance, we could cause 
	//array out of bounds errors because there might not be that many rows/columns
	//THEREFORE these two statements will make sure the SMALLER value is chosen
	if(rowCountTop > columnCountTop)
		rowCountTop = columnCountTop;

	//See explanation above
	if(rowCountBot > columnCountBot)
		rowCountBot = columnCountBot;

	//This loop goes through the top half of the y = x diagonal
	for(int i = 0; i <= rowCountTop; i++)
	{
		//Stops the search if the current piece is not the one we
		//are checking the win condition for
		if(board[emptySpot - i][choiceColumn + i] == ' ' || board[emptySpot - i][choiceColumn + i] == piece)
			break;
		//If it gets to this point, that means it is still the piece
		//we are looking for, so one is added to the counter
		fourCount++;
	}

	//This loop goes through the bottom half of the y = x diagonal
	for(int i = 0; i <= rowCountBot; i++)
	{
		//Stops the search if the current piece is not the one we
		//are checking the win condition for
		if(board[emptySpot + i][choiceColumn - i] == ' ' || board[emptySpot + i][choiceColumn - i] == piece)
			break;
		//If it gets to this point, that means it is still the piece
		//we are looking for, so one is added to the counter
		fourCount++;
	}

	//We overcounted the diagonal because we included the place the piece in is twice
	//Thus we have to subtract one
	fourCount--;

	//If the win condition has been met, this sets the doesWinnerExist
	//variable to true
	if(fourCount >= 4)
	*doesWinnerPointer = true;

	return;
}

/*********************************************************************************************
 * FUNCTION NAME: isThereTie
 * DESCRIPTION: Checks to see if the piece placed caused a tie
 * INPUTS: The address of the board (double pointer)
 *         Reference to Rows and Columns
 *         The address of the doesWinnerExist variable (pointer)
 * OUTPUTS: Whether there is a tie or not (bool)
 ********************************************************************************************/
bool isThereTie(char** board, int& rows, int& columns, bool* doesWinnerPointer)
{
	//Stores the variable we are checking the win condition for
	//If there are no spaces left and no other win condition has been met, there is a tie
	int spaceCount = 0;

	//This goes through the rows of the board
	for(int i = 0; i < rows; i++)
	{	
		//This goes through the columns of the board
		for(int j = 0; j < columns; j++)
		{
			//This checks to see whether the space is free
			if(board[i][j] == ' ')
				spaceCount++;
		}
	}

	//If there are no spaces left	
	if(spaceCount == 0)
	{
		//Message the user
		cout << endl << "********************" << endl << "There is a tie!" << endl << "********************" << endl << endl;
		//Set the win condition
		*doesWinnerPointer = true;	
		
		return true;
	}

	return false;
}

/*********************************************************************************************
 * FUNCTION NAME: playerOneMove
 * DESCRIPTION: This functions iniates the player's turn for PLAYER ONE, allowing them to
 * 		input their piece
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to the Rows and Columns (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * OUTPUTS: N/A
 ********************************************************************************************/
void playerOneMove(char** board, int& rows, int& columns, bool* doesWinnerPointer)
{
	//This is for the columns as the user sees them
	int choiceColumn = 0;
	//This is for the actual value of the columns in the array
	//Thus it has to be offset by 1
	int actualColumn = -1;

	//Gives the user instructions and allows them to enter their column of choice
	cout << "Player ONE's turn. Where do you want to place a piece?" << endl; 	
	cin >> choiceColumn;

	//Adjusts their input to make sure it works within an array
	actualColumn += choiceColumn;

	//This is for error handling
	//The choiceColumn limitations ensure that the column values are within the range of actual column values
	//And the board limitations make sure that the column isn't already full
	while(!cin || choiceColumn < 1 || choiceColumn > columns || board[0][actualColumn] == 'X' || board[0][actualColumn] == 'O')
	{
		//Clears the stream for future use
		cin.clear();
		cin.ignore(1000000,'\n');
		
		//Tells the user what's wrong and lets them try again
		cout << "That is an invalid column.\nThe column is either full or nonexistent.\nTry again." << endl;
		cin >> choiceColumn;
	
		//Readjusts the column for entry into the array
		actualColumn = choiceColumn - 1;
	}

	//Actually places the piece and stores the row the piece was placed on
	int emptySpot = piecePlacer(board, rows, actualColumn, 'X');

	//Prints the board
	printBoard(board, rows, columns);
	
	//Checks to see if the move caused a win condition
	isThereWinner(board, rows, columns, emptySpot, actualColumn, doesWinnerPointer,'O', "PLAYER ONE" ); 

	return;
}

/*********************************************************************************************
 * FUNCTION NAME: playerTwoMove
 * DESCRIPTION: This functions iniates the player's turn for PLAYER TWO, allowing them to
 * 		input their piece
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to the Rows and Columns (int)
 * 	   The address of the doesWinnerExist variable (pointer)
 * OUTPUTS: N/A
 ********************************************************************************************/
void playerTwoMove(char** board, int& rows, int& columns, bool* doesWinnerPointer)
{
	//This is for the columns as the user sees them
	int choiceColumn = 0;
	//This is for the actual value of the columns in the array
	//Thus it has to be offset by 1
	int actualColumn = -1;

	//Gives the user instructions and allows them to enter their column of choice
	cout << "Player TWO's turn. Where do you want to place a piece?" << endl; 	
	cin >> choiceColumn;

	//Adjusts their input to make sure it works within an array
	actualColumn += choiceColumn;

	//This is for error handling
	//The choiceColumn limitations ensure that the column values are within the range of actual column values
	//And the board limitations make sure that the column isn't already full
	while(!cin || choiceColumn < 1 || choiceColumn > columns || board[0][actualColumn] == 'X' || board[0][actualColumn] == 'O')
	{
		//Clears the stream for future use
		cin.clear();
		cin.ignore(1000000,'\n');

		//Tells the user what went wrong and lets them try again
		cout << "That is an invalid column.\nThe column is either full or nonexistent.\nTry again." << endl;
		cin >> choiceColumn;
		
		//Readjusts the column for entry into the array
		actualColumn = choiceColumn - 1;
	}

	//Actually places the piece and stores the row the piece was placed in
	int emptySpot = piecePlacer(board, rows, actualColumn, 'O');

	//Prints the board
	printBoard(board, rows, columns);

	//Checks to see if the piece caused a win condition
	isThereWinner(board, rows, columns, emptySpot, actualColumn, doesWinnerPointer,'X', "PLAYER TWO" ); 

	return;
}
/*********************************************************************************************
 * FUNCTION NAME: versusHuman
 * DESCRIPTION: Procters the HUMAN vs HUMAN gane
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to the Rows and columns (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void versusHuman(char** board, int& rows, int& columns)
{
	//This variable will determine if the win conditions have been met and
	//will allow for exit from the game
	bool doesWinnerExist = false;

	//This pointer allows the doesWinnerExist variable to be passed to functions
	bool* doesWinnerPointer = &doesWinnerExist;
	
	//Prints the board
	printBoard(board, rows, columns);

	//This loop goes until a winner is decided
	while(!doesWinnerExist)
	{
		//Was having some odd troubles with win conditions so these 
		//if statements are just here as another precaution
		if(!doesWinnerExist)
			//Initiates player one's move
			playerOneMove(board, rows, columns, doesWinnerPointer);
		if(!doesWinnerExist)
			//Initiates player two's move
			playerTwoMove(board, rows, columns, doesWinnerPointer);	
	}

	return;
}
/*********************************************************************************************
 * FUNCTION NAME: dumbAIChoice
 * DESCRIPTION: This is the dumb AI. It simply chooses a column by random
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to Rows, Columns, and the column that the piece will be placed in (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void dumbAIChoice(char** board, int& rows, int& columns, int& choiceColumn)
{
	//Allows for more randomness	
	srand(time(NULL));

	//Chooses a random column
	choiceColumn = rand() % columns;
	
	//Makes sure the column that was chosen is not already full and rechooses if 
	//it is full
	while(board[0][choiceColumn] != ' ')
		choiceColumn = rand() % columns;	
	
	return;
}

/*********************************************************************************************
 * FUNCTION NAME: smartAIChoice
 * DESCRIPTION: This is the intelligent AI. It DOES NOT choose just by randomness.
 *		How it determines where it will place:
 *			If the player is about to stack 4 vertically (it will 
 *			NEVER allow the player to do this)
 *
 *			Otherwise, it will pick randomly out of three options (if they exist):
 *				1) To the left of the player's last choice
 *				2) To the right of the player's last choice
 *				3) Or a random column
 *
 * INPUTS: The address of the board (double pointer)
 * 	   Reference to Rows, Columns, and the column that the piece will be placed in (int)
 * 	   The choice of column that the player previously made (int)
 * OUTPUTS: N/A
 ********************************************************************************************/
void smartAIChoice(char** board, int& rows, int& columns, int& choiceColumn, int playerChoice = 0)
{
	//For more randomness
	srand(time(NULL));
	
	//Randomly chooses one out of two options
	int probability = rand() % 2;
		
	//Acts based on those options
	if(probability == 1 & playerChoice - 1 >= 0)
		//To the left of the player's last choice
		choiceColumn = playerChoice - 1;
	else if(probability == 0 & playerChoice + 1 < rows)
		//To the right of the player's last choice
		choiceColumn = playerChoice + 1;
	else
		//randomly
		choiceColumn = rand() % columns;
	
	//This variable stores the quantity of the player's pieces in a row in the
	//column that they last chose
	int quantity  = 0;

	//This loop counts the amount of pieces the player has in the column they
	//last chose
	for(int i = 0; i < rows; i++)
	{
		if(board[i][playerChoice] == 'X')
			quantity++;		
	}

	//If they have over two pieces in that column, the computer will
	//choose this column to place the piece in
	if(quantity > 2)
		choiceColumn = playerChoice;

	//This prevents the AI from choosing a column that is full and will choose
	//a random column if it does choose a column that is full
	while(board[0][choiceColumn] != ' ')
	{
		choiceColumn = rand() % columns;
	}			

	return;
}










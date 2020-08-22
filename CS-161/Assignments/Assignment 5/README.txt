NAME: Pranaw Bajracharya
ONID Email: bajrachp@oregonstate.edu

COMPLIATION INSTRUCTIONS: 
	Nothing special. Command line arguments follows format: (executable name) (# of players) (# of rows) (# of columns) 

Description of Program: My program is as you would expect, Connect Four with all the bells and
			whistles. You have the option to play HUMAN vs HUMAN or HUMAN vs COMPUTER 
			and can choose to play versus the dumb AI or the more intelligent one. 

Limitations: A few of the functions slightly go over 15 lines (nothing crazy like 70). I believe
	     they are at most around 18 lines. Most of the functions serve only one purpose
	     (or at least very closely related purposes) and there are plenty of comments to 
	     clarify my implementation. For the instances that functions go over 15 lines,
	     at times it can be because of necessity, but most of the time it is due to
	     additions like messages to the user, or clearing spaces in the console for aesthetic purposes.
	     Please don't dock points. 
	     :D   : ^ D   :)

	     Also the smart AI isn't going to beat Magnus Carlsen at chess but it will limit your
	     win conditions. That is to say, it is smarter than dumb but it's not a brainiac.

Extra Credit: Yes - More intelligent AI

/*************************************************************************************************************************************************************************************
 * Author:
 * 	Pranaw Bajracharya
 * 
 * Program Name:
 * 	Connect Four
 *
 * Description:
 * 	This program is a CONNECT FOUR game and as such follows official CONNECT FOUR rules as seen here:
 * 	This game has two game types:
 * 		1) HUMAN vs COMPUTER
 * 			The player can choose between two differ AI
 * 				Dumb - The dumb AI will choose legal pieces at random
 * 				Smart - The smart AI will choose between a selection of options that relate to the 
 * 					last column that the user selected
 * 					It will never allow the user to connect four vertically
 * 		2) HUMAN vs HUMAN
 * 			Two players can play against each other
 *
 * 	The user can play the game as many times as they like. If they finish a game, the will be prompted if they want to play again.
 * 	If they decide to play agian, the game board will be reset to the specific parameters they entered through the command prompt and the game restarted.
 * 
 *
 * Iputs:
 *	Number of Players - Correct values (1 or 2)
 *
 *	Number of Rows - Correct values: (4-20)
 *
 *	Number of Columns - Correct values (4-20)
 * Outputs:
 *	None
 *
 ************************************************************************************************************************************************************************************/

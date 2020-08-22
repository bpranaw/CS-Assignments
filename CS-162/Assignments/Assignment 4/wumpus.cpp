#include "wumpus.h"

Wumpus::Wumpus()
{
	this->name = "W";
}


/*************************************************************************************
 * Function Name: Encounter
 * Description: Tells the player about the wumpus' waking and returns true when called
 * Inputs: N/A
 * Outputs: true (booL)
 ************************************************************************************/

bool Wumpus::encounter()
{
	cout << "RAWWWWWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR!!!\n\n\n\n\n....................................................\n\n\n\n\nYou have encountered the Wumpus and died..." << endl;

	return true;	
}

/*************************************************************************************
 * Function Name: precept
 * Description: Tells the player a message. This is called when the wumpus is nearby
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Wumpus::precept()
{
	cout << endl << "You smell a terrible stench nearby..." << endl;
	return;
}

/*************************************************************************************
 * Function Name: get_name
 * Description: returns the name of the object
 * Inputs: N/A
 * Outputs: The name of the object
 ************************************************************************************/
string Wumpus::get_name()
{
	return this->name;
}

		
/*************************************************************************************
 * Function Name:
 * Description: 
 * Inputs:
 * Outputs:
 ************************************************************************************/

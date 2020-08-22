#include "bat.h"

Bat::Bat()
{
	this->name = "B";
}

/*************************************************************************************
 * Function Name: Encounter
 * Description: Tells the player about the bat and returns true when called
 * Inputs: N/A
 * Outputs: true (booL)
 ************************************************************************************/

bool Bat::encounter()
{
	cout << "\nSHREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEK.....WHOSH WHOOSH....\n\n\n\n\n....................................................\n\n\n\n\nYou have encountered the bat and it has moved you to a new room " << endl;
	return true;	
}

/*************************************************************************************
 * Function Name: precept
 * Description: Tells the player a message. This is called when the bat is nearby
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Bat::precept()
{
	cout << endl << "You hear wings flapping nearby..." << endl;
	return;
}

/*************************************************************************************
 * Function Name: get_name
 * Description: returns the name of the object
 * Inputs: N/A
 * Outputs: The name of the object
 ************************************************************************************/
string Bat::get_name()
{
	return this->name;
}

		
/*************************************************************************************
 * Function Name:
 * Description: 
 * Inputs:
 * Outputs:
 ************************************************************************************/

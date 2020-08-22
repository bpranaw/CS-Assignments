#include "pit.h" 

Pit::Pit()
{
	this->name = "P";
}

/*************************************************************************************
 * Function Name: Encounter
 * Description: Tells the player about the pit and returns true when called
 * Inputs: N/A
 * Outputs: true (booL)
 ************************************************************************************/

bool Pit::encounter()
{
	cout << "\nWhooooooooooooooooooooooooooshhhhhhhhhhhhh.....Thump!!!\n\n\n\n\n....................................................\n\n\n\n\nYou have encountered the bottomless pit. You fell and died....." << endl;

	return true;	
}

/*************************************************************************************
 * Function Name: precept
 * Description: Tells the player a message. This is called when the pit is nearby
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Pit::precept()
{
	cout << endl << "You feel a breeze nearby..." << endl;
	return;
}

/*************************************************************************************
 * Function Name: get_name
 * Description: returns the name of the object
 * Inputs: N/A
 * Outputs: The name of the object
 ************************************************************************************/
string Pit::get_name()
{
	return this->name;
}

		
/*************************************************************************************
 * Function Name:
 * Description: 
 * Inputs:
 * Outputs:
 ************************************************************************************/

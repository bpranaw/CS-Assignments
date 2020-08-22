#include "gold.h"
 
Gold::Gold()
{
	this->name = "G";
}

/*************************************************************************************
 * Function Name: Encounter
 * Description: Tells the player about the Gold and returns true when called
 * Inputs: N/A
 * Outputs: true (booL)
 ************************************************************************************/

bool Gold::encounter()
{
	cout << "\nThis room is oddly quiet... You look around a pillar and notice a shine...\n\n\n\n\n....................................................\n\n\n\n\nYou have encountered the golden treasure and picked it up!!!" << endl;

	return true;	
}

/*************************************************************************************
 * Function Name: precept
 * Description: Tells the player a message. This is called when the gold is nearby
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Gold::precept()
{
	cout << endl << "You see a glimmer nearby..." << endl;
	return;
}

/*************************************************************************************
 * Function Name: get_name
 * Description: returns the name of the object
 * Inputs: N/A
 * Outputs: The name of the object
 ************************************************************************************/
string Gold::get_name()
{
	return this->name;
}

		
/*************************************************************************************
 * Function Name:
 * Description: 
 * Inputs:
 * Outputs:
 ************************************************************************************/

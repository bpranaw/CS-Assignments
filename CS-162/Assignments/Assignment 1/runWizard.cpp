#include "catalog.h"

int main(int argc, char * argv[])
{

//COMMAND LINE ARGUMENTS____________________________________________________________

	//Checks to see if there are an adequate number of command line arguments
	isCorrectNumberOfArguments(argc);	

	//If there are, stores them into these varaibles which we will use to
	//pass the arguments
	string fileName = argv[1];
	string fileName2 = argv[2];

	//Checks to see if these arguments are correct
	doFilesExist(fileName, fileName2);

//WIZARD LOGIN______________________________________________________________________

	//Creates wizard array and fills it up
	int numberOfWizards;
	wizard * wizardArray = parseWizardData(fileName, numberOfWizards);

	//This permission is for filtering whether the user can access the death spells
	bool permission = false;

	//Lets the user login
	wizardLogin(wizardArray, numberOfWizards, permission);


//GETTING INFORMATION INTO THE SPELLBOOKS___________________________________________
	
	//Creates spellbook array
	int numberOfSpellbooks;
	
	//Creates ifstream object to access spellbook file
	ifstream inputFile;
	inputFile.open(fileName2.c_str());

	inputFile >> numberOfSpellbooks;

	
	spellbook* spellbookArray = createSpellbooks(numberOfSpellbooks);	

	assignSpellbookInformation(spellbookArray, numberOfSpellbooks, inputFile);

	inputFile.close();	

//CHOOSING YOUR OPTIONS_____________________________________________________________

	chooseOptions(spellbookArray, numberOfSpellbooks, permission);


//CLEARING THE HEAP_________________________________________________________________

	deleteInformation(wizardArray, spellbookArray, numberOfSpellbooks);
	
	return 0;
}

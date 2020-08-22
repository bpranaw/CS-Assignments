#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

//STRUCTS*****************************************************************************
struct wizard
{
	string name;

	int ID;
	string password;

	string positionTitle;
	float beardLength;
};

struct spellbook
{
	string title;
	string author;

	int numberOfPages;
	int edition;

	int numberOfSpells;
	float averageSuccessRate;

	struct spell *spellPointer;

};

struct spell 
{
	string name;
	float successRate;
	string effect;

};

//END STRUCTS*************************************************************************

//FUNCTION PROTOTYPES*****************************************************************

//Functions related to storing information from the files-----------------------------

//Wizard Related-------------------------------------------------------
wizard * createWizards(int);

spellbook * createSpellbooks(int);

spell * createSpells(int);

wizard * parseWizardData(string, int&);

void assignWizardInformation(wizard*, int, ifstream &);

//Spellbook Related----------------------------------------------------

//This is populate_spellbook_data(spellbook *, int, ifstream &) RENAMED
int retrieveNumberOfSpellbooks(string);

void assignSpellbookInformation(spellbook*, int, ifstream&);

void assignSpellInformation(spell*, int, ifstream&);

//Command line argument checkers------------------------------------------------------

void isCorrectNumberOfArguments(int);

void doFilesExist(string, string);

//WizardLogin-------------------------------------------------------------------------
void wizardLogin(wizard*, int, bool&); 

int integerCheck();

bool loginCheck(wizard*,int, int&);

bool welcomeMessage(wizard*,int);

//Heap clearing functions-------------------------------------------------------------

void deleteInformation(wizard *, spellbook *, int);

void deleteArray(spellbook*, int);

//Sorting Functions-------------------------------------------------------------------

void chooseOptions(spellbook*, int, bool);

void sortByPages(spellbook*, spellbook*, int);

void sortByGroup(spellbook*, spell*,int, int);

void sortBySuccessRate(spellbook*, spellbook*, int);

void calculateSuccessRate(spellbook*, int);

int calculateNumberOfSpells(spellbook*, int);

int priorityChecker(spell);


//Printing Functions----------------------------------------------------------------

bool safetyCheck(spellbook*, int);

void printOption1(spellbook*, int, bool);

void printOption3(spellbook*, int, bool);

void printOption2(spell*, int, bool);

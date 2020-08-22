#include "student_db.h"

using namespace std;

student * create_student_db(int numberOfStudents)
{
	student* studentArray = new student[numberOfStudents];
	return studentArray;
}

void populate_student_db_info(student * studentArray, int numberOfStudents, ifstream &fromFile)
{
	string temporaryString;
	string fileString;

	while(!fromFile.eof())
	{
		getline(fromFile, temporaryString);
		fileString += temporaryString + '\n';			
	}	

	fromFile.close();

	int studentIndex = 0;
	
	int spaceCount = 0;

	
	string temporaryID;
	string temporaryFirstName;
	string temporaryLastName;
	string temporaryMajor;

	for(int i = 2; i < fileString.length(); i++)
	{

		char x = fileString[i];
	//	cout << x << "   " << int(x) << "   " << i << "   " << spaceCount << endl;
	
		if(studentIndex >= numberOfStudents)
			break;	

		if(spaceCount <= 0)
			temporaryID += x;
		if(spaceCount == 1)
			temporaryFirstName += x;
		if(spaceCount == 2)
			temporaryLastName += x;
		if(spaceCount == 3)
			temporaryMajor += x;


//		cout << x << "   " << temporaryMajor << "   " << i << "   " << endl;


		if(x == 32)	
			spaceCount++;

		if(x == 10)
		{
		

			studentArray[studentIndex].ID = temporaryID;
		
			studentArray[studentIndex].firstName = temporaryFirstName;	

			studentArray[studentIndex].lastName = temporaryLastName ;

			studentArray[studentIndex].major = temporaryMajor;


			temporaryID.clear();
			temporaryFirstName.clear();
			temporaryLastName.clear();
			temporaryMajor.clear();

			studentIndex++;
			
			spaceCount = 0;
		}
	
	}

	return;
}
//Not entirely sure if this was the intended use of this function
void delete_student_db_info(student** arrayOfArrays, int numberOfArrays)
{
	for(int i = 0; i < numberOfArrays; i++)
	{
		delete[] arrayOfArrays[i];	
	}
	
	return;
}

void sortByID(student* studentArray, student* sortedArray, int numberOfStudents)
{
	int currentVariable = 0, lowestVariable = 0, previousVariable = 999999999, index = 0;

	for(int i = 0; i < numberOfStudents; i++)
	{	
		previousVariable = 999999999;
		for(int j = 0; j < numberOfStudents; j++)
		{
			char temporaryArray[10];	
		
			for(int k = 0; k < 11; k++)
			{							
				if(k == 9)
					continue;
				if(k == 10)
					temporaryArray[k-1] = studentArray[j].ID[k-1];
				else
					temporaryArray[k] = studentArray[j].ID[k];
			}
	
			currentVariable = atoi(temporaryArray);
		
			if(currentVariable > lowestVariable & currentVariable < previousVariable)
			{
				previousVariable = currentVariable;	
				index = j;			
			}		
	
		}

		lowestVariable = previousVariable;
		
		sortedArray[i].ID = studentArray[index].ID;
		sortedArray[i].firstName = studentArray[index].firstName;
		sortedArray[i].lastName = studentArray[index].lastName;
		sortedArray[i].major = studentArray[index].major;
		
	}
	return;
}

void sortByLastName(student* studentArray, student* sortedArray, int numberOfStudents)
{
	string currentChar = "A", priorityChar = " ", previousChar = "{{{{{{zzzzzzzzzzzzz";
	int index = 0;

	for(int i = 0; i < numberOfStudents; i++)
	{
		previousChar = "{{{{{{{{{{{{{{{{{{{ZZZZZZZZZZZZZZZZZZZZZ";
		for(int j = 0; j < numberOfStudents; j++)
		{
			currentChar = studentArray[j].lastName;
		
			if(currentChar > priorityChar & currentChar < previousChar)
			{
				previousChar = currentChar;
				index = j;
			}
		}

			priorityChar = previousChar;

			sortedArray[i].ID = studentArray[index].ID;
			sortedArray[i].firstName = studentArray[index].firstName;
			sortedArray[i].lastName = studentArray[index].lastName;
			sortedArray[i].major = studentArray[index].major;
	}
		
	return;	
}

void checkNumberOfMajors(student* studentArray, int numberOfStudents, int & majors)
{
	majors = 1;

	for(int i = 1; i < numberOfStudents; i++)
	{
		int j = 0;

		for(j = 0; j < i; j++)
			if(studentArray[i].major == studentArray[j].major)
				break;

		if(i == j)
			majors ++;
	}
	return;
}

void writeToFile(student* sortedIDArray, student* sortedNameArray, int majors, int numberOfStudents, ofstream & outFile, string FILENAME)
{

	outFile.open(FILENAME.c_str());

	outFile << "SORTED BY ID NUMBER (LOWEST FIRST): " << endl << endl;

	for(int i = 0; i < numberOfStudents; i++)
	{
		outFile << sortedIDArray[i].ID << "   ";
		outFile << sortedIDArray[i].firstName << "   ";
		outFile << sortedIDArray[i].lastName << "   ";
		outFile << sortedIDArray[i].major << endl;
	}


	outFile << endl << "SORTED BY LAST NAME (ALPHABETICAL): " << endl << endl;

	for(int i = 0; i < numberOfStudents; i++)
	{
		outFile << sortedNameArray[i].ID << "   ";
		outFile << sortedNameArray[i].firstName << "   ";
		outFile << sortedNameArray[i].lastName << "   ";
		outFile << sortedNameArray[i].major << endl;
	}

	outFile << "NUMBER OF UNIQUE MAJORS: " << majors << endl;
	
	outFile.close();
}




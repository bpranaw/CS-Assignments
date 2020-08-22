#include "student_db.h"

int main(int argc, char ** argv)
{

	if(argc < 3)
	{
		cout << "You have entered too little parameters. The structure is as follows:";
		cout << endl << "student (Reading from, file name) (Writing to, file name)" << endl;
		exit(1);	
	}

	ifstream fromFile;
	string FILENAME;
	string OutFILENAME;

	FILENAME = argv[1];
	
	OutFILENAME = argv[2];
	
	fromFile.open(FILENAME.c_str());
	
	
	if(fromFile.fail())
	{
		cout << "You have entered an incorrect \"Read from\" file name. Try again will a file that exists." << endl;
		exit(1);
	}

	fromFile.close();

	fromFile.open(OutFILENAME.c_str());
	
	if(fromFile.fail())
	{
		cout << "You have entered an incorrect \"Write to\" file name. Try again will a file that exists." << endl;
		exit(1);
	}

	fromFile.close();

	

	int numberOfStudents = 0;	

	fromFile.open(FILENAME.c_str());

	fromFile >> numberOfStudents;
	
	fromFile.close();


	
	student* studentArray = create_student_db(numberOfStudents);
	
	student** needlessPointerToArray = &studentArray;


	fromFile.open(FILENAME.c_str());
	
	populate_student_db_info(studentArray, numberOfStudents, fromFile);
	
	fromFile.close();


	student* sortedIDArray = create_student_db(numberOfStudents);
	student** needlessPointerToArray2 = &sortedIDArray;


	student* sortedNameArray = create_student_db(numberOfStudents);
	student** needlessPointerToArray3 = &sortedNameArray;


	sortByID(studentArray, sortedIDArray, numberOfStudents);

	sortByLastName(studentArray,sortedNameArray, numberOfStudents);



	int majors = 1;
	checkNumberOfMajors(studentArray, numberOfStudents, majors);

	ofstream outFile;

	writeToFile(sortedIDArray, sortedNameArray, majors, numberOfStudents, outFile, OutFILENAME); 

	
	delete_student_db_info(needlessPointerToArray3, 1);
	delete_student_db_info(needlessPointerToArray2, 1);
	delete_student_db_info(needlessPointerToArray, 1);



	return 0;
}

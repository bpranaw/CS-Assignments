#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct student
{
	string ID;
	string firstName;
	string lastName;
	string major;
};

student * create_student_db(int);

void populate_student_db_info(student *, int, ifstream &);

void delete_student_db_info(student**,int);

void sortByID(student*, student*, int);

void sortByLastName(student*, student*, int);

void checkNumberOfMajors(student*, int, int &);

void writeToFile(student*, student*, int, int, ofstream &, string);



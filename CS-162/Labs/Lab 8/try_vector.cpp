#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
////be able to compare our vector template to the Standard 

//using namespace std;
//using std::vector;

using std::cout;
using std::endl;

int main ()
{
	vector<int> v;   //Our vector class

	std::vector<int> stdv; //Standard vector

	//Compare operation of our vector to std
	v.push_back(0);

	cout << endl << "Our vector1 (for assignment example) before copying: " << endl;

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	cout << endl << "The Vector that will be copied: " << endl;

	vector<int> c;   //Vector that will be copied

	c.push_back(1337);
       
	c.push_back(666);
	
	c.push_back(420);	
        
  
	for(int i = 0; i < c.size(); i++)
		cout << c[i] << endl;


	v = c;

	vector<int> v2 = c;


	cout << endl << "Our vector1 (for assignment example) AFTER copying: " << endl;

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;


	cout << endl << "Our vector2(for copy constructor example) AFTER copying: " << endl;

	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << endl;


	cout  << endl << "Trying to access index 0 with .at():" << endl << endl;
	cout << endl << v2.at(0) << endl;	
	
	cout  << endl << "Trying to access index -1 with .at():" << endl << endl;
		
	try
	{
		cout << endl << v2.at(-1) << endl;	
	}
	catch(out_of_range &e)
	{
		cout << e.what() << endl;
	}

	cout  << endl << "Trying to access index 1000 with .at():" << endl << endl;
	
	try
	{
		cout << endl << v2.at(1000) << endl;	
	}	
	catch(out_of_range &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

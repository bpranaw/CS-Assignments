#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <fstream>
#include "menu.h"
#include "emp_hours.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class Restaurant {
private:

	Menu menu;

	employee* employees;

	//This is just to make my life easier
	int numberOfEmployees;

	hours* week;
	
	//This is just to make my life easier
	int numberOfDays;

	string name;

	string phone;

	string address;
public:
	//need to include accessor functions and mutator functions for each private member

//BIG THREE/DESTRUCTOR________________________________________________________________________________________________________________________________________________________________


	//DEFAULT CONSTRUCTOR
	Restaurant();

	//COPY CONSTRUCTOR
	//JUST IN CASE I NEED IT FOR SOMETHING
	Restaurant(const Restaurant &); 

	//ASSIGNMENT OPERATOR OVERLOAD
	Restaurant& operator = (const Restaurant &);	

	//DESTRUCTOR
	~Restaurant();

//ACCESSORS/MUTATORS__________________________________________________________________________________________________________________________________________________________________

	//For Menu
	Menu getMenu();
	
	void setMenu(const Menu);

	//For Employees
	const employee* getEmployees();

	void setEmployees(const employee*, const int );	

	const int getNumberOfEmployees();

	void setNumberOfEmployees(const int);

	//For Hours
	hours* getHours();

	void setHours(const hours*, const int);

	const int getNumberOfDays();

	void setNumberOfDays(const int);
	
	//FOR RESTAURANT INFORMATION

	//For Name
	const string getName();
	
	void setName(const string);

	//For Phone
	const string getNumber();

	void setNumber(const string);

	//For Address
	const string getAddress();
	
	void setAddress(const string);


//LOADING DATA________________________________________________________________________________________________________________________________________________________________________


	void loadData(); //reads from files to correctly populate menu, employees, hours, etc.

	void loadRestaurantData(ifstream&, const int);	
	void loadNumber(ifstream&);
	void loadHours(ifstream&, const int);

	void loadMenuData(ifstream&, const int);

	void loadEmployeeData(ifstream&, const int);
	
	int countLinesInText(ifstream&);

//LOGGING IN__________________________________________________________________________________________________________________________________________________________________________

	void personPrompt();
	
	void employeePrompt();

	void customerPrompt();

	bool login(const string, const string);


//ACTIONS_____________________________________________________________________________________________________________________________________________________________________________

	void baseActions(const int);

	void customerActions(const int);

	void employeeActions(const int);

	void employeeChoice();

//VIEWING DATA________________________________________________________________________________________________________________________________________________________________________


	//added boolean so I could differenciate between customers and employees
	//for showing numbers
	void viewMenu(const bool);

	//added boolean so I could differenciate between customers and employees
	//for showing numbers
	void viewHours(const bool);

	void viewAddress();

	void viewPhone();


//SEARCHING MENUS_____________________________________________________________________________________________________________________________________________________________________

	void searchMenuByPrice();

	void searchByIngredients(const bool);

	string simplifyASCII(string);   

//EDITING ALL THE TEXT________________________________________________________________________________________________________________________________________________________________

	// selection is a dynamically allocated array of Pizza objects that are being ordered
	// selection_size indicates the number of Pizza objects in the array
	// num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
	
	void placeOrder(Pizza*, int, int*);
    
	void changeHours();
	void changeDay();
	void updateHours(ifstream&, const int);
	void removeDay();
	void updateHoursRemoval(ifstream&, const int);
	void addDay();	
	void updateHoursAddition(ifstream&, const string, const string, const string);

	void addToMenu();
	void updateMenuAddition(const string);
	
	void removeFromMenu();
	void updateMenuRemoval();

	void viewOrders();

	void removeOrders();

};

#endif

#include "restaurant.h"

//BIG THREE/DESTRUCTOR________________________________________________________________________________________________________________________________________________________________

Restaurant::Restaurant()
{
	//This isn't actually useful I just felt like putting it here
	this->employees = NULL;
	this->numberOfEmployees = 0;
	this->week = NULL;
	this->numberOfDays = 0;
	this->name = "bob";
	this->phone = "1234";
	this->address = "123 dang st";
}

//COPY CONSTRUCTOR
//JUST IN CASE I NEED IT FOR SOMETHING
/*************************************************************************************
 * Name: (COPY CONSTRUCTOR)
 * Description: This is the copy constructor. It is called when an instance of the
 * 		restaurant class is passed into a function. Additionally, it is called
 * 		when a new instance of the class is made and assigned to another at
 * 		creation (restaurant krustyKrab = bobsBurger)
 * Inputs: The previous restaurant where the information is from (&Restaurant)
 * Outputs: N/A
 ************************************************************************************/
Restaurant::Restaurant(const Restaurant & previousRestaurant)
{
	//Length Justification- Because there are 8 variables to copy over
	//This will be longer by necessity as the arrays require 2 lines
	//for memory allocation and looping through the values for a deep copy
	
	//Menu-The menu assignment operator will take care of this
	this->menu = previousRestaurant.menu;

	//Number of Employees
	this->numberOfEmployees = previousRestaurant.numberOfEmployees;
	
	//The employees themselves
	this->employees = new employee[numberOfEmployees]; 	
	for(int i = 0; i < this->numberOfEmployees; i++)
	{
		this->employees[i] = previousRestaurant.employees[i];
	}

	//For the number of days
	this->numberOfDays = previousRestaurant.numberOfDays;

	//For the days of the week
	this->week = new hours[numberOfDays];
	for(int i = 0; i < this->numberOfDays; i++)
	{
		this->week[i] = previousRestaurant.week[i];
	}

	//For the Restaurant Name
	this->name = previousRestaurant.name;

	//For the phone number
	this->phone = previousRestaurant.phone;

	//For the address
	this->address = previousRestaurant.address;
	
	
} 

//ASSIGNMENT OPERATOR OVERLOAD
/*************************************************************************************
 * Function Name: (ASSIGNMENT OPERATOR OVERLOAD)
 * Description: This is the assignment operator overload. This redefines the operator
 * 		"=" so that it can properly make a deep copy of any instances of
 * 		the restaurant class.
 * Inputs: The previous restaurant the information is from (& Restaurant)
 * Outputs: A new copy of the Restaurant (*Restaurant)
 ************************************************************************************/
Restaurant& Restaurant::operator = (const Restaurant & previousRestaurant)	
{

	//Length Justification- Because there are 8 variables to copy over
	//This will be longer by necessity as the arrays require 2 lines
	//for memory allocation and looping through the values for a deep copy
	
	if(this != &previousRestaurant)
	{
	
		//Menu-The menu assignment operator will take care of this
		this->menu = previousRestaurant.menu;

		//Number of Employees
		this->numberOfEmployees = previousRestaurant.numberOfEmployees;
	
		//The employees themselves
		this->employees = new employee[numberOfEmployees]; 	
		for(int i = 0; i < this->numberOfEmployees; i++)
		{
			this->employees[i] = previousRestaurant.employees[i];
		}

		//For the number of days
		this->numberOfDays = previousRestaurant.numberOfDays;

		//For the days of the week
		this->week = new hours[numberOfDays];
		for(int i = 0; i < this->numberOfDays; i++)
		{
			this->week[i] = previousRestaurant.week[i];
		}

		//For the Restaurant Name
		this->name = previousRestaurant.name;

		//For the phone number
		this->phone = previousRestaurant.phone;

		//For the address
		this->address = previousRestaurant.address;
	}

	return *this;	
}
//DESTRUCTOR
/*************************************************************************************
 * Function Name: (DESTRUCTOR)
 * Description: This is the destructor. It is called when the instaces of restaurant
 * 		are out of scope. It leans up the dynamically allocated information
 * 		so there are no memory leaks
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
Restaurant::~Restaurant()
{
	delete[] this->employees;
	this->employees = NULL;

	delete[] this->week;
	this->week = NULL;
}

//ACCESSORS/MUTATORS__________________________________________________________________________________________________________________________________________________________________

//For Menu

/*************************************************************************************
 * Function Name: getMenu
 * Description: Returns the Menu of the restaurant
 * Inputs: N/A
 * Outputs: The menu (Menu)
 ************************************************************************************/
Menu Restaurant::getMenu()
{
	return this->menu;
}
	
/*************************************************************************************
 * Function Name: setMenu
 * Description: Takes in a menu and makes the restaurant's menu equal to that menu
 * 		(There doesn't need to be much here because the assignment operator
 * 		overload in the menu class will take care if it)
 * Inputs: The old menu (Menu)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::setMenu(const Menu previousMenu)
{
	this->menu = previousMenu;
	return;
}

//For Employees

/*************************************************************************************
 * Function Name: getEmployees
 * Description: Returns the array of employees
 * Inputs: N/A
 * Outputs: The array of employees (employee*)
 ************************************************************************************/
const employee* Restaurant::getEmployees()
{
	return this->employees;
}

/*************************************************************************************
 * Function Name: setEmployees
 * Description: Takes in an array of employees and sets the restaurant's employees
 * 		equal to that array of employees. Also takes in the number of 
 * 		employees and assigns the restaurant's number of employes to that
 * Inputs: The employee array (employee**)
 * 	   The number of employees (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::setEmployees(const employee* employeeArray, const int arrayLength)
{
	//Sets number of employees
	setNumberOfEmployees(arrayLength);
	
	//Sets the employees
	this->employees = new employee[this->numberOfEmployees];
	for(int i = 0; i < this->numberOfEmployees; i++)
	{
		this->employees[i] = employeeArray[i];
	}

	return;
}	

/*************************************************************************************
 * Function Name: getNumberOfEmployees
 * Description: Returns the number of employees
 * Inputs: N/A
 * Outputs: The number of employees (int)
 ************************************************************************************/
const int Restaurant::getNumberOfEmployees()
{
	return this->numberOfEmployees;
}

/*************************************************************************************
 * Function Name: setNumberOfEmployees
 * Description: Takes in the number of employees and updates the restaurant's count
 * 		of employees
 * Inputs: Number of Employees (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::setNumberOfEmployees(const int numberOfEmployees)
{
	this->numberOfEmployees = numberOfEmployees;
	return;
}

//For Hours

/*************************************************************************************
 * Function Name: getHours
 * Description: Returns the weekday hours array of the restaurant.
 * Inputs: N/A
 * Outputs: The hour of the restaurant (hours*)
 ************************************************************************************/
hours* Restaurant::getHours()
{
	return this->week;
}

/*************************************************************************************
 * Function Name: setHours
 * Description: Takes in an array that holds the hours of the restaurant and updates
 * 		the restaurant's hours. Additionally, it sets the numberOfDays from
 * 		the numberOfDays that are manually entered.
 * Inputs: The hours array (hours*)
 * 	   The number of days (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::setHours(const hours* hoursArray, const int arrayLength)
{
	setNumberOfDays(arrayLength);

	this->week = new hours[this->numberOfDays];
	for(int i = 0; i < this->numberOfDays; i++)
	{
		this->week[i] = hoursArray[i];
	}
	
	return;
}

/*************************************************************************************
 * Function Name: getNumberOfDays
 * Description: Returns the number of days of the week that the restaurant is open for
 * Inputs: N/A
 * Outputs: The number of days the restaurant is open (int)
 ************************************************************************************/
const int Restaurant::getNumberOfDays()
{
	return this->numberOfDays;
}

/*************************************************************************************
 * Function Name: setNumberOfDays
 * Description: Takes in the number of days the restaurant is open for and updates
 * 		that number in the restaurant class' variable.
 * Inputs: The number of days open (int)
 * Outputs:
 ************************************************************************************/
void Restaurant::setNumberOfDays(const int numberOfDays)
{
	this->numberOfDays = numberOfDays;
	return;
}
	
//FOR RESTAURANT INFORMATION

//For Name

/*************************************************************************************
 * Function Name: getName
 * Description: Returns the name of the restaurant
 * Inputs: N/A
 * Outputs: The name of the restaurant (string)
 ************************************************************************************/
const string Restaurant::getName()
{
	return this->name;
}
	
/*************************************************************************************
 * Function Name: setName
 * Description: Takes in the name of the restaurant and updates the restaurant's name
 * Inputs: The name of the restaurant (string)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::setName(const string name)
{
	this->name = name;
	return;
}

//For Phone

/*************************************************************************************
 * Function Name: getNumber
 * Description: Returns the restaurant's phone number
 * Inputs: N/A
 * Outputs: The restaurant's number (int)
 ************************************************************************************/
const string Restaurant::getNumber()
{
	return this->phone;
}

/*************************************************************************************
 * Function Name: setNumber
 * Description: Takes in the phone number and updates the restaurant's phone number
 * Inputs: The new phone number (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::setNumber(const string number)
{
	this->phone = number;
	return;
}

//For Address

/*************************************************************************************
 * Function Name: getAddress
 * Description: Returns the restaurant's address
 * Inputs: N/A
 * Outputs: The restauarant's address (string)
 ************************************************************************************/
const string Restaurant::getAddress()
{
	return this->address;
}
 
/*************************************************************************************
 * Function Name: setAddress
 * Description: Takes in the new address and updates the restaurant class' address
 * 		variable
 * Inputs: The address (string)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::setAddress(const string address) 
{
	this->address = address;
	return;
}

//LOGIN/LOADINGDATA___________________________________________________________________________________________________________________________________________________________________

/*************************************************************************************
 * Function Name: loadData
 * Description: Calls the functions that load the data from the text files.
 * Inputs: N/A* Outputs: N/A
 ************************************************************************************/
void Restaurant::loadData() //reads from files to correctly populate menu, employees, hours, etc.
{
	ifstream inputFile;
	int lineCount = 0;	
	
	//Counts the lines of the Restaurant info file and loads the information
	inputFile.open("restaurant_info.txt");
	lineCount = countLinesInText(inputFile);
	loadRestaurantData(inputFile, lineCount);

	//Counts the lines of the menu file and loads the information
	inputFile.open("menu.txt");
	lineCount = countLinesInText(inputFile);
	loadMenuData(inputFile, lineCount);	

	//Counts the lines of the employee file and loads the information
	inputFile.open("employee.txt");
	lineCount = countLinesInText(inputFile);
	loadEmployeeData(inputFile, lineCount);

/*
	inputFile.open("orders.txt");
	lineCount = countLinesInText(inputFile);
	loadOrderData(inputFile, lineCount);		
*/
	return;	
}

/*************************************************************************************
 * Function Name: loadRestaurantData
 * Description: Loads all the information from the "restaurant_info.txt" file to our
 * 		restaurant class
 * Inputs: A reference to the ifstream object (ifstream&)
 * 	   The line count of the file (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::loadRestaurantData(ifstream &inputFile, const int lineCount)
{

	string finalString;

	//Sets the name
	inputFile.open("restaurant_info.txt");
	getline(inputFile, finalString);
	setName(finalString);

	//Loads the phone number of the restaurant
	loadNumber(inputFile);	

	//Loads the address
	getline(inputFile, finalString);
	setAddress(finalString);

	//Loads the hours
	loadHours(inputFile, lineCount - 3);

	inputFile.close();		
	return;
}

/*************************************************************************************
 * Function Name: loadNumber
 * Description: Takes in the open filestream and gets the phone number. It parses 
 * 		through the phone number and removes the non-numbers
 * Inputs: Reference to the ifstream object (ifstream&)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::loadNumber(ifstream& inputFile)
{
	string temporaryString, finalString;

	getline(inputFile, temporaryString);

	//Converts the phone number from the file format
	for(int i = 0; i < temporaryString.length(); i++)
	{
		char x = temporaryString[i];
		if(x > 47 && x < 58)
			finalString += x;
	}

	//Sets the phone number
	setNumber(finalString);
	
	return;
}
	
/*************************************************************************************
 * Function Name: loadHours
 * Description: Takes the hours data from the file and puts it into the Restaurant's
 * 		hour array.
 * Inputs: A reference to the ifstream object (ifstream&)
 * 	   The amount of days/lines left in the file (int)
 * Outputs:
 ************************************************************************************/
void Restaurant::loadHours(ifstream& inputFile, const int lineCount)
{
	//Goes through the hours array and loads all the information 
	hours hoursArray[lineCount];
	for(int i = 0; i < lineCount; i++)
	{
		inputFile >> hoursArray[i].day;
		inputFile >> hoursArray[i].open_hour;
		inputFile >> hoursArray[i].close_hour;
	}

	//Sets the restaurant's hours array equal to the loaded one
	setHours(hoursArray, lineCount);		

	return;
}


/*************************************************************************************
 * Function Name: loadMenuData
 * Description: Loads the menu information from the "menu.txt" file
 * Inputs: A reference to the ifstream object (ifstream&)
 * 	   The line count of the file (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::loadMenuData(ifstream &inputFile, const int lineCount)
{
	
	inputFile.open("menu.txt");

	menu.setNumberOfPizzas(lineCount);

	Pizza pizzaArray[lineCount];

	//Uses the populate pizza function to load all the menu data
	for(int i = 0; i < lineCount; i++)
	{
		pizzaArray[i].populatePizza(inputFile);
	}

	//Sets the pizza array in the menu equal to the loaded one
	menu.setPizzaArray(pizzaArray, lineCount);

	inputFile.close();	
	return;
}


/*************************************************************************************
 * Function Name: loadEmployeeData
 * Description: Takes in the employee data from the "employee.txt" file and puts it 
 * 		into the restaurant's records.
 * Inputs: A reference to the ifstream object (ifstream&)
 * 	   The number of employes/line count (int)
 * Outputs:
 ************************************************************************************/
void Restaurant::loadEmployeeData(ifstream &inputFile, const int lineCount)
{
	//Opens file
	inputFile.open("employee.txt");

	//Stores the number of employees in the Restaurant's records
	setNumberOfEmployees(lineCount);

	//Stores employees temporarily
	employee employeeArray[lineCount];

	for(int i = 0; i < lineCount; i++)
	{
		//Gets out all the information from the files
		inputFile >> employeeArray[i].id;
		inputFile >> employeeArray[i].password;
		inputFile >> employeeArray[i].first_name;
		inputFile >> employeeArray[i].last_name;

	}	
	
	//Actually stores it into the restaurant's data
	setEmployees(employeeArray, lineCount);
	inputFile.close();

	return;
}

/*************************************************************************************
 * Function Name: countLinesInText
 * Description: Counts the number of lines in a text file
 * Inputs: A reference to the input stream object(ifstream&)
 * Outputs: The number of lines in the file (int)
 ************************************************************************************/
int Restaurant::countLinesInText(ifstream& inputFile)
{
	//Counter for the lines
	int lineCount = 0;
	
	//Kind of doesn't do anthing but exist
	string useless;

	//Checks to see if there is a line in the file
	while(!inputFile.eof() && getline(inputFile, useless))
	{
		//Increments line count
		lineCount++;
	}
	
	//Closes file
	inputFile.close();

	//Outputs line count
	return lineCount;
}

//LOGGING IN__________________________________________________________________________________________________________________________________________________________________________

/*************************************************************************************
 * Function Name: personPrompt
 * Description: Determines whether the user is a customer or an employee and executes
 * 		the according maneuver.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::personPrompt()
{
	//Message to the user
	cout << "Are you a customer or an Employee? Type according  to the following:" << endl << "Employee: (E) or (e)" << endl << "Customer (Anything except E or e)" << endl;
	char choice;

	//Prompts user
	cin >> choice;

	//Clears the stream to prevent oddities
	cin.clear();
	cin.ignore(1000000,'\n');

	//Acts according to user's answer
	if(choice == 'E' || choice == 'e')
		employeePrompt();
	else
		customerPrompt();


	return;
}

/*************************************************************************************
 * Function Name: employeePrompt
 * Description: Calls all the actions of an employee
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::employeePrompt()
{
	bool validEmployee = false;

	//Welcome message
	cout << "Welcome to the Employee Portal." << endl <<  "Enter 1 if you would like to exit the Employee Portal\nOtherwise, enter anything else to proceed to login." << endl;
	int choice;
	
	string ID, password;

	//Prompts user	
	cin >> choice;		

	//Clears the stream to prevent oddities
	cin.clear();
	cin.ignore(1000000,'\n');

	//Acts according to their choice
	if(choice == 1)
		return;

	//Prompts for their login information.
	cout << "If you enter invalid credentials, you will be brought back to the home screen>" << endl <<  "Enter your ID" << endl;
	cin >> ID;
	cout << "Enter your password" << endl;
	cin >> password;
			
	//Checks to see if their credientals match
	validEmployee = login(ID, password);
	
	//Checks to see if they are actually an employee/acts accordingly
	if(validEmployee)
		employeeChoice();

	return;
}

/*************************************************************************************
 * Function Name: customerPrompt
 * Description: Calls all the actions of a customer
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::customerPrompt()
{
	
	while(1)
	{
		cout << endl << "Welcome Valued customer!\nWhat action would you like to do?\nEnter one of the values according." << endl;
	
		//Technically this line doesn't need to exist, it could've been in the one above, it just makes it easier to read.
		cout << "1) Exit to the home screen\n2) View our menu\n3) View our hours\n4) Get our address\n5) Get our phone number" << endl;

		cout << "6) Search Menu by Price\n7) Search Menu by Including Ingredients\n8) Search Menu by Excluding Ingredients\n9) Place Order" << endl;
		int choice;

		cin >> choice;

		if(choice == 1)
			break;
		else
		{
			//enables customer actions
			baseActions(choice);	
			customerActions(choice);	
		}	
	}
	return;
}

/*************************************************************************************
 * Function Name: login
 * Description: Checks to see if the login credentials match anything in the 
 * 		restaurant's data
 * Inputs: The ID (string)
 * 	   The password (string)
 * Outputs: The validity of the credentials (bool)
 ************************************************************************************/
bool Restaurant::login(const string ID, const string password)
{
	bool validity = false;

	//Goes through all the employee login credentials.
	for(int i = 0; i < getNumberOfEmployees(); i++)
	{
		//Checks to see if there is a match of login credentials
		if(getEmployees()[i].id == atoi(ID.c_str()) && getEmployees()[i].password.compare(password.c_str()) == 0)
		{
			//Changes the validity to show that they are indeed an employee and welcomes them
			validity = true;
			cout << "Welcome " << getEmployees()[i].first_name << " " << getEmployees()[i].last_name << "!" << endl;	
		}
	}

	//Tells the user if somethign went wrong	
	if(!validity)	
		cout << "Your login credentials did not match any of our records." << endl;

	return validity;
}

//ACTIONS_____________________________________________________________________________________________________________________________________________________________________________

/*************************************************************************************
 * Function Name: customerActions
 * Description: This is the continuation of customer prompt. Has actions 2-5
 * Inputs: The choice the customer made (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::baseActions(const int choice)
{
	//Chooses basic actions
	switch(choice)
	{
		case 2:
			viewMenu(false);
			break;
		case 3:
			viewHours(false);
			break;
		case 4:
			viewAddress();
			break;

		case 5:
			viewPhone();
			break;

		default:
			break;
	}

	return;

	
}

/*************************************************************************************
 * Function Name: customerActions
 * Description: Calls all the acitons that the customer can do
 * Inputs: The choice they made (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::customerActions(const int choice)
{
	//Calls the customer actions dependent on the one that was chosen
	switch(choice)
	{
		case 6:
			searchMenuByPrice();	
			break;
		case 7:
			searchByIngredients(true);
			break;
		case 8:
			searchByIngredients(false);
			break;
		case 9:
		//	placeOrder();
			break;
		default:
			break;
	}
}

/*************************************************************************************
 * Function Name: employeeChoice
 * Description: Prompts the employee for their choice and takes the appropriate action
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::employeeChoice()
{
	//Prompts the emplyee action continuously
	while(1)
	{
		cout << "What action do you want to take?" << endl;

		//Base actions
		//Technically this line doesn't need to exist, it could've been in the one above, it just makes it easier to read.
		cout << "1) Exit to the home screen\n2) View our menu\n3) View our hours\n4) Get our address\n5) Get our phone number" << endl;
	
		//Same with this line
		cout << "6) Change Restaurant Hours\n7) Add to Menu\n8) Remove items from the menu\n9) View Orders\n10) Remove orders" << endl << endl;

		int choice;
		
		cin >> choice;
	
		if(choice == 1)
			break;
		else
		{
			//enables employee action
			baseActions(choice);
			employeeActions(choice);
		}

	}
	
	return;
}
/*************************************************************************************
 * Function Name: employeeActions
 * Description: Calls the appropriate action based on choice
 * Inputs: The choice made by the user (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::employeeActions(const int choice)
{
	//Calls corresponding function dependent on choice
	switch(choice)
	{
		case 6:
			changeHours();		
			break;
		case 7:
			addToMenu();
			break;
		case 8:
			removeFromMenu();	
			break;
		case 9:
			viewOrders();
			break;
		case 10:
			removeOrders();
			break;
		default:
			break;
	}
}
//VIEWING DATA________________________________________________________________________________________________________________________________________________________________________

/*************************************************************************************
 * Function Name: viewMenu
 * Description: Shows the entire menu to the user. Shows customer and employee
 * 		different formats based on the situation
 * Inputs: Employee or customer (bool, true = employee)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::viewMenu(bool check)
{

	//Tells the user what is happening
	cout << endl << "Here is our menu.\nThe format is as follows: <Pizza Name> (Costs for: <small> <medium> <large>) <number of ingredients> <An ingredient>  <an ingredient> ... <nth ingredient>" << endl << endl;

	//Goes through all hte pizzas on the menu	
	for(int i = 0; i < getMenu().getNumberOfPizzas(); i++)
	{
	
		//Makes an instance of this pizza on the stack just for simplicity's sake.
		Pizza x = getMenu().getPizzas()[i];


		//For the employees
		if(check)
			cout << i + 1 << ") ";

		//Prints out everything up to the number of ingredients
		cout << x.getName() << " " << x.getSmallCost() << " " << x.getMediumCost() << " " << x.getLargeCost() << " " << x.getNumberOfIngredients() << " ";
		
		//Prints out actual ingredients
		for(int j = 0; j < x.getNumberOfIngredients(); j++)
		{
			cout << x.getIngredients()[j] << " ";
		} 
		
		//Ends line as it is the start of a new pizza
		cout << endl << endl;
	}
	
	return;
}

/*************************************************************************************
 * Function Name: viewHours
 * Description: Shows the customer the restaurant's hours. Will show different result
 * 		based on whether an employee or customer accesses this
 * Inputs: Employee or customer (bool, true = employee)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::viewHours(const bool check)
{
	//Tells the user about formatting
	cout << endl << "Here are our hours for the week.\nThe format is as follows: <Day> <Opening Time> <Closing Time>" << endl << endl;

	//Goes through all the days of the wekk
	for(int i = 0; i < getNumberOfDays(); i++)
	{
		//For simplicity's sake
		hours x = getHours()[i];

		//For the employees
		if(check)
			cout << i + 1 << ") ";

		//Prints our the hours
		cout << x.day << " " << x.open_hour << " " << x.close_hour << endl << endl;	
	}

	return;
}

/*************************************************************************************
 * Function Name: viewAddress
 * Description: Prints out the address to show the user
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::viewAddress()
{
	//Tells the user our address
	cout << endl << "Our address is: " << getAddress() << endl << endl;	
	return;
}

/*************************************************************************************
 * Function Name: viewPhone
 * Description: Tells the user our phoen number
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::viewPhone()
{
	//Tells the user our phone number
	cout << endl << "Our phone number is: " << getNumber() << endl << endl;
	return;
}


//SEARCHING MENUS_____________________________________________________________________________________________________________________________________________________________________

/*************************************************************************************
 * Function Name: searchMenuByPrice
 * Description: Searchs through the menu and outputs a
 * Inputs: N/A
 * Outputs: N/a
 ************************************************************************************/
void Restaurant::searchMenuByPrice()
{
	//This is a bit longer than it should be. It just felt unnecessary to split it into
	//two because it is close enough to 15. Additionally, the majority of the size
	//came from a REPITIVE code that was necessary to go through each little cost
	
	int upperBound;

	//Message to user and prompt for LIMIT
	cout << "What would you like your upper limit cost to be?" << endl;
	cin >> upperBound;
	cout << "Here is the filtered menu" << endl << endl;

	//This loop goes through all of the pizzas
	for(int i = 0; i < getMenu().getNumberOfPizzas(); i++)
	{
		//This just simplifies the writing
		Pizza x = getMenu().getPizzas()[i];
	
		//Prints out of the name of the pizza
		cout << x.getName() << " ";

		//Filters out the costly pizzas
		if(x.getSmallCost() > upperBound)
			cout << "N/A ";
		else
			cout << x.getSmallCost() << " ";
		
		if(x.getMediumCost() > upperBound)
			cout << "N/A ";
		else
			cout << x.getMediumCost() << " ";
		
		if(x.getLargeCost() > upperBound)
			cout << "N/A ";
		else
			cout << x.getLargeCost() << " ";

		//Prints out of the number of ingredients
		cout << x.getNumberOfIngredients() << " ";
		
		//Prints out all of the ingredients
		for(int j = 0; j < x.getNumberOfIngredients(); j++)
		{
			cout << x.getIngredients()[j] << " ";
		}
		cout << endl << endl;
	}	
}

/*************************************************************************************
 * Function Name: searchByIngredients
 * Description: Takes in the check variable, and depending on whether or not it is 
 * 		true, will search by inclusion or exclusion (check == inclusion,
 * 		!check = exclusion)
 * Inputs: The inclusion/exclusion variable (check)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::searchByIngredients(const bool check)
{
	//Prompts the user for the word in question
	//Whether it be the excluded word or the searched for word
	string word;
	cout << "What is the ingredient in question?" << endl;	
	cin >> word;
	
	//Simplifies that word so capitalizaiton doesn't matter
	string ingredient = simplifyASCII(word);

	//Goes through all the pizzas
	for(int i = 0; i < getMenu().getNumberOfPizzas(); i++)
	{
		//This checks to see if the pizza should or should no be included
		bool question = false;

		//This is for convience in writing
		Pizza x = getMenu().getPizzas()[i];
			
		//Goes through all the ingredients of this specific pizza
		for(int j =  0; j < x.getNumberOfIngredients(); j++)
		{
			//This is also for convience
			//It simplifies the ingredient so it can be properly compared
			string b = simplifyASCII(x.getIngredients()[j]);
				
			//This is looking for inclusion
			if(check)
			{
				if(ingredient.compare(b) == 0 && check)
					question = true;	
			}
			//This is looking for exclusion
			else
			{
				//This one only needs 1 false in order to exclude
				//the pizza
				question = true;
				if(ingredient.compare(b) ==0)
					question = false;
			}

		}
		
		//Prints out the pizza
		if(question)
		{
	
			//Prints out the name, costs, and ingredients
			cout << x.getName() << " " << x.getSmallCost() << " " << x.getMediumCost() << " " << x.getLargeCost() << " " << x.getNumberOfIngredients() << " ";
			for(int j =  0; j < x.getNumberOfIngredients(); j++)
			{
				cout << x.getIngredients()[j] << " ";	
			}
		
			cout << endl;
	
		}
	
	}


	
}

/*************************************************************************************
 * Function Name: simplifyASCII
 * Description: Takes in a string and rids it of differences in capitalization
 * Inputs: The word in question (string)
 * Outputs: The fully capitalized word (string)
 ************************************************************************************/
string Restaurant::simplifyASCII(string word)  
{
	for(int i = 0; i < word.length(); i++)
	{
		int letter = word[i];
		//Upper case region
		if(letter > 64 & letter < 91)
			/*Nothing*/;
		//Lower case region
		else if(letter > 96 & letter < 123)
			word[i] -= 32;
		//Alloqs spaces through
		else if(letter == 32)
			/*nothing*/;
		//In case of error, returns 'A'
		else
			word[i] = 'A';
	}
	return word;
}
//EDITING ALL THE TEXT________________________________________________________________________________________________________________________________________________________________

// selection is a dynamically allocated array of Pizza objects that are being ordered
// selection_size indicates the number of Pizza objects in the array
// num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered

/*************************************************************************************
 * Function Name:
 * Description:
 * Inputs:
 * Outputs:
 ************************************************************************************/
void Restaurant::placeOrder(Pizza* selection, int selectionSize, int* numberOrdered)
{
/*
	int choice;
	cout << "Which Pizza do you want? Select the number as you saw previously." << endl;
	cin >> choice;

	if(!cin || choice > selectionSize || choice < 0)
	{
		cout << "Invalid number, returning to the welcome screen" << endl;
		return;
	}  
	else
	{
		string size;
		cout << "What size of pizza?" << endl;
		cin >> size;
	}
*/	
}

/*************************************************************************************
 * Function Name: changeHours
 * Description: Can be used to change the hours of the restaurant by removing hours, 
 * 		adding new hours or changing hours that already exist
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::changeHours()
{
	//Shows the hours
	viewHours(true);

	cout << "Would you like to:\n1) Change Hours\n2) Remove Hours\n3) Add hours" << endl;
	int choice;
	cin >> choice;

	//Checks to see if they want to change the days
	if(choice == 1)
		changeDay();	
	//Checks to see if they want to remove a day
	else if(choice == 2)
		removeDay();
	//Checks to see if they want to add a day
	else
		addDay();
	
	return;
}

/*************************************************************************************
 * Function Name: changeDay
 * Description: Prompts a change for a pre-existing day.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::changeDay()
{
	//Prompts which line they want to edit
	int choice;
	cout << "Which set of hours would you like to change? Enter the number that is between 1 and " << getNumberOfDays() <<"\nIf you enter something invalid, this will not do anything." << endl;
	cin >> choice;

	//Makes sure it's a actual number
	if(!cin || choice < 1 || choice > getNumberOfDays())
		return;
	else
	{
		//Prompts the user for inputs
		cout << "What is the new day's name?" << endl;
		cin >> getHours()[choice-1].day;
	
		cout << "Please enter the opening time with AM or PM included" << endl;
		cin >> getHours()[choice-1].open_hour;

		cout << "Please enter the closing time with AM or PM included" << endl;
		cin >> getHours()[choice-1].close_hour;

		ifstream outputFile;
		outputFile.open("restaurant_info.txt");

		//Updates the file
		updateHours(outputFile, choice);
	}
	
	return;
}

/*************************************************************************************
 * Function Name: updateHours
 * Description: Takes in the file and lien of choice, swaps it out with the info
 * 		in the restaurant classes' books
 * Inputs: A reference to the ifstreamm object (ifstream &)
 * 	   The choice of line (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::updateHours(ifstream& outputFile, const int choice)
{
		string output, temporaryString;

		//Goes through till the specific line in question
		for(int i = 0; i < choice + 2; i++)
		{
			getline(outputFile, temporaryString);
			output += (temporaryString + "\n");
		}
		
		//Adds the change the user wanted to make
		output+= (getHours()[choice-1].day + " " + getHours()[choice-1].open_hour + " " + getHours()[choice-1].close_hour);
		
		//Skips the old file.
		getline(outputFile, temporaryString);
		
		//Copies the rest of the file
		for(int i = 0; i < getNumberOfDays() - choice; i++)
		{
			getline(outputFile, temporaryString);
			output += ("\n" + temporaryString);
		}
		
	
		outputFile.close();

		ofstream actualOutput;
		
		actualOutput.open("restaurant_info.txt");

		//Updates the file
		actualOutput << output;

		actualOutput.close();
}

/*************************************************************************************
 * Function Name: removeDay
 * Description: Prompts the user for which day that would likee removed and calls the
 * 		function that removes the day from the file
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::removeDay()
{
	//Prompts which line they want to edit
	int choice;
	cout << "Which set of hours would you like to remove? The removal becomes permanant AFTER you log off.\nEnter the number that is between 1 and " << getNumberOfDays() <<"\nIf you enter something invalid, this will not do anything." << endl;
	cin >> choice;
	
		
	if(!cin || choice < 1 || choice > getNumberOfDays())
		return;
	else
	{
		//Updates Restaurant class
		getHours()[choice-1].day = "N/A";
		getHours()[choice-1].open_hour = "N/A";
		getHours()[choice-1].close_hour = "N/A";
	
		//Updates file
		ifstream outputFile;
		outputFile.open("restaurant_info.txt");
		updateHoursRemoval(outputFile, choice);

	}
}

/*************************************************************************************
 * Function Name: updateHoursRemoval
 * Description: Updates the restaurant.txt file after a removal request
 * Inputs: A reference to the ifstream object (ifstream&)
 * 	   The line in question to remove (int)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::updateHoursRemoval(ifstream& outputFile, const int choice)
{
		string output, temporaryString;

		//Goes through till the specific line in question
		for(int i = 0; i < choice + 2; i++)
		{
			getline(outputFile, temporaryString);
			output += (temporaryString + "\n");
		}
		
		//Skips the old file line
		getline(outputFile, temporaryString);
		
		//Copies the rest of the file
		for(int i = 0; i < getNumberOfDays() - choice - 2; i++)
		{
			getline(outputFile, temporaryString);
			output += (temporaryString + "\n");
		}

		//UNFORNATELY I had to do this to preven it from adding one new \n to the file
		getline(outputFile, temporaryString);
		output += (temporaryString);
	
		outputFile.close();

		ofstream actualOutput;
		
		actualOutput.open("restaurant_info.txt");

		//Updates the file
		actualOutput << output;

		actualOutput.close();
}

/*************************************************************************************
 * Function Name: addDay
 * Description: Prompts the user for the information of the day they would like to add
 * 		and then adds it to the end of the file.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::addDay()
{
	//Prompts which line they want to edit
	string day, openingTime, closingTime;
	cout << "What hours would you like to add? The hours are added permanently AFTER you log off.\n\nPlease enter the day" << endl;
	cin >> day;
		
	cout << "Please enter the opening time" << endl;
	cin >> openingTime;

	cout << "Please enter the closing time" << endl;
	cin >> closingTime;

	ifstream outputFile;
	outputFile.open("restaurant_info.txt");
	updateHoursAddition(outputFile, day, openingTime, closingTime);
}

/*************************************************************************************
 * Function Name: updateHoursAddition
 * Description: Updates the file for the addition of a day
 * Inputs: A reference to the ifstream object(ifstream&)
 * 	   The day, opening and closing time (string)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::updateHoursAddition(ifstream& outputFile, const string day, const string openingTime, const string closingTime)
{
		string output, temporaryString;

		//Goes through entire file
		for(int i = 0; i < getNumberOfDays() + 3; i++)
		{
			getline(outputFile, temporaryString);
			output += (temporaryString + "\n");
		}
		
		output += (temporaryString + "\n");
	
		output+= (day + " " + openingTime + " " + closingTime);
		
		outputFile.close();

		ofstream actualOutput;
		
		actualOutput.open("restaurant_info.txt");

		//Updates the file
		actualOutput << output;

		actualOutput.close();
}

/*************************************************************************************
 * Function Name: addToMenu
 * Description: Prompts the user for what kind of pizza and all the other information
 * 		they would like to add to the menu. Then adds it to the menu.
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::addToMenu()
{
	//Length justification - Do to the five inputs that are required, this function has
	//to be longer than the ideal length. Technically it could be reduced to JUST TWO LINES
	//but that way is far less elegant and would require the user enter all the information at once.
	string finalString, name, small, medium, large, ingredientsNumber, temporaryString;

	cout << "The Addition becomes permanent AFTER YOU LOG OFF" << endl;

	cout << "What is the name of the pizza you would like to add?" << endl;
	cin >> name;
	
	cout << "What is the cost of a small pizza?" << endl;
	cin >> small;

	cout << "What is the cost of a medium pizza?" << endl;
	cin >> medium;

	cout << "What is the cost of a large pizza?" << endl;
	cin >> large;
	
	cout << "How manu ingredients are there? Enter only integers please." << endl;
	cin >> ingredientsNumber;

	finalString = (name + " " + small + " " + medium + " " + large + " " + ingredientsNumber + " "); 

	for(int i = 0; i < atoi(ingredientsNumber.c_str()); i++)
	{
		cout << "Please enter an ingredient" << endl;
		cin >> temporaryString;
		finalString += (temporaryString + " ");
	}

	updateMenuAddition(finalString);
	
	return;
}

/*************************************************************************************
 * Function Name: updateMenuAddition
 * Description: Updates the menu file with the new addition
 * Inputs: The new addition (string)
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::updateMenuAddition(const string output)
{
	string finalString, temporaryString;

	//Opens the file and counts the lines	
	ifstream outputFile;
	outputFile.open("menu.txt");		
	int count = countLinesInText(outputFile);

	//The function above closes the file so we have to open it once more.
	outputFile.open("menu.txt");		
	for(int i = 0; i < count; i++)
	{
		getline(outputFile, temporaryString);
		finalString += (temporaryString + "\n");		
	}
	
	finalString += output;

	outputFile.close();

	ofstream actualOutput;
	
	actualOutput.open("menu.txt");
	
	actualOutput << finalString;

	actualOutput.close();
}

/*************************************************************************************
 * Function Name: removeFromMenu
 * Description: The user can choose to remove an item from the menu
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::removeFromMenu()
{

	//Length Justification. This function essentially achieves a purpose that I 
	//have used two functions for previously. It's only a bit over 15 so it just
	//seemed unnecessary to split into two functions, although I could have. 
	//The mean reason is a lot of the lines are very SIMPLE things like opening and
	//closing a file.

	int choice;
	string finalString, temporaryString;

	//Shows the user the menu
	viewMenu(true);
		
	//Opens the file and counts the lines	
	ifstream outputFile;
	outputFile.open("menu.txt");		
	
	//Prompts them for a line to remove
	cout << "Which item would you like to remove from the menu?\nThis will do nothing if you enter an invalid number" << endl;
	cin >> choice;

	//Checks to see if their input is valid
	if(!cin || choice > getMenu().getNumberOfPizzas() || choice < 0)
	{
		cout << "You have entered an invalid number" << endl;
	}
	else
	{
		//Goes up until that line
		for(int i = 0; i < choice - 1; i++)
		{
			//Copies everything up to the line
			getline(outputFile, temporaryString);
			finalString += (temporaryString + "\n");		
		}
	
		//Skips the line in question
		getline(outputFile, temporaryString);

		//Copies the rest of the file
		for(int i = 0; i < getMenu().getNumberOfPizzas() - choice - 1; i++)
		{
			getline(outputFile, temporaryString);
			finalString += (temporaryString + "\n");		
		}

		//UNFORNATELY I had to do this to preven it from adding one new \n to the file
		getline(outputFile, temporaryString);
		finalString += (temporaryString);
	
		outputFile.close();
		
		ofstream actualOutput;
	
		//Actually outputs the corrected file to the neew file.
		actualOutput.open("menu.txt");
	
		actualOutput << finalString;

		actualOutput.close();
	}

	return;

}

/*************************************************************************************
 * Function Name: viewOrders
 * Description: Shows the user what all the orders are (from the orders.txt document)
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::viewOrders()
{
	//Variable declarations
	ifstream inputFile;
	string finalString, temporaryString;

	//Counts the amount of lines withing the document
	inputFile.open("orders.txt");
	int count = countLinesInText(inputFile);

	//The file must be reopened as the count lines function closes it
	inputFile.open("orders.txt");
	for(int i = 0; i < count; i++)
	{
		getline(inputFile, temporaryString);
		cout << i + 1 << ") " << temporaryString << endl;
	}

	return;	
}

/*************************************************************************************
 * Function Name: removeOrders
 * Description: Prompts the user for a specific order and removes that order for the
 * 		orders.txt file
 * Inputs: N/A
 * Outputs: N/A
 ************************************************************************************/
void Restaurant::removeOrders()
{
	
	//Length Justification. This function essentially achieves a purpose that I 
	//have used two functions for previously. It's only a bit over 15 so it just
	//seemed unnecessary to split into two functions, although I could have. 
	//The mean reason is a lot of the lines are very SIMPLE things like opening and
	//closing a file.

	viewOrders();

	//Variable declarations
	ifstream outputFile;
	string finalString, temporaryString;
	int choice;

	//Counts the amount of lines withing the document
	outputFile.open("orders.txt");
	int count = countLinesInText(outputFile);

	//Prompts them for a line to remove
	cout << "Which item would you like to remove from the orders?\nThis will do nothing if you enter an invalid number" << endl;
	cin >> choice;

	//Checks to see if their input is valid
	if(!cin || choice > count || choice < 0)
	{
		cout << "You have entered an invalid number" << endl;
	}
	else
	{

		//The count line function closes this so we have to open it again
		outputFile.open("orders.txt");

		//Goes up until that line
		for(int i = 0; i < choice - 1; i++)
		{
			//Copies everything up to the line
			getline(outputFile, temporaryString);
			finalString += (temporaryString + "\n");		
		}
	
		//Skips the line in question
		getline(outputFile, temporaryString);

		//Copies the rest of the file
		for(int i = 0; i < count - choice - 1; i++)
		{
			getline(outputFile, temporaryString);
			finalString += (temporaryString + "\n");		
		}

		//UNFORNATELY I had to do this to preven it from adding one new \n to the file
		getline(outputFile, temporaryString);
		finalString += (temporaryString);
	
		outputFile.close();
		
		ofstream actualOutput;
	
		//Actually outputs the corrected file to the neew file.
		actualOutput.open("orders.txt");
	
		actualOutput << finalString;

		actualOutput.close();
	}

	return;
}





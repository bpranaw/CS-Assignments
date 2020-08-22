#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <fstream>
#include "menu.h"
#include "emp_hours.h"

using namespace std;

class Restaurant {
  private:
    Menu menu;
    employee* employees;
    hours* week;
    string name;
    string phone;
    string address;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    void load_data(); //reads from files to correctly populate menu, employees, hours, etc.
    bool login(string id, string password);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void search_menu_by_price();
    void search_by_ingredients();
    
    // Only one of the following two prototypes should be used:
    // selection is a dynamically allocated array of Pizza objects that are being ordered
    // selection_size indicates the number of Pizza objects in the array
    // num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
    void place_order(Pizza* selection, int selection_size, int* num_ordered);
    // you may also choose to use this prototype:
    //void place_order(Pizza* selection);
    
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();
};

#endif

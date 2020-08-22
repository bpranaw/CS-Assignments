#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <fstream>

using namespace std;

class Pizza {
  private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    int num_ingredients;
    string* ingredients;
  public:
	Pizza();
	~Pizza();

void setName(const string);

const string getName();


void setNumberOfIngredients(const int);

const int getNumberOfIngredients();

void setSmallCost(const float);

const float getSmallCost();

void setMediumCost(const float);

const float getMediumCost();

void setLargeCost(const float);

const float getLargeCost();

oks like I spoke too soon, it is mentioned at the end of the problem statement)
void setIngredients(const int);

const string* getIngredients();

void populatePizza(ifstream&);

};

#endif

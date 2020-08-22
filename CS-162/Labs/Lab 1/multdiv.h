struct multdivEntry
{
	int mult;
	float div;
};

bool isValidDimensions(int*, int*);
multdivEntry** createTable(int, int);
void printTable(multdivEntry**, int, int);
void deleteTable(multdivEntry**, int);

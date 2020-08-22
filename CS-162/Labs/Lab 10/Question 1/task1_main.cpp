
#include <iostream>

#include <cstdlib>
#include <vector>

#include <chrono>
#include <iomanip>

using namespace std;

int get_memory_usage_kb(long* vmrss_kb, long* vmsize_kb);
bool containsDuplicate (vector<int>& nums);






bool result(int num, bool actual, bool expected){
	if (expected != actual){
		cout << "Test " << num << " failed" << endl;
		return false;
	}
	cout << "Test " << num << " passed" << endl;
	return true;
}


void print_vector(vector<int> &nums){
	cout << "[";
	for (int x : nums)
		cout << x << ", ";
	cout << "]" << endl;
}



int main() {
	srand(time(NULL));

	//variables for memory calculation
    long vmrss, vmsize;

    //declare and initialize vector1-vector10
    vector<int> vector1; //empty vector []

    vector<int> vector2; //contains one element [0]
    vector2.push_back(0);

    vector<int> vector3; // [3, 1]
    vector3.push_back(3);
    vector3.push_back(1);

    vector<int> vector4; // [3, 3]
    vector4.push_back(3);
    vector4.push_back(3);

    vector<int> vector5; // [1, 2, 3, 4]
    for (int i = 0; i < 4; ++i)
    	vector5.push_back(i+1);
    
    vector<int> vector6; // [3, 1, 2, 3, 4]
    vector6.push_back(3);
    for (int i = 0; i < 4; ++i)
    	vector6.push_back(i+1);

    vector<int> vector7; // [1, 1, 2, 3, 4]
    vector7.push_back(1);
    for (int i = 0; i < 4; ++i)
    	vector7.push_back(i+1);

    vector<int> vector8; // [1, 2, 3, 4, 1]
    for (int i = 0; i < 4; ++i)
    	vector8.push_back(i+1);
    vector8.push_back(1);


    vector<int> vector9; //vector of 50 elements contains values 0-48
    for (int i = 0; i < 50; ++i)
    	vector9.push_back(rand()%49);

    vector<int> vector10; //vector of 10000 elements with distinct elements
    for (int i = 10000; i > 0; --i)
    	vector10.push_back(i);

    //get time stamp before testing
    auto start = chrono::high_resolution_clock::now(); 

    //testing, exit program if "failed"
    if (result(1, containsDuplicate(vector1), false) == false)
    	exit(1);
    if (result(2, containsDuplicate(vector2), false)== false)
    	exit(1);
    if (result(3, containsDuplicate(vector3), false)== false)
    	exit(1);
    if (result(4, containsDuplicate(vector4), true)== false)
    	exit(1);
    if (result(5, containsDuplicate(vector5), false)== false)
    	exit(1);
    if (result(6, containsDuplicate(vector6), true)== false)
    	exit(1);
    if (result(7, containsDuplicate(vector7), true)== false)
    	exit(1);
    if (result(8, containsDuplicate(vector8), true)== false)
    	exit(1);
    if (result(9, containsDuplicate(vector9), true)== false)
    	exit(1);
    if (result(10, containsDuplicate(vector10), false)== false)
    	exit(1);

    //get time stamp after testing
    auto end = chrono::high_resolution_clock::now(); 
    
    //calculate and print time taken
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
    time_taken *= 1e-9; 
  
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
    

    //calculate total memory usage
    get_memory_usage_kb(&vmrss, &vmsize);
    printf("Current memory usage: VmRSS = %6ld KB, VmSize = %6ld KB\n", vmrss, vmsize);

    return 0;
 }

#include <algorithm>
#include <vector>

using namespace std;

bool containsDuplicate (vector<int>& nums){
	//Type your answer here:
	
	for(int i = 0; i < nums.size(); i ++)
	{
		for(int j = 0; j < nums.size(); j++)
		{
			if(nums[i] == nums[j] && i != j)
				return true;
		}
	}

	return false;
}

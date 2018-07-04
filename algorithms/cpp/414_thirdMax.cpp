#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int thirdMax(vector<int>& nums)
{
	long long firstmax, secondmax, thirdmax;
	firstmax = secondmax = thirdmax = LLONG_MIN;
	for (int i = 0; i < nums.size(); ++i)
	{
		if(nums[i] == firstmax || nums[i] == secondmax || nums[i] == thirdmax)
			continue;
		if (nums[i] > firstmax)
		{
			thirdmax = secondmax;
			secondmax = firstmax;
			firstmax = nums[i];
		}
		else if(nums[i] > secondmax)
		{
			thirdmax = secondmax;
			secondmax = nums[i];
		}
		else if(nums[i] > thirdmax)
		{
			thirdmax = nums[i];
		}
	}
	if(thirdmax == LLONG_MIN)
		thirdmax = firstmax;
	return thirdmax;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	int result = thirdMax(nums);
	return 0;
}

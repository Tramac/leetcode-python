#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
	int Max = nums.size();
	int expectSum = Max * (Max + 1) / 2;
	int curSum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		curSum += nums[i];
	}
	return expectSum - curSum;
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
	int result = missingNumber(nums);
	return 0;
}

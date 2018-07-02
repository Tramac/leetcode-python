#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k)
{
	if(k >= nums.size())
		k = k % nums.size();
	reverse(nums.begin() + nums.size() - k, nums.begin() + nums.size());
	reverse(nums.begin(), nums.begin() + nums.size() - k);
	reverse(nums.begin(), nums.end());
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
	rotate(nums, 0);
	return 0;
}

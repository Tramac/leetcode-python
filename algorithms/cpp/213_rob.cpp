#include <iostream>
#include <vector>

using namespace std;

int robber(vector<int>& nums, int left, int right)
{
	int pre = 0, cur = 0;
	for (int i = left; i <= right; ++i)
	{
		int temp = max(pre + nums[i], cur);
		pre = cur;
		cur = temp;
	}
	return cur;
}

int rob(vector<int>& nums)
{
	int n = nums.size();
	if(n == 0)
		return 0;
	if(n == 1)
		return nums[0];
	return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
}

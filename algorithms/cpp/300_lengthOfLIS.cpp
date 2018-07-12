#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	int length = nums.size();
	if (length == 0)
		return 0;
	vector<int> dp(length, 1);
	int res = 1;
	for (int i = 1; i < length; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(nums[j] < nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	return res;
}

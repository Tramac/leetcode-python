#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	int target = sum >> 1;
	if(sum % 2 == 1)
		return false;
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for(auto num : nums) {
		for (int i = target; i >= num; --i) {
			dp[i] = dp[i] || dp[i - num];
		}
	}
	return dp[target];
}

int main()
{
	int n;
	cin >> n;
	int tmp;
	vector<int> nums;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		nums.push_back(tmp);
	}
	bool res = canPartition(nums);
	return 0;
}

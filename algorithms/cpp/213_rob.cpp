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

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int robCore(vector<int>& nums, int start, int end) {
    if (start > end)
        return 0;
    if (end == start) {
        return nums[start];
    }
    if ((end - start) == 1) {
        return max(nums[start], nums[end]);
    }
    vector<int> dp(end - start + 1, 0);
    dp[0] = nums[start], dp[1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; ++i) {
        dp[i - start] = max(dp[i - 2- start] + nums[i], dp[i - 1- start]);
    }
    return dp[end - start];
}

int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    return max(robCore(nums, 0, nums.size() - 2), robCore(nums, 1, nums.size() - 1));
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    int res = rob(nums);
    cout << res << endl;
    return 0;
}
*/

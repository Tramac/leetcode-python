#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> dp(nums.size());
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if ((nums[i] % nums[j] == 0) && dp[j].size() > dp[i].size()) {
                dp[i] = dp[j];
            }
        }
        dp[i].push_back(nums[i]);
        res = res.size() > dp[i].size() ? res : dp[i];
    }
    return res;
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
    vector<int> res = largestDivisibleSubset(nums);
    return 0;
}

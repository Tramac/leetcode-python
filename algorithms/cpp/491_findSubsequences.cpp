#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int> >& res, vector<int>& seq, vector<int>& nums, int start) {
	if (seq.size() > 1) res.push_back(seq);
	unordered_set<int> mp;
	for (int i = start; i < nums.size(); ++i) {
		if ((seq.size() == 0 || nums[i] >= seq.back()) && mp.find(nums[i]) == mp.end())
		{
			seq.push_back(nums[i]);
			dfs(res, seq, nums, i + 1);
			seq.pop_back();
			mp.insert(nums[i]);
		}
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
	vector<vector<int> > res;
	vector<int> seq;
	dfs(res, seq, nums, 0);
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	vector<vector<int> > res = findSubsequences(nums);
	return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	if(nums.size() == NULL)
		return false;
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); ++i)
	{
		unordered_map<int, int>::iterator iter = mp.find(nums[i]);
		if(iter != mp.end())
		{
			int pos = iter->second;
			if(pos - i <= k)
				return true;
		}
		mp[nums[i]] = i;
	}
	return false;
}

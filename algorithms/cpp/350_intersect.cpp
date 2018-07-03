#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int> mp;
	vector<int> result;
	for (int i = 0; i < nums1.size(); ++i)
	{
		mp[nums1[i]]++;
	}
	for (int i = 0; i < nums2.size(); ++i)
	{
		if(mp[nums2[i]] > 0)
		{
			result.push_back(nums2[i]);
			mp[nums2[i]]--;
		}
	}
	return result;
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> nums1, nums2;
	for (int i = 0; i < m; ++i)
	{
		int temp;
		cin >> temp;
		nums1.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		nums2.push_back(temp);
	}
	vector<int> r = intersect(nums1, nums2);
	return 0;
}

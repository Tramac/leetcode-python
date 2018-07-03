#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	set<int> s1(nums1.begin(), nums1.end());
	set<int> s2(nums2.begin(), nums2.end());
	vector<int> result;
	set<int>::iterator iter1 = s1.begin();
	while(iter1 != s1.end())
	{
		if(s2.find(*iter1) != s2.end())
			result.push_back(*iter1);
		iter1++;
	}
	return result;
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> nums1, nums2;a
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
	vector<int> r = intersection(nums1, nums2);
	return 0;
}

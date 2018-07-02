#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums)
{
	int majority = nums[0];
	int count = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		if(nums[i] == majority)
			count++;
		else
		{
			count--;
			if(count == 0)
			{
				majority = nums[i];
				count = 1;
			}
		}
	}
	return majority;
}

main()
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
	int result = majorityElement(nums);
	return 0;
}

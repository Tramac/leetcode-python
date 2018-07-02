#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> result;
	int start = 0;
	int end = numbers.size() - 1;
	while(start < end)
	{
		if((numbers[start] + numbers[end]) == target)
		{
			result.push_back(start + 1);
			result.push_back(end + 1);
			break;
		}
		else if((numbers[start] + numbers[end]) < target)
			start++;
		else
			end--;
	}
	return result;
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
	vector<int> result = twoSum(nums, 9);
	return 0;
}

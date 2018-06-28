#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> Map;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i)
    {
        //Map中没有找到nums[i]
        if(Map.find(nums[i]) == Map.end())
        {
            //位置i对应的是target-nums[i]
            Map[target - nums[i]] = i;
        }
        else
        {
            result.push_back(Map[nums[i]]);
            result.push_back(i);
            break;
        }
    }
    return result;
}

int main()
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

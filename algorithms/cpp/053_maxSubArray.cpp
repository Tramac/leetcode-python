#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int maxSum = 0x80000000;
    int curSum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(curSum < 0)
        {
            curSum = nums[i];
        } 
        else
        {
            curSum += nums[i];
        }
        maxSum = (maxSum > curSum) ? maxSum : curSum;
    }
    return maxSum;
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
    int maxSum = maxSubArray(nums);
    cout << maxSum << endl;
    return 0;
}

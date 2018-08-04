#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    if(nums.size() == 0 || k <= 0) return 0;
    int count = 0;
    int curProduct = 1;
    for (int i = 0, j = 0; j < nums.size(); ++j)
    {
        curProduct *= nums[j];
        while(i <= j && curProduct >= k)
        {
            curProduct /= nums[i++];
        }
        count += j - i + 1;
    }
    return count;
}

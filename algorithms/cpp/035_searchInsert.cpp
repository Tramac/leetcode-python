#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    if(nums.size() == 0)
        return -1;
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(nums[mid] == target)
            return mid;
        else
        {
            if(nums[mid] < target)
            {
                if(mid == end || nums[mid + 1] > target)
                    return mid + 1;
                else
                {
                    start = mid + 1;
                }
            }
            
            else
            {
                if(mid == start || nums[mid - 1] < target)
                    return mid;
                else
                {
                    end = mid - 1;
                }
            }
        } 
    }
    return -1;
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
    int index = searchInsert(nums, 1);
    cout << index << endl;
    return 0;
}

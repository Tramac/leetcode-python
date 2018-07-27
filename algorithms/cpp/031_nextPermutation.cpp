#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    if(nums.size() <= 1) return;
    vector<int> map(nums.size(), -1);
    for(int i = nums.size() - 1; i > 0; --i)
    {
        for(int j = i - 1; j >=0; --j)
        {
            if(nums[j] < nums[i])
            {
                map[i] = j;
                break;
            }
        }
    }
    int Max = -1, Maxindex = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(map[i] >= Max)
        {
            Max = map[i];
            Maxindex = i;
        }
    }
    if(Max != -1)
    {
        int tmp = nums[Max];
        nums[Max] = nums[Maxindex];
        nums[Maxindex] = tmp;
        sort(nums.begin() + Max + 1, nums.end());
    }
    else
        sort(nums.begin(), nums.end());
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    nextPermutation(nums);
    return 0;
}

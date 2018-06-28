#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    if(nums.size() > 0)
    {
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == val)
            {
                vector<int>::iterator start = nums.begin();
                nums.erase(start + i, start + i + 1);
                continue;
            }
            else
                i++;
        }
    }
    return nums.size();
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
    int result = removeElement(nums, 3);
    cout << result << endl;
    return 0;
}

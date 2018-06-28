#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    vector<int>::iterator current = nums.begin();
    while(((nums.end() - current) > 1) && nums.size() > 1)
    {
        vector<int>::iterator next = current + 1;
        bool needDelete = false;
        if(*current == *next)
            needDelete = true;
        if(!needDelete)
        {
            current = next;
            next = current + 1;
        }
        
        else
        {
            int value = *current;
            vector<int>::iterator end = next + 1;
            while(end < nums.end() && *end == value)
            {
                end++;
            }
            nums.erase(next, end);
            current = current + 1;
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
    int result = removeDuplicates(nums);
    cout << result << endl;
    return 0;
}

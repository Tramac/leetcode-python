#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMin(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    if (nums[start] < nums[end]) 
        return nums[start];
    while (end - start > 1) {
        int mid = (start + end) / 2;
        if (nums[start] < nums[mid]) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    return nums[end];
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> nums;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        nums.push_back(temp);
    }
    int res = findMin(nums);
    return 0;
}

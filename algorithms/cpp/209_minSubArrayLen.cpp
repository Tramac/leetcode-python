#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums){
    if(nums.size() == 0) return 0;
    int start = 0, end = 0;
    int curSum = nums[start];
    int minLen = 0;
    while(end < nums.size()){
        if(curSum < s){
            end++;
            if(end < nums.size()){
                curSum += nums[end];
            }
            else break;
        }
        else{
            if(minLen == 0) minLen = end - start + 1;
            else{
                minLen = min(minLen, end - start + 1);
            }
            if(start == end && end < nums.size() - 1){
                end++;
            } 
            curSum -= nums[start];
            start++;
        }
    }
    return minLen;
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
    int res = minSubArrayLen(7, nums);
    return 0;
}

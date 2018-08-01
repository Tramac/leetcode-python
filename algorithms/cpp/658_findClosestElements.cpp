#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    vector<int> res;
    if(x <= arr[0])
    {
        for(int i = 0; i < k; ++i)
        {
            res.push_back(arr[i]);
        }
    }
    else if(x >= arr[arr.size() - 1])
    {
        for(int i = arr.size() - k; i < arr.size(); ++i)
        {
            res.push_back(arr[i]);
        }
    }
    else
    {
        int less = 0, greater = arr.size() - 1;
        int mid;
        while(less < greater - 1)
        {
            mid = (less + greater) / 2;
            if(arr[mid] == x)
            {
                less = mid;
                greater = mid;
                break;
            }
            else if(arr[mid] < x) less = mid;
            else greater = mid;
        }
        if(less == greater)
        {
            res.push_back(x);
            less--;
            greater++;
            k--;
        }
        while(less >= 0 && greater < arr.size() && k > 0)
        {
            if(abs(x - arr[less]) <= abs(arr[greater] - x))
            {
                res.insert(res.begin(), arr[less]);
                less--;
                k--;
            }
            else
            {
                res.push_back(arr[greater]);
                greater++;
                k--;
            }
        }
        if(k > 0)
        {
            if(less < 0)
            {
                for(int i = 0; i < k; ++i)
                {
                    res.push_back(arr[greater]);
                    greater++;
                }
            }
            else
            {
                for(int i = 0; i < k; ++i)
                {
                    res.insert(res.begin(), arr[less]);
                    less--;
                }
            }
        }
    }
    return res;
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
    vector<int> res = findClosestElements(nums, 4, -1);
    return 0;
}

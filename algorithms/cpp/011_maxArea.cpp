#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height)
{
    if(height.size() <= 1) return 0;
    int start = 0, end = height.size() - 1;
    int max_area = 0;
    while(start < end)
    {
        int h = min(height[start], height[end]);
        max_area = max(max_area, (end - start) * h);
        while(height[start] <= h) start++;
        while(height[end] <= h) end--;
    }
    return max_area;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        height.push_back(tmp);
    }
    int res = maxArea(height);
    return res;
}


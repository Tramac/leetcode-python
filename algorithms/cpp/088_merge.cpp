#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while(j >= 0)
        nums1[k--] = nums2[j--];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> nums1;
    for (int i = 0; i < m; ++i)
    {
        int temp;
        cin >> temp;
        nums1.push_back(temp);
    }
    vector<int> nums2;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        nums2.push_back(temp);
        nums1.push_back(0);
    }
    merge(nums1, m, nums2, n);

    return 0;
}

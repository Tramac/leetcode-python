#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    if (arr.size() == 0) return 0;
    int curMax = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        curMax = max(curMax, arr[i]);
        if (curMax == i) res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int res = maxChunksToSorted(arr);
    return 0;
}

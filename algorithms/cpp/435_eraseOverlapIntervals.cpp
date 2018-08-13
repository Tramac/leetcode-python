#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool compare(Interval& a, Interval& b) {
    return a.start < b.start;
}

int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    int res = 0, pre = 0;
    for(int i = 1; i < intervals.size(); ++i) {
        if(intervals[i].start < intervals[pre].end) {
            res++;
            if (intervals[i].end < intervals[pre].end) {
                pre = i;
            }
        }
        else 
            pre = i;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<Interval> intervals;
    Interval tmp;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp.start >> tmp.end;
        intervals.push_back(tmp);
    }
    int res = eraseOverlapIntervals(intervals);
    return 0;
}

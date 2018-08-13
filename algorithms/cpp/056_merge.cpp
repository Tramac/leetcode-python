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

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if (intervals.size() == 0) 
        return res;
    sort(intervals.begin(), intervals.end(), compare);
    
    int pre = 0;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start <= intervals[pre].end && intervals[i].end > intervals[pre].end) {
            intervals[pre].end = intervals[i].end;
        }
        else if (intervals[i].start > intervals[pre].end) {
            res.push_back(intervals[pre]);
            pre = i;
        }
    }
    res.push_back(intervals[pre]);
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
    vector<Interval> res = merge(intervals);
    return 0;
}

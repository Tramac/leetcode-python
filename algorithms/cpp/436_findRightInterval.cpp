#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int binarySearch(vector<int>& starts,int target) {
	int start = 0, end = starts.size() - 1;
	while (start < end) {
		int mid = (start + end) / 2;
		if (starts[mid] == target) {
			end = mid;
			break;
		}
		else if (starts[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return starts[end];
}

vector<int> findRightInterval(vector<Interval>& intervals) {
	vector<int> res;
	map<int, int> mp;
	vector<int> starts;
	for (int i = 0; i < intervals.size(); ++i) {
		mp[intervals[i].start] = i;
		starts.push_back(intervals[i].start);
	}
	sort(starts.begin(), starts.end());
	for (int i = 0; i < intervals.size(); ++i) {
		int target = intervals[i].end;
		int start = binarySearch(starts, target);
		if (start < target)
			res.push_back(-1);
		else
			res.push_back(mp[start]);
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<Interval> intervals;
	Interval tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp.start >> tmp.end;
		intervals.push_back(tmp);
	}
	vector<int> res = findRightInterval(intervals);
	return 0;
}

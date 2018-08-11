#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(pair<int, int>& a, pair<int, int>& b){
    return a.second == b.second ? a.first > b.first : a.second < b.second;
}

int findMinArrowShots(vector<pair<int, int> >& points){
    if (points.size() == 0) return 0;
    sort(points.begin(), points.end(), compare);
    int arrowPos = points[0].second;
    int res = 1;
    for(int i = 1; i < points.size(); ++i)
    {
        if(arrowPos >= points[i].first) continue;
        arrowPos = points[i].second;
        res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > points;
    pair<int, int> tmp;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp.first >> tmp.second;
        points.push_back(tmp);
    }
    int res = findMinArrowShots(points);
    return 0;
}

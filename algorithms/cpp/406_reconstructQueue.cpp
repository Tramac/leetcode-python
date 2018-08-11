#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.first == b.first ? a.second < b.second : a.first > b.first;
}

vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
	sort(people.begin(), people.end(), compare);
	vector<pair<int, int> > res;
	for (int i = 0; i < people.size(); ++i) {
		res.insert(res.begin() + people[i].second, people[i]);
	}
	return res;
}

int main()
{
	int n = 0;
	cin >> n;
	pair<int, int> tmp;
	vector<pair<int, int> > people;
	for (int i = 0; i < n; ++i) {
		cin >> tmp.first >> tmp.second;
		people.push_back(tmp);
	}
	vector<pair<int, int> > res = reconstructQueue(people);
	return 0;
}

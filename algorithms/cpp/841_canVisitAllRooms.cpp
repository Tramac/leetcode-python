#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> >& rooms, unordered_set<int>& visited, unordered_set<int>& keys, int cur) {
	visited.insert(cur);
	for (auto key : rooms[cur]) {
		keys.insert(key);
	}
	for (auto key : keys) {
		if (visited.find(key) == visited.end()) {
			dfs(rooms, visited, keys, key);
		}
	}
}

bool canVisitAllRooms(vector<vector<int> >& rooms) {
	unordered_set<int> visited;
	unordered_set<int> keys;
	dfs(rooms, visited, keys, 0);
	return visited.size() == rooms.size();
}

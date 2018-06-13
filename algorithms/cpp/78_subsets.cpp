#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > subsets(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int> > result(1, vector<int>());
	for(int i = 0; i < nums.size(); ++i)
	{
		int n = result.size();
		for(int j = 0; j < n; ++j)
		{
			result.push_back(result[j]);
			result.back().push_back(nums[i]);
		}
	}
	return result;
}

void printResult(vector<vector<int> >& result)
{
    for(int i=0; i<result.size(); i++){
        cout << "{";
        for(int j=0; j<result[i].size(); j++){
            cout << " " << result[i][j];
        }
        cout << " }" <<endl;
    }
}

int main()
{
	int n;
	cin >> n;
	vector<int> sets;
	for(int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		sets.push_back(temp);
	}
	vector<vector<int> > result = subsets(sets);
	printResult(result);
	return 0;
}

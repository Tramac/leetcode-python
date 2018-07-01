#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > results;
	if(numRows <= 0)
		return results;
	vector<int> current;
	current.push_back(1);
	if(numRows == 1)
	{
		results.push_back(current);
		return results;
	}
	vector<int> next;
	results.push_back(current);
	for (int i = 1; i < numRows; ++i)
	{
		next.push_back(1);
		for (int j = 0; j < current.size() - 1; ++j)
		{
			next.push_back(current[j] + current[j + 1]);
		}
		next.push_back(1);

		results.push_back(next);

		current = next;
		next.clear();
	}
	return results;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > results = generate(n);
	return 0;
}

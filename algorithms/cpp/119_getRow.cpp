#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
	vector<int> current;
	current.push_back(1);
	if(rowIndex == 0)
	{
		return current;
	}
	vector<int> next;
	for (int i = 1; i <= rowIndex; ++i)
	{
		next.push_back(1);
		for (int j = 0; j < current.size() - 1; ++j)
		{
			next.push_back(current[j] + current[j + 1]);
		}
		next.push_back(1);

		current = next;
		next.clear();
	}
	return current;
}

int main()
{
	int n;
	cin >> n;
    vector<int> results = getRow(n);
	return 0;
}

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int minPathSum(vector<vector<int> >& grid)
{
	if(grid.size() == 0)
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	int dp[m][n];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i)
	{
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	for (int i = 1; i < n; ++i)
	{
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = min(dp[i][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
		}
	}
	return dp[m - 1][n - 1];
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int> > grid;
	grid.resize(m);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp;
			cin >> temp;
			grid[i].push_back(temp);
		}
	}
	int result = minPathSum(grid);
	return 0;
}

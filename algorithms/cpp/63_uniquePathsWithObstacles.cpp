#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
{
	if(obstacleGrid.size() == 0)
		return 0;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int dp[m][n];
	memset(dp, 0, sizeof(dp));
	if(obstacleGrid[0][0] == 1)
		dp[0][0] = 0;
	else
		dp[0][0] = 1;
	for (int i = 0; i < m; ++i)
	{
		if(obstacleGrid[i][0] == 1)
			dp[i][0] = 0;
		else
			dp[i][0] = dp[i - 1][0];
	}
	for (int i = 0; i < n; ++i)
	{
		if(obstacleGrid[0][i] == 1)
			dp[0][i] = 0;
		else
			dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if(obstacleGrid[i][j] == 1)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
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
	int result = uniquePathsWithObstacles(grid);
	return 0;
}

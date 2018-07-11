#include <iostream>
#include <vector>

using namespace std;

// Bottom-up DP
int minimumTotal(vector<vector<int> >& triangle)
{
	int rows = triangle.size();
	if (rows == 0)
		return 0;
	vector<int> dp(triangle.back());
	for (int row = rows - 2; row >= 0; row--)
	{
		for (int i = 0; i <= row; ++i)
		{
			dp[i] = min(triangle[row][i] + dp[i], triangle[row][i] + dp[i + 1]);
		}
	}
	return dp[0];
}

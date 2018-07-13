#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
	int Max = amount + 1;
	vector<int> dp(amount + 1, Max);
	dp[0] = 0;
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j < coins.size(); ++j)
		{
			if(coins[j] <= i)
			{
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
	int n;
	cin >> n;
	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		coins.push_back(temp);
	}
	int result = coinChange(coins, 11);
	return 0;
}

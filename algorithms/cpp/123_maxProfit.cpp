#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices)
{
    // f[k][i] represents the max profit up until prices[i] (Note: NOT ending with prices[i]) using at most k transactions.
    // f[k][i] = max(f[k][i-1], prices[i] - prices[j] + f[k-1][j]) { j in range of [0, i-1] }
    // f[0][i] = 0; 0 times transation makes 0 profit
    // f[k][0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
    if(prices.size() <= 1) return 0;
    int trans = 2;
    int maxProf = 0;
    vector<vector<int> > dp(trans + 1, vector<int>(prices.size(), 0));
    for(int k = 1; k <= trans; ++k)
    {
        int tmpMax = dp[k - 1][0] - prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            dp[k][i] = max(dp[k][i - 1], prices[i] + tmpMax);
            tmpMax = max(tmpMax, dp[k - 1][i] - prices[i]);
            maxProf = max(maxProf, dp[k][i]);
        }
    }
    return maxProf;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        prices.push_back(tmp);
    }
    int res = maxProfit(prices);
    return 0;
}

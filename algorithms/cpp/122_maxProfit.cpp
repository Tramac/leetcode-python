#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
	if(prices.size() == 0)
		return 0;
	int sumPro = 0;
	for (int i = 0; i < prices.size() - 1; ++i)
	{
		if((prices[i+1] - prices[i]) > 0)
			sumPro += (prices[i + 1] - prices[i]);
	}
	return sumPro;
}

int main()
{
	int n;
	cin >> n;
	vector<int> prices;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		prices.push_back(temp);
	}
	int result = maxProfit(prices);
	cout << result << endl;
	return 0;
}

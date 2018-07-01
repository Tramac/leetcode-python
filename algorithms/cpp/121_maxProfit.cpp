#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
	if(prices.size() == 0)
		return 0;
	int maxPro = 0x80000000;
	int minPrice = 0x7FFFFFFF;
	for (int i = 0; i < prices.size(); ++i)
	{
		minPrice = min(minPrice, prices[i]);
		maxPro = max(maxPro, prices[i] - minPrice);
	}
	return maxPro;
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

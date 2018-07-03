#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
	if(nums.size() == 0)
		return;
	int zero = 0;
	int nozero = zero + 1;
	while (nozero < nums.size())
	{
		while(zero < nums.size() && nums[zero] != 0)
			zero++;
		nozero = zero + 1;
		while(nozero < nums.size() && nums[nozero] == 0)
			nozero++;
		if(nozero < nums.size())
		{
			int temp;
			nums[zero] = nums[nozero];
			nums[nozero] = temp;
			zero++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	moveZeroes(nums);
	return 0;
}

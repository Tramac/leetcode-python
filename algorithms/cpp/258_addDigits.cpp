#include <iostream>

using namespace std;

int addDigits(int num)
{
	while(num >= 10)
	{
		int newNum = 0;
		while(num > 0)
		{
			newNum += num % 10;
			num /= 10;
		}
		num = newNum;
	}
	return num;
}

int main()
{
	int n;
	cin >> n;
	int result = addDigits(n);
	return 0;
}

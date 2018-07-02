#include <iostream>

using namespace std;

bool isHappy(int n)
{
	int i = 50;
	while (i)
	{
		int newNumber = 0;
		while(n / 10 != 0)
		{
			newNumber += (n % 10) * (n % 10);
			n /= 10;
		}
		newNumber += n * n;
		n = newNumber;
		if(n == 1)
			return true;
		i--;
	}
	return false;
}

int main()
{
	bool result = isHappy(2);
	return 0;
}

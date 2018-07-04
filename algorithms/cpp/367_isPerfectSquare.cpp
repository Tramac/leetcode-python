#include <iostream>

using namespace std;

bool isPerfectSquare(int num)
{
	for (double i = 1; i * i <= (double)num; ++i)
	{
		if(i * i == (double)num)
			return true;
	}
	return false;
}

int main()
{
	bool result = isPerfectSquare(2147395600);
	return 0;
}

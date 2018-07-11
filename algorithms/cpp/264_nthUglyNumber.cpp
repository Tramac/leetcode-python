#include <iostream>

using namespace std;

int Min(int num1, int num2, int num3)
{
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;
	return min;
}

int nthUglyNumber(int n)
{
	if(n <= 0)
		return 0;
	int *pUglyNumbers = new int[n];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while(nextUglyIndex < n)
	{
		pUglyNumbers[nextUglyIndex] = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			pMultiply2++;
		while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			pMultiply3++;
		while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			pMultiply5++;
		nextUglyIndex++;
	}
	int ugly = pUglyNumbers[n - 1];
	delete[] pUglyNumbers;
	return ugly;
}

int main()
{
	int result = nthUglyNumber(10);
	return 0;
}

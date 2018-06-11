#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int maxProduct(int* data, int length)
{
	int maxProd = data[0];
	int maxCur = data[0], minCur = data[0];
	for (int i = 1; i < length; ++i)
	{
		if (data[i] < 0)
			Swap(&maxCur, &minCur);

		maxCur = max(maxCur * data[i], data[i]);
		minCur = min(minCur * data[i], data[i]);

		maxProd = max(maxProd, maxCur);
	}
	return maxProd;
}

#define TEST(a) cout << maxProduct(a, sizeof(a)/sizeof(int)) << endl
int main()
{
	int o[] = { 2, 3, -2, 4 };
	TEST(o);

	int a[] = { -4, -3 };
	TEST(a);

	int b[] = { -1, -1 };
	TEST(b);
	
	int c[] = { -1, 0, -2 };
	TEST(c);

	int d[] = { 2, 3, -2, 4, 5 };
	TEST(d);
}

#include <stdint.h>
#include <iostream>

using namespace std;

int hammingWeight(uint32_t n)
{
	int count = 0;
	while(n)
	{
		count++;
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	uint32_t n = 11;
	int result = hammingWeight(n);
	cout << result << endl;
	return 0;
}

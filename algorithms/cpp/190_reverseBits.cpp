#include <stdint.h>
#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
	uint32_t result = 0;
	for (int i = 0; i < 32; ++i)
	{
		int bit = n & 1;
		n = n >> 1;
		result = result * 2 + bit;
	}
	return result;
}

int main()
{
	uint32_t n = 43261596;
	uint32_t result = reverseBits(n);
	cout << result << endl;
	return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

int reachNumber(int target)
{
	double sum = abs(target);
	double k = sqrt(2 * sum + 0.25) - 0.5;
	if(k == int(k))
		return k;
	int n = int(k) + 1;
	int currentSum = n * (n + 1) / 2;
	int diff = currentSum - sum;
	if(diff % 2 == 0)
		return n;
	while(true)
	{
		n++;
		currentSum += n;
		if((currentSum - int(sum)) % 2 == 0)
		{
			return n;
		}
	}
}

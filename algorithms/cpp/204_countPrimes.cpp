#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int countPrimes(int n) 
{
    if (n<=2) 
        return 0;
    vector<bool> prime(n, false);
    int sum = 1;
    int upper = sqrt(n);
    for (int i=3; i<n; i+=2) 
    {
        if (!prime[i]) 
        {
            sum++;
            if (i>upper) 
                continue;
            for (int j=i*i; j<n; j+=2*i) 
                prime[j] = true;							
        }
    }
    return sum;
}

int main()
{
	int result = countPrimes(10);
	return 0;
}

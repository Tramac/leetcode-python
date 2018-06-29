#include <iostream>
#include <algorithm>

using namespace std;

int climbStairs(int n)
{
    if(n <= 2)
        return n;
    long long fibOne = 1;
    long long fibTwo = 2;
    long long fibN;
    for (int i = 3; i <= n; ++i)
    {
        fibN = fibOne + fibTwo;
        fibTwo = fibN;
        fibOne = fibTwo;
    }
    return fibN;
}

int main()
{
    int result = climbStairs(3);
    return 0;
}

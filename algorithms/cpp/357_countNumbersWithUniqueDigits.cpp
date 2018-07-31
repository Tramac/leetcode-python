#include <iostream>
#include <vector>

using namespace std;

int countNumbersWithUniqueDigits(int n)
{
    int res = 1;
    for(int i = 1; i <= n; ++i)
    {
        int curNum = 9;
        for(int j = 1; j < i; ++j)
        {
            curNum *= (10 - j);
        }
        res += curNum;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int res = countNumbersWithUniqueDigits(n);
    return 0;
}

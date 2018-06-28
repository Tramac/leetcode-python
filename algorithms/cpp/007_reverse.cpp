#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int reverse(int x)
{
    if(x == 0)
        return 0;
    int flag = 0;
    if(x < 0)
    {
        flag = 1;
        x = -x;
    }
    while(x % 10 == 0)
        x /= 10;
    int result = 0;
    while(x)
    {
        if(result > INT_MAX / 10 || result < INT_MIN / 10)
            return 0;
        result = result * 10 + x % 10;
        x /= 10;
    }
    if(flag == 1)
        result = -result;
    return result;
}

int main()
{
    int result = reverse(120);
    cout << result << endl;
    return 0;
}

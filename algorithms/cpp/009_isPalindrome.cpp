#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    if(x == 0)
        return true;
    if(x % 10 == 0)
        return false;
    int temp = x;
    int reverse = 0;
    while(temp)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    if(x == reverse)
        return true;
    return false;
}

int main()
{
    bool result = isPalindrome(121);
    cout << result << endl;
    return 0;
}

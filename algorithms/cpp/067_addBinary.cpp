#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    if(a == "0")
        return b;
    if(b == "0")
        return a;
    string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 && j >= 0)
    {
        int sum = (a[i] - '0') + (b[j] - '0') + carry;
        carry = 0;
        if(sum >= 2)
        {
            sum -= 2;
            carry = 1;
        }
        result += to_string(sum);
        i--;
        j--;
    }
    while(i >= 0)
    {
        int sum = (a[i] - '0') + carry;
        carry = 0;
        if(sum >= 2)
        {
            sum -= 2;
            carry = 1;
        }
        result += to_string(sum);
        i--;
    }
    while(j >= 0)
    {
        int sum = (b[j] - '0') + carry;
        carry = 0;
        if(sum >= 2)
        {
            sum -= 2;
            carry = 1;
        }
        result += to_string(sum);
        j--;
    }
    if(carry)
        result += "1";
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string a = "11";
    string b = "1";
    string sum = addBinary(a, b);
    cout << sum << endl;
    return 0;
}

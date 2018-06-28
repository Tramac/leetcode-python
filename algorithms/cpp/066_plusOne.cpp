#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int carry = 0, sum = 0;
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        if(i == digits.size() - 1)
            sum = digits[i] + 1 + carry;
        else
            sum = digits[i] + carry;
        if(sum >= 10)
        {
            carry = 1;
            digits[i] = sum - 10;
        }
        else
        {
            digits[i] = sum;
            break;
        }
    }
    if(digits[0] == 0)
    {
        digits.push_back(0);
        for (int i = digits.size() - 1; i > 0; --i)
            digits[i] = digits[i - 1];
        digits[0] = 1;
    }
    return digits;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> result = plusOne(nums);
    return 0;
}

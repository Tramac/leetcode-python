#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string removeKdigits(string num, int k) {
    if (k == 0)
        return num;
    if (k >= num.size())
        return "0";
    string num1 = "";
    string num2 = num;
    while(k > 0) {
        if (num1.size() == 0 || num1[num1.size() - 1] <= num2[0])  {
            num1 += num2[0];
            num2.erase(0, 1);
        }
        else {
            num1.erase(num1.size() - 1, 1);
            k--;
        }
    }
    num1 += num2;
    while (num1.size() > 0 && num1[0] == '0') {
        num1.erase(0, 1);
    }
    if (num1.size() == 0)
        return "0";
    return num1;
}

int main() {
    string s;
    cin >> s;
    string res = removeKdigits(s, 1);
    return 0;
}

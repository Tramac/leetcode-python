#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string longestPalindrome(string s)
{
    if(s.size() == 0)
        return "";
    int start = 0, end = 0;
    int maxLen = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if(i + maxLen / 2 >= s.size())
            break;
        int j = i, k = i;
        while (k < s.size() - 1 && s[k + 1] == s[k])
            k++;
        while(j >= 0 && k < s.size() && s[j] == s[k])
        {
            j--;
            k++;
        }
        if(k - j - 1 > maxLen)
        {
            maxLen = k - j - 1;
            start = j + 1;
            end = k - 1;
        }
    }
    return s.substr(start, maxLen);
}

int main()
{
    string s;
    cin >> s;
    string res = longestPalindrome(s);
    return 0;
}

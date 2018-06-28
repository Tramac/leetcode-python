#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while(start < end)
    {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
    int i = 0;
    while(s[i] == ' ')
        ++i;
    int count = 0, j = i;
    while(j < s.size() && s[j] != ' ')
    {
        ++j;
        ++count;
    }
    return count;
}

int main()
{
    string s = "Hello world";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}

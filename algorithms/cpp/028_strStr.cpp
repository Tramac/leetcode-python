#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
    if(needle.size() == 0)
        return 0;
    if(haystack.size() == 0 || haystack.size() < needle.size())
        return -1;
    for (int i = 0; i <= (haystack.size() - needle.size()); ++i)
    {
        bool isPresent = true;
        for (int j = 0; j < needle.size(); ++j)
        {
            if(needle[j] != haystack[i + j])
            {
                isPresent = false;
                break;
            }
        }
        if(isPresent)
            return i;
    }
    return -1;
}

int main()
{
    string haystack = "mississippi";
    string needle = "issip";
    int result = strStr(haystack, needle);
    cout << result << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 0)
        return "";
    string first = strs[0];
    string preFix;
    for (int i = 0; i < first.size(); ++i)
    {
        char curChar = first[i];
        bool isSame = true;
        for (int j = 1; j < strs.size(); ++j)
        {
            if(strs[j][i] != curChar)
            {
                isSame = false;
                break;
            }
        }
        if(isSame)
            preFix += curChar;
        else
            break;
    }
    return preFix;
}

int main()
{
    int n;
    cin >> n;
    string temp;
    getline(cin, temp);
    vector<string> strs;
    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        strs.push_back(str);
    }
    string prefix = longestCommonPrefix(strs);
    cout << prefix << endl;
    return 0;
}

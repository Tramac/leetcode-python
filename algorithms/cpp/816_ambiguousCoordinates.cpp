#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> pointNum(string s)
{
    vector<string> res;
    if(s.size() == 1)
    {
        res.push_bac#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> pointNum(string s)
{
    vector<string> res;
    if(s.size() == 1)
    {
        res.push_back(s);
    }
    else if(s[0] == '0')
    {
        if(s[s.size() - 1] != '0')
        {
            s.insert(1, ".");
            res.push_back(s);
        }
    }
    else
    {
        if(s[s.size() - 1] == '0')
        {
            res.push_back(s);
        }
        else
        {
            for(int i = 1; i < s.size(); ++i)
            {
                string tmp = s;
                tmp.insert(i, ".");
                res.push_back(tmp);
            }
            res.push_back(s);
        }
    }
    return res;
}

vector<string> ambiguousCoordinates(string S)
{
    vector<string> res;
    for(int i = 2; i < S.size() - 1; ++i)
    {
        string first(S.begin() + 1, S.begin() + i);
        string second(S.begin() + i, S.end() - 1);
        for(auto str1 : pointNum(first))
        {
            for(auto str2 : pointNum(second))
            {
                res.push_back("(" + str1 + "," + str2 + ")");
            }
        }
        
    }
    return res;
}

int main()
{
    string S;
    cin >>S;
    // vector<int> prices;
    // for(int i = 0; i < n; ++i)
    // {
    //     int tmp;
    //     cin >> tmp;
    //     prices.push_back(tmp);
    // }
    vector<string> res = ambiguousCoordinates(S);
    return 0;
}
k(s);
    }
    else if(s[0] == '0')
    {
        if(s[s.size() - 1] != '0')
        {
            s.insert(1, ".");
            res.push_back(s);
        }
    }
    else
    {
        if(s[s.size() - 1] == '0')
        {
            res.push_back(s);
        }
        else
        {
            for(int i = 1; i < s.size(); ++i)
            {
                string tmp = s;
                tmp.insert(i, ".");
                res.push_back(tmp);
            }
            res.push_back(s);
        }
    }
    return res;
}

vector<string> ambiguousCoordinates(string S)
{
    vector<string> res;
    for(int i = 2; i < S.size() - 1; ++i)
    {
        string first(S.begin() + 1, S.begin() + i);
        string second(S.begin() + i, S.end() - 1);
        for(auto str1 : pointNum(first))
        {
            for(auto str2 : pointNum(second))
            {
                res.push_back("(" + str1 + "," + str2 + ")");
            }
        }
        
    }
    return res;
}

int main()
{
    string S;
    cin >>S;
    vector<string> res = ambiguousCoordinates(S);
    return 0;
}

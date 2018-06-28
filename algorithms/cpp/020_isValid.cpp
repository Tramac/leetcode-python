#include <iostream>
#include <string>

using namespace std;

bool isValid(string s)
{
    if(s.size() == 0)
        return true;
    while(s.size() > 0)
    {
        if(s[0] == ')' || s[0] == ']' || s[0] == '}' || s[s.size() - 1] == '(' || s[s.size() - 1] == '[' || s[s.size() - 1] == '{')
            return false;
        char latest_right = s[0];
        int index = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                latest_right = s[i];
                index = i;
            }
        }
        int j = index + 1;
        for (; j < s.size(); ++j)
        {
            if(s[j] == ')' || s[j] == ']' || s[j] == '}')
                break;
        }
        if((latest_right == '(' && s[j] == ')') || (latest_right == '[' && s[j] == ']') || (latest_right == '{' && s[j] == '}'))
        {
                s.erase(index, 1);
                s.erase(--j, 1);
                continue;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    string str = "()[]{}";
    bool result = isValid(str);
    cout << result << endl;
    return 0;
}

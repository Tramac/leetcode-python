#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkValidStringCore(string& s, int numRight, int start) {
    if (start >= s.size()) {
        if (numRight == 0) return true;
        else return false;
    }
    if (numRight < 0) return false;
    if (s[start] == '(') {
        return checkValidStringCore(s, numRight + 1, start+1);
    }
    else if (s[start] == ')') {
        return checkValidStringCore(s, numRight - 1, start+1);
    }
    else {
        return checkValidStringCore(s, numRight + 1, start+1) || checkValidStringCore(s, numRight-1, start+1) || checkValidStringCore(s, numRight, start+1);
    }
}

bool checkValidString(string s) {
    bool res = checkValidStringCore(s, 0, 0);
    return res;
}

int main()
{
    string s = "(*)";
    bool res = checkValidString(s);
    return 0;
}

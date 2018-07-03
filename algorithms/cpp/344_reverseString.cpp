#include <iostream>
#include <string>

using namespace std;

string reverseString(string s)
{
	if(s.size() <= 1)
		return s;
	int start = 0;
	int end = s.size() - 1;
	while(start < end)
	{
		char ch = s[start];
		s[start] = s[end];
		s[end] = ch;

		start++;
		end--;
	}
	return s;
}

int main()
{
	string str = "hello";
	string result = reverseString(str);
	return 0;
}

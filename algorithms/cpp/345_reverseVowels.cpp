#include <iostream>
#include <string>

using namespace std;

string reverseVowels(string s)
{
	if(s.size() <= 1)
		return s;
	int start = 0;
	int end = s.size() - 1;
	while(start < end)
	{
		while(start < end && s[start] != 'a' && s[start] != 'e' && s[start] != 'i' && s[start] != 'o' && s[start] != 'u'
		&& s[start] != 'A' && s[start] != 'E' && s[start] != 'I' && s[start] != 'O' && s[start] != 'U')
			start++;
		while(end > start && s[end] != 'a' && s[end] != 'e' && s[end] != 'i' && s[end] != 'o' && s[end] != 'u'
		&& s[end] != 'A' && s[end] != 'E' && s[end] != 'I' && s[end] != 'O' && s[end] != 'U')
			end--;
		if(start < end)
		{
			char ch = s[start];
		    s[start] = s[end];
		    s[end] = ch;
			start++;
		    end--;
		}
	}
	return s;
}

int main()
{
	string str = "leetcode";
	string result = reverseVowels(str);
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
	if(s.size() == 0)
		return 0;
	const int TableSize = 52;
	int str[TableSize] = {0};
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		    str[s[i] - 'a']++;
		else
		    str[s[i] - 'A' + 26]++;
	}
	int length = 0;
	int singlecount = 0;
	for (int i = 0; i < TableSize; ++i)
	{
		if(str[i] % 2 == 1)
		{
			str[i]--;
			singlecount++;
		}
		if(str[i] > 0 && str[i] % 2 == 0)
			length += str[i];
	}
	if(singlecount > 0)
		length++;
	return length;
}

int main()
{
	int result = longestPalindrome("abccccdd");
	return 0;
}

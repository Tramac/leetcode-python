#include <iostream>
#include <string>

using namespace std;

char findTheDifference(string s, string t)
{
	const int TableSize = 26;
	int str1[TableSize] = {0};
	int str2[TableSize] = {0};
	for (int i = 0; i < s.size(); ++i)
	{
		str1[s[i] - 'a']++;
		str2[t[i] - 'a']++;
	}
	str2[t[t.size() - 1] - 'a']++;
	for (int i = 0; i < t.size(); ++i)
	{
		if(str1[t[i] - 'a'] != str2[t[i] - 'a'])
			return t[i];
	}
}

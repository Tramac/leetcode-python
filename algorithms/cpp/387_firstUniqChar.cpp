#include <iostream>
#include <string>

using namespace std;

int firstUniqChar(string s)
{
	if(s.size() == 0)
		return -1;
	const int TableSize = 26;
	int word[TableSize] = {0};
	for (int i = 0; i < s.size(); ++i)
	{
		word[s[i] - 'a']++;
	}
	char single = 'A';
	for (int i = 0; i < s.size(); ++i)
	{
		if(word[s[i] - 'a'] == 1)
		{
			single = s[i];
			break;
		}
	}
	if(single != 'A')
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == single)
				return i;
		}
	}
	return -1;
}

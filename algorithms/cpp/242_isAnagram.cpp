#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
	const int TableSize = 26;
	if(s.size() != t.size())
		return false;
	int hashmap1[TableSize] = {0};
	int hashmap2[TableSize] = {0};
	for (int i = 0; i < s.size(); ++i)
	{
		hashmap1[s[i] - 'a']++;
		hashmap2[t[i] - 'a']++;
	}
	for (int i = 0; i < TableSize; ++i)
	{
		if(hashmap1[i] != hashmap2[i])
			return false;
	}
	return true;
}

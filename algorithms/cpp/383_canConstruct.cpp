#include <iostream>
#include <string>
#include <tr1/unordered_map>

using namespace std::tr1;
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
	if(ransomNote.size() == 0)
		return true;
	unordered_map<char, int> mp;
	for (int i = 0; i < magazine.size(); ++i)
	{
		mp[magazine[i]]++;
	}
	for (int i = 0; i < ransomNote.size(); ++i)
	{
		if(mp[ransomNote[i]] <= 0)
			return false;
		else
			mp[ransomNote[i]]--;
	}
	return true;
}

int main()
{
	bool result = canConstruct("aa", "ab");
	return 0;
}

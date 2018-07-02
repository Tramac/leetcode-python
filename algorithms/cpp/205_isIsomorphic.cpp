#include <iostream>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t)
{
	const int tableSize = 256;
	unsigned int hashTable1[tableSize] = {0};
	unsigned int hashTable2[tableSize] = {0};
	int length = s.size();
	for (int i = 0; i < length; ++i)
	{
		if(hashTable1[s[i]] != hashTable2[t[i]])
			return false;
		hashTable1[s[i]] = i + 1;
		hashTable2[t[i]] = i + 1;
	}
	return true;
}

int main()
{
	string s = "egg";
	string t = "add";
	bool result = isIsomorphic(s, t);
	return 0;
}

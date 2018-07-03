#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>

using namespace std::tr1;
using namespace std;

vector<string> split(string str)
{
	vector<string> results;
	string s;
	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i] != ' ')
			s.push_back(str[i]);
		else
		{
			results.push_back(s);
			s.clear();
		}
	}
	if(!s.empty())
	    results.push_back(s);
	return results;
}

bool wordPattern(string pattern, string str)
{
	unordered_map<char, int> pm;
	unordered_map<string, int> sm;
	vector<string> vs = split(str);
	int i=0, j = 0;
	for (int k = 0; k < pattern.size(); ++k)
	{
		if(pm.find(pattern[k]) == pm.end())
			pm[pattern[k]] = i++;
	}

	for (int k = 0; k < vs.size(); ++k)
	{
		if(sm.find(vs[k]) == sm.end())
			sm[vs[k]] = j++;
	}
	string pp, sp;
	for (int k = 0; k < pattern.size(); ++k)
	{
		pp.push_back(pm.find(pattern[k])->second + '0');
	}
	for (int k = 0; k < vs.size(); ++k)
	{
		sp.push_back(sm.find(vs[k])->second + '0');
	}

	return pp == sp;
}

int main()
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	bool result = wordPattern(pattern, str);
	return 0;
}

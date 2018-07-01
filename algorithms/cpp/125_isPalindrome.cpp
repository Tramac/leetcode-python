#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
	if(s == "")
		return true;
	string::iterator start = s.begin();
	string::iterator end = s.end();
	while(start < end)
	{
		if((*start >= 'a' && *start <= 'z') || (*start >= 'A' && *start <= 'Z') || (*start >= '0' && *start <= '9'))
		{
			if(*start >= 'A' && *start <= 'Z')
			{
				*start += 32;
			}
			start++;
		}
		else
		{
			s.erase(start);
			end = s.end();
		}
	}
	start = s.begin();
	end = s.end() - 1;
	while(start < end)
	{
		if(*start != *end)
			return false;
		else
		{
			start++;
			end--;
		}
	}
	return true;
}

int main()
{
	string s = "0P";
	bool result = isPalindrome(s);
	return 0;
}

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countSegments(string s)
{
	int count = 0;
	istringstream newstr(s);
	while(newstr >> s)
		count++;
	return count;
}

int main()
{
	string s = "Hello, my name is John";
	int result = countSegments(s);
	return 0;
}

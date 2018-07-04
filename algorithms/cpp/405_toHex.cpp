#include <iostream>
#include <string>

using namespace std;

string toHex(int num)
{
	if(num == 0)
		return "0";
	string hexs = "0123456789abcdef";
	string result;
	int count = 0;
	while (num && count++ < 8)
	{
		result = hexs[num & 0xf] + result;
		num >>= 4;
	}
	return result;
}

int main()
{
	string result = toHex(26);
	return 0;
}

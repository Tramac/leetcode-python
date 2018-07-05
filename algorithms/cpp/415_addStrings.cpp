#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2)
{
	if(num1.size() == 0)
		return num2;
	if(num2.size() == 0)
		return num1;
	int end1 = num1.size() - 1;
	int end2 = num2.size() - 1;
	int carry = 0;
	string result;
	while (end1 >= 0 && end2 >= 0)
	{
		int curSum = (num1[end1] - '0') + (num2[end2] - '0') + carry;
		if(curSum >= 10)
		{
			carry = 1;
			curSum -= 10;
		}
		else
			carry = 0;
		result = to_string(curSum) + result;
		end1--;
		end2--;
	}
	while(end1 >= 0)
	{
		int curSum = (num1[end1] - '0') + carry;
		if(curSum >= 10)
		{
			carry = 1;
			curSum -= 10;
		}
		else
			carry = 0;
		result = to_string(curSum) + result;
		end1--;
	}
	while(end2 >= 0)
	{
		int curSum = (num2[end2] - '0') + carry;
		if(curSum >= 10)
		{
			carry = 1;
			curSum -= 10;
		}
		else
			carry = 0;
		result = to_string(curSum) + result;
		end2--;
	}
	if(carry)
		result = "1" + result;
	return result;
}

int main()
{
	string num1 = "111";
	string num2 = "2222";
	string result = addStrings(num1, num2);
	return 0;
}

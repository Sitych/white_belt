#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string str)
{
	size_t	len;

	len = str.size();
	for (size_t i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			return (false);
	}
	return (true);
}

int main()
{
	string s = "asd";
	cout << s[0];
}
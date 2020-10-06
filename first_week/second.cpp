#include <iostream>

using namespace std;

int	main()
{
	string	str1;
	string	str2;
	string	str3;

	cin >> str1 >> str2 >> str3;
	if (str1 < str2)
	{
		if (str1 < str3)
			cout << str1;
		else
			cout << str3;
	}
	else
	{
		if (str2 < str3)
			cout << str2;
		else
			cout << str3;
	}
	return (0);
}
#include <iostream>
#include <string>

using namespace std;

int	main()
{
	string	str;
	int		flag;

	cin >> str;
	flag = -2;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (flag == -1 && str[i] == 'f')
		{
			cout << i;
			return (0);
		}
		if (str[i] == 'f')
			flag = -1;
	}
	cout << flag;
	return (0);
}
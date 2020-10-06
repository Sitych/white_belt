#include <iostream>

using namespace std;

//g++ -Wall -Wextra -Werror .\main.cpp

int	main()
{
	int	a;
	int	b;

	cin >> a >> b;
	if (b == 0)
	{
		cout << "Impossible";
		return (0);
	}
	cout << a / b;
	return (0);
}
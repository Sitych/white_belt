#include <iostream>

using namespace std;

int	main()
{
	unsigned long long int	a;
	unsigned long long int	b;

	cin >> a >> b;
	while (a > 0 && b > 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	cout << (a + b);
	return (0);
}
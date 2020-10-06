#include <iostream>

using namespace std;

int	main()
{
	float	n;
	float	a;
	float	b;
	float	x;
	float	y;

	cin >> n >> a >> b >> x >> y;
	if (a < b)
	{
		if (n > b)
			cout << n * (100 - y) / 100;
		else if (n > a)
			cout << n * (100 - x) / 100;
		else
			cout << n;
	}
	return (0);
}
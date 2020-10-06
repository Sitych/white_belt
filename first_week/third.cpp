#include <iostream>
#include <cmath>

using namespace std;

int	main()
{
	double	a;
	double	b;
	double	c;
	double	d;

	cin >> a >> b >> c;
	d = pow(float(b), 2) - 4 * a * c;
	if (d > 0 && a != 0)
		cout << ((-1) * b + sqrt(d)) / (2 * a) << " " << ((-1) * b - sqrt(d)) / (2 * a);
	else if (d == 0 && a != 0)
		cout << ((-1) * b + sqrt(d)) / (2 * a);
	else if (a == 0 && b != 0)
		cout << -c / b;
	return (0);
}
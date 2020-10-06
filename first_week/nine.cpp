#include <iostream>

using namespace std;

int	main()
{
	int	x;
	int	i;

	cin >> x;
	if (x < 0)
	{
		cout << 1;
		x *= (-1);
		i = 0;
	}
	else
		for(i = 0; (x & 0x80000000) != 0x80000000 && i < 31; i++)
			x <<= 1;
	for (i = sizeof(int) * 8 - i; i > 0; i--)
	{
		cout << ((x & 0x80000000) >> 31);
		x <<= 1;
	}
	return (0);
}
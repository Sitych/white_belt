#include <iostream>

using namespace std;

int	main()
{
	int	start;
	int	end;

	cin >> start >> end;
	if (start <= end && start >= 1 && end <= 30000)
	{
		for (int i = start; i <= end; i++)
		{
			if (i % 2 == 0)
				cout << i << ' ';
		}
	}
	return (0);
}
#include <iostream>
#include <vector>

using namespace std;

int	main()
{
	vector<int>	temperatre;
	int			n;
	int			sum;
	int			col;

	cin >> n;
	sum = 0;
	col = 0;
	temperatre.resize(n);
	for (int i = 0; i < n; i++)
		cin >> temperatre[i];
	for (int i: temperatre)
		sum += i;
	sum /= n;
	for (int i = 0; i < n; i++)
		if (temperatre[i] > sum)
			col++;
	cout << col << endl;
	for (int i = 0; i < n; i++)
		if (temperatre[i] > sum)
			cout << i << " ";
	return (0);
}
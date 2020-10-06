#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int	main()
{
	map<vector<string>, int>	route;
	vector<string>				stop;
	int							i;
	int							q;
	int							n;

	cin >> q;
	i = 1;
	while (q-- > 0)
	{
		cin >> n;
		stop.resize(n);
		for (auto &c: stop)
			cin >> c;
		if (route.find(stop) != route.end())
		{
			cout << "Already exists for " << route[stop] << endl;
			stop.clear();
		}
		else
		{
			route[stop] = i;
			cout << "New bus " << i << endl;
			i++;
		}
	}
	return (0);
}
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int	main()
{
	map<set<string>, int>	route;
	set<string>				stop;
	string					s;
	int						i;
	int						q;
	int						n;

	cin >> q;
	i = 1;
	while (q-- > 0)
	{
		cin >> n;
		while (n-- > 0)
		{
			cin >> s;
			stop.insert(s);
		}
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
		stop.clear();
	}
	return (0);
}
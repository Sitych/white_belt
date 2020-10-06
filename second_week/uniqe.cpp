#include <set>
#include <iostream>

using namespace std;

int	main()
{
	set<string>	uniqe;
	string		s;
	int			q;

	cin >> q;
	while (q-- > 0)
	{
		cin >> s;
		uniqe.insert(s);
	}
	cout << uniqe.size();
	return (0);
}
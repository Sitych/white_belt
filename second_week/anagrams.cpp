#include <iostream>
#include <map>

using namespace std;

int	main()
{
	int				n;
	int				flag;
	string			word;
	map<char, int>	first;
	map<char, int>	second;

	cin >> n;
	while (n-- > 0)
	{
		flag = 1;
		cin >> word;
		for (char c: word)
			++first[c];
		word.clear();
		cin >> word;
		for (char c: word)
			++second[c];
		for (const auto &item: first)
			if (second[item.first] != item.second)
				flag = 0;
		if (first.size() == second.size() && flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		first.clear();
		second.clear();
	}
	return (0);
}
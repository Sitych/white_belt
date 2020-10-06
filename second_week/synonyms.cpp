#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int	main()
{
	map<string, set<string>>	synonyms;
	string						s1;
	string						s2;
	int							q;

	cin >> q;
	while (q-- > 0)
	{
		cin >> s1;
		if (s1 == "ADD")
		{
			cin >> s1;
			cin >> s2;
			synonyms[s1].insert(s2);
			synonyms[s2].insert(s1);
		}
		else if (s1 == "COUNT")
		{
			cin >> s1;
			if (synonyms.find(s1) != synonyms.end())
				cout << synonyms[s1].size() << endl;
			else
				cout << 0 << endl;
		}
		else if (s1 == "CHECK")
		{
			cin >> s1;
			cin >> s2;
			if (synonyms[s1].count(s2) == 1 || synonyms[s2].count(s1) == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return (0);
}
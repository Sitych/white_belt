#include <iostream>
#include <map>

using namespace std;

void	ft_print(string str)
{
	cout << str << endl;
}

int	main()
{
	int					q;
	string				s1;
	string				s2;
	string				buf;
	string				command;
	map<string, string>	lst;

	cin >> q;
	while (q-- > 0)
	{
		cin >> command;
		if (command == "CHANGE_CAPITAL")
		{
			cin >> s1 >> s2;
			if (lst.find(s1) != lst.end())
			{
				if (lst[s1] == s2)
					ft_print("Country " + s1 + " hasn't changed its capital");
				else
					ft_print("Country " + s1 + " has changed its capital " + \
					"from " + lst[s1] + " to " + s2);
			}
			else if (s1.size() != 0 && s2.size() != 0)
				ft_print("Introduce new country " + s1 + " with capital " + s2);
			if (s1.size() != 0 && s2.size() != 0)
				lst[s1] = s2;
		}
		else if (command == "RENAME")
		{
			cin >> s1 >> s2;
			if ((lst.find(s1) == lst.end() && s1.size() != 0) || \
						lst.find(s1)->first == s2 || lst.find(s2) != lst.end())
				ft_print("Incorrect rename, skip");
			else if (s1.size() != 0 && s2.size() != 0)
			{
				ft_print("Country " + s1 + " with capital " + lst[s1] +  \
												" has been renamed to " + s2);
				buf = lst[s1];
				lst.erase(s1);
				lst[s2] = buf;
			}
		}
		else if (command == "ABOUT")
		{
			cin >> s1;
			if (lst.find(s1)->first != s1)
				ft_print("Country " + s1 + " doesn\'t exist");
			else if (s1.size() != 0 && lst.find(s1) != lst.end())
				ft_print("Country " + s1 + " has capital " + lst[s1]);
		}
		else if (command == "DUMP")
		{
			if (lst.size() == 0)
				ft_print("There are no countries in the world");
			else
			{
				for (auto i = lst.begin(); i != lst.end(); ++i)
					cout << i->first + "/" + i->second + " ";
				cout << endl;
			}
		}
	}
	return (0);
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int	main()
{
	map<string, vector<string>>	bus;
	map<string, vector<string>>	stop;
	string						s;
	int							bus_col;
	int							q;

	cin >> q;
	while (q-- > 0)
	{
		cin >> s;
		if (s == "NEW_BUS")
		{
			cin >> s >> bus_col;
			bus[s].resize(bus_col);
			for (auto &c: bus[s])
			{
				cin >> c;
				stop[c].push_back(s);
			}
		}
		else if (s == "BUSES_FOR_STOP")
		{
			cin >> s;
			if (s.size() != 0 && stop.find(s) == stop.end())
				cout << "No stop";
			else if (s.size() != 0)
				for (const auto &c: stop[s])
					cout << c << " ";
			cout << endl;
		}
		else if (s == "STOPS_FOR_BUS")		
		{
			cin >> s;
			if (s.size() != 0 && bus.find(s) == bus.end())
				cout << "No bus" << endl;
			else if (s.size() != 0)
			{
				for (const auto &c: bus[s])
				{
					cout << "Stop " + c + ": ";
					if (stop[c].size() == 1)
						cout << "no interchange";
					else
						for (size_t i = 0; i < stop[c].size(); i++)
						{
							if (stop[c][i] != s)
								cout << stop[c][i] << " ";
						}
					cout << endl;
				}
			}
		}
		else if (s == "ALL_BUSES")
		{
			if (bus.size() == 0)
				cout << "No buses" << endl;
			else
			{
				for (auto c = bus.begin(); c != bus.end(); ++c)
				{
					cout << "Bus " + c->first + ": ";
					for(const auto &i: c->second)
						cout << i + " ";
					cout << endl;
				}
			}
		}
	}
	return (0);
}
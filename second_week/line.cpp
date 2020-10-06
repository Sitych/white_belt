#include <iostream>
#include <vector>
#include <string>

using namespace std;

int	main()
{
	vector<int>	line;
	string		str;
	string		command;
	int			n;
	int			num;
	int			col;

	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		getline(cin, str);
		for (size_t k = 0; k < str.size() && str[k] != ' '; k++)
			command += str[k];
		if (command == "WORRY_COUNT")
		{
			col = 0;
			for (int k: line)
				if (k == 1)
					col++;
			cout << col << endl;
		}
		else if (str.size() && command.size())
		{
			num = stoi(str.substr(command.size()));
			if (command == "COME" && num >= 0)
				line.resize(line.size() + num, 0);
			else if (command == "COME" && num < 0)
				line.resize(line.size() + num);
			else if (command == "QUIET")
				line[num] = 0;
			else if (command == "WORRY")
				line[num] = 1;
		}
		str.clear();
		command.clear();
	}
	return (0);
}
#include <iostream>
#include <vector>

using namespace std;

void	ft_creat(vector<vector<string>> &list)
{
	vector<int>	monthes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	list.resize(12);
	for (int i = 0; i < 12; i++)
		list[i].resize(monthes[i]);
}

vector<string>	ft_strsplit(string str)
{
	vector<string>	result;
	string			word;

	for (size_t k = 0; k < str.size();)
	{
		for (size_t i = k; str[i] != ' ' && i < str.size(); i++)
			word += str[i];
		result.push_back(word);
		k = k + word.size() + 1;
		word.clear();
	}
	return (result);
}

int				ft_countworld(const string &str)
{
	int	count;

	count = 0;
	for (size_t i = 0; i < str.size(); i++)
		if (str[i] == ' ')
			count++;
	return (count);
}

void			ft_copy(const vector<string> &prev, vector<string> &next)
{
	size_t	j;

	for (j = 0; j < prev.size() && j < next.size(); j++)
		next[j] = prev[j];
	if (j < prev.size())
		for (;j < prev.size(); j++)
			next[next.size() - 1] += prev[j];
}

void			ft_del(vector<string> &month)
{
	for (size_t i = 0; i < month.size(); i++)
		month[i].clear();
}

int	main()
{
	int						q;
	int						i;
	int						month;
	string					str;
	vector<string>			command;
	vector<vector<string>>	list;

	ft_creat(list);
	cin >> q;
	month = 0;
	while (q-- >= 0)
	{
		getline(cin, str);
		if (!str.size())
			continue ;
		command = ft_strsplit(str);
		if (command[0] == "NEXT")
		{
			ft_copy(list[month], list[(month + 1) < 12 ? month + 1 : 0]);
			ft_del(list[month]);
			month = (month + 1) < 12 ? month + 1 : 0; 
		}
		else if (command.size() > 1)
		{
			i = stoi(command[1]) - 1;
			if (command[0] == "ADD")
			{
				if (list[month][i].size() == 0)
					list[month][i] = command[2];
				else
					list[month][i] += command[2];
				list[month][i] += " ";
			}
			else if (command[0] == "DUMP")
			{
				if (list[month][i].size() == 0)
					cout << 0 << endl;
				else
					cout << ft_countworld(list[month][i]) << " " \
												<< list[month][i] << endl;				
			}
		}
		str.clear();
		command.clear();
	}
	return (0);
}
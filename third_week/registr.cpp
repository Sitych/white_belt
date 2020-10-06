#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void	ft_print(const vector<string> &v)
{
	for (const auto &i: v)
		cout << i << " ";
	cout << endl;
}

int	main()
{
	vector<string>	mas;
	int				n;

	cin >> n;
	mas.resize(n);
	for(auto &i: mas)
		cin >> i;
	sort(mas.begin(), mas.end(), [](const auto &s1, const auto &s2)
	{
		string	str1;
		string	str2;

		str1 = s1;
		str2 = s2;
		for_each(str1.begin(), str1.end(), [](char &c)
		{
			c = tolower(c);
		});
		for_each(str2.begin(), str2.end(), [](char &c)
		{
			c = tolower(c);
		});
		if (str1 < str2)
			return (true);
		else
			return (false);
	});
	ft_print(mas);
	return (0);
}
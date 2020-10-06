#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void	ft_print(const vector<int> &v)
{
	for (const auto &i: v)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int>	mas;
	int			n;

	cin >> n;
	mas.resize(n);
	for (auto &i: mas)
		cin >> i;
	sort(mas.begin(), mas.end(), [](const auto &a, const auto &b)
	{
		if (abs(a) > abs(b))
			return (false);
		else
			return (true);
	});
	ft_print(mas);
	return (0);
}
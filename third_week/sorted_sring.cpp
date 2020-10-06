#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class	SortedStrings
{
	public:
		void			AddString(const string &s)
		{
			strs.push_back(s);
			sort(strs.begin(), strs.end(), [](const auto &s1, const auto &s2)
			{
				if (s1 > s2)
					return (false);
				else
					return (true);
			});
		}
		vector<string>	GetSortedStrings()
		{
			return (strs);
		}
	private:
		vector<string>	strs;
};

void	PrintSortedStrings(SortedStrings &strings)
{
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

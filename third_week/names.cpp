#include <iostream>
#include <map>
#include <vector>

using namespace std;

string	ft_outputstr(const string &s1, const string &s2)
{
	if (s1.size() == 0)
		return (s2 + " with unknown first name");
	else if (s2.size() == 0)
		return (s1 + " with unknown last name");
	return (s1 + " " + s2);
}

class	Person
{
	public:
		void	ChangeFirstName(int year, const string &first_name)
		{
			SetFULLNAME(year);
			change[year].first = first_name;
		}
		void	ChangeLastName(int year, const string &last_name)
		{
			SetFULLNAME(year);
			change[year].last = last_name;
		}
		string	GetFullName(int year)
		{
			s_name	buf;

			buf.first = change.begin()->second.first;
			buf.last = change.begin()->second.last;
			if (change.begin()->first <= year)
			{
				for (auto iter = change.begin(); iter != change.end(); ++iter)
				{
					if (iter->first == year)
					{
						buf.first = (change[year].first.size() == 0) ? buf.first : change[year].first;
						buf.last = (change[year].last.size() == 0) ? buf.last : change[year].last;
						return (ft_outputstr(buf.first, buf.last));
					}
					if (iter->first > year)
						return (ft_outputstr(buf.first, buf.last));
					if (iter->second.first.size() != 0)
						buf.first = iter->second.first;
					if (iter->second.last.size() != 0)
						buf.last = iter->second.last;
				}
				return (ft_outputstr(buf.first, buf.last));
			}
			return ("Incognito");
		}
	private:
		struct				s_name
		{
			string	first;
			string	last;
		};
		map<int, s_name>	change;
		void	SetFULLNAME(int	year)
		{
			if (change.find(year) == change.end())
			{
				change[year].first = "";
				change[year].last = "";
			}
		}
};

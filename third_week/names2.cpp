#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year)
{
	string name;  // изначально имя неизвестно

	// перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name = item.second;
		} else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}
	return name;
}

vector<string>	FindNamesByYear(const map<int, string>& names, int year)
{
	vector<string> name;  // изначально имя неизвестно

	// перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name.insert(name.begin(), item.second);
		} else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}
	return name;
}

string			ft_outputstr(const int year, const map<int, string> &m)
{
	vector<string>	name;
	string			result;
	size_t			i;
	size_t			len;

	name = FindNamesByYear(m, year);
	len = name.size(); 
	if (len == 0)
		return ("");
	i = 0;
	result += name[i++];
	while (i < len && name[i - 1] == name[i])
		++i;
	if (len > 1 && i < len)
	{
		result +=  " (";
		for (;i < len; ++i)
			if (name[i - 1] != name[i])
			{
				result += name[i];
				if (i + 1 != len)
					result += ", ";
			}
		result += ")";
	}
	return (result);
}

class Person {
	public:
		Person(const string &first, const string &last, int year)
		{
			first_names[year] = first;
			last_names[year] = last;
		}
		void ChangeFirstName(int year, const string& first_name) {
			if (year > first_names.begin()->first)
				first_names[year] = first_name;
		}
		void ChangeLastName(int year, const string& last_name) {
			if (year > last_names.begin()->first)
				last_names[year] = last_name;
		}
		string GetFullName(int year) const {
			// получаем имя и фамилию по состоянию на год year
			const string first_name = FindNameByYear(first_names, year);
			const string last_name = FindNameByYear(last_names, year);

			// если и имя, и фамилия неизвестны
			if (first_name.empty() && last_name.empty()) {
				return "No person";

			// если неизвестно только имя
			} else if (first_name.empty()) {
				return last_name + " with unknown first name";
				
			// если неизвестна только фамилия
			} else if (last_name.empty()) {
				return first_name + " with unknown last name";
				
			// если известны и имя, и фамилия
			} else {
				return first_name + " " + last_name;
			}
		}
		string	GetFullNameWithHistory(int year) const
		{
			string	first_name;
			string	last_name;
			string	result;

			first_name = ft_outputstr(year, first_names);
			last_name = ft_outputstr(year, last_names);
			if (first_name.empty() && last_name.empty()) {
				return "No person";

			// если неизвестно только имя
			} else if (first_name.empty()) {
				return last_name + " with unknown first name";
				
			// если неизвестна только фамилия
			} else if (last_name.empty()) {
				return first_name + " with unknown last name";
				
			// если известны и имя, и фамилия
			} else {
				return first_name + " " + last_name;
			}
			return (result);
		}

	private:
		map<int, string> first_names;
		map<int, string> last_names;
};

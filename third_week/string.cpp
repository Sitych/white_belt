#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class	ReversibleString
{
	public:
		ReversibleString()
		{
			str = "";
		}
		ReversibleString(const string &s)
		{
			str = s;
		}
		void	Reverse()
		{
			reverse(str.begin(), str.end());
		}
		string	ToString() const
		{
			return (str);
		}

	private:
		string	str;
};

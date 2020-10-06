#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>
#include <set>
#include <map>
#define ABS(x) (x > 0 ? x : -1 * x)

using namespace std;

vector<string>	ft_strsplit(const string &line, const string &c){
	vector<string> split;

	for (int i = 0, j = 0; j != -1; ){
		j = line.find(c, i);
		split.push_back(line.substr(i, j - i));
		i = j + 1;
	}
	return (split);
}

vector<int>	ft_dividers(unsigned int num) {
	int 	i;
	vector<int>		res;

	while (num != 1) {
		i = num;
		if (i > 2) {
			for (unsigned int k = 2; k < i; ++k) {
				if (i % k == 0) {
					i = k;
					break ;
				}
			}
		}
		res.push_back((int)i);
		num /= i;
	}
	return (res);
}

class Rational
{
private:
	unsigned int	p;
	unsigned int	q;
	int				flag;
	void			Dividers() {
		vector<int> dividers;

		dividers = ft_dividers(p);
		for (const auto &elem: dividers) {
			if (q % elem == 0) {
				p /= elem;
				q /= elem;
			}
		}
	}
public:
	Rational() {
		p = 0;
		q = 1;
		flag = 1;
	}
	Rational(int numerator, int denominator) {
		if (numerator == 0 || denominator == 0) {
			p = 0;
			q = 1;
			flag = 1;
			return ;
		}
		if ((numerator > 0 && denominator > 0)
			|| (numerator < 0 && denominator < 0))
			flag = 1;
		else
			flag = -1;
		p = (unsigned int)ABS(numerator);
		q = (unsigned int)ABS(denominator);
		Dividers();
	}
	int		Numerator() const {
		return (flag * p);
	}
	int		Denominator() const {
		return (q);
	}
	void	Setp(int new_p) {
		p = new_p;
	}
	void	Setq(int new_q) {
		q = new_q;
	}
};

bool	operator==(const Rational &lhs, const Rational &rhs) {
	return (((float)lhs.Numerator() / (float)lhs.Denominator()) == ((float)rhs.Numerator() / (float)rhs.Denominator()));
}

Rational	operator+(const Rational &lhs, const Rational &rhs) {
	return {lhs.Numerator() * rhs.Denominator() + \
	rhs.Numerator() * lhs.Denominator(),rhs.Denominator() * lhs.Denominator()};	
}

Rational	operator-(const Rational &lhs, const Rational &rhs) {
	return {lhs.Numerator() * rhs.Denominator() - \
	rhs.Numerator() * lhs.Denominator(),rhs.Denominator() * lhs.Denominator()};	
}

Rational	operator*(const Rational &lhs, const Rational &rhs) {
	return {lhs.Numerator() * rhs.Numerator(),
										lhs.Denominator() * rhs.Denominator()};
}

Rational	operator/(const Rational &lhs, const Rational &rhs) {
	return {lhs.Numerator() * rhs.Denominator(),
										lhs.Denominator() * rhs.Numerator()};

}

ostream		&operator<<(ostream &stream, const Rational &num) {
	stream << num.Numerator() << "/" << num.Denominator();
	return (stream);
}

bool		operator<(const Rational &lhs, const Rational &rhs) {
	return (((float)lhs.Numerator() / (float)lhs.Denominator()) < \
						((float)rhs.Numerator() / (float)rhs.Denominator()));
}

istream		&operator>>(istream &stream, Rational &num) {
	string			input;
	string			str;
	vector<string>	split;

	str = "";
	if (stream.eof() || stream.tellg() == -1 || !stream) {
		stream >> input;
		return (stream);
	}
	while (str.find("/") == string::npos && !stream.eof()) {
		stream >> input;
		for (const auto &c: input) {
			if (isupper(c) || islower(c))
				return (stream);
		}
		str += input;
	}
	if (str.find("/") == string::npos)
		return (stream);
	if (str.find("/") == str.size() - 1) {
		stream >> input;
		for (const auto &c: input) {
			if (isupper(c) || islower(c))
				return (stream);
		}
		str += input;
	}
	split = ft_strsplit(str, "/");
	Rational	n1(atoi(split[0].c_str()), atoi(split[1].c_str()));
	num.Setp(n1.Numerator());
	num.Setq(n1.Denominator());
	return (stream);
}

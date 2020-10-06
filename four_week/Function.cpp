#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class	FunctionPart {
public:
	FunctionPart(char new_oper, double new_src){
		source = new_src;
		operation = new_oper;
	}
	double Apply(double value) const {
		if (operation == '-')
			return (value - source);
		else if (operation == '+')
			return (value + source);
		else if (operation == '*')
			return (value * source);
		else
			return (value / source);
	}
	void Invert(){
		if (operation == '-')
			operation = '+';
		else if (operation == '+')
			operation = '-';
		else if (operation == '*')
			operation = '/';
		else
			operation = '*';
	}
private:
	char	operation;
	double	source;
};

class	Function{
public:
	void	AddPart(char new_oper, double new_x){
		parts.push_back({new_oper, new_x});
	}
	double	Apply(double num) const {
		for (const FunctionPart &part: parts){
			num = part.Apply(num);
		}
		return (num);
	}
	void	Invert(){
		for (FunctionPart &part: parts){
			part.Invert();
		}
		reverse(parts.begin(), parts.end());
	}
private:
	vector<FunctionPart> parts;
};

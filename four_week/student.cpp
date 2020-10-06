#include <iostream>
#include <fstream>
#include <vector>

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

class	Student{
private:
	string	first_name;
	string	last_name;
	int		day;
	int		month;
	int		year;
public:
	Student(const string &line){
		vector<string> split;

		split = ft_strsplit(line, " ");
		first_name = split[0];
		last_name = split[1];
		day = atoi(split[2].c_str());
		month = atoi(split[3].c_str());
		year = atoi(split[4].c_str());
	}
	void	PrintName() const {
		cout << first_name << " " << last_name << endl;
	}
	void	PrintDate() const {
		cout << day << '.' << month << '.' << year << endl;
	}
};

int	main(){
	int				num;
	int				k;
	string			line;
	vector<Student>	students;

	cin >> num;
	getline(cin, line);
	while (num-- > 0){
		getline(cin, line);
		students.push_back({line});
	}
	cin >> num;
	while (num-- > 0){
		cin >> line >> k;
		if (line == "name" && k > 0 && k < (int)students.size() + 1){
			students[k - 1].PrintName();
		}
		else if (line == "date" && k > 0 && k < (int)students.size() + 1){
			students[k - 1].PrintDate();
		}
		else{
			cout << "bad request" << endl;
		}
	}
}
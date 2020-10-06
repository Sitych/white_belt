#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

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

int main(){
	int	N, M;
	string line;

	string inpath = "input.txt";
	ifstream input(inpath);
	if (input){
		getline(input, line, ' ');
		N = atoi(line.c_str());
		getline(input, line);
		M = atoi(line.c_str());
		M++;
		for (int i = 0; getline(input, line); ++i){
			int j = 0;
			for (const string &s : ft_strsplit(line, ",")){
				cout << fixed << setw(10);
				cout << s;
				if (j != M - 2){
					cout << ' ';
				}
				j++;
			}
			if (i != N - 1){
				cout << endl;
			}
		}
	}
}
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string inpath = "input.txt";
	string outpath = "output.txt";
	ofstream output(outpath);
	ifstream input(inpath);
	if (input){
		string line;
		while (getline(input, line)){
			output << line << endl;
		}
	}
}
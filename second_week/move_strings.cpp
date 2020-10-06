#include <vector>
#include <string>

using namespace std;

void	MoveStrings(vector<string> &source, vector<string> &destination)
{
	for(string str: source)
		destination.push_back(str);
	source.clear();
}

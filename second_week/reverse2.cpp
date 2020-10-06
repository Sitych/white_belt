#include <vector>

using namespace std;

vector<int> Reversed(const vector<int> &v)
{
	vector<int>	buf;

	for (int x: v)
		buf.insert(buf.begin(), x);
	return (buf);
}

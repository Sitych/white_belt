#include <vector>

using namespace std;

void	Reverse(vector<int> &v)
{
	vector<int>	buf;

	for (int x: v)
		buf.insert(buf.begin(), x);
	v = buf;
}

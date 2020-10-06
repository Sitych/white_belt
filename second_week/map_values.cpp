#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string>	BuildMapValuesSet(const map<int, string>& m)
{
	set<string>	result;

	for (auto iter = m.begin(); iter != m.end(); ++iter)
		result.insert(iter->second);
	return (result);
}
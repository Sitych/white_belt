#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string str)
{
	size_t	len;

	len = str.size();
	for (size_t i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			return (false);
	}
	return (true);
}

vector<string>	PalindromFilter(vector<string> words, int minLength)
{
	vector<string> result;

	for (string word: words)
	{
		if (IsPalindrom(word) && word.size() >= (size_t)minLength)
			result.push_back(word);
	}
	return (result);
}

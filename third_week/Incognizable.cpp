#include <iostream>
using namespace std;

class Incognizable
{
private:
	int	a;
	int	b;
public:
	Incognizable();
	Incognizable(int x1);
	Incognizable(int x1, int x2);
};

Incognizable::Incognizable()
{
	a = 0;
	b = 0;
}

Incognizable::Incognizable(int x1)
{
	a = x1;
	b = 0;
}

Incognizable::Incognizable(int x1, int x2)
{
	a = x1;
	b = x2;
}

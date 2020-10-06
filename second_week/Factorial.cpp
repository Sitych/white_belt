int	Factorial(int x)
{
	int	result;

	result = 1;
	if (x < 0)
		return (result);
	for (int i = 1; i <= x; i++)
		result *= i;
	return (result);
}
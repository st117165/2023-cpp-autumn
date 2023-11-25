#include<iostream>

void recursion(int n, int a, int b);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	recursion(n, 1, 3);

	return EXIT_SUCCESS;
}

void recursion(int n, int a, int b)
{
	if (n <= 0)
	{
		return;
	}
	int res = 6 - a - b;
	if (a + b == 4)
	{
		recursion(n, a, 2);
		recursion(n, 2, b);
	}
	else
	{
		recursion(n - 1, a, res);
		std::cout << n << " " << a << " " << b << std::endl;
		recursion(n - 1, res, b);
	}
}
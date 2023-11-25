#include<iostream>

void recursion(int n, int a, int b);

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;

	recursion(a, 1, 3);

	return EXIT_SUCCESS;
}

void recursion(int n, int a, int b)
{
	if (n <= 0)
	{
		return;
	}

	int c = 0;
	int res = 6 - a - b;

	if (n % 2 != 0)
	{
		int c = 6 - a - b;
		recursion(n - 1, a, c);
		std::cout << n << " " << a << " " << b << std::endl;
		recursion(n - 1, c, b);

	}

	else if (n % 2 == 0)
	{
		res = 3;
		c = 6 - a - res;
		recursion(n - 1, a, b);
		std::cout << n << " " << a << " " << res << std::endl;
	}
}
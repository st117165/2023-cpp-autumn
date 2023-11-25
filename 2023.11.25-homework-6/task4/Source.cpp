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
	if (n == 1)
	{
		std::cout << n << " " << a << " " << b << std::endl;
	}
	else
	{
		int res = 6 - a - b;
		recursion(n - 1, a, b);
		std::cout << n << " " << a << " " << res << std::endl;
		recursion(n - 1, b, a);
		std::cout << n << " " << res << " " << b << std::endl;
		recursion(n - 1, a, b);
	}
}
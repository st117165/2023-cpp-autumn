#include <iostream>

void hanoi(int n, int x, int y);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int a = 0;
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a;
		if (a > c)
		{
			hanoi(1, 1, 3);
		}
		else
		{
			hanoi(1, 1, 2);
		}
		c = a;
	}

	return EXIT_SUCCESS;
}

void hanoi(int n, int x, int y)
{
	if (n > 0)
	{
		int res = 6 - x - y;
		hanoi(n - 1, x, res);
		std::cout << 0 << " " << x << " " << y << std::endl;
		hanoi(n - 1, res, y);
		std::cout << n << " " << 6 - x - y << " " << 3 << std::endl;
	}
}
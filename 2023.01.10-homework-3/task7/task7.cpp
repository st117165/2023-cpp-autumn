#include <iostream>

int main(int argc, char* argv[])
{	int n = 0;
	int a = 1;
	int d = 0;
	std::cin >> n;
	while (a < n)
	{
		a *= 2;
		d += 1;
	}
	std::cout << d << std::endl;

	return 0;
}
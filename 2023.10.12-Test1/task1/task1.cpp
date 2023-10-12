#include<iostream>

int main(int argc, char* argv[])
{
	unsigned int n = 0;
	std::cin >> n;
	int sum = 0;

	while (n > 0)
	{
		sum += n & 1;
		n = (n >> 1);
	}
	std::cout << sum;

	return EXIT_SUCCESS;
}

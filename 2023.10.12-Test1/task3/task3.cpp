#include<iostream>

int main(int argc, char* argv[])
{
	int A = sizeof(unsigned short) * 8;
	unsigned short a = 0;
	std::cin >> a;
	unsigned short b = 0;
	std::cin >> b;
	int c = 0;
	bool u = 0;
	for (int i = 0; i < A; ++i)
	{
		bool x = ((a >> i) & 1);
		bool y = ((b >> i) & 1);
		bool z = x ^ y ^ u;
		u = (x & y) | (x & u) | (y & u);
		c |= ((int)z << i);
	}
	std::cout << c;

	return EXIT_SUCCESS;
}
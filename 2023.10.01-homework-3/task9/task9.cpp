#include<iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	int y = 0;
	std::cin >> x >> y;
	while (x != y)
	{
		if ((x % 2 == 2) && (x / 2 >= y))
		{
			x /= 2;
			std::cout << ":2" << std::endl;
		}
		else
		{
			x -= 1;
			std::cout << "-1" << std::endl;
		}
	}
	return 0;
}
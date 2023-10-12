#include<iostream>

int main(int argc, char* argv[])
{
	int BITS = sizeof(unsigned int) * 8;
	unsigned int n = 0;
	std::cin >> n;

	if (n == 0)
	{
		n = ~n;
	}
	else
	{
		int start = BITS - 1;
		int end = 0;
		while ((n >> start & 1) == 0)
		{
			start--;
		}
		while ((n >> end & 1) == 0)
		{
			end++;
		}
		start--;
		end++;
		unsigned int m = 0;
		m = ~m;
		m = (m >> (start - end + 1));
		m = ~m;
		m = (m >> (BITS - start - 1));
		n = n ^ m;
		m = 0;
		for (int i = end; i <= start; ++i)
		{
			m = m | (1 << i);
		}
		{
			std::cout << "0b ";
			for (int i = BITS - 1; i >= 0; --i)
			{
				std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
			}
			std::cout << std::endl;
		}
	}
	return EXIT_SUCCESS;
}

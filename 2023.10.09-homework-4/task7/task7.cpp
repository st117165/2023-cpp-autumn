#include<iostream>
#include<cstdlib>

void readarray(int, int*);
void printarray(int, int*);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	readarray(n, a);
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) < 0)
		{
			if (i != (n - 1))
			{
				while (*(a + i) < 0)
				{
					if (i == (n - 1))
					{
						*(a + i) = 0;
						--n;
						break;
					}
					for (int j = i; j < n - 1; ++j)
					{
						*(a + j) = *(a + j + 1);
					}
					--n;
				}
			}
			else
			{
				*(a + i) = 0;
				--n;
			}
		}
	}
	int* b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		*(b + i) = *(a + i);
	}
	printarray(n, b);
	free(b);
	free(a);


	return EXIT_SUCCESS;
}

void readarray(int n, int* a)
{
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
}

void printarray(int n, int* a)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;
}
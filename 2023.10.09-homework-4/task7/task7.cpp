#include<iostream>
#include<cstdlib>

int main()
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	int k = 0;
	for (int i = 0; i < n;++i)
	{
		if (*(a + i) > 0)
		{
			k++;
		}
	}
	int* b = (int*)malloc(sizeof(int) * k);
	k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			*(b + k) = *(a + i);
			++k;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < k; ++i)
	{
		std::cout << *(b + i) << " ";
	}
	free(a);

	return EXIT_SUCCESS;
}
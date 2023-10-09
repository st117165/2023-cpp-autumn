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

	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > max)
		{
			max = *(a + i);
		}
	}
	std::cout << max;
	free(a);

	return EXIT_SUCCESS;
}
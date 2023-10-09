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
	int min = *a;
	int maxi = 0;
	int mini = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(a + ((n - i) - 1)) > max)
		{
			max = *(a + ((n - i) - 1));
			maxi = i;
		}
		if (*(a + i) < min)
		{
			min = *(a + i);
			mini = i;
		}
	}
	*(a + mini) = max;
	*(a + (n - maxi - 1)) = min;
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);

	return EXIT_SUCCESS;
}
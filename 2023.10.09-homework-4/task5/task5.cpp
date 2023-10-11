#include<iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	int* b = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	for (int i = 0; i < n; ++i)
	{
		*(b + i) = *(a + (n - i - 1));
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(b + i) << " ";
	}
	free(a);

	return EXIT_SUCCESS;
}

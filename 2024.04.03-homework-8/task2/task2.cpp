#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* tonnels = (int*)malloc((n + 1) * sizeof(int));
	for (int i = 0; i <= n; i++)
	{
		tonnels[i] = 0;
	}
	int m = 0;
	std::cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a = 0;
		std::cin >> a;
		int b = 0;
		std::cin >> b;
		tonnels[a]++;
		tonnels[b]++;
	}
	for (int i = 1; i <= n; i++)
	{
		std::cout << tonnels[i] << " ";
	}

	free(tonnels);
	return 0;
}
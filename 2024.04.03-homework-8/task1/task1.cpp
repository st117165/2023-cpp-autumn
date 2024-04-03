#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int** graph = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		graph[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> graph[i][j];
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			sum += graph[i][j];
		}
	}
	std::cout << sum;


	for (int i = 0; i < n; i++)
	{
		free(graph[i]);
	}
	free(graph);

	return EXIT_SUCCESS;
}
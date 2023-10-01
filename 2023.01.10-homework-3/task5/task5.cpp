#include<iostream>

int main(int argc, char* argv[]){
	int n = 0;
	int c = 0;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int p = 0;
		for (int j = i; j > 0; j = j / 10)
		{
			p = j % 10 + p * 10;
		}
		if (p == i)
		{
			c += 1;
		}
	}
	std::cout << c << std::endl;

	return 0;
}
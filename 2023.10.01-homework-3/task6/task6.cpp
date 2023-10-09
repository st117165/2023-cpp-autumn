#include <iostream>

int main(int argc, char* argv[]){
	int n = 0;
	std::cin >> n;
	int f1 = 0;
	int f2 = 1;
	int a = 0;
	for (int i = 1; i < n; i++)
	{
		a = f2;
		f2 += f1;
		f1 = a;
	}
	if (n > 1)
	{
		std::cout << f2;
	}
	else if (n == 1)
	{
		std::cout << 1;
	}
	else
	{
		std::cout << 0;
	}
	return 0;
}
#include<iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int a = 1;
	int b = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		if (b < a) {
			std::cout << a << " ";
			b++;
		}
		else {
			a++;
			std::cout << a << " ";
			b = 1;
		}
	}
	return EXIT_SUCCESS;
}
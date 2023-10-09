#include<iostream>

int main(int argc, char* argv[]) {
	long int n = 0;
	int c = 0;
	std::cin >> n;
	for (long int i = 1; i <= n; i++) {
		if ((n % i) == 0) {
			c++;
		}
	}
	std::cout << c;
	return EXIT_SUCCESS;
}
#include<iostream>

int main(int argc, char* argv[]) {
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	if (n <= k) {
		std::cout << 2 * m;
	}
	else if ((n * 2 % k) == 0) {
		std::cout << m * (n * 2 / k);
	}
	else {
		std::cout << m * (1 + (n * 2 / k));
	}
	return EXIT_SUCCESS;
}
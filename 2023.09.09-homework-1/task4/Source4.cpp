#include<iostream>
int main() {
	int n = 0;
	std::cin >> n;
	std::cout << (n * 100) + (9 * 10) + (9 - n);
	return EXIT_SUCCESS;
}
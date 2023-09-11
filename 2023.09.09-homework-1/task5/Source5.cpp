#include <iostream>
int main() {
	int v, t;
	std::cin >> v >> t;
	std::cout << (109 + (v * t) % 109) % 109 + 1;
	return EXIT_SUCCESS;
}
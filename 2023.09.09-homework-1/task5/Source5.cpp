#include <iostream>
int main() {
	int v = 0;
	int t = 0;
	std::cin >> v;
	std::cin >> t;
	std::cout << (109 + (v * t) % 109) % 109 + 1;
	return EXIT_SUCCESS;
}
#include<iostream>
int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << (a * (a / b) + b * (b / a)) / (b / a + a / b);
	return EXIT_SUCCESS;
}
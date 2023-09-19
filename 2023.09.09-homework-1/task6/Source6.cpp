#include<iostream>
int main() {
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	std::cout << (a * (a / b) + b * (b / a)) / (b / a + a / b);
	return EXIT_SUCCESS;
}
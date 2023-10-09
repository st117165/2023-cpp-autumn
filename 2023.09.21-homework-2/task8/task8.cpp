#include<iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if ((a >= b) && (a >= c)) {
		if (b >= c) {
			std::cout << a << " " << b << " " << c;
		}
		else {
			std::cout << a << " " << c << " " << b;
		}
	}
	else if ((b >= a) && (b >= c)) {
		if (a >= c) {
			std::cout << b << " " << a << " " << c;
		}
		else {
			std::cout << b << " " << c << " " << a;
		}
	}
	else if (b >= a) {
		std::cout << c << " " << b << " " << a;
	}
	else {
		std::cout << c << " " << b << " " << a;
	}
	return EXIT_SUCCESS;
}
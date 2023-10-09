#include<iostream>
int main(int argc, char* argv[]) {
	int n = 0;
	std::cin >> n;
	if ((n % 100 <= 19) && (n % 100 >= 10)) {
		std::cout << n << " bochek";
	}
	else if (n % 10 == 1) {
		std::cout << n << " bochka";
	}
	else if ((n % 10 < 5) && (n % 10 != 0)) {
		std::cout << n << " bochki" << std::endl;
	}
	else {
		std::cout << n << " bochek" << std::endl;
	}
	return EXIT_SUCCESS;
}
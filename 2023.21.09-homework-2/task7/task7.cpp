#include<iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	std::cin >> a;
	while (a != 0) {
		if (a - 100 >= 0) {
			std::cout << "C";
			a -= 100;
		}
		if (a - 90 >= 0) {
			std::cout << "XC";
			a -= 90;
		}
		if (a - 50 >= 0) {
			std::cout << "L";
			a -= 50;
		}
		if (a - 40 >= 0) {
			std::cout << "XL";
			a -= 40;
		}
		if (a - 10 >= 0) {
			std::cout << "X";
			a -= 10;
		}
		if (a - 9 >= 0) {
			std::cout << "IX";
			a -= 9;
		}
		if (a - 5 >= 0) {
			std::cout << "V";
			a -= 5;
		}
		if (a - 4 >= 0) {
			std::cout << "IV";
			a -= 4;
		}
		if (a - 1 >= 0) {
			std::cout << "I";
			a -= 1;
		}
	}
	return EXIT_SUCCESS;
}
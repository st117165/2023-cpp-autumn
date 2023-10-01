#include <iostream>

int main(int argc, char* argv[]){
	int n = 0;
	bool y = 0;
	std::cin >> n;
	while (n > 0) {
		y = y || (n % 10);
		if (y) {
			std::cout << n % 10;
		}
		n = n / 10;
	}
	return 0;
}
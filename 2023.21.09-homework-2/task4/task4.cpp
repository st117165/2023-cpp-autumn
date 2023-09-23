#include<iostream>
int main(int argc, char* argv[]) {
	int n1 = 0;
	std::cin >> n1;
	int n60 = n1 / 60;
	n1 = n1 % 60;
	int n20 = n1 / 20;
	n1 = n1 % 20;
	int n10 = n1 / 10;
	n1 = n1 % 10;
	int n5 = n1 / 5;
	n1 = n1 % 5;
	if ((n1 * 15) >= 70) {
		n5 += 1;
		n1 = 0;
		if ((n5 * 70) + (n1 * 15) >= 125) {
			n10 += 1;
			n5 = 0;
			n1 = 0;
			if ((n10 * 125) + (n5 * 70) + (n1 * 15) >= 230) {
				n20 += 1;
				n10 = 0;
				n5 = 0;
				n1 = 0;
				if ((n20 * 230) + (n10 * 125) + (n5 * 70) + (n1 * 15) >= 440) {
					n60 += 1;
					n20 = 0;
					n10 = 0;
					n5 = 0;
					n1 = 0;
				}
			}
		}
	}
	std::cout << n1 << " " << n5 << " " << n10 << " " << n20 << " " << n60 << " ";
	return EXIT_SUCCESS;
}
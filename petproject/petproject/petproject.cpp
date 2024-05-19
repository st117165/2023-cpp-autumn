#include<iostream>
#include <fstream>
#include <gmpxx.h>
#include <cmath>
#include <ctime>

int iterations(int DIGITS);
void correctcin1(int& DIGITS);
void correctcin2(int& n);
void menu();

int main(int argc, char* argv[])
{
	menu();

	return 0;
}

struct PQR
{
	mpz_class P, Q, R;
};

class ABCDE
{
	mpz_class A, B, C, D, E, C_3_24;
	double DIGITS_PER_TERM;
	PQR calcPQR(int n1, int n2);

public:

	ABCDE()
	{
		A = 13591409;
		B = 545140134;
		C = 640320;
		D = 426880;
		E = 10005;
		DIGITS_PER_TERM = 14.1816474627254776555;
		C_3_24 = C * C * C / 24;
	}
	void calcpi1(int DIGITS);
};

class ABC
{
	mpf_class A, B, C;

	void initABC(int PREC)
	{
		A.set_prec(PREC);
		B.set_prec(PREC);
		C.set_prec(PREC);
		A = 1;
		B = 2;
		B = 1 / sqrt(B);
		C = 0.25;
	}

public:

	void calcpi2(int DIGITS);
};

PQR ABCDE::calcPQR(int n1, int n2)
{
	int m;
	PQR res;

	if (n1 + 1 == n2)
	{
		res.P = (2 * n2 - 1);
		res.P *= (6 * n2 - 1);
		res.P *= (6 * n2 - 5);
		res.Q = C_3_24 * n2 * n2 * n2;
		res.R = (A + B * n2) * res.P;
		if ((n2 & 1) == 1)
		{
			res.R = -res.R;
		}
	}
	else
	{
		m = (n1 + n2) / 2;
		PQR res1 = calcPQR(n1, m);
		PQR res2 = calcPQR(m, n2);
		res.P = res1.P * res2.P;
		res.Q = res1.Q * res2.Q;
		res.R = res1.R * res2.Q + res1.P * res2.R;
	}

	return res;
}

void ABCDE::calcpi1(int DIGITS)
{
	std::cout << "\nChudnovsky:\n";
	
	double start = clock() / CLOCKS_PER_SEC;

	int PREC = DIGITS * log2(10);
	int N = DIGITS / DIGITS_PER_TERM + 1;

	std::cout << "number of iterations: " << N - 1 << "\n";

	

	PQR PQR = calcPQR(0, N);

	mpf_class pi(0, PREC);
	pi = D * sqrt((mpf_class)E) * PQR.Q;
	pi /= (A * PQR.Q + PQR.R);

	double time = ((double)clock() / CLOCKS_PER_SEC - start);
	printf("%.3f seconds\n", time);

	std::ofstream ofs("pi1.txt");
	ofs.precision(DIGITS + 1);
	ofs << pi;
}

void ABC::calcpi2(int DIGITS)
{
	std::cout << "\nGauss-Legendre:\n";

	double start = clock() / CLOCKS_PER_SEC;

	int PREC = DIGITS * log2(10);
	int N = iterations(DIGITS);

	initABC(PREC);

	int D = 1;

	std::cout << "number of iterations: " << N << "\n";

	

	for (int i = 1; i <= N; i++)
	{
		mpf_class y(0, PREC);
		y = A;
		A = (A + B) / 2;
		B = sqrt(B * y);
		C -= D * (y - A) * (y - A);
		D *= 2;
	}

	mpf_class pi(0, PREC);
	pi = (A + B) * (A + B) / (4 * C);

	double time = (double)clock() / CLOCKS_PER_SEC - start;
	printf("%.3f seconds\n", time);

	std::ofstream ofs("pi2.txt");
	ofs.precision(DIGITS + 1);
	ofs << pi << std::endl;
}

int iterations(int DIGITS)
{
	int N = 1;
	int yx = 2;
	int x = 5;

	while (yx < DIGITS)
	{
		N++;
		yx += x;
		x *= 2;
	}

	return N;
}

void correctcin1(int& n)
{
	while (!(std::cin >> n) || (n < 0))
	{
		std::cout << "uncorrect number \n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}

	std::cout << "\033[2J\033[1;1H";
}

void correctcin2(int& n)
{
	while (!(std::cin >> n) || (n > 2) || (n < 1))
	{
		std::cout << "uncorrect number \n";
		std::cin.clear();
		std::cin.ignore(1000000000, '\n');
	}

	std::cout << "\033[2J\033[1;1H";
}

void menu()
{
	std::cout << "choose calculation algorithm\n\n1) Chudnovsky\n\n2) Gauss-Legendre\n\n";

	int n = 0;
	int DIGITS = 0;

	correctcin2(n);

	std::cout << "choose how many digits you want: ";

	if (n == 1)
	{
		ABCDE pi;
		correctcin1(DIGITS);
		pi.calcpi1(DIGITS);
	}
	else
	{
		ABC pi;
		correctcin1(DIGITS);
		pi.calcpi2(DIGITS);
	}
}
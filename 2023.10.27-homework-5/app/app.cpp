#include"app.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

void menu()
{
	std::cout << "0) Exit." << std::endl;
	std::cout << "1) Display array." << std::endl;
	std::cout << "2) Add element to array." << std::endl;;
	std::cout << "3) Delete element of array." << std::endl;
	std::cout << "4) Sort array in ascending order." << std::endl;
	std::cout << "5) Reverse array." << std::endl;
	std::cout << "6) Swap first max element and last min element in array." << std::endl;
	std::cout << "7) Delete all dublicates in array." << std::endl;
	std::cout << "8) Add n random elements." << std::endl;
	return;
}
void expandarray(int*& a, int& l, int n)
{
	int* b = new int[l + n] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < l; ++i)
		{
			b[i] = a[i];
		}
	}
	delete[] a;
	a = b;
	l += n;
}
void displayarray(int*& a, int l)
{
	if (l == 0)
	{
		std::cout << "nullptr";
	}
	else
	{
		for (int i = 0; i < l; ++i)
		{
			std::cout << "{" << a[i] << "} ";
		}
	}
	std::cout << std::endl;
	system("pause");
}
void addelement(int*& a, int& l)
{
	expandarray(a, l, 1);
	int n = 0;
	std::cin >> n;
	a[l-1] = n;
}
void deleteelement(int*& a, int& l)
{
	if (a != nullptr)
	{
		int n = 0;
		std::cin >> n;
		while ((n < 0) || (n > l - 1))
		{
			std::cout << "Incorrect index. Try again." << std::endl;
			std::cin >> n;
		}
		int* b = new int[l - 1] { 0 };
		if (n == 0)
		{
			for (int i = 0; i < l - 1; ++i)
			{
				b[i] = a[i + 1];
			}
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				b[i] = a[i];
			}
			for (int i = n; i < l - 1; ++i)
			{
				b[i] = a[i + 1];
			}
		}
		--l;
		delete[] a;
		a = b;
	}
	else
	{
		std::cout << "cannot be applied to nullptr" << std::endl;
	}
}
void deleteelement1(int*& a, int& l, int n)
{
	int* b = new int[l - 1] { 0 };
	if (n == 0)
	{
		for (int i = 0; i < l - 1; ++i)
		{
			b[i] = a[i + 1];
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			b[i] = a[i];
		}
		for (int i = n; i < l - 1; ++i)
		{
			b[i] = a[i + 1];
		}
	}
	--l;
	delete[] a;
	a = b;
}
void sortascending(int*& a, int l)
{
	if (a != nullptr)
	{
		int* b = new int[l] { 0 };
		for (int i = 0; i < l; ++i)
		{
			int min = 2147483647;
			int minind = 0;
			for (int j = 0; j < l; ++j)
			{
				if (a[j] < min)
				{
					min = a[j];
					minind = j;
				}
			}
			b[i] = min;
			a[minind] = 2147483647;
		}
		delete[] a;
		a = b;
	}
	else
	{
		std::cout << "cannot be applied to nullptr" << std::endl;
		system("pause");
	}
}
void reversearray(int*& a, int l)
{
	if (a != nullptr)
	{
		int* b = new int[l] { 0 };
		for (int i = 0; i < l; ++i)
		{
			b[i] = a[l - i - 1];
		}
		delete[] a;
		a = b;
	}
	else
	{
		std::cout << "cannot be applied to nullptr" << std::endl;
		system("pause");
	}
}
void minmaxswap(int*& a, int l)
{
	if (a != nullptr)
	{
		int min = 2147483647;
		int minind = 0;
		int max = 0;
		int maxind = 0;
		for (int i = 0; i < l; ++i)
		{
			if (a[i] > max)
			{
				max = a[i];
				maxind = i;
			}
			if (a[l - i - 1] < min)
			{
				min = a[l - i - 1];
				minind = l - i - 1;
			}
		}
		a[maxind] = min;
		a[minind] = max;
	}
	else
	{
		std::cout << "cannot be applied to nullptr" << std::endl;
		system("pause");
	}
}
int countofelement(int*& a, int l, int n)
{
	int k = 0;
	for (int i = 0; i < l; ++i)
	{
		if (a[i] = n)
		{
			++k;
		}
	}
	return k;
}
void addnrandomelements(int*& a, int& l)
{
	int n = 0;
	std::cin >> n;
	srand(time(0));
	int l1 = l;
	expandarray(a, l, n);
	for (int i = l1; i < l; ++i)
	{
		a[i] = rand();
	}
}
void deletedublicates(int*& a, int& l)
{
	if (a != nullptr)
	{
		int* c = new int[l] {0};
		for (int i = 0; i < l - 1; i++)
		{
			for (int j = i + 1; j < l; j++)
			{
				if (a[i] == a[j])
				{
					c[i] = 1;
					c[j] = 1;
				}
			}
		}
		int i = 0;
		while (i != l)
		{
			if (c[i] == 1)
			{
				deleteelement1(a, l, i);
				deleteelement1(c, l, i);
			}
			else
			{
				++i;
			}
		}
		delete[] c;
	}
	else
	{
		std::cout << "cannot be applied to nullptr" << std::endl;
		system("pause");
	}
}


#include<iostream>
#include<cstdlib>
#include<ctime>
#include"app.h"

int main(int argc, char* argv[])
{
	
	bool exit = true;
	int* array = nullptr;
	int l = 0;
	while (exit)
	{
		{
			system("cls");
			menu();
		}
		int choice = 0;
		std::cin >> choice;
		{
			switch (choice)
			{
			case (0):
			{
				exit = false;
				break;
			}
			case (1):
			{
				displayarray(array, l);
				break;
			}
			case (2):
			{
				addelement(array, l);
				break;
			}
			case (3):
			{
				deleteelement(array, l);
				break;
			}
			case (4):
			{
				sortascending(array, l);
				break;
			}
			case (5):
			{
				reversearray(array, l);
				break;
			}
			case (6):
			{
				minmaxswap(array, l);
				break;
			}
			case (7):
			{
				deletedublicates(array, l);
				break;
			}
			case (8):
			{
				addnrandomelements(array, l);
				break;
			}
			default:
				std::cout << "unknown command." << std::endl;
			}
		}
	}
	return EXIT_SUCCESS;
}
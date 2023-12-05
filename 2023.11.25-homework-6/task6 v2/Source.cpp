#include <iostream>

void recursion(int n, int x, int y);

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    recursion(n, 1, 3);

    return EXIT_SUCCESS;
}

void recursion(int n, int x, int y)
{
    if (n > 0)
    {
        int res = 6 - x - y;
        recursion(n - 1, x, res);
        if (n != 1)
        {
            std::cout << 0 << " " << x << " " << y << std::endl;

        }
        else
        {
            std::cout << n << " " << 6 - x - y << " " << 3 << std::endl;
        }
        recursion(n - 1, res, y);
    }
}
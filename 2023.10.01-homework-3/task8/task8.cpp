#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int n = 0;
    int t = 0;
    int p = 0;
    char x = 'A';
    char y = 'B';
    std::cin >> a >> b >> n;
    int a1 = a;
    int b1 = b;
    if (a > b)
    {
        p = a;
        a = b;
        b = p;
        x = 'B';
        y = 'A';
    }
    if (n == b)
    {
        std::cout << ">" << y;
        return 0;
    }
    while (b1 != 0)
    {
        p = a1 % b1;
        a1 = b1;
        b1 = p;
    }
    if ((n % a1 != 0) || ((n > a) && (n > b)))
    {
        std::cout << "Impossible" << std::endl;
    }
    else
    {
        while (1)
        {
            t += a;
            std::cout << ">" << x << std::endl;
            std::cout << x << ">" << y << std::endl;
            if (t >= b)
            {
                std::cout << y << ">" << std::endl;
                std::cout << x << ">" << y << std::endl;
                t %= b;
            }
            if ((t == n) || (t == 0))
            {
                break;
            }
        }
    }
    return 0;
}
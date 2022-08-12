#include <iostream>
#include <stdlib.h>

class Symmetric
{
private:
    int* A;
    int n;

public:
    Symmetric();
    Symmetric(int n);
    ~Symmetric();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

Symmetric::Symmetric()
{
    n = 2;
    A = new int[n * (n + 1) / 2];
}

Symmetric::Symmetric(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

Symmetric::~Symmetric()
{
    delete[]A;
}

void Symmetric::Create()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> x;
            if (i >= j)
            {
                A[i * (i - 1) / 2 + j - 1] = x;
            }
        }
    }
}

void Symmetric::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

void Symmetric::Get(int i, int j)
{
    if (i >= j)
    {
        std::cout << A[i * (i - 1) / 2 + j - 1] << " ";
    }
    else
    {
        std::cout << "0 ";
    }
}

void Symmetric::Display()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                std::cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                Get(j, i);
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Enter Dimensions\n";
    std::cin >> n;

    Symmetric matrix(n);

    std::cout << "Enter items\n";

    matrix.Create();

    std::cout << std::endl;

    matrix.Display();
}

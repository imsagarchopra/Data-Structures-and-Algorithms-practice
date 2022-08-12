#include <iostream>
#include <stdlib.h>

class UpperTriangularRowMajor
{
private:
    int* A;
    int n;

public:
    UpperTriangularRowMajor();
    UpperTriangularRowMajor(int n);
    ~UpperTriangularRowMajor();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

UpperTriangularRowMajor::UpperTriangularRowMajor()
{
    n = 2;
    A = new int[n * (n + 1) / 2];
}

UpperTriangularRowMajor::UpperTriangularRowMajor(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

UpperTriangularRowMajor::~UpperTriangularRowMajor()
{
    delete[]A;
}

void UpperTriangularRowMajor::Create()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> x;
            if (i <= j)
            {
                A[((i - 1) * n - ((i - 2) * (i - 1)) / 2) + j - i] = x;
            }
        }
    }
}

void UpperTriangularRowMajor::Set(int i, int j, int x)
{
    if (i <= j)
    {
        A[((i - 1) * n - ((i - 2) * (i - 1)) / 2) + j - i] = x;
    }
}

void UpperTriangularRowMajor::Get(int i, int j)
{
    if (i <= j)
    {
        std::cout << A[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        std::cout << "0";
    }
}

void UpperTriangularRowMajor::Display()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                std::cout << A[((i - 1) * n - ((i - 2) * (i - 1)) / 2) + j - i] << " ";
            }
            else
            {
                std::cout << "0 ";
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

    UpperTriangularRowMajor matrix(n);

    std::cout << "Enter items\n";

    matrix.Create();

    std::cout << std::endl;

    matrix.Display();
}

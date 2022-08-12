#include <iostream>
#include <stdlib.h>

class LowerTriangularColumnMajor
{
private:
    int* A;
    int n;

public:
    LowerTriangularColumnMajor();
    LowerTriangularColumnMajor(int n);
    ~LowerTriangularColumnMajor();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

LowerTriangularColumnMajor::LowerTriangularColumnMajor()
{
    n = 2;
    A = new int[n * (n + 1) / 2];
}

LowerTriangularColumnMajor::LowerTriangularColumnMajor(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

LowerTriangularColumnMajor::~LowerTriangularColumnMajor()
{
    delete[]A;
}

void LowerTriangularColumnMajor::Create()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> x;
            if (i >= j)
            {
                A[((j - 1) * n - ((j - 2) * (j - 1)) / 2) + i - j] = x;
            }
        }
    }
}

void LowerTriangularColumnMajor::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[((j - 1) * n - ((j - 2) * (j - 1)) / 2) + i - j] = x;
    }
}

void LowerTriangularColumnMajor::Get(int i, int j)
{
    if (i >= j)
    {
        std::cout << A[((j - 1) * n - ((j - 2) * (j - 1)) / 2) + i - j];
    }
    else
    {
        std::cout << "0";
    }
}

void LowerTriangularColumnMajor::Display()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                std::cout << A[((j - 1) * n - ((j - 2) * (j - 1)) / 2) + i - j] << " ";
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

//int main()
//{
//    int n;
//    std::cout << "Enter Dimensions\n";
//    std::cin >> n;
//
//    LowerTriangularColumnMajor matrix(n);
//
//    std::cout << "Enter items\n";
//
//    matrix.Create();
//
//    std::cout << std::endl;
//
//    matrix.Display();
//}

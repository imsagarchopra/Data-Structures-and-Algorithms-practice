#include <iostream>
#include <stdlib.h>

class LowerTriangularRowMajor
{
private:
    int* A;
    int n;

public:
    LowerTriangularRowMajor();
    LowerTriangularRowMajor(int n);
    ~LowerTriangularRowMajor();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

LowerTriangularRowMajor::LowerTriangularRowMajor()
{
    n = 2;
    A = new int[n * (n + 1) / 2];
}

LowerTriangularRowMajor::LowerTriangularRowMajor(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

LowerTriangularRowMajor::~LowerTriangularRowMajor()
{
    delete[]A;
}

void LowerTriangularRowMajor::Create()
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

void LowerTriangularRowMajor::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

void LowerTriangularRowMajor::Get(int i, int j)
{
    if (i >= j)
    {
        std::cout << A[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        std::cout << "0";
    }
}

void LowerTriangularRowMajor::Display()
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
//    LowerTriangularRowMajor matrix(n);
//
//    std::cout << "Enter items\n";
//
//    matrix.Create();
//
//    std::cout << std::endl;
//
//    matrix.Display();
//}

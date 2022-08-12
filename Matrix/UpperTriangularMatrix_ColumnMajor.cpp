#include <iostream>
#include <stdlib.h>

class UpperTriangularColumnMajor
{
private:
    int* A;
    int n;

public:
    UpperTriangularColumnMajor();
    UpperTriangularColumnMajor(int n);
    ~UpperTriangularColumnMajor();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

UpperTriangularColumnMajor::UpperTriangularColumnMajor()
{
    n = 2;
    A = new int[n * (n + 1) / 2];
}

UpperTriangularColumnMajor::UpperTriangularColumnMajor(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

UpperTriangularColumnMajor::~UpperTriangularColumnMajor()
{
    delete[]A;
}

void UpperTriangularColumnMajor::Create()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> x;
            if (i <= j)
            {
                A[j * (j - 1) / 2 + i - 1] = x;
            }
        }
    }
}

void UpperTriangularColumnMajor::Set(int i, int j, int x)
{
    if (i <= j)
    {
        A[j * (j - 1) / 2 + i - 1] = x;
    }
}

void UpperTriangularColumnMajor::Get(int i, int j)
{
    if (i <= j)
    {
        std::cout << A[j * (j - 1) / 2 + i - 1];
    }
    else
    {
        std::cout << "0";
    }
}

void UpperTriangularColumnMajor::Display()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                std::cout << A[j * (j - 1) / 2 + i - 1] << " ";
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
//    UpperTriangularColumnMajor matrix(n);
//
//    std::cout << "Enter items\n";
//
//    matrix.Create();
//
//    std::cout << std::endl;
//
//    matrix.Display();
//}

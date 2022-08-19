#include <iostream>
#include <stdlib.h>

class Toeplitz
{
private:
    int* A;
    int n;

public:
    Toeplitz();
    Toeplitz(int n);
    ~Toeplitz();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

Toeplitz::Toeplitz()
{
    n = 2;
    A = new int[2 * n - 1];
}

Toeplitz::Toeplitz(int n)
{
    this->n = n;
    A = new int[2 * n - 1];
}

Toeplitz::~Toeplitz()
{
    delete[]A;
}

void Toeplitz::Create()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> x;
            if (i <= j)
            {
                A[j - i] = x;
            }          
            else
            {
                A[n + i - j - 1] = x;
            }
        }
    }
}

void Toeplitz::Set(int i, int j, int x)
{
    if (i <= j)
    {
        A[j - i] = x;
    }
    else
    {
        A[n + i - j - 1] = x;
    }
}

void Toeplitz::Get(int i, int j)
{
    if (i <= j)
    {     
        std::cout << A[j - i] << " ";
    }
    else
    {
        std::cout << A[n + i - j - 1] << " ";       
    }
}

void Toeplitz::Display()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                std::cout << A[j - i] << " ";
            }
            else
            {
                std::cout << A[n + i - j - 1] << " ";
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
//    Toeplitz matrix(n);
//
//    std::cout << "Enter items\n";
//
//    matrix.Create();
//
//    std::cout << std::endl;
//
//    matrix.Display();
//}

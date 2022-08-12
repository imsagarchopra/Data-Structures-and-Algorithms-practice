#include <iostream>
#include <stdlib.h>

class TriDiagonal
{
private:
    int* A;
    int n;

public:
    TriDiagonal();
    TriDiagonal(int n);
    ~TriDiagonal();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

TriDiagonal::TriDiagonal()
{
    n = 2;
    A = new int[3 * n - 2];
}

TriDiagonal::TriDiagonal(int n)
{
    this->n = n;
    A = new int[3 * n - 2];
}

TriDiagonal::~TriDiagonal()
{
    delete[]A;
}

void TriDiagonal::Create()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> x;
            if (i - j == 1)
            {
                A[i - 2] = x;
            }
            else if (i - j == 0)
            {
                A[n - 1 + i - 1] = x;
            }
            else if (i - j == -1)
            {
                A[2 * n - 1 + i - 1] = x;
            }
        }
    }
}

void TriDiagonal::Set(int i, int j, int x)
{
    if (i - j == 1)
    {
        A[i - 2] = x;
    }
    else if (i - j == 0)
    {
        A[n - 1 + i - 1] = x;
    }
    else if (i - j == -1)
    {
        A[2 * n - 1 + i - 1] = x;
    }
}

void TriDiagonal::Get(int i, int j)
{
    if (i - j == 1)
    {      
        std::cout << A[i - 2] << " ";
    }
    else if (i - j == 0)
    {       
        std::cout << A[n - 1 + i - 1] << " ";
    }
    else if (i - j == -1)
    {     
        std::cout << A[2 * n - 1 + i - 1] << " ";
    }  
    else
    {
        std::cout << "0 ";
    }
}

void TriDiagonal::Display()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i - j == 1)
            {
                std::cout << A[i - 2] << " ";
            }
            else if (i - j == 0)
            {
                std::cout << A[n - 1 + i - 1] << " ";
            }
            else if (i - j == -1)
            {
                std::cout << A[2 * n - 1 + i - 1] << " ";
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
//    TriDiagonal matrix(n);
//
//    std::cout << "Enter items\n";
//
//    matrix.Create();
//
//    std::cout << std::endl;
//
//    matrix.Display();
//}

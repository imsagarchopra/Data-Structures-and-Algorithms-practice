#include <iostream>
#include <stdlib.h>

class Diagonal
{
private:
    int* A;
    int n;

public:
    Diagonal();
    Diagonal(int n);
    ~Diagonal();
    void Create();
    void Set(int i, int j, int x);
    void Get(int i, int j);
    void Display();

};

Diagonal::Diagonal()
{
    n = 2;
    A = new int[n];
}

Diagonal::Diagonal(int n)
{   
    this->n = n;
    A = new int[n];
}

Diagonal::~Diagonal()
{
    delete[]A;
}

void Diagonal::Create()
{
    int i,j,x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {           
            std::cin >> x;
            if (i == j)
            {
                A[i - 1] = x;
            }
        }
    }
}

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

void Diagonal::Get(int i, int j)
{
    if (i == j)
    {
        std::cout << A[i - 1];
    }
    else
    {
        std::cout << "0";
    }
}

void Diagonal::Display()
{
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {          
            if (i == j)
            {
                std::cout<< A[i - 1] << " ";
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout<< std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Enter Dimensions\n";
    std::cin >> n;

    Diagonal matrix(n);

    std::cout << "Enter items\n";

    matrix.Create();

    std::cout << std::endl;

    matrix.Display();
}

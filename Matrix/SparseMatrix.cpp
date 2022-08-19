#include <iostream>
#include <stdlib.h>
using namespace std;
class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element* ele;

public:
    
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        this->ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }

    void Read()
    {
        cout << "Enter non-zero elements" << endl;
        
        for (int i = 0; i < num; i++)
        {
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
        }
    }

    void Display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ele[k].i == i && ele[k].j == j)
                {
                    cout << ele[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    Sparse Add(Sparse &s)
    {
        int i, j, k;
        if (m != s.m || n != s.n)
            return Sparse(0, 0, 0);
        Sparse* sum = new Sparse(m, n, num + s.num);

        i = j = k = 0;
        while (i < num && j < s.num)
        {
            if (ele[i].i < s.ele[j].i)
                sum->ele[k++] = ele[i++];
            else if (ele[i].i > s.ele[j].i)
                sum->ele[k++] = s.ele[j++];
            else
            {
                if (ele[i].j < s.ele[j].j)
                    sum->ele[k++] = ele[i++];
                else if (ele[i].j > s.ele[j].j)
                    sum->ele[k++] = s.ele[j++];
                else
                {
                    sum->ele[k] = ele[i];
                    sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
                }
            }
        }
        for (; i < num; i++)sum->ele[k++] = ele[i];
        for (; j < s.num; j++)sum->ele[k++] = s.ele[j];
        sum->num = k;

        return *sum;
    }

};


//int main()
//{   
//    Sparse s1(5,5,5);
//    s1.Read();
//    cout << endl;
//
//    Sparse s2(5, 5, 5);
//    s2.Read();
//    cout << endl;
//    Sparse sum = s1.Add(s2);
//
//    cout << endl;
//    sum.Display();
//}

#include <iostream>
#include <stdlib.h>
using namespace std;
class Term
{
public:
	int coeff;
	int exp;
};

class Polynomial
{
private:
	int n;
	Term* term;

public:

	Polynomial(int n)
	{
		this->n = n;
		this->term = new Term[this->n];
	}
	~Polynomial()
	{
		delete[] term;
	}

	void Read()
	{
		cout << "Enter Polynomial elements" << endl;

		for (int i = 0; i < n; i++)
		{
			cin >> term[i].coeff >> term[i].exp;
		}
	}

	void Display()
	{
		for (int i = 0; i < n; i++)
		{
			cout << term[i].coeff << "x" << term[i].exp << " + ";
		}
	}

	Polynomial Add(Polynomial& p)
	{
		int i, j, k;

		Polynomial* sum = new Polynomial(n + p.n);

		i = j = k = 0;
		while (i < n && j < p.n)
		{
			if (term[i].exp > p.term[j].exp)
				sum->term[k++] = term[i++];
			else if (term[i].exp < p.term[j].exp)
				sum->term[k++] = p.term[j++];
			else
			{
				sum->term[k].exp = term[i].exp;
				sum->term[k++].coeff = term[i++].coeff + p.term[j++].coeff;
			}
		}
		for (; i < n; i++)sum->term[k++] = term[i];
		for (; j < p.n; j++)sum->term[k++] = p.term[j];
		sum->n = k;

		return *sum;
	}

};


int main()
{
	Polynomial p1(3);
	p1.Read();
	cout << endl;

	Polynomial p2(4);
	p2.Read();
	cout << endl;

	Polynomial sum = p1.Add(p2);

	cout << endl;
	sum.Display();
}

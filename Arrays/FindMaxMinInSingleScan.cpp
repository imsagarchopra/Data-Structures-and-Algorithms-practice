#include <iostream>
using namespace std;
template<class T>
class Array
{
private:
	T* A;
	int size;
	int length;
public:
	Array()
	{
		size = 10;
		A = new T[10];
		length = 0;
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new T[size];
	}
	~Array()
	{
		delete[]A;
	}
	void Display();
	void Insert(int index, T x);
	void MaxMin();
};

template<class T>
void Array<T>::Display()
{
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";
	cout << endl;
}

template<class T>
void Array<T>::Insert(int index, T x)
{
	if (index >= 0 && index <= length)
	{
		for (int i = length - 1; i >= index; i--)
			A[i + 1] = A[i];
		A[index] = x;
		length++;
	}
}

template<class T>
void Array<T>::MaxMin()
{
	int min = A[0];
	int max = A[0];

	for (int i = 1; i < length; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
		else if (A[i] > max)
		{
			max = A[i];
		}
	}
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
}

int main()
{
	int k = 10;
	Array<int> arr1(10);

	arr1.Insert(0, 6);
	arr1.Insert(1, 3);
	arr1.Insert(2, 8);
	arr1.Insert(3, 10);
	arr1.Insert(4, 16);
	arr1.Insert(5, 7);
	arr1.Insert(6, 5);
	arr1.Insert(7, 2);
	arr1.Insert(8, 9);
	arr1.Insert(9, 14);

	
	arr1.Display();	
	arr1.MaxMin();
	return 0;
}
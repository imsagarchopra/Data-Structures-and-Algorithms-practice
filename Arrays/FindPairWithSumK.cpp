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
	int Max();
	int Min();
	void FindPairWithSumK(int k);
	void FindPairWithSumKUsingHashing(int k);
	void FindPairWithSumKInSortedArray(int k);

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
int Array<T>::Max()
{
	int max = A[0];

	for (int i = 1; i < length; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	return max;
}

template<class T>
int Array<T>::Min()
{
	int min = A[0];

	for (int i = 1; i < length; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
	}
	return min;
}

template<class T>
void Array<T>::FindPairWithSumK(int k)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (A[i] + A[j] == k)
			{
				cout << "(" << A[i] << "," << A[j] << ")" << endl;
			}
		}
	}
}

template<class T>
void Array<T>::FindPairWithSumKUsingHashing(int k)
{
	int l, h;
	l = Min();
	h = Max();

	Array<int> H(h + 1);

	for (int i = 0; i <= h; i++)
	{
		H.Insert(i, 0);
	}

	for (int i = 0; i < length - 1; i++)
	{
		if (H.A[k - A[i]] != 0)
		{
			cout << "(" << A[i] << "," << k - A[i] << ")" << endl;
		}
		H.A[A[i]]++;
	}
}

template<class T>
void Array<T>::FindPairWithSumKInSortedArray(int k)
{
	int i = 0;
	int j = length - 1;

	while (i < j)
	{
		if (A[i] + A[j] == k)
		{
			cout << "(" << A[i] << "," << k - A[i] << ")" << endl;
			i++;
			j--;
		}
		else if (A[i] + A[j] < k)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
}

//int main()
//{
//	int k = 10;
//	Array<int> arr1(10);
//	Array<int> arr2(10);
//
//	arr1.Insert(0, 6);
//	arr1.Insert(1, 3);
//	arr1.Insert(2, 8);
//	arr1.Insert(3, 10);
//	arr1.Insert(4, 16);
//	arr1.Insert(5, 7);
//	arr1.Insert(6, 5);
//	arr1.Insert(7, 2);
//	arr1.Insert(8, 9);
//	arr1.Insert(9, 14);
//
//	arr2.Insert(0, 1);
//	arr2.Insert(1, 3);
//	arr2.Insert(2, 4);
//	arr2.Insert(3, 5);
//	arr2.Insert(4, 6);
//	arr2.Insert(5, 8);
//	arr2.Insert(6, 9);
//	arr2.Insert(7, 10);
//	arr2.Insert(8, 12);
//	arr2.Insert(9, 14);
//
//	//arr1.Display();	
//	arr2.Display();
//	//arr1.FindPairWithSumK(k);
//	//arr1.FindPairWithSumKUsingHashing(k);
//	arr2.FindPairWithSumKInSortedArray(k);
//	return 0;
//}
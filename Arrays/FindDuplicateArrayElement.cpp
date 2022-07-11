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
	void FindDuplicateElementFromSortedArray();
	void CountDuplicateElementsInSortedArray();
	void CountDuplicateElementsInUnSortedArrayUsingHashing();
	void CountDuplicateElementsInUnSortedArray();

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
void Array<T>::FindDuplicateElementFromSortedArray()
{
	int lastDupliate = 0;
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i] == A[i + 1] && A[i] != lastDupliate)
		{
			cout << A[i] << endl;
			lastDupliate = A[i];
		}
	}
}
//3 6 8 8 10 12 15 15 15 20

template<class T>
void Array<T>::CountDuplicateElementsInSortedArray()
{
	int j = 0;
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i] == A[i + 1])
		{
			j = i + 1;
			while (A[i] == A[j]) j++;
			cout << A[i] << " is appearing " << j - i << " times" << endl;
			i = j - 1;
		}
	}
}

template<class T>
void Array<T>::CountDuplicateElementsInUnSortedArrayUsingHashing()
{
	int l, h;
	l = Min();
	h = Max();

	Array<int> H(h + 1);	

	for (int i = 0; i <= h; i++)
	{
		H.Insert(i, 0);
	}

	for (int i = 0; i < length; i++)
	{
		H.A[A[i]]++;
	}

	for (int i = 0; i < h; i++)
	{
		if (H.A[i] > 1)
		{
			cout << i << " is appearing " << H.A[i] << " times" << endl;
		}
	}
}

template<class T>
void Array<T>::CountDuplicateElementsInUnSortedArray()
{
	for (int i = 0; i < length - 1; i++)
	{
		int count = 1;

		if (A[i] != -1)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (A[i] == A[j])
				{
					count++;
					A[j] = -1;
				}
			}

			if (count > 1)
			{
				cout << A[i] << " is appearing " << count << " times" << endl;
			}
		}		
	}
}

//int main()
//{
//	Array<int> arr1(10);	
//	
//	arr1.Insert(0, 3);
//	arr1.Insert(1, 6);
//	arr1.Insert(2, 8);
//	arr1.Insert(3, 8);
//	arr1.Insert(4, 10);
//	arr1.Insert(5, 12);
//	arr1.Insert(6, 15);
//	arr1.Insert(7, 15);
//	arr1.Insert(8, 15);
//	arr1.Insert(9, 20);
//
//	arr1.Display();
//	//arr1.FindDuplicateElementFromSortedArray();
//	//arr1.CountDuplicateElementsInSortedArray();
//	//arr1.CountDuplicateElementsInUnSortedArrayUsingHashing();
//	arr1.CountDuplicateElementsInUnSortedArray();
//	return 0;
//}


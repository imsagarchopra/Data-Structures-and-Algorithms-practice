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
		int Sum();
		int Max();
		int Min();
		void FindSingleMissingElementFromSortedArray();
		void FindMultipleMissingElementsFromSortedArray();
		void FindMultipleMissingElementsFromUnSortedArray();

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
int Array<T>::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}

template<class T>
int Array<T>:: Max()
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
int Array<T>:: Min()
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
void Array<T>::FindSingleMissingElementFromSortedArray()
{
	int n = A[length - 1];
	int expectedSum = (n * (n + 1)) / 2;
	int actualSum = Sum();

	cout << "Missing Number : " << expectedSum - actualSum;
}

template<class T>
void Array<T>::FindMultipleMissingElementsFromSortedArray()
{
	int l, h, diff;
	l = A[0];
	h = A[length - 1];

	diff = l - 0;

	for (int i = 0; i < length; i++)
	{
		if (A[i] - i != diff)
		{
			while (diff < A[i] - i)
			{
				cout << i + diff << endl;
				diff++;
			}
			
		}
	}

}

template<class T>
void Array<T>::FindMultipleMissingElementsFromUnSortedArray()
{
	int l, h;
	l = Min();
	h = Max();
	
	Array<int> H(h);
	for (int i = 0; i < H.length; i++)
	{
		H.A[i] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		H.A[A[i]]++;
	}

	for (int i = 0; i < H.length; i++)
	{
		if (H.A[i] == 0)
		{
			cout << i << endl;
		}
	}


}

int main()
{
	Array<int> arr1(10);
	Array<int> arr2(10);
	
	arr1.Insert(0, 1);
	arr1.Insert(1, 2);
	arr1.Insert(2, 3);
	arr1.Insert(3, 4);
	arr1.Insert(4, 5);
	arr1.Insert(5, 7);
	arr1.Insert(6, 8);
	arr1.Insert(7, 9);
	arr1.Insert(8, 10);
	arr1.Insert(9, 11);
	arr1.Insert(10, 12);

	arr2.Insert(0, 6);
	arr2.Insert(1, 7);
	arr2.Insert(2, 8);
	arr2.Insert(3, 9);
	arr2.Insert(4, 11);
	arr2.Insert(5, 12);
	arr2.Insert(6, 15);
	arr2.Insert(7, 16);
	arr2.Insert(8, 17);
	arr2.Insert(9, 18);
	arr2.Insert(10, 19);

	//arr1.Display();
	//arr1.FindSingleMissingElementFromSortedArray();
	//arr2.FindMultipleMissingElementsFromSortedArray();
	arr2.FindMultipleMissingElementsFromUnSortedArray();
    
	
	return 0;
}


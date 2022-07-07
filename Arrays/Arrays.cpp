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
	T Delete(int index);
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
T Array<T>::Delete(int index)
{
	T x = 0;
	if (index >= 0 && index < length)
	{
		x = A[index];
		for (int i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length--;
	}
	return x;
}
int main()
{
	Array<char> arr(10);

	arr.Insert(0, 'a');
	arr.Insert(1, 'c');
	arr.Insert(2, 'd');
	arr.Display();
	cout << arr.Delete(0) << endl;
	arr.Display();
	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//class Array
//{
//    private:
//        int *A;
//        int size;
//        int length;
//    public:
//        Array()
//        {
//            size = 10;
//            length = 0;
//            A = new int[size];
//        }
//        Array(int sz)
//        {
//            size = sz;
//            length = 0;
//            A = new int[size];
//        }
//        ~Array()
//        {
//            delete[]A;
//        }
//
//        void Display();
//        void Swap(int* a, int* b);
//        void Append(int n);
//        void Insert(int index, int n);
//        int Delete(int index);
//        int LinearSearch(int n);
//        int LinearSearchUsingTransposition(int n);
//        int LinearSearchUsingMoveToFront(int n);
//        int BinarySearch(int n);
//        int RecursiveBinarySearch(int l, int h, int n);
//        int Get(int index);
//        void Set(int index, int n);
//        int Max();
//        int Min();
//        int Sum();
//        int RecursiveSum(int n);
//        int Avg();
//        void Reverse();
//        void ReverseUsingSwap();
//        void LeftShift();
//        void LeftRotation();
//        void RightShift();
//        void RightRotation();
//        void InsertInSortedArray(int n);
//        bool IsSorted();
//        void MoveNegativesOnLeftSide();
//        Array* Merge(Array arr2);
//        Array* Union(Array arr2);
//        Array* Intersection(Array arr2);
//        Array* Difference(Array arr2);
//
//};
//
//void Array :: Display()
//{
//    for (int i = 0; i < length; i++)
//    {
//        printf("%d ", A[i]);
//    }
//}
//
//void Array::Swap(int* a, int* b)
//{
//    int temp;
//    temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void Array :: Append(int n)
//{
//    if (length < size)
//    {
//        A[length++] = n;
//    }
//}
//
//void Array :: Insert(int index, int n)
//{
//    if (index >= 0 && index <= length)
//    {
//        for (int i = length; i > index; i--)
//        {
//            A[i] = A[i - 1];
//        }
//
//        A[index] = n;
//        length++;
//    }
//
//}
//
//int Array :: Delete(int index)
//{
//    if (index >= 0 && index < length)
//    {
//        int x = A[index];
//        for (int i = index; i < length; i++)
//        {
//            A[i] = A[i + 1];
//        }
//        length--;
//        return x;
//    }
//    return 0;
//}
//
//int Array:: LinearSearch(int n)
//{
//    for (int i = 0; i < length; i++)
//    {
//        if (n ==  A[i])
//        {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int Array :: LinearSearchUsingTransposition(int n)
//{
//    for (int i = 0; i < length; i++)
//    {
//        if (n == A[i])
//        {
//            Swap(&A[i], &A[i - 1]);
//            return i;
//        }
//    }
//    return -1;
//}
//
//int Array:: LinearSearchUsingMoveToFront(int n)
//{
//    for (int i = 0; i < length; i++)
//    {
//        if (n == A[i])
//        {
//            Swap(&A[i], &A[0]);
//            return i;
//        }
//    }
//    return -1;
//}
//
//int Array :: BinarySearch(int n)
//{
//    int l, mid, h;
//    l = 0;
//    h = length - 1;
//
//    while (l <= h)
//    {
//        mid = (l + h) / 2;
//        if (n == A[mid])
//            return mid;
//        else if (n < A[mid])
//        {
//            h = mid - 1;
//        }
//        else
//        {
//            l = mid + 1;
//        }
//    }
//    return -1;
//}
//
//int Array :: RecursiveBinarySearch(int l, int h, int n)
//{
//    int mid;
//
//    if (l <= h)
//    {
//        mid = (l + h) / 2;
//        if (n == A[mid])
//            return mid;
//        else if (n < A[mid])
//        {
//            return RecursiveBinarySearch(l, mid - 1, n);
//        }
//        else
//        {
//            return RecursiveBinarySearch(mid + 1, h, n);
//        }
//    }
//    return -1;
//}
//
//int Array:: Get(int index)
//{
//    if (index >= 0 && index < length)
//    {
//        return A[index];
//    }
//    return -1;
//}
//
//void Array:: Set(int index, int n)
//{
//    if (index >= 0 && index < length)
//    {
//        A[index] = n;
//    }
//}
//
//int Array:: Max()
//{
//    int max = A[0];
//
//    for (int i = 1; i < length; i++)
//    {
//        if (A[i] > max)
//        {
//            max = A[i];
//        }
//    }
//    return max;
//}
//
//int Array:: Min()
//{
//    int min = A[0];
//
//    for (int i = 1; i < length; i++)
//    {
//        if (A[i] < min)
//        {
//            min = A[i];
//        }
//    }
//    return min;
//}
//
//int Array::Sum()
//{
//    int sum = 0;
//
//    for (int i = 0; i < length; i++)
//    {
//        sum += A[i];
//    }
//    return sum;
//}
//
//int Array::RecursiveSum(int n)
//{
//    if (n < 0)
//        return 0;
//    else
//    {
//        return RecursiveSum(n - 1) + A[n];
//    }
//}
//
//int Array::Avg()
//{
//    return Sum() / length;
//}
//
//void Array::Reverse()
//{
//    int* B;
//    int i, j;
//
//    B = (int*)malloc(length * sizeof(int));
//    for (i = length - 1, j = 0; i >= 0; i--, j++)
//        B[j] = A[i];
//    for (i = 0; i < length; i++)
//        A[i] = B[i];
//
//}
//
//void Array::ReverseUsingSwap()
//{
//    int i, j;
//    for (i = 0, j = length - 1; i < j; i++, j--)
//    {
//        Swap(&A[i], &A[j]);
//    }
//}
//
//void Array::LeftShift()
//{
//    int i;
//    for (i = 0; i < length - 1; i++)
//    {
//        A[i] = A[i + 1];
//    }
//    A[length - 1] = 0;
//}
//
//void Array::LeftRotation()
//{
//    int i, rotationVar;
//
//    rotationVar = A[0];
//
//    for (i = 0; i < length - 1; i++)
//    {
//
//        A[i] = A[i + 1];
//    }
//
//    A[length - 1] = rotationVar;
//}
//
//void Array::RightShift()
//{
//    int i;
//    for (i = length - 1; i > 0; i--)
//    {
//        A[i] = A[i - 1];
//    }
//    A[0] = 0;
//}
//
//void Array::RightRotation()
//{
//    int i, rotationVar;
//
//    rotationVar = A[length - 1];
//
//    for (i = length - 1; i > 0; i--)
//    {
//        A[i] = A[i - 1];
//    }
//    A[0] = rotationVar;
//
//}
//
//void Array::InsertInSortedArray(int n)
//{
//    int i = length - 1;
//
//    if (length == size)
//        return;
//
//    while (A[i] > n)
//    {
//        A[i + 1] = A[i];
//        i--;
//    }
//    A[i + 1] = n;
//    length++;
//
//}
//
//bool Array::IsSorted()
//{
//    int i;
//
//    for (i = 0; i < length - 1; i++)
//    {
//        if (A[i] > A[i + 1])
//            return false;
//    }
//    return true;
//}
//
//void Array::MoveNegativesOnLeftSide()
//{
//    int i, j;
//    i = 0;
//    j = length - 1;
//
//    while (i < j)
//    {
//        while (A[i] < 0)
//            i++;
//        while (A[j] >= 0)
//            j--;
//
//        if (i < j)
//        {
//            Swap(&A[i], &A[j]);
//        }
//    }
//}
//
//Array* Array::Merge(Array arr2)
//{
//    int i, j, k;
//    i = j = k = 0;
//
//    Array* arr3 = new Array(length + arr2.length);
//
//    while (i < length && j < arr2.length)
//    {
//        if (A[i] < arr2.A[j])
//            arr3->A[k++] = A[i++];
//        else
//            arr3->A[k++] = arr2.A[j++];
//    }
//    for (; i < length; i++)
//        arr3->A[k++] = A[i];
//    for (; j < arr2.length; j++)
//        arr3->A[k++] = arr2.A[j];
//    arr3->length = length + arr2.length;   
//
//    return arr3;
//}
//
//Array* Array:: Union(Array arr2)
//{
//    int i, j, k;
//    i = j = k = 0;
//
//    Array* arr3 = new Array();
//
//    while (i < length && j < arr2.length)
//    {
//        if (A[i] < arr2.A[j])
//            arr3->A[k++] = A[i++];
//        else if (arr2.A[j] < A[i])
//            arr3->A[k++] = arr2.A[j++];
//        else
//        {
//            arr3->A[k++] = A[i++];
//            j++;
//        }
//    }
//    for (; i < length; i++)
//        arr3->A[k++] = A[i];
//    for (; j < arr2.length; j++)
//        arr3->A[k++] = arr2.A[j];
//    arr3->length = k;
//    arr3->size = 10;
//
//    return arr3;
//}
//
//Array* Array::Intersection(Array arr2)
//{
//    int i, j, k;
//    i = j = k = 0;
//
//    Array* arr3 = new Array();
//
//    while (i < length && j < arr2.length)
//    {
//        if (A[i] < arr2.A[j])
//            i++;
//        else if (arr2.A[j] < A[i])
//            j++;
//        else
//        {
//            arr3->A[k++] = A[i++];
//            j++;
//        }
//    }
//    arr3->length = k;
//    arr3->size = 10;
//
//    return arr3;
//}
//
//Array* Array::Difference(Array arr2)
//{
//    int i, j, k;
//    i = j = k = 0;
//
//    Array* arr3 = new Array();
//
//    while (i < length && j < arr2.length)
//    {
//        if (A[i] < arr2.A[j])
//            arr3->A[k++] = A[i++];
//        else if (arr2.A[j] < A[i])
//            j++;
//        else
//        {
//            i++;
//            j++;
//        }
//    }
//
//    for (; i < length; i++)
//        arr3->A[k++] = A[i];
//    arr3->length = k;
//    arr3->size = 10;
//
//    return arr3;
//}
//
//int main() {
//
//    Array *arr;
//    arr = new Array();
//
//    arr->Display();
//    printf("\n");
// 
//    return 0;
//}
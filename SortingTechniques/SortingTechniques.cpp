
#include <iostream>
using namespace std;

void Swap(int* x, int* y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(int A[], int n)
{
	int i, j, flag;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				Swap(&A[j], &A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)// it means list is already sorted
		{
			break;
		}
	}
}

void InsertionSort(int A[], int n)
{
	int i, j, x;

	for (int i = 1; i < n ; i++)
	{
		j = i - 1;
		x = A[i];

		while (j > -1 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

void SelectionSort(int A[], int n)
{
	int i, j, k;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = k = i; j < n; j++)
		{
			if (A[j] < A[k])
			{
				k = j;
			}
		}
		Swap(&A[i], &A[k]);
	}
}

int Partition(int A[], int l, int h)
{
	int pivot, i, j;
	pivot = A[l];
	i = l;
	j = h;

	do
	{
		do { i++; } while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);

		if (i < j)
		{
			Swap(&A[i], &A[j]);
		}

	} while (i < j);

	Swap(&A[l], &A[j]);
	return j;
}

void QuickSort(int A[], int l, int h)
{
	int j;	

	if (l < h)
	{
		j = Partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j + 1, h);
	}
}

void Print(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2,INT32_MAX }, n = 11, i;

	//BubbleSort(A, n);
	//InsertionSort(A, n);
	//SelectionSort(A, n);
	//Print(A, n);

	QuickSort(A, 0, n - 1);
	Print(A, n-1);
	
}


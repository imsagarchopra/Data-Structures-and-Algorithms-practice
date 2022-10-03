
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
	int A[] = { 3,7,9,10,6,5,12,4,11,2 }, n = 10, i;

	//BubbleSort(A, n);
	//InsertionSort(A, n);
	SelectionSort(A, n);
	Print(A, n);
	
}


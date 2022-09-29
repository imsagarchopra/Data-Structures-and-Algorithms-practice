
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

	BubbleSort(A, n);
	Print(A, n);
	
}


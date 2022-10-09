
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

void Merge(int x[], int y[], int z[], int m, int n) 
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < m && j < n) {
		if (x[i] < y[j]) {
			z[k++] = x[i++];
		}
		else {
			z[k++] = y[j++];
		}
	}
	while (i < m) {
		z[k++] = x[i++];
	}
	while (j < n) {
		z[k++] = x[j++];
	}
}

void MergeSingle(int A[], int low, int mid, int high) 
{
	int i = low;
	int j = mid + 1;
	int k = low;
	int B[11]; //high + 1
	while (i <= mid && j <= high) {
		if (A[i] < A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}
	while (i <= mid) {
		B[k++] = A[i++];
	}
	while (j <= high) {
		B[k++] = A[j++];
	}
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

void IterativeMergeSort(int A[], int n)
{
	int p;
	for (p = 2; p <= n; p = p * 2)
	{
		for (int i = 0; i + p - 1 < n; i = i + p)
		{
			int low = i;
			int high = i + p - 1;
			int mid = (low + high) / 2;
			MergeSingle(A, low, mid, high);
		}
	}

	if (p / 2 < n)
	{
		MergeSingle(A, 0, p/2 - 1, n - 1);
	}
}

void RecursiveMergeSort(int A[], int low, int high)
{

	if (low < high)
	{
		int mid = (low + high) / 2;

		RecursiveMergeSort(A, low, mid);
		RecursiveMergeSort(A, mid + 1, high);
		MergeSingle(A, low, mid, high);
	}

}

int FindMax(int A[], int n)
{
	int max = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	return max;
}

void CountSort(int A[], int n) {
	int max = FindMax(A, n);

	// Create count array
	int* count = new int[max+1];

	// Initialize count array with 0
	for (int i = 0; i < max + 1; i++) {
		count[i] = 0;
	}

	// Update count array values based on A values
	for (int i = 0; i < n; i++) {
		count[A[i]]++;
	}

	// Update A with sorted elements
	int i = 0;
	int j = 0;
	while (j < max + 1) {
		if (count[j] > 0) {
			A[i++] = j;
			count[j]--;
		}
		else {
			j++;
		}
	}

	// Delete heap memory
	delete[] count;
}

// Linked List node
class Node {
public:
	int value;
	Node* next;
};

void Insert(Node** ptrBins, int idx) {
	Node* temp = new Node;
	temp->value = idx;
	temp->next = nullptr;

	if (ptrBins[idx] == nullptr) { // ptrBins[idx] is head ptr
		ptrBins[idx] = temp;
	}
	else {
		Node* p = ptrBins[idx];
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = temp;
	}
}

int Delete(Node** ptrBins, int idx) {
	Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
	ptrBins[idx] = ptrBins[idx]->next;
	int x = p->value;
	delete p;
	return x;
}

void BinSort(int A[], int n) {
	int max = FindMax(A, n);

	// Create bins array
	Node** bins = new Node * [max + 1];

	// Initialize bins array with nullptr
	for (int i = 0; i < max + 1; i++) {
		bins[i] = nullptr;
	}

	// Update count array values based on A values
	for (int i = 0; i < n; i++) {
		Insert(bins, A[i]);
	}

	// Update A with sorted elements
	int i = 0;
	int j = 0;
	while (i < max + 1) {
		while (bins[i] != nullptr) {
			A[j++] = Delete(bins, i);
		}
		i++;
	}

	// Delete heap memory
	delete[] bins;
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

	//QuickSort(A, 0, n - 1);
	//Print(A, n-1);

	//IterativeMergeSort(A, n);
	//RecursiveMergeSort(A, 0, n - 1);
	//Print(A, n - 1);

	//CountSort(A, n);
	BinSort(A, n);
	Print(A, n - 1);
}


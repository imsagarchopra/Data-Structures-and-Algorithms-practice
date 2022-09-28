#include <iostream>
#include <vector>

using namespace std;

// Lecture based
void InsertA(int A[], int n) {
	int i = n;
	int temp = A[n];
	while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
		A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
		i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
	}
	A[i] = temp;
}


// STL vector based
void Insert(vector<int>& vec, int key) {
	// Insert key at the end
	auto i = vec.size();
	vec.emplace_back(key);

	// Rearrange elements: Indices are not DRY :-(
	while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
		vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
		i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
	}
	vec[i] = key;
}

template <class T>
void Print(T& vec, int n) {
	cout << "Max Heap: [" << flush;
	for (int i = 0; i < n; i++) {
		cout << vec[i] << flush;
		if (i < n - 1) {
			cout << ", " << flush;
		}
	}
	cout << "]" << endl;
}

template <class T>
void Print(T& vec, int n, char c) {
	cout << c << ": [" << flush;
	for (int i = 0; i < n; i++) {
		cout << vec[i] << flush;
		if (i < n - 1) {
			cout << ", " << flush;
		}
	}
	cout << "]" << endl;
}


void CreateHeap(vector<int>& vec, int A[], int n) {
	// O(n log n)
	for (int i = 0; i < n; i++) {
		Insert(vec, A[i]);
	}
}

void createHeap(int A[], int n) {
	for (int i = 0; i < n; i++) {
		InsertA(A, i);
	}
}

//int main() {
//
//	int a[] = { 45, 35, 15, 30, 10, 12, 6, 5, 20, 50 };
//	InsertA(a, 9);
//	Print(a, sizeof(a) / sizeof(a[0]));
//	cout << endl;
//
//	// STL based
//	vector<int> v = { 45, 35, 15, 30, 10, 12, 6, 5, 20 };
//	Print(v, v.size());
//	v.reserve(15);  // Reserve space for 15 elements
//
//	Insert(v, 50);
//	Print(v, v.size());
//
//	cout << "Create Heap" << endl;
//	int b[] = { 10, 20, 30, 25, 5, 40, 35 };
//	Print(b, sizeof(b) / sizeof(b[0]), 'b');
//
//	vector<int> vec;
//	CreateHeap(vec, b, sizeof(b) / sizeof(b[0]));
//	Print(vec, vec.size(), 'vec');
//
//	cout << "Inplace Insert" << endl;
//	createHeap(b, sizeof(b) / sizeof(b[0]));
//	Print(b, sizeof(b) / sizeof(b[0]), 'b');
//
//	return 0;
//}
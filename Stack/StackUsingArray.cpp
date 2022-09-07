#include <iostream>
using namespace std;
class Stack
{
private:
	int size;
	int top;
	int* S;
public:
	Stack(int size);
	~Stack();
	int IsFull();
	int IsEmpty();
	void Push(int x);
	int Pop();
	int Peek(int index);
	int StackTop();
	void Display();	
};

Stack::Stack(int size)
{
	this->size = size;
	this->top = -1;
	this->S = new int[size];
}

Stack::~Stack()
{
	delete[] S;
}

int Stack::IsFull()
{
	if (top == size - 1)
	{
		return 1;
	}	
	return 0;	
}

int Stack::IsEmpty()
{
	if (top == - 1)
	{
		return 1;
	}
	return 0;
}

void Stack::Push(int x)
{
	if (IsFull())
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		top++;
		S[top] = x;
	}
}

int Stack::Pop()
{
	int x = -1;
	if (IsEmpty())
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{
		x = S[top];
		top--;
	}
	return x;
}

int Stack::Peek(int index) 
{
	int x = -1;
	if (top - index + 1 < 0 || top - index + 1 == size) {
		cout << "Invalid position!" << endl;
	}
	else {
		x = S[top - index + 1];
	}
	return x;
}

int Stack::StackTop()
{	
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return S[top];
	}
}

void Stack::Display()
{
	for (int i = top; i >= 0; i--) {
		cout << S[i] << " | " << flush;
	}
	cout << endl;
	
}

//int main()
//{
//	int A[] = { 1, 3, 5, 7, 9 };
//
//	Stack stk(sizeof(A) / sizeof(A[0]));
//
//	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
//	{
//		stk.Push(A[i]);
//	}
//	stk.Push(11);
//	stk.Display();
//
//	stk.Pop();
//	stk.Display();
//
//	cout << stk.Peek(2) << endl;
//
//	cout << stk.StackTop() << endl;
//
//}

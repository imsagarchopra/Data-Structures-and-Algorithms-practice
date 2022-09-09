#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class StackUsingLL
{
private:
	Node* top;
public:
	StackUsingLL();
	~StackUsingLL();
	int IsFull();
	int IsEmpty();
	void Push(int x);
	int Pop();
	int Peek(int index);
	int StackTop();
	void Display();
};

StackUsingLL::StackUsingLL()
{	
	this->top = nullptr;;	
}

StackUsingLL::~StackUsingLL()
{
	Node* p = top;
	while (top)
	{
		top = top->next;
		delete p;
		p = top;
	}
}

int StackUsingLL::IsFull()
{
	Node* t = new Node;
	int result = t ? 0 : 1;
	delete t;
	return result;
}

int StackUsingLL::IsEmpty()
{
	return top ? 0 : 1;
}

void StackUsingLL::Push(int x)
{
	if (IsFull())
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		Node* t = new Node;
		t->data = x;
		t->next = top;
		top = t;		
	}
}

int StackUsingLL::Pop()
{
	int x = -1;
	if (IsEmpty())
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{
		Node* p = top;
		x = p->data;
		top = top->next;
		delete p;
	}
	return x;
}

int StackUsingLL::Peek(int index)
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		Node* p = top;
		for (int i = 0; p != nullptr && i < index - 1; i++)
		{
			p = p->next;
		}

		if (p != nullptr)
		{
			return p->data;
		}
		else
		{
			return -1;
		}
	}
}

int StackUsingLL::StackTop()
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return top->data;
	}
}

void StackUsingLL::Display()
{
	Node* p = top;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}

//int main()
//{
//	int A[] = { 1, 3, 5, 7, 9 };
//
//	StackUsingLL stk;
//
//	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
//	{
//		stk.Push(A[i]);
//	}
//	
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

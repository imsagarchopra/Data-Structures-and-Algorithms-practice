#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class QueueUsingLL
{
private:
	Node* front;
	Node* rear;
public:
	QueueUsingLL();
	~QueueUsingLL();
	int IsFull();
	int IsEmpty();
	void Enqueue(int x);
	int Dequeue();
	int First();
	int Last();
	void Display();
};

QueueUsingLL::QueueUsingLL()
{
	this->front = this->rear = nullptr;;
}

QueueUsingLL::~QueueUsingLL()
{
	Node* p = front;
	while (front)
	{
		front = front->next;
		delete p;
		p = front;
	}
}

int QueueUsingLL::IsFull()
{
	Node* t = new Node;
	int result = t ? 0 : 1;
	delete t;
	return result;
}

int QueueUsingLL::IsEmpty()
{
	return front ? 0 : 1;
}

void QueueUsingLL::Enqueue(int x)
{
	if (IsFull())
	{
		cout << "Queue is full" << endl;
	}
	else
	{
		Node* t = new Node;
		t->data = x;
		t->next = nullptr;
		if (IsEmpty())
		{
			front = rear = t;
		}
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int QueueUsingLL::Dequeue()
{
	int x = -1;
	if (IsEmpty())
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		Node* p = front;
		x = p->data;
		front = front->next;
		delete p;
	}
	return x;
}

int QueueUsingLL::First()
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return front->data;
	}
}

int QueueUsingLL::Last()
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return rear->data;
	}
}

void QueueUsingLL::Display()
{
	Node* p = front;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}

int main()
{
	int A[] = { 1, 3, 5, 7, 9 };

	QueueUsingLL q;

	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		q.Enqueue(A[i]);
	}
	
	q.Enqueue(11);
	q.Display();

	q.Dequeue();
	q.Display();

	cout << q.First() << endl;
	cout << q.Last() << endl;

}

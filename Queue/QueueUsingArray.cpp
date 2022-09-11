#include <iostream>
using namespace std;
class QueueUsingArray
{
private:
	int size;
	int front;
	int rear;
	int* Q;
public:
	QueueUsingArray(int size);
	~QueueUsingArray();
	int IsFull();
	int IsEmpty();
	void Enqueue(int x);
	int Dequeue();
	int First();
	int Last();
	void Display();
};

QueueUsingArray::QueueUsingArray(int size)
{
	this->size = size;
	this->front = this->rear = -1;
	this->Q = new int[size];
}

QueueUsingArray::~QueueUsingArray()
{
	delete[] Q;
}

int QueueUsingArray::IsFull()
{
	if (rear == size - 1)
	{
		return 1;
	}
	return 0;
}

int QueueUsingArray::IsEmpty()
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}

void QueueUsingArray::Enqueue(int x)
{
	if (IsFull())
	{
		cout << "Queue is full" << endl;
	}
	else
	{
		rear++;
		Q[rear] = x;
	}
}

int QueueUsingArray::Dequeue()
{
	int x = -1;
	if (IsEmpty())
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		x = Q[front + 1];
		front++;
	}
	return x;
}

int QueueUsingArray::First()
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return Q[front + 1];
	}
}

int QueueUsingArray::Last()
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return Q[rear];
	}
}

void QueueUsingArray::Display()
{
	for (int i = front+1; i <= rear; i++) {
		cout << Q[i] << " | " << flush;
	}
	cout << endl;

}

int main()
{
	int A[] = { 1, 3, 5, 7, 9 };

	QueueUsingArray q(sizeof(A) / sizeof(A[0]));

	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		q.Enqueue(A[i]);
	}
	q.Display();
	q.Enqueue(11);
	q.Display();

	q.Dequeue();
	q.Display();

	cout << q.First() << endl;

	cout << q.Last() << endl;

}

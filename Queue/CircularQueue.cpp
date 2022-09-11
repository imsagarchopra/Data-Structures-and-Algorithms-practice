#include <iostream>
using namespace std;
class CircularQueue
{
private:
	int size;
	int front;
	int rear;
	int* Q;
public:
	CircularQueue(int size);
	~CircularQueue();
	int IsFull();
	int IsEmpty();
	void Enqueue(int x);
	int Dequeue();
	int First();
	int Last();
	void Display();
};

CircularQueue::CircularQueue(int size)
{
	this->size = size;
	this->front = this->rear = 0;
	this->Q = new int[size];
}

CircularQueue::~CircularQueue()
{
	delete[] Q;
}

int CircularQueue::IsFull()
{
	if ((rear+1)%size == front)
	{
		return 1;
	}
	return 0;
}

int CircularQueue::IsEmpty()
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}

void CircularQueue::Enqueue(int x)
{
	if (IsFull())
	{
		cout << "Queue is full" << endl;
	}
	else
	{
		rear = (rear + 1) % size;
		Q[rear] = x;
	}
}

int CircularQueue::Dequeue()
{
	int x = -1;
	if (IsEmpty())
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		front = (front + 1) % size;
		x = Q[front];
	}
	return x;
}

int CircularQueue::First()
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return Q[(front + 1) % size];
	}
}

int CircularQueue::Last()
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

void CircularQueue::Display()
{
	int i = front + 1;
	do
	{
		cout << Q[i] << " ";
		i = (i + 1) % size;
	} while (i != (rear + 1) % size);
	cout << endl;
}

int main()
{
	int A[] = { 1, 3, 5, 7, 9 };

	CircularQueue q(sizeof(A) / sizeof(A[0]));

	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		q.Enqueue(A[i]);
	}
	q.Display();
	q.Enqueue(11);
	q.Display();

	q.Dequeue();
	q.Enqueue(11);
	q.Display();

	cout << q.First() << endl;

	cout << q.Last() << endl;

}

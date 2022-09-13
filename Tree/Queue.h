#include <iostream>

class TreeNode
{
public:
	TreeNode* lchild;
	int data;
	TreeNode* rchild;
};

class Node
{
public:
	TreeNode* data;
	Node* next;
};

class Queue
{
private:
	Node* front;
	Node* rear;
public:
	Queue();
	~Queue();
	int IsFull();
	int IsEmpty();
	void Enqueue(TreeNode* x);
	TreeNode* Dequeue();
};

Queue::Queue()
{
	this->front = this->rear = nullptr;;
}

Queue::~Queue()
{
	Node* p = front;
	while (front)
	{
		front = front->next;
		delete p;
		p = front;
	}
}

int Queue::IsFull()
{
	Node* t = new Node;
	int result = t ? 0 : 1;
	delete t;
	return result;
}

int Queue::IsEmpty()
{
	return front ? 0 : 1;
}

void Queue::Enqueue(TreeNode* x)
{
	if (IsFull())
	{
		std::cout << "Queue is full" << std::endl;
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

TreeNode* Queue::Dequeue()
{
	TreeNode* x = nullptr;
	if (IsEmpty())
	{
		std::cout << "Queue is Empty" << std::endl;
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



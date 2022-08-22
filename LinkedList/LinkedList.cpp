
#include <iostream>
#include <stdlib.h>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{

public:
	Node* first;
	LinkedList()
	{
		first = NULL;
	}

	LinkedList(int A[], int n);
	~LinkedList();
	void Display();
	void RecursiveDisplay(Node *t);
};

LinkedList::LinkedList(int A[], int n)
{
	int i;
	Node* last, * t;

	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

LinkedList::~LinkedList()
{
	Node* p = first;

	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

void LinkedList::Display()
{
	Node* p = first;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void LinkedList::RecursiveDisplay(Node *t)
{
	Node* p = t;

	if (p)
	{
		cout << p->data << " ";
		RecursiveDisplay(p->next);
	}	
	cout << endl;
}


int main()
{
	int A[]{ 3,5,7,10,15 };
	
	LinkedList list(A, 5);
	//list.Display();

	list.RecursiveDisplay(list.first);

}

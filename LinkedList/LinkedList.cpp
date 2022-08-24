
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
	int Count();
	int RecursiveCount(Node* t);
	int Add();
	int RecursiveAdd(Node* t);
	int Max();
	int RecursiveMax(Node* t);
	Node* Search(int key);
	Node* RecursiveSearch(Node* t, int key);
	Node* Search_MoveToHead(int key);
	void Insert(int index, int x);
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


int LinkedList::Count()
{
	Node* p = first;

	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}

	return count;
}


int LinkedList::RecursiveCount(Node *t)
{
	Node* p = t;
	
	if (p == 0)
	{
		return 0;				
	}
	return RecursiveCount(p->next) + 1;	
}

int LinkedList::Add()
{
	Node* p = first;

	int sum = 0;
	while (p)
	{		
		sum += p->data;
		p = p->next;
	}

	return sum;
}

int LinkedList::RecursiveAdd(Node* t)
{
	Node* p = t;

	if (p == 0)
	{
		return 0;
	}
	return RecursiveAdd(p->next) + p->data;
}

int LinkedList::Max()
{
	Node* p = first;
	int max = INT16_MIN;

	while (p)
	{
		if (p->data > max)
		{
			max = p->data;
		}		
		p = p->next;
	}

	return max;
}

int LinkedList::RecursiveMax(Node* t)
{
	Node* p = t;
	int max = INT16_MIN;
	int x = 0;

	if (p == 0)
	{
		return max;
	}

	x = RecursiveMax(p->next);
	return x > p->data ? x : p->data;			
}

Node* LinkedList::Search(int key)
{
	Node* p = first;

	while (p)
	{
		if (p->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

Node* LinkedList::RecursiveSearch(Node* t,int key)
{
	Node* p = t;

	while (p)
	{
		if (p == NULL)
			return NULL;
		if (key == p->data)
			return p;
		return RecursiveSearch(p->next, key);
	}
}

Node* LinkedList::Search_MoveToHead(int key)
{
	Node* p = first;
	Node* q = NULL;

	while (p)
	{		
		
		if (p->data == key)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

void LinkedList::Insert(int index, int x)
{
	if (index < 0 || index > Count())
		return;

	Node* p = first;
	Node* t = new Node;

	t->data = x;

	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}

		t->next = p->next;
		p->next = t;
	}
}

int main()
{
	int A[]{ 3,5,7,10,15 };
	
	LinkedList list(A,5);
	//list.Display();
	//list.RecursiveDisplay(list.first);
	//cout << list.Count();
	//cout << list.RecursiveCount(list.first);
	//cout << list.Add();
	//cout << list.RecursiveAdd(list.first);
	//cout << list.Max();
	//cout << list.RecursiveMax(list.first);

	/*if (list.Search(7))
	{
		cout << "Key Found";
	}
	else
	{
		cout << "Key Not Found";
	}*/

	//if (list.RecursiveSearch(list.first,7))
	//{
	//	cout << "Key Found";
	//}
	//else
	//{
	//	cout << "Key Not Found";
	//}

	/*if (list.Search_MoveToHead(7))
	{
		cout << "Key Found"<<endl;
	}
	else
	{
		cout << "Key Not Found"<<endl;
	}*/

	list.Insert(0, 4);
	list.Display();
}

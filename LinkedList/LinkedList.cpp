
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
	Node* second;
	Node* third;
	LinkedList()
	{
		first = NULL;
		second = NULL;
		third = NULL;
	}

	LinkedList(int A[], int n);
	~LinkedList();
	void Create(int A[], int n);
	void Display();
	void Display(Node* p);
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
	void InsertLast(int x);
	void SortedInsert(int x);
	int Delete(int index);
	int IsSorted();
	void RemoveDuplicate();
	void ReverseUsingArray();
	void ReverseUsingSlidingPointers();
	void RecursiveReverse(Node* q, Node* p);
	void Concat(Node* p, Node* q);
	void Merge(Node* p, Node* q);
};

LinkedList::LinkedList(int A[], int n)
{
	int i;
	Node* last, * t;

	first = new Node;
	second = NULL;
	third = NULL;

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

void LinkedList::Create(int A[], int n)
{
	int i;
	Node* last, * t;

	second = new Node;
	second->data = A[0];
	second->next = NULL;
	last = second;

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

void LinkedList::Display(Node *p)
{
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

void LinkedList::InsertLast(int x)
{
	Node* last = first;
	Node* t = new Node;

	t->data = x;

	if (first == NULL)
	{

		first = last = t;
	}
	else
	{

		last->next = t;
		last = t;
	}
}

void LinkedList::SortedInsert(int x)
{
	Node* p = first;
	Node* q = NULL;
	Node* t = new Node;

	t->data = x;
	t->next = NULL;

	if (first == NULL)
	{
		first = t;
	}
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}

		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int LinkedList::Delete(int index)
{
	Node* p = first;
	Node* q = NULL;
	int x = -1;

	if (index < 1 || index > Count())
	{
		return -1;
	}
	
	if (index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;

		delete q;
		return x;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}

		q->next = p->next;
		x = p->data;

		delete p;
		return x;
	}
}

int LinkedList::IsSorted()
{
	Node* p = first;
	int x = INT16_MIN;

	while (p)
	{
		if (p->data < x)
			return 0;

		x = p->data;
		p = p->next;
	}
	return 1;
}

void LinkedList::RemoveDuplicate()
{
	Node* p = first;
	Node* q = first->next;

	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}

void LinkedList::ReverseUsingArray()
{
	Node* q = first;
	int* A, i = 0;

	A = new int[Count()];

	while (q != NULL)
	{
		A[i] = q->data;
		q = q->next;
		i++;
	}

	q = first;
	i--;

	while (q != NULL)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}
}

void LinkedList::ReverseUsingSlidingPointers()
{
	Node* p = first;
	Node* q = NULL;
	Node* r = NULL;
	
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

void LinkedList::RecursiveReverse(Node* q, Node* p)
{	
	if (p != NULL)
	{
		RecursiveReverse(p, p->next);
		p->next = q;
	}
	else
	{
		first = q;
	}
}

void LinkedList::Concat(Node* p, Node* q)
{
	third = first;
	while (p->next != NULL)
	{		
		p = p->next;
	}

	p->next = second;
	second = NULL;
}

void LinkedList::Merge(Node* p, Node* q)
{
	Node* last;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		last->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		last->next = NULL;
	}

	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}

		if (p)
		{
			last->next = p;
		}
		else
		{
			last->next = q;
		}
	}

}

int main()
{
	//int A[]{ 3,5,7,10,15,9 };
	int A[]{ 10,20,30,40,50 };
	int B[]{ 1,2,3,4,5 };
	
	LinkedList list(A,5);
	//list.Display(list.first);
	list.Create(B, 5);
	//list.Display(list.second);

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

	//list.Insert(0, 4);
	//list.InsertLast(10);

	//list.SortedInsert(9);
	//list.Delete(3);

	/*if (list.IsSorted())
	{
		cout << "Sorted";
	}
	else
	{
		cout << "Not Sorted";
	}*/

	//list.RemoveDuplicate();
	//list.Display();

	//list.ReverseUsingArray();
	//list.ReverseUsingSlidingPointers();
	//list.RecursiveReverse(NULL, list.first);
	//list.Display();

	//list.Concat(list.first, list.second);
	list.Merge(list.first, list.second);
	list.Display(list.third);
}

#include <iostream>
#include <stdlib.h>

using namespace std;
class Node
{
public:
	int data;
	Node* next;
};

class CircularLinkedList
{
public:
	Node* head;
	CircularLinkedList()
	{
		head = NULL;
	}
	CircularLinkedList(int A[], int n);
	~CircularLinkedList();
	void Display();
	void Display(Node* p);
	void RecursiveDisplay(Node* t);
	int Count();
	void Insert(int index, int x);
	int Delete(int index);
};

CircularLinkedList::CircularLinkedList(int A[], int n)
{
	int i;
	Node* t, * last;

	head = new Node;

	head->data = A[0];
	head->next = head;
	last = head;

	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

CircularLinkedList :: ~CircularLinkedList()
{
	Node* p = head;

	while (p->next != head)
	{
		p = p->next;
	}

	while (p != head)
	{
		p->next = head->next;
		free(head);
		head = p->next;
	}
	free(head);
}

void CircularLinkedList::Display()
{
	Node* p = head;
	do
	{
		cout << p->data << " ";
		p = p->next;

	} while (p != head);
	cout << endl;
}

void CircularLinkedList::Display(Node *p)
{	
	do
	{
		cout << p->data << " ";
		p = p->next;

	} while (p != head);
	cout << endl;
}

void CircularLinkedList::RecursiveDisplay(Node* p)
{
	static int flag = 0;
	if (p != head || flag == 0)
	{
		flag = 1;
		cout << p->data << " ";
		RecursiveDisplay(p->next);
	}
	flag = 0;
}

int CircularLinkedList::Count()
{
	Node* p = head;

	int count = 0;
	do
	{
		count++;
		p = p->next;
	} while (p != head);

	return count;
}

void CircularLinkedList::Insert(int index, int x)
{
	if (index < 0 || index > Count())
		return;

	Node* p = head;
	Node* t = new Node;

	t->data = x;

	if (index == 0)
	{
		if (head == NULL)
		{
			head = t;
			head->next = head;
		}
		else
		{
			while (p->next != head)
			{
				p = p->next;
			}
			p->next = t;
			t->next = head;
			head = t;
		}
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

int CircularLinkedList::Delete(int index)
{
	Node* p = head;
	Node* q = NULL;
	int x = -1;

	if (index < 1 || index > Count())
	{
		return -1;
	}

	if (index == 1)
	{
		while (p->next != head)
		{
			p = p->next;
		}
		x = head->data;
		if (head == p)
		{
			free(head);
			head = NULL;
		}
		else
		{
			p->next = head->next;
			free(head);
			head = p->next;
		}
	}
	else
	{
		for (int i = 0; i < index - 2; i++)
		{			
			p = p->next;
		}

		q = p->next;
		p->next = q->next;

		x = q->data;

		free(q);	
	}
	return x;
}

//int main()
//{
//	int A[]{ 3,5,7,10,15};
//	CircularLinkedList list(A, 5);
//
//	//list.Display();
//	//list.Display(list.head);
//	//list.RecursiveDisplay(list.head);
//	//cout<< list.Count();
//
//	//list.Insert(2, 4);
//	list.Delete(1);
//	list.Display();
//}
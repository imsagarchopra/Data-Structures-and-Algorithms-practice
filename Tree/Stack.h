#pragma once
#include <iostream>
#include "Node.h"

//class TreeNode
//{
//public:
//	TreeNode* lchild;
//	int data;
//	TreeNode* rchild;
//};

//class Node
//{
//public:
//	TreeNode* data;
//	Node* next;
//};

class Stack
{
private:
	Node* top;
public:
	Stack();
	~Stack();
	int IsFull();
	int IsEmpty();
	void Push(TreeNode* x);
	TreeNode* Pop();
	TreeNode* Peek(int index);
	TreeNode* StackTop();
	void Display();
};

Stack::Stack()
{
	this->top = nullptr;;
}

Stack::~Stack()
{
	Node* p = top;
	while (top)
	{
		top = top->next;
		delete p;
		p = top;
	}
}

int Stack::IsFull()
{
	Node* t = new Node;
	int result = t ? 0 : 1;
	delete t;
	return result;
}

int Stack::IsEmpty()
{
	return top ? 0 : 1;
}

void Stack::Push(TreeNode* x)
{
	if (IsFull())
	{
		std::cout << "Stack Overflow" << std::endl;
	}
	else
	{
		Node* t = new Node;
		t->data = x;
		t->next = top;
		top = t;
	}
}

TreeNode* Stack::Pop()
{
	TreeNode* x = nullptr;
	if (IsEmpty())
	{
		std::cout << "Stack Underflow" << std::endl;
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

TreeNode* Stack::Peek(int index)
{
	if (IsEmpty())
	{
		return NULL;
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
			return NULL;
		}
	}
}

TreeNode* Stack::StackTop()
{
	if (IsEmpty())
	{
		return NULL;
	}
	else
	{
		return top->data;
	}
}

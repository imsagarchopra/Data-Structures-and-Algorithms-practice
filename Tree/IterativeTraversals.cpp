
#include <iostream>
#include "Queue.h"
#include "Stack.h"

class IterativeTraversals
{
private:
	TreeNode* root;
public:
	IterativeTraversals();
	~IterativeTraversals();
	void CreateTree();
	void Preorder(TreeNode* p);
	void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
	void Inorder(TreeNode* p);
	void Inorder() { Inorder(root); }
	void Postorder(TreeNode* p);
	void Postorder() { Postorder(root); }
};

IterativeTraversals::IterativeTraversals()
{
	root = nullptr;
}

IterativeTraversals::~IterativeTraversals()
{
	//TODO:
}

void IterativeTraversals::CreateTree()
{
	TreeNode* p;
	TreeNode* t;
	int x;
	Queue q;

	root = new TreeNode;
	std::cout << "Enter root data: " << std::flush;
	std::cin >> x;

	root->data = x;
	root->lchild = nullptr;
	root->rchild = nullptr;
	q.Enqueue(root);

	while (!q.IsEmpty())
	{
		p = q.Dequeue();

		std::cout << "Enter left child data of " << p->data << ": " << std::flush;
		std::cin >> x;

		if (x != -1)
		{
			t = new TreeNode;
			t->data = x;
			t->lchild = nullptr;
			t->rchild = nullptr;
			p->lchild = t;
			q.Enqueue(t);
		}

		std::cout << "Enter right child data of " << p->data << ": " << std::flush;
		std::cin >> x;

		if (x != -1)
		{
			t = new TreeNode;
			t->data = x;
			t->lchild = nullptr;
			t->rchild = nullptr;
			p->rchild = t;
			q.Enqueue(t);
		}
	}
}

void IterativeTraversals::Preorder(TreeNode* p)
{
	Stack stk;
	while(p != NULL || !stk.IsEmpty())
	{
		if (p != NULL)
		{
			std::cout << p->data << ", " << std::flush;
			stk.Push(p);
			p = p->lchild;
		}
		else
		{
			p = stk.Pop();
			p = p->rchild;
		}
	}
	std::cout << std::endl;
}


void IterativeTraversals::Inorder(TreeNode* p) 
{
	Stack stk;
	while (p != nullptr || !stk.IsEmpty()) 
	{
		if (p != nullptr) 
		{
			stk.Push(p);
			p = p->lchild;
		}
		else 
		{
			p = stk.Pop();
			std::cout << p->data << ", " << std::flush;
			p = p->rchild;
		}
	}
	std::cout << std::endl;
}

void IterativeTraversals::Postorder(TreeNode* p)
{
	Stack stk;
	long int temp;
	while (p != nullptr || !stk.IsEmpty()) 
	{
		if (p != nullptr) 
		{
			stk.Push((long int)p);
			p = p->lchild;
		}
		else
		{
			temp = stk.Pop();
			if (temp > 0)
			{
				stk.Push(-temp);
				p = ((TreeNode*)temp)->rchild;
			}
			else
			{
				std::cout << ((TreeNode*)(-1 * temp))->data << ", " << std::flush;
				p = nullptr;
			}
		}
	}
	std::cout << std::endl;
}

int main() {

	IterativeTraversals bt;

	bt.CreateTree();
	std::cout << std::endl;

	std::cout << "Preorder: " << std::flush;
	bt.Preorder();
	std::cout << std::endl;

	std::cout << "Inorder: " << std::flush;
	bt.Inorder();
	std::cout << std::endl;

	std::cout << "Postorder: " << std::flush;
	bt.Postorder();
	std::cout << std::endl;

	return 0;
}

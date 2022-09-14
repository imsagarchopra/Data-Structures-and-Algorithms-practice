//
//#include <iostream>
//#include "Queue.h"
//
//class Tree
//{
//private:
//	TreeNode* root;
//public:
//	Tree();
//	~Tree();
//	void CreateTree();
//	void Preorder(TreeNode* p);
//	void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
//	void Inorder(TreeNode* p);
//	void Inorder() { Inorder(root); }
//	void Postorder(TreeNode* p);
//	void Postorder() { Postorder(root); }
//	void Levelorder(TreeNode* p);
//	void Levelorder() { Levelorder(root); }
//	int Height(TreeNode* p);
//	int Height() { return Height(root); }
//};
//
//Tree::Tree()
//{
//	root = nullptr;
//}
//
//Tree::~Tree() 
//{
//	//TODO:
//}
//
//void Tree::CreateTree()
//{
//	TreeNode* p;
//	TreeNode* t;
//	int x;
//	Queue q;
//
//	root = new TreeNode;
//	std::cout << "Enter root data: " << std::flush;
//	std::cin >> x;
//
//	root->data = x;
//	root->lchild = nullptr;
//	root->rchild = nullptr;
//	q.Enqueue(root);
//
//	while (!q.IsEmpty())
//	{
//		p = q.Dequeue();
//
//		std::cout << "Enter left child data of " << p->data << ": " << std::flush;
//		std::cin >> x;
//
//		if (x != -1)
//		{
//			t = new TreeNode;
//			t->data = x;
//			t->lchild = nullptr;
//			t->rchild = nullptr;
//			p->lchild = t;
//			q.Enqueue(t);
//		}
//
//		std::cout << "Enter right child data of " << p->data << ": " << std::flush;
//		std::cin >> x;
//
//		if (x != -1)
//		{
//			t = new TreeNode;
//			t->data = x;
//			t->lchild = nullptr;
//			t->rchild = nullptr;
//			p->rchild = t;
//			q.Enqueue(t);
//		}
//	}
//}
//
//void Tree::Preorder(TreeNode* p) 
//{
//	if (p) 
//	{
//		std::cout << p->data << ", " << std::flush;
//		Preorder(p->lchild);
//		Preorder(p->rchild);
//	}
//}
//
//void Tree::Inorder(TreeNode* p) 
//{
//	if (p) 
//	{
//		Inorder(p->lchild);
//		std::cout << p->data << ", " << std::flush;
//		Inorder(p->rchild);
//	}
//}
//
//void Tree::Postorder(TreeNode* p) 
//{
//	if (p) 
//	{
//		Postorder(p->lchild);
//		Postorder(p->rchild);
//		std::cout << p->data << ", " << std::flush;
//	}
//}
//
//void Tree::Levelorder(TreeNode* p) 
//{
//	Queue q;
//	std::cout << root->data << ", " << std::flush;
//	q.Enqueue(root);
//
//	while (!q.IsEmpty()) 
//	{
//		p = q.Dequeue();		
//
//		if (p->lchild) 
//		{
//			std::cout << p->lchild->data << ", " << std::flush;
//			q.Enqueue(p->lchild);
//		}
//
//		if (p->rchild) 
//		{
//			std::cout << p->rchild->data << ", " << std::flush;
//			q.Enqueue(p->rchild);
//		}
//	}
//}
//
//int Tree::Height(TreeNode* p) 
//{
//	int l = 0;
//	int r = 0;
//	if (p == nullptr) 
//	{
//		return 0;
//	}
//
//	l = Height(p->lchild);
//	r = Height(p->rchild);
//
//	if (l > r) 
//	{
//		return l + 1;
//	}
//	else 
//	{
//		return r + 1;
//	}
//}
//
//
////int main() {
////
////	Tree bt;
////
////	bt.CreateTree();
////	std::cout << std::endl;
////
////	std::cout << "Preorder: " << std::flush;
////	bt.Preorder();
////	std::cout << std::endl;
////
////	std::cout << "Inorder: " << std::flush;
////	bt.Inorder();
////	std::cout << std::endl;
////
////	std::cout << "Postorder: " << std::flush;
////	bt.Postorder();
////	std::cout << std::endl;
////
////	std::cout << "Levelorder: " << std::flush;
////	bt.Levelorder();
////	std::cout << std::endl;
////
////	std::cout << "Height: " << bt.Height() << std::endl;
////
////	return 0;
////}

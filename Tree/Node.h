#pragma once
#ifndef Node_H // include guard
#define Node_H
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
#endif

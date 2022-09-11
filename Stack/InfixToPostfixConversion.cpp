#include <iostream>
using namespace std;

class Node
{
public:
	char data;
	Node* next;
};

class Stack2
{
private:

public:

	Stack2();
	~Stack2();
};
Node* top;

Stack2::Stack2()
{
	top = nullptr;;
}

Stack2::~Stack2()
{
	Node* p = top;
	while (top)
	{
		top = top->next;
		delete p;
		p = top;
	}
}

int IsFull()
{
	Node* t = new Node;
	int result = t ? 0 : 1;
	delete t;
	return result;
}

int IsEmpty()
{
	return top ? 0 : 1;
}

void Push(char x)
{
	if (IsFull())
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		Node* t = new Node;
		t->data = x;
		t->next = top;
		top = t;
	}
}

char Pop()
{
	char x = NULL;
	if (IsEmpty())
	{
		cout << "Stack Underflow" << endl;
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

char Peek(int index)
{
	if (IsEmpty())
	{
		return -1;
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

int StackTop()
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		return top->data;
	}
}

void Display()
{
	Node* p = top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}

int IsOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}

int Precedence(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else if (IsOperand)
		return 3;
	else
		return 0;
}

char* InToPost(char* infix) {
	int i = 0, j = 0;
	char* postfix;
	int len = strlen(infix);
	postfix = new char[len + 2];

	while (infix[i] != '\0')
	{
		if (IsOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if (Precedence(infix[i]) > Precedence(top->data))
			{
				Push(infix[i++]);
			}
			else
			{
				postfix[j++] = Pop();
			}
		}
	}

	while (top)
	{
		postfix[j++] = Pop();
	}
	postfix[j] = '\0';
	return postfix;
}

char* InToPost2(char* infix) {
	int i = 0, j = 0;
	char* postfix;
	int len = strlen(infix);
	postfix = new char[len + 2];

	while (infix[i] != '\0')
	{

		if (Precedence(infix[i]) > Precedence(top->data))
		{
			Push(infix[i++]);
		}
		else
		{
			postfix[j++] = Pop();
		}

	}

	while (top)
	{
		postfix[j++] = Pop();
	}
	postfix[j] = '\0';
	return postfix;
}

int isOperand1(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/' ||
		x == '^' || x == '(' || x == ')') {
		return 0;
	}
	return 1;
}

int outPrecedence(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	else if (x == '*' || x == '/') {
		return 3;
	}
	else if (x == '^') {
		return 6;
	}
	else if (x == '(') {
		return 7;
	}
	else if (x == ')') {
		return 0;
	}
	return -1;
}

int inPrecedence(char x) {
	if (x == '+' || x == '-') {
		return 2;
	}
	else if (x == '*' || x == '/') {
		return 4;
	}
	else if (x == '^') {
		return 5;
	}
	else if (x == '(') {
		return 0;
	}
	return -1;
}

char* convert(char* infix) {
	char* postfix = new char[strlen(infix) + 1];

	Stack2 stk;

	int i = 0;
	int j = 0;

	while (infix[i] != '\0') {
		if (isOperand1(infix[i])) {
			postfix[j++] = infix[i++];
		}
		else {
			if (IsEmpty() || outPrecedence(infix[i]) > inPrecedence(top())) {
				stk.push(infix[i++]);
			}
			else if (outPrecedence(infix[i]) == inPrecedence(stk.top())) {
				stk.pop();
			}
			else {
				postfix[j++] = stk.top();
				stk.pop();
			}
		}
	}

	while (!stk.empty() && stk.top() != ')') {
		postfix[j++] = stk.top();
		stk.pop();
	}

	postfix[j] = '\0';

	return postfix;

}

int main()
{
	char infix[] = "a+b*c-d/e";
	Push('#');

	char* postfix = InToPost(infix);
	cout << postfix << endl;

	postfix = InToPost2(infix);

	cout << postfix << endl;


	return 0;
}

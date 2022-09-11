#include <iostream>
#include<cstring>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Stack3 {
private:
	Node* top;
public:
	Stack3();
	~Stack3();
	void push(int x);
	int pop();
	int peek(int index);
	int isEmpty();
	int isFull();
	int StackTop();
};

Stack3::Stack3() {
	top = nullptr;
}

Stack3::~Stack3() {
	Node* p = top;
	while (top) {
		top = top->next;
		delete p;
		p = top;
	}
}

void Stack3::push(int x) {
	Node* t = new Node;
	if (t == nullptr) {
		cout << "Stack Overflow!" << endl;
	}
	else {
		t->data = x;
		t->next = top;
		top = t;
	}
}

int Stack3::pop() {
	Node* p;
	int x = -1;
	if (top == nullptr) {
		cout << "Stack Underflow!" << endl;
	}
	else {
		p = top;
		x = p->data;
		top = top->next;
		delete p;
	}
	return x;
}

int Stack3::isFull() {
	Node* t = new Node;
	int r = t ? 1 : 0;
	delete t;
	return r;
}

int Stack3::isEmpty() {
	return top ? 0 : 1;
}

int Stack3::StackTop() {
	if (top) {
		return top->data;
	}
	return -1;
}

int Stack3::peek(int index) {
	if (isEmpty()) {
		return -1;
	}
	else {
		Node* p = top;

		for (int i = 0; p != nullptr && i < index - 1; i++) {
			p = p->next;
		}

		if (p != nullptr) {
			return p->data;
		}
		else {
			return -1;
		}
	}
}


int isOperand(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/') {
		return 0;
	}
	return 1;
}

int operation(char op, int x, int y) {
	if (op == '+') {
		return x + y;
	}
	else if (op == '-') {
		return x - y;
	}
	else if (op == '*') {
		return x * y;
	}
	else if (op == '/') {
		return x / y;
	}
}

int Evaluate(char* postfix) {
	Stack3 stk;
	int x, y, result;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))
		{
			stk.push(postfix[i] - '0');
		}
		else
		{
			y = stk.pop();
			x = stk.pop();
			result = operation(postfix[i], x, y);
			stk.push(result);
		}
	}

	result = stk.pop();
	return result;
}

int main() {

	char postfix[] = "35*62/+4-";
	cout << Evaluate(postfix) << endl;
	
	return 0;
}
/*
This will be my Stack.h file
This will contain the fundamental function declarations of a standard stack ADT; I am planning on making use of a linked list implementation because of the unknown length of the mathematical expression that must be calculated, I am also planning on making it so that the Stack class is only used when given a string with absolutely no white spaces inside of it (cutting the string until there are no white spaces)

it has come to my observations that I must use a template file to create a stack for taking in doubles, and another to take in the char operands

Recall that the way to use this is:
Stack <type> StackNameHere;

and then to use the functions:
StackNameHere.push


*/
#ifndef __STACK_H__
#define __STACK_H__
#include<iostream>
#include"stackexception.h"

template<class T>
class Stack{
public:
	Stack();
	
	~Stack();
	
	bool empty() const;
	
	void push(T newItem) throw(stack_exception);
	
	void pop() throw(stack_exception);
	
	void pop(T &stackTop) throw(stack_exception);
	
	void top(T &stackTop) const throw(stack_exception);

private:
	struct StackNode{
		T item;
		StackNode *next;
	};
	StackNode	*top_ptr;
};
#include"stack.cpp"

#endif

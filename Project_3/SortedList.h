/*
I will be making a linked list implementation of a list that stores the data types:
string str //which will keep the original, unmodified, infix expression
double result //which will be given the value of a valid infix expression after being converted to postfix and having been calculated in the *calculator* class

As well as having the functions to implement a sorted list (so as to simply print() whenever the program must give out its data in an ascending order of result number

As a summary;
this is an ordered linked list that will nodes containing data of type string and double, as well as a pointer to the next node and a pointer to the very top of the list as well as a pointer to the very bottom of the list. This MUST have a public print() function so that we may access the private member data
*/
#ifndef __SORTEDLIST_H__
#define __SORTEDLIST_H__
#include<iostream>
#include<string>
#include"stackexception.h"

class SortedList{
public:
	SortedList();
	
	~SortedList();
	
	bool empty() const;	//returns true if size == 0
	
	void erase();		//list equivalent of stack.pop() used in destructor
	
	void insert(double num, string expression) throw (list_exception);	//given num and expression, creates a ListNode that will compare the ListNode->result until it finds a node with a greater result than itself and it will use a temp pointer pointing to the previous node (right before it encountered the one with a bigger result) and insert itself there
	// P.S. using throw stack_exception because this is the only function which can get an error of such variety, as as stack_exception will merely print out a string to cerr; I saw no harm in using it in this instance
	
	void print();	//prints out the entire contents of this SORTED list starting from head or top_ptr into the cout stream, erroneous infix expressions go into the cerr stream

	int length();	//returns size

private:
	struct ListNode{
		string orig_string;
		double result;
		ListNode *next;
	};
	int	size;
	ListNode	*top_ptr;
	ListNode	*bot_ptr;
};

#endif

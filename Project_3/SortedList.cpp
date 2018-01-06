#include "SortedList.h"

SortedList::SortedList(){
	top_ptr = NULL;
	bot_ptr = NULL;
}

SortedList::~SortedList(){
	while(!empty())
		erase();
}

bool SortedList::empty() const{
	return size == 0 ? true:false;
}
void SortedList::erase(){
	ListNode *to_delete = top_ptr;
	top_ptr = top_ptr->next;
	to_delete->next = NULL;
	delete to_delete;
}

void SortedList::insert(double num, string expression) throw (list_exception){
	ListNode* newNode = new ListNode;
	if (newNode == NULL){
		throw list_exception("insert could not allocate node");
	}
	newNode->result = num;
	newNode->orig_string = expression;
	
	if (empty()){
		top_ptr = newNode;
		newNode->next = NULL;
		bot_ptr = newNode;
		return;
	}
	
	ListNode* previous = NULL;
	ListNode* current = top_ptr;
	while (current->result < newNode->result && previous != current){
		previous = current;
		current = current->next;
	}
	
	if (previous == NULL){	//if newNode is less than the first entry in the list
		newNode->next = top_ptr;
		top_ptr = newNode;
	}
	
	else if(previous == current){	//if newNode is greater than the last entry in the list
			bot_ptr->next = newNode;
			bot_ptr = newNode;
		}
		else {		//if newNode is neither being inserted last nor first in the list
			newNode->next = current;
			previous->next = newNode;			
		}
}

void SortedList::print(){
	ListNode* current = top_ptr;
	int counter = 0;
	while (counter != size){
		cout << current->result << " = " << current->orig_string << "\n";
		current = current->next;
		counter++;
	}
}

int SortedList::length(){
	return size;
}

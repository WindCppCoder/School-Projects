//#include"stack.h"

template<class T>
 Stack<T>::Stack(){
	top_ptr = NULL;
}

template<class T>
 Stack<T>::~Stack(){
	while (!empty()){
		StackNode* tempNode = top_ptr;
		top_ptr = top_ptr->next;
		tempNode->next = NULL;
		delete tempNode;
	}
}

template <class T>
bool Stack<T>::empty() const{
	return top_ptr == NULL;
}

template <class T>
void Stack<T>::push(T newItem) throw(stack_exception){
	StackNode *newPtr = new StackNode;
	if (NULL == newPtr)
		throw stack_exception("push could not allocate node");
	newPtr->item = newItem;
	
	newPtr->next = top_ptr;
	top_ptr = newPtr;
}

template <class T>	
void Stack<T>::pop() throw(stack_exception){
	if (empty())
		throw stack_exception("stack_exception: stack empty on pop");
	else {
		StackNode *temp = top_ptr;
		top_ptr = top_ptr->next;
		temp->next = NULL;
		delete temp;
	}
}

template <class T>
void Stack<T>::pop(T &stackTop) throw(stack_exception){
	if (empty())
		throw stack_exception("stack_exception: stack empty on pop");
	else{
		stackTop = top_ptr->item;
		StackNode *temp = top_ptr;
		top_ptr = top_ptr->next;
		
		temp->next = NULL;
		delete temp;
	}
}

template <class T>	
void Stack<T>::top(T &stackTop) const throw(stack_exception){
	if (empty())
		throw stack_exception("stack_exception: stack empty on top");
	else
		stackTop = top_ptr->item;
}

#include"pseudoserver.h"

PseudoServer::PseudoServer(){
	size = 0;
	head = NULL;
	tail = NULL;
}

bool PseudoServer::read(istream & is){
	if (insert(is))
	return true;
	
	else 
	return false;
}

bool PseudoServer::extract(string & s){
	if (remove(s))
	return true;
	
	else
	return false;
}

int PseudoServer::queuesize(){
	return size;
}

//check if queue is full; consider a try block around new call and only catching the exception and thus return a false
bool PseudoServer::insert(istream & is){
	string tempLine;
	getline (is, tempLine);
	
	PseudoServerNode* Item;
	try{
	Item = new PseudoServerNode();
	}
	catch (exception& e){
		return false;
	}
	
	if (head == NULL){
		Item->setData(tempLine);
		head = Item;
		tail = Item;
		size++;
		return true;
	}
	
	else {
		Item->setData(tempLine);
		tail->next = Item;
		tail = Item;
		size++;
		return true;
	}
}

bool PseudoServer::remove(string & s){
	if (head == NULL){
		return false;
	}
	else {
		s = head->data;
		PseudoServerNode* temp;
		temp = head->next;
		head->next = NULL;
		delete head;
		head = temp;
		size--;
		return true;
	}
}

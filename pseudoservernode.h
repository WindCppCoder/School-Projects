/*******************************************************************************
  Title          : pseudoservernode.h
  Author         : Windhaw Chia Chang
  Created on     : February 20, 2018
  Description    : The interface file for the nodes pseudoserver.h will be using
  Purpose        : To provide a class which may then be used in the pseudoserver queue
  			through a linked list implementation.
  Usage          : Include this file with client code
  Build with     : gcc -c pseudoservernode.cpp
  Modifications  : 
 
singly linked list with access only allowed at the tail and head
*******************************************************************************/

#ifndef __PSEUDOSERVERNODE_H__
#define __PSEUDOSERVERNODE_H__

#include<iostream>
#include<string>

using namespace std;

class PseudoServerNode{
public:
private:
	/*
	default constructor
	*/
	PseudoServerNode();
	
	/*
	parameter constructor
	*/
	PseudoServerNode(string line);
	
	/*
	parameter constructor for when "next" node is known
	*/
	PseudoServerNode(string line, PseudoServerNode* connection);
	
	/*
	sets the data
	*/
	void setData(string line);
	
	/*
	sets the pointer
	*/
	void setNode(PseudoServerNode* connection);
	
	PseudoServerNode* next;
	string data;
	friend class PseudoServer;
};

#endif /*__PSEUDOSERVERNODE_H__ */

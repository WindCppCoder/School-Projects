/*******************************************************************************
  Title          : pseudoserver.h
  Author         : Windhaw Chia Chang
  Created on     : February 20, 2018
  Description    : The interface file for the pseudoserver class
  Purpose        : To provide a queue which will contain the lines from a text file and act
  			as a buffer for the program; also reports back the size of the
  			queue.
  Usage          : Include this file with client code
  Build with     : gcc -c pseudoserver.cpp
  Modifications  : 
 
 should decide to use either a struct or class Node for each line in PseudoServer
*******************************************************************************/

#ifndef __PSEUDOSERVER_H__
#define __PSEUDOSERVER_H__

#include<iostream>
#include<string>
#include<fstream>
#include"pseudoservernode.h"

using namespace std;

class PseudoServer{
public:
	//default constructor for PseudoServer
	PseudoServer();
	
	/*
	if there is another line of text in the open input stream is, it returns true
	and puts the line onto the end of its internal queue. Otherwise it returns false.
	increases the size variable on every true return.
	istream is should have already been confirmed to be working and accessible
	*/
	bool read(istream & is);
	
	/*
	if the queue is not empty, it removes the front element from the queue,
	stores it into the string parameter passed to it, and returns true.
	Otherwise it returns false.
	decreases the size variable on every true return.
	*/
	bool extract(string & s);
	
	/*
	This returns the number of elements in the queue.
	*/
	int queuesize();
	
private:
	int size;
	
	/*
	used by bool read(istream & is) as a more secure function call
	*/
	bool insert(istream & is);
	
	/*
	used by bool extract(string & s) as a more secure function call
	*/
	bool remove(string & s);
	
	PseudoServerNode* head;
	PseudoServerNode* tail;
};

#endif /*__PSEUDOSERVER_H__ */

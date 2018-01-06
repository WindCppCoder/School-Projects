/******************************************************************************
  Title          : bst.h
  Author         : Windhaw Chia Chang
  Created on     : December 1, 2017
  Description    : Interface for the hotspot class
  Purpose        : 
  Modifications  : December 7

  Notes:
  Abandoned pure virtual...
******************************************************************************/
#ifndef __BST_H__
#define __BST_H__
#include<iostream>
using namespace std;

template <class T>
class BST {
public:
	BST ();				//default
	BST (const BST & tree);		//copy constructor
	~BST ();			//destructor
	
	//Search methods:
	T find (const T& x);
	T findMin ();
	
	//Displaying the tree contents:
	void print (ostream& out);
	
	// Tree Modifiers:
	void clear();	//empty the tree
	void insert( const T& x);	//insert item of type T called x
	void remove( const T& x);	//remove item of type T called x
};

#include "bst.cpp"

#endif

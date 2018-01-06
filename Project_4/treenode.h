/******************************************************************************
  Title          : treenode.h
  Author         : Windhaw Chia Chang
  Created on     : December 1, 2017
  Description    : Interface for the treenode class
  Purpose        : 
  Modifications  : December 5
  			December 7

  Notes:
 
******************************************************************************/
#ifndef __TREENODE_H__
#define __TREENODE_H__

#include<iostream>
#include"hotspot.h"
using namespace std;

class TreeNode{
public:
private:
	//default constructor
	TreeNode();
	
	//parameter constructor; giving it a Hotspot object an connecting it to two 			other TreeNodes by pointer
	TreeNode(const Hotspot &hSpot, TreeNode* left, TreeNode* right);


	Hotspot		HotSpot;
	TreeNode*	Left;
	TreeNode*	Right;
	friend bool operator < (const TreeNode & lt, const TreeNode & rt);
	friend bool operator < (const TreeNode & lt, int id);
	friend bool operator > (const TreeNode & lt, int id);
	friend bool operator == (const TreeNode & lt, int rt);
	friend bool operator == (const TreeNode & lt, const TreeNode & rt);
	friend class HotspotList;
};

#endif // __TREENODE_H__

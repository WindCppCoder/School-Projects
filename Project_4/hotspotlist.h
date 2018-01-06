/******************************************************************************
  Title          : hotspotlist.h
  Author         : Windhaw Chia Chang
  Created on     : December 1, 2017
  Description    : Interface for the hotspotlist class
  Purpose        : 
  Modifications  : December 4
  			December 6
  			December 7

  Notes:
  For fear of breaking; I created wrappers for my functions but for fear
  of breaking the program I have left most of the functions in public
  but I have, hopefully, only used the wrapper functions throughout the
  parts of the program that interact externally anyway
******************************************************************************/
#ifndef __HOTSPOTLIST_H__
#define __HOTSPOTLIST_H__
#include<iostream>
#include"bst.h"
#include"hotspot.h"
#include"treenode.h"
#include<string>
class HotspotList : BST<Hotspot>{
public:
	HotspotList();
	~HotspotList();
	
	/*
	write(ostream&) prints out all hotspots in hotspotlist to the ostream
	@param ostream should already be open and valid
	@pre the objects in hotspotlist should be valid
	@post all objects will be printed to ostream file and this function
		will return the number of objects recorded into ostream
	*/
	int write(ostream& ,TreeNode* );
	
	/*
	insert(const Hotspot&) A single hotspot object is added to the hotspotlist
		preserving the order of the list
	@param Hotspot should not have an ObjectId which is already in hotspotlist
	@pre Hotspot's ObjectId should not be in hotspotlist currently
	@post if Hotspot ObjectId is found in hotspotlist, insert will return 0;
		if not found in hotspotlist, insert will return 1 and insert Hotspot in
		order
	*/
	int insert(const Hotspot& , TreeNode* );
	
	/*
	insert(const HotspotList& hlist) Another hotspotlist object is added to the
		hotspotlist, preserving order
	@param hlist is a valid HotspotList object, which may or may not have
		duplicate hotspot objects when compared to hotspotlist;
		WARNING: do not pass a copy of object type HotspotList as hlist
	@pre hlist should be in proper inorder form
	@post all hotspot objects in hlist will be inserted in proper order into
		hotspotlist, not including the duplicates, and this insert returns
		the total number of objects successfully inserted
	*/
	int insert_node(const TreeNode* hold);
	int insert(const HotspotList & hlist);
	
	/*
	remove(int ID) this removes the hotspot object which has the same ObjectId
		as ID
	@param ID must be a valid integer value
	@pre ID is a valid int value
	@post hotspot objects with ObjectId == ID will be removed and this
		remove function will return either a 1 for success or 0 for failure
	*/
	int remove(int ID, TreeNode*&);
	
	Hotspot findLowest(TreeNode*& h);
	/*
	int size() returns the number of objects in hotspotlist
	@pre there must be a private member value called size which updates itself with
		an update function which will take the return value of remove, 
		insert(Hotspot) and insert(HotspotList) to increment size accordingly
	@post will return the current value of size
	*/
	int get_size();
	void update_size(int num);
	
	/*
	int make_empty() deletes all Hotspot objects in hotspotlist and returns
		the number of objects deleted
	@pre hotspotlist must be fully connected and valid
	@post hotspotlist will have deleted the contents of its collection of
		hotspot objects and set the pointers leading to said objects to NULL
	*/
	int make_empty(TreeNode*& );
	
	void print_single(Hotspot , ofstream& );
	
	void print_ID(int, ofstream&);
	
	
	//bst's virtual functions start here
	/*
	Hotspot find(const Hotspot& x) calls on int find(int ID, Hotspot&, TreeNode*) to 			find if Hotspot x is in hotspotlist or not
	@param make sure Hotspot x is a valid Hotspot object
	@pre this function is used only to find if Hotspot x is in hotspotlist
	@post after calling find(int ID, Hotspot&, TreeNode*) if Hotspot& designation
		matches Hotspot x then return x; else return temp which has 0 for ObjectId
	*/
	Hotspot find (const Hotspot& x);
	
	/*
	Hotspot findMin() is the definition of the virtual T findMin found in bst.h
		this calls upon a private member function which is supposed to find the
		lowest ObjectId in hotspotlist; function name might be 
		void findLowest(TreeNode& h)
		
	@pre  must be called as, findMin(); which will return a Hotspot object
	@post after calling findLowest(TreeNode& h) returns h which is a a pointer which
		indicates where the lowest ObjectId value is, within that Tree
	*/
	Hotspot findMin();
	Hotspot findMine(TreeNode* );
	
	
	/*
	void print (ostream& out) calls on int write(ostream&) and prints out
		all Hotspot objects in hotspotlist
	@pre out must be an open and accessible file
	@post print should have given all its Hotspot objects and ensuing information into
		out file
	*/
	void print (ostream& out);
	
	/*
	void clear() calls on int make_empty(); which will empty hotspotlist
	*/
	void clear();
	
	/*
	void insert(const Hotspot& x) calls on int insert (const Hotspot&) to insert x
		into the hotspotlist
	*/
	void insert(const Hotspot& x);
	
	/*
	void remove(const Hotspot& x) calls on int remove (int ID) to remove the ObjectId
		which matches x's ObjectId from the hotspotlist
	*/
	void remove(const Hotspot& x);
	
	//longitude and latitude
	void traverse(double, double, double, ofstream&);
	
	void traverse(string&, ofstream&);
	
	void in_order(TreeNode*, string&, ofstream&);
	
	void in_order(TreeNode*, double, double, double, ofstream&);
protected:
	/*
	int find(int ID, Hotspot&) searches for ID from ObjectId of all objects
		in hotspotlist and returns the Hotspot object using Hotspot& designation
	@param must be given a valid int value of ID and a valid Hotspot object to store
		information into
	@pre Having a valid ID
	@post returns Hotspot object if and only if ObjectId matches ID, returns 1 if found
		returns 0 if not found
	*/
	int find(int ID, Hotspot&, TreeNode* h);
private:
int	size;
TreeNode	*root;

};


#endif //__HOTSPOTLIST_H__

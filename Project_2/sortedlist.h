#ifndef __SORTEDLIST_H__
#define __SORTEDLIST_H__
#include "hotspotlist.h"
#include "hotspot.h"
#include<iostream>
//template class header for hotspotlist.h

template <class T> 
class SortedList{
public:
	//constructor
	SortedList();
	
	//Used to insert the to_Be_Inserted of class/type T into the sorted list
	int insert(const T & to_Be_Inserted);
	
	//Used to remove all Hotspot records with ObjectId == ID
	int remove(int ID);
	
	//Used to return the number of individual, unique, Hotspot records in the list
	int size();
	
	//Used to empty the list while making all pointers point to NULL
	int make_empty();

//private:
//	Hotspot	*head = NULL;
//	Hotspot	*tail = NULL;
};
#include "sortedlist.cpp"
#endif /* __SORTEDLIST_H__ */

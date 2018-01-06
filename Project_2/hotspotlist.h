#ifndef __HOTSPOTLIST_H__
#define __HOTSPOTLIST_H__
#include<iostream>
#include<fstream>
#include"hotspot.h"
#include"sortedlist.h"

class HotspotList
{
public:
	//Default constructor;
	HotspotList();
	
	/**int write(ostream&) using the given ostream, write out the current list
	onto the ostream and return the number of records written
	*/
	int write(ofstream& s);
	
	/**double distance(double Lat, double Lon, double dist, ostream& s) using given lat and lon, write out all the hotspot records within dist distance from the given coordinates
	*/
	double distance(double Lat, double Lon, double dist, ofstream& s);
	
	/**int insert(const Hotspot &) A single record is added to the hotspot
	in its proper sorted order, provided that its ObjectId is not the same as
	that of an existing record. This should return 1 if successful and 0 if no
	*/
	int insert(const Hotspot & to_Be_Inserted);
	
	/**int insert(const HotspotList & hlist, bool isSorted)
	if hlist is in sorted order of ObjectIds, then isSorted is given as true,
	if that is true, then this inserts every hotspot record from the list
	into the existing hotspot list. The end result is the same as calling the
	above insert() multiple times; however this one merges the lists in a 
	single pass of the list. if isSorted is given as false, this must insert 
	each hotspot record one by one in multiple passes; not inserting any 
	repeat ObjectIds in either case, this must return the number of records 
	successfully inserted into the list
	*/
	int insert(const HotspotList & hlist, bool isSorted);
	
	/**int remove(ObjectId) This removes the Hotspot object from the hotspot
	list whose ObjectId matches the given ObjectId. if none match, it has no
	effect. This returns the number of records deleted, a 1 or 0.
	*/
	int remove(int ID);
	
	// int size() this returns the number of records in the list.
	int size();
	
	/**Searches the hotspot list for the record whose ObjectId matches the 
	given ObjectId. It it finds one, it is copied into the supplied parameter
	If not, the parameter is unchanged. It returns 1 if itfound the record
	and 0 if it did not
	*/
	int retrieve(int ID, Hotspot& Hspot);

	/**int make_empty() this deletes all of the records in the list
	and returns the number of records deleted
	*/
	int make_empty();
	
private:
	SortedList<Hotspot> hotspotlist;

};
#endif /* __HOTSPOTLIST_H__ */

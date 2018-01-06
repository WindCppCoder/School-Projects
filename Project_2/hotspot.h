#ifndef __HOTSPOT_H__
#define __HOTSPOT_H__
#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<string>
#include"hotspotlist.h"
#include"sortedlist.h"
class Hotspot
{
public:
	//Default constructor; fills fields with zeros or null strings;
	Hotspot();
	
	//Constructor that creates Hotspot object from a hotspot file text line
	Hotspot( string line);
	
	// Copy constructor
	Hotspot(const Hotspot & Hspot);
	
	// Constructor to create a Hotspot object from nine separate data values
	Hotspot (int ID, string Borough, string Wifi_Typ, string Prov, string Loc_N, string Loc_A, double Lat, double Long, string SS);
	
	// Sets all nine data members
	void set(int ID, string Borough, string Wifi_Typ, string Prov, string Loc_N, string Loc_A, double Lat, double Long, string SS);
	
	//Gets all nine data members
	void get(int& ID, string& Borough, string& Wifi_Typ, string& Prov, string& Loc_N, string& Loc_A, double& Lat, double& Long, string& SS);
	
	/** print() - prints the hotspot data onto the given ostream
	* @param ostream s [inout] ostream openered for writing
	* @pre the object has valid data
	*@post if the object has valid data, then it is written to ostream
	*	in CSV format and the ostrema is updated
	*/
	void print( ofstream & s);
	
	void printID(ofstream& s);
	
	/** Two friend comparison operators:
	* bool operator < (lt, rt) is true if and only if:
	*	lt.ObjectId < rt.ObjectId
	* bool operator == (lt, rt) is true if and only if:
	*	lt.ObjectId == rt.ObjectId
	*/
	friend bool operator < (const Hotspot & lt, const Hotspot & rt);
	//just make it so that when '<' is between 2 Hotspot objects, they can access the private member functions
	friend bool operator == (const Hotspot & lt, const Hotspot & rt);
	
	friend bool operator == (const Hotspot & lt, int ID); //for when searching for specific ObjectId
	
	friend bool operator != (const Hotspot & lt, const Hotspot & rt); //for when using Curr.next != head.next to run a loop through linked list
	Hotspot* next;
	Hotspot* prev;
private:

	int 	ObjectId;
	string	Boro;
	string	Wifi_Type;
	string	Provider;
	string	Loc_Name;
	string	Loc_Address;
	double	Lati;
	double	Longi;
	string	SSID;
	
	Hotspot* next;
	Hotspot* prev;
};

#endif /* __HOTSPOT_H__ */

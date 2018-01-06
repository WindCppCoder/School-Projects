/******************************************************************************
  Title          : hotspot.h
  Author         : Windhaw Chia Chang
  Created on     : December 1, 2017
  Description    : Interface for the hotspot class
  Purpose        : 
  Modifications  : December 4
  			December 7

  Notes:
 
******************************************************************************/
#ifndef __HOTSPOT_H__
#define __HOTSPOT_H__
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<cmath>

using namespace std;

class Hotspot{
public:
	//default constructorl fills fields with zeros or null strings
	Hotspot();
	
	//constructor that creates a Hotspot object from a hotspot file text line
	Hotspot(const string);
	
	//copy constructor
	Hotspot(const Hotspot&);

	//Constructor to create a Hotspot object from nine separate data values
	Hotspot(int, string, string, string, string, string, double, double, string);
	
	//sets all nine data members
	void set(int, string, string, string, string, string, double, double, string);
	
	//gets all nine data members
	void get(int&, string&, string&, string&, string&, string&, double&, double&, string&);
	
	void get_int(int&);
	
	void get_lat_lon(double& lat, double& lon);
	
	void get_boro( string& );
	
	void set_int(int);
	
	/*prints the hotspot data onto the given ostream
	@param ostream s [inout] ostream opened for writing
	@pre the object has valid data
	@post if the object has valid data, then it is written to ostream 
		in CSV format and the ostream is updated
	*/
	void print(ostream & s);
	
	//this is used to just print it to cout (testing purposes)
	void print();
	
	//latitude and longitude
	double calc_dist(double , double, double, double);
	
	friend bool operator < (const Hotspot & lt, const Hotspot & rt);
	friend bool operator < (const Hotspot& lt, int );
	friend bool operator > (const Hotspot& lt, int );
	friend bool operator == (const Hotspot & lt, int );
	friend bool operator == (const Hotspot & lt, const Hotspot & rt);
	
private:
	int	ObjectId;
	string 	Boro;
	string 	Type;
	string	Provider;
	string	Name;
	string 	Location;	//a valid file line must have " " marks or it is invalid and will be disregarded
	double	Latitude;
	double	Longitude;
	string	SSID;
};

#endif //__HOTSPOT_H__

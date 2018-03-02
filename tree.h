/*******************************************************************************
  Title          : tree.h
  Author         : Windhaw Chia Chang
  Created on     : February 23, 2018
  Description    : The interface file for the tree class
  Purpose        : Will take a string from the pseudoserver (csv format) and convert it
  			so as to take a subset of the information and storing it to be
  			written out or printed to a specified file.
  Usage          : Include this file with client code
  Build with     : gcc -c tree.cpp
  Modifications  : 
*******************************************************************************/
#ifndef __TREE_H__
#define __TREE_H__

#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>

using namespace std;

class Tree{
public:
	//a constructor for the class that takes a string from a csv file.
	Tree(const string& treedata);

	/*
	This prints a Tree object onto the given ostream. Each of the members of the Tree 
	object should be printed in the exact same order as they are described in the 
	table above, e.g., with the tree spc_common name first, then the tree_id. Fields 
	should be separated by commas in the output stream.
	*/
	friend ostream& operator << (ostream & os, const Tree & t);

	/*
	This creates a string from the data members of the Tree object, in the exact same 
	order as they are described in the table above. The members in the string are 
	separated by tab characters.
	*/
	string write();

private:
	string species;	//10th column in the csv file
	int ID; //1st column in the csv file
	int dbh; //4th column in the csv file
	string status; //7th column in the csv file
	string health; //8th column in the csv file
	string address; //25th column in the csv file
	string boro; //30th column in the csv file
	int zipcode; //26th column in the csv file
	double lat; //38th column in the csv file
	double longi; //39th column in the csv file
	
	
};

#endif /*__TREE_H__*/

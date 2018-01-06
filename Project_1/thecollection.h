/******************************************************************************
  Title          : thecollection.h
  Author         : Windhaw Chia Chang
  Created on     : September  24, 2017
  Description    : Interface for the BabyCollection class
  Purpose        : The BabyCollection class represents a BabyCollection object
  Modifications  : September 25, 2017
                   added various functions

  Notes:
  This header file contains all the call functions for the BabyCollection class
  as well as a friend void Print to allow babyname objects to use private data
 
******************************************************************************/
#ifndef __THECOLLECTION_H__
#define __THECOLLECTION_H__
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include"command.h"
#include"babyname.h"
#include"sorting.h"

class BabyCollection
{
	public:
	/**	BabyCollection() A default constructor for the class
	
	*/
		BabyCollection();
		
	/**
		getLimit() simply returns the size of the vector, to be used as a "limit" when using loops in the program that 			interact with the vectors.
		@pre	None
		@post	None
		@return An integer which represents the size of all vectors within this class
	*/
		int getLimit();
	/**
		getCollection (int i, int &year, Gender &gender, Ethnicity &ethnicity, string &name, int &count, int &rank) passes 			variables by reference to grab the data needed from the private section of this class
		@pre int i is the index (read "shelf") in which the information is stored on these separate vectors
		int &year,Gender &gender, Ethnicity &ethnicity, string &name, int &count, int &rank are from appropriate variables
		when called so as to take the correct format of information from vectors
		@post int i is unchanged, rest of the params take the respective vector[i] information back to their variables
		
	*/
		
		void getCollection(int i, int &year, Gender &gender, Ethnicity &ethnicity, string &name, int &count, int &rank);
	/**
		addCollection(string line) takes the input from babynames.csv file and converts them into a format appropriate for
		inserting into the vectors of this object
		@pre line must contain the entire line from the babynames.csv file
		@post line has been cut up into, year, gender, ethnicity, name, count and rank; in that order and put into their
		respective vectors, kept on the same "shelf" via push_back
	*/
		void addCollection(string line);
	/**
		sortByRank() re-organizes all vectors and keeps individual information on ordered "shelves", and sorts by rank 			according to their own categories
		@pre Assumes there is something to sort
		@post vectors have been sorted by rank according to assignment description
	*/
		void sortByRank();
	/**
		sortByName() re-organizes all vectors and keeps individual information on ordered "shelves", and sort by name
		according to their own categories
		@pre Assumes there is something to sort
		@post vectors have been sorted by name according to assignment description
	*/
		void sortByName();
	/**
		getMax(Gender g, int y, Ethnicity e) collects the records of all babies with the highest count (multiple in the case 			of ties) and prints it out into a file named results in the same format as when they were taken into this object
		@pre Gender g must be the appropriate type, as well as int y and Ethnicity e
		@post command will organize, collect and print out the appropriate individual records to a file named "results"
	*/	
		void getMax(Gender g, int y, Ethnicity e);
	/**
		getCount(string n, int y, Ethnicity e) collects the records of all babies of name n, of year y and ethnicity e; counts
		all those babies and prints out "There were count babies born in the given year(s) whose mother was of the given
		ethnicity with the name n"
		@pre string n must be a valid name, int y must be a valid year value and Ethnicity e must be a valid ethnicity value
		@post command will count through the collection of vectors to find the babies with the name n and print out a pre-set 
		message displaying the amount of babies born with the name n in the given years and under given ethnicity
	*/
		void getCount( string n, int y, Ethnicity e);
	/**
		friend void Print( ostream & s) gives rights for Babyname.Print to access the private section of this object
	*/
		friend void Print( ostream & s);
		
	private:
		vector<int>		Baby_Year;
		vector<Gender>		Baby_Gender;
		vector<Ethnicity>	Mother_Ethnicity;
		vector<string>		Baby_Name;
		vector<int>		Baby_Name_Count;
		vector<int>		Baby_Name_Rank;
};
#endif /* __THECOLLECTION_H__ */

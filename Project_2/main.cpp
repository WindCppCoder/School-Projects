/******************************************************************************
  Title          : main.cpp
  Author         : Windhaw Chia Chang
  Created on     : October 23, 2017
  Description    : Implementation for the main
  Purpose        : declaration of objects, opening and closing files, linking
  			all the various files together
  Modifications  : 

  Notes:
  This file is meant to include all other .h files used in Project_2
  opening given files and calling functions from objects to create the
  desired effects based on the commands of a given file
 
******************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include"hotspot.h"
#include"hotspotlist.h"
#include"sortedlist.h"
#include"sortedlist.cpp"
#include"command.h"
using namespace std;
/**
	int main( int argc, char * argv[]) takes the files input on the
	command line to insert parameters and commands for the executable
	@pre must have a total of 3 "arguments" from the command line, 
	first one being the executable, the other 2 being the files
	@post hopefully creates desired effect from commands
*/
int main( int argc, char * argv[]){
/**
	makes certain there are at least 3 "arguments" from the command line
	@pre must have some input from command line
	@post if there are not enough arguments from the command line
	the program exits
*/
if (argc < 3){
	cerr << argv[0] << "	inputFileName	commandFileName  \n";
	exit(1);
}
string line, numHold;

/**
	these variables are used to call upon get_args from Command object and 		help to access the private data of Command object and bring it into main
	to be used as parameters for other functions
	
	**hotspotList, commandFile are used for command line inputs**
*/
ifstream hotspotList, commandFile, inputFile;
ofstream outputFile;
string toFile, fromFile;
double latitude, longitude, distance;
bool result;

/**
	these next 2 functions simply make sure the files can be opened
*/
hotspotList.open(argv[1]);
if (hotspotList.fail()){
	cerr << "The file " << argv[1] << " cannot be opened.\n";
	exit;
}

commandFile.open(argv[2]);
if (commandFile.fail()){
	cerr << "The file " << argv[2] << " cannot be opened.\n";
	exit;
}
HotspotList Library;
Hotspot Book, copy;
Command Librarian;

/**
	this populates the linked list "hotspotlist" inside Library with objects of type Hotspot
*/
while (!hotspotList.eof()){
	getline (hotspotList, line);
	Book(line);
	Hotspot BookC(Book);
	Library.insert(BookC);
}

while (!commandFile.eof()){
	Librarian.get_next(commandFile);
	
	if (Librarian.type_of() == write_cmmd){
		Librarian.get_args(fromFile, toFile, latitude, longitude, distance, result);
		outputFile.open(toFile.c_str());
		Library.write(outputFile);
		outputFile.close();
	}
	if (Librarian.type_of() == save_by_id_cmmd){
		Librarian.get_args(fromFile, toFile, latitude, longitude, distance, result);
		inputFile.open(fromFile.c_str());
		outputFile.open(toFile.c_str());
		while(!inputFile.eof()){
			int num;
			getline (inputFile, numHold);
			num = atoi (numHold.c_str());
			Library.retrieve(num, copy);
			copy.print(outputFile);
		}
		inputFile.close();
		outputFile.close();
	}
	
	if (Librarian.type_of() == save_by_loc_cmmd){
		Librarian.get_args(fromFile, toFile, latitude, longitude, distance, result);
		outputFile.open(toFile.c_str());
		Library.distance( latitude, longitude, distance, outputFile);
		outputFile.close();
	}
	
	if (Librarian.type_of() == insert_cmmd){
		Librarian.get_args(fromFile, toFile, latitude, longitude, distance, result);
		inputFile.open(fromFile.c_str());
		while (!inputFile.eof()){
			getline (inputFile, line);
			Book(line);
			Hotspot Bookc(Book);
			Library.insert(BookC);
		}
		inputFile.close();
	}
	
	if (Librarian.type_of() == delete_by_id_cmmd){
		Librarian.get_args(fromFile, toFile, latitude, longitude, distance, result);
		inputFile.open(fromFile.c_str());
		while (!inputFile.eof()){
			int num;
			getline (inputFile, numHold);
			num = atoi (numHold.c_str());
			Library.remove(num);
		}
		inputFile.close();
	}
}

}

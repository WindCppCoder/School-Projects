/******************************************************************************
  Title          : main.cpp
  Author         : Windhaw Chia Chang
  Created on     : December 1, 2017
  Description    : Implementation for the main
  Purpose        : declaration of objects, opening and closing files, linking
  			all the various files together
  Modifications  : December 4
  			December 5
  			December 6
  			December 7
  
  Usage		:	g++ -c hotspot.cpp
  			g++ -c hotspotlist.cpp
  			g++ -c treenode.cpp
  			g++ main.cpp hotspot.o hotspotlist.o treenode.o command.o

  Notes:
  This file is meant to include all other .h files used in Project_4
  opening given files and calling functions from objects to create the
  desired effects based on the commands of a given file
 
******************************************************************************/

#include"hotspot.h"
#include"treenode.h"
#include"hotspotlist.h"
#include"command.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main( int argc, char * argv[]){
	if (argc < 3){
		cerr << argv[0] << "	inputFileName	commandFileName  \n";
		exit(1);
	}
	
	ifstream hotspotList, commandFile, inputFile;
	ofstream outputFile;
	string toFile, fromFile, line;
	double latitude, longitude, distance;
	bool result;
	
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
	
	HotspotList Tree;
	Hotspot temp;
	LOOP:
	try{
		while (!hotspotList.eof()){
			getline (hotspotList, line);
			temp = Hotspot(line);
			Tree.insert(temp);
		}
	}
	catch (Hotspot exception){
		goto LOOP;
	}
	Command Orders;
	Boro_type holder;
	while (!commandFile.eof()){
		if (Orders.get_next(commandFile)){
			Orders.get_args(fromFile, toFile, latitude, longitude, distance, holder, result);
			if (Orders.type_of() == write_cmmd){
				outputFile.open(toFile.c_str());
				if (outputFile.fail()){
					cerr << "File name " << toFile << " would not open.\n";
					exit;
				}
				else{
					Tree.print(outputFile);
				}
				outputFile.close();
			}
			if (Orders.type_of() == save_by_id_cmmd){
				inputFile.open(fromFile.c_str());
				if (inputFile.fail()){
					cerr << "File " << fromFile << " would not open.\n";
					exit;
				}
				while(!inputFile.eof()){
					getline(inputFile, line);
					int ID = atoi(line.c_str());
					temp.set_int(ID);
					if (Tree.find(temp) == 0){

					}
					else {
						Tree.print_single(temp, outputFile);
					}
				}
				inputFile.close();
			}
			if (Orders.type_of() == save_by_loc_cmmd){
				outputFile.open(toFile.c_str());
				if (outputFile.fail()){
					cerr << "File name " << toFile << " would not open.\n";
					exit;
				}
				Tree.traverse(longitude, latitude, distance, outputFile);
				outputFile.close();
			}
			if (Orders.type_of() == save_by_boro_cmmd){
				outputFile.open(toFile.c_str());
				if (outputFile.fail()){
					cerr << "File name " << toFile << " would not open.\n";
					exit;
				}
				string tempStr;
				if (holder == MN){
					tempStr = "MN";
					Tree.traverse(tempStr, outputFile);
				}
				if (holder == BX){
					tempStr = "BX";
					Tree.traverse(tempStr, outputFile);
				}
				if (holder == BK){
					tempStr = "BK";
					Tree.traverse(tempStr, outputFile);
				}
				if (holder == QU){
					tempStr = "QU";
					Tree.traverse(tempStr, outputFile);
				}
				if (holder == SI){
					tempStr = "SI";
					Tree.traverse(tempStr, outputFile);
				}
				else{
					cerr << "BAD_BORO command\n";
				}
				outputFile.close();
			}
			if (Orders.type_of() == insert_cmmd){
				inputFile.open(fromFile.c_str());
				if (inputFile.fail()){
					cerr << "The input file for insert_cmmd cannot be opened.\n";
					exit;
				}
				while(!inputFile.eof()){
					getline (inputFile, line);
					temp = Hotspot(line);
					Tree.insert(temp);
				}
				inputFile.close();
			}
			if (Orders.type_of() == delete_by_id_cmmd){
				inputFile.open(fromFile.c_str());
				if (inputFile.fail()){
					cerr << "The input file for delete_by_id_cmmd cannot be opened.\n";
					exit;
				}
				while(!inputFile.eof()){
					getline (inputFile, line);
					int tempID = atoi(line.c_str());
					temp.set_int(tempID);
					Tree.remove(temp);
				}
				inputFile.close();
			}
		}
	}

}

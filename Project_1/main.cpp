/******************************************************************************
  Title          : main.cpp
  Author         : Windhaw Chia Chang
  Created on     : September  24, 2016
  Description    : Implementation for the main
  Purpose        : declaration of objects, opening and closing files, linking
  			all the various files together
  Modifications  : September 25, 2017
                   New variables added
                   September 26, 2017
                   Included many more files and libraries
                   September 27, 2017
                   New commands added
                   September 28, 2017
                   Adjusted old commands

  Notes:
  This file is meant to include all other .h files used in Project_1
  opening given files and calling functions from objects to create the
  desired effects based on the commands of a given file
 
******************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"command.h"
#include"babyname.h"
#include"sorting.h"
#include"thecollection.h"
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
string line;

/**
	these variables are used to call upon get_args from Command object and help
	to access the private data of Command object and bring it into main
	to be used as parameters for other functions
*/
int OYear, OCount, ORank;
Ethnicity OEthnicity;
Gender OGender;
string OName, OutputFileName;
bool OResult;

/**
	calling Command class overlord
		Babyname class minion
		BabyCollection hive
	constructors to create the objects to be used in this program
*/
Command overlord;
Babyname minion;
BabyCollection hive;

/**
	creates input streams called babyList, and commandFile
	creates output stream called OutputFile; to be used for the print tofilename
*/
ifstream babyList, commandFile;
ofstream OutputFile;

/**
	these next 2 functions simply make sure the files can be opened
*/
babyList.open(argv[1]);
if (babyList.fail()){
	cerr << "The file " << argv[1] << " cannot be opened.\n";
	exit;
}

commandFile.open(argv[2]);
if (commandFile.fail()){
	cerr << "The file " << argv[2] << " cannot be opened.\n";
	exit;
}

/**
	this populates the vectors of object hive with the list of individuals from the file babyList is connected to
*/

while( getline (babyList, line) ){
	if (line != ""){
		hive.addCollection(line);
	}
}

/**
	if commandFile still contains lines and can still be accessed,
	functions inside this loop will follow the commands accordingly
*/
while ( commandFile.good() ){	//print = 0, sort_byname, sort_byrank, getmax, getcount, bad_command,
	overlord.get_next(commandFile);
	
/**
	if command_type is print, the program will get the arguments from current overlord
	object and transfer from the private data of overlord into variables that can be used
	by main
*/
	if (overlord.type_of() == 0){
		overlord.get_args(OutputFileName, OName, OYear, OGender, OEthnicity, OResult);
		const char * c = OutputFileName.c_str();
		OutputFile.open (c);
		minion.Print(OutputFile);
		OutputFile.close();
		exit;
	}
	
/**
	if command_type is sort_byname or sort_byrank these will act accordingly after
	getting the arguments from the object overlord
*/
	if (overlord.type_of() == 1 || overlord.type_of() == 2){
		overlord.get_args(OutputFileName, OName, OYear, OGender, OEthnicity, OResult);
		if (overlord.type_of() == 1){
			hive.sortByName();
			exit;
		}
		if (overlord.type_of() == 2){
			hive.sortByRank();
			exit;
		}
	}

/**
	if command_type is getMax; read the getMax function comments in thecollection.h
*/
	if (overlord.type_of() == 3){
		overlord.get_args(OutputFileName, OName, OYear, OGender, OEthnicity, OResult);
		hive.getMax(OGender, OYear, OEthnicity);
		exit;
	}
/**
	if command_type is getcount; read the getCount function comments in thecollection.h
*/
	if (overlord.type_of() == 4){
		overlord.get_args(OutputFileName, OName, OYear, OGender, OEthnicity, OResult);
		hive.getCount(OName, OYear, OEthnicity);
		exit;
	}

	if (overlord.type_of() == bad_command){
		cerr << "command file " << argv[2] << " had a bad command \n";
		exit (2);
	}
}










}

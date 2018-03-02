/*******************************************************************************
  Title          : main.cpp
  Author         : Windhaw Chia Chang
  Created on     : February 23, 2018
  Description    : The main file where the rest of the files for Project1 will be linked
  			through.
  Purpose        : To provide function calls to accomplish task
  Build with     : gcc pseudoserver.cpp tree.o pseudoserver.o pseudoservernode.o bitcoin.o
  Modifications  : 
  			February 26: completed the argv[] checks and use of bitcoin for
  				project uses to be implemented. COMPLETED
 
********************************************************************************/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include"pseudoserver.h"
#include"pseudoservernode.h"
#include"tree.h"
#include"bitcoin.h"

using namespace std;

int main(int argc, char * argv[]){
	//check to see if executable name and 3 arguments were provided
	if (argc < 4){
		cerr << argv[0] << " 	csvFileName	outputFileName	Seed \n";
		exit(1);
	}
	
	ifstream csvFile;
	ofstream outputFile;
	istringstream seed_origin(argv[3]);
	int seed;
	csvFile.open(argv[1]);
	if (csvFile.fail()){	//if csv file cannot be opened
		cerr << "The file " << argv[1] << " cannot be opened.\n";
		exit(2);
	}
	
	outputFile.open(argv[2]);
	if (outputFile.fail()){	//if output file cannot be opened
		cerr << "The file " << argv[2] << " cannot be opened.\n";
		exit(2);
	}
	
	if (!(seed_origin >> seed && seed_origin.eof())){ //if third argument is not an integer
		cerr << "The third argument " << argv[3] << " is not an integer.\n";
		exit(2);
	}
	
	
	int max_queue = 0, empty_queue_count = 0, queue_on_eof = 0, iterations = 0;
	double average_queue = 0.0;
	PseudoServer queue;
	
	Bitcoin mycoin(seed);	//seeded the bitcoin
	while (!csvFile.eof()){
		string extracted;	//string to be used for PseudoServer's extract
		if (mycoin() == 0){
			if (queue.extract(extracted)){	//if queue is not empty
				Tree treeHolder(extracted);
				outputFile << treeHolder;
				average_queue += queue.queuesize();
				iterations++;
				if (max_queue < queue.queuesize())
					max_queue = queue.queuesize();
			}
			else {				//if queue is empty
				empty_queue_count++;
				iterations++;
			}
		}
		else {	//if bitcoin is 1
			if (queue.read(csvFile)){
				average_queue += queue.queuesize();
				iterations++;
				if (max_queue < queue.queuesize())
					max_queue = queue.queuesize();
			}
		}
	}
	/*
	The following is to compensate for having used .eof()
	*/
	average_queue -= queue.queuesize();
	queue_on_eof = queue.queuesize()-1;
	iterations--;
	
	
	for (int i = 0; i < queue_on_eof; i++){
		string extracted;
		if (queue.extract(extracted)){
			Tree treeHolder(extracted);
			outputFile << treeHolder;
		}
	}
	cout << "average queue size: " << average_queue/iterations << endl;
	cout << "maximum queue size: " << max_queue << endl;
	cout << "empty queue count: " << empty_queue_count << endl;
	cout << "queue size on eof: " << queue_on_eof << endl;
}

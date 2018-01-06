#include<iostream>
#include<fstream>
#include<string>
#include"SortedList.h"
#include"stack.h"
#include"calculator.h"
#include"stackexception.h"
using namespace std;

int main( int argc, char * argv[]){

	SortedList List;
	Calculator Calc;
	string Original_String;
	if (argc == 1){
		cout << "Input an infix expression to be calculated, to cease program and receive the output, do not enter another expression: \n";
		while (cin != ""){
			cin >> Original_String;

			
			//call calculator function at this point to create a result
			double result = Calc.calculate(Original_String);
			
			List.insert(result, Original_String);
		}
		List.print();
	}
	else if (argc == 2){
		ifstream infixFile;
		double result;
		
		infixFile.open(argv[1]);
		if (infixFile.fail()){
			cerr << "The file " << argv[1] << " cannot be opened.\n";
		}
		
		while (!infixFile.eof()){
			getline (infixFile, Original_String);
			result = Calc.calculate(Original_String);
			List.insert(result, Original_String);
		}
		List.print();
	}
	
			else
				cerr << "Invalid command line arguments.\n";
}

#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include<iostream>
#include<string>
#include"stackexception.h"
#include"stack.h"
#include<stdlib.h>

//PEMDAS order of operations
enum Tokens { subtraction, addition, division, multiplication, exponent, openingParenthesis, closingParenthesis};

class Calculator{

public:
	Calculator();
	
	double calculate(const string& expression);


};

#endif

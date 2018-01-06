/* this is where my parsing and calculating of the infix expressions must be done; this is the calculator.h file

think about how to implement this after rearranging the Original_String into a valid postfix state
OR
implementing this while calculating the Original_String as an infix expression

*/
#include"calculator.h"

//PEMDAS order of operations
	Calculator::Calculator(){}

	double Calculator::calculate(const string &expression){
		string temp;

		for (int i = 0; i < expression.length(); i++){
			if ((expression[i] < 'z' && expression[i] > 'a') || (expression[i] < 'Z' && expression[i] > 'A')){
				throw stack_exception("infix expression invalid");
			}
			
			if (expression[i] != ' '){
				temp = temp + expression[i];
			}
			
		}
			
		int openingCount, closingCount;	//keep track of the amount of ( and )
		for (int i = 0; i < temp.length(); i++){
			if (temp[i] == '(')
				openingCount++;
			if (temp[i] == ')')
				closingCount++;
		}
			
		if (openingCount != closingCount){
			throw stack_exception("infix expression invalid");
		}
			
		Stack <string> postfixStack;
		Stack <char> operatorStack;
		
		for (int i = 0; i < temp.length(); i++){
			char tempChar;
			string tempStr;
			if (temp[i] == '+' || temp[i] == '-' || temp[i] == '/' || temp[i] == '*' || temp[i] == '^' || temp[i] == '(' || temp[i] == ')'){
				Tokens Token, token1, token2;
				if (temp[i] == '+')
					Token = addition;
				
				else if (temp[i] == '-')
					Token = subtraction;
				else if (temp[i] == '/')
					Token = division;	
				else if (temp[i] == '*')
					Token = multiplication;
				else if (temp[i] == '^')
					Token = exponent;
				else if (temp[i] == '(')
					Token = openingParenthesis;
				else if (temp[i] == ')')
					Token = closingParenthesis;
					
				
				switch (Token){
				
				case 6:
					char stackTop;
					
					operatorStack.top(stackTop);
					while (stackTop != '('){
						operatorStack.pop(tempChar);
						tempStr = tempChar;
						postfixStack.push(tempStr);
						operatorStack.top(stackTop);
					}
					operatorStack.pop(); //at the end of this while loop, operatorStack.top() == '('so get rid of it from the operatorStack
					break;
				case 5:
					operatorStack.push(temp[i]);	//just push '(' into operator stack
					break;
					
				case 4:
					operatorStack.top(tempChar);
					if (temp[i] == '+')
						token1 = addition;
					else if (temp[i] == '-')
						token1 = subtraction;
					else if (temp[i] == '/')
						token1 = division;	
					else if (temp[i] == '*')
						token1 = multiplication;
					else if (temp[i] == '^')
						token1 = exponent;
					
					token2 = exponent;
					while ( !operatorStack.empty() && (token1 <= token2 )){
						operatorStack.pop(tempChar);
						tempStr = tempChar;
						postfixStack.push(tempStr);
					}
					break;
					
				case 3:
					operatorStack.top(tempChar);
					if (temp[i] == '+')
						token1 = addition;
					else if (temp[i] == '-')
						token1 = subtraction;
					else if (temp[i] == '/')
						token1 = division;	
					else if (temp[i] == '*')
						token1 = multiplication;
					else if (temp[i] == '^')
						token1 = exponent;
					
					token2=multiplication;
					while ( !operatorStack.empty() && (token1 <= token2 )){
						operatorStack.pop(tempChar);
						tempStr = tempChar;
						postfixStack.push(tempStr);
					}
					operatorStack.push(temp[i]);
					break;
				case 2:
					operatorStack.top(tempChar);
					if (temp[i] == '+')
						token1 = addition;
					else if (temp[i] == '-')
						token1 = subtraction;
					else if (temp[i] == '/')
						token1 = division;	
					else if (temp[i] == '*')
						token1 = multiplication;
					else if (temp[i] == '^')
						token1 = exponent;
					
					token2=division;
					while ( !operatorStack.empty() && (token1 <= token2 )){
						operatorStack.pop(tempChar);
						tempStr = tempChar;
						postfixStack.push(tempStr);
					}
					operatorStack.push(temp[i]);
					break;
				case 1:
					operatorStack.top(tempChar);
					if (temp[i] == '+')
						token1 = addition;
					else if (temp[i] == '-')
						token1 = subtraction;
					else if (temp[i] == '/')
						token1 = division;	
					else if (temp[i] == '*')
						token1 = multiplication;
					else if (temp[i] == '^')
						token1 = exponent;
					
					token2=addition;
					while ( !operatorStack.empty() && (token1 <= token2 )){
						operatorStack.pop(tempChar);
						tempStr = tempChar;
						postfixStack.push(tempStr);
					}
					operatorStack.push(temp[i]);
					break;
				case 0:
					operatorStack.top(tempChar);
					if (temp[i] == '+')
						token1 = addition;
					else if (temp[i] == '-')
						token1 = subtraction;
					else if (temp[i] == '/')
						token1 = division;	
					else if (temp[i] == '*')
						token1 = multiplication;
					else if (temp[i] == '^')
						token1 = exponent;
					
					token2 = subtraction;
					while ( !operatorStack.empty() && (token1 <= token2 )){
						operatorStack.pop(tempChar);
						tempStr = tempChar;
						postfixStack.push(tempStr);
					}
					operatorStack.push(temp[i]);
					break;
				}
			}	//at this point, temp[i] is not an operator
			
			else {	//whenever temp[i] is a number or a .
				int count = 0, start = i;
				while (temp[i] != '+' || temp[i] != '-' || temp[i] != '/' || temp[i] != '*' || temp[i] != '^' || temp[i] != '(' || temp[i] != ')'){
					i++;
					count++;
				}
				string temp = temp.substr (start, count);
				postfixStack.push(temp);
			}
		}		//at this point, we have gone through the entire infix expression
		
		while (!operatorStack.empty()){
			char tempChar;
			string tempStr;
			operatorStack.pop(tempChar);
			tempStr = tempChar;
			postfixStack.push(tempStr);
		}
		
				// postfixStack now has a valid postfix expression
		Stack <double> resultStack;
		while (!postfixStack.empty()){
			char tempChar;
			string stackTop;
			postfixStack.top(stackTop);
			tempChar = stackTop.at(0);
			if (tempChar != '+' || tempChar != '-' || tempChar != '/' || tempChar != '*' || tempChar != '^'){
			//tempChar is not an operator at this point
				string tempHold;
				postfixStack.pop(tempHold);
				double tempNum = atof(tempHold.c_str());
				resultStack.push(tempNum);
			}
			else {	//tempChar is an operator
				string tempStr;
				postfixStack.pop(tempStr);
				char tempChar = tempStr.at(0);
				
				double right_operand, left_operand, result;
				resultStack.pop(right_operand);
				resultStack.pop(left_operand);
				if (tempChar == '+')
					result = left_operand + right_operand;
				if (tempChar == '-')
					result = left_operand - right_operand;
				if (tempChar == '/')
					result = left_operand / right_operand;
				if (tempChar == '*')
					result = left_operand * right_operand;
				if (tempChar == '^'){
					right_operand = right_operand + 0.5;
					int exponential = right_operand;
					double temp = left_operand;
					for (int i = 1; i<exponential; i++){
						temp = temp*left_operand;
					}
					result = temp;
					
				}

				resultStack.push(result);
			}
			
			postfixStack.pop();	//"increments" this while loop
		}
		double result;
		resultStack.top(result);
		return result;
	}			//this is the end of the overloaded float operator () function

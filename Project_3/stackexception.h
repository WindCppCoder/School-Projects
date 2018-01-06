#ifndef __STACKEXCEPTION_H__
#define __STACKEXCEPTION_H__
#include<stdexcept>
#include<string>
using namespace std;
class stack_exception: public logic_error{
public:
	stack_exception(const string &message = "") : logic_error(message.c_str()){}
};
class list_exception: public logic_error{
public:
	list_exception(const string &message = "") : logic_error(message.c_str()){}
};

#endif

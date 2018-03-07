#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

#include <Types.h>

List::List(std::vector<BaseObject *> val){
	this->val = val;
}

string List::__type__(){
	return "List";
}

string List::__repr__(){
	string str = "";
	for(auto& i : this->val){
		str += i->__repr__();
	}
	return str;
}

BaseObject * List::__add__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * List::__sub__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * List::__mul__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * List::__div__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * List::__pow__(BaseObject * other){	
	exit(1); //error handler
}

BaseObject * List::__mod__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * List::__copy__(){
	return new List(this->val);
}
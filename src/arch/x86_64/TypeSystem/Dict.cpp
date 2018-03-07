#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

#include <Types.h>

Dict::Dict(map<BaseObject *,BaseObject *> val){
	this->val = val;
}

string Dict::__type__(){
	return "Dict";
}

string Dict::__repr__(){
	return "";
}

BaseObject * Dict::__add__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * Dict::__sub__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * Dict::__mul__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * Dict::__div__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * Dict::__pow__(BaseObject * other){	
	exit(1); //error handler
}

BaseObject * Dict::__mod__(BaseObject * other){
	exit(1); //error handler
}

BaseObject * Dict::__copy__(){
	return new Dict(this->val);
}
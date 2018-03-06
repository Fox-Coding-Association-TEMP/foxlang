#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#include <Float.h>
#include <Integer.h>

Float::Float(double val){
	this->val = val;
}

string Float::__type__(){
	return "Float";
}

BaseObject * Float::__add__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Float(this->val + (double)(dynamic_cast<Integer *>(other)->val));
	}else if(other->__type__() == "Float"){
		return new Float(this->val + (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

BaseObject * Float::__sub__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Float(this->val - (double)(dynamic_cast<Integer *>(other)->val));
	}else if(other->__type__() == "Float"){
		return new Float(this->val - (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

BaseObject * Float::__mul__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Float(this->val * (double)(dynamic_cast<Integer *>(other)->val));
	}else if(other->__type__() == "Float"){
		return new Float(this->val * (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

BaseObject * Float::__div__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Float(this->val / (double)(dynamic_cast<Integer *>(other)->val));
	}else if(other->__type__() == "Float"){
		return new Float(this->val / (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

BaseObject * Float::__pow__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Float(pow(this->val, (double)(dynamic_cast<Integer *>(other)->val)));
	}else if(other->__type__() == "Float"){
		return new Float(pow(this->val, (double)(dynamic_cast<Float *>(other)->val)));
	}else{
		exit(1); //error handler
	}
}

BaseObject * Float::__mod__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Float(this->val % (double)(dynamic_cast<Integer *>(other)->val));
	}else if(other->__type__() == "Float"){
		exit(1); //error handler
	}else{
		exit(1); //error handler
	}
}

BaseObject * Float::__copy__(){
	return new Float(this->val);
}
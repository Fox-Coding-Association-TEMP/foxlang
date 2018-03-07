#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#include <Types.h>

Integer::Integer(int val){
	this->val = val;
}

string Integer::__type__(){
	return "Integer";
}

string Integer::__repr__(){
	return to_string(this->val);
}

/* implements adding an integer to other types (Supported types are Integer and Float as of now)*/
BaseObject * Integer::__add__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Integer(this->val + dynamic_cast<Integer *>(other)->val);
	}else if(other->__type__() == "Float"){
		return new Float(this->val + (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

/* implements subtracting an integer from other types (Supported types are Integer and Float as of now)*/
BaseObject * Integer::__sub__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Integer(this->val - dynamic_cast<Integer *>(other)->val);
	}else if(other->__type__() == "Float"){
		return new Float(this->val - (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

/* implements multiplying an integer with other types (Supported types are Integer and Float as of now)*/
BaseObject * Integer::__mul__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Integer(this->val * dynamic_cast<Integer *>(other)->val);
	}else if(other->__type__() == "Float"){
		return new Float(this->val * (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

/* implements dividing an integer with other types (Supported types are Integer and Float as of now)*/
BaseObject * Integer::__div__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Integer(this->val / dynamic_cast<Integer *>(other)->val);
	}else if(other->__type__() == "Float"){
		return new Float(this->val / (double)(dynamic_cast<Float *>(other)->val));
	}else{
		exit(1); //error handler
	}
}

/* implements dividing an integer with other types (Supported types are Integer and Float as of now)*/
BaseObject * Integer::__pow__(BaseObject * other){	
	if(other->__type__() == "Integer"){
		return new Integer(pow(this->val, dynamic_cast<Integer *>(other)->val));
	}else if(other->__type__() == "Float"){
		return new Float(pow(this->val, (double)(dynamic_cast<Float *>(other)->val)));
	}else{
		exit(1); //error handler
	}
}

/* implements dividing an integer with other types (Supported types are Integer and Float as of now)*/
BaseObject * Integer::__mod__(BaseObject * other){
	if(other->__type__() == "Integer"){
		return new Integer( this->val % dynamic_cast<Integer *>(other)->val);
	}else if(other->__type__() == "Float"){
		exit(1); //error handler
	}else{
		exit(1); //error handler
	}
}

BaseObject * Integer::__copy__(){
	return new Integer(this->val);
}
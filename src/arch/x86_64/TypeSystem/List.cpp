#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

#include <Types.h>

List::List(std::vector<BaseObject *> val){
	this->val = val;
}

List::List(){
	this->val = {};
}

string List::__type__(){
	return "List";
}

string List::__repr__(){
	string str = "[";
	for(auto& i : this->val){
		str += i->__repr__();
		str += ",";
	}
	str.back() = ']';
	return str;
}

BaseObject * List::__add__(BaseObject * other){
	if(other->__type__() == "List"){
		List * l = new List(this->val);
		l->extend(other);
		return l;
	}else{
		exit(1); //error handler
	}
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


void List::from_vector(vector<BaseObject *> items){
	this->val = items;
}

void List::append(BaseObject * item){
	this->val.push_back(item);
}

void List::extend(BaseObject * items){
	if(items->__type__() == "List"){
		this->val.insert(this->val.end(), dynamic_cast<List *>(items)->val.begin(), dynamic_cast<List *>(items)->val.end());
	}else{
		exit(1); //error handler
	}
}

void List::repeat(BaseObject * item){
	if(item->__type__() == "Integer"){
		vector<BaseObject *> v = this->val;
		for (int i = 0; i < dynamic_cast<Integer *>(item)->val; ++i)
		{
			this->val.insert(this->val.end(), v.begin(), v.end());
		}
	}else{
		exit(1); //error handler
	}
}
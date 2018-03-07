#define __USE_MINGW_ANSI_STDIO 0

#include <definitions.h>
#include <iostream>
using namespace std;

#include <Types.h>

BaseObject::BaseObject(){

}

string BaseObject::__type__(){
	return "BaseObject";
}

string BaseObject::__repr__(){
	return "BaseObject";
}












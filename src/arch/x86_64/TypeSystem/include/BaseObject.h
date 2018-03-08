
#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <string>

//every type in the language will be a class inheriting from this one. this ensures that every object can be saved
//on the stack (using pointers to the BaseObject).

class BaseObject{
	public:
		int refcount;
		BaseObject();
		virtual BaseObject * __add__(BaseObject * other) = 0;
		virtual BaseObject * __sub__(BaseObject * other) = 0;
		virtual BaseObject * __mul__(BaseObject * other) = 0;
		virtual BaseObject * __div__(BaseObject * other) = 0;
		virtual BaseObject * __pow__(BaseObject * other) = 0;
		virtual BaseObject * __mod__(BaseObject * other) = 0;
		
		virtual BaseObject * __getattr__(BaseObject * attr) = 0;
		virtual BaseObject * __getitem__(BaseObject * item) = 0;
		virtual void __setitem__(BaseObject * item, BaseObject * val) = 0;
		virtual void __setattr__(BaseObject * attr, BaseObject * val) = 0;

		virtual BaseObject * __copy__() = 0;
		virtual std::string __type__();
		virtual std::string __repr__();
};



#endif


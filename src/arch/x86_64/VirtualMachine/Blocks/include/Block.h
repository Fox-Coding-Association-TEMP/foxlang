
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <Instruction.h>
#include <Types.h>

using namespace std;

struct Block{
	public:
		int PC = 0;
		stack<BaseObject *> s;
		vector<Instruction> bytecode;
		vector<BaseObject *> constants;
		vector<string> names;
};

#endif


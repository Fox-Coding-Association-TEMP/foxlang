#define __USE_MINGW_ANSI_STDIO 0

#include <definitions.h>
#include <iostream>
#include <Types.h>
#include <Executor.h>
#include <Block.h>
#include <Instruction.h>

using namespace std;

int main(int argc, char *argv[]){
	// BaseObject * a = new Integer(3);
	// BaseObject * b = new Float(3.5);
	// BaseObject * c = a->__pow__(b);
	// cout << c->__repr__() << endl;

	Block * B1 = new Block();
	B1->bytecode = {
		Instruction {JUMP, 1},
		Instruction {STOP_EXECUTION}
	};
	B1->constants = {
		new Integer(3),
		new Integer(5),
	};

	Block * B2 = new Block();
	B2->bytecode = {
		Instruction {LOAD_CONST, 1},
		Instruction {STOP_EXECUTION}
	};
	B2->constants = {
		new Integer(3),
		new Integer(5),
	};

	ExecutionUnit * exec = new ExecutionUnit();
	exec->AddBlock(B1);
	exec->AddBlock(B2);
	exec->Execute();
}
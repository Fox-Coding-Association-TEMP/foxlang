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

	Block * B = new Block();
	B->bytecode = {
		Instruction {NOP},
		Instruction {LOAD_CONST,0},
		Instruction {LOAD_CONST,1},
		Instruction {BINARY_ADD},
		Instruction {STOP_EXECUTION}
	};
	B->constants = {
		new Integer(3),
		new Integer(5),
	};

	ExecutionUnit * exec = new ExecutionUnit();
	exec->AddBlock(B);
	exec->Execute();
}
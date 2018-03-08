#define __USE_MINGW_ANSI_STDIO 0

#include <definitions.h>
#include <iostream>
#include <Types.h>
#include <Executor.h>
#include <Block.h>
#include <Instruction.h>

using namespace std;

int main(int argc, char *argv[]){
	Block * B1 = new Block();
	B1->bytecode = {
		Instruction {LOAD_CONST, 0},
		Instruction {LOAD_CONST, 1},
		Instruction {BINARY_POWER},
		Instruction {STOP_EXECUTION},
	};
	B1->constants = {
		new Integer(3),
		new Integer(5),
	};

	ExecutionUnit * exec = new ExecutionUnit();
	exec->AddBlock(B1);
	exec->Execute();
}
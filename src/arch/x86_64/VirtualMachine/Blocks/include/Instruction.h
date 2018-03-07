
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <vector>

using namespace std;

enum iname {

	NOP = 0x00,
	

	//binary_operations
	BINARY_ADD, //TOS = TOS + TOS1
	BINARY_SUBTRACT, //TOS = TOS - TOS1
	BINARY_DIVIDE, //TOS = TOS / TOS1
	BINARY_MULTIPLY, //TOS = TOS * TOS1
	BINARY_MODULO, //TOS = TOS % TOS1
	BINARY_POWER, //TOS = TOS ** TOS1

	//variables
	LOAD_VAR, //TOS = varnames[arg]
	STORE_VAR, //varnames[arg] = TOS

	//constants
	LOAD_CONST, //TOS = constants[arg]


	//flow
	JUMP_TOSISTRUE, // if(TOS == True){execute(block)}
	JUMP, //execute(block)
	CALL_TOSISTRUE, // if(TOS == True){execute(block)}
	CALL, //execute(block)


	//types
	CONSTRUCT_LIST, //TOS = list(TOS...TOS[arg])
	CONSTRUCT_DICT, //TOS = dict(TOS:TOS1...TOS[arg]:TOS[arg+1])


	//other
	DUPLICATE_TOS, // TOS = TOS1 = TOS,
	CLEAR_STACK, //resets stack
	STOP_EXECUTION, //stop
};


struct Instruction{
	iname InstructionCode;
	int InstructionArgument = 0;

	Instruction(iname c, int a = 0){
		InstructionCode = c;
		InstructionArgument = a;
	}
};

#endif
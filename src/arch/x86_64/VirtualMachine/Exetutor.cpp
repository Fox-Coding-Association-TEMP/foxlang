#include <definitions.h>

#include <iostream>
#include <stack>
#include <Block.h>
#include <Instruction.h>
#include <Executor.h>
#include <Types.h>

using namespace std;

void printobjectstack(stack<BaseObject *> s){
	cout<<"stack--> ";
	while(!s.empty()){
		cout<<s.top()->__repr__()<<"  ";
		s.pop();		
	}
	cout<<endl;
}

ExecutionUnit::ExecutionUnit(){

}

void ExecutionUnit::Execute(){

	if(this->blockstack.empty()){
		this->blockstack.push(this->blocks[0]);
	}

	while(true){
		// cout<<this->blockstack.top()->PC<<endl;
		Instruction instruction = this->blockstack.top()->bytecode[this->blockstack.top()->PC];
		if(DEBUG){cout<<this->blockstack.top()->PC<<endl;}
		if(DEBUG){cout<<"now executing:"<<instruction.InstructionCode<<", arg:"<<instruction.InstructionArgument<<endl;}
		switch(instruction.InstructionCode){
			case NOP: {
				break;
			}	
			case STOP_EXECUTION:{
				if(DEBUG){cout<<"exiting program"<<endl;}
				exit(0);
				break;
			}	
			case LOAD_CONST:{
				this->blockstack.top()->s.push(
					this->blockstack.top()->constants[
						instruction.InstructionArgument
						]
					);
				break;
			}	
			case BINARY_ADD:{
				BaseObject * a = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				BaseObject * b = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				this->blockstack.top()->s.push(
					b->__add__(a)
					);
				break;
			}	
			case BINARY_SUBTRACT:{
				BaseObject * a = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				BaseObject * b = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				this->blockstack.top()->s.push(
					b->__sub__(a)
					);
				break;
			}	
			case BINARY_MULTIPLY:{
				BaseObject * a = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				BaseObject * b = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				this->blockstack.top()->s.push(
					b->__mul__(a)
					);
				break;	
			}	
			case BINARY_DIVIDE:{
				BaseObject * a = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				BaseObject * b = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				this->blockstack.top()->s.push(
					b->__div__(a)
					);
				break;
			}	
			case BINARY_MODULO:{
				BaseObject * a = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				BaseObject * b = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				this->blockstack.top()->s.push(
					b->__mod__(a)
					);
				break;	
			}	
			case BINARY_POWER:{
				BaseObject * a = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				BaseObject * b = this->blockstack.top()->s.top();
				this->blockstack.top()->s.pop();
				this->blockstack.top()->s.push(
					b->__pow__(a)
					);
				break;	
			}		
			case CONSTRUCT_LIST:{
				List * l = new List();
				for(int i = 0; i < instruction.InstructionArgument; ++i){
					l->append(this->blockstack.top()->s.top());
					this->blockstack.top()->s.pop();
				}
				this->blockstack.top()->s.push(l);
				break;	
			}	
			case JUMP:{
				Block * b = this->blocks[instruction.InstructionArgument];
				this->blockstack.pop();
				this->blockstack.push(b);
				this->blockstack.top()->PC = 0;
				this->blockstack.top()->s = stack<BaseObject *>();
				continue;
				break;	
			}		
			case CALL:{
				Block * b = this->blocks[instruction.InstructionArgument];
				this->blockstack.push(b);
				this->blockstack.top()->PC++;
				this->blockstack.top()->s = stack<BaseObject *>();
				continue;
				break;	
			}			
			case RETURN:{
				if(!this->blockstack.empty()){
					this->blockstack.pop();
					continue;
				}else{
					exit(1); //exception handler
				}
				break;	
			}	
		}
		this->blockstack.top()->PC++;
		if(DEBUG){printobjectstack(this->blockstack.top()->s);}
	}
}

void ExecutionUnit::AddBlock(Block * block){
	this->blocks.push_back(block);
}




















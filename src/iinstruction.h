#include "instruction.h"

class IInstruction: public Instruction {
    public:
        string parseInstruction(string machineCode);
        string formMemoryInstruction();
        string formBranchInstruction();
        string formImmediateInstruction();
};
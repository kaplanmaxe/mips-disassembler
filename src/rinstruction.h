#include "instruction.h"

class RInstruction: public Instruction {
    public:
        string parseInstruction(string machineCode);
};
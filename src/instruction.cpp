#include "instruction.h"

using namespace std;

// binaryToDecimal takes in a bit string and converts to
// decimal.
int Instruction::binaryToDecimal(string bits, int size) {
    int decimal = 0;
    const int base = 2;
    for (int i = 0; i < size; i++) {
        int value = 0;
        int power = (size - 1) - i;
        if (bits[i] == '1') {
            value = pow(base, power);
        }
        decimal += value;
    }
    return decimal;
}

void Instruction::setOpcode(string op) {
    opcode = op;
}

void Instruction::setRS(string reg) {
    rs = reg;
}

void Instruction::setRT(string reg) {
    rt = reg;
}

string Instruction::getOpcode() {
    return opcode;
}

string Instruction::getRS() {
    return rs;
}

string Instruction::getRT() {
    return rt;
}

string IInstruction::parseInstruction(string machineCode) {
    int rsDec = binaryToDecimal(machineCode.substr(6, 11), 5);
    string rsStr = reg.getRegister(rsDec);
    int rtDec = binaryToDecimal(machineCode.substr(11, 16), 5);
    string rtStr = reg.getRegister(rtDec);
    
    setRS(rsStr);
    setRT(rtStr);
    setImmediate(binaryToDecimal(machineCode.substr(16, 32), 16));
    ostringstream assemblyStream;
    assemblyStream << getOpcode() << " " << getRT() << ", " << getImmediate() << "(" << getRS() << ")";
    return assemblyStream.str();
}

void IInstruction::setImmediate(int dec) {
    immediate = dec;
}

int IInstruction::getImmediate() {
    return immediate;
}

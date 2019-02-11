#include "instruction.h"

using namespace std;

Instruction::Instruction() {
    // i operations
    operations["i"][4] = "beq";
    operations["i"][5] = "bne";
    operations["i"][8] = "addi";
    operations["i"][9] = "addiu";
    operations["i"][10] = "slti";
    operations["i"][11] = "sltiu";
    operations["i"][12] = "andi";
    operations["i"][13] = "ori";
    operations["i"][15] = "lui";
    operations["i"][35] = "lw";
    operations["i"][36] = "lbu";
    operations["i"][37] = "lhu";
    operations["i"][40] = "sb";
    operations["i"][41] = "sh";
    operations["i"][43] = "sw";
    operations["i"][48] = "ll";
    operations["i"][56] = "sc";

    // j operations
    operations["j"][2] = "j";
    operations["j"][3] = "jal";

    // r operations
    operations["r"][32] = "add";
    operations["r"][34] = "sub";
    operations["r"][42] = "slt";
}

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

string Instruction::getOperationFromMap(string format, int dec) {
    return operations.at(format).at(dec);
}

string Instruction::getOperation() {
    return operation;
}

string Instruction::getRS() {
    return rs;
}

string Instruction::getRT() {
    return rt;
}

string Instruction::getRD() {
    return rd;
}

int Instruction::getShamt() {
    return shamt;
}

string Instruction::getFunct() {
    return funct;
}

int Instruction::getImmediate() {
    return immediate;
}

int Instruction::getAddress() {
    return address;
}

void Instruction::setOperation(string op) {
    operation = op;
}

void Instruction::setRS(string reg) {
    rs = reg;
}

void Instruction::setRT(string reg) {
    rt = reg;
}

void Instruction::setRD(string reg) {
    rd = reg;
}

void Instruction::setShamt(int sh) {
    shamt = sh;
}

void Instruction::setFunct(string f) {
    funct = f;
}

void Instruction::setImmediate(int dec) {
    immediate = dec;
}

void Instruction::setAddress(int addr) {
    address = addr;
}

string IInstruction::parseInstruction(string machineCode) {
    int opDec = binaryToDecimal(machineCode.substr(0, 6), 6);
    string op = getOperationFromMap("i", opDec);
    int rsDec = binaryToDecimal(machineCode.substr(6, 11), 5);
    string rsStr = reg.getRegister(rsDec);
    int rtDec = binaryToDecimal(machineCode.substr(11, 16), 5);
    string rtStr = reg.getRegister(rtDec);
    
    setOperation(op);
    setRS(rsStr);
    setRT(rtStr);
    setImmediate(binaryToDecimal(machineCode.substr(16, 32), 16));

    if (op == "sw" || op == "lw") {
        return formMemoryInstruction();
    } else if (op == "beq" || op == "bne") {
        return formBranchInstruction();
    } else {
        return formImmediateInstruction();
    }
}

string IInstruction::formMemoryInstruction() {
    ostringstream assemblyStream;
    assemblyStream << getOperation() << " " << getRT() << ", " << getImmediate() << "(" << getRS() << ")";
    return assemblyStream.str();
}

string IInstruction::formBranchInstruction() {
    ostringstream assemblyStream;
    assemblyStream << getOperation() << " " << getRS() << ", " << getRT() << ", " << getImmediate();
    return assemblyStream.str();
}

string IInstruction::formImmediateInstruction() {
    ostringstream assemblyStream;
    assemblyStream << getOperation() << " " << getRT() << ", " << getRS() << ", " << getImmediate();
    return assemblyStream.str();
}

string JInstruction::parseInstruction(string machineCode) {
    // Get opcode
    int opDec = binaryToDecimal(machineCode.substr(0, 6), 6);
    string op = getOperationFromMap("j", opDec);
    // Get address
    int address = binaryToDecimal(machineCode.substr(6, 32), 26);

    // Set values
    setOperation(op);
    setAddress(address);

    // Build assembly
    ostringstream assemblyStream;
    assemblyStream << getOperation() << " " << getAddress();
    return assemblyStream.str();
}

string RInstruction::parseInstruction(string machineCode) {
    int rsDec = binaryToDecimal(machineCode.substr(6, 11), 5);
    int rtDec = binaryToDecimal(machineCode.substr(11, 16), 5);
    int rdDec = binaryToDecimal(machineCode.substr(16, 21), 5);
    int shamtDec = binaryToDecimal(machineCode.substr(21, 26), 5);
    int functDec = binaryToDecimal(machineCode.substr(26, 32), 6);

    setRS(reg.getRegister(rsDec));
    setRT(reg.getRegister(rtDec));
    setRD(reg.getRegister(rdDec));
    setShamt(shamtDec);
    setFunct(getOperationFromMap("r", functDec));

    // Build assembly
    ostringstream assemblyStream;
    assemblyStream << getFunct() << " " << getRD() << ", " << getRS() << ", " << getRT();
    return assemblyStream.str();
}



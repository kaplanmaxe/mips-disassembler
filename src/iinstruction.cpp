#include "iinstruction.h"

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

string IInstruction::parseInstruction(string machineCode) {
    int opDec = binaryToDecimal(machineCode.substr(0, 6));
    string op = getOperationFromMap("i", opDec);
    int rsDec = binaryToDecimal(machineCode.substr(6, 5));
    string rsStr = reg.getRegister(rsDec);
    int rtDec = binaryToDecimal(machineCode.substr(11, 5));
    string rtStr = reg.getRegister(rtDec);
    
    setOperation(op);
    setRS(rsStr);
    setRT(rtStr);
    setImmediate(binaryToDecimal(machineCode.substr(16, 16), true));

    if (op == "sw" || op == "lw") {
        return formMemoryInstruction();
    } else if (op == "beq" || op == "bne") {
        return formBranchInstruction();
    } else {
        return formImmediateInstruction();
    }
}
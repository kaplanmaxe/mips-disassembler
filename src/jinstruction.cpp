#include "jinstruction.h"

string JInstruction::parseInstruction(string machineCode) {
    // Get opcode
    int opDec = binaryToDecimal(machineCode.substr(0, 6));
    string op = getOperationFromMap("j", opDec);
    // Get address
    int address = binaryToDecimal(machineCode.substr(6, 26), true);

    // Set values
    setOperation(op);
    setAddress(address);

    // Build assembly
    ostringstream assemblyStream;
    assemblyStream << getOperation() << " " << getAddress();
    return assemblyStream.str();
}
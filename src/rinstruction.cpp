#include "rinstruction.h"

string RInstruction::parseInstruction(string machineCode) {
    int rsDec = binaryToDecimal(machineCode.substr(6, 5));
    int rtDec = binaryToDecimal(machineCode.substr(11, 5));
    int rdDec = binaryToDecimal(machineCode.substr(16, 5));
    int shamtDec = binaryToDecimal(machineCode.substr(21, 5), true);
    int functDec = binaryToDecimal(machineCode.substr(26, 6));

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
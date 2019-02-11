#include "disassembler.h"

int Disassembler::getFormat(string machineCode) {
    int opcodeDec = i->binaryToDecimal(machineCode.substr(0, 6));
    if (opcodeDec == 0) {
        return Format::r;
    } else if (opcodeDec == 2 || opcodeDec == 3) {
        return Format::j;
    } else {
        // This is a broad assumption but for now assume i format
        // TODO: more careful checking
        return Format::i;
    }
}

string Disassembler::disassemble(string machineCode) {
    string assembly;
    Instruction inst;
    i = &inst;
    int format = getFormat(machineCode);
    if (format == Format::i) {
        IInstruction iinst;
        i = &iinst;
        assembly = i->parseInstruction(machineCode);
    } else if (format == Format::j) {
        JInstruction jinst;
        i = &jinst;
        assembly = i->parseInstruction(machineCode);
    } else if (format == Format::r) {
        RInstruction rinst;
        i = &rinst;
        assembly = i->parseInstruction(machineCode);
    }
    
    return assembly;
}
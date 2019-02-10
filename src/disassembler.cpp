#include "disassembler.h"

Disassembler::Disassembler() {
    populateOpcodes();
}

// addi, addiu, andi, beq, bne, lbu, lhu, ll, lui, lw, ori, slti, sltiu, sb, sc, sh, sw
void Disassembler::populateOpcodes() {
    opcodes[0] = makeOpcode("r", "special");
    opcodes[4] = makeOpcode("i", "beq");
    opcodes[5] = makeOpcode("i", "bne");
    opcodes[8] = makeOpcode("i", "addi");
    opcodes[9] = makeOpcode("i", "addiu");
    opcodes[10] = makeOpcode("i", "slti");
    opcodes[11] = makeOpcode("i", "sltiu");
    opcodes[12] = makeOpcode("i", "andi");
    opcodes[13] = makeOpcode("i", "ori");
    opcodes[15] = makeOpcode("i", "lui");
    opcodes[35] = makeOpcode("i", "lw");
    opcodes[36] = makeOpcode("i", "lbu");
    opcodes[37] = makeOpcode("i", "lhu");
    opcodes[40] = makeOpcode("i", "sb");
    opcodes[41] = makeOpcode("i", "sh");
    opcodes[43] = makeOpcode("i", "sw");
    opcodes[48] = makeOpcode("i", "ll");
    opcodes[56] = makeOpcode("i", "sc");   
}

// Factory for creating Opcode
Opcode Disassembler::makeOpcode(string format, string op) {
    Opcode opcode = { format, op };
    return opcode;
}

Opcode Disassembler::getOpcode(int opcode) {
    return opcodes.at(opcode);
}

string Disassembler::getOpcodeBitString(string instruction) {
    return instruction.substr(0, 6);
}

string Disassembler::disassemble(string machineCode) {
    string assembly;
    string opcodeBits = getOpcodeBitString(machineCode);
    int opcodeDec = i.binaryToDecimal(opcodeBits, 6);
    Opcode opcode = getOpcode(opcodeDec);
    if (opcode.format == "i") {
        i.setOpcode(opcode.op);
        assembly = i.parseInstruction(machineCode);
    }
    return assembly;
}
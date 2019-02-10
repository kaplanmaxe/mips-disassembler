#include "register.h"

Register::Register() {
    populateRegisters();
}

void Register::populateRegisters() {
    registers[0] = "$zero";
    registers[1] = "$at";
    registers[2] = "$v0";
    registers[3] = "$v1";
    registers[4] = "$a0";
    registers[5] = "$a1";
    registers[6] = "$a2";
    registers[7] = "$a3";
    registers[8] = "$t0";
    registers[9] = "$t1";
    registers[10] = "$t2";
    registers[11] = "$t3";
    registers[12] = "$t4";
    registers[13] = "$t5";
    registers[14] = "$t6";
    registers[15] = "$t7";
    registers[16] = "$s0";
    registers[17] = "$s1";
    registers[18] = "$s2";
    registers[19] = "$s3";
    registers[20] = "$s4";
    registers[21] = "$s5";
    registers[22] = "$s6";
    registers[23] = "$s7";
    registers[24] = "$t8";
    registers[25] = "$t9";
    registers[26] = "$k0";
    registers[27] = "$k1";
    registers[28] = "$gp";
    registers[29] = "$sp";
    registers[30] = "$fp";
    registers[31] = "$ra";
}

string Register::getRegister(int reg) {
    return registers.at(reg);
}
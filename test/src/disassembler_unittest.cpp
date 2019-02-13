#include <limits.h>
#include "../../src/disassembler.h"
#include <gtest/gtest.h>


namespace DisassemblerTests {
    Disassembler d;
    TEST(Disassembler, Add) {
        EXPECT_EQ("add $t0, $t1, $t2", d.disassemble("00000001001010100100000000100000"));
    }

    TEST(Disassembler, Addi) {
        EXPECT_EQ("addi $t1, $t2, 5", d.disassemble("00100001010010010000000000000101"));
        EXPECT_EQ("addi $sp, $sp, -1", d.disassemble("00100011101111011111111111111111"));
        EXPECT_EQ("addi $sp, $sp, -4", d.disassemble("00100011101111011111111111111100"));
        EXPECT_EQ("addi $sp, $sp, -1", d.disassemble("00100011101111011111111111111111"));
        EXPECT_EQ("addi $sp, $sp, -100", d.disassemble("00100011101111011111111110011100"));
        EXPECT_EQ("addi $sp, $sp, -37", d.disassemble("00100011101111011111111111011011"));
        EXPECT_EQ("addi $sp, $sp, -32", d.disassemble("00100011101111011111111111100000"));
    }

    TEST(Disassembler, Sub) {
        EXPECT_EQ("sub $t0, $t1, $t2", d.disassemble("00000001001010100100000000100010"));
    }

    TEST(Disassembler, Beq) {
        EXPECT_EQ("beq $t0, $zero, 1", d.disassemble("00010001000000000000000000000001"));
        EXPECT_EQ("beq $t0, $zero, -2", d.disassemble("00010001000000001111111111111110"));
    }

    TEST(Disassembler, Slt) {
        EXPECT_EQ("slt $t0, $t1, $t2", d.disassemble("00000001001010100100000000101010"));
    }

    TEST(Disassembler, J) {
        EXPECT_EQ("j 3", d.disassemble("00001000000000000000000000000011"));
        EXPECT_EQ("j -2", d.disassemble("00001011111111111111111111111110"));
        EXPECT_EQ("j -1", d.disassemble("00001011111111111111111111111111"));
    }

    TEST(Disassembler, Jal) {
        EXPECT_EQ("jal 3", d.disassemble("00001100000000000000000000000011"));
    }

    TEST(Disassembler, Sw) {
        EXPECT_EQ("sw $v0, 20($v1)", d.disassemble("10101100011000100000000000010100"));
    }

    TEST(Disassembler, Lw) {
        EXPECT_EQ("lw $t0, 8($s1)", d.disassemble("10001110001010000000000000001000"));
        EXPECT_EQ("lw $t0, -8($s1)", d.disassemble("10001110001010001111111111111000"));
    }
}
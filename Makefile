.PHONY: run

CC   = g++
OPTS = -Wall -std=c++14

# Project name
PROJECT = mips-disassemble

# Libraries
LIBS =
INCS = -I./src/include

SRCS = $(shell find src -name '*.cpp')
DIRS = $(shell find src -type d | sed 's/src/./g' ) 
OBJS = $(patsubst src/%.cpp,out/%.o,$(SRCS))

# Targets
$(PROJECT): buildrepo $(OBJS)
	$(CC) $(OPTS) $(OBJS) $(LIBS) $(INCS) -o $@

out/%.o: src/%.cpp
	$(CC) $(OPTS) -c $< $(INCS) -o $@

clean:
	rm -rf out/
	rm $(PROJECT)

buildrepo:
	mkdir -p out
	for dir in $(DIRS); do mkdir -p out/$$dir; done

run: $(PROJECT)
	./$(PROJECT)

# add  00000001001010100100000000100000 add $t0, $t1, $t2
# addi 00100001010010010000000000000101 addi $t1, $t2, 5
# addi 00100011101111011111111111111100 addi $sp, $sp, -4
# addi 00100011101111011111111111111111 addi $sp, $sp, -1
# addi 00100011101111011111111110011100 addi $sp, $sp, -100
# addi 00100011101111011111111111011011 addi $sp, $sp, -37
# addi 00100011101111011111111111100000 addi $sp, $sp, -32
# sub  00000001001010100100000000100010 sub $t0, $t1, $t2
# beq  00010001000000000000000000000001 beq $t0, $zero, 1
# beq  00010001000000001111111111111110 beq $t0, $zero, -2
# slt  00000001001010100100000000101010 slt $t0, $t1, $t2
# j    00001000000000000000000000000011 j 3
# j    00001011111111111111111111111111 j -1
# jal  00001100000000000000000000000011 jal 3
# sw   10101100011000100000000000010100 sw $v0, 20($v1)
# lw   10001110001010000000000000001000 lw $t0, 8($s1)
# lw   10001110001010001111111111111000 lw $t0, -8($s1)


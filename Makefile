.PHONY: run

CC   = g++
OPTS = -lm -Wall

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
# sub  00000001001010100100000000100010 sub $t0, $t1, $t2
# beq  00010001000000000000000000000001 beq $t0, $zero, 1
# slt  00000001001010100100000000101010 slt $t0, $t1, $t2
# j    00001000000000000000000000000011 j 3
# jal  00001100000000000000000000000011 jal 3
# sw   10101100011000100000000000010100 sw $v0, 20($v1)
# lw   10001110001010000000000000001000 lw $t0, 8($s1)


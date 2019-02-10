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

# 10101100011000100000000000010100
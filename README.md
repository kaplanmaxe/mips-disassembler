# MIPS Disassembler

[![Build Status](https://travis-ci.com/kaplanmaxe/mips-disassembler.svg?branch=master)](https://travis-ci.com/kaplanmaxe/mips-disassembler)

MIPS Disassembler written in C++

### Description

This project was for a masters class. **It is still a WIP and does not support all instructions correctly.**

It takes in machine code from stdin and outputs the corresponding assembly.

The format of this may change in the future. It was simply an assignment.

### Build

```
cmake .
make
```

### Running

Running `make` (after running `cmake .`) will output an executable called `./mips-disassembler`.

Simply run `./mips-disassembler`

It will accept in machine code as a value in stdin and print the correct result to stdout.


### Example

```
$ ./mips-disassembler
Please enter a 32 bit long string:
00100011101111011111111111100000 <-- You enter this here
Valid bit string: 00100011101111011111111111100000
disassembled result: addi $sp, $sp, -32
```
#include <stdio.h>
#include <string.h>
#include "disassembler.h"

#define LENGTH 32
#define ACTUAL_LENGTH 32 + 1
#define false 0
#define true 1

// Checks that the char array is 32 bits long
// and only has 0 and 1 in it.
int check(char* bits) {
    if (strlen(bits) != LENGTH) {
        return false;
    }
    for (int i = 0; i < LENGTH; i++) {
        if (bits[i] != '0' && bits[i] != '1') {
            return false;
        }
    }
    return true;
}

int main(void) {
    char instruction[ACTUAL_LENGTH];
    printf("Please enter a 32 bit long string:\n");
    scanf("%s", instruction);
    if (!check(instruction)) {
        printf("Invalid bit string: %s!\n Shutting down.\n", instruction);
        return -1;
    }
    printf("Valid bit string: %s\n", instruction);
    // Your code here!
    string instructionStr;
    instructionStr.assign(instruction);
    Disassembler d;
    string assembly = d.disassemble(instructionStr);
    printf("disassembled result: %s\n", assembly.c_str());
    return 0;
}

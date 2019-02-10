
#include <map>
#include <string>
#include "instruction.h"

using namespace std;

struct Opcode
{
    string format;
    string op;
};

enum Format {
    r, i, j
};

class Disassembler
{
  public:
    Disassembler();
    string disassemble(string);
    Instruction *i;

  protected:
    map<int, Opcode> opcodes;
    void populateOpcodes();
    int binaryToDecimal(string bitString, int size);
    string getOpcodeBitString(string instruction);
    Opcode getOpcode(int opcode);
    Opcode makeOpcode(string format, string op);
    int getFormat(string);
};
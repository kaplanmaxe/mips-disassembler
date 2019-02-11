
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
    // Disassembler();
    string disassemble(string);
    Instruction *i;

  private:
    int getFormat(string);
};
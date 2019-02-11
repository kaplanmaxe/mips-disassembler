
#include <map>
#include <string>
#include "iinstruction.h"
#include "jinstruction.h"
#include "rinstruction.h"

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
    string disassemble(string);
    Instruction *i;

  private:
    int getFormat(string);
};
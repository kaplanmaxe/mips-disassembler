#include <map>
#include <math.h>
#include <cstring>
#include <string>
#include <sstream>
#include "register.h"

using namespace std;

class Instruction {
    public:
        void parseInstruction(string machineCode);
        // virtual void printInstruction();
        
        Register reg;
        string format;
        
        string funct;
        int binaryToDecimal(string bits, int size);
        void setRS(string);
        void setRT(string);
        void setOpcode(string);
        string getOpcode();
        string getRS();
        string getRT();
    
    private:
        string opcode;
        string rs;
        string rt;
        string rd;
        int shamt;
};

class IInstruction: public Instruction {
    public:
        string parseInstruction(string machineCode);
        void setImmediate(int);
        int getImmediate();
        // void printInstruction();
        // IInstruction();
    private:
        int immediate;
};

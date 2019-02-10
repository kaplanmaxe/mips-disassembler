#include <map>
#include <math.h>
#include <cstring>
#include <string>
#include <sstream>
#include "register.h"

using namespace std;

class Instruction {
    public:
        Register reg;

        int binaryToDecimal(string bits, int size);
        string getOpcode();
        string getRS();
        string getRT();
        void setRS(string);
        void setRT(string);
        void setOpcode(string);
        virtual string parseInstruction(string machineCode) {
            return "";
        };
    
    private:
        string opcode;
        string rs;
        string rt;
};

class IInstruction: public Instruction {
    public:
        string parseInstruction(string machineCode);
        void setImmediate(int);
        int getImmediate();

    private:
        int immediate;
};

class RInstruction: public Instruction {
    public:
        string parseInstruction(string machineCode);
        string getRD();
        string getShamt();
        string getFunct();
        void setRD(string);
        void setShamt(int);
        void setFunct(string);
    
    private:
        string rd;
        int shamt;
        string funct;
};

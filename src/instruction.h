#include <map>
#include <math.h>
#include <cstring>
#include <string>
#include <sstream>
#include "register.h"
#pragma once

using namespace std;

class Instruction {
    public:
        Register reg;

        Instruction();
        int binaryToDecimal(string bits, bool signedInt=false);
        void twosComplementToUnsigned(string*);
        void addOne(string*, int);
        string getOperationFromMap(string, int);

        string getOperation();
        string getRS();
        string getRT();
        string getRD();
        int getShamt();
        string getFunct();
        int getImmediate();
        int getAddress();

        void setOperation(string);
        void setRS(string);
        void setRT(string);
        void setRD(string);
        void setShamt(int);
        void setFunct(string);
        void setImmediate(int);
        void setAddress(int);
        virtual string parseInstruction(string) {
            return "";
        };
    
    private:
        map<string, map<int, string>> operations;
        string operation;
        string rs;
        string rt;
        string rd;
        string funct;
        int immediate;
        int address;
        int shamt;
};

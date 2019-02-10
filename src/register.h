#include <string>
#include <map>

using namespace std;

class Register {
    public:
        Register();
        string getRegister(int reg);
    
    private:
        map<int, string> registers;
        void populateRegisters();
};
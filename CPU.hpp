// CPU
#include <iostream>
#include <map>
#include "simulated_memory.hpp"
#include "register.hpp"
#include "J.hpp"
#include "I.hpp"
#include "R.hpp"

typedef unsigned int uint;
typedef unsigned char uchar;

typedef void (*R_OPCODE)(const uchar &, const uchar &, const uchar &, const uchar &);
// input arguments are rs(5), rt(5), rd(5), shamt(5)
typedef void (*I_OPCODE)(const uchar &, const uchar &, const uint &);
// input arguments are rs(5), rt(5), immediate(16)
typedef void (*J_OPCODE)(const uint &);
// input arguments are address(26)

class CPU
{
    private:
    //public:
    // references to processor components
    simulated_memory memory;
    simulated_register registers;
    R_TYPE r;
    I_TYPE i;
    J_TYPE j;
    //static std::map<uchar, R_OPCODE> R_OPCODES;
    //std::map<uchar, R_OPCODE> R_OPCODES;

    static std::map<uchar, I_OPCODE> I_OPCODES;
    static std::map<uchar, J_OPCODE> J_OPCODES;
    void interpret_instruction(const uint &instruction);

    public:
        int run(); // returns exit code
        CPU(/*file stream for binary instructions*/);
};

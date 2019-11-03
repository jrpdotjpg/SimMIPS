#include "register.hpp"
#include "simulated_memory.hpp"
typedef unsigned int uint;
typedef unsigned char uchar;

typedef int (*I_OPCODE)(const uchar &, const uchar &, const uint &, simulated_register&, simulated_memory&);
// input arguments are rs(5), rt(5), immediate(16) AND a reference to the register block AND a reference to the memory block

// NB I have changed the return type to int for purposes of propagating errors

class I_TYPE : public simulated_register
{
    public:
    // I type operators declarations
        int BEQ(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int BNE(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int BLEZ(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int BGTZ(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int ADDI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int ADDIU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int SLTI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int SLTIU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int ANDI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int ORI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int XORI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int LUI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int LB(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int LH(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int LW(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int LBU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int LHU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int SB(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int SH(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
        int SW(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem);
};

uint sign_extend(uint word, uchar length_of_word);
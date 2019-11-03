#include "I.hpp"

uint sign_extend(uint word, uchar length_of_word)
{
    if ((word & (0b1 << length_of_word)) > 0)
    {
        return (0xFFFFFFFF << length_of_word) | word;
    }
    else 
    {
        return word;
    }
}

// I type operators implementation
int I_TYPE::BEQ(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::BNE(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::BLEZ(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::BGTZ(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::ADDI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::ADDIU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem)
{
    reg.write_register(rt, reg.read_register(rs) + sign_extend(immediate, 16));
    return 0;
}
int I_TYPE::SLTI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::SLTIU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::ANDI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) 
{
    reg.write_register(rt, reg.read_register(rs) & immediate);
    return 0;
}
int I_TYPE::ORI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) 
{
    reg.write_register(rt, reg.read_register(rs) | immediate);
    return 0;
}
int I_TYPE::XORI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) 
{
    reg.write_register(rt, reg.read_register(rs) ^ immediate);
    return 0;
}
int I_TYPE::LUI(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::LB(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::LH(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::LW(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::LBU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::LHU(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::SB(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::SH(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}
int I_TYPE::SW(const uchar &rs, const uchar &rt, const uint &immediate, simulated_register &reg, simulated_memory &mem) {}

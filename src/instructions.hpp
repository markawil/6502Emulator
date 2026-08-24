//
// Created by Mark Wilkinson on 8/23/26.
//

#ifndef INC_6502EMULATOR_INSTRUCTIONS_HPP
#define INC_6502EMULATOR_INSTRUCTIONS_HPP
#include "emulator.hpp"

/*
* Load/Store Operations
These instructions transfer a single byte between memory and one of the registers.
Load operations set the negative (N) and zero (Z) flags depending on the value of transferred.
Store operations do not affect the flag settings.

LDA	Load Accumulator	N,Z
LDX	Load X Register	    N,Z
LDY	Load Y Register	    N,Z
STA	Store Accumulator
STX	Store X Register
STY	Store Y Register

*/

struct Instruction {
    BYTE opcode;
    short bytes_count;
    short cycles;
};

inline constexpr Instruction LDA_IMMEDIATE{0xA9, 2, 2};
inline constexpr Instruction LDA_ZERO_PAGE{0xA5, 2, 3};
inline constexpr Instruction LDA_ZERO_PAGE_X{0xB5, 2, 4};
inline constexpr Instruction LDA_ABSOLUTE{0xAD, 3, 4};
inline constexpr Instruction LDA_ABSOLUTE_X{0xBD, 3, 4}; // +1 cycle if page crossed
inline constexpr Instruction LDA_ABSOLUTE_Y{0xB9, 3, 4}; // +1 cycle if page crossed
inline constexpr Instruction LDA_INDIRECT_X{0xA1, 2, 6};
inline constexpr Instruction LDA_INDIRECT_Y{0xB1, 2, 5}; // +1 cycle if page crossed

#endif //INC_6502EMULATOR_INSTRUCTIONS_HPP
